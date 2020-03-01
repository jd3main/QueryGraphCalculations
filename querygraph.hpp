#ifndef QUERYGRAPH_HPP
#define QUERYGRAPH_HPP

#include <map>
#include <array>
#include "typesdef.hpp"
#include "property.hpp"
#include "blocks.hpp"


using std::map;
using std::array;

namespace wdgq {
    class QueryGraph {
    private:
        map<int,Block> blocks;      // Uid -> Block
        map<int,map<int,Property>> properties;   // SrcUid -> DstUid -> Property
    public:
        vector<string> logs;
        vector<string> warnings;
        vector<string> errors;

        enum class Status {
            good,
            warnned,
            error
        };

        QueryGraph(){

        }

        Status Check() {
            Status status = Status::good;
            return status;
        }

        string MakeQL() {
            return "Not Implemented";
        }
        
        vector<Block> GetBlocks() const {
            vector<Block> results;
            for(auto it=blocks.begin(); it!=blocks.end(); it++) {
                results.push_back(it->second);
            }
            return results;
        }

        vector<Property> GetPropertiesFrom(int uid) const {
            vector<Property> results;
            const map<int,Property>& propertiesFromTarget = properties.at(uid);
            for(auto it = propertiesFromTarget.cbegin() ; it != propertiesFromTarget.cend() ; it++) {
                results.push_back(it->second);
            }
            return results;
        }
        
        vector<Block> GetFieldBlocks() const {
            vector<Block> results;
            for(auto it=blocks.begin(); it!=blocks.end(); it++) {
                if (it->second.isField) {
                    results.push_back(it->second);
                }
            }
            return results;
        }

        void AddBlock(const Block &b) {
            blocks.insert({b.getUid(), b});
        }

        void DeleteBlock(int uid) {
            blocks.erase(uid);
        }

        void AddProperty(int from, int to) {
            AddProperty(Property(&blocks[from], &blocks[to]));
        }

        void AddProperty(const Property &p) {
            properties[p.from->getUid()][p.to->getUid()] = p;
        }

        vector<array<string,3>> MakeTriples() {
            return vector<array<string,3>>();
        }
    };
}

#endif // QUERYGRAPH_HPP