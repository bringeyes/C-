#pragma once
#include <iostream>
using namespace std;

// 链式队列结点
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
	Qnode<T>* front;		// 队首
	Qnode<T>* rear;		// 队尾

	Queue() { front = rear = new Qnode<T>; }	// 留一个结点不存放数据
	~Queue() {
		while (front) {
			Qnode<T>* next = front->next;
			delete front;
			front = next;
		}
	}

	// 判断队列是否为空，为空true，不为空false
	bool empty() const {
		return front->next == nullptr;
	}

	// 尾插法入队
	void enqueue(T x) {
		rear->next = new Qnode<T>(x);			// 注意在new的时候显示指定模板参数
		rear = rear->next;
		if (!front->next) front->next = rear;	// 如果入队的是首元，还要处理头指针关系
	}

	// 出队
	T dequeue() {
		if (empty()) return '\0';

		Qnode<T>* q = front->next;
		T x = q->data;		// 队首数据
		front->next = q->next;
		delete q;
		q = nullptr;
		return x;
	}

	void print()const {
		if (empty()) { cout << "队列为空" << endl; return; }

		Qnode<T>* curr = front->next;	// 首元结点
		while (curr) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
		cout << endl;
	}
};