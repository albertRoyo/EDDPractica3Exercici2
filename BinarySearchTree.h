#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <vector>

#include "TreeNode.h"

using namespace std;

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
    TreeNode<Element>* search(const int key);//CAMBIAT: busquem l'element per la key, i no pel propi element
    vector<Element> printInorder();//CAMBIAT: retornem un vector d'elements enlloc d'imprimir directament
    void printPreorder() const;
    void printPostorder() const;
    int getHeight();
    void insert(const Element& element, const int key);//CAMBIAT: inserim l'element per la key, i no pel propi element

private:
    
    void postDelete(TreeNode<Element>* p);
    int size(TreeNode<Element>* p) const;
    TreeNode<Element>* search(const int key, TreeNode<Element>* p);
    void printPreorder(TreeNode<Element>* p) const;
    void printPostorder(TreeNode<Element>* p) const;
    void printInorder(TreeNode<Element>* p, vector<Element>& v);
    int getHeight(TreeNode<Element>* p);
    void insert(const Element& element, const int key, TreeNode<Element>* node);
    int contadorNodes;
    TreeNode<Element>* proot;
    
    
};

#endif /* BINARYSEARCHTREE_H */
