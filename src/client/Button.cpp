/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on November 17, 2016, 3:35 PM
 *
 * Part of tank */


#include <iostream>

#include "Button.h"

namespace client{
    


    Button::Button(const char* image_file, engine::Command* command, unsigned int xTex, unsigned int widthButton, unsigned int heightButton, bool Hoover, unsigned int xPos, unsigned int yPos) {
        /* Dans l'ordre : 
         * image_file : emplacement texture
         * command : commande à exécuter lors d'un appuie
         * xTex: position xTex
         * widthButton : largeur de l'image/sprite
         * heightButton :  hauteur de l'image/sprite
         * Hoover : présence d'un deuxième sprite lorsqu'on passe la souris dessus ?
         * xPos : position x dans l'écran
         * yPos : position y dans l'écran*/
        
        this->command = command;//stockage de la commande a effectue en cas d'appuie
        
        if (!m_tilesetButton.loadFromFile(image_file))//chargement de la texture
            std::cout << "Erreur - button.png non chargé" << std::endl;
       
        s_button.push_back(new sf::Sprite());
        s_button[0]->setTexture(m_tilesetButton);
        s_button[0]->setTextureRect(sf::IntRect(xTex, 0, widthButton, heightButton));
        s_button[0]->setPosition(xPos,yPos);
        if(Hoover){// on a une texture pour le passage sur le boutton
            s_button.push_back(new sf::Sprite());
            s_button[1]->setTexture(m_tilesetButton);
            s_button[1]->setTextureRect(sf::IntRect(xTex, heightButton, widthButton, heightButton));//on suppose qu'ils sont alligné verticalement
            s_button[1]->setPosition(xPos,yPos); 
        }
        this->frame = new sf::IntRect(xPos,yPos,widthButton,heightButton);//on enregistre la zone de réaction du boutton
    }
        
    

    
    
    
    void Button::draw(sf::RenderWindow* window, sf::Vector2i localPosition) const {
        /* draw the button
         */
        if(frame->contains(localPosition))
        {
            if(s_button.size()>1)// si on a une texture pour le passage sur le boutton
                window->draw(*s_button[1]);
            else
                window->draw(*s_button[0]);
        }
        else
            window->draw(*s_button[0]);
    }
    
    void Button::press(sf::Vector2i localPosition, engine::Engine* engine) const {
        /* Launch the command if we are on the button
         */
        if(frame->contains(localPosition))
            {
                engine->addCommand(command);                    
            }
    }

}