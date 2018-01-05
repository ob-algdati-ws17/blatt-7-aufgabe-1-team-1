//
// Created by hm-scalet on 02.01.2018.
//

#include <iostream>
#include "AVLTree.h"


AVLTree::~AVLTree()
{
    delete root;
}

bool AVLTree::find( const int k ) const
{
    if( root == nullptr )
        return false;
    return root->find( k );
}

void AVLTree::insert( const int k )
{
    if( root == nullptr )
    {
        root = new Node(k);
        root->selfPointer = &root;
    }
    else
        root->insert( k );
}

void AVLTree::remove( const int k )
{
    if( root != nullptr )
        root->remove( k );

}


bool AVLTree::checkStructure()
{
    int tmp = 0;
    return root->checkStructure( &tmp, &tmp, &tmp );
}




AVLTree::Node::Node( const int k ) : key(k) {}

AVLTree::Node::~Node()
{
    delete left;
    delete right;
}

bool AVLTree::Node::find( const int k ) const
{

    if( k < key )
    {
        if( left == nullptr )
            return false;
        return left->find( k );
    }
    else if( k > key )
    {
        if( right == nullptr )
            return false;
        return right->find( k );
    }
    return true;

}

bool AVLTree::Node::insert( const int k )
{
    if( k < key )
    {
        if( left == nullptr )
        {
            left = new Node( k );
            left->selfPointer = &left;
            balance--;
            return (bool) balance;
        }
        else
        {
            if (left->insert(k))
            {
                if (balance == -1)
                {
                    if(left->balance == -1)
                    {
                        rotateRight( 0, 0 );
                        return false;
                    }
                    else
                    {
                        rotateLeftRight();
                    }
                }
                else
                {
                    balance--;
                    return (bool) balance;
                }
            }
            return false;
        }

    }
    else if( k > key )
    {
        if( right == nullptr )
        {
            right = new Node(k);
            right->selfPointer = &right;
            balance++;
            return (bool) balance;
        }
        else {
            if (right->insert(k))
            {
                if (balance == 1)
                {
                    if(right->balance == 1)
                    {
                        rotateLeft( 0, 0 );
                        return false;
                    }
                    else
                    {
                        rotateRightLeft();
                    }
                }
                else
                {
                    balance++;
                    return (bool) balance;
                }
            }
            return false;
        }

    }

    return false;
}

bool AVLTree::Node::remove( const int k )
{
    if( k < key )
    {
        if( left != nullptr )
        {
            if( left->remove( k ) )
            {
                return balanceLeft();
            }
        }


    }
    else if( k > key )
    {
        if( right != nullptr )
        {
            if( right->remove( k ) )
            {
                return balanceRight();
            }
        }

    }
    else
    {
        if( left == nullptr && right == nullptr )
        {
            *selfPointer = nullptr;
            delete this;
            return true;
        }
        else if( left != nullptr && right != nullptr)
        {
            int leftMax = left->findMax();
            key = leftMax;
            if( left->remove( leftMax ) )
            {
                return balanceLeft();
            }
        }
        else
        {
            if(left != nullptr )
            {
                left->selfPointer = selfPointer;
                *selfPointer = left;
                left = nullptr;
                delete this;
                return true;
            }
            else
            {
                right->selfPointer = selfPointer;
                *selfPointer = right;
                right = nullptr;
                delete this;
                return true;
            }
        }
    }

}


void AVLTree::Node::rotateRight( int b, int bC )
{
    Node *child = left;
    left = child->right;
    child->right = this;
    *selfPointer = child;
    child->selfPointer = selfPointer;
    if(left != nullptr )
        left->selfPointer = &left;
    selfPointer = &child->right;
    balance = b;
    child->balance = bC;
}

