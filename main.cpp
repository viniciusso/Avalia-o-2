#include <iostream>
#include <cmath>
#define MAX  200
using namespace std;

class Point{
private:
    float x, y;
public:
    Point();
    Point(float cx, float cy);
    void setX(float cx);
    void setY(float cy);
    void setXY(float cx, float cy);
    float getX();
    float getY();
    Point add(Point p1);
    Point sub(Point p1);
    float norma();
    void translada(float a, float b);
    void imprime();
};

class Poligono{
    private:
        Point poli[MAX];
        int x1 = 0;
    public:
        void addVer(float x, float y);
        int getx1();
        Point getOrigin();
        int count();
        float area();
        void translada(float a, float b);
        void rotacionar(float angulo, Point p);
        void imprimir();
};

class Retangulo: public Poligono{
    private:
        float x, y;
        float largura, altura;
    public:
        Retangulo(float x, float y, float largura, float altura);
};

Point::Point(){}
Point::Point(float cx, float cy){
    x = cx;
    y = cy;
}

void Point::setX(float cx){
    x = cx;
}
void Point::setY(float cy){
    y = cy;
}
void Point::setXY(float cx, float cy){
    x = cx;
    y = cy;
}
float Point::getX(){
    return x;
}
float Point::getY(){
    return y;
}
Point Point::add(Point p1){
    Point p3;
    p3.x = x + p1.x;
    p3.y = y + p1.y;
    return p3;
}
Point Point::sub(Point p1){
    Point p3;
        p3.x = x - p1.x;
        p3.y = y - p1.y;

        return p3;
}
float Point::norma(){
    return sqrt(pow(x, 2) + pow(y, 2));
}
void Point::translada(float a, float b){
    x = x + a;
    y = y + b;
}
void Point::imprime(){
    cout << "("<< x << ", "<< y <<")"<< endl;
}

Retangulo::Retangulo(float x, float y, float altura, float largura){
    this->addVer(x, y);
    this->addVer(x + largura, y);
    this->addVer(x + largura, y + altura);
    this->addVer(x, y + altura);
}


void Poligono::addVer(float x, float y){
    poli[x1].setXY(x, y);
    x1++;
}

int Poligono::count(){
    return x1;
}

Point Poligono::getOrigin(){
    return poli[0];
}

float Poligono::area(){
    float area = 0.0;
    int size = x1;
    /*Aqui é a formula do Shoelace*/
    int j = size - 1;
    for (int i = 0; i < size; i++){
        area += (poli[j].getX() + poli[i].getX()) * (poli[j].getY() - poli[i].getY());
        j = i;
    }
    return abs(area / 2.0);
}

void Poligono::translada(float a, float b){
    int n = x1;
    for(int i=0;i<n;i++){
        poli[i].setX(poli[i].getX() + a);
        poli[i].setY(poli[i].getY() + b);
    }
}
void Poligono::rotacionar(float angulo, Point p){
    float s, c, x2, y2;
    int size = x1;
    for(int i = 0; i < size; i++){
        s = sin(angulo);
        c = cos(angulo);

        poli[i].setX(poli[i].getX() - p.getX());
        poli[i].setY(poli[i].getY() - p.getY());

        x2 = poli[i].getX() * c - poli[i].getY() * s;
        y2 = poli[i].getX() * s + poli[i].getY() * c;

        poli[i].setX(x2 + p.getX());
        poli[i].setY(y2 + p.getY());

    }
}
void Poligono::imprimir(){
    int n = x1;
        for(int i = 0; i < n; i++){
                cout << "(" << poli[i].getX() << ", " << poli[i].getY() << ")";
        if(i < n-1){
            cout << " -> ";
        }
        }
    cout << endl;
}



int main(){

    Retangulo retan(0, 0, 3, 4);
    retan.imprimir();
    cout << "A area eh "<< retan.area() << endl;

    cout << endl << "Translacao"<< endl;
    retan.translada(-3, 4);
    cout << "Pontos depois de translacao com (-3, 4) sao: ";
    retan.imprimir();
    cout << "A area apos translacao eh "<< retan.area() << endl;

    cout << endl << "Rotacao"<< endl;
    /*calculo do centro de massa*/
    Point origin = retan.getOrigin();
    float xCM = origin.getX() + (4/2);
    float yCM = origin.getY() + (3/2);
    /*Rotacao de 30 graus*/
    Point pCM(xCM, yCM);
    retan.rotacionar(30, pCM);
    cout << "coordenadas com 30 graus em relacao ao seu centro de massa: ";
        retan.imprimir();
        cout << "A area apos translacao eh: "<< retan.area() << endl;

    return 0;
}
