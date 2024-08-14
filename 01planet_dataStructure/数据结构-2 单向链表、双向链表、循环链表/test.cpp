#include "test.h"

void test01() {
	linklist l = initList();
	// ����ͷ�巨��β�巨
	for (int i = 0; i < 10; i++) {
		head_insert(l, i);
	}
	for (int i = 0; i < 5; i++) {
		tail_insert(l, i * 10);
	}
	printList(l);

	// ���Խ��ɾ��
	delete_node(l, 10);
	printList(l);

	// ���ԸĽ��ֵ
	update_node(l, 20, 99);
	printList(l);
}

void test02() {
	dList l = init_dList();
	// ����ͷ�巨��β�巨
	for (int i = 0; i < 10; i++) {
		head_insert(l, i);
	}
	for (int i = 0; i < 5; i++) {
		tail_insert(l, i * 10);
	}
	printList(l);

	// ���Խ��ɾ��
	delete_node(l, 10);
	printList(l);

	// ���ԸĽ��ֵ
	update_node(l, 20, 99);
	printList(l);
}
/*
void test02_time() {
	chrono::steady_clock::time_point start, end;    // start-��ʱ��ʼ��end-��ʱ���
	chrono::nanoseconds dt;     // ʱ���
	int n = 10;
	while (n--) {
		start = chrono::steady_clock::now();        // ��ʼ��ʱ
		for (int i = 0; i < 100000; i++) {             // ִ��һ�����
			// ����Ҫ��ʱ�Ĵ���
			test02_1();
		}
		end = chrono::steady_clock::now();          // ��ʱ���
		dt = end - start;                                       // ����ʱ���
		cout << "test02_1();��ʱ��" << (double)dt.count() / (1000 * 1000 * 1000) << "�롣\n";   // ��ʾ����ʱ��

		//����������������������������������������������������������������������������������������������������������������������������������������������������������������

		start = chrono::steady_clock::now();        // ��ʼ��ʱ
		for (int i = 0; i < 100000; i++) {             // ִ��һ�����
			// ����Ҫ��ʱ�Ĵ���
			test02_2();
		}
		end = chrono::steady_clock::now();          // ��ʱ���
		dt = end - start;                                       // ����ʱ���
		cout << "test02_2();��ʱ��" << (double)dt.count() / (1000 * 1000 * 1000) << "�롣\n";   // ��ʾ����ʱ��
	}
}
*/

void test03() {
	cList l = init_cList();

	// ����ͷ�巨��β�巨
	for (int i = 0; i < 10; i++) {
		head_insert(l, i);
	}
	for (int i = 0; i < 5; i++) {
		tail_insert(l, i * 10);
	}
	printList(l);

	// ���Խ��ɾ��
	delete_node(l, 10);
	printList(l);

	// ���ԸĽ��ֵ
	update_node(l, 20, 99);
	printList(l);
}