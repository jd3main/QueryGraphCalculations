#ifndef BLOCKS_HPP
#define BLOCKS_HPP

#include <set>
#include "wddata.hpp"

using std::set;
using std::string;

namespace wdgq
{
    struct Block {
    private:
        static int _lastUid;
        int uid;
    public:
        bool isField;
        WdDataType dataType;

        Block(WdDataType type = WdDataType::Item) { 
            uid = _lastUid++;
            dataType = type;
        }

        int getUid() const {
            return uid;
        }

        friend bool operator < (const Block& a, const Block& b);
    };

    bool operator < (const Block& a, const Block& b) { return a.uid < b.uid; }
}
#endif // BLOCKS_HPP