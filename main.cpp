//
// Created by mario on 12/26/17.
//


#include <iostream>
#include "AVLTree.h"


int main()
{
    AVLTree t;

    t.insert( 1 );
    t.insert( 5 );
    t.insert( 7 );
    t.insert( 8 );
    t.insert( 12 );
    t.insert( 6 );
    t.insert( 17 );
    t.insert( 18 );
    t.insert( 12 );
    t.insert( 31 );
    t.insert( 22 );
    t.insert( 41 );

    std::cout << t.find( 1 ) << std::endl;
    std::cout << t.find( 5 ) << std::endl;
    std::cout << t.find( 23 ) << std::endl;
    std::cout << t.find( 24 ) << std::endl;


    std::cout << "Hello World" << std::endl;
}