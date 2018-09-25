/*
    Defines Dn Dimensional vector.
    Vector range is theoretically +-Tk for each dimension
*/ 
#include <iostream> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "RWObj.h"

using namespace std; 


bool RWObj::seed_is_init = false;

RWObj::RWObj(int Dn, int Tk):Dn(Dn),Tk(Tk),debug(0)
//This constructor has enough information to start random walk
{
    coord.resize(Dn);
    restart(); 
}

RWObj::RWObj():Dn(0),Tk(0),debug(0)
{

}

RWObj::RWObj(const RWObj & RW2)
{
    Dn = RW2.Dn;
    Tk = RW2.Tk;
    debug = 0;
    coord.resize(Dn);
    for(int i = 0; i < Dn; i++)
    {
        coord[i] = RW2.coord[i];
    }
}

void RWObj::set_debug(int i)
{
    debug = i; 
}

void RWObj::restart()
{
    for(int i = 0; i < Dn; i++)
    {
        coord[i] = 0; //initialize to origin
    }
    int d; // points to a dimension
    int delta; // stores 1 or -1
    if(debug) 
    {
         cout << "[DBG] " << "Coordinate definition (d1,d2,d3,..,dn)"<<endl; 
    }
    
    if(!seed_is_init)
    {
        seed_is_init = true;
        srand(time(0)); //initialize srand() seed once
    }

    for(int i = 0; i < Tk; i++)
    {
        d = rand()%Dn + 1; //randomly pick between 1 and Dn (inclusive)
        delta = rand()%2;
        if(delta == 0) delta = -1; 
        coord[d - 1] += delta;

        if(debug)
        {
            cout << "[DBG] " << "Selected d" << d << endl; 
            cout << "[DBG] " << "Selected delta=" << delta << endl; 
            cout << "[DBG] " << "("; 
            for(int i = 0; i < Dn - 1; i++)
            {
                cout << coord[i] << ","; 
            }
            cout << coord[Dn - 1]; 
            cout << ")" << endl; 
        }
    }    
}

void RWObj::print()
{
    cout << "position => ("; 
    for(int i = 0; i < Dn - 1; i++)
    {
        cout << coord[i] << ","; 
    }
    cout << coord[Dn - 1]; 
    cout << ")" << endl; 
}
void RWObj::test_rand()
{
    int num;
    for(int i = 0; i < Tk; i++)
    {
        num = rand()%10 + 1;
        cout << "num = " << num << endl; 
    }
}

void RWObj::test_randb()
{
    int num;
    for(int i = 0; i < Tk; i++)
    {
        num = rand()%2;
        if(num == 0)
            num = -1;
        cout << "num = " << num << endl; 
    }
}