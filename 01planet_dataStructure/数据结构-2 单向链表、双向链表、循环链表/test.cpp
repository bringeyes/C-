#include "test.h"

void test01() {
	linklist l = initList();
	// 测试头插法和尾插法
	for (int i = 0; i < 10; i++) {
		head_insert(l, i);
	}
	for (int i = 0; i < 5; i++) {
		tail_insert(l, i * 10);
	}
	printList(l);

	// 测试结点删除
	delete_node(l, 10);
	printList(l);

	// 测试改结点值
	update_node(l, 20, 99);
	printList(l);
}

void test02() {
	dList l = init_dList();
	// 测试头插法和尾插法
	for (int i = 0; i < 10; i++) {
		head_insert(l, i);
	}
	for (int i = 0; i < 5; i++) {
		tail_insert(l, i * 10);
	}
	printList(l);

	// 测试结点删除
	delete_node(l, 10);
	printList(l);

	// 测试改结点值
	update_node(l, 20, 99);
	printList(l);
}
/*
void test02_time() {
	chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
	chrono::nanoseconds dt;     // 时间差
	int n = 10;
	while (n--) {
		start = chrono::steady_clock::now();        // 开始计时
		for (int i = 0; i < 100000; i++) {             // 执行一百万次
			// 填入要测时的代码
			test02_1();
		}
		end = chrono::steady_clock::now();          // 计时完成
		dt = end - start;                                       // 计算时间差
		cout << "test02_1();耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

		//————————————————————————————————————————————————————————————————————————————————

		start = chrono::steady_clock::now();        // 开始计时
		for (int i = 0; i < 100000; i++) {             // 执行一百万次
			// 填入要测时的代码
			test02_2();
		}
		end = chrono::steady_clock::now();          // 计时完成
		dt = end - start;                                       // 计算时间差
		cout << "test02_2();耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间
	}
}
*/

void test03() {
	cList l = init_cList();

	// 测试头插法和尾插法
	for (int i = 0; i < 10; i++) {
		head_insert(l, i);
	}
	for (int i = 0; i < 5; i++) {
		tail_insert(l, i * 10);
	}
	printList(l);

	// 测试结点删除
	delete_node(l, 10);
	printList(l);

	// 测试改结点值
	update_node(l, 20, 99);
	printList(l);
}