/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "state.hpp"

namespace state {

  /// class ElementGrid - 

    // Attributes
/*  protected:
    int width;
    int height;
    // Operations
  public:*/
    ElementGrid::ElementGrid (State& s){
        this->width = 0;
        this->height =0;
    };
      
    int const ElementGrid::getWidth (){
        return width;
    };
    
    int const ElementGrid::getHeight (){
        return height;
    };
        
    Element* const ElementGrid::getCell (int i, int j){ 
        // retourne l'element à la place ligne i, colonne j du tableau
        // error s'il n'existe pas
        assert (this->hasCell(i,j)); 
        return ElementList::elements[i*width+j];

    };
          
    bool const ElementGrid::isSpace (int i, int j){
           assert (this->hasCell(i,j)); 
           return ElementList::elements[i*width+j].getTypeId==space;
    };
    
    void ElementGrid::setCell (int i, int j, Element* e){
        assert (this->hasCell(i,j));
        ElementList::set(i*width+j, e);
    };
    
    bool const ElementGrid::hasCell (int i, int j){
        return (i<width)&&(j<height)&&(0<=i)&&(0<=j);
    };
    
    
    void ElementGrid::load (const char* file_name){
        ElementFactory* f = new ElementFactory();
        //save the factory
        ElementList::setElementFactory(f);
        string line;
        ifstream myfile (file_name);
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();
        }

        else cout << "Unable to open file"; 
        
        
    };
    
  };


