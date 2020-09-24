#include <string>  
#include "vld.h"		 //проверка на утечки
template<typename T>
class LinkedListStack			    //реализация стека через связный список
{
	T data;
	LinkedListStack* next;
	LinkedListStack(LinkedListStack* h, const T& t) :next(h),data(t){	}
public:

	LinkedListStack<T>() { next = 0; }
	void push(const T& t) {
		this->next = new LinkedListStack(this->next, data);
		this->data = t;
	}
	T pop() {
		T t = this->data;
		LinkedListStack* prev = this->next;
		this->data = prev->data;
		this->next = prev->next;
		delete prev;
		return t;
	}
	void clean() {
		while (this->next) {
			pop();
		}
	}
};
template<typename T>
class ArrayStack 					//реализация стека через массив
{
	T* data;
	size_t amount;
	size_t capacity;
public:
	ArrayStack<T>() { 
		amount = 0;
		capacity = 10;
		data = new T[capacity];
	}
	void push(const T& t) {
		if (amount < capacity) {
			data[amount] = t;
		}
		else {
			T* newData = new T[capacity+10];
			for (int i = 0; i != capacity; ++i) {
				newData[i] = data[i];
			}
			newData[capacity] = t;
			capacity += 10;
			delete[] data;
			data = newData;
		}
		amount++;
	}
	T pop() {
		if(amount>0)
		return data[-1+amount--];
		
	}
	void clean() {
		delete[] data;
	}
};

//--------------------------------тесты------------------------------------------------------

LinkedListStack<int>* constructor_createEmptyLinkedListStackOfInt_returnVoid() {
	return new LinkedListStack<int>();
}
void push_pushIntsToLinkedListStack_returnVoid(LinkedListStack<int>* stack) {
	stack->push(1);
	stack->push(2);
	stack->push(3);

 }
void pop_popIntsToLinkedListStack_returnInt(LinkedListStack<int>* stack) {
	stack->pop();		//return 3
	stack->pop();		//return 2
}
void clean_cleanLinkedListStack_returnVoid(LinkedListStack<int>* stack) {
	stack->clean();
	delete stack;
}

ArrayStack<int>* constructor_createEmptyArrayStackOfInt_returnVoid() {
	return new ArrayStack<int>();
}
void push_pushIntsToArrayStack_returnVoid(ArrayStack<int>* stack) {
	for (int i = 0; i != 11; ++i)
		stack->push(i);

}
void pop_popIntsToArrayStack_returnInt(ArrayStack<int>* stack) {
	stack->pop();		//return 10
	stack->pop();		//return 9
}
void clean_cleanArrayStack_returnVoid(ArrayStack<int>* stack) {
	stack->clean();
	delete stack;
}

LinkedListStack<std::string>* constructor_createEmptyLinkedListStackOfString_returnVoid() {
	return new LinkedListStack<std::string>();
}
void push_pushStringsToLinkedListStack_returnVoid(LinkedListStack<std::string>* stack) {
	stack->push("abc");
	stack->push("123");
	stack->push("Hello stack!");

}
void pop_popStringsToLinkedListStack_returnStrings(LinkedListStack<std::string>* stack) {
	stack->pop();		//return Hello stack!
	stack->pop();		//return 123
}
void clean_cleanLinkedListStack_returnVoid(LinkedListStack<std::string>* stack) {
	stack->clean();
	delete stack;
}

ArrayStack<std::string>* constructor_createEmptyArrayStackOfString_returnVoid() {
	return new ArrayStack<std::string>();
}
void push_pushStringsToArrayStack_returnVoid(ArrayStack<std::string>* stack) {
	stack->push("abc");
	stack->push("123");
	stack->push("Hello stack!");

}
void pop_popStringsToArrayStack_returnStrings(ArrayStack<std::string>* stack) {
	stack->pop();		//return Hello stack!
	stack->pop();		//return 123
}
void clean_cleanArrayStack_returnVoid(ArrayStack<std::string>* stack) {
	stack->clean();
	delete stack;
}

