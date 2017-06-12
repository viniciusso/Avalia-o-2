#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this); // Alocando memória pro socket.

    // Inicializando as variáveis no construtor para serem usadas em funções mais adiante.
    timerID = 0;
    menor = 0;
    maior = 0;
}

MainWindow::~MainWindow() // Destrutor
{
    delete ui;
    delete socket;
}

void MainWindow::conectar()
{    
    QString ip = ui->textEdit_IP->toPlainText(); // Captura o IP colocado no textEdit.

    socket->connectToHost(ip,1234); // Tenta fazer a conexão do IP com determinada porta, no caso 1234.

    //Espera conectar com o servidor até 3s.
    if(socket->waitForConnected(3000)){
        ui->statusbar->showMessage("Conectado com sucesso!");
    }
    else{
        ui->statusbar->showMessage("Erro na conexão!");
    }

}

void MainWindow::desconectar()
{
    socket->close(); // Fecha a conexão.
    ui->statusbar->showMessage("Servidor desconectado!");

}

void MainWindow::iniciar()
{
    // Captura os valores da faixa.
    QString faixaMenor = ui->textEdit_FaixaMenor->toPlainText();
    QString faixaMaior = ui->textEdit_FaixaMaior->toPlainText();

    // Se a conexão existir
    if(socket->isOpen()){
        // Caso um dos campos da faixa esteja vazio
        if(faixaMenor.isEmpty() || faixaMaior.isEmpty()){
            ui->statusbar->showMessage("Você precisa digitar a faixa de valores!");
            return;
        }
        else{

            // Converte menor e maior do tipo String para Inteiro.
            menor = faixaMenor.toInt();
            maior = faixaMaior.toInt();

            // Avalia se o menor valor foi colocado no campo de maior faixa ou vice-versa.
            if(menor > maior){
                ui->statusbar->showMessage("Erro no intervalo!");
                return;
            }
            else{
                ui->statusbar->showMessage("Produzindo valores...");
            }

            // Captura o valor do horizontalSlider.
            int intervalo = ui->horizontalSlider_Intervalo->value();

            // Tempo de intervalo que leva para gerar um dado e outro, multiplicando 1000ms (1s) pelo valor de intervalo escolhido.
            timerID = startTimer(intervalo*1000);

        }

    }
    else{
        ui->statusbar->showMessage("Precisa se conectar primeiro!");
    }
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    // Gera valor aleatório.
    int valor = qrand()%(maior - menor + 1) + menor;

    QDateTime datetime;
    QString str;

    if(socket->isOpen()){
        // Captura data e hora atual.
        datetime = QDateTime::currentDateTime();
        str = "set "+ datetime.toString(Qt::ISODate) + " " + QString::number(valor) + "\r\n";
        socket->write(str.toStdString().c_str());
        socket->waitForBytesWritten(3000); // Espera até 3s para validar se uma carga de dados foi escrito no servidor.
        ui->textEdit_Tela->append(str); // Joga no textEdit os valores gerados.
      }
}

void MainWindow::parar()
{
    QString faixaMenor = ui->textEdit_FaixaMenor->toPlainText();
    QString faixaMaior = ui->textEdit_FaixaMaior->toPlainText();

    if(socket->isOpen()){
        if(faixaMenor.isEmpty() || faixaMaior.isEmpty()){
            ui->statusbar->showMessage("Você precisa digitar a faixa de valores!");
            return;
        }
        killTimer(timerID); // Pára o tempo.
        ui->statusbar->showMessage("Produção de valores parado!");
    }
    else{
        ui->statusbar->showMessage("Precisa se conectar primeiro!");
    }
}
