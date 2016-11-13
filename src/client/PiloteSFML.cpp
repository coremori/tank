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

    
    
    PiloteSFML::PiloteSFML(state::State* s) {//met la scene à afficher et attribue au layer les surfaces

        state = s;
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
        surfaces[0]->loadTexture("res/Textures/button.png"); // surface pour les boutons sans hover

        for(int i=0; i<scene.getLayerCount(); i++)
        {
<<<<<<< HEAD
            surfaces.push_back(new SurfaceSFML());
            surfaces[i+1]->loadTexture("res/Textures/textures.png");
            scene.setSurface(i,surfaces[i+1]);
        }
=======
            std::cout << "ERROR : file \"res/Textures/button.png\" not found" << std::endl;            
        }
    
    m_tilesetButton.setSmooth(true);
    state->load("res/Levels/level1.txt"); //charge le level.
    
}
>>>>>>> bdf8d37c38389c61e7fc46371328d74af0d88d23

        engine = nullptr;

        if (!m_tilesetButton.loadFromFile("res/Textures/button.png")){
            std::cout << "Erreur - button.png non chargé" << std::endl;
        }

        m_tilesetButton.setSmooth(true);

         state->load("res/Levels/level1.txt"); //charge le level.

<<<<<<< HEAD
    }






    PiloteSFML::~PiloteSFML() {
    }
=======
void PiloteSFML::setEngine(engine::Engine* e) {
    this->engine = e;
}

