#include <utility>
#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

template <typename Comparable>
class quicksort
{
public:
    uint32_t next; // points at next available node

    quicksort()
    {
        next = 0;
    }

    void insert(const Comparable &x)
    {
        /*

          YOUR CODE GOES HERE

         */
    }

    void print()
    {
        /*

          YOUR CODE GOES HERE

         */
    }

    void reserve(uint32_t size)
    {
        /*

          YOUR CODE GOES HERE

         */
    }

    uint32_t quantity()
    {
        /*

          YOUR CODE GOES HERE

         */
    }

    void sort()
    {
        /*

          YOUR CODE GOES HERE

         */
    }

private:
    vector<Comparable> q;

    void quicksort_insert(const Comparable &x)
    {
        // MY CODE
    }

    void quicksort_print()
    {
        /*

          YOUR CODE GOES HERE

         */
    }

    void quicksort_reserve(uint32_t size)
    {
        /*

          YOUR CODE GOES HERE

         */
    }

    uint32_t quicksort_quantity()
    {
        /*

          YOUR CODE GOES HERE

         */
    }

    void quicksort_sort(uint32_t start, uint32_t end)
    {
        /*

          YOUR CODE GOES HERE

         */
        uint32_t i = start, j = end;
        uint32_t tmp;
        uint32_t arr[];

        // printf("quickSort(left = %d, right = %d, pivot = %d)\n",left,right,
        // pivot);

        /* partition */

        /* recursion */

        if (left < j)
            quickSort(left, j, arr);
        if (i < right)
            quickSort(i, right, arr);
    }

    //  ----------------------
    //
    //  Helper functions
    //
    //

    // Returns the pivot point's index

    uint32_t partition(uint32_t start, uint32_t end)
    {

        uint32_t arr[];
        uint32_t pivot = arr[(start + end) / 2];
        while (i <= j)
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;

            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];

                arr[j] = tmp;
                i++;
                j--;
            }
        }

        return pivot;
    }
};

int main()
{
    quicksort<int> q;
    uint32_t val;

    q.reserve(1028);

    while (cin >> val)
    {
        q.insert(val);
    }

    q.sort();
    q.print();
}
