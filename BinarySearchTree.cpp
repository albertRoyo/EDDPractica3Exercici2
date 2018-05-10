#include <iostream>
#include "BinarySearchTree.h"
#include "TreeNode.h"

using namespace std;

template <class Element>
BinarySearchTree<Element>::BinarySearchTree() {this->proot = nullptr;}

//em dona segmentation fault
template <class Element>
BinarySearchTree<Element>::BinarySearchTree(const BinarySearchTree* orig) {
    if (!orig->isEmpty()){
        TreeNode<Element>* newNode = new TreeNode<Element>(orig->root()->getData());
        BinarySearchTree<Element> newTree = new BinarySearchTree();
        newTree.proot = newNode;
                        cout<<"hh"<<endl;

        copy(newNode,orig->root());//al cridar aixó
        newNode->setParent(nullptr);
    }
}
template <class Element>
void BinarySearchTree<Element>::copy(TreeNode<Element>* dest, const TreeNode<Element>* orig) {
    
    dest->setData(orig->getData());
    copy(dest->getLeft(),orig->getLeft());
    copy(dest->getRight(),orig->getRight());
    if (dest->hasLeft()) dest->getLeft()->setParent(dest);
    if (dest->hasRight()) dest->getRight()->setParent(dest);
 }

//falta fer el mirror

template <class Element>
BinarySearchTree<Element>::~BinarySearchTree() {}

template <class Element>
bool BinarySearchTree<Element>::isEmpty() const{return (this->root() == nullptr);}

template <class Element>
TreeNode<Element>* BinarySearchTree<Element>::root() const{return this->proot;}

template <class Element>
int BinarySearchTree<Element>::size() const{
    return this->contadorNodes; //O(1)
}

template <class Element>
int BinarySearchTree<Element>::size(TreeNode<Element>* p) const{}

//Funció pública
template <class Element>
void BinarySearchTree<Element>::printPreorder() const{
    cout << "Preordre = {";
    printPreorder(this->root());
    cout << '}';
    cout << endl;
}
//Funció privada
template <class Element>
void BinarySearchTree<Element>::printPreorder(TreeNode<Element>* p) const{
    cout << p->getData() << " ";
    if (p->hasLeft()) this->printPreorder(p->getLeft());
    if (p->hasRight()) this->printPreorder(p->getRight());
}

//Funció pública
template <class Element>
void BinarySearchTree<Element>::printInorder() const{
    cout << "Inordre = {";
    printInorder(this->root());
    cout << '}';
    cout << endl;
}
//Funció privada
template <class Element>
void BinarySearchTree<Element>::printInorder(TreeNode<Element>* p) const{
    if (p->hasLeft()){this->printInorder(p->getLeft());}
    cout << p->getData() << " ";
    if (p->hasRight()){this->printInorder(p->getRight());}
}

//Funció pública
template <class Element>
void BinarySearchTree<Element>::printPostorder() const{
    cout << "Postordre = {";
    printPostorder(this->root());
    cout << '}';
    cout << endl;
}
//Funció privada
template <class Element>
void BinarySearchTree<Element>::printPostorder(TreeNode<Element>* p) const{
    if (p->hasRight()){this->printPostorder(p->getLeft());}
    if (p->hasLeft()){this->printPostorder(p->getRight());}
    cout << p->getData() << " ";
}

//Funció pública
template <class Element>
int BinarySearchTree<Element>::getHeight(){
    getHeight(this->root());
}
//Funció privada
template <class Element>
int BinarySearchTree<Element>::getHeight(TreeNode<Element>* node){
    TreeNode<Element>* arrel = node;
    if (node->isExternal()) return 0;
    else {
        return max(this->getHeight(node->getLeft()), this->getHeight(node->getRight())) + 1;
    }
}


template <class Element>
bool BinarySearchTree<Element>::search(const Element& element){
    this->search(element, this->root());
}
template <class Element>
bool BinarySearchTree<Element>::search(const Element& element, TreeNode<Element>* node){
    if (element == node->getData()){return true;}
    else if ((element < node->getData()) && (node->hasLeft())){
        return this->search(element, node->getLeft());
    }
    else if ((element > node->getData()) && (node->hasRight())){
        return this->search(element, node->getRight());
    }
    else return false;
}

//Funció pública
template <class Element>
void BinarySearchTree<Element>::insert(const Element& element){
    //Mirem el cas on el nostre arbre és completament vuit
    if (this->root() == nullptr){
        TreeNode<Element>* newNode = new TreeNode<Element>(element);
        this->proot = newNode;
        this->contadorNodes++;
    }
    //sinò, cridem a la funció privada
    else this->insert(element, this->root()); 
}
//Funció privada
template <class Element>
void BinarySearchTree<Element>::insert(const Element& element, TreeNode<Element>* node){
    if (element <= node->getData()){
        if (node->hasLeft()) this->insert(element, node->getLeft());
        else {
            TreeNode<Element>* newNode = new TreeNode<Element>(element);
            node->setLeft(newNode);
            newNode->setParent(node);
            this->contadorNodes++;
        }
    } else {
        if (node->hasRight()) this->insert(element, node->getRight());
        else{
            TreeNode<Element>* newNode = new TreeNode<Element>(element);
            node->setRight(newNode);
            newNode->setParent(node);
            this->contadorNodes++;
        }
    }
}

template <class Element>
void BinarySearchTree<Element>::postDelete(TreeNode<Element>* p){ //acabar d'arreglar
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
