#include "solution.h"

void printList(ListNode* head) {
	if (!head) return;
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}

void head_insert(ListNode* head, int x) {
	if (!head) return;
	ListNode* tmp = new ListNode(x, head->next);
	head->next = tmp;
}