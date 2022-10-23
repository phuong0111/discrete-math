#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
typedef vector<string> svec;
typedef vector<char> cvec;
void matrix_to_list(string a,string& end){
	string temp;
	for(int i=0;i<a.length();i++){
		if(a.at(i)!=' ') temp+=a.substr(i,1);
	}
	end=temp;
}
void rightstring(string& str){
	string temp;
	for(int i=0;i<str.length();i++){
		if(str.at(i)!=';') temp+=str.substr(i,1);
	}
	str=temp;
}
void readFile(char* filename,cvec& start,svec& end,int& line){
	ifstream filein;string str;string _end;char _start;
    filein.open(filename, ios::in);int i = 0;
    if (filein.is_open() == false)
    {
        cout << "Could not open the file!!!" << endl;
    }
    while(!filein.eof()){
    	getline(filein,str);_start=(char)(i+'a');i++;
    	matrix_to_list(str,_end);
    	start.push_back(_start);
    	end.push_back(_end);
	}
	filein.close();
	line=i;
}
void writeFilein1_1(cvec& start,svec& end,int line){
	ofstream fileout;
    fileout.open("input1_1.txt",ios::out);
    fileout<<line<<endl;
    for(int i=0;i<start.size();i++){
    	fileout<<start[i]<<":";
    	for(int j=0;j<end[i].length();j++){
    		if(end[i].at(j)=='1') fileout<<(char)(j+'a')<<";";
		}
		if(i<start.size()-1) fileout<<endl;
	}
	fileout.close();
}
void writeFilein1_2(cvec& start,svec& end,int line){
	ofstream fileout;
    fileout.open("input1_2.txt",ios::out);
    fileout<<line<<endl;
    for(int i=0;i<start.size();i++){
    	for(int j=i+1;j<end[i].length();j++){
    		if(end[i].at(j)=='1') fileout<<start[i]<<(char)(j+'a')<<";";
		}
		if(i<start.size()-1) fileout<<endl;
	}
	fileout.close();
}
int** readFilein1_1(){
	ifstream filein;string str;
	filein.open("input1_1.txt",ios::in);
	getline(filein,str);
	int line = str.at(0)-'0';
	int**a = new int*[line];
	for(int j=0;j<line;j++){
		a[j]=new int[line+1];
	}
	for(int m=0;m<line;m++)
		for(int n=0;n<line+1;n++)
			a[m][n]=0;
	int cnt=0;
	while(!filein.eof()){
		getline(filein,str,':');
		if(filein.eof()) break;
		getline(filein,str);
		rightstring(str);
		int index=0;
		for(int j=0;j<str.length();j++){
			a[cnt][str.at(j)-'a']=1;
		}
		cnt++;
	}
	filein.close();
	return a;
}
void writeFileout1_1(int** a,int line){
	ofstream fileout;
    fileout.open("output1_1.txt",ios::out);
    for(int i=0;i<line;i++){
    	for(int j=0;j<line;j++){
    		fileout<<a[i][j]<<" ";a[i][line]+=a[i][j];
		}
		fileout<<"  "<<(char)(i+'a')<<" degree:"<<a[i][line];
		fileout<<endl;
	}
	for(int i=0;i<line;i++){
		for(int j=i+1;j<line;j++)
			if(a[i][j]==1) fileout<<(char)(i+'a')<<(char)(j+'a')<<";";
		if(i<line-1) fileout<<endl;
	}
	fileout.close();
}
int** readFilein1_2(){
	ifstream filein;string str;
	filein.open("input1_2.txt",ios::in);
	getline(filein,str);
	int line = str.at(0)-'0';
	int**a = new int*[line];
	for(int j=0;j<line;j++){
		a[j]=new int[line+1];
	}
	for(int m=0;m<line;m++)
		for(int n=0;n<line+1;n++)
			a[m][n]=0;
	int cnt=0;
	while(!filein.eof()){
		getline(filein,str);
		rightstring(str);
		int index=0;
		for(int j=0;j<str.length();j=j+2){
			a[str.at(j)-'a'][str.at(j+1)-'a']=1;
			a[str.at(j+1)-'a'][str.at(j)-'a']=1;
		}
	}
	filein.close();
	return a;
}
void writeFileout1_2(int** a,int line){
	ofstream fileout;
    fileout.open("output1_2.txt",ios::out);
    for(int i=0;i<line;i++){
    	for(int j=0;j<line;j++){
    		fileout<<a[i][j]<<" ";a[i][line]+=a[i][j];
		}
		fileout<<"  "<<(char)(i+'a')<<" degree:"<<a[i][line];
		fileout<<endl;
	}
	for(int i=0;i<line;i++){
		fileout<<(char)(i+'a')<<":";
		for(int j=i+1;j<line;j++)
			if(a[i][j]==1) fileout<<(char)(j+'a')<<";";
		if(i<line-1) fileout<<endl;
	}
	fileout.close();
}






