
#include <iostream>

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