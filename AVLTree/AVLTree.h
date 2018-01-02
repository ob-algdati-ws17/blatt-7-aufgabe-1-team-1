//
// Created by hm-scalet on 02.01.2018.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H


class AVLTree
{
    struct Node
    {
        const int key;

        Node *left = nullptr;

        Node *right = nullptr;

        Node( const int );
        ~Node();
    };

    Node *root = nullptr;

public:
    ~AVLTree();
};


#endif //AVLTREE_AVLTREE_H
