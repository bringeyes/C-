#include "Skill.h"

// 艾希
int skill_Aixi(Hero& target, int level) {
	/*
	* 技能描述：
	技能名：万箭齐发
	被动：战斗开始时拥有15根箭矢。每3次攻击获得(1/1/3)level根箭矢。（当前箭矢数：）
	主动：对当前进行一次箭矢齐射，每支已储存的箭矢造成(40%/40%/100%)AD+(4%/6%/20%)AP 物理伤害，
		总计造成()物理伤害，由目标和距离内相距最近的3个敌人均摊。
	*/
	double add_AD, add_AP;				// 技能的AD/AP加成
	int	arrows = 15;						// 箭矢数
	int add_arrow;						// 每3次攻击获得的箭矢数
	int damage = 0;						// 技能伤害

	// 根据英雄星级调整技能加成
	switch (level) {
	case 1:
		add_AD = 0.4; add_AP = 0.04; add_arrow = 1;
		break;
	case 2:
		add_AD = 0.4; add_AP = 0.06; add_arrow = 1;
		break;
	case 3:
		add_AD = 1.0; add_AP = 0.2; add_arrow = 3;
		break;
	default:
		cout << "英雄星级输入错误，正确范围{1,2,3}。\n";
		break;
	}

	int current_AD = target.m_ratio_AD * target.m_AD;					// 计算当前物攻
	arrows = 15 + (target.m_count_Attacks / 3) * add_arrow;				// 计算当前箭矢数
	damage = arrows * (add_AD * current_AD + add_AP * target.m_AP);		// 计算技能伤害

	// 如果技能可以暴击，根据暴击率计算技能伤害
	if (target.if_Skill_Crit == true) {
		if ((static_cast<double>(rand()) / RAND_MAX) <= target.m_baoji) {
			damage *= target.m_baoshang;
			/*cout << "技能暴击！";*/
		}
	}

	damage *= target.m_ratio_damage;					// 乘以伤害倍率
	/*cout << "第" << target.m_count_Skills << "次技能伤害：" << damage << endl;*/

	return damage;
}