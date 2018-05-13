#ifndef TREENODE_H
#define TREENODE_H

template <class Element>
class TreeNode {
public:

    TreeNode(const Element& value, const int key);//CANVIAT
    virtual ~TreeNode();
    
    const Element& getValue() const;//CANVIAT
    const int& getKey() const; //NOU
    void setValue(Element element); //CANVIAT
    void setKey(int key);// NOU
    TreeNode* getRight() const;
    TreeNode* getLeft() const;
    TreeNode* getParent() const;
    void setRight(TreeNode* right);
    void setLeft(TreeNode* left);
    void setParent(TreeNode* parent);
    bool isRoot() const;
    bool isExternal() const;
    int getHeight() const;
    void setHeight(int h);
    bool hasRight() const;
    bool hasLeft() const;
private:
    Element value;
    int key; //NOU
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int height;
};

#endif /* TREENODE_H */
