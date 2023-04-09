#include "foo.h"



Matriz2D::Matriz2D() : filas(3) , columnas(3) {
    ptr = new float* [filas] ;

    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
    }

}

Matriz2D::Matriz2D(int n) : filas(n) ,columnas(n){
    ptr = new float* [n] ;

    for(int i = 0; i < n; i++){
        ptr[i] = new float[n];
    }



}

Matriz2D::Matriz2D(int n, int m) : filas(n) , columnas(m){
    ptr = new float*[n];

    for(int i = 0; i < n; i++){
        ptr[i] = new float[m];
    }



}

Matriz2D::Matriz2D(const Matriz2D& m) : ptr(m.ptr) , filas(m.filas) , columnas(m.columnas){
    cout<<endl ;
}

Matriz2D::Matriz2D(Matriz2D&& m){

    filas = m.filas ;
    columnas = m.columnas ;
    ptr = m.ptr ;
    m.ptr = nullptr ;
    m.filas = 0 ;
    m.columnas = 0 ;
}


Matriz2D t(Matriz2D& m){
    int filas = m.columnas ;
    int columnas = m.filas ;

    Matriz2D ob(filas , columnas) ;
    for (int i = 0; i < filas ; ++i) {
        for (int j = 0; j <columnas; ++j) {
            ob.ptr[i][j] = m.ptr[j][i] ;
        }
    }


    return ob ;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    for (int i = 0; i < m.filas ; ++i) {
        for (int j = 0; j < m.columnas; ++j) {
            os<<m.ptr[i][j] <<" " ;
        }
        os<<endl ;
    }
    return os ;

}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    Matriz2D ob(m1.filas , m1.columnas) ;

    for (int i = 0; i < ob.filas ; ++i) {
        for (int j = 0; j < ob.columnas; ++j) {
            ob.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j] ;
        }
    }

    return ob ;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){

    Matriz2D ob(m1.filas , m1.columnas) ;

    for (int i = 0; i < ob.filas ; ++i) {
        for (int j = 0; j < ob.columnas; ++j) {
            ob.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j] ;
        }
    }

    return ob ;

}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){


    Matriz2D ob(m1.filas , m1.columnas) ;

    for (int i = 0; i < ob.filas ; ++i) {
        for (int j = 0; j < ob.columnas; ++j) {
            ob.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j] ;
        }
    }

    return ob ;
}

Matriz2D operator+(const Matriz2D& m, float n){

    Matriz2D ob(m.filas , m.columnas) ;

    for (int i = 0; i < ob.filas ; ++i) {
        for (int j = 0; j < ob.columnas; ++j) {
            ob.ptr[i][j] = m.ptr[i][j] + n ;
        }
    }

    return ob ;

}

Matriz2D operator-(const Matriz2D& m, float n){
    Matriz2D ob(m.filas , m.columnas) ;

    for (int i = 0; i < ob.filas ; ++i) {
        for (int j = 0; j < ob.columnas; ++j) {
            ob.ptr[i][j] = m.ptr[i][j] - n ;
        }
    }

    return ob ;
}

Matriz2D operator*(const Matriz2D& m, float n){
    Matriz2D ob(m.filas , m.columnas) ;

    for (int i = 0; i < ob.filas ; ++i) {
        for (int j = 0; j < ob.columnas; ++j) {
            ob.ptr[i][j] = m.ptr[i][j] * n ;
        }
    }

    return ob ;
}

Matriz2D operator/(const Matriz2D& m, float n){
    Matriz2D ob(m.filas , m.columnas) ;

    for (int i = 0; i < ob.filas ; ++i) {
        for (int j = 0; j < ob.columnas; ++j) {
            ob.ptr[i][j] = m.ptr[i][j] / n ;
        }
    }

    return ob ;
}

Matriz2D::~Matriz2D() {

    for (int i = 0; i < filas; i++){
        delete[] ptr[i];
    }
    delete[] ptr ;

}


float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
