#include <iostream>
using namespace std;

void automata(string txt, string pat){
	int M[pat.size()+1][256];
	int k = 0;
	for(int i=0; i<256; i++){
		M[0][i] = 0;
	}
	M[0][pat[0]] = 1;
	for(int i=1; i<=pat.size(); i++){
		for(int j=0; j<256; j++){
			M[i][j] = M[k][j];
		}
		M[i][pat[i]] = i+1;
		if(i<pat.size()){
			k = M[k][pat[i]];
		}
	}
	int j = 0;
	for (int i = 0; i < txt.size(); i++)
	{	
		j = M[j][txt[i]];
		if(j == pat.size()){
			cout<<i-pat.size()+1<<endl;
		}
	}
	
}

int main(){
	string txt = "AABACAABABACAA";
	string pat = "ACA";
	automata(txt,pat);
	return 0;
}