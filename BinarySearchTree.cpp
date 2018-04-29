#include "BinarySearchTree.h"
#include "TreeNode.h"

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
    if (element == this->root()->getData()){return true;}
    else if ((element < this->root()->getData()) && (this->root()->hasLeft())){return this->search(element, this->root()->getLeft());}
    else if ((element > this->root()->getData()) && (this->root()->hasLeft())){return this->search(element, this->root()->getRight());}
    else {return false;}
}

template <class Element>
void BinarySearchTree<Element>::printInorder() const{/***/
    if (this->root()->hasLeft()){this->printInorder(this->root()->getLeft());}
    cout << this->root()->getData() << " ";
    if (this->root()->hasRight()){this->printInorder(this->root()->getRight());}
}

template <class Element>
void BinarySearchTree<Element>::printPostorder() const{/***/
    if (this->root()->hasLeft()){this->printPostorder(this->root()->getLeft());}
    if (this->root()->hasRight()){this->printPostorder(this->root()->getRight());}
    cout << this->root()->getData() << " ";
}

template <class Element>
void BinarySearchTree<Element>::printPreorder() const{/***/
    cout << this->root()->getData() << " ";
    if (this->root()->hasLeft()){this->printPreorder(this->root()->getLeft());}
    if (this->root()->hasRight()){this->printPreorder(this->root()->getRight());}
}

template <class Element>
int BinarySearchTree<Element>::getHeight() const{
    if (this->root()->isExternal()){return 0;}
    else {
        int h = 0;
        h = max(h, this->getHeight(this->root()->getLeft()), this->getHeight(this->root()->getRight()));
        return (h+1);
    }
}

template <class Element>
int BinarySearchTree<Element>::getHeight(TreeNode<Element>* p){
    if (this->p->isExternal()){return 0;}
    else{
        int h = 0;
        h = max(h, this->getHeight(this->p->getLeft(), this->p->getRight()));
        return (h+1);
    }
}

template <class Element>
void BinarySearchTree<Element>::insert(const Element& element){
    TreeNode<Element>* newNode = new TreeNode<Element>(element);
    if (element <= this->root()->getData()){
        this->insert(element, this->root()->getLeft());
    }
    else if (element > this->root()->getData()){this->inser(element, this->root()->getRight());}
}

template <class Element>
void BinarySearchTree<Element>::postDelete(TreeNode<Element>* p){}

template <class Element>
int BinarySearchTree<Element>::size(TreeNode<Element>* p) const{}

template <class Element>
void BinarySearchTree<Element>::printPreorder(TreeNode<Element>* p) const{
    cout << this->p->getData() << " ";
    if (this->p->hasLeft()){this->printPreorder(this->p->getLeft());}
    if (this->p->hasRight()){this->printPreorder(this->p->getLeft());}
}

template <class Element>
void BinarySearchTree<Element>::printPostorder(TreeNode<Element>* p) const{
    if (this->p->hasRight()){this->printPostorder(this->p->getRight());}
    if (this->p->hasLeft()){this->printPostorder(this->p->getLeft());}
    cout << this->p->getData() << " ";
}

template <class Element>
void BinarySearchTree<Element>::printInorder(TreeNode<Element>* p) const{
    if (this->p->hasLeft()){this->printInorder(this->p->getLeft());}
    cout << this->p->getData() << " ";
    if (this->p->hasRight()){this->printInorder(this->p->getRight());}
}

//Añadido
template <class Element>
bool BinarySearchTree<Element>::search(const Element& element, TreeNode<Element>* node){
    if (element == node->getData()){return true;}
    else if ((element < node->getData()) && (node->hasLeft())){return this->search(element, node->getLeft());}
    else if ((element > node->getData()) && (node->hasRight())){return this->search(element, node->getRight());}
    else {return false;}
}