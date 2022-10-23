#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
typedef vector<string> svec;
typedef vector<char> cvec;
void del_space(string& a){
	string temp;
	for(int i=0;i<a.length();i++){
		if(a.at(i)>='0'&&a.at(i)<='9')
			temp+=a.substr(i,1);
	}
	a = temp;
}
class Graph{
	private:
		bool oriented;
		int vertex;
		int** matrix;
	public:
		Graph();
		~Graph();
		void readFile();
		void deg(int);
		void link(int);
		int num_of_vertices();
		void num_of_edge();
		void print();
};
Graph::Graph(){
}
Graph::~Graph(){
}
void Graph::readFile(){
	ifstream filein;filein.open("input.txt",ios::in);
	int i=0;svec end;string str;
	getline(filein,str);this->oriented=str.at(0)-'0';
	while(!filein.eof()){
		getline(filein,str);
		del_space(str);
		end.push_back(str);
		i++;
	}
	this->vertex=i;
	this->matrix=new int* [i];
	for(int j=0;j<i;j++){
		matrix[j]=new int [i];
	}
	for(int j=0;j<i;j++)
		for(int k=0;k<i;k++)
			matrix[j][k]=end[j].at(k)-'0';
	filein.close();	
}
void Graph::deg(int ver){
	int degree=0;int degreepos=0;int degreeneg=0;
	if(ver>this->vertex) cout<<"deg "<<(char)(ver-1+'a')<<":"<<0<<endl;
	else if(this->oriented==0){
		for(int i=0;i<this->vertex;i++)
			degree+=matrix[ver-1][i];
		cout<<"deg "<<(char)(ver-1+'a')<<":"<<degree<<endl;
	}
	else{
		for(int i=0;i<this->vertex;i++){
			degreeneg+=matrix[ver-1][i];
			degreepos+=matrix[i][ver-1];
		}
		cout<<"deg "<<(char)(ver-1+'a')<<"+:"<<degreepos<<" deg "<<(char)(ver-1+'a')<<"-:"<<degreeneg<<endl;
	}
}
void Graph::link(int ver){
	if(ver>this->vertex) cout<<"deg "<<(char)(ver-1+'a')<<":"<<0;
	else{
		cout<<"Edges start with "<<(char)('a'+ver-1)<<" :";
		for(int i=0;i<vertex;i++){
			if(matrix[ver-1][i]==1) cout<<(char)('a'+ver-1)<<(char)('a'+i)<<";";
		}
	}
	cout<<endl;
}
int Graph::num_of_vertices(){
	return this->vertex;
}
void Graph::num_of_edge(){
	int sum=0;
	for(int j=0;j<vertex;j++)
		for(int k=0;k<vertex;k++)
			sum+=matrix[j][k];
	if(this->oriented==0) cout<<"edges:"<<sum/2<<endl;
	else cout<<"edge:"<<sum<<endl;
}
void Graph::print(){
	if(this->oriented==0) cout<<"non oriented graph:";
	else cout<<"oriented graph:";
	this->num_of_edge();
	for(int j=0;j<vertex;j++){
		for(int k=0;k<vertex;k++)
			cout<<matrix[j][k]<<" ";
		cout<<endl;
	}	
}
int main(){
	Graph g;
	g.readFile();
	g.print();
	g.link(4);
}
