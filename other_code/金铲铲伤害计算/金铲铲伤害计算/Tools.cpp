#include <cmath>
#include "Tools.h"

int calculateDamage(Hero& target, int time) {
	int level = target.m_level;			// �Ǽ�
	double baoji = target.m_baoji;		// ��ʼ��������
	int mana = target.m_initMana;		// ��ʼ������
	const int AD = target.m_AD;			// ��ʼ�������﹥
	const double AS = target.m_AS;		// ��ʼ����������
	int& count_Attacks = target.m_count_Attacks;					// ��ʼ����������
	int& count_Skills = target.m_count_Skills;					// ��ʼ�������ͷŴ���

	bool manalock = false;				// ������
	int skill_time = 0;				// ��ǰ�����ͷ�ʱ��(ms)
	int attack_time = 0;				// ��ǰ����ʱ��(ms)
	double attack_interval_time = 1 / (target.m_ratio_AS * AS);	// �������ʱ��
	int current_AD = target.m_ratio_AD * AD;						// ��ʼ���﹥
	int atk;								// ���ι����˺�

	int totalDamage = 0;					// ���˺�
	int skillDamage = 0;					// �����˺�
	int attackDamage = 0;				// �����˺�

	// �����˺�
	for (int seconds = 1; seconds < time * 1000; seconds++) {			// ÿ0.001���ж�ִ������
		// ���װ����ˮ������14�������ӹ���
		if (target.m_equips.a_shuiyin == true && seconds <= 14000) {
			if (seconds % 2000 == 0) {
				target.m_ratio_AS += 0.04;
			}
		}

		// �����ﵽ����
		if (mana >= target.m_maxMana) {
			// �ͷż���
			count_Skills++;
			/*cout << seconds << "s ��" << count_Skills << "���ͷż���\n";*/
			mana = 0;				// �������
			manalock = true;		// ����������ֹͣ�չ�
			skillDamage += target.m_skill(target, level);		// ���ݵ�ǰ���Լ��㼼���˺�
		}

		if (manalock == true) {
			// �жϼ����ͷ��Ƿ����
			if (skill_time < target.m_release_time * 1000) skill_time++;
			else {
				manalock = false;	// �����ͷ���ϣ��ر�������
				skill_time = 0;
			}
		}
		if (manalock == false) {
			// ���ݵ�ǰ���ټ��㹥����Ҫ��ʱ��
			if (attack_time < attack_interval_time * 1000) attack_time++;
			else {
				count_Attacks++;
				/*cout << seconds << "s ��" << count_Attacks << "�ι���\n";*/

				// ���װ���˹����Ŀ�֮�У����ٱ���+0.05
				target.m_ratio_AS += target.m_equips.a_guisuo * 0.05;

				mana += 10;		// ��������10

				// ���ݱ����ʼ����չ��˺�
				if ((static_cast<double>(rand()) / RAND_MAX) < baoji) {
					atk = current_AD * target.m_baoshang;
				}
				else atk = current_AD;

				atk *= target.m_ratio_damage;		// �����˺�����

				attackDamage += atk;

				// ���װ����¬���ȵ�쫷磬����װ����ɵ��˺�
				attackDamage += target.m_equips.a_jufeng * target.m_AD * target.m_ratio_AD * 0.55 * target.m_ratio_damage;

				attack_time = 0;		// ���ù���ʱ��

				attack_interval_time = 1 / (target.m_ratio_AS * AS);

				// �����ٳ���5.0��ǿ�ƹ������Ϊ0.2s
				if (target.m_ratio_AS * AS > 5.0) {
					target.m_ratio_AS = 5.0 / AS;
					attack_interval_time = 0.2;
					target.m_equips.a_guisuo = 0;
				}
			}
		}
	}

	totalDamage = skillDamage + attackDamage;

	//cout << "���˺���" << totalDamage << "�������˺���" << attackDamage << "�������˺���" << skillDamage
	//	<< "������������" << count_Attacks << "�������ͷŴ�����" << count_Skills << endl;

	return totalDamage;
}

int calculateTankiness(Hero& target, int time) {
	int level = target.m_level;			// �Ǽ�
	int total_susDamage = 0;				// ��ʼ���ܳ����˺�
	int mana = target.m_initMana;		// ��ʼ������
	double seconds = 0;					// ��ǰʱ��
	/*
	���˻�����ʽ��
		�ɷ�ʽ���ܵ���6%��ǰ�˺�(��������)��ת��Ϊ���ɵķ���ֵ��y=0.06x (x<825); y=50 (x>=825)
		�·�ʽ���ܵ���1%��ǰ�˺���7%�ۺ��˺���ת��Ϊ���ɵķ���ֵ
	*/

	// ����ÿ�����
	for (double i = 0; i < seconds; i += 0.1) {
		// �����ﵽ����
		if (mana >= target.m_maxMana) {
			// �ͷż���
			mana -= target.m_maxMana;		// ��������
			target.m_skill(target, level);
		}
	}

	return total_susDamage;
}

