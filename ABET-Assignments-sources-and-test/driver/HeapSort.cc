
#include "Sort.h"
#include <iostream>
#include <string>

// HeapSort implementation

class Sort::ImplSort
{

  /* -----      DO NOT MODIFY ABOVE THIS LINE       ----- */
  /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
  /* vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */

  /* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
  /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
  /* -----      DO NOT MODIFY BELOW THIS LINE       ----- */

};


Sort::Sort() : implSort_(new ImplSort) {}

Sort::~Sort()
{
  delete implSort_;
}

void Sort::insert(const std::string & key, const std::string & value)
{
  implSort_->insert(key,value);
}

void Sort::enumerate(std::ostream& output_file)
{
  implSort_->enumerate(output_file);
}
