#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state/Element.h"

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML


using namespace std;

int main(int argc,char* argv[]) 
{
    /*render::Scene* s = new render::Scene();
    
        render::Surface* surface = new render::SurfaceSFML();
        surface->loadTexture("res/Textures/textures.png",0,88);//sand
        render::Layer* l = new render::Layer();
        surface->setSpriteTexture(0,layers[0]->getTile(0))
        l->setSurface(surface);
        
        l->setTile(new render::Tile());
        l->setTile(new render::Tile(0,8));
        l->setTile(new render::Tile(0,16));
        
        
        s->layers.push_back(l);
        
        
        s->layers[0]->surface;
        s->layers[0]->surface->setSpriteTexture(0,layers[0]->getTile(1));
        s->layers[0]->surface->setSpriteTexture(0,layers[0]->getTile(2));
        
        s->layers[0]->surface->affiche();
       */ 
        
    render::Surface* terrain = new render::SurfaceSFML();
    terrain->loadTexture("res/Textures/textures.png");
    
    render::Layer* test = new render::Layer();
    test->setSurface(terrain);
    state::ElementList* list;
    for(int i=0; i<list->size(); i++)
        {   
            state::Element* e = list->get(i);
            render::Tile* t = new render::Tile(e->getX(),e->getY());
            switch(e->getTypeId()){
                    case 1: //obstacle
                        switch(e->getObstacleType()){//if a la place
                                case state::sand:
                                    break;
                                case state::ObstacleTypeId::greenery:
                                    break;
                        }
                        case 2://space
                            break;
                            case 3://tank
                                break;
                                case 4://missile
                                    break;
                                    case 5://shell
                                        break;
            }
                                            
        }
    render::Scene* s = new render::Scene();
    s->setLayer(0, test);
    
        
        
        
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
