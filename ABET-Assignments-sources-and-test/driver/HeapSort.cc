
#include "Sort.h"
#include <iostream>
#include <string>

// HeapSort implementation

class Sort::ImplSort
{

  /* -----      DO NOT MODIFY ABOVE THIS LINE       ----- */
  /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
  /* vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */

private:
  struct Node
  {
    Node *left;
    Node *right;
    std::string data;
    int left_count;
    int right_count;

    Node(const std::string Data, Node *left = nullptr, Node *right = nullptr)
        : data(Data), left(left), right(right), left_count(0), right_count(0) {}

    ~Node()
    {
      delete left;
      delete right;
    }

    void heapify(Node *root)
    {
      if (root == nullptr)
      {
        return;
      }

      Node *smallest = root;
      if (root->left && root->left->data < smallest->data)
      {
        smallest = root->left;
      }
      if (root->right && root->right->data < smallest->data)
      {
        smallest = root->right;
      }
      if (smallest != root)
      {
        std::swap(root->data, smallest->data);
        heapify(smallest);
      }
    }

    Node *extractMin(Node *root)
    {
      if (root == nullptr)
      {
        return nullptr;
      }

      if (root->left == nullptr && root->right == nullptr)
      {
        delete root;
        return nullptr;
      }

      Node *minChild;
      if (root->left == nullptr)
      {
        minChild = root->right;
      }

      else if (root->right == nullptr)
      {
        minChild = root->left;
      }
      else
      {
        minChild = (root->left->data < root->right->data) ? root->left : root->right;
      }

      root->data = minChild->data;
      if (minChild == root->left)
      {
        root->left = extractMin(root->left);
        root->left_count--;
      }
      else
      {
        root->right = extractMin(root->right);
        root->right_count--;
      }

      heapify(root);
      return root;
    }

    Node *insert(const std::string &key, const std::string &value, Node *root)
    {
      if (root == nullptr)
      {
        return new Node(value);
      }
      if (root->left_count <= root->right_count)
      {
        root->left = insert(key, value, root->left);
        root->left_count++;
      }
      else
      {
        root->right = insert(key, value, root->right);
        root->right_count++;
      }

      heapify(root);
      return root;
    }

    void enumerate(std::ostream &output_file, Node *root)
    {
      while (root != nullptr)
      {
        output_file << root->data << std::endl;
        root = extractMin(root);
      }
    }
  };

  Node *root = nullptr;

public:
  void insert(const std::string &key, const std::string &value)
  {
    root = root->insert(key, value, root);
  }

  void enumerate(std::ostream &output_file)
  {
    if (root)
    {
      root->enumerate(output_file, root);
    }
  }

  Node *extractMin()
  {
    if (!root)
      return nullptr;

    Node *minNode = root;
    root = root->extractMin(root);
    return minNode;
  }
  /* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
  /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
  /* -----      DO NOT MODIFY BELOW THIS LINE       ----- */
};

Sort::Sort() : implSort_(new ImplSort) {}

Sort::~Sort()
{
  delete implSort_;
}

void Sort::insert(const std::string &key, const std::string &value)
{
  implSort_->insert(key, value);
}

void Sort::enumerate(std::ostream &output_file)
{
  implSort_->enumerate(output_file);
}
