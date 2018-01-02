//
// Created by hm-scalet on 02.01.2018.
//

#include "AVLTree.h"


AVLTree::~AVLTree()
{
    delete root;
}




AVLTree::Node::Node( const int key ) : key(key) {}

AVLTree::Node::~Node()
{
    delete left;
    delete right;
}