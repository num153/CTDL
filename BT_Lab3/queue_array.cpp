
/* 
    push: chu y dieu kien va vi tri khi rear++ va khi rong thi chi co front = 0
*/
#include<iostream>

using namespace std;
#define MAX 3
struct Queue{
    int front,rear;
    int a[MAX];
};
void init(Queue &q){
    q.front = -1;
    q.rear = -1;
}
bool isEmpty(Queue q){
    return (q.front ==-1 && q.rear ==-1);
}
bool isFull(Queue q){
    return q.rear - q.front == MAX-1;
}
void push(Queue &q, int val) {
    if (isFull(q)) {
        cout << "Queue is full!";
    } else {
        if(isEmpty(q)){
            q.front =0;
        }
        if(q.rear == MAX -1){
            for(int i = q.front; i<=q.rear;i++){
                q.a[i-q.front] = q.a[i];
                q.rear = MAX -1 - q.front;
                q.front = 0;
            }
        }
            q.rear ++;
            q.a[q.rear] = val;
    }
}
void pop(Queue &q){
    if(isEmpty(q)){
        cout << "Queue empyty !";
    }
    if(q.front == q.rear){ //neu chi co 1 phan tu
        q.front = -1;
        q.rear = -1;
    }else{
        //neu co nhieu hon mot
        q.front ++;
    }
}
void output(Queue q){
    for(int i=q.front;i<=q.rear;i++){
        cout << q.a[i] << '\t';
    }
}
void outputFront(Queue q){
    cout <<"\nfront: " << q.a[q.front];
}
void outputRear(Queue q){
    cout << "\nrear: " << q.a[q.rear];
}
int main()
{
    Queue q1;
    init(q1);
    push(q1,10);
    output(q1);
    pop(q1);
    outputFront(q1);
    outputRear(q1);
    return 0;
}
