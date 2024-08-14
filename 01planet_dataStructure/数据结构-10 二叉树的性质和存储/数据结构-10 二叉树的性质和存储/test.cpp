#include "test.h"

// 测试模板template
void test01() {
	// 测试栈结点
	auto* s1 = new Snode<int>(99);
	cout << s1->data << endl;

	// 测试链栈
	auto* S2 = new Stack<int>;
	S2->push(10); S2->push(20); S2->push(30);
	cout << S2->pop() << ' ';
	cout << S2->getTop() << endl;

	// 测试队列
	auto* q1 = new Queue<char>;
	q1->enqueue('3'); q1->enqueue('4'); q1->enqueue('5');
	q1->print();
	q1->dequeue();
	q1->print();
	q1->~Queue();

	// 测试树结点
	auto* t1 = new TreeNode<string>("好");
	cout << t1->data << endl;

	// 测试二叉树
	auto* T2 = new BinaryTree<double>;
	T2->root->data = 3.3;
	T2->addNode(3.3, 2.1);
	T2->addNode(3.3, 3.4, 1);
	T2->addNode(2.1, 1.0, 1);
	T2->addNode(3.4, 4.3);
	T2->addNode(3.4, 4.5, 1);
	T2->printTree();

	T2->levelOrderTraversal();
	T2->inOrderTraversal(T2->root); cout << endl;

	T2->deleteNode(2.1);
	T2->printTree();
}

// 测试二叉树
void test02() {
	// 测试增、删、打印树
	BinaryTree<char> b1;
	b1.root->data = 'A';
	b1.addNode('A', '1');
	b1.addNode('A', '2', 1);
	b1.addNode('1', 'B');
	b1.addNode('1', 'C', 1);
	b1.addNode('2', 'D');
	b1.addNode('2', 'E', 1);
	b1.addNode('B', '3');
	b1.printTree();

	b1.deleteNode('B');
	b1.printTree();

	// 测试入队、出队、打印
	auto* q = new Queue<char>;
	q->enqueue('a');
	q->enqueue('b');
	q->enqueue('c');
	q->print();
	q->dequeue();
	q->print();

	// 测试层次遍历打印
	cout << "层次遍历："; b1.levelOrderTraversal();

	// 测试先序、中序、后序遍历
	cout << "先序遍历："; b1.preOrderTraversal(b1.root); cout << endl;
	cout << "中序遍历："; b1.inOrderTraversal(b1.root); cout << endl;
	cout << "后序遍历："; b1.postOrderTraversal(b1.root); cout << endl;
}

// 测试BUG
void test03() {
	auto s1 = new Stack<int>;

	s1->push(10); s1->push(20); s1->push(30);
	cout << s1->pop() << ' ' << s1->getTop() << endl;	// s1->getTop()应该在执行完s1->pop()后更新为20，但此处显示30
	cout << s1->getTop() << endl;
}