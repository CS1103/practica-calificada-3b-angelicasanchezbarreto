//
// Created by lica-pc on 11/17/19.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
};

bool valido();
void leer();
void imprimir();
void ordenar();
bool interseca();

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
    imprimir(vec);
    sort(vec.begin(), vec.end());
    imprimir(vec);
    valido(vec);

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






#endif //PC3B_FUNCIONES_H
