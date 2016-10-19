#include "Element.h"
#include <iostream>
#include <fstream>
#include "state.hpp"
#include <stdio.h>
#include <string.h>


using namespace std;

namespace state {

  /// class ElementList -  c
     
    ElementList::ElementList (State& s) : s(s) {
        
    };
    
    
    ElementList::~ElementList (){
    };

   
    int ElementList::size () const{
        //elements[0]->getObstacleType();
        return elements.size();
    };
        
    Element* ElementList::get ( int idx)  const{
        assert(size()>idx && idx>=0);
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
    
    void ElementList::load(char* path){
        string line;
        ifstream myfile(path);
        int x=0,y=0;
        if(myfile.is_open())
        {
            while (getline(myfile,line))
            {
                ++y;
                
                cout << line << '\n';
                for(std::string::size_type i = 0; i < line.length(); ++i){
                    char* c = &line[i];
                    ++x;
                    if(strcmp(c,".")==0){
                        this->elements.push_back(new Space(x,y));
                    }
                    else if(strcmp(c,"|")==0){
                        this->elements.push_back(new Obstacle(greenery,x,y));
                    }
                    else if(strcmp(c,"-")==0){
                        this->elements.push_back(new Obstacle(sand,x,y));
                    }
                    else if(strcmp(c,"&")==0){
                        s.getMobiles().elements.push_back(new Tank(Little_tank_green,realPlayer,right_down,x,y));
                    }
                    else if(strcmp(c,"%")==0){
                        s.getMobiles().elements.push_back(new Tank(Little_tank_grey,realPlayer,left_down,x,y));
                    }
                    
                    if(i==(line.length()-1)){
                        x=0;
                    }
                }
                 
            }
            myfile.close();
        }
        else cout << "Unable to open file"; 

    }
    

};
