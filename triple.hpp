#ifndef TRIPLE_HPP
#define TRIPLE_HPP

#include "typesdef.hpp"

namespace wdgq
{
    template <typename T>
    class Triple {
        union {
            struct {
                union { T m1, first; }
                union { T m2, second; }
                union { T m3, third; }
            }
            T a[3];
        }

        const T operator [] (int i) const { return a[i]; }
        T& operator [] (int i) { return a[i]; }

        Triple(T1 a1, T2 a2, T3 a3) {
            m1 = a1;
            m2 = a2;
            m3 = a3;
        }
    };
}


#endif /* TRIPLE_HPP */