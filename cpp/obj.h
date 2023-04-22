#ifndef OBJ_H
#define OBJ_H
#include <string>

/**
 * does not handle concurrent access
*/
class Obj {
    private:
        static int count;
    public:
        Obj();
        ~Obj();
        int nobjs();
};

#endif
