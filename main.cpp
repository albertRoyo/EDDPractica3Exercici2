#include <iostream>
#include <vector>

#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "TreeNode.h"
#include "TreeNode.cpp"

using namespace std;

int main() {
    BinarySearchTree<int>* tree = new BinarySearchTree<int>();
    cout << "Arbre binari creat." << endl;
    vector<int> dades = {54, 23, 68, 10, 34, 57, 123};
    for (int i=0; i<dades.size(); ++i){
        tree->insert(dades[i]);
        cout << "Inserta a l’arbre element " << dades[i] << endl;
    }
    
    //Mostrem el arbre gràficament
    cout << "\t\t" << tree->root()->getData() << endl;
    cout << "\t" << tree->root()->getLeft()->getData() << "\t\t" << tree->root()->getRight()->getData() << endl;
    cout << "    " << tree->root()->getLeft()->getLeft()->getData();
    cout << "    " << tree->root()->getLeft()->getRight()->getData();
    cout << "\t     " << tree->root()->getRight()->getLeft()->getData();
    cout << "    " << tree->root()->getRight()->getRight()->getData() << endl;
    cout << endl;
    
    BinarySearchTree<int>* treeCopy = new BinarySearchTree<int>(tree);// em peta aquí
    
    //Imprimim l'arbre en els diferents ordres
    tree->printPreorder();
    tree->printInorder();
    tree->printPostorder();

    
    cout << "Mida: " << tree->size() << endl;
    cout << "Búsquedes:" << endl;
    cout << tree->search(23) << endl;
    cout << tree->search(123) << endl; // los search funcionan bien
    cout << tree->search(145) << endl;
    
    cout << "Alçada:" << tree->getHeight() << endl;// alçada del arbre
    
    
    return 0;
}


