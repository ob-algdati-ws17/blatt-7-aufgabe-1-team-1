//
// Created by hm-scalet on 02.01.2018.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#include <vector>


class AVLTree
{
    struct Node
    {
        int key;

        int balance = 0;

        Node **selfPointer;

        Node *left = nullptr;

        Node *right = nullptr;

        Node( const int );
        ~Node();

        bool find ( const int ) const;
        bool insert( const int );
        bool remove( const int );


        void rotateRight( int, int );
        void rotateLeftRight();
        void rotateLeft( int, int );
        void rotateRightLeft();

        int findMax();
        bool balanceLeft();
        bool balanceRight();


        bool checkStructure( int *, int *, int * );
        std::vector<int> *preorder() const; // (Hauptreihenfolge)
        std::vector<int> *inorder() const; // (Symmetrische Reihenfolge)
        std::vector<int> *postorder() const; // (Nebenreihenfolge)


    };

    Node *root = nullptr;

public:
    ~AVLTree();

    bool find( const int ) const;
    void insert( const int );
    void remove( const int );

    bool checkStructure();
    std::vector<int> *preorder() const; // (Hauptreihenfolge)
    std::vector<int> *inorder() const; // (Symmetrische Reihenfolge)
    std::vector<int> *postorder() const; // (Nebenreihenfolge)
};


#endif //AVLTREE_AVLTREE_H
