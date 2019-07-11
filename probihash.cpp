#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
using namespace std;

const int tam_tabla = 101;
 
template <class V>
class Node
{
public:
    V dato;
    Node<V>* next;
    Node(V dato);
};

template <class V>
Node<V>::Node(V dato){
    this->dato = dato;
    this->next = NULL;
}

template <class V>
class Hash
{
    private:
        Node<V>** tabla;
    public:
        Hash();
        ~Hash(){}
        int posicion();
        void insertar(V dato);
        V buscar(V key);
        void print();
};

template <class V>
Hash<V>::Hash(){
    tabla = new Node<V>*[tam_tabla];
    for (int i = 0; i < tam_tabla; i++){
        tabla[i] = NULL;
    }
}

template <class V>
void Hash<V>::print(){
    for (int i = 0; i < tam_tabla; ++i)
    {   

        cout<<i;
        Node<V>* entrada = tabla[i];
        while(entrada){
            cout<<"  "<<entrada->dato;
            entrada=entrada->next;
        }
        cout<<endl; 
    }  
}

template <class V>
int Hash<V>::posicion(){
    return rand()%tam_tabla;
}

template <class V>
void Hash<V>::insertar(V dato){
    int hash_val = posicion();
    Node<V>* prev = NULL;
    Node<V>* entrada = tabla[hash_val];
    while (entrada != NULL){
        prev = entrada;
        entrada = entrada->next;
    }
    if (entrada == NULL){
         entrada = new Node<V>(dato);
        if (prev == NULL)
        {
            tabla[hash_val] = entrada;
        }
        else
        {
            prev->next = entrada;
        }
    }
    else
    {
        entrada->dato = dato;
    }
}

template <class V>
V Hash<V>::buscar(V key){
    bool flag = false;
    int hash_val = posicion();
    Node<V>* entrada = tabla[hash_val];
    while (entrada)
    {   
        if (entrada->dato == key)
        {
            cout<<hash_val<<" "<<entrada->dato<<endl;
            flag = true;
        }
        entrada = entrada->next;
    }
    if (!flag){
      return 0;
    }
    
    /*
    int index = posicion();
    if(tabla[index] == NULL){
        return -1;
        //return "No se encontro";
    }
    else{
        Node<V>* entrada = tabla[index];
        while(entrada != NULL and entrada->dato != key){
            entrada = entrada->next;
        }
        if(entrada == NULL){
            return -1;
            //return "No se encontro";
        }
        else{
            return entrada->dato;
        }
    }
    */
}

int main(){
	Hash<int> hash;
    for (int i = 0; i < 1000; ++i)
    {
        int r = rand()%100;
        hash.insertar(r);

    }
    
    /*
    hash.insertar(45);
    hash.insertar(22);
    */
    hash.print();
    cout<<hash.buscar(23);
	return 0;
}