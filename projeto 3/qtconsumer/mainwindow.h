#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QStringListModel>
#include <QVector>
#include "grafico.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class permite criar uma
 * janela e mostrar componentes na tela.
 *
 * @details A partir dela, permite realizar as funcionalidades do programa como:
 * conectar e desconectar do servidor, e iniciar e parar a exibição de dados plotados no gráfico.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief MainWindow é a classe principal do programa.
     * @param O parent é um ponteiro para Qwidget
     * que indica onde a mainwindow será desenhada.
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
      * @brief ~MainWindow() é o destrutor da classe MainWindow.
      */
    ~MainWindow();

private:

    /**
     * @brief ui é o ponteiro para o componente principal.
     */
    Ui::MainWindow *ui;

    /**
     * @brief socket é o ponteiro para o TCP (Protocolo de Controle de Transmissão),
     * por meio da QTcpSocket class.
     */
    QTcpSocket *socket;

    /**
     * @brief model é o ponteiro para a listView, por meio da QStringListModel class.
     */
    QStringListModel *model;

    /**
     * @brief timerID é a variável declarada para ser usado na inicialização (startTimer()).
     */
    int timerID;

public slots:

    /**
     * @brief Em conectar() faz a captura do IP informado e tenta realizar a conexão com o servidor com a porta,
     * no caso, 1234. Se a conexão for um sucesso, o IP é adicionado na listView.
     */
    void conectar();

    /**
     * @brief Em desconectar() realiza o encerramento da comunicação com o servidor.
     */
    void desconectar();

    /**
     * @brief Em parar() interrompe a produção de dados, parando o tempo.
     */
    void parar();

    /**
     * @brief Em iniciar(), juntamente com a variável timerID, é realizado a inicialização da captura, sendo controlado
     * pelo HorizontalSlider, determinando o intervalo de tempo que deve pegar os dados do servidor e plotar no gráfico.
     */
    void iniciar();

protected:

    /**
     * @brief O timerEvent() é um temporizador de eventos, que no caso vai capturar do servidor os dados com sua data/hora
     * e, enquanto existir, vai sendo adicionado em três vetores: eixoX, eixoY e eixoY_temp. O eixoX, por ser data/hora,
     * sabe-se como encontrar o menor (primeiro valor no vetor) e o maior (último valor no vetor) de forma mais rápida.
     * Já no eixo Y, foi preciso criar um vetor temporário que recebe os mesmos valores do eixo Y original. A diferença
     * é que o temporário é feito uma ordenação de valores. Dessa forma, é possível indicar o menor e o maior valor no
     * vetor. Assim, é feito a normalização dos eixos X e Y (0 - 1), para que todos os pontos sejam colocados dentro do
     * gráfico de maneira proporcional aos seus valores, sendo dentro do intervalo 0 e 1.
     */
    void timerEvent(QTimerEvent *e);
};


#endif // MAINWINDOW_H
