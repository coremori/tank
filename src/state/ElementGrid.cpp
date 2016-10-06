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
           return ElementList::elements[i*width+j]->getTypeId()==space;
    };
    
    void ElementGrid::setCell (int i, int j, Element* e){
        assert (this->hasCell(i,j));
        ElementList::set(i*width+j, e);
    };
    
    bool const ElementGrid::hasCell (int i, int j){
        return (i<width)&&(j<height)&&(0<=i)&&(0<=j);
    };
    
    
    void ElementGrid::load (const char* file_name){
        elements.clear();
        char element;
        int idx = 0;
        int idxmobiles = 0;
        /*ElementList mobiles = new ElementList(s);
        s.setMobiles(mobiles);*/
        
        
        ifstream myfile (file_name);
        if (myfile.is_open())
        {
            myfile >> this->width >> this->height;
                                                    // regler la hauteur de ciel
            while ( myfile.get(element) )
            {
                if ((element != '*')&&(element != '%')) //'*' pour le joueur humain et '%' pour l'IA
                {
                    ElementList::set(idx,factory->newInstance(element));
                    idx++;
                }
                else
                {
                    ElementList::set(idx,factory->newInstance('.'));
                    ElementList e = s.getMobiles();
                    e.set(idxmobiles, factory->newInstance(element));
                    idxmobiles ++;
                }
            }
            myfile.close();
             
        }

        else cout << "Unable to open file"; 
        
        
    };
    
  };


