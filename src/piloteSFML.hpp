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
    sf::VertexArray m_button;
    sf::Font font;
    std::vector<sf::Text*> text;
    engine::Engine* engine;
    void button(unsigned int x1, unsigned int x2, sf::Color color, std::string textButton);
};

#endif /* PILOTESFML_HPP */

