 #include <iostream>
#include <string.h>
#include <stack>
using namespace std;
typedef stack<char> cstack; 
cstack path;
void dump(cstack cs){
	while(!cs.empty()){
		cout<<cs.top()<<";";
		cs.pop();
	}
	cout<<endl;
}
void emptyStack(cstack cs){
	while(!cs.empty()){
		cs.pop();
	}
}
struct Graph{
	int vertex;
	int** edge;
	int* visit;
	Graph(int ); 
	Graph();
};
Graph::Graph(){
	int ver;
	cout<<"vertex:";cin>>ver;
	vertex=ver;
	edge = new int*[vertex];
	visit=new int[vertex];
	for(int i=0;i<vertex;i++){
		edge[i]=new int[vertex];
	}
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			if(i==j){
				edge[i][j]=0;cout<<edge[i][j]<<" ";
			}
			else if(i<j) cin>>edge[i][j];
			else{
				edge[i][j]=edge[j][i];cout<<edge[i][j]<<" ";
			}
		}
		visit[i]=0;
	}
}
Graph::Graph(int ver){
	vertex=ver;
	edge = new int*[vertex];
	visit=new int[vertex];
	for(int i=0;i<vertex;i++){
		edge[i]=new int[vertex];
	}
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			if(i==j){
				edge[i][j]=0;cout<<edge[i][j]<<" ";
			}
			else if(i<j) cin>>edge[i][j];
			else{
				edge[i][j]=edge[j][i];cout<<edge[i][j]<<" ";
			}
		}
		visit[i]=0;
	}
}
bool link(Graph& g,int v1,int v2){
	return g.edge[v1][v2];
}
void setVisit(Graph& g){
	for(int i=0;i<g.vertex;i++)
		g.visit[i]=0;
}
void DFSconnected(Graph& g,int v){
	cout<<(char)(v+'a')<<';';g.visit[v]=1;
	for(int i=0;i<g.vertex;i++){
		if(link(g,v,i)&&g.visit[i]==0){
			DFSconnected(g,i);
		}
	}
}
void DFS(Graph& g){
	setVisit(g);cout<<endl;
	for(int i=0;i<g.vertex;i++){
		if(g.visit[i]==0) DFSconnected(g,i);
	}
}
bool isolated(Graph& g,int v){
	for(int i=0;i<g.vertex;i++){
		if(link(g,i,v)&&g.visit[i]==0) return false;
	}
	return true;
}
void nextEdge(Graph& g,int v1){
	for(int i=0;i<g.vertex;i++){
		if(link(g,v1,i)&&g.visit[i]==0)
			g.visit[i]=1;
	}
}
bool _pathDFS(Graph& g,int v1,int v2){
	g.visit[v1]=1;
	for(int i=0;i<g.vertex;i++){
		if(link(g,v1,i)&&g.visit[i]==0){
			path.push((char)(i+'a'));g.visit[i]=1;
			if(i==v2){
				break;
			}else if(isolated(g,i)){
				path.pop();
				_pathDFS(g,v1,v2);
			}else{
				_pathDFS(g,i,v2);
			}			
		}
	}
}
void pathDFS(Graph& g,int v1,int v2){
	emptyStack(path);
	path.push((char)(v1+'a'));
	_pathDFS(g,v1,v2) ;dump(path);
}
int main(){
	Graph g;
	//DFS(g);
	setVisit(g);
	pathDFS(g,2,5);
	return 0;
}
