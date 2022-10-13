//
// Created by STSC on 10/10/2022.
//

#include "DaTree.h"
template<class T>
DaTree<T>::DaTree(){
    root= nullptr;
    numNodes=0;
}

template<class T>
DaTree<T>::~DaTree() {

}



template<class T>
void DaTree<T>::PutItem(T val) {
    TreeNode* newNode =new TreeNode();
    newNode->value=val;

    //Base Case
    if(root == nullptr){
        root=newNode;
        numNodes++;
        return;
    }

    //Traverse through the Tree
    TreeNode* curr=root;
    while(true){
        //If it is smaller than the current go to the left
        if(val<curr->value){
            // If it hit the leaf node, I guess
            // Set that leaf node to the newNode
            if(curr->left== nullptr){
                curr->left=newNode;
                break;
            }
            //Use to traverse
            curr=curr->left;
            //If it is smaller than the current go to the right
        }else if(val>curr->value){
            // If it hit the leaf node, I guess
            // Set that leaf node to the newNode
            if(curr->right== nullptr){
                curr->right=newNode;
                break;
            }
            curr=curr->right;
        }else{
            delete newNode;
            return;
        }
    }
    numNodes++;
}

template<class T>
void DaTree<T>::RemoveItem(T val) {
    TreeNode* curr =root;
    while(curr!= nullptr){
        if(val == curr->value){
            cout<<"Found: "<<curr->value<<" ... attempt to delete ! \n";
            DeleteNode(curr);
            cout<<"Success\n";
            numNodes--;
            return;
        }else if(val < curr->value){
            curr=curr->left;
        }else{
            curr=curr->right;
        }
    }
}

template<class T>
int DaTree<T>::GetSize() {
    return numNodes;
}

template<class T>
void DaTree<T>::Self_Balancing() {

}

template<class T>
bool DaTree<T>::Check_Balancing() {
    return false;
}

template<class T>
void DaTree<T>::ResetIterator(Order traverseOrder) {
    printQueue.empty();
    if (traverseOrder == IN_ORDER)
        PlaceInOrder(root);
    else if (traverseOrder == POST_ORDER)
        PlacePostOrder(root);
    else if (traverseOrder == PRE_ORDER)
        PlacePreOrder(root);
}

template<class T>
T DaTree<T>::GetNextItem() {
    T value = printQueue.front();  // Top, peek, front
    printQueue.pop();
    return value;
}

template<class T>
void DaTree<T>::DestroyTree(DaTree::TreeNode *node) {
    if(node== nullptr){
        return;
    }
    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
}

template<class T>
void DaTree<T>::RemoveHelper(DaTree::TreeNode *&subtree, T value) {
    if(value==subtree->value){
        DeleteNode(subtree);
    }else if(value<subtree->value){
        subtree=subtree->left;
    }else{
        subtree=subtree->right;
    }
}

template<class T>
void DaTree<T>::DeleteNode(DaTree::TreeNode *&subtree) {
    T item;
    TreeNode* tempPtr;
    tempPtr=subtree;
    if(subtree->right== nullptr&&subtree->left==nullptr){
        delete tempPtr;
        subtree= nullptr;
    }else if(subtree->left ==nullptr){
        subtree=subtree->right;
        delete tempPtr;
    }else if(subtree->right== nullptr){
        subtree=subtree->right;
        delete tempPtr;
    }else{
        GetPredecessor(subtree->left,item);
        subtree->value=item;
        RemoveHelper(subtree->left,item);
    }
}

template<class T>
void DaTree<T>::GetPredecessor(DaTree::TreeNode *curr, T &value) {
    while(curr->right!= nullptr){
        curr=curr->right;
    }
    value=curr->value;
}

template<class T>
DaTree<T>& DaTree<T>::operator=(const DaTree &otherTree) {
    CopyHelper(root, otherTree.root);
    numNodes=otherTree.numNodes;
    return *this;
}

template<class T>
void DaTree<T>::CopyHelper(DaTree::TreeNode *&thisTree, DaTree::TreeNode *otherTree) {
    //Base Case
    if(otherTree== nullptr){
        thisTree== nullptr;
        return;
    }
    thisTree=new TreeNode;
    thisTree->value=otherTree->value;
    CopyHelper(thisTree->left,otherTree->left);
    CopyHelper(thisTree->right,otherTree->right);
}

//Pre-order Traversal
template<class T>
void DaTree<T>::PlacePreOrder(DaTree::TreeNode *node) {
    if (node == nullptr)
        return;
    printQueue.push(node->value);
    PlacePreOrder(node->left);
    PlacePreOrder(node->right);
}

//Post-Order Traversal
template<class T>
void DaTree<T>::PlacePostOrder(DaTree::TreeNode *node) {
    if (node == nullptr)
        return;
    PlacePreOrder(node->left);
    PlacePreOrder(node->right);
    printQueue.push(node->value);
}

//In-Order Traversal
template<class T>
void DaTree<T>::PlaceInOrder(DaTree::TreeNode *node) {
    if (node == nullptr)
        return;
    PlacePreOrder(node->left);
    printQueue.push(node->value);
    PlacePreOrder(node->right);
}

template<typename T>
bool DaTree<T>::Contains(T val) {
    TreeNode* curr =root;
    while(curr!= nullptr){
        if(val==curr->value){
            return true;
        }else if(val<curr->value){
            curr=curr->left;
        }else{
            curr=curr->right;
        }
    }
};