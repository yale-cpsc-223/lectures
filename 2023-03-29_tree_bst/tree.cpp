#include "tree.hpp"

#include <iomanip>
#include <string>

#define TABW 4

enum Kind : int
{
    LEAF = 0b00,
    LEFT_CHILD = 0b01,
    RIGHT_CHILD = 0b10,
    TWO_CHILDREN = 0b11
};

const Kind operator&(const Kind &lhs, const Kind &rhs)
{
    const Kind ans = Kind((int)lhs & (int)rhs);
    return ans;
}

class BSTNode
{
public:
    const int payload;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int x) : payload(x), left(nullptr), right(nullptr) {}

    const Kind kind()
    {
        Kind n = LEAF;
        if (this->left != nullptr)
        {
            n = n & Kind::LEFT_CHILD;
        }
        if (this->right != nullptr)
        {
            n = n & Kind::RIGHT_CHILD;
        }
        return n;
    }

    void pretty_print(std::ostream &os, int indent)
    {
        if (this->right != nullptr)
        {
            this->right->pretty_print(os, indent + 1);
        }
        if (indent)
        {
            os << std::setw(indent * TABW) << ' ';
        }
        if (this->right != nullptr)
        {
            os << " /" << std::endl
               << std::setw(indent * TABW) << ' ';
        }
        std::cout << this->payload << std::endl
                  << ' ';
        if (this->left != nullptr)
        {
            std::cout << std::setw(indent * TABW) << ' ' << " \\" << std::endl;
            this->left->pretty_print(os, indent + 1);
        }
    }
};

void traverse_node(BSTNode *node, Order order, std::function<void(int)> visit)
{
    if (node != nullptr)
    {
        switch (order)
        {
        case IN_ORDER:
            traverse_node(node->left, order, visit);
            visit(node->payload);
            traverse_node(node->right, order, visit);
            break;

        case PRE_ORDER:
            visit(node->payload);
            traverse_node(node->left, order, visit);
            traverse_node(node->right, order, visit);
            break;

        case POST_ORDER:
            traverse_node(node->left, order, visit);
            traverse_node(node->right, order, visit);
            visit(node->payload);
            break;
        }
    }
}

size_t node_height(BSTNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        size_t lheight = node_height(node->left);
        size_t rheight = node_height(node->right);
        return 1 + (lheight > rheight ? lheight : rheight);
    }
}

size_t node_size(BSTNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        size_t lsize = node_size(node->left);
        size_t rsize = node_size(node->right);

        return 1 + lsize + rsize;
    }
}

bool node_search(BSTNode *node, int x)
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->payload == x)
    {
        return true;
    }
    else if (x < node->payload)
    {
        return node_search(node->left, x);
    }
    else
    {
        return node_search(node->right, x);
    }
}

BSTNode *node_insert(BSTNode *node, int x)
{
    if (node == nullptr)
    {
        return new BSTNode(x);
    }
    else
    {
        BSTNode *root = node;
        if (x < node->payload)
        {
            root->left = node_insert(node->left, x);
        }
        else if (x > node->payload)
        {
            root->right = node_insert(node->right, x);
        }
        else
        {
            assert(false);
        }
        return root;
    }
}

const int node_min_value(BSTNode *node)
{
    assert(node != nullptr);
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node->payload;
}

BSTNode *node_remove(BSTNode *node, int x)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (x < node->payload)
    {
        node->left = node_remove(node->left, x);
        return node;
    }
    else if (x > node->payload)
    {
        node->right = node_remove(node->right, x);
        return node;
    }
    else
    {
        BSTNode *root = node;
        switch (node->kind())
        {
        case LEAF:
        {
            root = nullptr;
            break;
        }
        case LEFT_CHILD:
        {
            root = node->left;
            node->left = nullptr;
            break;
        }
        case RIGHT_CHILD:
        {
            root = node->right;
            node->right = nullptr;
            break;
        }
        case TWO_CHILDREN:
        {
            int root_val = node_min_value(node->right);
            root = new BSTNode(root_val);
            root->left = node->left;
            root->right = node_remove(node->right, root->payload);
            node->left = nullptr;
            node->right = nullptr;
            break;
        }
        }
        delete node;
        return root;
    }
}
BST::BST() : root(nullptr) {}

BST::BST(std::istream &in) : BST::BST()
{
    int val;
    while (in >> val)
    {
        this->insert(val);
    }
}

BST::~BST() = default;

void BST::traverse(Order order, std::function<void(int)> visit) const
{
    traverse_node(this->root, order, visit);
}

size_t BST::height() const
{
    return node_height(this->root);
}

size_t BST::size() const
{
    return node_size(this->root);
}

bool BST::search(int x) const
{
    return node_search(this->root, x);
}

void BST::insert(int x)
{
    if (this->root == nullptr)
    {
        this->root = new BSTNode(x);
    }
    else
    {
        BSTNode *new_root = node_insert(this->root, x);
        assert(new_root == this->root);
    }
}

void BST::remove(int x)
{
    if (this->root != nullptr)
    {
        node_remove(this->root, x);
    }
}

std::ostream &operator<<(std::ostream &os, const BST *tree)
{
    if (tree->root != nullptr)
    {
        tree->root->pretty_print(os, 0);
    }
    else
    {
        os << std::endl;
    }
    return os;
}
