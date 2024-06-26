/*

*/

#include <iostream>
#include "Hero.h"
#include "Skill.h"
#include "Equipment.h"
#include "Tools.h"
using namespace std;

int main()
{
	// 初始化随机数种子
	srand(static_cast<unsigned>(time(0)));

	// 被测装备组合
	Equipment Equips[7] = {
	Wujin,Guisuo,Ruili,HongBUFF,QingYu,JuFeng,ShuoJi		// JuSha,PoFang,
	};

	Test_Process(Aixi1, Equips, 7);
}