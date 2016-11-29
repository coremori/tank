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

namespace client{

    
    
    PiloteSFML::PiloteSFML(state::State* state, engine::Engine* e) {//met la scene à afficher et attribue au layer les surfaces
        character = 0;
        //state = s;
        this->scene = *(new render::Scene());
        obs.push_back(&scene);
        obs.push_back(new render::LandscapeLayer());
        obs.push_back(new render::MobileLayer());
        obs.push_back(new render::CharLayer());

        render::LandscapeLayer* landlayer = dynamic_cast<render::LandscapeLayer*>(obs[1]);
        render::MobileLayer* mobilelayer = dynamic_cast<render::MobileLayer*>(obs[2]);
        render::CharLayer* charlayer = dynamic_cast<render::CharLayer*>(obs[3]);

        scene.setLayer(0,landlayer);
        scene.setLayer(1,mobilelayer);
        scene.setLayer(2,charlayer);


        state->getGrid().registerObserver(obs[1]);
        state->getMobiles().registerObserver(obs[2]);
        state->getMobiles().registerObserver(obs[3]);
        state->registerObserver(obs[0]);

        surfaces.push_back(new SurfaceSFML());
        surfaces[0]->loadTexture("res/Textures/button.png"); // surface pour le mode victory
        surfaces.push_back(new SurfaceSFML());
        surfaces[1]->loadTexture("res/Textures/button.png"); // surface pour le mode defaite
        
        for(int i=0; i<scene.getLayerCount(); i++)
        {
            surfaces.push_back(new SurfaceSFML());
            surfaces[i+2]->loadTexture("res/Textures/textures.png");
            scene.setSurface(i,surfaces[i+2]);
        }

        engine = e;

        
        
        //m_tilesetButton.setSmooth(true); //lissage de l'image
        
        state->load("res/Levels/level1.txt"); //charge le level, pour être sur qu'il existe

    }






    PiloteSFML::~PiloteSFML() {}
    
    
    
    
    
    void PiloteSFML::createMenu() {
        //create the window and the button
        applyChange();
        int Pixel_def = 8;
        int h = scene.getHeight()*Pixel_def;
        int w = scene.getWidth()*Pixel_def;   

        window.create(sf::VideoMode(w, h + 40), "Rendu");
        // message victoir3
        surfaces[0]->setSpriteButton(408, 24, 624, 385);//paramètre : xPos, yPos, xTex, width texture
        //// message defaite    
        surfaces[1]->setSpriteButton(409, 24,240, 382);
        
        //button "fin de tour"
        /* Dans l'ordre : emplacement texture, commande à exécuter, position xTex, largeur de l'image, hauteur de l'image
         *présence d'un deuxième sprite lorsqu'on passe la souris dessus, position x dans l'écran, position y dans l'écran*/
        button.push_back(*(new Button("res/Textures/button.png", new engine::EndTurnCommand(this->character),0,104,23,true, (w-104)/2,h+8)));  

        //button "level 1"
        button.push_back(*(new Button("res/Textures/button.png", new engine::LoadCommand("res/Levels/level1.txt"),104,69,23,true, w-148,h+8)));

        //button "level 2"
        button.push_back(*(new Button("res/Textures/button.png", new engine::LoadCommand("res/Levels/level2.txt"),173,69,23,true, w-74,h+8)));
        
        //button "AI"
        button.push_back(*(new Button("res/Textures/button.png", new engine::ModeCommand(engine::AI),1010,74,23,true, w-232,h+8)));
   
    }
    









    void PiloteSFML::applyChange() {
        if (engine->getUpdateMutex().try_lock()) {
                for(unsigned int i = 0; i<obs.size(); i++)
                    obs[i]->applyStateChanged();
                    engine->getUpdateMutex().unlock();
        }
        //scene.update();
    engine->setAnimRunning(scene.update());
    };

    
    
    
    
    void PiloteSFML::eventUp() {
        sf::Event event;
        sf::Vector2i localPosition2;
        localPosition2 = sf::Mouse::getPosition(window);
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
               engine->setMode(engine::close);
               window.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code){
                    case sf::Keyboard::P :
                        engine->addCommand(new engine::ModeCommand(engine::AI));
                        break;
                    case sf::Keyboard::Escape :
                        engine->addCommand(new engine::ModeCommand(engine::replay));
                        break;

                    case sf::Keyboard::Right :
                        engine->addCommand(new engine::MoveCommand(this->character,8,0));
                        break;

                    case sf::Keyboard::Left :
                        engine->addCommand(new engine::MoveCommand(this->character,-8,0));
                        break;

                    case sf::Keyboard::E :
                        engine->addCommand(new engine::DirectionCommand(this->character,state::right_up));
                        break;

                    case sf::Keyboard::Z :
                        engine->addCommand(new engine::DirectionCommand(this->character,state::left_up));
                        break;

                    case sf::Keyboard::Q :
                        engine->addCommand(new engine::DirectionCommand(this->character,state::left_down));
                        break;

                    case sf::Keyboard::D :
                        engine->addCommand(new engine::DirectionCommand(this->character,state::right_down));
                        break;

                    case sf::Keyboard::Space :
                        engine->addCommand(new engine::ShotCommand(this->character,10));
                        break;

                    default : break;
                }

            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                for(unsigned int i=0; i<button.size(); i++)
                    button[i].press(localPosition2,engine);
            }
        }
    } 





void PiloteSFML::display(){

    //applyChange();

   

    /*if(!window.isOpen())
    {*/
        sf::Vector2i localPosition;
        localPosition = sf::Mouse::getPosition(window);
        
        //eventUp();
            
        
        //applyChange();//actualise l'affichage

        window.clear();
        for(unsigned int i=2; i<surfaces.size(); i++)
            window.draw(*surfaces[i]);

        for(unsigned int i=0; i<button.size(); i++)
            button[i].draw(&window,localPosition);
        /*
        if(hover)
            window.draw(*s_button[1]);
        else
            window.draw(*s_button[0]);
         * */
        switch(engine->getMode()){
            case engine::Finish:
                if(engine->getCharTurn() == character)
                    window.draw(*surfaces[1]);
                else
                    window.draw(*surfaces[0]);
                break;
                
            default :
                break;
        }

        window.display();

    //}
}

}
    

    