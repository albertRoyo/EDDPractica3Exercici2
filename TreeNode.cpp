#include "TreeNode.h"

template <class Element>
TreeNode<Element>::TreeNode(const Element& value, const int key){
    this->value = value;
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template <class Element>
TreeNode<Element>::~TreeNode() {/**Destructor*/}

template <class Element>
const Element& TreeNode<Element>::getValue() const{return this->value;}

template <class Element>
const int& TreeNode<Element>::getKey() const{return this->key;}

template <class Element>
void TreeNode<Element>::setValue(Element element){this->value = element;}

template <class Element>
void TreeNode<Element>::setKey(int key){this->key = key;}

template <class Element>
TreeNode<Element>* TreeNode<Element>::getRight() const{return this->right;}

template <class Element>
TreeNode<Element>* TreeNode<Element>::getLeft() const{return this->left;}

template <class Element>
TreeNode<Element>* TreeNode<Element>::getParent() const{return this->parent;}

template <class Element>
void TreeNode<Element>::setLeft(TreeNode* left){this->left = left;}

template <class Element>
void TreeNode<Element>::setRight(TreeNode* right){this->right = right;}

template <class Element>
void TreeNode<Element>::setParent(TreeNode* parent){this->parent = parent;}

template <class Element>
bool TreeNode<Element>::isRoot() const{return this->parent == nullptr;}

template <class Element>
bool TreeNode<Element>::isExternal() const{return !(this->hasLeft() && this->hasRight());}

template <class Element>
int TreeNode<Element>::getHeight() const{return this->height;}

template <class Element>
void TreeNode<Element>::setHeight(int h){this->height = height;}

template <class Element>
bool TreeNode<Element>::hasLeft() const{return !(this->left == nullptr);}

template <class Element>
bool TreeNode<Element>::hasRight() const{return !(this->right == nullptr);}
