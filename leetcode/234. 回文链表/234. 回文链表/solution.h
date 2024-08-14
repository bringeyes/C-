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
	// �Լ��ķ��� ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
	bool isPalindrome(ListNode* head) {
		if (!head) return true;		// �������ǻ���

		int num = 0, half1 = 0, half2 = 0;
		ListNode* curr = head;

		// �õ��ܽ�����
		while (curr) {
			num++;
			curr = curr->next;
		}
		int* arr = new int[num / 2];

		curr = head;		// ����currָ��
		while (curr) {
			// ���ǰ��������ֵ
			if (half1 < num / 2) {
				arr[half1] = curr->val;	// ������arr[half++]����д��
				half1++; half2++;
			}
			// ���������Ϊ�����������м���
			else if (num % 2 != 0 && half1 == num / 2) { half1++; }
			// �ȽϺ����Ƿ����
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

	// �ȸ��Ƶ������У�Ȼ����˫ָ�뷨���ٷ��ⷨ1��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
	bool isPalindrome_1(ListNode* head) {
		if (!head) return true;		// �������ǻ���

		vector<int> vals;
		while (head != nullptr) {
			// ʹ��β�巨
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

	// �ݹ飨�ٷ��ⷨ2��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
	ListNode* frontPointer;		// ��ͷ������ָ�룬�����ں�����
	bool isPalindrome_2(ListNode* head) {
		if (!head) return true;		// �������ǻ���
		frontPointer = head;

		return recursivelyCheck(head);
	}
	// �ݹ���
	// �ڵݹ����ʱ��ջ��洢�˵�ǰ���curr����˿ռ临�Ӷ�ΪO(n)������O(1)
	bool recursivelyCheck(ListNode* curr) {
		// �ݹ���ֹ����
		if (!curr) return true;

		// �����ݻ�����ֵ��true���ҵ�ǰ����ֵ�����������ʱ�ŷ���true������false
		if (recursivelyCheck(curr->next) && curr->val == frontPointer->val) {
			// �ƶ�frontPointer
			frontPointer = frontPointer->next;
			return true;
		}
		return false;
	}

	/*
	˼·:
	����ʹ�� O(n) ����ռ�ķ������Ǹı����롣
	���ǿ��Խ�����ĺ�벿�ַ�ת���޸�����ṹ����Ȼ��ǰ�벿�ֺͺ�벿�ֽ��бȽϡ��Ƚ���ɺ�����Ӧ�ý�����ָ�ԭ������Ȼ����Ҫ�ָ�Ҳ��ͨ����������������ʹ�øú�������ͨ����ϣ������ṹ�����ġ�
	�÷�����Ȼ���Խ��ռ临�ӶȽ��� O(1)�������ڲ��������£��÷���Ҳ��ȱ�㡣�ڲ��������£���������ʱ��Ҫ���������̻߳���̶�����ķ��ʣ���Ϊ�ں���ִ�й���������ᱻ�޸ġ�

	�������̿��Է�Ϊ����������裺
		�ҵ�ǰ�벿�������β�ڵ㣬ͬʱ��תǰ�벿������
			(����ͨ��һ�α����õ��ܽ�������Ҳ�����ÿ���ָ����һ�α������ҵ�ǰ�벿��β��㣬��--һ��2������--һ��1��)
		�ж��Ƿ���ġ�
		�ָ�����
		���ؽ����
	*/
	bool isPalindrome_3(ListNode* head) {
		if (!head || !head->next)
			return true;		// �������ֻ��һ���ڵ�������ǻ���

		bool isPalindrome = true;
		ListNode* slow = head, * fast = head, * prev = nullptr, * curr = head;

		// ʹ�ÿ���ָ���ҵ�������м�ڵ�
		while (fast && fast->next) {
			fast = fast->next->next;

			// ��תǰ�벿������
			ListNode* next = slow->next;
			slow->next = prev;
			prev = slow;
			slow = next;
		}
		// slow ���ǰ�벿�ַ�ת���νӵĽ��

		// �ȽϷ�ת���ǰ�벿�ֺͺ�벿��
		ListNode* firstHalf = prev;
		ListNode* secondHalf = fast ? slow->next : slow;		// ���������ʱ�������м���

		while (secondHalf) {
			if (firstHalf->val != secondHalf->val) {
				isPalindrome = false;
				break;
			}
			firstHalf = firstHalf->next;
			secondHalf = secondHalf->next;
		}

		// ��ԭ������תǰ�벿������
		ListNode* newPrev = nullptr;
		while (prev) {
			ListNode* next = prev->next;
			prev->next = newPrev;
			newPrev = prev;

			if (!prev->next) prev->next = slow;		// ��ԭ����ʱ�νӻ�ԭ����
			prev = next;
		}

		return isPalindrome;
	}
};
