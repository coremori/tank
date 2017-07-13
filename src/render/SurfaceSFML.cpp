#include <vector>
#include <assert.h> 

#include "state/ElementMobile.h"
#include "state/ElementLiving.h"

#include "trace.h"

#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <bits/stl_vector.h>
#include "SurfaceSFML.hpp"
#include <iostream>


#define STD_HEIGHT 8
#define STD_WIDTH 8
   ///////////////////////////////////////////////////////////////////////
   /// \fn updateElementGraphic
   /// \brief change the texture 
   /// \param elementDisplay : ElementGraphic we want to display
   /// \return void
   /////////////////////////////////////////////////////////////////////////   
void SurfaceSFML::updateElementGraphic(ElementGraphic* elementDisplay, int newPositionX = -1, int newPositionY = -1)
{

	int numSprite (elementDisplay->p_spriteNumber);

	// Check the validity of numSprite
	if ((numSprite < 0) || (numSprite > m_vertices.getVertexCount()/4))
	return;



    unsigned int width ( elementDisplay->getWidth() );
    unsigned int height ( elementDisplay->getHeight() );

    int textureX ( elementDisplay->getTextureX() + width * elementDisplay->getOrientation_serie() );
    int textureY ( elementDisplay->getTextureY() );


    // We get the pointer to the quad 
    sf::Vertex* quad = &m_vertices[numSprite * 4];
    
    // We define his new texture coordinate
    quad[0].texCoords = sf::Vector2f(textureX, textureY);
    quad[1].texCoords = sf::Vector2f(textureX + width, textureY);
    quad[2].texCoords = sf::Vector2f(textureX + width, textureY + height);
    quad[3].texCoords = sf::Vector2f(textureX, textureY + height);    


	//We update the coordinate
    if ( (newPositionX != -1) && (newPositionY != -1))
	{
	    quad[0].position = sf::Vector2f(x, y);
	    quad[1].position = sf::Vector2f(x + width, y);
	    quad[2].position = sf::Vector2f(x + width, y + height);
	    quad[3].position = sf::Vector2f(x, y + height);
	}
   

//We update the childreen
    for(int i = 0; i < elementDisplay->getNumberSubGraphic(); i++)
    {
    	this->updateElementGraphic(elementDisplay->getSubGraphic(i), newPositionX, newPositionY);
    }

}    


	///////////////////////////////////////////////////////////////////////
	/// \fn newSprite
	/// \brief create a new sprite
	/// \param elementToDisplay : ElementBase* we want to display
	/// \param x : Element position x, if -1 then elementToDisplay is assumed being a ElementMobile and x is get from it
	/// \param y : Element position y, if -1 then elementToDisplay is assumed being a ElementMobile and y is get from it
	/// \return void
	/////////////////////////////////////////////////////////////////////////   
void SurfaceSFML::newSprite( ElementBase* elementToDisplay, int x, int y)
{
	if ((x == -1) && (y = -1))
	{
		ElementLiving* cast = dynamic_cast<ElementLiving*>(elementToDisplay);
		x = cast->getX;
		y = cast->getY;
	}

	//We create a new quad vertex
	m_vertices.resize(m_vertices.getVertexCount()+4);
       
    ElementGraphic* elementToDisplayGraphic = elementToDisplay->getGraphic();

	elementToDisplayGraphic->p_spriteNumber = m_vertices.getVertexCount();

	//On update l'affichage
    this->updateElementGraphic(elementToDisplayGraphic, x, y);
}



	///////////////////////////////////////////////////////////////////////
	/// \fn newSpriteList
	/// \brief create a new sprite for each element in listOfElementToDisplay
	/// \param listOfElementToDisplay : elements we want to display
	/// \param sizeLine : number of element by line
	/// \return void
	/////////////////////////////////////////////////////////////////////////   
void SurfaceSFML::newSpriteList (std::vector<ElementBase*> listOfElementToDisplay, int sizeLine)
{
	//We clear the last sprite
	this->clear();

	for (int i = 0; i < listOfElementToDisplay.size(); i++)
	{
		this->newSprite(listOfElementToDisplay[i], (i % sizeLine) * STD_WIDTH, (i / sizeLine) * STD_HEIGHT);
	}
}




  ///////////////////////////////////////////////////////////////////////
  /// \fn textToSprite
  /// \brief Display a text on a sprite
  /// \param text : text we want to display
  /// \param textNumber : numero of the previous text (for update this sprite)
  /// \param positionX : text position x (-1 for no change)
  /// \param positionY : text position y (-1 for no change)
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void SurfaceSFML::textToSprite (std::string text, int textNumber = -1, int positionX = -1, int positionY =-1)
  {
    //We chek if a police was loaded
    if (f_Font == nullptr)
        return;


    sf::Text* newText ;

   
    if (textNumber < 0)
    {
         //We create a new text variable
        newText = new sf:Text(text, f_Font);
        f_AllText.pushback(newText);
    }
    else
    {
        newText = f_AllText[textNumber];

            // select the font
        newText->setFont(f_Font); // font is a sf::Font

        // set the string to display
        newText->setString(text);

        // set the character size
        newText->setCharacterSize(24); // in pixels, not points!
    }

  
    // set the color
    newText->setFillColor(sf::Color::Black);

    if ( (positionX != -1) && (positionY != -1) )
        newText->setPosition( (float) x, (float) y);   

    /*// set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);*/


/*    // inside the main loop, between window.clear() and window.display()
    window.draw(text);*/

  }

  ///////////////////////////////////////////////////////////////////////
  /// \fn loadFont
  /// \brief load the font who will be used to display the text
  /// \param font_file : the font to use
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
  void SurfaceSFML::loadFont( const char* font_file)
  {
    if (!f_Font.loadFromFile(font_file))
    {
        TRACE("Can not open file %s", font_file);
    }
  }


  ///////////////////////////////////////////////////////////////////////
  /// \fn loadTexture
  /// \brief load the texture who will be used to display the sprite
  /// \param image_file : the texture to use
  /// \return void
  /////////////////////////////////////////////////////////////////////////   
