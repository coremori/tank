/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   piloteSFML.hpp
 * Author: corentin
 *
 * Created on October 18, 2016, 1:26 PM
 */

#ifndef PILOTESFML_HPP
#define PILOTESFML_HPP

#include "render/Scene.h"
#include <vector>
#include "render/SurfaceSFML.hpp"
#include <SFML/Graphics.hpp>
#include <string.h>
#include "engine/Engine.h"

class piloteSFML {
public:
    
    
    
    piloteSFML(render::Scene* s);
    virtual ~piloteSFML();
    void affiche();
    void setEngine(engine::Engine* e);
    
private:
    render::Scene* scene;
    std::vector<SurfaceSFML*> surfaces;
    std::vector<sf::Sprite*> s_button;
    engine::Engine* engine;
    sf::Texture m_tilesetButton;
    

    void button(unsigned int x1, unsigned int xTex, unsigned int width, bool SpriteOrVertex, int numSprite = 0);
};

#endif /* PILOTESFML_HPP */

