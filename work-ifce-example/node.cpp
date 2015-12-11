#ifndef NODE_CPP
#define NODE_CPP

#include <iostream>

using namespace std;

template <class T>
class Node{
	private:
		int priority;
		bool visited;
		T *data;
		Node<T> *next;
		Node<T> *previous;
	public:
		Node(T *data){
			setData(data);
			setNext(NULL);
			setPrevious(NULL);
			setPriority(0);
			setVisited(false);
		}
		Node(T *data,int priority){
			setData(data);
			setNext(NULL);
			setPriority(priority);
			setVisited(false);
			setPrevious(NULL);
		}
		
		void setVisited(bool visited){
			this->visited = visited;
		}
		void setData(T *data){
			this->data = data;
		}
		void setNext(Node<T> *next){
			this->next = next;
		}
		void setPrevious(Node<T> *previous){
			this->previous = previous;
		}
		void setPriority(int priority){
			this->priority = priority;
		}
		
		Node<T> *getNext(){
			return next;
		}
		T *getData(){
			return data;
		}
		int getPriority(){
			return priority;
		}
		bool getVisited(){
			return visited;
		}
		Node<T> *getPrevious(){
			return (this->previous);
		}
};

#endif
