#ifndef EDGE_CPP
#define EDGE_CPP

#include <iostream>

template<class T>
class Edge{
	
	private:
		T *data;
		int distance;
	public:
		Edge(T *data,int distance){
			setData(data);
			setDistance(distance);
		}
		
		void setData(T *data){
			this->data = data;
		}
		void setDistance(int distance){
			this->distance = distance;
		}
		
		T *getData(){
			return (data);
		}
		int getDistance(){
			return (distance);
		}
		
		void toString(){
			getData()->toString();
		}
		
		int compareTo(Edge<T> *edge){
			if(getDistance() > edge->getDistance())
				return 1;
			if(getDistance() < edge->getDistance())
				return -1;
			if(getDistance() == edge->getDistance())
				return 0;
		}
		
};

#endif
