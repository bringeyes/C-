#pragma once
#include <unordered_map>
#include "Hero.h"

typedef void (*Equipment)(Hero& target);			// ����װ������ָ��

extern unordered_map<Equipment, string> Equip_Name;		// ����һ���ֵ䣬��� װ������������װ���� ��ֵ��

extern Equipment All_Equips[9];

// �õ�װ�����
Equipment** Get_Equip_Combination(Equipment Equips[], int num);

// ���װ��
void add_Equips(Hero& target, Equipment equips[3]);

// ��ʾװ��
void show_Equips(Equipment Equips[3]);

// �յ�װ����
void NoEquip(Hero& target);

// �޾�֮��
void Wujin(Hero& target);

// �����Ŀ�֮��
void Guisuo(Hero& target);

// ����֮��
void Ruili(Hero& target);

// ��Է�
void HongBUFF(Hero& target);

// ����ɱ��
void JuSha(Hero& target);

// �Ʒ���
void PoFang(Hero& target);

// ����֮��
void ZhengYi(Hero& target);

// ˮ��
void ShuiYin(Hero& target);

// ��������
void QingYu(Hero& target);

// ¬���ȵ�쫷�
void JuFeng(Hero& target);

// ˷��֮ì
void ShuoJi(Hero& target);