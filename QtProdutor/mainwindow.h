#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>


namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class permite criar uma
 * janela e mostrar componentes na tela.
 *
 * @details A partir dela, permite realizar as funcionalidades do programa como:
 * conectar e desconectar do servidor, e iniciar e parar a produção de dados num determinado intervalo de tempo estipulado
 * pelo usuário.
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
     * @brief As variáveis menor e maior são usados para determinar o intervalo de valores aleatórios
     * que podem ser gerados. E o timerID é a variável destinada a controlar o espaço de tempo na produção dos dados.
     */
    int menor;
    int maior;
    int timerID;

public slots:
    /**
     * @brief Em conectar() faz a captura do IP informado e tenta realizar a conexão com o servidor com a porta,
     * no caso, 1234.
     */
  void conectar();
  /**
   * @brief Em desconectar() realiza o encerramento da comunicação com o servidor.
   */
  void desconectar();
  /**
   * @brief Em iniciar() captura os valores da faixa de valores; faz a verificação da faixa de valores, se os campos
   * estão vazios ou não; converte o conteúdo dos campos em inteiro; verifica se os valores foram colocados
   * em locais trocados; e por fim um timer para começar a produção de dados.
   */
  void iniciar();
  /**
   * @brief Em parar() interrompe a produção de dados, parando o tempo.
   */
  void parar();

protected:
  /**
   * @brief O timerEvent() é um temporizador de eventos, que permite no caso enviar ao servidor e colocar no textEdit
   * os dados com sua data/hora.
   */
  void timerEvent(QTimerEvent *e);

};

#endif // MAINWINDOW_H
