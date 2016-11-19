#include "state.h"
#include <assert.h>
#include "ElementGrid.h"

namespace state {

    ElementGrid::ElementGrid (State& s) : ElementList(s){
        this->width = 0;
        this->height =0;
    };
      
    int ElementGrid::getWidth () const {
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
        if(this->hasCell(i,j))
        {
            return elements[j*width+i]->getTypeId()==space;
        }
        return false;
    };
    
    void ElementGrid::setCell (int i, int j, Element* e){
        if(this->hasCell(i,j))
        {
            ElementList::set(j*width+i, e);
        }
        
    };
    
    bool ElementGrid::hasCell (int i, int j) const{
        return (i<width)&&(j<height)&&(0<=i)&&(0<=j);
    };
    
    void ElementGrid::setHeight (int h){
        height = h;
    };
    
    void ElementGrid::setWidth (int w){
        width = w;
    };
    
    void ElementGrid::copy(const ElementGrid e) {
        
        clear();
        
        for(int i = 0; i < e.size(); i++)
            elements.push_back(e.get(i)->clone());
        width = e.getWidth();
        height = e.getHeight();
    }

  };


