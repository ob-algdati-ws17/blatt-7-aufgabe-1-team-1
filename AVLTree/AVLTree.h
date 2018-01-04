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

        int balance = 0;

        Node **selfPointer;

        Node *left = nullptr;

        Node *right = nullptr;

        Node( const int );
        ~Node();

        bool insert( const int );

        void rotateRight();
        void rotateLeftRight();
        void rotateLeft();
        void rotateRightLeft();

        bool checkStructure( int *, int *, int * );

    };

    Node *root = nullptr;

public:
    ~AVLTree();

    void insert( const int );

    bool checkStructure();
};


#endif //AVLTREE_AVLTREE_H
