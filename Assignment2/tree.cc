#include <utility>
#include <iostream>

using namespace std;

template <typename Comparable>
class binary_search_tree
{
public:
    binary_search_tree()
    {
        root = nullptr;
    }

    const Comparable &min()
    {

        // MY CODE: ------------------------------
        // if node is empty then just return nothing
        /*if (is_empty())
        {
            return nullptr;
        }*/

        // if not empty then run private function
        return min(root)->element;
        //---------------------------------------
    }

    const Comparable &max()
    {
        // MY CODE: ------------------------------
        // if node is empty then just return nothing
        /*if (is_empty())
        {
            return nullptr;
        }*/

        // if not empty then run private function
        return max(root)->element;
        //---------------------------------------
    }

    bool contains(const Comparable &x)
    {
        // MY CODE: ------------------------------
        // if node is empty then just return false
        if (is_empty())
        {
            return false;
        }

        // if not empty then run private function
        return contains(x, root);
        //---------------------------------------
    }

    bool is_empty()
    {

        // MY CODE: ------------------------------
        return is_empty(root);
        //---------------------------------------
    }

    void insert(const Comparable &x)
    {
        // MY CODE: ------------------------------
        if (is_empty())
        {
            root = new binary_node(x, nullptr, nullptr);
        }
        else
        {
            insert(x, root);
        }

        //---------------------------------------
    }

    void print()
    {
        // MY CODE: ------------------------------
        print(root, cout);
        //---------------------------------------
    }

private:
    struct binary_node
    {
        Comparable element;
        binary_node *left;
        binary_node *right;

        binary_node(const Comparable &an_element, binary_node *l, binary_node *r) : element{an_element}, left{l}, right{r} {}

        binary_node(const Comparable &&an_element, binary_node *l, binary_node *r) : element{std::move(an_element)}, left{l}, right{r} {}
    };

    binary_node *root = nullptr;

    void insert(const Comparable &x, binary_node *&t)
    {
        // MY CODE: ------------------------------
        // if node is empty then just create node
        if (t == nullptr)
        {
            t = new binary_node(x, nullptr, nullptr);
        }
        // if value x is less than node then move to the left
        else if (x < t->element)
        {
            insert(x, t->left);
        }
        // if not move it to the right
        else if (x > t->element)
        {
            insert(x, t->right);
        }

        //---------------------------------------
    }

    binary_node *min(binary_node *t)
    {
        // MY CODE: ------------------------------
        // if node is null or no left child then it's the smallest
        if (t == nullptr)
        {
            return t; // invalid
        }
        else if (t->left == nullptr)
        {
            return t;
        }
        // if not then go to left subtree and try again
        return min(t->left);
        //--------------------------------------
    }

    binary_node *max(binary_node *t)
    {
        // MY CODE: ------------------------------
        // if node is null or no right child then it's the smallest
        if (t == nullptr)
        {
            return nullptr; // invalid
        }
        else if (t->right == nullptr)
        {
            return t;
        }
        // if not then go to right subtree and try again
        return max(t->right);
        //--------------------------------------
    }

    bool is_empty(binary_node *t)
    {
        // MY CODE: ------------------------------
        // return true or false if empty
        return t == nullptr;
        //--------------------------------------
    }

    bool contains(const Comparable &x, binary_node *t)
    {
        // MY CODE: ------------------------------
        // if empty return false
        if (is_empty(t))
        {
            return false;
        }

        // search recursively in the l or r subtree
        else if (x < t->element)
        {
            return contains(x, t->left);
        }
        else if (x > t->element)
        {
            return contains(x, t->right);
        }

        // if value is the current node return true
        else
        {
            return true;
        }
        //--------------------------------------
    }

    void print(binary_node *t, ostream &out)
    {
        // MY CODE: ------------------------------
        if (!(is_empty(t)))
        {
            // print the left, middle, and then right (in-order)
            print(t->left, out);
            out << t->element << endl;
            print(t->right, out);
        }

        //--------------------------------------
    }
};

int main()
{
    binary_search_tree<int> bst;
    int x;

    while (cin >> x)
    {
        bst.insert(x);
    }

    bst.print();
    cout << "Minimal element = " << bst.min() << "\n";
    cout << "Maximal element = " << bst.max() << "\n";
}
