/*
    Defines an random walk object
    Random walk in 2D
*/ 
#include <vector>

class RWObj
{
    public:     
    static bool seed_is_init; 

    RWObj(int Dn, int Tk);
    RWObj();
    RWObj(const RWObj & RW2); // copy constructor 

    void test_rand(); 
    void test_randb(); //binary rand
    void set_debug(int i); 
    void restart(); //starts random walk
    void print(); //last coordinate
    private: 
    int Dn; // defines the number of dimensions for random walk
    int Tk; // defines number of trails 
    int debug; 
    std::vector <int> coord; //tracks the last coordinate

}; 

