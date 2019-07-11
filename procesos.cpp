#include <iostream>
#include <algorithm>   
using namespace std;

int main(){
	int n = 4;
	int total = 0;
	int procesos[n] = {1,2,3,4};
	int tiempo[n] = {6,8,7,3};
	int tiempo_espera[n];
	int tp[n];

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(tiempo[j]<tiempo[i]){
				swap(tiempo[i],tiempo[j]);
				swap(procesos[i],procesos[j]);
			}
		}
	}

	tiempo_espera[0] = 0;

	for(int i=1; i<n; i++){
		tiempo_espera[i] = 0;
		for(int j=0; j<i; j++){
			tiempo_espera[i] = tiempo_espera[i]+tiempo[j];
		}
	}

	cout<<"\nProcesos\tTiempo    \tTiempo de espera\tTiempo de respuesta";
	for(int i=0; i<n; i++){
		tp[i] = tiempo[i]+tiempo_espera[i];
		total = total+tp[i];
		cout<<"\n"<<procesos[i]<<"\t\t"<<tiempo[i]<<"\t\t"<<tiempo_espera[i]<<"\t\t\t"<<tp[i];
	}
	cout<<"\nTiempo promedio de respuesta: "<<(total/n);
}