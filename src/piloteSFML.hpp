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
    
    
    
    piloteSFML(state::State* s);
    virtual ~piloteSFML();
    void affiche();
    void setEngine(engine::Engine* e);
    
private:
    state::State* state;
    render::Scene* scene;
    std::vector<cache::CacheStateObserver*> obs;
    std::vector<SurfaceSFML*> surfaces;
    std::vector<sf::Sprite*> s_button;
    engine::Engine* engine;
    sf::Texture m_tilesetButton;
    int character = 0;

    void button(unsigned int x1, unsigned int xTex, unsigned int width, bool SpriteOrVertex, int numSprite = 0);
    void applyChange();
};

#endif /* PILOTESFML_HPP */

