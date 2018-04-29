#include <iostream>

#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "TreeNode.h"
#include "TreeNode.cpp"

using namespace std;

int main() {
    
    TreeNode<int>* node1 = new TreeNode<int>(4);
    TreeNode<int>* node2 = new TreeNode<int>(5);
    node2->setParent(node1);
    cout << node2->getParent()->getData() << endl;

    return 0;
}

