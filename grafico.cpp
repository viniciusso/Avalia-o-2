#include "grafico.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QDebug>

Grafico::Grafico(QWidget *parent) : QWidget(parent)
{

}


void Grafico::setEixoX(QVector<double> eixo_X) // Atualiza o valor do eixo X.
{
    eixoX = eixo_X;
}

void Grafico::setEixoY(QVector<double> eixo_Y) // Atualiza o valor do eixo Y.
{
    eixoY = eixo_Y;
}

void Grafico::paintEvent(QPaintEvent *e){
  QPainter painter(this);
  QBrush brush; // Preenchimento
  QPen pen; // Contorno
  int xi, xf, yi, yf;

  painter.setRenderHint(QPainter::Antialiasing); // Para as retas do gráfico não ficarem serrilhadas.

  pen.setColor(QColor(0,0,255)); // Desenha o contorno do fundo do gráfico na cor azul.
  painter.setPen(pen);

  brush.setColor(QColor(255,255,0)); // Colore o fundo do gráfico na cor amarela.
  brush.setStyle(Qt::SolidPattern);
  painter.setBrush(brush);

  painter.drawRect(0,0,width()-1, height()-1); // Desenha o fundo da tela.


  pen.setColor(QColor(0,0,255)); // Desenha as linhas do gráfico na cor azul.

  pen.setWidth(2); // Define a grossura do traço.
  painter.setPen(pen);

  if(eixoX.size()>0){
    xi = eixoX.at(0);
    yi = eixoY.at(0);

//    Sabendo que o primeiro ponto do gráfico surge na composição de (x,y) localizados na primeira posição de seus vetores,
//    o for a seguir é inicializado a partir de 1 até o tamanho máximo do eixoX.

    for(int i = 1; i < eixoX.size(); i++)
    {
        xf = qRound(eixoX.at(i)*width());
        yf = height() - qRound(eixoY.at(i)*height());
        painter.drawLine(xi,yi,xf,yf); // Determina como será desenhado o gráfico na tela.
        xi = xf; // Atualiza os valores de x.
        yi = yf; // Atualiza os valores de y.
    }
  }
}






