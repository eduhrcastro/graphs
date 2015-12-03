#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "graph.cpp"
#include "integer.cpp"
#include "dijkstra.cpp"
#include "stack.cpp"

using namespace std;

int main(int argc, char** argv) {
	
	Graph<Integer> *g = new Graph<Integer>();
	
	int n;
	
	do{
		cout<<"\n Informe o numero de nohs do grafo: "<<endl;
		cin>>n;
		if(n<5||n>100)
			cout<<"\n Numero digitado eh invalido"<<endl;
	}while(n<5||n>100);
	
	for(int i=0;i<n;i++)
		g->addVertex(new Vertex<Integer>(new Integer(i+1)));
	
	int nO,nD;
	
	do{
		cout<<"\n Informe o noh de origem: "<<endl;
		cin>>nO;
		if(nO<0||nO>n)
			cout<<"\n Numero digitado eh invalido"<<endl;
	}while(nO<0||nO>n);
	
	do{
		cout<<"\n Informe o noh de destino: "<<endl;
		cin>>nD;
		if(nD<0||nD>n||nD==nO)
			cout<<"\n Numero digitado eh invalido"<<endl;
	}while(nD<0||nD>n||nD==nO);
	
	cout<<endl;
	
	int resp,n1,n2,t,op;
	do{
		
		do{
			cout<<"\n Digite N1: ";
			cin>>n1;
			if(n1<0||n1>n)
				cout<<"\n Opcao digitada eh invalida"<<endl;
		}while(n1<0||n1>n);
		
		do{
			cout<<"\n Digite N2: ";
			cin>>n2;
			if(n2<0||n2>n||n2==n1)
				cout<<"\n Opcao digitada eh invalida"<<endl;
		}while(n2<0||n2>n||n2==n1);
		
		do{
			cout<<"\n Tempo: ";
			cin>>t;
			if(t<0)
				cout<<"\n Opcao digitada eh invalida"<<endl;
		}while(t<0);
		
		Integer *i = new Integer(n1);
		Integer *j = new Integer(n2);
		Vertex<Integer> *v1 = g->getVertex(i);
		Vertex<Integer> *v2 = g->getVertex(j);
		g->addEdge(v1,v2,t);
		g->addEdge(v2,v1,t);
		
		do{
			cout<<"\n Deseja adicionar outra aresta? (1-Sim 2-Nao)"<<endl;
			cin>>resp;
			if(resp<1||resp>2)
				cout<<"\n Opcao digitada eh invalida"<<endl;
		}while(resp<1||resp>2);
		
	}while(resp==1);	

	cout<<"--------------------------------------------------------------"<<endl;
	
	Dijkstra<Integer> *d = new Dijkstra<Integer>(g);
	
	d->findShortPath(g->getVertex(new Integer(nO)));
	
	Vertex<Integer> *aux = g->getVertex(new Integer(nD));
	
	cout<<"\n TEMPO TOTAL DE DESLOCAMENTO: "<<aux->getAuxDistance()<<endl;
	
	Stack< Vertex<Integer> > *shortPath = new Stack< Vertex<Integer> >();
	
	while(aux!=NULL){
		shortPath->pop(aux);
		aux = aux->getPrevious();
	}
	
	cout<<"\n CAMINHO PARA CHEGAR AO NOH DESTINO: ";
	while(!shortPath->isEmpty())
		cout<<" "<<shortPath->push()->getData()->getData();
	
	cout<<endl;
	cout<<"--------------------------------------------------------------"<<endl;	
	cout<<endl;
		
	return 0;
}
