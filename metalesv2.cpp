#include <iostream>
using namespace std;

int precios[11]={0,1,5,8,9,10,17,17,20,24,30};
int visitado[11]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int corteSimple(int n){
	int m = 0;
	for(int i=1; i<=n; i++){
		m = max(m,precios[i]+corteSimple(n-i));
	}
	return m;
}

int cortesTopDown(int n){
	if(visitado[n]!=-1){
		return visitado[n];
	}
	int m = 0;
	for(int i=1; i<=n; i++){
		m = max(m,precios[i]+cortesTopDown(n-i));
	}
	return visitado[n] = m;
}

int cortesBottomUp(int n){
	if(visitado[n]!=-1){
		return visitado[n];
	}
	for(int i=0; i<=n; i++){
		int m = 0;
		for(int j=0; j<=i; j++){
			m = max(m,precios[j]+visitado[i-j]);
		}
		visitado[i] = m;
	}
	return visitado[n];
}

int main(){
	cout<<corteSimple(4)<<endl;
	cout<<cortesTopDown(4)<<endl;
	cout<<cortesBottomUp(4)<<endl;
	return 0;
}