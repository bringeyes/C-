#pragma once
#include <iostream>
#include "Hero.h"
#include "Equipment.h"

// 伤害计算，参数：被测目标-target，测试时长-time
int calculateDamage(Hero& target, int time);

// 坦度计算，参数：被测目标-target，测试时长-time
int calculateTankiness(Hero& target, int time);

// 计算伤害范围，返回值：最低伤害；参数：被测目标-target，传入装备-Equips[3]，测试次数-num
void Get_RangeOfDamage(Hero& target, Equipment Equips[3], int num);

// 返回值：英雄&装备组合的最小伤害，参数：被测目标-target，传入装备-Equips[3]，测试次数-num，测试时间：1,2星英雄-25秒；3星英雄-15秒
int Get_Min_Damage(Hero& target, Equipment Equips[3], int num);

// 测试流程，参数：被测目标-target，传入装备的备选组合-Equip_combine[]，组合包含的装备数-num
void Test_Process(Hero& target, Equipment Equip_combine[], int num);

// 返回与给定值匹配的键，如果找不到，则返回 nullptr
Equipment* findKeyByValue(const unordered_map<Equipment*, int>& map, int value);

// 释放二维数组
void releaseArray(Equipment** arr, int rows);

// 快速排序
void quickSort(int arr[], unsigned int len);

// 打印数组
void printList(int arr[], int len);