void Get_RangeOfDamage(Hero& target, Equipment Equips[3], int num) {
	show_Equips(Equips);		// ��ʾװ��
	add_Equips(target, Equips); /*target.show();*/	// ��ʾ����װ�����Ӣ������

	int* arr = new int[num];		// ������̬���飬���ÿ�εõ��Ľ��

	for (int time = 10; time <= 30; time += 10) {
		cout << "��" << time << "�룺\n";

		for (int i = 0; i < num; i++) {
			add_Equips(target, Equips);			// ����װ��������Ӣ�����ԣ�����Ҫ����
			arr[i] = calculateDamage(target, time);
		}
		quickSort(arr, num);
		cout << arr[0] << "��" << arr[num - 1] << endl;
	}

	delete arr;		// �ͷ�����
}

int Get_Min_Damage(Hero& target, Equipment Equips[3], int num) {
	int* arr = new int[num];		// ������̬���飬���ÿ�εõ��Ľ��

	if (target.m_level == 3) {		// 3��Ӣ�ۿ�ǰ15����˺�
		for (int i = 0; i < num; i++) {
			add_Equips(target, Equips);			// ����װ��������Ӣ�����ԣ�����Ҫ����
			arr[i] = calculateDamage(target, 15);
		}
		quickSort(arr, num);
	}
	else {							// 1��2��Ӣ�ۿ�ǰ25����˺�
		for (int i = 0; i < num; i++) {
			add_Equips(target, Equips);
			arr[i] = calculateDamage(target, 25);
		}
		quickSort(arr, num);
	}

	int minDamage = arr[0];			// ������Сֵ
	delete arr;						// �ͷ�����
	return minDamage;				// �����˺���Сֵ
}

void Test_Process(Hero& target, Equipment Equip_combine[], int num) {
	Equipment** Equips = Get_Equip_Combination(Equip_combine, num);		// �õ�����װ�����

	cout << "��ǰ���Զ���" << target.m_name << " (" << target.m_level << "��)\n";

	int times = num * (num + 1) * (num + 2) / 6;			// �����װ���������
	int* arr = new int[times];		// ����һ�����飬������Ų�ͬװ������˺�����Сֵ

	// ����һ���µ� Equipment** ���飬���ڴ�������� Equips ����
	Equipment** sortedEquips = new Equipment * [times];

	// ����һ���ֵ�
	unordered_map<Equipment*, int> map;

	for (int i = 0; i < times; i++) {
		arr[i] = Get_Min_Damage(target, Equips[i], num);		// �����˺���Сֵ���浽����arr��
		map[Equips[i]] = arr[i];			// �����ֵ��
	}
	quickSort(arr, times);

	for (int i = 0; i < times; i++) {
		// ���������˺�����װ������������Ż��ռ䣬����������˺���ͬ��ֻ�ܷ���һ����
		sortedEquips[i] = findKeyByValue(map, arr[i]);
		show_Equips(sortedEquips[i]);
		cout << arr[i] << endl;
	}

	// �ͷ��ڴ�
	delete[] arr;
	releaseArray(Equips, times);
	delete[] sortedEquips, times;
}

Equipment* findKeyByValue(const unordered_map<Equipment*, int>& map, int value) {
	for (const auto& pair : map) {
		if (pair.second == value) {
			return pair.first;
		}
	}
	return nullptr;		// ����Ҳ���ƥ��ļ������� nullptr
}

void releaseArray(Equipment** arr, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

void quickSort(int arr[], unsigned int len) {
	if (len < 2) return;    // ����Ԫ��<2����������

	int mid = arr[0];       // �����ᣨ��׼����
	int left = 0, right = len - 1;
	int moving = 2;        // ��ǰӦ�ƶ���ָ�룬1-��ָ�룬2-��ָ�룬ȱʡȡֵ2��

	while (left < right) {
		if (moving == 2) {      // �ƶ���ָ��
			if (arr[right] >= mid) { right--; continue; }
			arr[left] = arr[right];
			left++;
			moving = 1;
		}
		else {                          // �ƶ���ָ��
			if (arr[left] < mid) { left++; continue; }
			arr[right] = arr[left];
			right--;
			moving = 2;
		}
	}
	arr[left] = mid;

	quickSort(arr, left);         // ������������
	quickSort(arr + left + 1, len - left - 1);      // ������������
}

void printList(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}