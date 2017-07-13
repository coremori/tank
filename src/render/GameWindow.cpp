//#include "GameWindow.h"

//GameWindow::GameWindow(QWidget* Parent, const QPoint& Position, const QSize& Size) :
//QSFMLCanvas(Parent, Position, Size)
//{

//}

//void GameWindow::OnInit()
//{
//    // On charge une image
//    myImage.LoadFromFile("datas/qt/sfml.png");

//    // On paramètre le sprite
//    mySprite.SetImage(myImage);
//    mySprite.SetCenter(mySprite.GetSize() / 2.f);
//}

//void GameWindow::OnUpdate()
//{
//    // On efface l'écran
//    Clear(sf::Color(0, 128, 0));

//    // Une petite rotation du sprite
//    mySprite.Rotate(GetFrameTime() * 100.f);

//    // Et on l'affiche
//    Draw(mySprite);
//}
