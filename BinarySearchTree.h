#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

template <class Element>
class BinarySearchTree {
public:
    
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree* orig);
    void copy(TreeNode<Element>* dest, const TreeNode<Element>* orig);
    virtual ~BinarySearchTree();
    
    int size() const;
    bool isEmpty() const;
    TreeNode<Element>* root() const; //añadido el const
    bool search(const Element& element);
    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;
    int getHeight();
    void insert(const Element& element);

private:
    
    void postDelete(TreeNode<Element>* p);
    int size(TreeNode<Element>* p) const;
    void printPreorder(TreeNode<Element>* p) const;
    void printPostorder(TreeNode<Element>* p) const;
    void printInorder(TreeNode<Element>* p) const;
    int getHeight(TreeNode<Element>* p);
    bool search(const Element& element, TreeNode<Element>* node);
    void insert(const Element& element, TreeNode<Element>* node);
    int contadorNodes;
    TreeNode<Element>* proot;
    
};

#endif /* BINARYSEARCHTREE_H */

