#include <iostream>
using namespace std;

void boyerjeje(string txt, string pat){
	int M[256];
	fill(M,M+256,-1);
	for(int i = 0; i < pat.size(); i++){
		M[pat[i]] = i;
	}
	int i = 0;
	while(i<=(txt.size()-pat.size())){
		int j = pat.size()-1;
		while(j>=0 and pat[j] == txt[i+j]){
			j--;
		}
		if(j<0){
			cout<<i<<endl;
			if(i+pat.size()<txt.size()){
				i = i+pat.size()-M[txt[i+pat.size()]];
			}
			else{
				i = i+1;
			}
		}
		else{
			i = i+max(1,j-M[txt[i+j]]);
		}
	}
}

int main(){
	string txt = "FINEEDLEAYSTACKNEEDLEINA";
	string pat = "NEEDLE";
	boyerjeje(txt,pat);
	return 0;
}