#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
using namespace std;

const int tam_tabla = 499;
 
template <class T>
class Node
{
public:
    T key;
    Node(T key);
};

template <class T>
Node<T>::Node(T key){
    this->key = key;
}

template <class T>
class Hash
{
    private:
        Node<T>** tabla;
        int tam;
    public:
        Hash();
        ~Hash(){}
        int posicion1(T key);
        int posicion2(T key);
        void insertar(T key);
        bool buscar(T key);
        void print();
};

template <class T>
Hash<T>::Hash(){
    tabla = new Node<T>*[tam_tabla];
    for (int i = 0; i < tam_tabla; i++){
        tabla[i] = NULL;
    }
}

template <class T>
int Hash<T>::posicion1(T key){
    return key%tam_tabla;
}

template <class T>
int Hash<T>::posicion2(T key){
    return 1+(key%tam_tabla);
}

template <class T>
void Hash<T>::insertar(T key){
    if(tam == tam_tabla){
        return;
    }
    int index = posicion1(key);
    if(tabla[index]){
        int index2 = posicion2(key);
        int i = 0;
        while(1){
            int indexD = (index+i*index2) % tam_tabla;
            if(tabla[indexD] == NULL){
                tabla[indexD] = new Node<T>(key);
                return;
            }
            i++;
        }
    }
    else{
        tabla[index] = new Node<T>(key);
    }
    tam++;
}

template <class T>
bool Hash<T>::buscar(T key){
    int index = posicion1(key);
    if(tabla[index]){
        int index2 = posicion2(key);
        int i = 0;
        while(1){
            if(i>tam_tabla){
                return false;
            }
            int indexD = (index+i*index2) % tam_tabla;
            if(tabla[indexD]->key == key){
                cout<<indexD<<" "<<tabla[indexD]->key;
                return true;
            }
            i++;
        }
    }
    else{
        cout<<index<<" "<<tabla[index];
        return true;
    }
}

template <class T>
void Hash<T>::print(){
    for (int i = 0; i < tam_tabla; ++i)
    {
        if(tabla[i]){
            cout<<i<<" "<<tabla[i]->key<<endl;
        }
        else{
            cout<<i<<" "<<"vacio"<<endl;
        }
       
    }
}

int main(){
	Hash<int> hash;
    for (int i = 0; i < tam_tabla; ++i)
    {
        int r = rand()%tam_tabla;
        hash.insertar(r);
    }
    hash.print();
    hash.buscar(68);
	return 0;
}