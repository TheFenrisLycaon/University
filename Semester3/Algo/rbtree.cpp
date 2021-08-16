#include <bits/stdc++.h>
using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;
    Node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
        this->color = RED;
    }
};

class redBlackTree
{
private:
    Node *root;

protected:
    void rotLeft(Node *&, Node *&);
    void rotRight(Node *&, Node *&);
    void fixVio(Node *&, Node *&);

public:
    redBlackTree() { root = NULL; }
    void insert(const int &n);
    void inOrder();
    void levelOrder();
};

void inOrderHelp(Node *root)
{
    if (root == NULL)
        return;
    inOrderHelp(root->left);
    cout << root->data << " ";
    inOrderHelp(root->right);
}

Node *insertBST(Node *root, Node *pt)
{
    if (root == NULL)
        return pt;
    if (pt->data < root->data)
    {
        root->left = insertBST(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = insertBST(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

void levelOrderHelp(Node *root)
{
    if (root == NULL)
        return;
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void redBlackTree::rotLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != NULL)
        pt->right->parent = pt;
    pt_right->parent = pt->parent;
    if (pt->parent == NULL)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;
    pt_right->left = pt;
    pt->parent = pt_right;
}

void redBlackTree::rotRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;
    pt->left = pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;
    pt_left->parent = pt->parent;
    if (pt->parent == NULL)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;
    pt_left->right = pt;
    pt->parent = pt_left;
}

void redBlackTree::fixVio(Node *&root, Node *&pt)
{
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;
    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
        if (parent_pt == grand_parent_pt->left)
        {
            Node *uncle_pt = grand_parent_pt->right;
            if (uncle_pt != NULL && uncle_pt->color ==
                                        RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->right)
                {
                    rotLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotRight(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        else
        {
            Node *uncle_pt = grand_parent_pt->left;
            if ((uncle_pt != NULL) && (uncle_pt->color ==
                                       RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    rotRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotLeft(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

void redBlackTree::insert(const int &data)
{
    Node *pt = new Node(data);
    root = insertBST(root, pt);
    fixVio(root, pt);
}

void redBlackTree::inOrder()
{
    inOrderHelp(root);
}
void redBlackTree::levelOrder()
{
    levelOrderHelp(root);
}

int main()
{
    redBlackTree tree;
    tree.insert(8);
    tree.insert(18);
    tree.insert(5);
    tree.insert(15);
    tree.insert(17);
    tree.insert(25);
    tree.insert(40);
    cout << "Inoder Traversal of Created Tree\n";
    tree.inOrder();
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    return 0;
}
