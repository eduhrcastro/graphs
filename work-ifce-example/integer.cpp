#ifndef INTEGER_CPP
#define INTEGER_CPP

#include <iostream>

using namespace std;

class Integer{
	
	private:
		int data;
	public:
		Integer(int data){
			setData(data);
		}
		Integer(){
			setData(-1);
		}
		
		void setData(int data){
			this->data = data;
		}
		int getData(){
			return (this->data);
		}
		
		int compareTo(Integer *integer){
			if(getData() > integer->getData())
				return 1;
			if(getData() < integer->getData())
				return -1;
			if(getData() == integer->getData())
				return 0;
		}
		
		void toString(){
			cout<<getData();
		}
	
};

#endif
