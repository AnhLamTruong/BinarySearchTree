#include <iostream>
#include "DaTree.h"
#include "DaTree.cpp"
using namespace std;

int main() {
    DaTree<int> treeA;
    DaTree<int> treeB;
    DaTree<int>* tree=new DaTree<int>;

    tree->PutItem(2);
    tree->PutItem(1);
    tree->PutItem(10);
    tree->PutItem(6);
    tree->PutItem(7);

    tree->ResetIterator(IN_ORDER);
    for(int i=0; i<tree->GetSize(); i++){
        cout<<tree->GetNextItem()<<'\t';
    }
    cout<<endl;
    delete tree;
    return 0;
}
