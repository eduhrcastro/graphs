#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP

#include <iostream>
#include "node.cpp"

using namespace std;

template<class T>
class PriorityQueue{
	
	private:
		Node<T> *head;
		Node<T> *tail;
		int count;
		
		Node<T> *getNodeMaxPriority(){
			Node<T> *aux = getHead();
			for(Node<T> *temp = getHead()->getNext();temp!=NULL;temp=temp->getNext()){
				if(aux->getPriority() < temp->getPriority())
					aux = temp;
			}	
			return aux;
		}
		
		Node<T> *getNodePredecessorMaxPriority(Node<T> *maxPriority,Node<T> *head){
			if(head!=NULL){
				if(head->getNext() == maxPriority)
					return head;
				else{
					head = head->getNext();
					return getNodePredecessorMaxPriority(maxPriority,head);
				}
			}
		}
		
	public:
		PriorityQueue(){
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
			return head;
		}
		Node<T> *getTail(){
			return tail;
		}
		int getCount(){
			return count;
		}
		
		bool isEmpty(){
			return (getHead()==NULL);
		}
		
		void enqueue(T *data){
			Node<T> *newNode = new Node<T>(data);
			if(isEmpty())
				setHead(newNode);
			else
				getTail()->setNext(newNode);
			setTail(newNode);
			setCount(getCount()+1);
		}
		
		T *dequeue(){
			if(isEmpty())
				cout<<"\n ERROR - QUEUE IS EMPTY"<<endl;
			else{
				
				Node<T> *maxPriority = getNodeMaxPriority();
				Node<T> *predMaxPriority = NULL;
				if(maxPriority != getHead())
					predMaxPriority = getNodePredecessorMaxPriority(maxPriority,getHead());
				if(predMaxPriority!=NULL){
					predMaxPriority->setNext(maxPriority->getNext());
					if(predMaxPriority->getNext()==NULL)
						setTail(predMaxPriority);
				}else
					setHead(maxPriority->getNext());
				setCount(getCount()-1);
				
				return maxPriority->getData();
			}	
		}
	
};

#endif
