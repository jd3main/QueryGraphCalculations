#ifndef TOOLBOX_HPP
#define TOOLBOX_HPP

#include <string>
#include "blocks.hpp"
#include "property.hpp"
#include <vector>

using std::string;

namespace wdgq
{
    class ToolBox {
    public: 
        const std::vector<string> BlockTypesNames = {"Entity","Query","Data"};

        static Block MakeBlock(string blockTypeName) {
            Block newBlock = Block();
            if (blockTypeName == "Entity") {
                newBlock.type = Block::Type::Entity;
            }
            else if (blockTypeName=="Query") {
                newBlock.type = Block::Type::Field;
            }
            else if (blockTypeName=="Data") {
                newBlock.type = Block::Type::Data;
            }
            return newBlock();
        }
    };
}

#endif // TOOLBOX_HPP