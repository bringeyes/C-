#include <cmath>
#include "Tools.h"

int calculateDamage(Hero& target, int time) {
	int level = target.m_level;			// 星级
	double baoji = target.m_baoji;		// 初始化暴击率
	int mana = target.m_initMana;		// 初始化蓝量
	const int AD = target.m_AD;			// 初始化基础物攻
	const double AS = target.m_AS;		// 初始化基础攻速
	int& count_Attacks = target.m_count_Attacks;					// 初始化攻击次数
	int& count_Skills = target.m_count_Skills;					// 初始化技能释放次数

	bool manalock = false;				// 蓝条锁
	int skill_time = 0;				// 当前技能释放时间(ms)
	int attack_time = 0;				// 当前攻击时间(ms)
	double attack_interval_time = 1 / (target.m_ratio_AS * AS);	// 攻击间隔时间
	int current_AD = target.m_ratio_AD * AD;						// 初始化物攻
	int atk;								// 单次攻击伤害

	int totalDamage = 0;					// 总伤害
	int skillDamage = 0;					// 技能伤害
	int attackDamage = 0;				// 攻击伤害

	// 计算伤害
	for (int seconds = 1; seconds < time * 1000; seconds++) {			// 每0.001秒判断执行条件
		// 如果装备了水银，在14秒内增加攻速
		if (target.m_equips.a_shuiyin == true && seconds <= 14000) {
			if (seconds % 2000 == 0) {
				target.m_ratio_AS += 0.04;
			}
		}

		// 蓝量达到上限
		if (mana >= target.m_maxMana) {
			// 释放技能
			count_Skills++;
			/*cout << seconds << "s 第" << count_Skills << "次释放技能\n";*/
			mana = 0;				// 清空蓝条
			manalock = true;		// 打开蓝条锁，停止普攻
			skillDamage += target.m_skill(target, level);		// 根据当前属性计算技能伤害
		}

		if (manalock == true) {
			// 判断技能释放是否结束
			if (skill_time < target.m_release_time * 1000) skill_time++;
			else {
				manalock = false;	// 技能释放完毕，关闭蓝条锁
				skill_time = 0;
			}
		}
		if (manalock == false) {
			// 根据当前攻速计算攻击需要的时间
			if (attack_time < attack_interval_time * 1000) attack_time++;
			else {
				count_Attacks++;
				/*cout << seconds << "s 第" << count_Attacks << "次攻击\n";*/

				// 如果装备了鬼索的狂暴之刃，攻速倍率+0.05
				target.m_ratio_AS += target.m_equips.a_guisuo * 0.05;

				mana += 10;		// 法力生成10

				// 根据暴击率计算普攻伤害
				if ((static_cast<double>(rand()) / RAND_MAX) < baoji) {
					atk = current_AD * target.m_baoshang;
				}
				else atk = current_AD;

				atk *= target.m_ratio_damage;		// 乘以伤害倍率

				attackDamage += atk;

				// 如果装备了卢安娜的飓风，增加装备造成的伤害
				attackDamage += target.m_equips.a_jufeng * target.m_AD * target.m_ratio_AD * 0.55 * target.m_ratio_damage;

				attack_time = 0;		// 重置攻击时间

				attack_interval_time = 1 / (target.m_ratio_AS * AS);

				// 当攻速超过5.0后，强制攻击间隔为0.2s
				if (target.m_ratio_AS * AS > 5.0) {
					target.m_ratio_AS = 5.0 / AS;
					attack_interval_time = 0.2;
					target.m_equips.a_guisuo = 0;
				}
			}
		}
	}

	totalDamage = skillDamage + attackDamage;

	//cout << "总伤害：" << totalDamage << "，攻击伤害：" << attackDamage << "，技能伤害：" << skillDamage
	//	<< "，攻击次数：" << count_Attacks << "，技能释放次数：" << count_Skills << endl;

	return totalDamage;
}

