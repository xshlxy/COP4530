
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

    Node(const std::string Data, Node *left = nullptr, Node *right = nullptr)
    {
      data = Data;
      left = nullptr;
      right = nullptr;
    }

    ~Node()
    {
      delete left;
      delete right;
    }

    void insert(const std::string &value)
    {
      if (value < data)
      {
        if (left)
        {
          left->insert(value);
          if (left->data > data)
          {
            std::swap(left->data, data);
          }
        }
        else
        {
          left = new Node(value);
        }
      }
      else
      {
        if (right)
        {
          right->insert(value);
          if (right->data > data)
          {
            std::swap(right->data, data);
          }
        }
        else
        {
          right = new Node(value);
        }
      }
    }

    void heapify()
    {
      Node *largest = this;
      if (left && left->data > largest->data)
      {
        largest = left;
      }
      if (right && right->data > largest->data)
      {
        largest = right;
      }
      if (largest != this)
      {
        std::swap(data, largest->data);
        largest->heapify();
      }
    }

    void heapSort()
    {
      if (!left && !right)
        return;
      heapify();
      if (left)
        left->heapSort();
      if (right)
        right->heapSort();
    }

    void enumerate(std::ostream &output_file)
    {
      if (left)
        left->enumerate(output_file);
      output_file << data << "\n";
      if (right)
        right->enumerate(output_file);
    }
  };

  Node *root = nullptr;

public:
  void insert(const std::string &key, const std::string &value)
  {
    if (root == nullptr)
    {
      root = new Node(value, nullptr, nullptr);
    }
    else
      root->insert(value);
  }
  void enumerate(std::ostream &output_file)
  {
    if (root)
    {
      root->heapSort();
      root->enumerate(output_file);
    }
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
