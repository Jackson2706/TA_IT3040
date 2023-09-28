#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//push a new element to the begin of the list
Node* prepend(Node *head, int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}

void print(Node *head){
    while(head!= NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node *head){
    Node *prev = NULL;
    Node *next = NULL;
    while (head){
        next = head->next;
        head->next = prev;  
        prev = head;
        head = next;
    }
    return prev;
}

int main(){
    int n, u;
    cin >> n;
    Node *head = NULL;
    for(int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);
    cout << "Reversed list: ";
    print(head);

    return 0;
}
