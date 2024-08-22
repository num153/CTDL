/*
  Chu y dieu kien chay cua i j khi sort
  node != NULL & node->next != NULL
*/
#include<iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
};
void init(Node*&head){
    head = NULL;
}
Node* createNode(int x){
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}
bool isEmpty(Node *head){
    return head == NULL;
}
void addLast(Node *&head, int val){
    Node *p=createNode(val);
        //list rong 
    if(isEmpty(head)){
        head = p;
    }else{
        Node *temp = head;
        //list chi co 1 node (k can dau vi neu co mot node thi tmp->next = NULL se k chay while)
        //list > 2 node 
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = p;
    }
}
void addFirst(Node*&head,int val){
    Node *p=createNode(val);
    //list rong
    if(isEmpty(head)){
        head = p;
    }else{
    //list > 2 node
        p->next = head;
        head = p;
    }
}
void output(Node*head){
    if(!isEmpty(head)){
        Node *temp = head;
        while(temp!=NULL){
        cout << temp->data << '\t';
        temp = temp->next;
    }
    }
}
void input(Node*&head,int &val, int &n){
    cout << "Number of node: "; cin >> n;
    for(int i=0;i<n;i++){
        cout << "Value no." << i+1 << ": ";
        cin >> val;
        addLast(head,val);
    }
}
void interchangeSort(Node*head){
    for(Node* i=head;i->next!=NULL;i=i->next){ //int i = 0; i < n - 1; i++
        for(Node* j=i->next;j!=NULL;j=j->next){ //int j = i + 1; j < n; j++
            if(i->data > j->data){
                swap(i->data,j->data);
            }
        }
    }
}
void selectionSort(Node*&head){
    for(Node*i=head;i!=NULL;i=i->next){
        Node* min_node = i;
        for(Node*j=i->next;j!=NULL;j=j->next){
            if(min_node->data>j->data){
                min_node = j;
            }
        }
        swap(i->data,min_node->data);
    }
}
int main()
{
    Node *ls;
    int x,n;
    init(ls);
    input(ls,x,n);
    output(ls);
    cout << "\nSort: \n";
    selectionSort(ls);
    output(ls);
    return 0;
}
