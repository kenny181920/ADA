#include <iostream>
using namespace std;

//word es una sequencia de indices (urnas)
//counting sort 
//radix sort

int matrix(string a, string b){
	int M[a.length()][b.length()];
	for(int i=0; i<=a.length(); i++){
		for(int j=0; j<=b.length(); j++){
			if(i==0 or j==0){
				M[0][j] = j;
				M[i][0] = i;
			}
			else{
				if(a[i]==b[j]){
					M[i][j] = M[i-1][j-1];
				}
				else{
					M[i][j] = min(min(M[i-1][j],M[i][j-1]),M[i-1][j-1])+1;
				}
			}
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	return M[a.length()][b.length()];
}

int main(){
	string A = "abcdfg";
	string B = "apcfd";	
	cout<<matrix(B,A);
	return 0;
}