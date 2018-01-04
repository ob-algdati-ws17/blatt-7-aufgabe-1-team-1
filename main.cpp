//
// Created by mario on 12/26/17.
//


#include <iostream>
#include "AVLTree.h"


int main()
{
    /*
    srand(1380550327);
    AVLTree t;
    for( int i = 0; i < 10000; i++)
    {
        int r = rand();
        std::cout << "Insert: " << r << std::endl;
        t.insert( r );
        if(!t.checkStructure())
            std::cout << "fail" << std::endl;
    }
    */


    srand(12345);
    for( int i = 0; i < 1000000; i++)
    {
        int seed = rand();
        std::cout << "Test: " << i << " with seed " << seed << std::endl;
        srand(seed);
        AVLTree t;
        for( int i = 0; i < 10000; i++)
        {
            int r = rand();
            t.insert( r );
            if(!t.checkStructure()) {
                std::cout << "fail" << std::endl;
                exit(1);
            }
        }
    }


    std::cout << "Hello World" << std::endl;
}