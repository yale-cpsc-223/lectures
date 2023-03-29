#include "tree.hpp"

#include <cassert>
#include <iomanip>

#define TABW 4

enum class Kind : int
{
    LEAF = 0b00,
    LEFT_CHILD = 0b01,
    RIGHT_CHILD = 0b10,
    TWO_CHILDREN = 0b11
};

const Kind operator&(const Kind &lhs, const Kind &rhs)
{
    const Kind ans = static_cast<Kind>(static_cast<int>(lhs) & static_cast<int>(rhs));
    return ans;
}

const Kind operator|(const Kind &lhs, const Kind &rhs)
{
    const Kind ans = static_cast<Kind>(static_cast<int>(lhs) | static_cast<int>(rhs));
    return ans;
}

class BSTNode
{
public:
    const int payload;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int x) : payload(x), left(nullptr), right(nullptr) {}
    ~BSTNode()
    {
        delete this->left;
        delete this->right;
    }

    const Kind kind()
    {
        Kind n = Kind::LEAF;
        if (this->left != nullptr)
        {
            n = n | Kind::LEFT_CHILD;
        }
        if (this->right != nullptr)
        {
            n = n | Kind::RIGHT_CHILD;
        }
        return n;
    }

    void pretty_print(std::ostream &os, int indent)
    {
        bool hasRightChild = static_cast<bool>(this->kind() & Kind::RIGHT_CHILD);
        bool hasLeftChild = static_cast<bool>(this->kind() & Kind::LEFT_CHILD);

        if (hasRightChild)
        {
            this->right->pretty_print(os, indent + 1);
        }
        if (indent)
        {
            os << std::setw(indent * TABW) << ' ';
        }
        if (hasRightChild)
        {
            os << " /" << std::endl
               << std::setw(indent * TABW) << ' ';
        }
        std::cout << this->payload << std::endl
                  << ' ';
        if (hasLeftChild)
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
        case Kind::LEAF:
        {
            root = nullptr;
            break;
        }
        case Kind::LEFT_CHILD:
        {
            root = node->left;
            node->left = nullptr;
            break;
        }
        case Kind::RIGHT_CHILD:
        {
            root = node->right;
            node->right = nullptr;
            break;
        }
        case Kind::TWO_CHILDREN:
        {
            int root_val = node_min_value(node->right);
            root = new BSTNode(root_val);
            root->left = node->left;
            node->left = nullptr;
            root->right = node_remove(node->right, root_val);
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

BST::~BST()
{
    delete this->root;
}

void BST::traverse(Order order, std::function<void(int)> visit) const
{
    if (this->root == nullptr)
    {
        return;
    }
    traverse_node(this->root, order, visit);
}

size_t BST::height() const
{
    if (this->root == nullptr)
    {
        return 0;
    }
    return node_height(this->root);
}

size_t BST::size() const
{
    if (this->root == nullptr)
    {
        return 0;
    }
    return node_size(this->root);
}

bool BST::search(int x) const
{
    if (this->root == nullptr)
    {
        return false;
    }
    return node_search(this->root, x);
}

void BST::insert(int x)
{
    if (this->root == nullptr)
    {
        this->root = new BSTNode(x);
        return;
    }
    this->root = node_insert(this->root, x);
}

void BST::remove(int x)
{
    if (this->root == nullptr)
    {
        return;
    }
    this->root = node_remove(this->root, x);
}

std::ostream &operator<<(std::ostream &os, const BST *tree)
{
    if (tree->root == nullptr)
    {
        return os << std::endl;
    }
    tree->root->pretty_print(os, 0);
    return os;
}
