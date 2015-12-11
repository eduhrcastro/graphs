#ifndef LIST_CPP
#define LIST_CPP

#include <iostream>
#include "node.cpp"

using namespace std;

template<class T>
class List{
	
	private:
		Node<T> *head;
		Node<T> *tail;
		int count;
	public:
		List(){
			setHead(NULL);
			setTail(NULL);
			setCount(0);
		}
		
		void setHead(Node<T> *head){
			this->head = head;
		}
		void setTail(Node<T> *tail){
			this->tail = tail;
		}
		void setCount(int count){
			this->count = count;
		}
		
		Node<T> *getHead(){
			return (head);
		}
		Node<T> *getTail(){
			return (tail);
		}
		int getCount(){
			return (count);
		}
		
		bool isEmpty(){
			return (getHead()==NULL);
		}
		
		void addLast(T *data){
			Node<T> *newNode = new Node<T>(data);
			if(isEmpty()){
				setHead(newNode);
				setTail(newNode);
			}else{
				getTail()->setNext(newNode);
				setTail(getTail()->getNext());
			}
			setCount(getCount()+1);
		}
		
		void print(){
			for(Node<T> *t = getHead();t!=NULL;t=t->getNext()){
				t->getData()->toString();
				cout<<" ";
			}
		}
};

#endif
