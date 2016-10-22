

#include "engine.h"


namespace engine {

  /// class LoadCommand - 
    // Attributes
    LoadCommand::LoadCommand (const char* f){
        file_name = f;
    };
    
    int LoadCommand::getCategory () const{
        return MAIN_CATEGORY;
    };
    
    CommandTypeId LoadCommand::getTypeId () const{
        return LOAD;
    };
    const char* LoadCommand::getFileName () const{
        return file_name;
    };


};