void PiloteSFML::createMenu() {
    // message victoire
    int si = s_button.size();
        s_button.push_back(new sf::Sprite());
        s_button[si]->setTexture(m_tilesetButton);
        s_button[si]->setTextureRect(sf::IntRect(624, 0, 388, 72));
        s_button[si]->setPosition(408,24);
    //// message defaite    
        s_button.push_back(new sf::Sprite());
        s_button[si+1]->setTexture(m_tilesetButton);
        s_button[si+1]->setTextureRect(sf::IntRect(237, 0, 385, 72));//xTex, yTex, width, height
        s_button[si+1]->setPosition(409,24);      
}
>>>>>>> bdf8d37c38389c61e7fc46371328d74af0d88d23







    void PiloteSFML::setEngine(engine::Engine* e) {
        this->engine = e;
    }







    void PiloteSFML::createMenu() {
        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< test message victoire
        int si = s_button.size();
            s_button.push_back(new sf::Sprite());
            s_button[si]->setTexture(m_tilesetButton);
            s_button[si]->setTextureRect(sf::IntRect(624, 0, 388, 72));
            s_button[si]->setPosition(408,24);

            s_button.push_back(new sf::Sprite());
            s_button[si+1]->setTexture(m_tilesetButton);
            s_button[si+1]->setTextureRect(sf::IntRect(237, 0, 385, 72));
            s_button[si+1]->setPosition(409,24);

    }










    void PiloteSFML::button(unsigned int x1, unsigned int xTex, unsigned int width, bool SpriteOrVertex, int TypeSprite){//SpriteOrVertex == true : sprite
        //TypeSprite : 0 -> non selectionné, 1-> selectionné
        int h = scene.getHeight();
        if(SpriteOrVertex)
        {
            int s = s_button.size();
            s_button.push_back(new sf::Sprite());
            s_button[s]->setTexture(m_tilesetButton);
            s_button[s]->setTextureRect(sf::IntRect(xTex, TypeSprite*23, width, 23));
            s_button[s]->setPosition(x1,h*8+8);
        }
        else
        {
            surfaces[0]->setSpriteButton(x1, h*8+8, xTex, width);
        }
<<<<<<< HEAD
    };










    void PiloteSFML::applyChange() {
        if (engine->getUpdateMutex().try_lock()) {
                for(unsigned int i = 0; i<obs.size(); i++)
                    obs[i]->applyStateChanged();
                engine->getUpdateMutex().unlock();
            }
        scene.update();
    };









    void PiloteSFML::affiche(){//ouvre la fenetre et affiche les sprites (boucle jusqu'à fermeture de la fenetre)
        
        applyChange();

        int Pixel_def = 8;
        int h = scene.getHeight()*Pixel_def;
        int w = scene.getWidth()*Pixel_def;   


        sf::RenderWindow window(sf::VideoMode(w, h + 40), "Rendu");// fenetre d'affichage, on rajoute deux ligne en bas
     
     
        /*
        sf::Music music;
        if (!music.openFromFile("res/Sounds/GameMusic/music_game.ogg"))
            std::cout << "file not found "<<std::endl;
        music.play();
        */


        //button "fin de tour"
        button((w-104)/2,0,104,1,0);//bouton centré
        button((w-104)/2,0,104,1,1);
        sf::IntRect* rectEnd = new sf::IntRect((w-104)/2,h+8, 104, 23);
        bool hover = false;

        
        
        //button "level 1"
        button(w-148,104,64,0,0);
        sf::IntRect* rectLevel1 = new sf::IntRect(w-148,h+8, 64, 23);

        
        
        //button "level 2"
        button(w-74,168,64,0,0);
        sf::IntRect* rectLevel2 = new sf::IntRect(w-74,h+8, 64, 23);

        sf::Vector2i localPosition;

        createMenu();

        while (window.isOpen())
        {
            
            sf::Event event;
            localPosition = sf::Mouse::getPosition(window);

            if(rectEnd->contains(localPosition))
                hover = true;
            else
                hover = false;

            while (window.pollEvent(event))
            {
                //eventUp(event,window,engine,character,rectEnd,rectLevel1,rectLevel2,localPosition);
               

                    if (event.type == sf::Event::Closed){
                                engine->setMode(engine::close);
                                //music.stop();
                                window.close();
                    }
                    else if (event.type == sf::Event::KeyPressed)
                    {
                        switch(event.key.code){

                            case sf::Keyboard::Escape :
                                std::cout << "the escape key was pressed" << std::endl; 
                                engine->setMode(engine::pause);
                                break;

                            case sf::Keyboard::Right :
                                std::cout << "right move" << std::endl;
                                engine->addCommand(new engine::MoveCommand(character,8,0));
                                break;

                            case sf::Keyboard::Left :
                                std::cout << "left move" << std::endl;
                                engine->addCommand(new engine::MoveCommand(character,-8,0));
                                break;

                            case sf::Keyboard::E :
                                std::cout << "direction rigth up " << std::endl;
                                engine->addCommand(new engine::DirectionCommand(character,state::right_up));
                                break;

                            case sf::Keyboard::Z :
                                std::cout << "direction left up" << std::endl;
                                engine->addCommand(new engine::DirectionCommand(character,state::left_up));
                                break;

                            case sf::Keyboard::Q :
                                std::cout << "direction left down" << std::endl;
                                engine->addCommand(new engine::DirectionCommand(character,state::left_down));
                                break;

                            case sf::Keyboard::D :
                                std::cout << "direction right down" << std::endl;
                                engine->addCommand(new engine::DirectionCommand(character,state::right_down));
                                break;

                            case sf::Keyboard::Space :
                                std::cout << "shot" << std::endl;
                                engine->addCommand(new engine::ShotCommand(character,10));
                                break;

                            default : break;
                        }

                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        if(rectEnd->contains(localPosition))
                        {
                            std::cout << "Button End turn pressed" << std::endl;
                            engine->addCommand(new engine::EndTurnCommand(character));                    
                        }
                        else if (rectLevel1->contains(localPosition))
                        {
                            std::cout << "Button level1 pressed" << std::endl;
                            engine->addCommand(new engine::LoadCommand("res/Levels/level1.txt"));
                        }
                        else if (rectLevel2->contains(localPosition))
                        {
                            std::cout << "Button level2 pressed" << std::endl;
                            engine->addCommand(new engine::LoadCommand("res/Levels/level2.txt"));
                        }
                    }

                 
            }


            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            applyChange();

            window.clear();
            for(unsigned int i=0; i<surfaces.size(); i++)
                window.draw(*surfaces[i]);


            if(hover)
                window.draw(*s_button[1]);
            else
                window.draw(*s_button[0]);

            switch(engine->getMode()){
                
                case engine::victoire:
                    window.draw(*s_button[2]);
                    break;
                
                case engine::defaite:
                    window.draw(*s_button[3]);
                    break;
                
                default :
                    break;
            }

            window.display();

        }
    }
}

=======
    //scene.update();
    engine->setAnimInRun(scene.update());
    
};

