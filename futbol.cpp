#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 3;
int totalS = 6;
int asientos[3] = {2,2,3};
int n_asientos[3] = {0,0,0};

void v2(int arr[],int ca, int i){
	if(ca<0 or ca>3){
		return;
	}
	else{
		if(n_asientos[ca] == 0){
			n_asientos[ca] = i+1;
			return;
		}
		else{
			int mov = arr[i];
			if(mov == 0){
				v2(arr,ca-1,i);
			}
			else{
				v2(arr,ca+1,i);
			}
		}
	}
}

void verificacion(int arr[], int n) 
{ 	
    for (int i = 0; i < n; i++){ 
    	int ca = asientos[i]-1;
    	v2(arr,ca,i);
    }
    if(n_asientos[0]+n_asientos[1]+n_asientos[2]==totalS){
    	cout<<n_asientos[0] << " "<<n_asientos[1] << " "<<n_asientos[2] <<endl;
    }
    n_asientos[0]=0;
    n_asientos[1]=0;
    n_asientos[2]=0;
} 
  
void combinaciones(int n, int arr[], int i) 
{ 
    if (i == n){ 
        verificacion(arr, n); 
        return; 
    }  
    arr[i] = 0; 
    combinaciones(n, arr, i + 1); 
    arr[i] = 1; 
    combinaciones(n, arr, i + 1); 
} 
  
int main() 
{ 
    int arr[n]; 
    combinaciones(n, arr, 0); 
    return 0; 
} 