int calculateTankiness(Hero& target, int time) {
	int level = target.m_level;			// 星级
	int total_susDamage = 0;				// 初始化总承受伤害
	int mana = target.m_initMana;		// 初始化蓝量
	double seconds = 0;					// 当前时间
	/*
	受伤回蓝公式：
		旧方式：受到的6%折前伤害(四舍五入)会转化为生成的法力值，y=0.06x (x<825); y=50 (x>=825)
		新方式：受到的1%折前伤害和7%折后伤害会转化为生成的法力值
	*/

	// 计算每秒承伤
	for (double i = 0; i < seconds; i += 0.1) {
		// 蓝量达到上限
		if (mana >= target.m_maxMana) {
			// 释放技能
			mana -= target.m_maxMana;		// 消耗蓝条
			target.m_skill(target, level);
		}
	}

	return total_susDamage;
}

void Get_RangeOfDamage(Hero& target, Equipment Equips[3], int num) {
	show_Equips(Equips);		// 显示装备
	add_Equips(target, Equips); /*target.show();*/	// 显示加载装备后的英雄属性

	int* arr = new int[num];		// 创建动态数组，存放每次得到的结果

	for (int time = 10; time <= 30; time += 10) {
		cout << "第" << time << "秒：\n";

		for (int i = 0; i < num; i++) {
			add_Equips(target, Equips);			// 加载装备，重置英雄属性（很重要！）
			arr[i] = calculateDamage(target, time);
		}
		quickSort(arr, num);
		cout << arr[0] << "—" << arr[num - 1] << endl;
	}

	delete arr;		// 释放数组
}

int Get_Min_Damage(Hero& target, Equipment Equips[3], int num) {
	int* arr = new int[num];		// 创建动态数组，存放每次得到的结果

	if (target.m_level == 3) {		// 3星英雄看前15秒的伤害
		for (int i = 0; i < num; i++) {
			add_Equips(target, Equips);			// 加载装备，重置英雄属性（很重要！）
			arr[i] = calculateDamage(target, 15);
		}
		quickSort(arr, num);
	}
	else {							// 1星2星英雄看前25秒的伤害
		for (int i = 0; i < num; i++) {
			add_Equips(target, Equips);
			arr[i] = calculateDamage(target, 25);
		}
		quickSort(arr, num);
	}

	int minDamage = arr[0];			// 保存最小值
	delete arr;						// 释放数组
	return minDamage;				// 返回伤害最小值
}

void Test_Process(Hero& target, Equipment Equip_combine[], int num) {
	Equipment** Equips = Get_Equip_Combination(Equip_combine, num);		// 得到所有装备组合

	cout << "当前测试对象：" << target.m_name << " (" << target.m_level << "星)\n";

	int times = num * (num + 1) * (num + 2) / 6;			// 被测的装备组合数量
	int* arr = new int[times];		// 定义一个数组，用来存放不同装备组合伤害的最小值

	// 创建一个新的 Equipment** 数组，用于存放排序后的 Equips 数组
	Equipment** sortedEquips = new Equipment * [times];

	// 创建一个字典
	unordered_map<Equipment*, int> map;

	for (int i = 0; i < times; i++) {
		arr[i] = Get_Min_Damage(target, Equips[i], num);		// 返回伤害最小值，存到数组arr中
		map[Equips[i]] = arr[i];			// 插入键值对
	}
	quickSort(arr, times);

	for (int i = 0; i < times; i++) {
		// 按排序后的伤害，对装备组合排序（有优化空间，如果多个组合伤害相同，只能返回一个）
		sortedEquips[i] = findKeyByValue(map, arr[i]);
		show_Equips(sortedEquips[i]);
		cout << arr[i] << endl;
	}

	// 释放内存
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
	return nullptr;		// 如果找不到匹配的键，返回 nullptr
}

void releaseArray(Equipment** arr, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

void quickSort(int arr[], unsigned int len) {
	if (len < 2) return;    // 数组元素<2个不用排序

	int mid = arr[0];       // 中心轴（基准数）
	int left = 0, right = len - 1;
	int moving = 2;        // 当前应移动的指针，1-左指针，2-右指针，缺省取值2。

	while (left < right) {
		if (moving == 2) {      // 移动右指针
			if (arr[right] >= mid) { right--; continue; }
			arr[left] = arr[right];
			left++;
			moving = 1;
		}
		else {                          // 移动左指针
			if (arr[left] < mid) { left++; continue; }
			arr[right] = arr[left];
			right--;
			moving = 2;
		}
	}
	arr[left] = mid;

	quickSort(arr, left);         // 对左区间排序
	quickSort(arr + left + 1, len - left - 1);      // 对右区间排序
}

void printList(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}