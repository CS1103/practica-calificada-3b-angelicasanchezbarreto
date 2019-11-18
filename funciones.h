//
// Created by lica-pc on 11/17/19.
//
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>
#include "rectangulo.cpp"
#ifndef PC3B_FUNCIONES_H
#define PC3B_FUNCIONES_H

void leer();
void imprimir();
bool interseca();
bool valido();
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
            if(rec.A=='A')
                vec.push_back(rec);
            else
                cout<<"No se encontó esa acción";
        }
    }
    file_rectangulos.close();
    cout<<"Rectangulos con intersecciones:"<<endl;
    imprimir(vec);
    cout<<"Rectangulos sin intersecciones:"<<endl;
    vec = valido(vec);
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
bool interseca(Rectangulo rec1, Rectangulo rec2){
    int x1_left = rec1.x;
    int y1_left = rec1.y;
    int x1_right = rec1.filas+x1_left;
    int y1_right = rec1.columnas+y1_left;
    int x2_left = rec2.x;
    int y2_left = rec2.y;
    int x2_right = rec2.filas+x2_left;
    int y2_right = rec2.columnas+y2_left;

    if( (x1_left == x2_left && y1_left == y2_left)
           && (x2_right > x1_right || y2_right > y1_right || x1_right > x2_right || y1_right > y2_right ) )
        return true;

    if(x1_left>x2_right || x2_left>x1_right)
        return false;

    if(y1_left<y2_right || y2_left<y1_right)
        return false;

    return false;
}

template <typename T>
vector<Rectangulo<T>> valido(vector<Rectangulo<T>> rectangulos){
    for(size_t i=0; i<rectangulos.size(); i++ ){
        for(size_t j=1+i; j<rectangulos.size(); j++){
            if(interseca(rectangulos[i],rectangulos[j])){
                rectangulos.erase(rectangulos.begin()+j);
            }
        }
    }
    imprimir(rectangulos);
    return rectangulos;
}



template <typename T>
void escribir(const char *file_name, vector<Rectangulo<T>> vec){
    ofstream file_rectangulos(file_name);
    for(auto &rec:vec) {
        file_rectangulos<<rec<<endl;
    }
}





#endif //PC3B_FUNCIONES_H
