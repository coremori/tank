/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   piloteSFML.cpp
 * Author: corentin
 * 
 * Created on October 18, 2016, 1:26 PM
 */

#include "piloteSFML.hpp"
#include "render/Tile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stl_vector.h>
#include "render/SurfaceSFML.hpp"
#include <vector>
#include <iostream>

#include "engine.h"



piloteSFML::piloteSFML(render::Scene* s) {//met la scene à afficher et attribue au layer les surfaces
    this->scene = s;
    surfaces.push_back(new SurfaceSFML());
    surfaces[0]->loadTexture("res/Textures/button.png"); // surface pour les boutons sans hover
    
    for(int i=0; i<scene->getLayerCount(); i++)
    {
        surfaces.push_back(new SurfaceSFML());
        surfaces[i+1]->loadTexture("res/Textures/textures.png");
        scene->setSurface(i,surfaces[i+1]);
    }
   
    
    
    engine = nullptr;
    
    if (!m_tilesetButton.loadFromFile("res/Textures/button.png")) 
        {
            //error
        }
    m_tilesetButton.setSmooth(true);
    
}

piloteSFML::~piloteSFML() {
}

void piloteSFML::setEngine(engine::Engine* e) {
    this->engine = e;
}



void piloteSFML::button(unsigned int x1, unsigned int xTex, unsigned int width, bool SpriteOrVertex, int TypeSprite) {//SpriteOrVertex == true : sprite
    //TypeSprite : 0 -> non selectionner, 1-> selectionner
    int h = scene->getHeight();
    if(SpriteOrVertex)
    {
        int s = s_button.size();
        s_button.push_back(new sf::Sprite());
        s_button[s]->setTexture(m_tilesetButton);
        s_button[s]->setTextureRect(sf::IntRect(xTex, xTex+TypeSprite*23, width, 23));
        s_button[s]->setPosition(x1,h*8+8);
    }
    else
    {
        surfaces[0]->setSpriteButton(x1, h*8+8, xTex, width);
    }
}


void piloteSFML::affiche(){//ouvre la fenetre et affiche les sprites (boucle jusqu'à fermeture de la fenetre)
    //! mutex non mis !
    scene->update();
    int Pixel_def = 8;
    int h = scene->getHeight()*Pixel_def;
    int w = scene->getWidth()*Pixel_def;
    
    
    
    sf::RenderWindow window(sf::VideoMode(w, h + 40), "Rendu");// fenetre d'affichage, on rajoute deux ligne en bas
    sf::Music music;
    if (!music.openFromFile("res/Sounds/GameMusic/music_game.ogg"))
        std::cout << "file not found "<<std::endl;
    music.play();
    
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
    //
    
    
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
            if (event.type == sf::Event::Closed)
            {
                music.stop();
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
                    engine->endTurn();
                    scene->update();
                }
                else if (rectLevel1->contains(localPosition))
                {
                    std::cout << "Button level1 pressed" << std::endl;
                    engine->addCommand(new engine::LoadCommand("res/Levels/level1.txt"));
                    scene->update();
                }
                else if (rectLevel2->contains(localPosition))
                {
                    std::cout << "Button level2 pressed" << std::endl;
                    engine->addCommand(new engine::LoadCommand("res/Levels/level2.txt"));
                    scene->update();
                }
                // le bouton gauche est enfoncé : on tire
                    //engine->addCommand(new engine::ModeCommand(engine::pause));
                        //std::cout << "Button mode pressed" << std::endl;    }
            }
        }
        
                

        
        window.clear();
        for(unsigned int i=0; i<surfaces.size(); i++)
            window.draw(*surfaces[i]);
        
        if(hover)
            window.draw(*s_button[1]);
        else
            window.draw(*s_button[0]);
        
        
        
        window.display();
        
    }
}

