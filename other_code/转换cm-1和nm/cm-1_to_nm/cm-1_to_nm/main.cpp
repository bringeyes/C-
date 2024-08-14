/*

*/

#include <iostream>
using namespace std;

int cm1_to_nm(int cm1) {
	return 10000000 / cm1;
}

int nm_to_cm1(int nm) {
	return 10000000 / nm;
}

double C_to_K(double C) {
	return C + 273.15;
}

double K_to_C(double K) {
	return K - 273.15;
}

int main()
{
	int index = 0, num = 0;
	cout << "cm-1 转换为 nm（1）\nnm 转换为 cm-1（2）" << endl;
	while (1) {
		cin >> index;
		switch (index)
		{
		case 1:
			cout << "请输入值（cm-1）："; cin >> num;
			cout << cm1_to_nm(num) <<'\n' << endl;
			break;
		case 2:
			cout << "请输入值（nm）："; cin >> num;
			cout << nm_to_cm1(num) << '\n' << endl;
		}
	}
}