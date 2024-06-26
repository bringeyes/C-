#include "Equipment.h"

unordered_map<Equipment, string> Equip_Name = {
	{ Wujin,"无尽之刃" },
	{ Guisuo,"鬼索的狂暴之刃" },
	{ Ruili,"锐利之刃" },
	{ HongBUFF,"红霸符" },
	{ JuSha,"巨人杀手" },
	{ PoFang,"破防者" },
	{ QingYu,"最后的轻语" },
	{ JuFeng,"卢安娜的飓风" },
	{ ShuoJi,"朔极之矛" },
};

Equipment All_Equips[9] = {
	Wujin,Guisuo,Ruili,HongBUFF,JuSha,PoFang,QingYu,JuFeng,ShuoJi
};

Equipment** Get_Equip_Combination(Equipment Equips[], int num) {
	int rows = num * (num + 1) * (num + 2) / 6;		// 用公式计算总行数

	// 生成一个镜像二维数组，用于选择对应标号的装备
	int** arr = new int* [rows];
	int count = 0;		// 当前行数

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

	// 动态分配一个指向Equipment指针的数组
	Equipment** equip_Combination = new Equipment * [rows];

	// 为每个指针分配一个包含 3 个Equipment对象的数组
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
	// 添加装备前先重置英雄属性
	target.initHero();

	for (int i = 0; i < 3; i++) {
		equips[i](target);			// 根据装备修改英雄属性
	}
	// 调整暴击率和暴击伤害
	if (target.m_baoji > 1) {
		target.m_baoshang += (target.m_baoji - 1) / 2;
		target.m_baoji = 1;
	}
}

void show_Equips(Equipment Equips[3]) {
	cout << "\n***装备***\n";
	for (int i = 0; i < 3; i++) {
		cout << Equip_Name[Equips[i]] << ' ';
	}
	cout << "\n\n";
}

void NoEquip(Hero& target) {};

void Wujin(Hero& target) {
	/*
	攻击力+35%	暴击率+35%
	技能可以暴击。如果携带者的技能已经可以暴击了，则转而提供10%暴击伤害
	*/
	target.m_ratio_AD += 0.35;
	target.m_baoji += 0.35;
	if (target.if_Skill_Crit == true) target.m_baoshang += 0.1;
	target.if_Skill_Crit = true;
}

void Guisuo(Hero& target) {
	/*
	攻击速度+15%	法术强度+10
	攻击提供5%可叠加的攻击速度
	*/
	target.m_AP += 10;
	target.m_ratio_AS += 0.15;
	target.m_equips.a_guisuo++;
}

void Ruili(Hero& target) {
	/*
	攻击力+55%
	造成8%额外伤害。
	*/
	target.m_ratio_AD += 0.55;
	target.m_ratio_damage += 0.08;
}

void HongBUFF(Hero& target) {
	/*
	攻击速度+40%
	造成6%额外伤害。攻击和技能对敌人们造成持续5秒的1%灼烧效果和33%重伤效果。(可叠加？)
	*/
	target.m_ratio_AS += 0.4;
	target.m_ratio_damage += 0.06;
}

void JuSha(Hero& target) {
	/*
	攻击力+30% 攻击速度+10% 法术强度+20
	对最大生命值超过了1750的敌人们造成25%额外伤害
	*/
	target.m_ratio_AD += 0.3;
	target.m_ratio_AS += 0.1;
	target.m_AP += 20;
	target.m_equips.a_jusha++;
	// 默认巨杀触发
	target.m_ratio_damage += 0.25;
}

void PoFang(Hero& target) {
	/*
	生命上限+150 暴击率+20% 攻击速度+20% 法术强度+10
	在对护盾造成伤害后，多造成25%伤害，持续3秒。
	*/
	target.m_extra_health += 150;
	target.m_baoji += 0.2;
	target.m_ratio_AS += 0.2;
	target.m_AP += 10;
	target.m_equips.a_pofang++;
	// 默认破防触发
	target.m_ratio_damage += 0.25;
}

void ZhengYi(Hero& target) {
	/*
	暴击率+20% 法力值+15
	获得2个效果：
		攻击力+15%，法术强度+15
		全能吸血+15%
	每一回合，随机使其中一个效果翻倍。
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
	魔抗+20 暴击率+20% 攻击速度+30%
	战斗开始时，获得持续14秒的控制免疫效果。
	在此期间，每2秒获得4%攻击速度。
	*/
	target.m_mokang += 20;
	target.m_baoji += 0.2;
	target.m_ratio_AS += 0.3;
	target.m_equips.a_shuiyin = true;
}

void QingYu(Hero& target) {
	/*
	暴击率+20% 攻击速度+25% 攻击力+15%
	物理伤害会对目标施加持续3秒的30%护甲击碎。这个效果不会叠加。
	*/
	target.m_baoji += 0.2;
	target.m_ratio_AS += 0.25;
	target.m_ratio_AD += 0.15;
	target.m_equips.a_qingyu = true;
}

void JuFeng(Hero& target) {
	/*
	攻击速度+10% 魔抗+20 攻击力+25%
	携带者的攻击会对附近的另一名敌人发射一个弹体，造成携带者55%攻击力的物理伤害
	*/
	target.m_ratio_AS += 0.1;
	target.m_mokang += 20;
	target.m_ratio_AD += 0.25;
	target.m_equips.a_jufeng++;
}

void ShuoJi(Hero& target) {
	/*
	攻击力+20% 法力值+15 法强+20
	每次普攻提供5额外法力值。
	*/
	target.m_ratio_AD += 0.2;
	target.m_initMana += 15;
	target.m_AP += 20;
	target.m_huilan += 5;
}