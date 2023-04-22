#ifndef OBJ_H
#define OBJ_H
#include <string>

/**
 * does not handle concurrent access
*/
class Obj {
    private:
        
    public:
        static int count;
        Obj();
        Obj(const Obj& other_obj);
        Obj(Obj&& other_obj) noexcept;
        Obj& operator=(const Obj& other_obj);
        Obj& operator=(Obj&& other_obj) noexcept;
        ~Obj();
        int nobjs();
};

#endif
