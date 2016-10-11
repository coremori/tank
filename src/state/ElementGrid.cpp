/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"


namespace state {

    ElementGrid::ElementGrid (State& s) : ElementList(s){
        new ElementList(s);
        this->width = 0;
        this->height =0;
    };
      
    int const ElementGrid::getWidth (){
        return width;
    };
    
    int ElementGrid::getHeight () const{
        return height;
    };
        
    Element* ElementGrid::getCell (int i, int j) const{ 
        // retourne l'element à la place ligne i, colonne j du tableau
        // error s'il n'existe pas
        assert (this->hasCell(i,j)); 
        return ElementList::elements[i*width+j];

    };
          
    bool ElementGrid::isSpace (int i, int j)  const{
           assert (this->hasCell(i,j)); 
           return ElementList::elements[i*width+j]->getTypeId()==space;
    };
    
    void ElementGrid::setCell (int i, int j, Element* e){
        assert (this->hasCell(i,j));
        ElementList::set(i*width+j, e);
    };
    
    bool ElementGrid::hasCell (int i, int j) const{
        return (i<width)&&(j<height)&&(0<=i)&&(0<=j);
    };
    
    
    
    
    
  };


