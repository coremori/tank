#include "mainwindow.h"
#include <QApplication>
#include "trace.h"

#include "state/ElementManager.h"

#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication App(argc, argv);

    // On crée la fenêtre principale
//    QFrame* MainFrame = new QFrame;
//    MainFrame->setWindowTitle("Qt SFML");
//    MainFrame->resize(400, 400);
//    MainFrame->show();

    //On crée une vue SFML dans la fenêtre principale
//    MyCanvas* SFMLView = new MyCanvas(MainFrame, QPoint(20, 20), QSize(360, 360));
//    SFMLView->show();




    ElementManager *test = new ElementManager(1000,500);
    test->loadFile("C:\\Users\\coren\\Documents\\tank\\tank\\res\\Levels\\level1.txt");
    //test->createElementSub(str[0]);
    MainWindow w;
    w.show();
    return App.exec();
//    return a.exec();
}
