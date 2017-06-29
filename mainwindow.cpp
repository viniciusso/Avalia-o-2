#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QListView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    model = new QStringListModel(this);
    ui->listView->setModel(model);
    timerID = 0;
}

MainWindow::~MainWindow() // Destrutor
{
    delete ui;
    delete socket;
    delete model;

}

void MainWindow::conectar()
{
    QString ip = ui->textEditIP->toPlainText(); // Captura o IP colocado no textEdit.

    socket->connectToHost(ip,1234); // Tenta conectar o IP com determinada porta, no caso 1234.


    if(socket->waitForConnected(3000)){
        ui->statusBar->showMessage("Conectado com sucesso!");
        model->insertRows(0,1); // Adiciona linhas no listview.
        model->setData(model->index(0),ui->textEditIP->toPlainText()); // Coloca o ip do servidor conectado no listview.
    }
    else{
        ui->statusBar->showMessage("Erro na conexão!");
    }
}

void MainWindow::desconectar()
{
    socket->close(); // Fecha a conexão.
    ui->statusBar->showMessage("Servidor desconectado!");
}

void MainWindow::parar()
{
    if(socket->isOpen()){
        killTimer(timerID); // Pára o tempo.
        ui->statusBar->showMessage("Parado!");
    }
    else{
        ui->statusBar->showMessage("Precisa se conectar primeiro!");
    }
}

void MainWindow::iniciar()
{
    int intervalo = ui->horizontalSliderConsumidor->value();
    timerID = startTimer(intervalo*1000); // Tempo de intervalo que leva para capturar novos dados. Inicializa o timerEvent.
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    double menorx, maiorx, menory, maiory;
    QVector<double> eixoX;
    QVector<double> eixoY;
    QVector<double> eixoY_temp;
    QString str;
    QStringList list;
    QDateTime datetime;
    if(socket->state()== QAbstractSocket::ConnectedState){
      socket->write(QString("get " + ui->textEditIP->toPlainText() + "\r\n").toStdString().c_str()); // Converte para String.
      socket->waitForBytesWritten(3000); // Espera até 3s para validar se uma carga de dados foi escrito no servidor.
      socket->waitForReadyRead(3000); // Espera até 3s para validar se uma carga de dados está disponível para leitura no servidor.

      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          datetime = QDateTime::fromString(list.at(0),Qt::ISODate);
          str = list.at(1);

          eixoX.append(datetime.toTime_t()); // Insere os valores datetime em segundos que se passaram no final do vector eixoX.
          eixoY.append(str.toFloat()); // Insere os valores str convertido em float no final do vector eixoY.
          eixoY_temp.append(str.toFloat()); // Insere os valores str convertido em float no final do vector eixoY temporário.
        }
      }
      menorx = eixoX.at(0); // Encontra o menor valor X (posição 0).
      maiorx = eixoX.at(eixoX.size()-1); // Encontra o maior valor X.

      for(int i = 0; i < eixoX.size(); i++)
      {
          eixoX.replace(i, (eixoX.at(i)-menorx)/(maiorx-menorx)); // Normaliza os valores de X (0 - 1).
      }

      qSort(eixoY_temp); // Ordena o eixo Y temporário para facilitar na descoberta do menor e maior valor em Y.

      menory = eixoY_temp.at(0); // Encontra o menor valor Y (posição 0).
      maiory = eixoY_temp.at(eixoY_temp.size()-1); // Encontra o maior valor Y.
      for(int i = 0; i < eixoY_temp.size(); i++)
      {
          eixoY.replace(i,(eixoY.at(i)-menory)/(maiory-menory)); // Normaliza os valores de Y (0 - 1).
      }

      ui->grafico->setEixoX(eixoX);
      ui->grafico->setEixoY(eixoY);
      ui->grafico->update(); // Atualiza o gráfico.
    }

}

