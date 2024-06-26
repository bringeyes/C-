#pragma once
#include <unordered_map>
#include "Hero.h"

typedef void (*Equipment)(Hero& target);			// 定义装备函数指针

extern unordered_map<Equipment, string> Equip_Name;		// 定义一个字典，存放 装备函数名——装备名 键值对

extern Equipment All_Equips[9];

// 得到装备组合
Equipment** Get_Equip_Combination(Equipment Equips[], int num);

// 添加装备
void add_Equips(Hero& target, Equipment equips[3]);

// 显示装备
void show_Equips(Equipment Equips[3]);

// 空的装备槽
void NoEquip(Hero& target);

// 无尽之刃
void Wujin(Hero& target);

// 鬼索的狂暴之刃
void Guisuo(Hero& target);

// 锐利之刃
void Ruili(Hero& target);

// 红霸符
void HongBUFF(Hero& target);

// 巨人杀手
void JuSha(Hero& target);

// 破防者
void PoFang(Hero& target);

// 正义之手
void ZhengYi(Hero& target);

// 水银
void ShuiYin(Hero& target);

// 最后的轻语
void QingYu(Hero& target);

// 卢安娜的飓风
void JuFeng(Hero& target);

// 朔极之矛
void ShuoJi(Hero& target);