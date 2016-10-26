/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 1:27 PM
 *
 * Part of tank */

#include "CommandSet.h"
#include "Command.h"
#include <utility> 

namespace engine{
    
    int CommandSet::size() const {
        return commands.size();
    };

    void CommandSet::add(Command* command) {
        commands.insert(std::make_pair(command->getCategory(),command));
    };
    
    Command* CommandSet::get(int category) const {
        return commands.at(category);
    };
          
    void CommandSet::clear() {
        commands.clear();
    };

}