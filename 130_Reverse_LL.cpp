//Iterative Approach

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* current = head;
        Node*prev = nullptr;
        Node* nxt = nullptr;
        while(current != nullptr){
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }
    
};