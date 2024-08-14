#include "circular_linkedList.h"

cList init_cList() {
	cList l = new(nothrow) cNode;		// ʹ��new(std::nothrow)������ʧ��ʱ���ؿ�ָ�룬�������׳��쳣
	if (l == nullptr) return l;			// �ڴ����ʧ��

	l->next = l;			// ��ʼ��ָ��ͷ����Լ�
	return l;
}

// ͷ��㲻�������ݣ��ڱ���㣩
void printList(cList l) {
	if (l == nullptr) return;

	cList tmp = l->next;
	while (tmp != l) {
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	cout << endl;
}

// ͷ�巨�����ٿ��Ǻ�̽���Ƿ�գ�
void head_insert(cList l, int x) {
	if (l == nullptr) return;
	cList tmp = new cNode; tmp->data = x;

	tmp->next = l->next;
	l->next = tmp;
}

// β�巨��β����nextָ��ͷ��㣩
void tail_insert(cList l, int x) {
	if (l == nullptr) return;

	cList head = l;
	while (l->next != head) {
		l = l->next;
	}
	cList tmp = new cNode; tmp->data = x;

	tmp->next = head;
	l->next = tmp;
}

// ɾ����㣨Ҫ�࿼��ֻ��һ�����������
void delete_node(cList l, int k) {
	if (l == nullptr) return;
	// ���ѭ������ֻ��һ��Ԫ��
	if (l->next == l) {
		if (l->data == k) {
			delete l;
			l = nullptr;
			return;
		}
		else return;
	}

	// ѭ��������Ҫô�ҵ�kֵ��Ҫô��������Ҳû�ҵ�
	// ����д��Ч�ʸ���
	while (l->next != l && l->next->data != k) {
		l = l->next;
	}
	if (l->next == l) return;		// û�ҵ��ͷ���

	cList tmp = l->next;
	l->next = tmp->next;
	delete tmp;
	tmp = nullptr;
}

// ���½�㣨Ҫ�࿼��ֻ��һ�����������
void update_node(cList l, int k, int x) {
	if (l == nullptr) return;
	// ���ѭ������ֻ��һ��Ԫ��
	if (l->next == l) {
		if (l->data == k) {
			l->data = x;
			return;
		}
		else return;
	}

	cList p = l->next;
	while (p != l && p->data != k) {
		p = p->next;
	}
	if (p == l) return;		// û�ҵ��ͷ���

	p->data = x;
}