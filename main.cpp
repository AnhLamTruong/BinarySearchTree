#include <iostream>
#include "DaTree.h"
#include "DaTree.cpp"
using namespace std;

int main() {
    DaTree<int> treeA;
    DaTree<int> treeB;
    treeA.PutItem(2);
    treeA.PutItem(1);
    treeA.PutItem(10);
    treeA.PutItem(6);
    treeA.PutItem(7);
    treeB=treeA;
//    treeA=treeB;
//    DaTree<int>* tree=new DaTree<int>;
//    DaTree<int>* treeA=new DaTree<int>;


//    tree->PutItem(2);
//    tree->PutItem(1);
//    tree->PutItem(10);
//    tree->PutItem(6);
//    tree->PutItem(7);
//    treeA=tree;

    treeA.ResetIterator(IN_ORDER);
    for(int i=0; i<treeA.GetSize(); i++){
        cout<<treeA.GetNextItem()<<'\t';
    }
    cout<<endl;

    treeB.ResetIterator(IN_ORDER);
    for(int i=0; i<treeB.GetSize(); i++){
        cout<<treeB.GetNextItem()<<'\t';
    }
    cout<<endl;

//    tree->RemoveItem(10);
//
//    tree->ResetIterator(IN_ORDER);
//    for(int i=0; i<tree->GetSize(); i++){
//        cout<<tree->GetNextItem()<<'\t';
//    }
//
//    cout<<endl;
//    delete treeA;
    return 0;
}