void writeFilein2_1(cvec& start,svec& end,int line){
	ofstream fileout;
    fileout.open("input2_1.txt",ios::out);
    fileout<<line<<endl;
    for(int i=0;i<start.size();i++){
    	fileout<<start[i]<<":";
    	for(int j=0;j<end[i].length();j++){
    		if(end[i].at(j)=='1') fileout<<(char)(j+'a')<<";";
		}
		if(i<start.size()-1) fileout<<endl;
	}
	fileout.close();
}
void writeFilein2_2(cvec& start,svec& end,int line){
	ofstream fileout;
    fileout.open("input2_2.txt",ios::out);
    fileout<<line<<endl;
    for(int i=0;i<start.size();i++){
    	for(int j=0;j<end[i].length();j++){
    		if(end[i].at(j)=='1') fileout<<start[i]<<(char)(j+'a')<<";";
		}
		if(i<start.size()-1) fileout<<endl;
	}
	fileout.close();
}
int** readFilein2_1(){
	ifstream filein;string str;
	filein.open("input2_1.txt",ios::in);
	getline(filein,str);
	int line = str.at(0)-'0';
	int**a = new int*[line];
	for(int j=0;j<line;j++){
		a[j]=new int[line];
	}
	for(int m=0;m<line;m++)
		for(int n=0;n<line;n++)
			a[m][n]=0;
	int cnt=0;
	while(!filein.eof()){
		getline(filein,str,':');
		if(filein.eof()) break;
		getline(filein,str);
		rightstring(str);
		int index=0;
		for(int j=0;j<str.length();j++){
			a[cnt][str.at(j)-'a']=1;
		}
		cnt++;
	}
	filein.close();
	return a;
}
void writeFileout2_1(int** a,int line){
	ofstream fileout;int degpos[line],degneg[line];
	for(int i=0;i<line;i++){
		degpos[i]=degneg[i]=0;
	}
    fileout.open("output2_1.txt",ios::out);
    for(int i=0;i<line;i++)
    	for(int j=0;j<line;j++)
    		degpos[j]+=a[i][j];
    for(int i=0;i<line;i++){
    	for(int j=0;j<line;j++){
    		fileout<<a[i][j]<<" ";degneg[i]+=a[i][j];
		}
		fileout<<"  "<<(char)(i+'a')<<" degree+:"<< degpos[i]<<" degree-:"<<degneg[i];
		fileout<<endl;
	}
	for(int i=0;i<line;i++){
		for(int j=0;j<line;j++)
			if(a[i][j]==1) fileout<<(char)(i+'a')<<(char)(j+'a')<<";";
		if(i<line-1) fileout<<endl;
	}
	fileout.close();
}
int** readFilein2_2(){
	ifstream filein;string str;
	filein.open("input2_2.txt",ios::in);
	getline(filein,str);
	int line = str.at(0)-'0';
	int**a = new int*[line];
	for(int j=0;j<line;j++){
		a[j]=new int[line];
	}
	for(int m=0;m<line;m++)
		for(int n=0;n<line;n++)
			a[m][n]=0;
	int cnt=0;
	while(!filein.eof()){
		getline(filein,str);
		rightstring(str);
		int index=0;
		for(int j=0;j<str.length();j=j+2){
			a[str.at(j)-'a'][str.at(j+1)-'a']=1;
		}
	}
	filein.close();
	return a;
}
void writeFileout2_2(int** a,int line){
	ofstream fileout;int degpos[line],degneg[line];
	for(int i=0;i<line;i++){
		degpos[i]=degneg[i]=0;
	}
    fileout.open("output2_2.txt",ios::out);
    for(int i=0;i<line;i++)
    	for(int j=0;j<line;j++)
    		degpos[j]+=a[i][j];
    for(int i=0;i<line;i++){
    	for(int j=0;j<line;j++){
    		fileout<<a[i][j]<<" ";degneg[i]+=a[i][j];
		}
		fileout<<"  "<<(char)(i+'a')<<" degree+:"<< degpos[i]<<" degree-:"<<degneg[i];
		fileout<<endl;
	}
	for(int i=0;i<line;i++){
		fileout<<(char)(i+'a')<<":";
		for(int j=0;j<line;j++)
			if(a[i][j]==1) fileout<<(char)(j+'a')<<";";
		if(i<line-1) fileout<<endl;
	}
	fileout.close();
}
int main(){
	cvec start1,start2;svec end1,end2;int line;int**a,**b,**c,**d;
	readFile("input1.txt",start1,end1,line);
	writeFilein1_1(start1,end1,line);
	writeFilein1_2(start1,end1,line);
	a=readFilein1_1();
	writeFileout1_1(a,line);
	b=readFilein1_2();
	writeFileout1_2(b,line);
	readFile("input2.txt",start2,end2,line);
	writeFilein2_1(start2,end2,line);
	writeFilein2_2(start2,end2,line);
	c=readFilein2_1();
	writeFileout2_1(c,line);
	d=readFilein2_2();
	writeFileout2_2(d,line);
//	writeFileout1_1(row);
	return 0;
}

