//
// Created by STSC on 10/10/2022.
//

#ifndef BINARYTREE_DATREE_H
#define BINARYTREE_DATREE_H
#include <iostream>
#include <bits/stdc++.h>
#include <queue> //stl library

// Used to identify the order you wish to traverse the tree
enum Order {POST_ORDER, IN_ORDER, PRE_ORDER};

using namespace std;

template <typename T>
class DaTree {
public:
    //Constructor
    DaTree();

    //Destructor
    ~DaTree();

    //Overload = operator for a better life-code copying
    DaTree& operator=(const DaTree& otherTree);

    //PutItem
    void PutItem(T val);

    //RemoveItem
    void RemoveItem(T val);

    //Return Number of Node in the structure
    int GetSize();

    //Self-Healthy-and-Balance Function
    void Self_Balancing();

    //Check-Healthy-and-Balance Function
    bool Check_Balancing();

    //Contains Function
    bool Contains(T val);
    // These are used by the iterator
    void ResetIterator(Order traverseOrder);    // Initializes the Iterator
    T GetNextItem();

private:
    struct TreeNode{
        T value;
        TreeNode* left= nullptr;
        TreeNode* right= nullptr;
        //Add new Node at leaf so, initially, the height is 1
        int height=1;
    };
    TreeNode* root;
    int numNodes{};
    queue<T> printQueue;

//    //Allocate newNode
//    TreeNode* newNode(T value){
//        auto* node =new TreeNode();
//        node->info=value;
//        return node;
//    }

    // Used for de-constructor
    void DestroyTree(TreeNode* node);


    // Used for Node removal
    void RemoveHelper(TreeNode*& subtree, T value);
    void DeleteNode(TreeNode*& subtree);
    void GetPredecessor(TreeNode* curr, T& value);

    //For Copy OverLoad Operator
    void CopyHelper(TreeNode*& thisTree, TreeNode* otherTree);

    // Used for iterator
    queue<T> iterArr;     // queue used for the iterator
    void PlacePreOrder(TreeNode* node);
    void PlacePostOrder(TreeNode* node);
    void PlaceInOrder(TreeNode* node);
};
#endif //BINARYTREE_DATREE_H
