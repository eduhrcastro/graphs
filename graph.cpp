#ifndef GRAPH_CPP
#define	GRAPH_CPP

#include <iostream>
#include "node.cpp"
#include "vertex.cpp"
#include "edge.cpp"

using namespace std;

template<class T>
class Graph{
	
	private:
		Node< Vertex<T> > *head;
		Node< Vertex<T> > *tail;
		int count;
	
	public:
		Graph(){
			setHead(NULL);
			setTail(NULL);
			setCount(0);
		}
		
		void setHead(Node< Vertex<T> > *head){
			this->head = head;
		}
		void setTail(Node< Vertex<T> > *tail){
			this->tail = tail;
		}
		void setCount(int count){
			this->count = count;
		}
		
		Node< Vertex<T> > *getHead(){
			return (head);
		}
		Node< Vertex<T> > *getTail(){
			return (tail);
		}
		int getCount(){
			return (count);
		}
		
		bool isEmpty(){
			return (getHead()==NULL);
		}
		
		void addVertex(Vertex<T> *data){
			
			Node< Vertex<T> > *newNode = new Node< Vertex<T> >(data);
			
			if(isEmpty()){
				setHead(newNode);
				setTail(newNode);
			}else{
				getTail()->setNext(newNode);
				setTail(getTail()->getNext());
			}
			setCount(getCount()+1);
		}
		
		//ESSA FUNÇÃO RECEBE COMO PARAMETROS OS ENDEREÇOS DOS VÉRTICES;
		//JÁ DEVE SER TESTADO ANTES DE SER ENVIADO PARA A FUNÇÃO A INTEGRIDADE DOS VERTICES;
		void addEdge(Vertex<T> *dataSource,Vertex<T> *dataDestination,int distance){
			
			dataSource->getListAdj()->addLast(new Edge<T>(dataDestination->getData(),distance));
			dataSource->setDegree(dataSource->getDegree()+1);
			
		}
		
		//FUNÇÃO QUE RETORNA O END. DE MEMÓRIA DE UM VÉRTICE COM INDÍCE "DATA";
		Vertex<T> *getVertex(T *data){
				
				Node< Vertex<T> > *t = getHead();
				
				while((t!=NULL) && ((t->getData()->getData()->compareTo(data))!=0))
					t = t->getNext();
				
				if(t!=NULL){
					return (t->getData());
				}else
					return NULL;	
		}
		
		Node< Vertex<T> > *getNode(Vertex<T> *data){
			
			Node< Vertex<T> > *t = getHead();
			while((t!=NULL) && ((t->getData()->getData()->compareTo(data->getData()))!=0))
				t = t->getNext();
			
			if(t!=NULL)
				return (t);
			else
				return (NULL);
		}
		
		void print(){
			
			for(Node< Vertex<T> > *t = getHead();t!=NULL;t=t->getNext()){
				t->getData()->getData()->toString();
				cout<<"\t";
				t->getData()->getListAdj()->print();
				cout<<endl;
			}
		}
		
};

#endif
