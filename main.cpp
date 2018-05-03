#include <iostream>

#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "TreeNode.h"
#include "TreeNode.cpp"

using namespace std;

int main() {
    BinarySearchTree<int>* tree = new BinarySearchTree<int>(); //constructor ok
    tree->insert(54);
    tree->insert(23);
    tree->insert(68); // los inserts funcionan bien
    tree->insert(10);
    tree->insert(34);
    tree->insert(57);
    tree->insert(123);
    
    cout << "\t\t" << tree->root()->getData() << endl;
    cout << "\t" << tree->root()->getLeft()->getData() << "\t\t" << tree->root()->getRight()->getData() << endl;
    cout << "    " << tree->root()->getLeft()->getLeft()->getData();
    cout << "    " << tree->root()->getLeft()->getRight()->getData();
    cout << "\t     " << tree->root()->getRight()->getLeft()->getData();
    cout << "    " << tree->root()->getRight()->getRight()->getData() << endl;
    
    //tree->printPostorder(); //Todos los prints estan mal
    tree->printInorder();
    tree->printPostorder();
    tree->printPreorder();
    
    //cout << tree->size() << "\t" << endl; // size y height estan mal, height tiene un fallo en tiempo de ejecucion
    cout << tree->search(23) << endl;
    cout << tree->search(123) << endl; // los search funcionan bien
    cout << tree->search(145) << endl;
    
    return 0;
}
