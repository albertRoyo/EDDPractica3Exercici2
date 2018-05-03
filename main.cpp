#include <iostream>

#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "TreeNode.h"
#include "TreeNode.cpp"

using namespace std;
/*
g++ -std=c++11 $(ls *.cpp) && ./a.out
g++ -std=c++11 -c BinarySearchTree.cpp
g++ -std=c++11 -c TreeNode.cpp
g++ -std=c++11 -o main.exe main.o TreeNode.o BinarySearchTree.o*/

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
    cout << endl;
    
    //ja funcionan tots, era simplement canviar alguns left per right
    cout << "Preordre, inordre i postordre:" << endl;
    tree->printPreorder();
    tree->printInorder();
    tree->printPostorder();
    
    cout << "Mida: " << tree->size() << endl;
    cout << "Búsquedes:" << endl;
    cout << tree->search(23) << endl;
    cout << tree->search(123) << endl; // los search funcionan bien
    cout << tree->search(145) << endl;
    
    cout << "Alçada:" << tree->getHeight() << endl;// alçada del arbre
    
    //(comptant que una fulla té alçada 0)
    
    return 0;
}
