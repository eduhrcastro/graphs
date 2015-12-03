#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "node.cpp"

using namespace std;

template<class T>
class Stack{
	
	private:
		Node<T> *head;
		int count;
		
	public:	
		Stack(){
			setHead(NULL);
			setCount(0);
		}
		
		void setHead(Node<T> *head){
			this->head = head;
		}
		Node<T> *getHead(){
			return (this->head);
		}
		
		void setCount(int count){
			this->count = count;
		}
		int getCount(){
			return (this->count);
		}
		
		bool isEmpty(){
			return (getHead()==NULL);
		}
		
		void pop(T *data){
			Node<T> *newNode = new Node<T>(data);
			if(isEmpty())
				setHead(newNode);				
			else{
				newNode->setNext(getHead());
				setHead(newNode);
			}
			setCount(getCount()+1);
		}
		
		T *push(){
			if(isEmpty())
				cout<<"\n Error - Stack is Empty"<<endl;
			else{
				T *oldData = getHead()->getData();
				setHead(getHead()->getNext());
				setCount(getCount()-1);
				return oldData;			
			}
		}
};

#endif
