#include "test.h"

//void test01() {
//	Tree* t1 = new Tree;
//	for (int i = 0; i < 3; i++)
//		t1->create_ch(i - 1, 100 - 10 * i);
//	for (int i = 0; i < 3; i++)
//		t1->create_ch(1, i + 5);
//	t1->display();
//
//	cout << "find(80) = " << t1->find(80) << endl;
//	cout << "find_pa(5) = " << t1->find_pa(5) << endl;
//	cout << "find_ch(90) =" << t1->find_ch(90) << endl;
//}
//
//void test02() {
//	//Tree_2* t2 = new Tree_2(3);
//
//	Tree_2 t2(3);
//	t2.printTree();
//
//	t2.addNode(3, 5);
//	t2.addNode(3, 7);
//
//	t2.addNode(5, 9);
//	t2.addNode(5, 11);
//
//	t2.printTree();
//
//	t2.addNode(4, 4);	// 测试结点不存在的情况
//	cout << t2.find(4) << endl;
//
//	cout << t2.find(7) << endl;
//	cout << t2.find_ch(3) << endl;
//	cout << t2.find_ch(11) << endl;
//	cout << t2.find_pa(3) << endl;
//}

void test03() {
	Tree t3('x');
	t3.addNode('x', 'y');
	t3.addNode('x', 'z');
	t3.addNode('y', 'a');
	t3.addNode('y', 'b');
	t3.addNode('y', 'c');
	t3.addNode('z', 'd');
	t3.addNode('z', 'e');

	t3.printTree();

	t3.deleteNode('e');
	t3.printTree();

	t3.deleteNode('y');
	t3.printTree();
}