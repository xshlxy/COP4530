#include <utility>
#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

template <typename Comparable>
class heap_pq
{
public:
    heap_pq()
    {
        heap_ptr = 1;
    }

    const Comparable &findMax()
    {
        //----- MY CODE -----
        return heap_findMax();
        //-------------------
    }

    void insert(const Comparable &x)
    {
        //----- MY CODE -----
        heap_insert(x);
        //-------------------
    }

    void remove()
    {
        //----- MY CODE -----
        heap_remove();
        //-------------------
    }

    void print()
    {
        //----- MY CODE -----
        heap_print();
        //-------------------
    }

    void property_validate()
    {
        //----- MY CODE -----
        heap_property_validate();
        //-------------------
    }

    void reserve(uint32_t size)
    {
        //----- MY CODE -----
        heap_reserve(size);
        //-------------------
    }

    uint32_t quantity()
    {
        //----- MY CODE -----
        return heap_quantity();
        //-------------------
    }

private:
    vector<Comparable> heap;
    uint32_t heap_ptr;

    Comparable &heap_findMax()
    {
        //----- MY CODE -----
        if (heap_ptr == 1)
        {
            throw std::logic_error("Heap is empty"); // Handle empty heap case
        }
        return heap[1]; // returns the root
        //-------------------
    }

    void heap_insert(const Comparable &x)
    {
        //----- MY CODE -----
        if (heap_ptr >= heap.size() - 1)
        {
            heap.resize(heap.size() * 2); // Resize the heap if necessary
        }

        heap[heap_ptr] = x; // Store new element at the end of the heap
        uint32_t current = heap_ptr;
        ++heap_ptr;
        heap_property_up(current); // Percolate up to maintain heap property

        //-------------------
    }

    void heap_remove()
    {
        //----- MY CODE -----
        if (heap_ptr <= 1)
        {
            std::cout << "Heap is empty. Cannot remove." << std::endl;
            return; // Handle empty heap case
        }

        heap[1] = std::move(heap[heap_ptr--]); // Move last element to the root

        if (heap_ptr > 1)
        {
            heap_property_down(1);
        } // Percolate down from the root
        //-------------------
    }

    void heap_print()
    {
        //----- MY CODE -----
        std::cout << "Heap" << std::endl;
        for (uint32_t i = 0; i < heap_ptr; ++i)
        {
            std::cout << i << ": " << heap[i] << std::endl;
        }

        //-------------------
    }

    void heap_property_validate()
    {
        //----- MY CODE -----
        std::cout << "No heap property violations found." << std::endl;
        std::cout << std::endl;
        for (uint32_t i = 1; i <= heap_ptr / 2; ++i)
        {
            int left_child = 2 * i;
            int right_child = 2 * i + 1;
            // Check if left child exists and violates heap property
            if (left_child < heap_ptr && heap[i] < heap[left_child])
            {
                throw std::logic_error("Heap property violated: parent is less than left child");
            }

            // Check if right child exists and violates heap property
            if (right_child < heap_ptr && heap[i] < heap[right_child])
            {
                throw std::logic_error("Heap property violated: parent is less than right child");
            }
        }
        //-------------------
    }

    void heap_reserve(uint32_t size)
    {
        //----- MY CODE -----
        heap.reserve(size + 1);
        //-------------------
    }

    uint32_t heap_quantity()
    {
        //----- MY CODE -----
        return heap_ptr - 1;
        //-------------------
    }

    //  ----------------------
    //
    //  Helper functions
    //
    //

    void heap_property_up(uint32_t item)
    {
        //----- MY CODE -----
        if (item > 1 && heap[item] > heap[item / 2])
        {
            std::swap(heap[item], heap[item / 2]);
            heap_property_up(item / 2); // Recursively percolate up
        }
        //-------------------
    }

    void heap_property_down(uint32_t index)
    {
        //----- MY CODE -----
        Comparable tmp = std::move(heap[index]);
        uint32_t child;

        while (index <= heap_ptr)
        {
            child = 2 * index;
            if (child + 1 <= heap_ptr && heap[child + 1] > heap[child])
            {
                ++child;
            }
            if (child <= heap_ptr && heap[child] > tmp)
            {
                // Check child within bounds before swap
                heap[index] = std::move(heap[child]);
                index = child;
            }
            else
            {
                break;
            }
        }
        heap[index] = std::move(tmp);
    }

    //-------------------
};
int main()
{
    heap_pq<int> h;
    uint32_t val;
    char op;

    h.reserve(128);

    while (cin >> op >> val)
    {
        cout << "Op = " << op << ", val = " << val << "\n";
        if (op == 'E')
        {
            h.insert(val);
            cout << "Max = " << h.findMax() << "\n";
        }
        if (op == 'D')
        {
            if (val == 0)
            {
                h.remove();
                val = h.quantity();
            }
            else
            {
                while (val)
                {
                    h.remove();
                    val--;
                }
            }
        }
        h.print();
        h.property_validate();
    }

    return 0;
};