void AVLTree::Node::rotateLeftRight()
{
    Node *child = left;
    Node *grandChild = child->right;
    child->right = grandChild->left;
    left = grandChild->right;
    grandChild->left = child;
    grandChild->right = this;
    *selfPointer = grandChild;
    grandChild->selfPointer = selfPointer;
    child->selfPointer = &grandChild->left;
    selfPointer = &grandChild->right;

    if( child->right != nullptr )
        child->right->selfPointer = &child->right;
    if( left != nullptr )
        left->selfPointer = &left;

    switch( grandChild->balance )
    {
        case -1:
            balance = 1;
            child->balance = 0;
            break;
        case 0:
            balance = 0;
            child->balance = 0;
            break;
        case 1 :
            balance = 0;
            child->balance = -1;
            break;
    }

    grandChild->balance = 0;



}

void AVLTree::Node::rotateLeft( int b, int bC )
{
    Node *child = right;
    right = child->left;
    child->left = this;
    *selfPointer = child;
    child->selfPointer = selfPointer;
    if(right != nullptr )
        right->selfPointer = &right;
    selfPointer = &child->left;
    balance = b;
    child->balance = bC;
}

void AVLTree::Node::rotateRightLeft()
{
    Node *child = right;
    Node *grandChild = child->left;
    child->left = grandChild->right;
    right = grandChild->left;
    grandChild->right = child;
    grandChild->left = this;
    *selfPointer = grandChild;
    grandChild->selfPointer = selfPointer;
    child->selfPointer = &grandChild->right;
    selfPointer = &grandChild->left;

    if( child->left != nullptr )
        child->left->selfPointer = &child->left;
    if( right != nullptr )
        right->selfPointer = &right;

    switch( grandChild->balance )
    {
        case 1:
            balance = -1;
            child->balance = 0;
            break;
        case 0:
            balance = 0;
            child->balance = 0;
            break;
        case -1 :
            balance = 0;
            child->balance = 1;
            break;
    }

    grandChild->balance = 0;


}

int AVLTree::Node::findMax()
{
    if(right == nullptr)
        return key;
    return right->findMax();
}

bool AVLTree::Node::balanceLeft()
{
    if( balance == 1 )
    {
        switch(right->balance)
        {
            case -1:
                rotateRightLeft();
                return true;
            case 0:
                rotateLeft( 1, -1 );
                return false;
            case 1:
                rotateLeft( 0, 0 );
                return true;
        }
    }
    else
    {
        balance++;
        return !(bool) balance;
    }
}

bool AVLTree::Node::balanceRight()
{
    if( balance == -1 )
    {
        switch(left->balance)
        {
            case 1:
                rotateLeftRight();
                return true;
            case 0:
                rotateRight( -1, 1 );
                return false;
            case -1:
                rotateRight( 0, 0 );
                return true;
        }
    }
    else
    {
        balance--;
        return !(bool) balance;
    }
}


bool AVLTree::Node::checkStructure( int *height, int *min, int *max ) {
    *min = key;
    *max = key;
    *height = 0;
    int lHeight = 0;
    int rHeight = 0;

    if (balance < -1 || balance > 1)
    {
        std::cout << "balance out of Bounds at Node " << key << std::endl;
        return false;
    }
    if( *selfPointer != this )
    {
        std::cout << "selfPointer incorrect at Node " << key << std::endl;
        return false;
    }
    if( left != nullptr )
    {
        int lMin;
        int lMax;

        if( !left->checkStructure( &lHeight, &lMin, &lMax ) )
            return false;
        if( lMin >= key || lMax >= key )
        {
            std::cout << "Min or Max of left subtree bigger than key at Node " << key << std::endl;
            return false;
        }
        *min = lMin;
    }
    if( right != nullptr )
    {
        int rMin;
        int rMax;

        if( !right->checkStructure( &rHeight, &rMin, &rMax ) )
            return false;
        if( rMin <= key || rMax <= key )
        {
            std::cout << "Min or Max of right subtree smaller than key at Node " << key << std::endl;
            return false;
        }
        *max = rMax;
    }

    if( rHeight - lHeight != balance )
    {
        std::cout << "Height of subtrees does not match balance at Node " << key << std::endl;
        return false;
    }

    *height = std::max(rHeight, lHeight);

    (*height)++;
    return true;
}

