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
    
}

piloteSFML::~piloteSFML() {
}

void piloteSFML::button() {
    int h = scene->getHeight();
    int w = scene->getWidth();
    int nbButton = 2;
m_button.clear();
    m_button.setPrimitiveType(sf::Quads);
    m_button.resize(nbButton*4);
    
    // on récupère un pointeur vers le quad à définir dans le tableau de vertex
    sf::Vertex* quad = &m_button[1 * 4];
                
    // on définit ses quatre coins
    quad[0].position = sf::Vector2f(0, h*8);
    quad[1].position = sf::Vector2f(96, h*8);
    quad[2].position = sf::Vector2f(96, h*8+16);
    quad[3].position = sf::Vector2f(0, h*8+16);

    // on définit ses quatre coordonnées de texture
    quad[0].color = sf::Color(73,135,229);
    quad[1].color = sf::Color(73,135,229);
    quad[2].color = sf::Color(73,135,229);
    quad[3].color = sf::Color(73,135,229);
    
    sf::Font font;
    if (!font.loadFromFile("res/Font/arial.ttf"))
    {
        // erreur...
    }
    
    
    sf::Text text;   
    text.setFont(font); // font est un sf::Font
    // choix de la chaîne de caractères à afficher
    text.setString("Play/Pause");
    // choix de la taille des caractères
    text.setCharacterSize(12); // exprimée en pixels, pas en points !
    // choix de la couleur du texte
    text.setColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(16,h*8));
    // choix du style du texte
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}


void piloteSFML::affiche(){//ouvre la fenetre et affiche les sprites (boucle jusqu'à fermeture de la fenetre)
    //! mutex non mis !
    int nbButton = 2;
    scene->update();
    int h = scene->getHeight();
    int w = scene->getWidth();
    
    sf::RenderWindow window(sf::VideoMode(w*8, h*8 + 32), "Rendu");// fenetre d'affichage, on rajoute deux ligne en bas
    sf::Music music;
    if (!music.openFromFile("res/Sounds/GameMusic/music_game.ogg"))
        std::cout << "file not found "<<std::endl;
    music.play();
    
    
    
    
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
                        std::cout << "Button pressed" << std::endl;     
            }
        }
        
            
        
        window.clear();
        for(unsigned int i=0; i<surfaces.size(); i++)
            window.draw(*surfaces[i]);
        
        
        window.draw(m_button);
        window.draw(text);
        window.display();
        
    }
}

