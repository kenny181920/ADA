#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> res;


int matrix(vector<string> & a, vector<string> & b, int m, int n){
	if(m == 0 or n == 0){
		return 0;
	}
	if(a[m-1] == b[n-1]){
		cout<<a[m-1]<<endl;
		return matrix(a,b,m-1,n-1)+1;
	}
	return max(matrix(a,b,m,n-1),matrix(a,b,m-1,n));
}

int main(){
	//vector<string> pal1 = {"10","2","1","3","5"};
	vector<string> pal1 = {"g","b","a","c","d"};
	//vector<string> pal2 = {"6","1","2","3","10","5"};
	vector<string> pal2 = {"f","a","b","c","g","d"};
	cout<<matrix(pal1,pal2,pal1.size(),pal2.size());
	return 0;
}