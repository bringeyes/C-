#include "Equipment.h"

unordered_map<Equipment, string> Equip_Name = {
	{ Wujin,"�޾�֮��" },
	{ Guisuo,"�����Ŀ�֮��" },
	{ Ruili,"����֮��" },
	{ HongBUFF,"��Է�" },
	{ JuSha,"����ɱ��" },
	{ PoFang,"�Ʒ���" },
	{ QingYu,"��������" },
	{ JuFeng,"¬���ȵ�쫷�" },
	{ ShuoJi,"˷��֮ì" },
};

Equipment All_Equips[9] = {
	Wujin,Guisuo,Ruili,HongBUFF,JuSha,PoFang,QingYu,JuFeng,ShuoJi
};

Equipment** Get_Equip_Combination(Equipment Equips[], int num) {
	int rows = num * (num + 1) * (num + 2) / 6;		// �ù�ʽ����������

	// ����һ�������ά���飬����ѡ���Ӧ��ŵ�װ��
	int** arr = new int* [rows];
	int count = 0;		// ��ǰ����

	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			for (int k = j; k < num; k++) {
				arr[count] = new int[3];
				arr[count][0] = i;
				arr[count][1] = j;
				arr[count][2] = k;
				count++;
			}
		}
	}

	// ��̬����һ��ָ��Equipmentָ�������
	Equipment** equip_Combination = new Equipment * [rows];

	// Ϊÿ��ָ�����һ������ 3 ��Equipment���������
	for (int i = 0; i < rows; i++) {
		equip_Combination[i] = new Equipment[3];

		for (int j = 0; j < 3; j++) {
			equip_Combination[i][j] = Equips[arr[i][j]];
		}
		//show_Equips(equip_Combination[i]);
	}

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return equip_Combination;
}

void add_Equips(Hero& target, Equipment equips[3]) {
	// ���װ��ǰ������Ӣ������
	target.initHero();

	for (int i = 0; i < 3; i++) {
		equips[i](target);			// ����װ���޸�Ӣ������
	}
	// ���������ʺͱ����˺�
	if (target.m_baoji > 1) {
		target.m_baoshang += (target.m_baoji - 1) / 2;
		target.m_baoji = 1;
	}
}

void show_Equips(Equipment Equips[3]) {
	cout << "\n***װ��***\n";
	for (int i = 0; i < 3; i++) {
		cout << Equip_Name[Equips[i]] << ' ';
	}
	cout << "\n\n";
}

void NoEquip(Hero& target) {};

void Wujin(Hero& target) {
	/*
	������+35%	������+35%
	���ܿ��Ա��������Я���ߵļ����Ѿ����Ա����ˣ���ת���ṩ10%�����˺�
	*/
	target.m_ratio_AD += 0.35;
	target.m_baoji += 0.35;
	if (target.if_Skill_Crit == true) target.m_baoshang += 0.1;
	target.if_Skill_Crit = true;
}

void Guisuo(Hero& target) {
	/*
	�����ٶ�+15%	����ǿ��+10
	�����ṩ5%�ɵ��ӵĹ����ٶ�
	*/
	target.m_AP += 10;
	target.m_ratio_AS += 0.15;
	target.m_equips.a_guisuo++;
}

void Ruili(Hero& target) {
	/*
	������+55%
	���8%�����˺���
	*/
	target.m_ratio_AD += 0.55;
	target.m_ratio_damage += 0.08;
}

void HongBUFF(Hero& target) {
	/*
	�����ٶ�+40%
	���6%�����˺��������ͼ��ܶԵ�������ɳ���5���1%����Ч����33%����Ч����(�ɵ��ӣ�)
	*/
	target.m_ratio_AS += 0.4;
	target.m_ratio_damage += 0.06;
}

void JuSha(Hero& target) {
	/*
	������+30% �����ٶ�+10% ����ǿ��+20
	���������ֵ������1750�ĵ��������25%�����˺�
	*/
	target.m_ratio_AD += 0.3;
	target.m_ratio_AS += 0.1;
	target.m_AP += 20;
	target.m_equips.a_jusha++;
	// Ĭ�Ͼ�ɱ����
	target.m_ratio_damage += 0.25;
}

void PoFang(Hero& target) {
	/*
	��������+150 ������+20% �����ٶ�+20% ����ǿ��+10
	�ڶԻ�������˺��󣬶����25%�˺�������3�롣
	*/
	target.m_extra_health += 150;
	target.m_baoji += 0.2;
	target.m_ratio_AS += 0.2;
	target.m_AP += 10;
	target.m_equips.a_pofang++;
	// Ĭ���Ʒ�����
	target.m_ratio_damage += 0.25;
}

void ZhengYi(Hero& target) {
	/*
	������+20% ����ֵ+15
	���2��Ч����
		������+15%������ǿ��+15
		ȫ����Ѫ+15%
	ÿһ�غϣ����ʹ����һ��Ч��������
	*/
	target.m_baoji += 0.2;
	target.m_initMana += 15;
	target.m_ratio_AD += 0.15;
	target.m_AP += 15;
	target.m_xixie += 0.15;
	if ((static_cast<double>(rand()) / RAND_MAX) <= 0.5) {
		target.m_ratio_AD += 0.15; target.m_AP += 15;
	}
	else target.m_xixie += 0.15;
}

void ShuiYin(Hero& target) {
	/*
	ħ��+20 ������+20% �����ٶ�+30%
	ս����ʼʱ����ó���14��Ŀ�������Ч����
	�ڴ��ڼ䣬ÿ2����4%�����ٶȡ�
	*/
	target.m_mokang += 20;
	target.m_baoji += 0.2;
	target.m_ratio_AS += 0.3;
	target.m_equips.a_shuiyin = true;
}

void QingYu(Hero& target) {
	/*
	������+20% �����ٶ�+25% ������+15%
	�����˺����Ŀ��ʩ�ӳ���3���30%���׻��顣���Ч��������ӡ�
	*/
	target.m_baoji += 0.2;
	target.m_ratio_AS += 0.25;
	target.m_ratio_AD += 0.15;
	target.m_equips.a_qingyu = true;
}

void JuFeng(Hero& target) {
	/*
	�����ٶ�+10% ħ��+20 ������+25%
	Я���ߵĹ�����Ը�������һ�����˷���һ�����壬���Я����55%�������������˺�
	*/
	target.m_ratio_AS += 0.1;
	target.m_mokang += 20;
	target.m_ratio_AD += 0.25;
	target.m_equips.a_jufeng++;
}

void ShuoJi(Hero& target) {
	/*
	������+20% ����ֵ+15 ��ǿ+20
	ÿ���չ��ṩ5���ⷨ��ֵ��
	*/
	target.m_ratio_AD += 0.2;
	target.m_initMana += 15;
	target.m_AP += 20;
	target.m_huilan += 5;
}