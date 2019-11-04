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
    
    int CommandSet::size() const {
        return commands.size();
    }

    Command* CommandSet::get(int category) const {
        auto search = commands.find(category);
        if (search != commands.end())
            return commands.at(category);
        return nullptr;
    };

    void CommandSet::add(Command* command) {
        auto a  = commands.insert(std::make_pair(command->getCategory(),command));
        if (!a.second)//first renvoie le type de catégorie second la commande. 
            /*Si on insère une commande avec une clé déjà existante, la commande
             * n'est pas ajoutée donc on force l'ajout ce qui supprime l'ancienne
             * commande de la même catégorie!
             */
            commands[command->getCategory()] = command;
    };
    
              
    void CommandSet::clear() {
        commands.clear();
    };

}