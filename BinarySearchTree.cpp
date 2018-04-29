#include "BinarySearchTree.h"

template <class Element>
BinarySearchTree<Element>::BinarySearchTree() {this->proot = nullptr;}

template <class Element>
BinarySearchTree<Element>::BinarySearchTree(const BinarySearchTree& orig) {}

template <class Element>
BinarySearchTree<Element>::~BinarySearchTree() {}

template <class Element>
int BinarySearchTree<Element>::size() const{
    int size = 1;
    int sizeLeft = 0;
    int sizeRight = 0;
    if (this->root()->hasLeft()){sizeLeft = this->size(this->root()->getLeft());}
    if (this->root()->hasRight()){sizeRight = this->size(this->root()->getRight());}
    return (size+sizeLeft+sizeRight);
}

template <class Element>
bool BinarySearchTree<Element>::isEmpty() const{return (this->root() == nullptr);}

template <class Element>
TreeNode<Element>* BinarySearchTree<Element>::root() {return this->proot;}

template <class Element>
bool BinarySearchTree<Element>::search(const Element& element){
    //
}

template <class Element>
void BinarySearchTree<Element>::printInorder() const{/***/}

template <class Element>
void BinarySearchTree<Element>::printPostorder() const{/***/}

template <class Element>
void BinarySearchTree<Element>::printPreorder() const{/***/}

template <class Element>
int BinarySearchTree<Element>::getHeight() const{}

template <class Element>
int BinarySearchTree<Element>::getHeight(TreeNode<Element>* p){}

template <class Element>
void BinarySearchTree<Element>::insert(const Element& element){}

template <class Element>
void BinarySearchTree<Element>::postDelete(TreeNode<Element>* p){}

template <class Element>
int BinarySearchTree<Element>::size(TreeNode<Element>* p) const{}

template <class Element>
void BinarySearchTree<Element>::printPreorder(TreeNode<Element>* p) const{}

template <class Element>
void BinarySearchTree<Element>::printPostorder(TreeNode<Element>* p) const{}

template <class Element>
void BinarySearchTree<Element>::printInorder(TreeNode<Element>* p) const{}