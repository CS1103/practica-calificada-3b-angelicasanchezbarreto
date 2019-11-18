//
// Created by lica-pc on 11/17/19.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

#ifndef PC3B_FUNCIONES_H
#define PC3B_FUNCIONES_H

using namespace std;

template <typename T>
struct Rectangulo{
    T x, y, filas, columnas;
    char A;
    //Rectangulo()= default;
    bool operator < (const Rectangulo<T> & rec) const {
        return x < rec.x;
    }
    friend ostream &operator<<( ostream &file_salida, const Rectangulo &Rec ) {
        file_salida <<Rec.A<<" "<<Rec.x<<" "<<Rec.y<<" "<<Rec.filas<<" "<<Rec.columnas;
        return file_salida;
    }
};

bool valido();
void leer();
void imprimir();
void ordenar();
bool interseca();
void escribir();

template <typename T>
void leer(const string &file_name ){
    int num_rec = 0, filas=0, columnas=0;
    vector<Rectangulo<T>> vec;

    ifstream file_rectangulos(file_name);
    if(!file_rectangulos.is_open()){
        cout << "ERROR"<<endl;
    }
    else {
        file_rectangulos>>num_rec>>filas>>columnas;
        //cout << num_rec << " " << filas << " " << columnas << " " << endl;
        for(int i=0; i<num_rec; i++){
            Rectangulo<T> rec{};
            file_rectangulos>>rec.A>>rec.x>>rec.y>>rec.filas>>rec.columnas;
            vec.push_back(rec);
        }
    }
    file_rectangulos.close();
    cout<<"Rectangulos con intersecciones:"<<endl;
    imprimir(vec);
    cout<<"Rectangulos sin intersecciones:"<<endl;
    valido(vec);
    sort(vec.begin(), vec.end());
    cout<<"Rectangulos sin intersecciones ordenados:"<<endl;
    imprimir(vec);
    escribir("rectangulos2.out", vec);
}

template <typename T>
void imprimir(vector<Rectangulo<T>> vec){
    for(auto &rec: vec)
        cout<<rec.A<<" "<<rec.x<<" "<<rec.y<<" "<<rec.filas<<" "<<rec.columnas<<endl;

    cout << endl;
}


template <typename Rectangulo>
bool interseca(Rectangulo l1, Rectangulo r1, Rectangulo l2, Rectangulo r2)
{
    if (l1.x > r2.filas+r2.x-1 || l2.x > r1.filas+r1.x-1)
        return false;

    if (l1.y < r2.columnas+r2.y-1 || l2.y < r1.columnas+r1.y-1)
        return false;

    return true;
}
template <typename T>
void valido(vector<Rectangulo<T>> rectangulos){
    for(size_t i=0; i<rectangulos.size(); i++ ){
        for(size_t j=1+i; j<rectangulos.size(); j++){
            if(interseca(rectangulos[i],rectangulos[i],rectangulos[j],rectangulos[j])){
                rectangulos.erase(rectangulos.begin()+j-1);
            }
        }
    }
    imprimir(rectangulos);
}



template <typename T>
void escribir(const char *file_name, vector<Rectangulo<T>> vec){
    ofstream file_rectangulos(file_name);
    for(auto &rec:vec) {
        file_rectangulos<<rec<<endl;
    }
}





#endif //PC3B_FUNCIONES_H
