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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSair;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QTextEdit *textEdit_IP;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_FaixaMenor;
    QTextEdit *textEdit_FaixaMaior;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSlider_Intervalo;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Conectar;
    QPushButton *pushButton_Desconectar;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit_Tela;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(638, 528);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        QIcon icon;
        icon.addFile(QStringLiteral("sair.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSair->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        textEdit_IP = new QTextEdit(centralwidget);
        textEdit_IP->setObjectName(QStringLiteral("textEdit_IP"));

        horizontalLayout_3->addWidget(textEdit_IP);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        textEdit_FaixaMenor = new QTextEdit(centralwidget);
        textEdit_FaixaMenor->setObjectName(QStringLiteral("textEdit_FaixaMenor"));

        verticalLayout_2->addWidget(textEdit_FaixaMenor);

        textEdit_FaixaMaior = new QTextEdit(centralwidget);
        textEdit_FaixaMaior->setObjectName(QStringLiteral("textEdit_FaixaMaior"));

        verticalLayout_2->addWidget(textEdit_FaixaMaior);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        horizontalSlider_Intervalo = new QSlider(centralwidget);
        horizontalSlider_Intervalo->setObjectName(QStringLiteral("horizontalSlider_Intervalo"));
        horizontalSlider_Intervalo->setMinimum(1);
        horizontalSlider_Intervalo->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_Intervalo);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_Start = new QPushButton(centralwidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));

        horizontalLayout_4->addWidget(pushButton_Start);

        pushButton_Stop = new QPushButton(centralwidget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));

        horizontalLayout_4->addWidget(pushButton_Stop);


        verticalLayout_4->addLayout(horizontalLayout_4);

        pushButton_Conectar = new QPushButton(centralwidget);
        pushButton_Conectar->setObjectName(QStringLiteral("pushButton_Conectar"));

        verticalLayout_4->addWidget(pushButton_Conectar);

        pushButton_Desconectar = new QPushButton(centralwidget);
        pushButton_Desconectar->setObjectName(QStringLiteral("pushButton_Desconectar"));

        verticalLayout_4->addWidget(pushButton_Desconectar);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        textEdit_Tela = new QTextEdit(centralwidget);
        textEdit_Tela->setObjectName(QStringLiteral("textEdit_Tela"));

        horizontalLayout_5->addWidget(textEdit_Tela);


        verticalLayout_6->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 638, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QIcon icon1;
        QString iconThemeName = QStringLiteral("File");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("servidor.png"), QSize(), QIcon::Selected, QIcon::Off);
        }
        menuFile->setIcon(icon1);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSair);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_Conectar, SIGNAL(clicked()), MainWindow, SLOT(conectar()));
        QObject::connect(pushButton_Desconectar, SIGNAL(clicked()), MainWindow, SLOT(desconectar()));
        QObject::connect(pushButton_Start, SIGNAL(clicked()), MainWindow, SLOT(iniciar()));
        QObject::connect(pushButton_Stop, SIGNAL(clicked()), MainWindow, SLOT(parar()));
        QObject::connect(horizontalSlider_Intervalo, SIGNAL(sliderMoved(int)), label_4, SLOT(setNum(int)));
        QObject::connect(actionSair, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0));
#ifndef QT_NO_TOOLTIP
        actionSair->setToolTip(QApplication::translate("MainWindow", "Sair do programa", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "IP:", 0));
        textEdit_IP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "Faixa:", 0));
        textEdit_FaixaMenor->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", 0));
        textEdit_FaixaMaior->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "Intervalo:", 0));
        label_4->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "Start", 0));
        pushButton_Stop->setText(QApplication::translate("MainWindow", "Stop", 0));
        pushButton_Conectar->setText(QApplication::translate("MainWindow", "Conectar", 0));
        pushButton_Desconectar->setText(QApplication::translate("MainWindow", "Desconectar", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
