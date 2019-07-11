#include <iostream>
using namespace std;

int mochila(int w, int wm[], int p[], int n){
	int M[n+1][w+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=w; j++){
			if(i==0 or j==0){
				M[i][j] = 0;
			}
			else{
				if(wm[i-1] <= j){
					M[i][j] = max(p[i-1] + M[i-1][j-wm[i-1]], M[i-1][j]);
				}
				else{
					M[i][j] = M[i-1][j];
				}
			}
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	return M[n][w];
}

int main(){
	int p[] = {1,2,5,6};
	int wm[] = {2,3,4,5};
	int n = 4;
	int w = 8;
	cout<<mochila(w,wm,p,n);
	return 0;
}