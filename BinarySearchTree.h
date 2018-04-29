#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

template <class Element>
class BinarySearchTree {
public:
    
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& orig);
    virtual ~BinarySearchTree();
    
    int size() const;
    bool isEmpty() const;
    TreeNode<Element>* root();
    bool search(const Element& element);
    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;
    int getHeight() const;
    void insert(const Element& element);
    
private:
    
    void postDelete(TreeNode<Element>* p);
    int size(TreeNode<Element>* p) const;
    void printPreorder(TreeNode<Element>* p) const;
    void printPostorder(TreeNode<Element>* p) const;
    void printInorder(TreeNode<Element>* p) const;
    int getHeight(TreeNode<Element>* p);

    //Añadido
    bool search(const Element& element, TreeNode<Element>* node);
    
    TreeNode<Element>* proot;
    
};

#endif /* BINARYSEARCHTREE_H */

