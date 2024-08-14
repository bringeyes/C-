#pragma once
#include <iostream>
#include <exception>
using namespace std;

// �Զ����쳣��
class StackException :public exception {
public:
	explicit StackException(const char* message) :msg_(message) {}

	virtual const char* what()const noexcept {	// virtualʵ��what()�Ķ�̬��noexcept��Ǻ������׳��쳣
		return msg_;
	}
private:
	const char* msg_;	// ������Ϣ
};

// ��ջ
template<typename T>
struct Snode
{
	T data;
	Snode* next;

	Snode() : next(nullptr) {}
	Snode(T x) :data(x), next(nullptr) {}
};
template<typename T>
struct Stack
{
	Stack() :top(nullptr) {}

	void push(T x) {
		Snode<T>* newNode = new Snode<T>(x);
		newNode->next = top;
		top = newNode;
	}

	T pop() {
		if (empty()) throw StackException("ջΪ��");		// ջΪ��ʱ�׳��쳣

		Snode<T>* oldTop = top;
		top = top->next;
		T data = oldTop->data;
		delete oldTop;
		return data;
	}

	bool empty()const {
		return top == nullptr;
	}

	T getTop()const {
		if (empty()) throw StackException("ջΪ��");
		return top->data;
	}

private:
	Snode<T>* top;		// ջ������ջ��Ԫ��
};
