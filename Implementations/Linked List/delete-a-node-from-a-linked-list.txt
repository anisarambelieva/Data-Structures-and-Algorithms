/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    
    // if we have to delete the head - works!
    if(position == 0)
    {
        SinglyLinkedListNode* copyHead = head;
        head = head->next;
        delete copyHead;
    }
    else
    {
        //we have to find the element on that position
        SinglyLinkedListNode* current = head->next;
        SinglyLinkedListNode* prev = head;
        int count = 1;
        while(count < position)
        {
            current = current->next;
            prev = prev->next;
            count++;
        }
        prev->next = current->next;
        delete current;
    }
    
    
    return head;
}