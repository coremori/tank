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
#include <bits/stl_vector.h>
#include "render/SurfaceSFML.hpp"
#include <vector>

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

void piloteSFML::affiche(){//ouvre la fenetre et affiche les sprites (boucle jusqu'à fermeture de la fenetre)
    //! mutex non mis !
    
    scene->update();
    
    sf::RenderWindow window(sf::VideoMode(scene->getWidth(), scene->getHeight()), "Rendu");// fenetre d'affichage
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(unsigned int i=0; i<surfaces.size(); i++)
            window.draw(*surfaces[i]);        
        window.display();
    }
}
