#include <bits/stdc++.h>

using namespace std;
class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

// Returns the Head of Loop
SinglyLinkedListNode* Loop(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *s = head;
    SinglyLinkedListNode *f = head;
    
    do{
        s = s->next;
        f= f->next->next;
    }
    while(s!=f);
    
    s = head;
    while(s!=f){
        s = s->next;
        f = f->next;
    }
    SinglyLinkedListNode *loop_start = f;
    int length=1;
    do{
        f = f->next;
        length++;
    }
    while(loop_start!=f->next);
    
    // f gives pointer to node just before the head of loop, loop_start is the pointer to head of loop. Length gives length of loop. 
    return loop_start;

}


// Returns the head of revered Linked List.
SinglyLinkedListNode* Reverse(SinglyLinkedListNode* head) {

    SinglyLinkedListNode *h = head;
    SinglyLinkedListNode *prev = NULL;
    SinglyLinkedListNode *current = head;
    SinglyLinkedListNode *Next = NULL;
        
    while(current!=NULL){
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
    }
    head = prev;

    return head;

}

// Returns the head of the original list with nodes reversed between m and n. (Indexing is from one)
SinglyListNode* reverseBetween(SinglyListNode* head, int m, int n) {
        SinglyListNode *ha = head;
        SinglyListNode *prev = NULL;
        SinglyListNode *current = head;
        SinglyListNode *og = head;
        SinglyListNode *og_prev = head;

        if(m==1){
            for(int i=0;i<m-1;i++){
                current = current->next;
                og = og->next;
            }
            SinglyListNode *Next = NULL;

            for(int i=0;i<n;i++)
            {
                if(current!=NULL){
                    Next = current->next;
                    current->next = prev;
                    prev = current;
                    current = Next;
                }
            }
            og->next = current;
            return prev;
            
        }
            for(int i=0;i<m-1;i++){
                current = current->next;
                og = og->next;
            }
            prev = head;
            for(int i=0;i<m-2;i++){
                og_prev = og_prev->next;
                prev = prev->next;
            }
            SinglyListNode *Next = NULL;

            for(int i=0;i<=n-m;i++)
            {
                if(current!=NULL){
                    Next = current->next;
                    current->next = prev;
                    prev = current;
                    current = Next;
                }
            }
            og->next = current;
            og_prev->next = prev;
            return ha;
        
   }

// Returns head of rotated list, rotates the list right k times
SinglyListNode* rotateRight(SinglyListNode* head, int k) {

        SinglyListNode *t= head;
        if(head==NULL)
            return NULL;
        else if(head->next==NULL)
            return head;
        
        SinglyListNode* h=head;
        
        SinglyListNode *i = head;
        int n=0;
        while(i!=NULL){
            i=i->next;
            n++;
        }
        k = k%n;
        
        for(int i=0;i<k;i++)
            h = rotate(h);
        
        return h;
         
}
// Returns head of rotated list, rotates the list right once
SinglyListNode* rotate(SinglyListNode *head){

        SinglyListNode *t= head;
        while(t->next->next!=NULL)
            t=t->next;            
        t->next->next = head;
        SinglyListNode* newHead = t->next;
        t->next = NULL;

        return newHead;
}

// Checks if the linked list is a palindrome
bool isPalindrome(SinglyListNode* head) {
        int n=0;
        ListNode* t= head;
        if(head==NULL)
            return true;
   
        
        while(t!=NULL){
            t=t->next;
            n++;
        }
    if(n==1)
        return true;
     if(n%2==0){
         reverseBetween(head,n/2 + 1,n);
         SinglyListNode *temp = head;
         SinglyListNode *temp2 = head;
         for(int i=0;i<(n/2);i++)
             temp2= temp2->next;
         int flag=0;
         
         // cout << "TEMP2 " << temp2->val << endl;
         // cout << "TEMP1 " << temp->val << endl;
         
         
         for(int i=0;i<=n/2-1;i++){
             if(temp->val!=temp2->val){
                 flag=1;
                 // cout << "HAAA" << endl;
                 break;
             }
             temp=temp->next;
             temp2=temp2->next;
         }
         
        if(flag==1)
            return false;
        return true;            
         }
        
         reverseBetween(head,n/2 + 2,n);
         SinglyListNode *temp = head;
         SinglyListNode *temp2 = head;
         for(int i=0;i<=(n/2);i++)
             temp2= temp2->next;
         int flag=0;
         
         for(int i=0;i<n/2;i++){
             if(temp->val!=temp2->val){
                 flag=1;
                 break;
             }
             temp=temp->next;
             temp2=temp2->next;
             
         }
        if(flag==1)
            return false;
        return true;   
        
}