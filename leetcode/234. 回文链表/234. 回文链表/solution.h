#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* head);

void head_insert(ListNode* head, int x);

class Solution {
public:
	// 自己的方法 时间复杂度O(n)，空间复杂度O(n)
	bool isPalindrome(ListNode* head) {
		if (!head) return true;		// 空链表是回文

		int num = 0, half1 = 0, half2 = 0;
		ListNode* curr = head;

		// 得到总结点个数
		while (curr) {
			num++;
			curr = curr->next;
		}
		int* arr = new int[num / 2];

		curr = head;		// 充置curr指针
		while (curr) {
			// 存放前半段链表的值
			if (half1 < num / 2) {
				arr[half1] = curr->val;	// 不能用arr[half++]这种写法
				half1++; half2++;
			}
			// 如果结点个数为奇数，跳过中间结点
			else if (num % 2 != 0 && half1 == num / 2) { half1++; }
			// 比较后半段是否回文
			else {
				half2--;
				if (curr->val != arr[half2]) {
					delete[] arr;
					return false;
				}
			}

			curr = curr->next;
		}
		delete[] arr;
		return true;
	}

	// 先复制到数组中，然后用双指针法（官方解法1）时间复杂度O(n)，空间复杂度O(n)
	bool isPalindrome_1(ListNode* head) {
		if (!head) return true;		// 空链表是回文

		vector<int> vals;
		while (head != nullptr) {
			// 使用尾插法
			vals.emplace_back(head->val);
			head = head->next;
		}
		for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
			if (vals[i] != vals[j]) {
				return false;
			}
		}
		return true;
	}

	// 递归（官方解法2）时间复杂度O(n)，空间复杂度O(n)
	ListNode* frontPointer;		// 从头遍历的指针，定义在函数外
	bool isPalindrome_2(ListNode* head) {
		if (!head) return true;		// 空链表是回文
		frontPointer = head;

		return recursivelyCheck(head);
	}
	// 递归检查
	// 在递归调用时，栈里存储了当前层的curr，因此空间复杂度为O(n)而不是O(1)
	bool recursivelyCheck(ListNode* curr) {
		// 递归终止条件
		if (!curr) return true;

		// 当传递回来的值是true，且当前结点的值满足回文条件时才返回true，否则false
		if (recursivelyCheck(curr->next) && curr->val == frontPointer->val) {
			// 移动frontPointer
			frontPointer = frontPointer->next;
			return true;
		}
		return false;
	}

	/*
	思路:
	避免使用 O(n) 额外空间的方法就是改变输入。
	我们可以将链表的后半部分反转（修改链表结构），然后将前半部分和后半部分进行比较。比较完成后我们应该将链表恢复原样。虽然不需要恢复也能通过测试用例，但是使用该函数的人通常不希望链表结构被更改。
	该方法虽然可以将空间复杂度降到 O(1)，但是在并发环境下，该方法也有缺点。在并发环境下，函数运行时需要锁定其他线程或进程对链表的访问，因为在函数执行过程中链表会被修改。

	整个流程可以分为以下五个步骤：
		找到前半部分链表的尾节点，同时反转前半部分链表。
			(可以通过一次遍历得到总结点个数，也可以用快慢指针在一次遍历总找到前半部分尾结点，快--一次2步、慢--一次1步)
		判断是否回文。
		恢复链表。
		返回结果。
	*/
	bool isPalindrome_3(ListNode* head) {
		if (!head || !head->next)
			return true;		// 空链表或只有一个节点的链表是回文

		bool isPalindrome = true;
		ListNode* slow = head, * fast = head, * prev = nullptr, * curr = head;

		// 使用快慢指针找到链表的中间节点
		while (fast && fast->next) {
			fast = fast->next->next;

			// 反转前半部分链表
			ListNode* next = slow->next;
			slow->next = prev;
			prev = slow;
			slow = next;
		}
		// slow 存放前半部分反转后衔接的结点

		// 比较反转后的前半部分和后半部分
		ListNode* firstHalf = prev;
		ListNode* secondHalf = fast ? slow->next : slow;		// 结点奇数个时，跳过中间结点

		while (secondHalf) {
			if (firstHalf->val != secondHalf->val) {
				isPalindrome = false;
				break;
			}
			firstHalf = firstHalf->next;
			secondHalf = secondHalf->next;
		}

		// 还原链表，反转前半部分链表
		ListNode* newPrev = nullptr;
		while (prev) {
			ListNode* next = prev->next;
			prev->next = newPrev;
			newPrev = prev;

			if (!prev->next) prev->next = slow;		// 还原结束时衔接回原链表
			prev = next;
		}

		return isPalindrome;
	}
};
