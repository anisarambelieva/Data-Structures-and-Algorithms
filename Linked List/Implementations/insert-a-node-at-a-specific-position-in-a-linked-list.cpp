/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    
    SinglyLinkedListNode* toInsert = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* current = head;
    
    int counter = 1;
    
    while(true)
    {
        if(position == counter)
        {
            toInsert->next = current->next;
            current->next = toInsert;
            break;
        }
        counter++;
        current = current->next;
    }
    return head;
}