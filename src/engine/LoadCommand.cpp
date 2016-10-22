

#include "engine.h"
#include <string>


namespace engine {

  /// class LoadCommand - 
    // Attributes
    LoadCommand::LoadCommand (const char* f){
        file_name = f;
    };
    
    int LoadCommand::getCategory () const{
        return MAIN_CATEGORY;
    };
    
    const char* LoadCommand::getFileName () const{
        return file_name.c_str();
    };


};



