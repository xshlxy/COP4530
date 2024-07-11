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
        quicksort_insert(x);
    }

    void print()
    {
        quicksort_print();
    }

    void reserve(uint32_t size)
    {
        quicksort_reserve(size);
    }

    uint32_t quantity()
    {
        return quicksort_quantity();
    }

    void sort()
    {
        if (next > 0)
        {
            quicksort_sort(0, next - 1);
        }
    }

private:
    vector<Comparable> q;

    void quicksort_insert(const Comparable &x)
    {
        // MY CODE
        auto it = q.begin();
        while (it != q.end() && *it < x)
        {
            ++it;
        }
        q.insert(it, x);
        ++next;
    }

    void quicksort_print()
    {
        std::cout << "List";
        for (uint32_t i = 0; i < next; ++i)
        {
            std::cout << "\n"<<i << ": " << q[i];
        }
    }

    void quicksort_reserve(uint32_t size)
    {
        q.reserve(size + 1);
    }

    uint32_t quicksort_quantity()
    {
        return next;
    }

    void quicksort_sort(uint32_t start, uint32_t end)
    {
        if (start >= end)
            return; // Base case 1: If there is only one element

        if (end - start == 1)
        { // Base case 2: if the elements contained are two
            if (q[start] > q[end])
            {
                swap(q[start], q[end]);
            }
            return;
        }
        // Recursive case: If there are three or more elements then
        // Call the partition function and recursively quicksort left and right subarrays.

        int i = partition(start, end);
        quicksort_sort(start, i);
        quicksort_sort(i + 1, end);
    }

    //  ----------------------
    //
    //  Helper functions
    //
    //

    uint32_t partition(uint32_t start, uint32_t end)
    {
        uint32_t median = (start + end) / 2;

        if (q[median] < q[start])
        {
            std::swap(q[start], q[median]);
        }
        if (q[end] < q[start])
        {
            std::swap(q[end], q[start]);
        }
        if (q[end] < q[median])
        {
            std::swap(q[median], q[end]);
        }

        // Place the pivot at position end - 1
        std::swap(q[median], q[end - 1]);
        Comparable pivot = q[end - 1];
        uint32_t i = start;
        uint32_t j = end - 1;

        while (true)
        {
            while (q[++i] < pivot)
                ;
            while (pivot < q[--j])
                ;
            if (i >= j)
                break;
            std::swap(q[i], q[j]);
        }

        std::swap(q[i], q[end - 1]); // Restore pivot
        return i;
    };
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
