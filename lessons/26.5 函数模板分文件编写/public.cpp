#include "public.h"

void Swap(int a, int b)		// ��ͨ����
{
	cout << "ʹ������ͨ���� Swap(int a, int b)\n";
}

template <>					// ���廯�ĺ���ģ��
void Swap(int a, int b) {
	cout << "ʹ���˾��廯�ĺ���ģ�� Swap(int a, int b)\n";
}