#include <iostream>

struct Node 
{
    int data;
    Node* next;
};

bool has_cycle(Node* head)
{
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}

int main() 
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head->next; 

    if (has_cycle(head))
    {
        std::cout << "Cycle detected" << std::endl;
    }
    else
    {
        std::cout << "No cycle detected" << std::endl;
    }

    return 0;
}
