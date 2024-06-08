#pragma once
#include <iostream>
#include "Hero.h"
#include "Equipment.h"

// �˺����㣬����������Ŀ��-target������ʱ��-time
int calculateDamage(Hero& target, int time);

// ̹�ȼ��㣬����������Ŀ��-target������ʱ��-time
int calculateTankiness(Hero& target, int time);

// �����˺���Χ������ֵ������˺�������������Ŀ��-target������װ��-Equips[3]�����Դ���-num
void Get_RangeOfDamage(Hero& target, Equipment Equips[3], int num);

// ����ֵ��Ӣ��&װ����ϵ���С�˺�������������Ŀ��-target������װ��-Equips[3]�����Դ���-num������ʱ�䣺1,2��Ӣ��-25�룻3��Ӣ��-15��
int Get_Min_Damage(Hero& target, Equipment Equips[3], int num);

// �������̣�����������Ŀ��-target������װ���ı�ѡ���-Equip_combine[]����ϰ�����װ����-num
void Test_Process(Hero& target, Equipment Equip_combine[], int num);

// ���������ֵƥ��ļ�������Ҳ������򷵻� nullptr
Equipment* findKeyByValue(const unordered_map<Equipment*, int>& map, int value);

// �ͷŶ�ά����
void releaseArray(Equipment** arr, int rows);

// ��������
void quickSort(int arr[], unsigned int len);

// ��ӡ����
void printList(int arr[], int len);