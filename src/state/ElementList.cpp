#include "Element.h"
#include <iostream>
#include <fstream>
#include "state.h"
#include <stdio.h>
#include <string.h>


using namespace std;

namespace state {

  /// class ElementList -  c
     
    ElementList::ElementList (State& s) : s(s) {
        
    };
    
    
    ElementList::~ElementList (){
        clear();
    };

   
    int ElementList::size () const{
        //elements[0]->getObstacleType();
        return elements.size();
    };
        
    Element* ElementList::get ( int idx)  const{
        return elements[idx];
    };
        
    void ElementList::clear (){
        elements.clear();
    };
    
  
    void ElementList::set ( int idx, Element* e){
        if(idx==size())
            elements.push_back(e);
        elements[idx] = e;
    };
    
    void ElementList::load(const char* path){
        int NB_STD_HEIGHT_SPRITE = 8;

        string line;
        ifstream myfile(path);
        int x=0,y=-NB_STD_HEIGHT_SPRITE;
        int w,h;
        if(myfile.is_open())
        {
            myfile >> w >> h;
            s.getGrid().setWidth(w);
            s.getGrid().setHeight(h);
            while (getline(myfile,line))
            {
                
                x = 0;
                
                for(unsigned int i = 0; i < line.length(); i++){
                    
                    
                    
                    if(line.at(i)=='.'){
                        this->elements.push_back(new Space(x,y));
                    }
                    else if(line.at(i)=='|'){
                        this->elements.push_back(new Obstacle(greenery,x,y));
                    }
                    else if(line.at(i)=='-'){
                        this->elements.push_back(new Obstacle(sand,x,y));
                    }
                    else if(line.at(i)=='~'){
                        this->elements.push_back(new Obstacle(border,x,y));
                    }
                    else if(line.at(i)=='&'){
                        this->elements.push_back(new Space(x,y));
                        s.getMobiles().elements.push_back(new Tank(Little_tank_green,realPlayer,right_down,x,y));
                    }
                    else if(line.at(i)=='%'){
                        this->elements.push_back(new Space(x,y));
                        s.getMobiles().elements.push_back(new Tank(Little_tank_grey,realPlayer,left_down,x,y));
                    }
                    x = x+NB_STD_HEIGHT_SPRITE;
                }
                y=y+NB_STD_HEIGHT_SPRITE;
                 
            }
            myfile.close();
        }
        else cout << "Unable to open file"; 

    }

    void ElementList::notifyObserver(int idx) const {
        Observable::notifyObserver(ElementEvent(this, idx));
    }

};
