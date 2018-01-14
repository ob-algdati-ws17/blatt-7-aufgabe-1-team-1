//
// Created by mario on 1/14/18.
//

#include "testAVLTree.h"


//Empty Tree
TEST( AVLTreeTest, Empty_Tree )
{
    AVLTree t;
    EXPECT_EQ( nullptr, t.preorder() );
    EXPECT_EQ( nullptr, t.inorder() );
    EXPECT_EQ( nullptr, t.postorder() );
}

//Insert and find


TEST( AVLTreeTest, One_Node )
{
    AVLTree t;
    t.insert( 5 );
    EXPECT_TRUE( t.find( 5 ));
    EXPECT_FALSE( t.find( 3 ));
    EXPECT_FALSE( t.find( 8 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 5 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 5 ));
}

TEST( AVLTreeTest, Three_Nodes )
{
    AVLTree t;
    t.insert( 5 );
    t.insert( 3 );
    t.insert( 8 );

    EXPECT_TRUE( t.find( 5 ));
    EXPECT_TRUE( t.find( 3 ));
    EXPECT_TRUE( t.find( 8 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5, 3, 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 3, 5, 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 3, 8, 5 ));
}

TEST( AVLTreeTest, Single_Rotation )
{
    AVLTree t;

    t.insert( 3 );
    t.insert( 5 );
    t.insert( 8 );


    EXPECT_TRUE( t.find( 3 ));
    EXPECT_TRUE( t.find( 5 ));
    EXPECT_TRUE( t.find( 8 ));

    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5, 3, 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 3, 5, 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 3, 8, 5 ));

}

TEST( AVLTreeTest, Double_Rotation )
{
    AVLTree t;

    t.insert( 8 );
    t.insert( 3 );
    t.insert( 5 );


    EXPECT_TRUE( t.find( 8 ));
    EXPECT_TRUE( t.find( 3 ));
    EXPECT_TRUE( t.find( 5 ));

    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5, 3, 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 3, 5, 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 3, 8, 5 ));
}

TEST( AVLTreeTest, Random_nodes )
{
    AVLTree t;

    for( int i = 0; i < 1000; i++ )
    {
        int random = rand() % 1000;
        t.insert(random);
        EXPECT_TRUE( t.find( random ) );
        EXPECT_TRUE( t.checkStructure() );

    }
}

//Delete

TEST( AVLTreeTest, Delete )
{
    AVLTree t;
    t.insert( 5 );
    t.insert( 3 );
    t.insert( 8 );

    EXPECT_TRUE( t.find( 5 ));
    EXPECT_TRUE( t.find( 3 ));
    EXPECT_TRUE( t.find( 8 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5, 3, 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 3, 5, 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 3, 8, 5 ));

    t.remove( 3 );

    EXPECT_TRUE( t.find( 5 ));
    EXPECT_FALSE( t.find( 3 ));
    EXPECT_TRUE( t.find( 8 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5, 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 5, 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 8, 5 ));

    t.remove( 5 );

    EXPECT_FALSE( t.find( 5 ));
    EXPECT_FALSE( t.find( 3 ));
    EXPECT_TRUE( t.find( 8 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 8 ));


    t.remove( 8 );

    EXPECT_FALSE( t.find( 5 ));
    EXPECT_FALSE( t.find( 3 ));
    EXPECT_FALSE( t.find( 8 ));
    EXPECT_EQ( nullptr, t.preorder() );
    EXPECT_EQ( nullptr, t.inorder() );
    EXPECT_EQ( nullptr, t.postorder() );
}

TEST( AVLTreeTest, Delete_Single_Rotation )
{
    AVLTree t;
    t.insert( 5 );
    t.insert( 3 );
    t.insert( 8 );
    t.insert( 2 );

    EXPECT_TRUE( t.find( 5 ));
    EXPECT_TRUE( t.find( 3 ));
    EXPECT_TRUE( t.find( 8 ));
    EXPECT_TRUE( t.find( 2 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5, 3, 2, 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 2, 3, 5, 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 2, 3, 8, 5 ));

    t.remove( 8 );

    EXPECT_TRUE( t.find( 5 ));
    EXPECT_TRUE( t.find( 3 ));
    EXPECT_FALSE( t.find( 8 ));
    EXPECT_TRUE( t.find( 2 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 3, 2, 5 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 2, 3, 5 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 2, 5, 3 ));
}

TEST( AVLTreeTest, Delete_Double_Rotation )
{

    AVLTree t;
    t.insert( 5 );
    t.insert( 3 );
    t.insert( 8 );
    t.insert( 4 );

    EXPECT_TRUE( t.find( 5 ));
    EXPECT_TRUE( t.find( 3 ));
    EXPECT_TRUE( t.find( 8 ));
    EXPECT_TRUE( t.find( 4 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 5, 3, 4, 8 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 3, 4, 5, 8 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 4, 3, 8, 5 ));

    t.remove( 8 );



    EXPECT_TRUE( t.find( 5 ));
    EXPECT_TRUE( t.find( 3 ));
    EXPECT_FALSE( t.find( 8 ));
    EXPECT_TRUE( t.find( 4 ));
    EXPECT_THAT( *t.preorder(), testing::ElementsAre( 4, 3, 5 ));
    EXPECT_THAT( *t.inorder(), testing::ElementsAre( 3, 4, 5 ));
    EXPECT_THAT( *t.postorder(), testing::ElementsAre( 3, 5, 4 ));
}


TEST( AVLTreeTest, Delete_Random )
{
    AVLTree t;

    for( int i = 0; i < 1000; i++ )
    {
        int random = rand() % 1000;
        t.insert(random);
    }

    for( int i = 0; i < 1000; i++ )
    {
        int random = rand() % 1000;
        t.remove( random );
        EXPECT_FALSE( t.find( random ) );
        EXPECT_TRUE( t.checkStructure() );
    }
}