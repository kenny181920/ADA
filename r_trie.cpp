#include <iostream>
using namespace std;

class trie;

class node
{
private:
	int valor;
	node *child[26];
public:
	node(){
		for (int i = 0; i < 26; i++)
		{
			child[i] = 0;
		}
		valor = -1;
	};
	virtual ~node(){};
	friend class trie;
};

class trie
{
private:
	node *root;
public:
	trie(){
		root = new node();
	}

	virtual ~trie(){};

	node * insert(node **n,string key,int val,int d){
		if((*n) == NULL){
			(*n) = new node();
		}
		if(d == key.length()){
			(*n)->valor = val;
			return (*n);
		}
		int index = key[d] - 'a';
		(*n)->child[index] = insert(&(*n)->child[index],key,val,d+1);
		return (*n);
	}
	void insert(string key, int val){
		insert(&root,key,val,0);
	}

	node * find(node **n,string key,int d){
		if((*n) == NULL){
			return NULL;
		}
		if(d == key.length()){
			return (*n);
		}
		int index = key[d] - 'a';
		return find(&(*n)->child[index],key,d+1);
	}

	void find(string key){
		node * n;
		n = find(&root,key,0);
		if(n == NULL){
			cout<<"No se encontro"<<endl;
		}
		else{
			cout<<"Se encontro y su valor es "<<n->valor<<endl;
		}
	}

	bool valor(node *n){
		return n->valor != -1;
	}

	void print2(node *n, char pal[], int d){
		if(valor(n)){
			pal[d] = '\0';
			cout<<pal<<endl;
		}
		for (int i = 0; i < 26; i++){
			if(n->child[i]){
				pal[d] = i + 'a';
				//cout<<n->child[i]<<endl;
				//cout<<"--";
				//cout<<pal[d]<<endl;
				print2(n->child[i],pal,d+1);
			}
		}
	}

	void print(){
		char pal[100];
		//cout<<"graph {"<<endl;
		//cout<<root<<endl;
		print2(root,pal,0);
		//cout<<"}"<<endl;
	}

	int cont_child(node **n, int * index){
		int count = 0;
		for (int i = 0; i < 26; i++){
			if((*n)->child[i] != NULL){
				count++;
				//cout<<"d";
				*index = i;
			}
		}
		return count;
	}

	string pref_largo_(node **n){
		int index=0;
		string pref;
		while(cont_child(&(*n),&index)==1 and (*n)->valor == -1){
			//cout<<"3";
			(*n) = (*n)->child[index];
			pref.push_back('a'+index);
		}
		return pref;
	}

	void pref_largo(){
		cout<<pref_largo_(&root);
	}

	bool tiene_hijos(node **n){
		for(int i=0; i<26; i++){
			if((*n)->child[i]){
				return 0;
			}
		}
		return 1;
	}

	void buscar_suf(node **n, string suf){
		if((*n)->valor!=-1){
			cout<<suf<<endl;
		}
		if(tiene_hijos(&(*n))){
			return;
		}
		for(int i=0; i<26; i++){
			if((*n)->child[i]){
				suf.push_back(97+i);
				buscar_suf(&(*n)->child[i],suf);
			}
		}
	}

	int pr_buscar_suf(node **n, string pal){
		for(int i=0; i<pal.length(); i++){
			int index = pal[i] - 'a';
			if(!(*n)->child[index]){
				cout<<"No se encontro"<<endl;
				return 0;
			}
			(*n) = (*n)->child[index];
		}
		bool h = tiene_hijos(&(*n));
		if(!h){
			string suf = pal;
			buscar_suf(&(*n),suf);
		}
	}

	void pr_buscar_suf(string pal){
		pr_buscar_suf(&root,pal);
	}
};

int main(){
	trie t;
	
	t.insert("are",12);
	t.insert("by",4);
	t.insert("sea",14);
	t.insert("sells",11);
	t.insert("shells",15);
	t.insert("she",10);
	t.insert("shore",7);
	t.insert("surely",13);
	t.insert("sur",0);
	t.insert("the",8);
	
	/*
	t.insert("pan",12);
	t.insert("pancrasio",4);
	t.insert("panes",1);
	t.insert("panseco",5);
	*/
	t.print();
	cout<<"---------"<<endl;
	//t.pref_largo();
	t.pr_buscar_suf("sh");
	return 0;
}