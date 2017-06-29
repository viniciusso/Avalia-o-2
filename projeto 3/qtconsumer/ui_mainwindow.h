/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "grafico.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEditIP;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonConectar;
    QPushButton *pushButtonDesconectar;
    QPushButton *pushButtonAtualizar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *horizontalSliderConsumidor;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonIniciar;
    QPushButton *pushButtonParar;
    Grafico *grafico;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(602, 440);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        textEditIP = new QTextEdit(centralWidget);
        textEditIP->setObjectName(QStringLiteral("textEditIP"));

        verticalLayout_2->addWidget(textEditIP);

        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout_2->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonConectar = new QPushButton(centralWidget);
        pushButtonConectar->setObjectName(QStringLiteral("pushButtonConectar"));

        horizontalLayout->addWidget(pushButtonConectar);

        pushButtonDesconectar = new QPushButton(centralWidget);
        pushButtonDesconectar->setObjectName(QStringLiteral("pushButtonDesconectar"));

        horizontalLayout->addWidget(pushButtonDesconectar);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        pushButtonAtualizar = new QPushButton(centralWidget);
        pushButtonAtualizar->setObjectName(QStringLiteral("pushButtonAtualizar"));

        verticalLayout_4->addWidget(pushButtonAtualizar);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalSliderConsumidor = new QSlider(centralWidget);
        horizontalSliderConsumidor->setObjectName(QStringLiteral("horizontalSliderConsumidor"));
        horizontalSliderConsumidor->setMinimum(1);
        horizontalSliderConsumidor->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(horizontalSliderConsumidor);


        verticalLayout_7->addLayout(verticalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonIniciar = new QPushButton(centralWidget);
        pushButtonIniciar->setObjectName(QStringLiteral("pushButtonIniciar"));

        horizontalLayout_3->addWidget(pushButtonIniciar);

        pushButtonParar = new QPushButton(centralWidget);
        pushButtonParar->setObjectName(QStringLiteral("pushButtonParar"));

        horizontalLayout_3->addWidget(pushButtonParar);


        verticalLayout_7->addLayout(horizontalLayout_3);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_7);

        grafico = new Grafico(centralWidget);
        grafico->setObjectName(QStringLiteral("grafico"));

        formLayout->setWidget(0, QFormLayout::FieldRole, grafico);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderConsumidor, SIGNAL(sliderMoved(int)), label_3, SLOT(setNum(int)));
        QObject::connect(pushButtonConectar, SIGNAL(clicked()), MainWindow, SLOT(conectar()));
        QObject::connect(pushButtonDesconectar, SIGNAL(clicked()), MainWindow, SLOT(desconectar()));
        QObject::connect(pushButtonParar, SIGNAL(clicked()), MainWindow, SLOT(parar()));
        QObject::connect(pushButtonIniciar, SIGNAL(clicked()), MainWindow, SLOT(iniciar()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "IP do servidor:", 0));
        pushButtonConectar->setText(QApplication::translate("MainWindow", "Conectar", 0));
        pushButtonDesconectar->setText(QApplication::translate("MainWindow", "Desconectar", 0));
        pushButtonAtualizar->setText(QApplication::translate("MainWindow", "Atualizar", 0));
        label_2->setText(QApplication::translate("MainWindow", "Intervalo de tempo", 0));
        label_3->setText(QApplication::translate("MainWindow", "1", 0));
        pushButtonIniciar->setText(QApplication::translate("MainWindow", "Iniciar", 0));
        pushButtonParar->setText(QApplication::translate("MainWindow", "Parar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
