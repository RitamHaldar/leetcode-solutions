/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        Node* res = new Node(-1);
        Node* tempc = res;
        while (temp != NULL) {
            Node* temp1 = new Node(temp->val);
            tempc->next = temp1;
            mp[temp] = temp1;
            tempc = tempc->next;
            temp = temp->next;
        }
        temp = head;
        tempc = res->next;
        while (temp != NULL) {
            if (temp->random == NULL) tempc->random = NULL;
            else tempc->random = mp[temp->random];
            temp = temp->next;
            tempc = tempc->next;
        }
    return res->next;
    }
};
