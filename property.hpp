#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <string>
#include <vector>
#include <array>
#include "blocks.hpp"

using std::string;
using std::vector;
using std::array;

namespace wdgq
{
    class Property {
    private:
        static int _lastUid;
        int uid;
    public:
        Block* from;
        Block* to;
        string propertyName;

        Property() {
            from = nullptr;
            to = nullptr;
            uid = _lastUid++;
        }

        Property(Block* from, Block* to) : from(from), to(to) {
            uid = _lastUid++;
        }

        int getUid() {
            return uid;
        }

        vector<array<string,3>> GetTriples() {
            return vector<array<string,3>>();
        }

        friend bool operator < (const Property& a, const Property& b);
    };

    bool operator < (const Property& a, const Property& b) { return a.uid < b.uid; }
}

#endif // PROPERTY_HPP