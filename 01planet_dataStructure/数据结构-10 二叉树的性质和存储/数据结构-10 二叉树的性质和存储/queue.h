#pragma once
#include <iostream>
using namespace std;

// ��ʽ���н��
template<typename T>
struct Qnode
{
	T data;
	Qnode* next;

	Qnode() :next(nullptr) {}
	Qnode(T x) :data(x), next(nullptr) {}
};
template<typename T>
struct Queue
{
	Qnode<T>* front;		// ����
	Qnode<T>* rear;		// ��β

	Queue() { front = rear = new Qnode<T>; }	// ��һ����㲻�������
	~Queue() {
		while (front) {
			Qnode<T>* next = front->next;
			delete front;
			front = next;
		}
	}

	// �ж϶����Ƿ�Ϊ�գ�Ϊ��true����Ϊ��false
	bool empty() const {
		return front->next == nullptr;
	}

	// β�巨���
	void enqueue(T x) {
		rear->next = new Qnode<T>(x);			// ע����new��ʱ����ʾָ��ģ�����
		rear = rear->next;
		if (!front->next) front->next = rear;	// �����ӵ�����Ԫ����Ҫ����ͷָ���ϵ
	}

	// ����
	T dequeue() {
		if (empty()) return '\0';

		Qnode<T>* q = front->next;
		T x = q->data;		// ��������
		front->next = q->next;
		delete q;
		q = nullptr;
		return x;
	}

	void print()const {
		if (empty()) { cout << "����Ϊ��" << endl; return; }

		Qnode<T>* curr = front->next;	// ��Ԫ���
		while (curr) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
		cout << endl;
	}
};