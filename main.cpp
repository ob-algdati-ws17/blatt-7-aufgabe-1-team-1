//
// Created by mario on 12/26/17.
//


#include <iostream>
#include "AVLTree.h"


int main()
{



    for( int i = 0; i < 1000; i++ )
    {
        AVLTree t;
        for( int j = 0; j < 10000; j++)
        {
            t.insert( rand() % 1000 );
        }

        for( int i = 0; i < 10000; i++ )
        {
            t.remove( i );
            std::cout << t.checkStructure() << std::endl;
        }
    }

    std::cout << "Hello World" << std::endl;
}