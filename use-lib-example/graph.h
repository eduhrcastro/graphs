/* GRAPH_H */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>

using namespace std;

/* INTEGER CLASS DECLARATION */
class Integer
{
	private:
		int integer;
	public:
		Integer(int integer);
		void setInteger(int integer);
		int getInteger();
		int compareTo(Integer *integer);
		void toString();
};

/* NODE CLASS DECLARATION */
template<typename T>
class Node
{
	private:
		T *data;
		Node<T> *next;
		Node<T> *previous;
		int priority;
		bool visited;
	public:
	    Node(T *data);
	    T *getData();
	    void setData(T *data);
	    Node<T> *getNext();
	    void setNext(Node<T> *next);
	    Node<T> *getPrevious();
	    void setPrevious(Node<T> *previous);
	    int getPriority();
	    void setPriority(int priority);
	    bool isVisited();
	    void setVisited(bool visited);
};

/* LIST CLASS DECLARATION */
template<typename T>
class List
{
	private:
		Node<T> *head;
		Node<T> *tail;
		int count;
	public:
	    List();
	    Node<T> *getHead();
	    void setHead(Node<T> *head);
	    Node<T> *getTail();
	    void setTail(Node<T> *tail);
	    int getCount();
	    void setCount(int count);
	    bool isEmpty();
	    void addLast(T *data);
		void print();
};

/* EDGE CLASS DECLARATION */
template<class T>
class Edge{
	private:
		T *data;
		int distance;
	public:
		Edge(T *data,int distance);
		void setData(T *data);
		void setDistance(int distance);	
		T *getData();
		int getDistance();
		void toString();
		int compareTo(Edge<T> *edge);	
};

/* VERTEX CLASS DECLARATION */
template<class T>
class Vertex{
	private:
		T *data;
		int auxDistance;
		int degree;
		bool visited;
		List< Edge<T> > *listAdj;
		Vertex<T> *previous;	
	public:
		Vertex(T *data);
		void setData(T *data);
		void setAuxDistance(int auxDistance);
		void setDegree(int degree);
		void setVisited(bool visited);
		void setPrevious(Vertex<T> *previous);
		void setListAdj(List< Edge<T> > *listAdj);
		List< Edge<T> > *getListAdj();
		T *getData();
		int getDegree();
		int getAuxDistance();
		bool getVisited();
		Vertex<T> *getPrevious();
		int compareTo(Vertex<T> *vertex);
		void toString();
};

/* GRAPH CLASS DECLARATION */
template<typename T>
class Graph
{
	private:
		Node< Vertex<T> > *head;
		Node< Vertex<T> > *tail;
		int count;
	public:
		Graph();
		void setHead(Node< Vertex<T> > *head);
		void setTail(Node< Vertex<T> > *tail);
		void setCount(int count);
		Node< Vertex<T> > *getHead();
		Node< Vertex<T> > *getTail();
		int getCount();
		bool isEmpty();
		void addVertex(Vertex<T> *data);
		//ESSA FUNÇÃO RECEBE COMO PARAMETROS OS ENDEREÇOS DOS VÉRTICES;
		//JÁ DEVE SER TESTADO ANTES DE SER ENVIADO PARA A FUNÇÃO A INTEGRIDADE DOS VERTICES;
		void addEdge(Vertex<T> *dataSource,Vertex<T> *dataDestination,int distance);
		//FUNÇÃO QUE RETORNA O END. DE MEMÓRIA DE UM VÉRTICE COM INDÍCE "DATA";
		Vertex<T> *getVertex(T *data);
		Node< Vertex<T> > *getNode(Vertex<T> *data);
		void print();
};

/* INTEGER CLASS DEFINITION */
Integer::Integer(int integer)
{
	setInteger(integer);	
}

void Integer::setInteger(int integer){
	this->integer = integer;
}

int Integer::getInteger(){
	return integer;
}

int Integer::compareTo(Integer *integer){
	if(getInteger() > integer->getInteger())
		return 1;
	if(getInteger() < integer->getInteger())
		return -1;
	if(getInteger() == integer->getInteger())
		return 0;
}

void Integer::toString(){
	cout<<getInteger()<<" ";
}

/* NODE CLASS DEFINITION */
template<typename T>
Node<T>::Node(T *data) 
{ 
	setNext(NULL);
	setPrevious(NULL);
	setData(data);
	setVisited(false);
	setPriority(0);
}

template<typename T>
T *Node<T>::getData() 
{ 
	return this->data;
}

template<typename T>
void Node<T>::setData(T *data) 
{ 
	this->data = data;
}

template<typename T>
Node<T> *Node<T>::getNext() 
{ 
	return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) 
{ 
	this->next = next;
}

template<typename T>
Node<T> *Node<T>::getPrevious() 
{ 
	return this->previous;
}

template<typename T>
void Node<T>::setPrevious(Node<T> *previous) 
{ 
	this->previous = previous;
}

template<typename T>
int Node<T>::getPriority() 
{ 
	return this->previous;
}

template<typename T>
void Node<T>::setPriority(int priority) 
{ 
	this->priority = priority;
}

template<typename T>
bool Node<T>::isVisited() 
{ 
	return visited;
}

template<typename T>
void Node<T>::setVisited(bool visited) 
{ 
	this->visited = visited;
}

/* LIST CLASS DEFINITION */
template<typename T>
List<T>::List() 
{ 
	setHead(NULL);
	setTail(NULL);
	setCount(0);
}

template<typename T>
Node<T> *List<T>::getHead()
{
	return head;
}

template<typename T>
void List<T>::setHead(Node<T> *head)
{
	this->head = head;
}

