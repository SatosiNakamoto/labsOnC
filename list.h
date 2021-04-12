#include <iostream>
#include <utility>

#include <time.h>

template<typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node* prev;
        Node* next;
    } *head = nullptr, * tail = nullptr;

    void copy(const List& list)
    {
        if (list.head)
        {
            head = tail = new Node{ list.head->value, nullptr, nullptr };

            for (Node* current = list.head->next; current; current = current->next)
            {
                tail = tail->next = new Node{ current->value, tail, nullptr };
            }
        }
    }

public:
    List() = default;

    List(int* arr, int arr_size)
    {
        if(arr_size > 0)
        {
            int counter = 0;
            head = tail = new Node{ arr[counter++], nullptr, nullptr };
            for(;counter < arr_size; ++counter)
            {
                this->push_back(arr[counter]);
            }   
        }
    }

    List(const List& list)
    {
        copy(list);
    }

    ~List()
    {
        clear();
    }

    List(List&& list) noexcept
    {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
    }

    List& operator =(const List& list)
    {
        clear();
        copy(list);

        return *this;
    }

    List& operator =(List&& list) noexcept
    {
        std::swap(head, list.head);
        std::swap(tail, list.tail);

        return *this;
    }

    void clear()
    {
        while (head)
        {
            delete std::exchange(head, head->next);
        }

        tail = head;
    }

    void push_back(const T& value)
    {
        Node* new_node = new Node{ value, tail, nullptr };

        if (tail)
        {
            tail = tail->next = new_node;
        }
        else
        {
            head = tail = new_node;
        }
    }

    friend std::ostream& operator <<(std::ostream& os, const List& list)
    {
        for (Node* current = list.head; current; current = current->next)
        {
            os << current->value << " -> ";
        }

        return os << "null";
    }
};

int main()
{
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    List<int> lst1(a, 10);
    clock_t t_without_move;
    t_without_move = clock();
    
    for(int i = 0; i < 1000000; ++i)
    {
        List<int> ls2(lst1);
    }

    t_without_move = clock() - t_without_move;
    double time_taken_without_move = ((double)t_without_move) / CLOCKS_PER_SEC;
    clock_t t_with_move;
    t_with_move = clock();

    for (int i = 0; i < 100000; ++i)
    {
        List<int> ls2(std::move(lst1));
    }

    t_with_move = clock() - t_with_move;
    double time_taken_with_move = ((double)t_with_move) / CLOCKS_PER_SEC;

    std::cout << "without - " <<time_taken_without_move << " with - " << time_taken_with_move;
}
