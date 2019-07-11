#include <iostream>
using namespace std;

//word es una sequencia de indices (urnas)
//counting sort 
//radix sort

int matrix(string a, string b){
	int res = 0;
	int M[a.length()][b.length()];
	for(int i=0; i<=a.length(); i++){
		for(int j=0; j<=b.length(); j++){
			if(i==0 or j==0){
				M[i][j] = 0;
			}
			else{
				if(a[i-1]==b[j-1]){
					M[i][j] = M[i-1][j-1]+1;
					res = max(res,M[i][j]);
					//cout<<"res<"<<res<<">"<<endl;
				}
				else{
					M[i][j] = 0;
				}
			}
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	return res;
}

int main(){
	string A = "abedgh";
	string B = "edgabci";	
	cout<<matrix(A,B);
	return 0;
}