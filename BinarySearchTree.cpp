#include <iostream>
#include "BinarySearchTree.h"
#include "TreeNode.h"

using namespace std;

template <class Element>
BinarySearchTree<Element>::BinarySearchTree() {this->proot = nullptr;}

template <class Element>
BinarySearchTree<Element>::BinarySearchTree(const BinarySearchTree& orig) {}

template <class Element>
BinarySearchTree<Element>::~BinarySearchTree() {}

template <class Element>
int BinarySearchTree<Element>::size() const{
    //Reemplazar por un contador en BinaryTree que guarde cuantos nodos existen.
    //Se actualiza cuando se inserta o elimina un nodo
//    int size = 1;
//    int sizeLeft = 0;
//    int sizeRight = 0;
//    if (this->root()->hasLeft()){sizeLeft = this->size(this->root()->getLeft());}
//    if (this->root()->hasRight()){sizeRight = this->size(this->root()->getRight());}
//    return (size+sizeLeft+sizeRight);
    return this->contadorNodes; //O(1)
}

template <class Element>
bool BinarySearchTree<Element>::isEmpty() const{return (this->root() == nullptr);}

template <class Element>
TreeNode<Element>* BinarySearchTree<Element>::root() const{return this->proot;}

template <class Element>
bool BinarySearchTree<Element>::search(const Element& element){
    if (element == this->root()->getData()){return true;}
    else if ((element < this->root()->getData()) && (this->root()->hasLeft())){return this->search(element, this->root()->getLeft());}
    else if ((element > this->root()->getData()) && (this->root()->hasLeft())){return this->search(element, this->root()->getRight());}
    else {return false;}
}

template <class Element>
void BinarySearchTree<Element>::printInorder() const{/***/
    if (this->root()->hasLeft()){printInorder(this->root()->getLeft());}
    cout << this->root()->getData() << " ";
    if (this->root()->hasRight()){printInorder(this->root()->getRight());}
    cout << endl;
}

template <class Element>
void BinarySearchTree<Element>::printPostorder() const{/***/
    if (this->root()->hasLeft()){this->printPostorder(this->root()->getLeft());}
    if (this->root()->hasRight()){this->printPostorder(this->root()->getRight());}
    cout << this->root()->getData() << " ";
    cout << endl;
}

template <class Element>
void BinarySearchTree<Element>::printPreorder() const{/***/
    cout << this->root()->getData() << " ";
    if (this->root()->hasLeft()){this->printPreorder(this->root()->getLeft());}
    if (this->root()->hasRight()){this->printPreorder(this->root()->getRight());}
    cout << endl;
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
int BinarySearchTree<Element>::getHeight(TreeNode<Element>* node){
    if (node->isExternal()){return 0;}
    else{
        int h = 0;
        h = max(h, this->getHeight(node->getLeft(), node->getRight()));
        return (h+1);
    }
}

template <class Element>
void BinarySearchTree<Element>::insert(const Element& element){
    if (this->root() == nullptr){
        TreeNode<Element>* newNode = new TreeNode<Element>(element);
        this->proot = newNode;
        this->contadorNodes++;
    } else if (element <= this->root()->getData()){
        if (this->root()->hasLeft()){this->insert(element, this->root()->getLeft());}
        else{
            TreeNode<Element>* newNode = new TreeNode<Element>(element);
            this->root()->setLeft(newNode);
            newNode->setParent(this->root());
            this->contadorNodes++;
        }
    } else {
        if (this->root()->hasRight()){this->insert(element, this->root()->getRight());}
        else{
            TreeNode<Element>* newNode = new TreeNode<Element>(element);
            this->root()->setRight(newNode);
            newNode->setParent(this->root());
            this->contadorNodes++;
        }
    }
}

template <class Element>
void BinarySearchTree<Element>::postDelete(TreeNode<Element>* p){
    if ((p->hasLeft()) && (p->hasRight())){p->setParent(nullptr);delete p;}
    else if ((p->hasLeft()) && !(p->hasRight())){
        if(p->getParent()->getLeft() == p){
            p->getParent()->setLeft(p->getLeft());
            p->getLeft()->setParent(p->getParent());
            delete p;
        }else if(p->getParent()->getRight() == p){
            p->getParent()->setRight(p->getLeft());
            p->getLeft()->setParent(p->getParent());
            delete p;
        }
    }else if ((p->hasRight()) && !(p->hasLeft())){
        if(p->getParent()->getLeft() == p){
            p->getParent()->setLeft(p->getRight());
            p->getRight()->setParent(p->getParent());
            delete p;
        }else if(p->getParent()->getRight() == p){
            p->getParent()->setRight(p->getRight());
            p->getRight()->setParent(p->getParent());
            delete p;
        }
    }else{
        TreeNode<Element> succesor = p->getRight();
        while (succesor->hasLeft()){
            succesor = succesor->getLeft();
        }
        p->setData(succesor->getData());
        succesor->getParent();
    }

}

template <class Element>
int BinarySearchTree<Element>::size(TreeNode<Element>* p) const{}

template <class Element>
void BinarySearchTree<Element>::printPreorder(TreeNode<Element>* p) const{
    cout << p->getData() << " ";
    if (p->hasLeft()){this->printPreorder(p->getLeft());}
    if (p->hasRight()){this->printPreorder(p->getLeft());}
}

template <class Element>
void BinarySearchTree<Element>::printPostorder(TreeNode<Element>* p) const{
    if (p->hasRight()){this->printPostorder(p->getRight());}
    if (p->hasLeft()){this->printPostorder(p->getLeft());}
    cout << p->getData() << " ";
}

template <class Element>
void BinarySearchTree<Element>::printInorder(TreeNode<Element>* p) const{
    if (p->hasLeft()){this->printInorder(p->getLeft());}
    cout << p->getData() << " ";
    if (p->hasRight()){this->printInorder(p->getRight());}
}

//Añadido ////////////////////////////////////////////////////////////////////////////////////////////////////
template <class Element>
bool BinarySearchTree<Element>::search(const Element& element, TreeNode<Element>* node){
    if (element == node->getData()){return true;}
    else if ((element < node->getData()) && (node->hasLeft())){return this->search(element, node->getLeft());}
    else if ((element > node->getData()) && (node->hasRight())){return this->search(element, node->getRight());}
    else {return false;}
}

template <class Element>
void BinarySearchTree<Element>::insert(const Element& element, TreeNode<Element>* node){
    if (element <= node->getData()){
        if (node->hasLeft()){this->insert(element, node->getLeft());}
        else{
            TreeNode<Element>* newNode = new TreeNode<Element>(element);
            node->setLeft(newNode);
            newNode->setParent(node);
            this->contadorNodes++;
        }
    }else{
        if (node->hasRight()){this->insert(element, node->getRight());}
        else{
            TreeNode<Element>* newNode = new TreeNode<Element>(element);
            node->setRight(newNode);
            newNode->setParent(node);
            this->contadorNodes++;
        }
    }
}