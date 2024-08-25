/*
  Ham getFront phai co truong hop else tra ve NULL
*/
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
struct Queue{
    Node*front;
    Node*rear;
};
void init(Queue&q){
    q.front = NULL;
    q.rear = NULL;
}
bool isEmpty(Queue q){
    return q.front == NULL;
}
// bool isFull(Queue q) ko co dau em iu
Node *create(int x){
    Node* p = new Node;
    p->data=x;
    p->next=NULL;
    return p;
}
void enqueue(Queue &q, int val){
    Node*p=create(val);
    if(isEmpty(q)){
        q.front = q.rear = p;
    }else{
        q.rear->next = p;
        q.rear = p;
    }
}
void dequeue(Queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty!\n";
        return;
    }
    Node*temp=q.front;
    q.front = temp->next;
    if (q.front == NULL) {
        q.rear = NULL;
    }
    delete temp;
}
void output(Queue q){
    if(!isEmpty(q)){
        Node*temp=q.front;
        while(temp!=NULL){
            cout << temp->data << '\t';
            temp=temp->next;
        }
    }
}
Node* getFront(Queue q){
    if(!isEmpty(q)){
        return q.front;
    }else{
        return NULL; //Neu ham la con tro thi PHAI CO VAL TRA VE
    }
}
Node* getRear(Queue q){
    if(!isEmpty(q)){
        return q.rear;
    }else{
        return NULL;
    }
}

int main(){
    Queue q1;
    init(q1);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 55);
    output(q1);
    Node*a;
    Node*b;
    a=getFront(q1);
    b=getRear(q1);
    cout << "\nFront: " << a->data;
    cout << "\nRear: " << b->data;
    return 0;
}
