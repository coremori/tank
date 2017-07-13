#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent)
{
    QWidget *gameWindow = new QWidget;

     QMenu* test = new QMenu();
     test->addMenu(tr("&File"));
     //menuBar()->addMenu(tr("&File"));

    gameWindow->setMinimumSize(900,200);
    gameWindow->setStyleSheet("background-color:black;");

    QPushButton *button1 = new QPushButton("Next Turn");
    // manque les connects

    QGridLayout *layout = new QGridLayout;
    QGridLayout *layoutGlobal = new QGridLayout;

    layout->addWidget(button1, 1, 0, 1, 2,Qt::AlignHCenter);

    layoutGlobal->addWidget(test,0,0);
    layoutGlobal->addWidget(gameWindow,1,0);
    layoutGlobal->addLayout(layout,2,0);


    this->setLayout(layoutGlobal);
    this->show();

}

MainWindow::~MainWindow()
{

}
