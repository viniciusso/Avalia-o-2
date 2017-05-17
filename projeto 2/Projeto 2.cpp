#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Screen{
private:
  int nlin, ncol;
  char brush;
  vector< vector<char> > mat;

public:
  Screen();
  Screen(int nl, int nc);
  vector< vector<char> > getMat();
  void setPixel(int x, int y);
  void clear();
  void setBrush(char brush);
  friend ostream& operator<<(ostream &os, Screen &t);
};

class FiguraGeometrica
{
public:
    FiguraGeometrica();

    virtual void draw(Screen &t)=0;
};

/*==================== CIRCULO ====================*/
class Circulo : public FiguraGeometrica{
private:
    int xc; int yc; int raio; bool cheio;
public:
    Circulo(int xcen, int ycen, int r, bool completo);
    void draw(Screen &t);
};

Circulo::Circulo(int xcen, int ycen, int r, bool completo){
    xc=xcen;
    yc=ycen;
    raio=r;
    cheio = completo;
}

void Circulo::draw(Screen &t){
    int x0, y0, x1, y1, yt;
    x0 = xc - raio;
    x1 = xc + raio;
    y0 = yc - raio;
    y1 = yc + raio;

   /* formula y=rais(r^2 - x^2)*/

    for(int i=x0; i<=x1; i++){
        yt=round(sqrt(pow(raio,2)-pow(i-xc, 2)) + yc);
        t.setPixel(i, yt);
        yt = round(yc-sqrt(pow(raio,2)-pow(i-xc, 2)));
        t.setPixel(i, yt);
    }

    int tempo;
    if(cheio){
        for(int i = x0; i <= x1; i++){
            for(int j = y0; j <= y1; j++){
                tempo = round(sqrt(pow(i-xc,2)+pow(j-yc, 2)));
                if(tempo <= raio){
                    t.setPixel(i,j);
                }
            }
        }
    }
}

/*==================== RETANGULO ====================*/
class Retangulo : public FiguraGeometrica
{
private:
    int x0; int y0; int largura; int altura;
public:
    Retangulo(int x1, int y1, int L, int H);
    void draw(Screen &t);
};

Retangulo::Retangulo(int x1, int y1, int L, int H){
    x0 = x1;
    y0 = y1;
    largura = L;
    altura = H;
}

void Retangulo::draw(Screen &t){

    for(int i=x0; i<x0+largura; i++){
        t.setPixel(i, y0);
        t.setPixel(i, y0+altura);
    }

    /*altura*/
    for(int j=y0; j<y0+altura; j++){
        t.setPixel(x0, j);
        t.setPixel(x0+largura-1, j);
        }
}

/*==================== RETA ====================*/
class Reta : public FiguraGeometrica
{
private:
    float x0; float y0; float x1; float y1;
public:
    Reta(float x, float y, float X1, float Y1);
    void draw(Screen &t);
};
void Reta::draw(Screen &t){
    float a, b;
    if(x0 == x1){
        for(int i=y0; i<=y1; i++)
        {
            t.setPixel(x0, i);
        }
    }else{
        a = (y1-y0)/(x1-x0);
        b = y1-a*x1;
        for(int i=x0; i<=x1; i++)
        {
            t.setPixel(i, round(a*i+b));
        }
    }
}

Reta::Reta(float x, float y, float X1, float Y1){
    x0 = x;
    y0 = y;
    x1 = X1;
    y1 = Y1;
}



/*===================================================================*/


Screen::Screen(){
}

Screen::Screen(int nl, int nc){
    nlin = nl;
    ncol = nc;
    mat.resize(nlin);
    for(int i=0;i<nlin;i++)
    {
        mat[i].resize(ncol, ' ');
    }
}

vector< vector<char> > Screen::getMat(){
    return mat;
}

void Screen::setPixel(int x, int y){
    mat[x][y] = brush;
}

void Screen::clear(){
    for(int i = 0; i<nlin;i++){
        for(int j = 0; j<ncol;j++){
                mat[i][j]=' ';
            }
        }
}

void Screen::setBrush(char _brush){
    brush = _brush;
}

ostream& operator<<(ostream &os, Screen &t){
    for(int j=0; j< t.nlin; j++){
        for(int i=0; i< t.ncol; i++){
            os << t.mat[i][j];
        }
        os << endl;
    }
    return os;
}

FiguraGeometrica::FiguraGeometrica()
{

}

int main(){

    Screen *t;
    FiguraGeometrica *f;


    ifstream input;
    ofstream output;
    string codigo;
    string file = "entrada.txt";
    string ofile = "saida.txt";

    int nlinhas, ncolunas, largura, altura, x0, y0, x1, y1, raio, cheio;
    char brush;

    input.open(file.c_str());
    output.open(ofile.c_str());

    if(input.is_open()){
        cout << "Opening The File"<<endl;

        string line;

        while(getline(input, line)){
            stringstream sstream(line);

            sstream >> codigo;

            if(codigo == "dim"){
                sstream >> nlinhas;
                sstream >> ncolunas;
                t = new Screen(nlinhas, ncolunas);
                t->clear();

                if(output.is_open()){
                    output << "Arquivo de saida com "<< nlinhas<< " linhas e "<<ncolunas<<" colunas" <<endl<<endl;;
                }

            }else if(codigo == "brush"){
                sstream >> brush;

                if(!sstream.good()){
                    brush = ' ';
                }
                t->setBrush(brush);

            }else if(codigo == "line"){
                sstream >> x0;
                sstream >> y0;
                sstream >> x1;
                sstream >> y1;
                f = new Reta(x0, y0, x1, y1);
                f->draw(*t);
                cout << *t;
                if(output.is_open()){
                    output << *t <<endl;
                }
                t->clear();
            }else if(codigo == "rectangle"){
                sstream >> x0;
                sstream >> y0;
                sstream >> largura;
                sstream >> altura;
                f = new Retangulo(x0, y0, largura, altura);
                f->draw(*t);
                cout << *t;
                if(output.is_open()){
                    output << *t <<endl;
                }
                t->clear();
            }else if(codigo == "circle"){
                sstream >> x0;
                sstream >> y0;
                sstream >> raio;
                sstream >> cheio;
                if(cheio == 0){
                    f = new Circulo(x0, y0, raio, false);
                }else if(cheio == 1){
                    f = new Circulo(x0, y0, raio, true);
                }
                f->draw(*t);
                cout << *t;
                if(output.is_open()){
                    output << *t <<endl;
                }
                t->clear();

            }
            delete(f);
            codigo.clear();
        }
    }else{
        cout << "File cant be opened"<<endl;
    }
    output.close();
    input.close();
    return 0;
}