void SurfaceSFML::loadTexture (const char* image_file)
{   //basic: "res/Textures/textures.png"
    
    if (!m_tileset.loadFromFile(image_file)) 
    {
        TRACE("Can not open file %s", image_file);
    }
    
};
    
       
    
    
    
    void SurfaceSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);

        //we draw the text
        foreach (sf::Text* text = f_AllText)
            target.draw(&text);
    }
    
    
    
    
    
    
    void SurfaceSFML::clear (){
        m_vertices.clear();
    };
    
    
    
  
    
    
    
    void SurfaceSFML::setSprite (const std::vector<render::Tile> tiles){//NOT DONE!!
        // on charge la texture du tileset
        
        
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.clear();
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(tiles.size()*4);
        
        
        // on remplit le tableau de vertex, avec un quad par tuile
            for (unsigned int j = 0; j < tiles.size(); ++j)
            {
                // on récupère le numéro de tuile courant

                // on en déduit sa position dans la texture du tileset
                int tu = tiles[j].getXTex();//position dans la texture
                int tv = tiles[j].getYTex();
                
                unsigned int w = tiles[j].getWidth();//width d'un affichage
                unsigned int h = tiles[j].getHeight();
                
                unsigned int x = tiles[j].getX();//position dans l'image
                unsigned int y = tiles[j].getY();

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[j * 4];
                
                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(x,y);
                quad[1].position = sf::Vector2f(x+w, y);
                quad[2].position = sf::Vector2f(x+w, y+h);
                quad[3].position = sf::Vector2f(x, y+h);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu, tv);
                quad[1].texCoords = sf::Vector2f(tu + w, tv);
                quad[2].texCoords = sf::Vector2f(tu + w, tv +h);
                quad[3].texCoords = sf::Vector2f(tu, tv +h);
            }
        
    
    };
    
    
    
    
    
    
    void SurfaceSFML::setSpriteNum(int idx, render::Tile tile) {
        
        if(idx<0)
            return;
        
        unsigned int maxi = idx;
        
        if(maxi==(m_vertices.getVertexCount()/4))//si idx > size ou idx<0 (comparaison signed/unsigned avantageuse ici)
        {
            m_vertices.resize(m_vertices.getVertexCount()+4);
        }
        else if(maxi>(m_vertices.getVertexCount()/4))
            return;
                
        int tu = tile.getXTex();//position dans la texture
                int tv = tile.getYTex();
                
                unsigned int w = tile.getWidth();//width d'un affichage
                unsigned int h = tile.getHeight();
                
                unsigned int x = tile.getX();//position dans l'image
                unsigned int y = tile.getY();

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[idx * 4];
                
                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(x,y);
                quad[1].position = sf::Vector2f(x+w, y);
                quad[2].position = sf::Vector2f(x+w, y+h);
                quad[3].position = sf::Vector2f(x, y+h);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu, tv);
                quad[1].texCoords = sf::Vector2f(tu + w, tv);
                quad[2].texCoords = sf::Vector2f(tu + w, tv +h);
                quad[3].texCoords = sf::Vector2f(tu, tv +h);        
    };

{
}
    
    
    
    
    
    void SurfaceSFML::setSpriteButton (unsigned int x1, unsigned int y1, unsigned int xTex, unsigned int width){
        
        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        unsigned int size = m_vertices.getVertexCount();
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(size+4);
        
        int tu = xTex;//position dans la texture

        unsigned int w = width;//width d'un affichage
        unsigned int h = 72;

        // on récupère un pointeur vers le quad à définir dans le tableau de vertex
        sf::Vertex* quad = &m_vertices[size];

        // on définit ses quatre coins
        quad[0].position = sf::Vector2f(x1,y1);
        quad[1].position = sf::Vector2f(x1+w, y1);
        quad[2].position = sf::Vector2f(x1+w, y1+h);
        quad[3].position = sf::Vector2f(x1, y1+h);

        // on définit ses quatre coordonnées dans la texture
        quad[0].texCoords = sf::Vector2f(tu, 0);
        quad[1].texCoords = sf::Vector2f(tu + w,0);
        quad[2].texCoords = sf::Vector2f(tu + w, h);
        quad[3].texCoords = sf::Vector2f(tu, h);       
    }
  
    
