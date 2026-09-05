/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head;
        while(temp){
            if (temp->child){
                Node* a=temp->next;
                Node* c=temp->child;
                temp->child=NULL;
                c=flatten(c);
                temp->next=c;
                c->prev=temp;
                while(c->next){
                    c=c->next;
                }
                c->next=a;
                if (a) a->prev=c;
            }
            temp=temp->next;
        }
        return head;
    }
};
