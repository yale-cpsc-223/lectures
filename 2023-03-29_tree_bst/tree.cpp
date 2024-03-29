#include "tree.hpp"

#include <cassert>
#include <iomanip>

#define TABW 4

/* Enum for node "Kind"s. */
enum class Kind : int
{
    LEAF = 0b00,
    LEFT_CHILD = 0b01,
    RIGHT_CHILD = 0b10,
    TWO_CHILDREN = 0b11
};

/*
 * Returns the Kind resulting from the bitwise-and of the integer values of the two operands.
 */
const Kind operator&(const Kind &lhs, const Kind &rhs)
{
    const Kind ans = static_cast<Kind>(static_cast<int>(lhs) & static_cast<int>(rhs));
    return ans;
}

/*
 * Returns the Kind resulting from the bitwise-or of the integer values of the two operands.
 */
const Kind operator|(const Kind &lhs, const Kind &rhs)
{
    const Kind ans = static_cast<Kind>(static_cast<int>(lhs) | static_cast<int>(rhs));
    return ans;
}

/*
Class for a node in the linked BST implementation.
*/
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

    /* Reports the Kind of this node (one of LEAF, LEFT_CHILD, RIGHT_CHILD, TWO_CHILDREN).*/
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

    /*
    Pretty-prints the tree rooted at this node.
    */
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

/*
Traverse the tree rooted at node with the given order, calling function visit at each node.
 */
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

/* Reports the height of the tree rooted at node. */
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

/* Reports the number of nodes in the tree rooted at node. */
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

/* Reports where there is a node in the tree rooted at node with payload equal to x. */
bool node_search(BSTNode *node, int x)
{
    if (node == nullptr)
    {
        // We've walked off the bottom of the tree without finding x.
        return false;
    }
    if (node->payload == x)
    {
        // We found x!
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

/* Inserts the value x into the tree rooted at node, and returns the root of the tree. */
BSTNode *node_insert(BSTNode *node, int x)
{
    if (node == nullptr)
    {
        // If the tree is empty, make a new node and return it.
        return new BSTNode(x);
    }
    else
    {
        // Otherwise, decide which direction to go and insert the node in the appropriate subtree.
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
            // Do nothing if a repeat value is inserted.
        }
        return root;
    }
}

/* Reports the minimium value in the tree rooted at node.
The tree must not be empty.*/
const int node_min_value(BSTNode *node)
{
    assert(node != nullptr);
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node->payload;
}

/* Removes a node with value x from the tree rooted at node, and returns the root of the updated tree.
If x is not the value of any node in the tree, this leaves the tree unchanged.
*/
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
        // We found the value. Remove it.
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
            /* Complicated case:
                1. Find the min value in the right subtree
                2. Make a new root with that value
                3. Replace node with the new root
                4. Remove the new root from the right subtree
             */
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
    return os << '\r';
}
