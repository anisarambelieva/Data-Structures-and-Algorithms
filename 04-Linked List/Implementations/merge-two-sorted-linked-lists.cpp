/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

// implementation explained in this video https://youtu.be/EvgZCUhTosc

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode* fake = new SinglyLinkedListNode(-1);
    SinglyLinkedListNode* last = fake;
    
    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->data < head2->data)
        {
            //we have to link the current last with the smaller value
            last->next = head1;
            //we have a new last element
            last = head1;
            head1 = head1->next;
        } 
        else
        {
            last->next = head2;
            last = head2;
            head2 = head2->next;
        }
    }
    if(head1 != nullptr)
    {
        last->next = head1;
    }
    if(head2 != nullptr)
    {
        last->next = head2;
    }
    return fake->next;
}