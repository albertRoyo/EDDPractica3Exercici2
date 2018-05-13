#include <iostream>
#include <vector> 
#include "BinarySearchTree.h"


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
    cout << p->getValue() << " ";
    if (p->hasLeft()) this->printPreorder(p->getLeft());
    if (p->hasRight()) this->printPreorder(p->getRight());
}

//Funció pública
template <class Element>
//retornme un vector d'Elements ja que des d'aquesta funció no podem cridar al toString de Movie
vector<Element> BinarySearchTree<Element>::printInorder() {
    vector<Element> v;
    printInorder(this->root(), v);
    return v;
}
//Funció privada
template <class Element>
void BinarySearchTree<Element>::printInorder(TreeNode<Element>* p, vector<Element>& v) {
    if (p->hasLeft()){this->printInorder(p->getLeft(), v);}
    v.insert(p->getValue());
    if (p->hasRight()){this->printInorder(p->getRight(), v);}
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
    cout << p->getValue() << " ";
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

//CAMBIAT: Ara busquem per key i retornem un punter al node que contingui key, sinó està key, retornem un nullptr
template <class Element>
TreeNode<Element>* BinarySearchTree<Element>::search(const int key){
    return this->search(key, this->root());
}
template <class Element>
TreeNode<Element>* BinarySearchTree<Element>::search(const int key, TreeNode<Element>* node){
    if (key == node->getKey()){return node;}
    else if ((key < node->getKey()) && (node->hasLeft())){
        return this->search(key, node->getLeft());
    }
    else if ((key > node->getKey()) && (node->hasRight())){
        return this->search(key, node->getRight());
    }
    else return nullptr;
}

//Funció pública
template <class Element>
void BinarySearchTree<Element>::insert(const Element& element, const int key){
    //Mirem el cas on el nostre arbre és completament vuit
    if (this->root() == nullptr){
        TreeNode<Element>* newNode = new TreeNode<Element>(element, key);
        this->proot = newNode;
        this->contadorNodes++;
    }
    //sinò, cridem a la funció privada
    else this->insert(element, key, this->root()); 
}
//Funció privada
template <class Element>
void BinarySearchTree<Element>::insert(const Element& element, const int key, TreeNode<Element>* node){
    if (key <= node->getKey()){
        if (node->hasLeft()) this->insert(element, key, node->getLeft());
        else {
            TreeNode<Element>* newNode = new TreeNode<Element>(element, key);
            node->setLeft(newNode);
            newNode->setParent(node);
            this->contadorNodes++;
        }
    } else {
        if (node->hasRight()) this->insert(element, key, node->getRight());
        else{
            TreeNode<Element>* newNode = new TreeNode<Element>(element, key);
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
