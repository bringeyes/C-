#pragma once
#include <iostream>
#include <exception>
using namespace std;

// 自定义异常类
class StackException :public exception {
public:
	explicit StackException(const char* message) :msg_(message) {}

	virtual const char* what()const noexcept {	// virtual实现what()的多态，noexcept标记函数不抛出异常
		return msg_;
	}
private:
	const char* msg_;	// 错误消息
};

// 链栈
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
		if (empty()) throw StackException("栈为空");		// 栈为空时抛出异常

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
		if (empty()) throw StackException("栈为空");
		return top->data;
	}

private:
	Snode<T>* top;		// 栈顶（链栈首元）
};
