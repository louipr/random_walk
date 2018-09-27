#include <iostream>
#include "RWObj.h"
#include <chrono>
#include <thread>

using namespace std; 
//rand()

int main()
{
    const int N_WALKS = 50;
    RWObj * rwArray = new RWObj[N_WALKS];
    
    for(int i = 0; i < N_WALKS; i++)
    {
        rwArray[i] = RWObj(i/10 + 1,1000); //Invoking copy constructor 
    }
    for(int i = 0; i < N_WALKS; i++)
    {
        rwArray[i].print();
    }

    //Output debug log
    RWObj rwdbg(2,4);
    rwdbg.set_debug(true);
    rwdbg.restart();
    rwdbg.print();

    return 0;  
}