void PiloteSFML::affiche(){//ouvre la fenetre et affiche les sprites (boucle jusqu'à fermeture de la fenetre)
    applyChange();
    
    int Pixel_def = 8;
    int h = scene.getHeight()*Pixel_def;
    int w = scene.getWidth()*Pixel_def;   
    
    
    sf::RenderWindow window(sf::VideoMode(w, h + 40), "Rendu");// fenetre d'affichage, on rajoute deux ligne en bas
/*    sf::Music music;
    if (!music.openFromFile("res/Sounds/GameMusic/music_game.ogg"))
        std::cout << "file not found "<<std::endl;
    music.play();
  */  
    
    
    //button "fin de tour"
    button((w-104)/2,0,104,1,0);//bouton centré
    button((w-104)/2,0,104,1,1);
    sf::IntRect* rectEnd = new sf::IntRect((w-104)/2,h+8, 104, 23);
    bool hover = false;
>>>>>>> bdf8d37c38389c61e7fc46371328d74af0d88d23
    
    
    
    
    
/*    
    void eventUp(sf::Event& event,sf::RenderWindow& window,engine::Engine* engine,int character,sf::IntRect* rectEnd,sf::IntRect* rectLevel1,sf::IntRect* rectLevel2,sf::Vector2i localPosition){
        
        if (event.type == sf::Event::Closed){
                    engine->setMode(engine::close);
                    //music.stop();
                    window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code){

                case sf::Keyboard::Escape :
                    std::cout << "the escape key was pressed" << std::endl; 
                    engine->setMode(engine::pause);
                    break;

                case sf::Keyboard::Right :
                    std::cout << "right move" << std::endl;
                    engine->addCommand(new engine::MoveCommand(character,8,0));
                    break;

                case sf::Keyboard::Left :
                    std::cout << "left move" << std::endl;
                    engine->addCommand(new engine::MoveCommand(character,-8,0));
                    break;

                case sf::Keyboard::E :
                    std::cout << "direction rigth up " << std::endl;
                    engine->addCommand(new engine::DirectionCommand(character,state::right_up));
                    break;

                case sf::Keyboard::Z :
                    std::cout << "direction left up" << std::endl;
                    engine->addCommand(new engine::DirectionCommand(character,state::left_up));
                    break;

                case sf::Keyboard::Q :
                    std::cout << "direction left down" << std::endl;
                    engine->addCommand(new engine::DirectionCommand(character,state::left_down));
                    break;

                case sf::Keyboard::D :
                    std::cout << "direction right down" << std::endl;
                    engine->addCommand(new engine::DirectionCommand(character,state::right_down));
                    break;

                case sf::Keyboard::Space :
                    std::cout << "shot" << std::endl;
                    engine->addCommand(new engine::ShotCommand(character,10));
                    break;

                default : break;
            }

        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(rectEnd->contains(localPosition))
            {
                std::cout << "Button End turn pressed" << std::endl;
                engine->addCommand(new engine::EndTurnCommand(character));                    
            }
            else if (rectLevel1->contains(localPosition))
            {
<<<<<<< HEAD
                std::cout << "Button level1 pressed" << std::endl;
                engine->addCommand(new engine::LoadCommand("res/Levels/level1.txt"));
=======
                switch(event.key.code){
                    case sf::Keyboard::Escape :
                        std::cout << "the escape key was pressed" << std::endl; 
                        engine->addCommand(new engine::ModeCommand(engine::replay));
                        break;
                    case sf::Keyboard::Right :
                        engine->addCommand(new engine::MoveCommand(character,8,0));
                        break;
                    case sf::Keyboard::Left :
                        engine->addCommand(new engine::MoveCommand(character,-8,0));
                        break;
                    case sf::Keyboard::E :
                        std::cout << "direction rigth up " << std::endl;
                        engine->addCommand(new engine::DirectionCommand(character,state::right_up));
                        break;
                    case sf::Keyboard::Z :
                        std::cout << "direction left up" << std::endl;
                        engine->addCommand(new engine::DirectionCommand(character,state::left_up));
                        break;
                    case sf::Keyboard::Q :
                        engine->addCommand(new engine::DirectionCommand(character,state::left_down));
                        break;
                    case sf::Keyboard::D :
                        engine->addCommand(new engine::DirectionCommand(character,state::right_down));
                        break;
                    case sf::Keyboard::Space :
                        engine->addCommand(new engine::ShotCommand(character,10));
                        break;
                    default : break;
                }
                
>>>>>>> bdf8d37c38389c61e7fc46371328d74af0d88d23
            }
            else if (rectLevel2->contains(localPosition))
            {
<<<<<<< HEAD
                std::cout << "Button level2 pressed" << std::endl;
                engine->addCommand(new engine::LoadCommand("res/Levels/level2.txt"));
            }
        }
        
    } 
  */  
=======
                if(rectEnd->contains(localPosition))
                {
                    engine->addCommand(new engine::EndTurnCommand(character));                    
                }
                else if (rectLevel1->contains(localPosition))
                {
                    engine->addCommand(new engine::LoadCommand("res/Levels/level1.txt"));
                }
                else if (rectLevel2->contains(localPosition))
                {
                    engine->addCommand(new engine::LoadCommand("res/Levels/level2.txt"));
                }
            }
        }
        
                
        std::this_thread::sleep_for(std::chrono::milliseconds(50));//sleep for 50ms+
        applyChange();
        
        window.clear();
        for(unsigned int i=0; i<surfaces.size(); i++)//dessin background, mobile et pv + button à affichage simple
            window.draw(*surfaces[i]);
        
              
        if(hover)//pour le endTurn qui change de couleur
            window.draw(*s_button[1]);
        else
            window.draw(*s_button[0]);
        
        switch(engine->getMode()){//pour la victoire//défaite
            case engine::victoire:
                window.draw(*s_button[2]);
                break;
            case engine::defaite:
                window.draw(*s_button[3]);
                break;
            default :
                break;
        }
        
        window.display();
        
    }
}

}
>>>>>>> bdf8d37c38389c61e7fc46371328d74af0d88d23
