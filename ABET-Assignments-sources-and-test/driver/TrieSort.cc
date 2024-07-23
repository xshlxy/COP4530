
#include "Sort.h"
#include <iostream>
#include <string>

// TrieSort implementation

class Sort::ImplSort
{

  /* -----      DO NOT MODIFY ABOVE THIS LINE       ----- */
  /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
  /* vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
private:
  struct Node
  {
    bool has_data;
    int count;
    std::string data;
    Node *children[26];

    Node()
        : has_data(false), data(""), children{nullptr}, count(0) {}

    ~Node()
    {
      for (int i = 0; i < 26; ++i)
      {
        delete children[i];
      }
    }

    void insert(Node *node, const std::string &str, size_t index)
    {
      if (index == str.length() || str[index] == ' ')
      {
        node->has_data = true;
        node->data = str;
        node->count = node->count + 1;
        return;
      }

      int child_index = str[index] - 'A';
      if (child_index < 0 || child_index >= 26)
      {
        return;
      }
      if (node->children[child_index] == nullptr)
      {
        node->children[child_index] = new Node();
      }

      insert(children[child_index], str, index + 1);
    }

    void enumerate(std::ostream &output_file, std::string prefix = "")
    {
      if (has_data)
      {
        output_file << data << std::endl;
      }

      for (int i = 0; i < 26; ++i)
      {
        if (children[i] != nullptr)
        {
          char next_char = 'A' + i;
          children[i]->enumerate(output_file, prefix + next_char);
        }
      }
    }
  };
  Node *root;

public:
  ImplSort()
  {
    root = new Node();
  }

  ~ImplSort()
  {
    delete root;
  }
  void insert(const std::string &key, const std::string &value)
  {
    root->insert(root, key.substr(0, 10), 0);
  }

  void enumerate(std::ostream &output_file)
  {
    if (root)
    {
      root->enumerate(output_file);
    }
  }
};

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
/* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
/* -----      DO NOT MODIFY BELOW THIS LINE       ----- */

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
