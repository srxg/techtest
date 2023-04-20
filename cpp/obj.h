#ifndef OBJ_H
#define OBJ_H

class Obj {
    private:
        static int count;
    public:
        Obj();
        ~Obj();
        int nobjs();
};

#endif
