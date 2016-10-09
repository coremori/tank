#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML


using namespace std;

int main(int argc,char* argv[]) 
{
    sf::Texture texture;  //WARNING : texture ne doit pas être supprimer après être affecter à sprite (carré blanc sinon)
    if (!texture.loadFromFile("res/Textures/textures.png", sf::IntRect(0, 0,24, 24))) //rectangle de point (0,0) et de taille 24*24
    {
        return 1;//if not open
    }
    
    sf::Texture sand;
    if (!sand.loadFromFile("res/Textures/textures.png", sf::IntRect(0,88,8, 8))) //rectangle de point (x=0,y=88) et de taille (x=8*y=8) 
    {
        return 2;
    }
    
    sf::Texture sky;
    if (!sky.loadFromFile("res/Textures/textures.png", sf::IntRect(24,88,8, 8))) 
    {
        return 3;
    }
    sky.setRepeated(true);//on veut le répéter si le rectangle est plus grand que lui
    sf::Sprite orangina; //crée le sprite
    
    sand.setRepeated(true);
    sf::Sprite sprite; 
    sf::Sprite coca;
    coca.setTexture(texture);//WARNING : texture ne doit pas être supprimer après être affecter à sprite (carré blanc sinon)
    
    sprite.setTexture(sand);
    sprite.setTextureRect(sf::IntRect(0, 0, 24, 8));//donne la taille du sprite (qui ici est plus grand que la texture et sera répeter grace à setRepeated)
    sprite.setPosition(sf::Vector2f(0,24));//place le sprite au coordonnée x=0 et y=24
    orangina.setTexture(sky);
    orangina.setTextureRect(sf::IntRect(0, 0, 24, 24));
    
    //le setTextureRect ne sera pas utilisé, mais c'est moins chiant à faire qu'un putain de tableau de vector
    
    sf::RenderWindow window(sf::VideoMode(200, 200), L"Peut-tu seulement dépasser la médiocrité ?");// fenetre d'affichage

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        window.draw(orangina);
        window.draw(coca);
        window.draw(sprite);//on les traces dans cette ordre là (le dernier tracer est au dessus (notamment pour le char))
        
        window.display();
    }
    
    
    
    return 0;
}
