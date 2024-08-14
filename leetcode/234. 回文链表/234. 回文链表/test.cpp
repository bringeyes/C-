#include "test.h"

void test01() {
	ListNode* l1 = new ListNode;
	for (int i = 0; i < 5; i++) head_insert(l1, 2 * i);
	printList(l1);

	Solution s;
	cout << s.isPalindrome(l1) << endl;

	for (int i = 3; i > 0; i--) head_insert(l1, i * 2);
	printList(l1);
	cout << s.isPalindrome(l1) << endl;

	ListNode* l2 = new ListNode(1);
	for (int i = 0; i < 2; i++) head_insert(l2, 0);
	printList(l2);
	cout << s.isPalindrome(l2) << endl;
}

void test02() {
	ListNode* l1 = new ListNode;
	for (int i = 0; i < 5; i++) head_insert(l1, 2 * i);
	printList(l1);

	Solution s;
	cout << s.isPalindrome_1(l1) << endl;

	for (int i = 3; i > 0; i--) head_insert(l1, i * 2);
	printList(l1);
	cout << s.isPalindrome_1(l1) << endl;

	ListNode* l2 = new ListNode(1);
	for (int i = 0; i < 2; i++) head_insert(l2, 0);
	printList(l2);
	cout << s.isPalindrome_1(l2) << endl;
}

void test03() {
	ListNode* l1 = new ListNode;
	for (int i = 0; i < 5; i++) head_insert(l1, 2 * i);
	printList(l1);

	Solution s;
	cout << s.isPalindrome_2(l1) << endl;

	for (int i = 3; i > 0; i--) head_insert(l1, i * 2);
	printList(l1);
	cout << s.isPalindrome_2(l1) << endl;

	ListNode* l2 = new ListNode(1);
	for (int i = 0; i < 2; i++) head_insert(l2, 0);
	printList(l2);
	cout << s.isPalindrome_2(l2) << endl;
}

void test04() {
	ListNode* l1 = new ListNode;
	for (int i = 0; i < 6; i++) head_insert(l1, 2 * i);
	printList(l1);

	Solution s;
	cout << s.isPalindrome_3(l1) << endl;
	printList(l1); cout << "！！！！！！！！！！！！！！！！！！！！！！！！" << endl;

	for (int i = 4; i > 0; i--) head_insert(l1, i * 2);
	printList(l1);
	cout << s.isPalindrome_3(l1) << endl;
	printList(l1); cout << "！！！！！！！！！！！！！！！！！！！！！！！！" << endl;
}