LinkedListStack<double>* constructor_createEmptyLinkedListStackOfDouble_returnVoid() {
	return new LinkedListStack<double>();
}
void push_pushDoublesToLinkedListStack_returnVoid(LinkedListStack<double>* stack) {
	stack->push(1.0);
	stack->push(-1.0);
	stack->push(3.1415);

}
void pop_popDoublesToLinkedListStack_returnDoubles(LinkedListStack<double>* stack) {
	stack->pop();		//return 3.1415...
	stack->pop();		//return -1.000..
}
void clean_cleanLinkedListStack_returnVoid(LinkedListStack<double>* stack) {
	stack->clean();
	delete stack;
}

ArrayStack<double>* constructor_createEmptyArrayStackOfDouble_returnVoid() {
	return new ArrayStack<double>();
}
void push_pushDoublesToArrayStack_returnVoid(ArrayStack<double>* stack) {
	stack->push(1.0);
	stack->push(-1.0);
	stack->push(3.1415);

}
void pop_popDoublesToArrayStack_returnDouble(ArrayStack<double>* stack) {
	stack->pop();		//return 3.1415...
	stack->pop();		//return -1.0..
}
void clean_cleanArrayStack_returnVoid(ArrayStack<double>* stack) {
	stack->clean();
	delete stack;
}


int main() {
	{
		LinkedListStack<int>* p = constructor_createEmptyLinkedListStackOfInt_returnVoid();
		push_pushIntsToLinkedListStack_returnVoid(p);
		pop_popIntsToLinkedListStack_returnInt(p);
		clean_cleanLinkedListStack_returnVoid(p);
	}
	{
		ArrayStack<int>* p = constructor_createEmptyArrayStackOfInt_returnVoid();
		push_pushIntsToArrayStack_returnVoid(p);
		pop_popIntsToArrayStack_returnInt(p);
		clean_cleanArrayStack_returnVoid(p);
	}
	{
		LinkedListStack<std::string>* p = constructor_createEmptyLinkedListStackOfString_returnVoid();
		push_pushStringsToLinkedListStack_returnVoid(p);
		pop_popStringsToLinkedListStack_returnStrings(p);
		clean_cleanLinkedListStack_returnVoid(p);
	}
	{
		ArrayStack<std::string>* p = constructor_createEmptyArrayStackOfString_returnVoid();
		push_pushStringsToArrayStack_returnVoid(p);
		push_pushStringsToArrayStack_returnVoid(p);
		pop_popStringsToArrayStack_returnStrings(p);
		clean_cleanArrayStack_returnVoid(p);
	}
	{
		LinkedListStack<double>* p = constructor_createEmptyLinkedListStackOfDouble_returnVoid();
		push_pushDoublesToLinkedListStack_returnVoid(p);
		pop_popDoublesToLinkedListStack_returnDoubles(p);
		clean_cleanLinkedListStack_returnVoid(p);
	}
	{
		ArrayStack<double>* p = constructor_createEmptyArrayStackOfDouble_returnVoid();
		push_pushDoublesToArrayStack_returnVoid(p);
		push_pushDoublesToArrayStack_returnVoid(p);
		pop_popDoublesToArrayStack_returnDouble(p);
		clean_cleanArrayStack_returnVoid(p);
	}
	return 0;
}
// К минусам реализации стека через связный список можно отнести большую, по сравнении с реализации через
//массив, вероятность фрагментации памяти(так как на каждый элемент память выделяеться отдельно), необходимость
//хранить дополнительные данные, количество которых зависит от количества элементов в стеке. Однако, при
// реализации через массив при превышении некоторого количества элементов приходится создавать новый массив 
// большего объема и копировать все элементы, уже находящиеся в стеке, что является потенциально длительной 
// операцией, и соответсвенно большим минусом. 