#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "render.h"
#include "state/Element.h"
#include "state/ElementList.h"
#include "state/Obstacle.h"
#include "render/SurfaceSFML.hpp"

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML


using namespace std;
using namespace state;
using namespace render;

int main(int argc,char* argv[]) 
{
    
       
    /*
    render::Surface* terrain = new render::SurfaceSFML();
    terrain->loadTexture("res/Textures/textures.png");
        
    
    
    render::Layer* test = new render::Layer();
    test->setSurface(terrain);
    
    std::vector<state::Element*> list;
    list[1] = new state::Obstacle(1);
    
    list[2] = new state::Obstacle(2);
    
    list[3] = new state::Obstacle(1);
    
    
    for(int i=0; i<list->size(); i++)
        {   
            state::Element* e = list->get(i);
            render::Tile* t = new render::Tile(e->getX(),e->getY());
            switch(e->getTypeId()){
                    case 1: //obstacle
                        switch(e->getObstacleType()){//if a la place
                                case sand
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
    s->setLayer(0, test);*/
    
   SurfaceSFML* s = new SurfaceSFML();
   s->loadTexture("res/Textures/textures.png");
   
   std::vector<Tile*> tile;
   tile.push_back( new Tile(0,0,8,8));
   tile[0]->setXTex(0);
   tile[0]->setYTex(88);
   s->setSprite(tile);
          
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
        for(int i=0; i<1; i++)
        {
            std::vector<sf::Sprite*> li = s->getSprites();
            sf::Sprite sprite = *li[i];
            window.draw(sprite);
        }
        
        
        window.display();
    }
    
    
    
    return 0;
}
