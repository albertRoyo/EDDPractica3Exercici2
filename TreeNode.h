#ifndef TREENODE_H
#define TREENODE_H

template <class Element>
class TreeNode {
public:

    TreeNode(const Element& data);
    virtual ~TreeNode();
    
    const Element& getData() const;
    void setData(Element element);
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
    Element data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int height;
};

#endif /* TREENODE_H */

