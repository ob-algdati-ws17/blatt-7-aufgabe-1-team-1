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

        bool find ( const int ) const;
        bool insert( const int );
        bool remove( const int );


        void rotateRight();
        void rotateLeftRight();
        void rotateLeft();
        void rotateRightLeft();

        bool checkStructure( int *, int *, int * );

    };

    Node *root = nullptr;

public:
    ~AVLTree();

    bool find( const int ) const;
    void insert( const int );
    void remove( const int );

    bool checkStructure();
};


#endif //AVLTREE_AVLTREE_H
