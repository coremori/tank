/* 
 * Author: Corentin Morisse & Pierre-Bernard Le Roux 
 * Created on October 22, 2016, 1:27 PM
 *
 * Part of tank */

#include "CommandSet.h"
#include "Command.h"
#include <utility> 
#include <map>


namespace engine{
    
<<<<<<< HEAD
    int CommandSet::size() const {
        return commands.size();
=======

    Command* CommandSet::get(int category) const {
        auto search = commands.find(category);
        if (search != commands.end())
            return commands.at(category);
        return nullptr;
>>>>>>> ec32201184404f0ba19d037094215cb80a215b72
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