#pragma once
#include <iostream>
#include <functional>
using namespace std;

enum damageType { AD, AP };	// �˺�����

class AddedEquip {
public:
	int a_guisuo;			// �����Ŀ�֮��
	int a_jusha;			// ����ɱ��
	int a_pofang;			// �Ʒ���
	int a_jufeng;			// ¬���ȵ�쫷�
	bool a_shuiyin;			// ˮ��
	bool a_qingyu;			// ����
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
	string m_name;			// ����
	const int m_level;		// �Ǽ�
	const int m_health;		// ��������ֵ
	int m_extra_health;		// ��������ֵ
	int m_armor;			// ����
	int m_mokang;			// ħ��
	const int m_AD;			// �����﹥
	int m_AP;				// ��ǿ
	const double m_AS;		// ��������
	double m_baoji;			// ������
	double m_baoshang;		// �����˺�
	double m_xixie;			// ȫ����Ѫ
	int m_range;				// ��������
	int m_initMana;			// ��ʼ����ֵ
	int m_maxMana;			// �����ֵ
	double m_ratio_AD;		// ��ǰ�﹥����
	double m_ratio_AS;		// ��ǰ���ٱ���
	double m_ratio_damage;	// �˺�����
	int m_count_Attacks;		// ��������
	int m_count_Skills;		// �����ͷŴ���
	int m_huilan;			// ��������
	damageType m_type;		// �˺�����
	function<int(Hero&, int)> m_skill;		// ����
	double m_release_time;	// �����ͷ�ʱ��
	bool if_Skill_Crit;		// �����Ƿ���Ա���
	AddedEquip m_equips;		// �����װ��

	Hero(string name, int level, int health, int armor, int mokang, int AD, double AS, int range, int initMana, int maxMana,
		damageType type, function<int(Hero&, int)> skill, double release_time) :
		// ����ʱ��Ҫ����Ĳ���
		m_level(level), m_name(name), m_health(health), m_armor(armor), m_mokang(mokang), m_AD(AD), m_AS(AS), m_range(range),
		m_initMana(initMana), m_maxMana(maxMana), m_type(type), m_skill(skill), m_release_time(release_time),
		// ����ʱĬ�ϵĲ�����ע�� m_equips()�ĸ�ֵ��
		m_extra_health(0), m_AP(0), m_baoji(0.25), m_baoshang(1.4), m_xixie(0), m_ratio_AD(1.0), m_ratio_AS(1.0), m_ratio_damage(1.0),
		m_count_Attacks(0), m_count_Skills(0), m_huilan(10), if_Skill_Crit(false), m_equips(0, 0, 0, 0, false, false) {}

	void show() {
		cout << "***Ӣ������***\n" << m_name << " (" << m_level << "��)"
			<< "\n����ֵ:" << m_health + m_extra_health << "\t����:" << m_armor
			<< "\nħ��:" << m_mokang << "\t\t�����﹥:" << m_AD
			<< "\n��ǿ:" << m_AP << "\t\t��������:" << m_AS
			<< "\n��ǰ�﹥:" << m_ratio_AD * m_AD << "\t��ǰ����:" << m_ratio_AS * m_AS
			<< "\n�˺�����:" << m_ratio_damage << "\t��������:" << m_range
			<< "\n������:" << m_baoji << "\t�����˺�:" << m_baoshang
			<< "\n��ʼ����ֵ:" << m_initMana << "\t����ֵ:" << m_maxMana
			<< "\n�˺�����:" << (m_type == 0 ? "AD" : "AP")
			<< "\t�����ͷ�ʱ��:" << m_release_time << "s\n\n";
	}

	void initHero() {
		m_extra_health = 0;				// ��������ֵ
		m_AP = 0;						// ��ǿ
		m_baoji = 0.25;					// ������
		m_baoshang = 1.4;				// �����˺�
		m_xixie = 0;					// ȫ����Ѫ
		m_ratio_AD = m_ratio_AS = m_ratio_damage = 1;	// �������ʡ����ٱ��ʡ��˺�����
		m_count_Attacks = m_count_Skills = 0;			// ���������������ͷŴ���
		m_huilan = 10;					// ��������
		if_Skill_Crit = false;			// �����Ƿ񱩻�
		m_equips.initAddedEquip();		// ���װ������
	}
};

extern Hero Aixi1, Aixi2, Aixi3;