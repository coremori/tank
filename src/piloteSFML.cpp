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
    for(int i=0; i<scene->getLayerCount(); i++)
    {
        surfaces.push_back(new SurfaceSFML());
        surfaces[i]->loadTexture("res/Textures/textures.png");
        scene->setSurface(i,surfaces[i]);
    }
    m_button.clear();
    m_button.setPrimitiveType(sf::Quads);
    
    if (!font.loadFromFile("res/Font/arial.ttf"))
    {
        
    }
    engine = nullptr;
}

piloteSFML::~piloteSFML() {
}

void piloteSFML::setEngine(engine::Engine* e) {
    this->engine = e;
}


void piloteSFML::button(unsigned int x1, unsigned int x2, sf::Color color, std::string textButton) {
    //Draw the button (doesn't implemante)
    int h = scene->getHeight();
    //int w = scene->getWidth();
    int size = m_button.getVertexCount();
    m_button.setPrimitiveType(sf::Quads);
    m_button.resize(size+4);
    
    // on récupère un pointeur vers le quad à définir dans le tableau de vertex
    sf::Vertex* quad = &m_button[size];
                
    // on définit ses quatre coins
    quad[0].position = sf::Vector2f(x1, h*8+8);
    quad[1].position = sf::Vector2f(x2, h*8+8);
    quad[2].position = sf::Vector2f(x2, h*8+32);
    quad[3].position = sf::Vector2f(x1, h*8+32);

    // on définit ses quatre coordonnées de texture
    quad[0].color = color;
    quad[1].color = color;
    quad[2].color = color;
    quad[3].color = color;
    
    int centre = (x2-x1-textButton.size()*6)/2;//on centre le texte
    int ts = text.size();
    text.push_back(new sf::Text());
    text[ts]->setFont(font); // font est un sf::Font
    // choix de la chaîne de caractères à afficher
    text[ts]->setString(textButton);
    // choix de la taille des caractères
    text[ts]->setCharacterSize(12); // exprimée en pixels, pas en points !
    // choix de la couleur du texte
    text[ts]->setColor(sf::Color::Black);
    text[ts]->setPosition(sf::Vector2f(x1+centre,h*8+12));
    // choix du style du texte
    //text[0]->setStyle(sf::Text::Bold | sf::Text::Underlined);
}



void piloteSFML::affiche(){//ouvre la fenetre et affiche les sprites (boucle jusqu'à fermeture de la fenetre)
    //! mutex non mis !
    scene->update();
    int h = scene->getHeight();
    int w = scene->getWidth();
    
    sf::RenderWindow window(sf::VideoMode(w*8, h*8 + 40), "Rendu");// fenetre d'affichage, on rajoute deux ligne en bas
    sf::Music music;
    if (!music.openFromFile("res/Sounds/GameMusic/music_game.ogg"))
        std::cout << "file not found "<<std::endl;
    music.play();
    
    button(0,96,sf::Color(73,135,229),"Play/Pause");
    button(w*8-100,w*8-4,sf::Color(73,135,229),"Level 1");
    button((w*8-120)/2,(w*8+120)/2,sf::Color(212,135,0),"End the turn");

    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                music.stop();
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;                    
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                }
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // le bouton gauche est enfoncé : on tire
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if((localPosition.x<96) && (localPosition.y>h*8)&&(localPosition.y<(h*8+16)))
                    engine->addCommand(new engine::ModeCommand(engine::pause));
                        std::cout << "Button mode pressed" << std::endl;    
                std::cout << localPosition.x << std::endl;     
            }
        }
        
            
        
        window.clear();
        for(unsigned int i=0; i<surfaces.size(); i++)
            window.draw(*surfaces[i]);
        
        
        window.draw(m_button);
        for(unsigned int j=0; j<text.size(); j++)
            window.draw(*text[j]);
        window.display();
        
    }
}

