#ifndef VERTEX_CPP
#define VERTEX_CPP

#include <iostream>
#include "list.cpp"
#include "edge.cpp"

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
		Vertex(T *data){
			setData(data);
			setAuxDistance(0);
			setDegree(0);
			setVisited(false);
			setPrevious(NULL);
			setListAdj(new List< Edge<T> >());
		}
		
		void setData(T *data){
			this->data = data;
		}
		void setAuxDistance(int auxDistance){
			this->auxDistance = auxDistance;
		}
		void setDegree(int degree){
			this->degree = degree;
		}
		void setVisited(bool visited){
			this->visited = visited;
		}
		void setPrevious(Vertex<T> *previous){
			this->previous = previous;
		}
		void setListAdj(List< Edge<T> > *listAdj){
			this->listAdj = listAdj;
		}
		
		List< Edge<T> > *getListAdj(){
			return (listAdj);
		}
		T *getData(){
			return (data);
		}
		int getDegree(){
			return (degree);
		}
		int getAuxDistance(){
			return (auxDistance);
		}
		bool getVisited(){
			return (visited);
		}
		Vertex<T> *getPrevious(){
			return (this->previous);
		}
		
		int compareTo(Vertex<T> *vertex){
			if(getAuxDistance() > vertex->getAuxDistance())
				return 1;
			if(getAuxDistance() < vertex->getAuxDistance())
				return -1;
			if(getAuxDistance() == vertex->getAuxDistance())
				return 0;	
		}
		
		void toString(){
			getData()->toString();
		}
};

#endif
