/* 
 * File:   piloteSFML.cpp
 * Author: corentin
 * 
 * Created on October 18, 2016, 1:26 PM
 */

#include "PiloteSFML.h"
#include "render/Tile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stl_vector.h>
#include "render/SurfaceSFML.hpp"
#include <vector>
#include <iostream>

#include "engine.h"
#include "render/LandscapeLayer.h"
#include "render/MobileLayer.h"
#include "render/CharLayer.h"

#include "state/State.h"

#include <thread>
#include "Pilote.h"

namespace client{

    
    
    PiloteSFML::PiloteSFML(state::State* state, engine::Engine* e, int character, Pilote* pilote):
        pilote(pilote),
        character(character)
    {
        /* Set  the scene to display
         * Create the layer and register then to the state
         * Create the Surface
         * */
        this->scene = *(new render::Scene());
        obs.push_back(&scene);
       
        render::LandscapeLayer* landlayer(new render::LandscapeLayer());
        obs.push_back(landlayer);
        render::MobileLayer* mobilelayer(new render::MobileLayer());
        obs.push_back(mobilelayer);
        render::CharLayer* charlayer(new render::CharLayer());
        obs.push_back(charlayer);

        scene.setLayer(0,landlayer);
        scene.setLayer(1,mobilelayer);
        scene.setLayer(2,charlayer);

        state->getGrid().registerObserver(landlayer);
        state->getMobiles().registerObserver(mobilelayer);
        state->getMobiles().registerObserver(charlayer);
        state->registerObserver(&scene);

        surfaces.push_back(new SurfaceSFML());
        surfaces[0]->loadTexture("res/Textures/button.png"); // surface pour la victoire
        surfaces.push_back(new SurfaceSFML());
        surfaces[1]->loadTexture("res/Textures/button.png"); // surface pour la  defaite
        
        for(int i=0; i<scene.getLayerCount(); i++)
        {
            surfaces.push_back(new SurfaceSFML());
            surfaces[i+2]->loadTexture("res/Textures/textures.png");
            scene.setSurface(i,surfaces[i+2]);
        }

        engine = e;
    }






    PiloteSFML::~PiloteSFML() {}
    
    
    
    
    
    void PiloteSFML::createMenu() {
        /* create the window and the button
         * The state must be initialized before using this function
         * */
        applyChange();
        int Pixel_def = 8;
        int h = scene.getHeight()*Pixel_def;
        int w = scene.getWidth()*Pixel_def;   

        window.create(sf::VideoMode(w, h + 40), "Rendu");
        // message victoire
        surfaces[0]->setSpriteButton(408, 24, 624, 385);//paramètre : xPos, yPos, xTex, width texture
        //// message defaite    
        surfaces[1]->setSpriteButton(409, 24,240, 382);
        
        //button "fin de tour"
        /* Dans l'ordre : emplacement texture, commande à exécuter, position xTex, largeur de l'image, hauteur de l'image
         * présence d'un deuxième sprite lorsqu'on passe la souris dessus, position x dans l'écran, position y dans l'écran
         */
        button.push_back(*(new Button("res/Textures/button.png", new engine::EndTurnCommand(this->character),0,104,23,true, (w-104)/2,h+8)));  

        //button "level 1"
        button.push_back(*(new Button("res/Textures/button.png", new engine::LoadCommand("res/Levels/level1.txt"),104,69,23,true, w-148,h+8)));

        //button "level 2"
        button.push_back(*(new Button("res/Textures/button.png", new engine::LoadCommand("res/Levels/level2.txt"),173,69,23,true, w-74,h+8)));
        
        //button "AI"
        button.push_back(*(new Button("res/Textures/button.png", new engine::ModeCommand(engine::AI),1010,74,23,true, w-232,h+8)));
   
    }
    









    void PiloteSFML::applyChange() {
        /* Update the display if the state had changed
         */
        if (engine->getUpdateMutex().try_lock()) {
                for(unsigned int i = 0; i<obs.size(); i++)
                    obs[i]->applyStateChanged();
                    engine->getUpdateMutex().unlock();
        }
        engine->setAnimRunning(scene.update());
    };

    
    
    
    
    void PiloteSFML::eventUp() {
        /* Check if a key or a button was pressed
         */
        sf::Event event;
        sf::Vector2i localPosition2;
        localPosition2 = sf::Mouse::getPosition(window);
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                /* Window Closing 
                 * Set the mode to engine::Close for stopping the engine thread
                 */
               engine->setMode(engine::close);
               window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                //pas d'agrandissement quand on agrandit la fenêtre
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code){
                    case sf::Keyboard::P :
                        pilote->addCommand(new engine::ModeCommand(engine::AI));
                        break;
                    case sf::Keyboard::Escape :
                        pilote->addCommand(new engine::ModeCommand(engine::replay));
                        break;

                    case sf::Keyboard::Right :
                        pilote->addCommand(new engine::MoveCommand(this->character,8,0));
                        break;

                    case sf::Keyboard::Left :
                        pilote->addCommand(new engine::MoveCommand(this->character,-8,0));
                        break;

                    case sf::Keyboard::E :
                        pilote->addCommand(new engine::DirectionCommand(this->character,state::right_up));
                        break;

                    case sf::Keyboard::Z :
                        pilote->addCommand(new engine::DirectionCommand(this->character,state::left_up));
                        break;

                    case sf::Keyboard::Q :
                        pilote->addCommand(new engine::DirectionCommand(this->character,state::left_down));
                        break;

                    case sf::Keyboard::D :
                        pilote->addCommand(new engine::DirectionCommand(this->character,state::right_down));
                        break;

                    case sf::Keyboard::Space :
                        pilote->addCommand(new engine::ShotCommand(this->character,10));
                        break;

                    default : break;
                }

            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                /* Check the buttons
                 */
                for(unsigned int i=0; i<button.size(); i++)
                    button[i].press(localPosition2,pilote);
            }
        }
    } 





    void PiloteSFML::display(){
        /* Draw the display depending on the mode
         */

        sf::Vector2i localPosition;
        localPosition = sf::Mouse::getPosition(window);

        window.clear();
        for(unsigned int i=2; i<surfaces.size(); i++)
            window.draw(*surfaces[i]);

        /* Draw the button*/
        for(unsigned int i=0; i<button.size(); i++)
            button[i].draw(&window,localPosition);

        switch(engine->getMode()){
            case engine::Finish:
                if(engine->getCharTurn() == character)
                    window.draw(*surfaces[1]);//Lost
                else
                    window.draw(*surfaces[0]);//win
                break;

            default :
                break;
        }

        window.display();
    }

}
    

    