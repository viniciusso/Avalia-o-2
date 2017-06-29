#ifndef GRAFICO_H
#define GRAFICO_H

#include <QWidget>
#include <QVector>

/**
 * @brief The Grafico class permite criar um gráfico de acordo com os dados capturados no servidor.
 */
class Grafico : public QWidget
{
  Q_OBJECT
public:

    /**
     * @brief Grafico é a classe complementar do programa.
     * @param O parent é um ponteiro para Qwidget
     * que indica onde o grafico será desenhado.
     */
  explicit Grafico(QWidget *parent = 0);

    /**
     * @brief No setEixoX() é feito a atualização dos dados no eixo X.
     */
  void setEixoX(QVector<double>);
  /**
   * @brief No setEixoY() é feito a atualização dos dados no eixo Y.
   */
  void setEixoY(QVector<double>);

public slots:

protected:

  /**
   * @brief No paintEvent() é feito toda a manipulação do gráfico. Nesse caso,
   * é feito o desenho e a pintura nas bordas, linhas e no fundo do gráfico;
   * define a grossura do traço e determina como será desenhado o gráfico na
   * tela.
   */
  void paintEvent(QPaintEvent *e);

private:

  /**
   * @brief No vector eixoX é armazenado os dados correspondentes ao eixo X.
   */
  QVector<double> eixoX;
  /**
   * @brief No vector eixoY é armazenado os dados correspondentes ao eixo Y.
   */
  QVector<double> eixoY;

};

#endif // GRAFICO_H
