#include <iostream>
using namespace std;
#include <queue>
#define T 8

bool bfs(int gr[T][T], int in, int en, int parent[]){
	bool v[T];
	fill(v,v+T,0);
	queue<int> q;
	q.push(in);
	v[in] = 1;
	parent[in] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0; i<T; i++){
			if(v[i]==0 and gr[u][i]){
				q.push(i);
				parent[i] = u;
				v[i] = 1;
			}
		}
	}
	return (v[en] == 1);
}

void dfs(int gr[T][T], int in, bool v[]){
	v[in] = 1;
	for(int i=0; i<T; i++){
		if(gr[in][i] and !v[i]){
			dfs(gr,i,v);
		}
	}
}

void flow(int gr[T][T], int in, int en){
	int nGR[T][T];
	int parent[T];
	int max = 0;
	for(int i=0; i<T; i++){
		for(int j=0; j<T; j++){
			nGR[i][j] = gr[i][j];
		}
	}
	while(bfs(nGR,in,en,parent)){
		int pf = INT_MAX;
		int cur = en;
		while(cur!=in){
			int prev = parent[cur];
			pf = min(pf,nGR[prev][cur]);
			cur = prev;
		}
		int cur2 = en;
		while(cur2!=in){
			int prev = parent[cur2];
			nGR[prev][cur2] = nGR[prev][cur2]-pf;
			nGR[cur2][prev] = nGR[cur2][prev]+pf;
			cur2 = prev;
		}
		max = max+pf;
	}
	cout<<"max flow "<<max<<endl;
	bool v2[T];
	fill(v2,v2+T,0);
	dfs(nGR,in,v2);
	for(int i=0; i<T; i++){
		for(int j=0; j<T; j++){
			if(v2[i] and !v2[j] and gr[i][j]){
				cout<<"("<<i<<"-"<<j<<")"<<endl;
			}
		}
	}
}

int main(){
	int g[T][T] = {	{0,10,5,15,0,0,0,0},
					{0,0,4,0,9,15,0,0},
					{0,0,0,4,0,8,0,0},
					{0,0,0,0,0,0,16,0},
					{0,0,0,0,0,0,0,10},
					{0,0,0,0,0,0,15,10},
					{0,0,6,0,0,0,0,10},
					{0,0,0,0,0,0,0,0}
				  };
	flow(g,0,7);			  
	return 0;
}