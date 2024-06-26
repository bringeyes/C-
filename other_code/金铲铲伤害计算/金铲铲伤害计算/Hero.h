#pragma once
#include <iostream>
#include <functional>
using namespace std;

enum damageType { AD, AP };	// 伤害类型

class AddedEquip {
public:
	int a_guisuo;			// 鬼索的狂暴之刃
	int a_jusha;			// 巨人杀手
	int a_pofang;			// 破防者
	int a_jufeng;			// 卢安娜的飓风
	bool a_shuiyin;			// 水银
	bool a_qingyu;			// 轻语
	AddedEquip(int guisuo, int jusha, int pofang, int jufeng, bool shuiyin, bool qingyu)
		:a_guisuo(guisuo), a_jusha(jusha), a_pofang(pofang), a_jufeng(jufeng), a_shuiyin(shuiyin), a_qingyu(qingyu) {}
	void initAddedEquip() {
		a_guisuo = 0;
		a_jusha = 0;
		a_pofang = 0;
		a_jufeng = 0;
		a_shuiyin = false;
		a_qingyu = false;
	}
};

class Hero {
public:
	string m_name;			// 名字
	const int m_level;		// 星级
	const int m_health;		// 基础生命值
	int m_extra_health;		// 额外生命值
	int m_armor;			// 护甲
	int m_mokang;			// 魔抗
	const int m_AD;			// 基础物攻
	int m_AP;				// 法强
	const double m_AS;		// 基础攻速
	double m_baoji;			// 暴击率
	double m_baoshang;		// 暴击伤害
	double m_xixie;			// 全能吸血
	int m_range;				// 攻击距离
	int m_initMana;			// 初始法力值
	int m_maxMana;			// 最大法力值
	double m_ratio_AD;		// 当前物攻倍率
	double m_ratio_AS;		// 当前攻速倍率
	double m_ratio_damage;	// 伤害倍率
	int m_count_Attacks;		// 攻击次数
	int m_count_Skills;		// 技能释放次数
	int m_huilan;			// 攻击回蓝
	damageType m_type;		// 伤害类型
	function<int(Hero&, int)> m_skill;		// 技能
	double m_release_time;	// 技能释放时长
	bool if_Skill_Crit;		// 技能是否可以暴击
	AddedEquip m_equips;		// 已添加装备

	Hero(string name, int level, int health, int armor, int mokang, int AD, double AS, int range, int initMana, int maxMana,
		damageType type, function<int(Hero&, int)> skill, double release_time) :
		// 构造时需要输入的参数
		m_level(level), m_name(name), m_health(health), m_armor(armor), m_mokang(mokang), m_AD(AD), m_AS(AS), m_range(range),
		m_initMana(initMana), m_maxMana(maxMana), m_type(type), m_skill(skill), m_release_time(release_time),
		// 构造时默认的参数（注意 m_equips()的赋值）
		m_extra_health(0), m_AP(0), m_baoji(0.25), m_baoshang(1.4), m_xixie(0), m_ratio_AD(1.0), m_ratio_AS(1.0), m_ratio_damage(1.0),
		m_count_Attacks(0), m_count_Skills(0), m_huilan(10), if_Skill_Crit(false), m_equips(0, 0, 0, 0, false, false) {}

	void show() {
		cout << "***英雄属性***\n" << m_name << " (" << m_level << "星)"
			<< "\n生命值:" << m_health + m_extra_health << "\t护甲:" << m_armor
			<< "\n魔抗:" << m_mokang << "\t\t基础物攻:" << m_AD
			<< "\n法强:" << m_AP << "\t\t基础攻速:" << m_AS
			<< "\n当前物攻:" << m_ratio_AD * m_AD << "\t当前攻速:" << m_ratio_AS * m_AS
			<< "\n伤害倍率:" << m_ratio_damage << "\t攻击距离:" << m_range
			<< "\n暴击率:" << m_baoji << "\t暴击伤害:" << m_baoshang
			<< "\n初始法力值:" << m_initMana << "\t法力值:" << m_maxMana
			<< "\n伤害类型:" << (m_type == 0 ? "AD" : "AP")
			<< "\t技能释放时长:" << m_release_time << "s\n\n";
	}

	void initHero() {
		m_extra_health = 0;				// 额外生命值
		m_AP = 0;						// 法强
		m_baoji = 0.25;					// 暴击率
		m_baoshang = 1.4;				// 暴击伤害
		m_xixie = 0;					// 全能吸血
		m_ratio_AD = m_ratio_AS = m_ratio_damage = 1;	// 攻击倍率、攻速倍率、伤害倍率
		m_count_Attacks = m_count_Skills = 0;			// 攻击次数、技能释放次数
		m_huilan = 10;					// 攻击回蓝
		if_Skill_Crit = false;			// 技能是否暴击
		m_equips.initAddedEquip();		// 清空装备属性
	}
};

extern Hero Aixi1, Aixi2, Aixi3;