template<typename T>
Node<T> *List<T>::getTail()
{
	return tail;
}

template<typename T>
void List<T>::setTail(Node<T> *tail)
{
	this->tail = tail;
}

template<typename T>
int List<T>::getCount()
{
	return count;
}

template<typename T>
void List<T>::setCount(int count)
{
	this->count = count;
}

template<typename T>
bool List<T>::isEmpty(){
	return (getHead()==NULL);
}

template<typename T>
void List<T>::addLast(T *data){
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

template<typename T>
void List<T>::print(){
	for(Node<T> *t = getHead();t!=NULL;t=t->getNext()){
		t->getData()->toString();
	}
}

/* EDGE CLASS DEFINITION */
template<class T>
Edge<T>::Edge(T *data,int distance){
	setData(data);
	setDistance(distance);
}

template<class T>
void Edge<T>::setData(T *data){
	this->data = data;
}

template<class T>
void Edge<T>::setDistance(int distance){
	this->distance = distance;
}

template<class T>
T *Edge<T>::getData(){
	return (data);
}

template<class T>
int Edge<T>::getDistance(){
	return (distance);
}

template<class T>
void Edge<T>::toString(){
	getData()->toString();
}

template<class T>
int Edge<T>::compareTo(Edge<T> *edge){
	if(getDistance() > edge->getDistance())
		return 1;
	if(getDistance() < edge->getDistance())
		return -1;
	if(getDistance() == edge->getDistance())
		return 0;
}

/* VERTEX CLASS DEFINITION */ 
template<class T>
Vertex<T>::Vertex(T *data){
	setData(data);
	setAuxDistance(0);
	setDegree(0);
	setVisited(false);
	setPrevious(NULL);
	setListAdj(new List< Edge<T> >());
}

template<class T>
void Vertex<T>::setData(T *data){
	this->data = data;
}

template<class T>
void Vertex<T>::setAuxDistance(int auxDistance){
	this->auxDistance = auxDistance;
}

template<class T>
void Vertex<T>::setDegree(int degree){
	this->degree = degree;
}

template<class T>
void Vertex<T>::setVisited(bool visited){
	this->visited = visited;
}

template<class T>
void Vertex<T>::setPrevious(Vertex<T> *previous){
	this->previous = previous;
}

template<class T>
void Vertex<T>::setListAdj(List< Edge<T> > *listAdj){
	this->listAdj = listAdj;
}

template<class T>
List< Edge<T> > *Vertex<T>::getListAdj(){
	return (listAdj);
}

template<class T>
T *Vertex<T>::getData(){
	return (data);
}

template<class T>
int Vertex<T>::getDegree(){
	return (degree);
}

template<class T>
int Vertex<T>::getAuxDistance(){
	return (auxDistance);
}

template<class T>
bool Vertex<T>::getVisited(){
	return (visited);
}

template<class T>
Vertex<T> *Vertex<T>::getPrevious(){
	return (this->previous);
}

template<class T>
int Vertex<T>::compareTo(Vertex<T> *vertex){
	if(getAuxDistance() > vertex->getAuxDistance())
		return 1;
	if(getAuxDistance() < vertex->getAuxDistance())
		return -1;
	if(getAuxDistance() == vertex->getAuxDistance())
		return 0;	
}

template<class T>
void Vertex<T>::toString(){
	getData()->toString();
}

/* GRAPH CLASS DEFINITION */
template<class T>
Graph<T>::Graph()
{
	setHead(NULL);
	setTail(NULL);
	setCount(0);
}

template<class T>
void Graph<T>::setHead(Node< Vertex<T> > *head)
{
	this->head = head;
}

template<class T>
void Graph<T>::setTail(Node< Vertex<T> > *tail)
{
	this->tail = tail;
}

template<class T>
void Graph<T>::setCount(int count)
{
	this->count = count;
}

template<class T>
Node< Vertex<T> > *Graph<T>::getHead()
{
	return (head);
}

template<class T>
Node< Vertex<T> > *Graph<T>::getTail()
{
	return (tail);
}

template<class T>
int Graph<T>::getCount()
{
	return (count);
}

template<class T>
bool Graph<T>::isEmpty()
{
	return (getHead()==NULL);
}

template<class T>
void Graph<T>::addVertex(Vertex<T> *data)
{
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

//ADD Throws EXCEPTION
template<class T>
void Graph<T>::addEdge(Vertex<T> *dataSource,Vertex<T> *dataDestination,int distance)
{
	dataSource->getListAdj()->addLast(new Edge<T>(dataDestination->getData(),distance));
	dataSource->setDegree(dataSource->getDegree()+1);	
}

template<class T>
Vertex<T> *Graph<T>::getVertex(T *data)
{
	Node< Vertex<T> > *t = getHead();
	
	while((t!=NULL) && ((t->getData()->getData()->compareTo(data))!=0))
		t = t->getNext();
	
	if(t!=NULL){
		return (t->getData());
	}else
		return NULL;	
}

template<class T>
Node< Vertex<T> > *Graph<T>::getNode(Vertex<T> *data)
{
	Node< Vertex<T> > *t = getHead();
	while((t!=NULL) && ((t->getData()->getData()->compareTo(data->getData()))!=0))
		t = t->getNext();
	
	if(t!=NULL)
		return (t);
	else
		return (NULL);
}

template<class T>
void Graph<T>::print()
{
	for(Node< Vertex<T> > *t = getHead();t!=NULL;t=t->getNext()){
		t->getData()->getData()->toString();
		cout<<"\t";
		t->getData()->getListAdj()->print();
		cout<<endl;
	}
}

#endif
