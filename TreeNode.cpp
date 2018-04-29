#include "TreeNode.h"

template <class Element>
TreeNode<Element>::TreeNode(const Element& data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template <class Element>
TreeNode<Element>::~TreeNode() {/**Destructor*/}

template <class Element>
const Element& TreeNode<Element>::getData() const{return this->data;}

template <class Element>
void TreeNode<Element>::setData(Element element){this->data = element;}

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
bool TreeNode<Element>::isRoot() const{return this->parent = nullptr;}

template <class Element>
bool TreeNode<Element>::isExternal() const{return (this->right = nullptr || this->left = nullptr);}

template <class Element>
int TreeNode<Element>::getHeight() const{return this->height;}

template <class Element>
void TreeNode<Element>::setHeight(int h){this->height = height;}

template <class Element>
bool TreeNode<Element>::hasLeft() const{return !(this->left = nullptr);}

template <class Element>
bool TreeNode<Element>::hasRight() const{return !(this->right = nullptr);}
