/*
    CHU Y free() thuong xuyen gap loi 
    Dieu kien && vs || o case 7
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
struct Doublell {
    Node* head;
    Node* tail;
};
void init(Doublell& ls) {
    ls.head = NULL;
    ls.tail = NULL;
}
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
bool isEmpty(Doublell ls) { return ls.head == NULL; }
void addFirst(Doublell& ls, int val) {
    Node* p = createNode(val);
    if (isEmpty(ls)) {
        ls.head = p;
        ls.tail = p;
    }
    else {
        p->next = ls.head;
        ls.head->prev = p;
        ls.head = p;
    }
}
void addLast(Doublell& ls, int val) {
    Node* p = createNode(val);
    if (isEmpty(ls)) {
        ls.head = p;
        ls.tail = p;
    }
    else {
        p->prev = ls.tail;
        ls.tail->next = p;
        ls.tail = p;
    }
}
void addAfter(Doublell &ls,int pos,int val){
    Node*temp=ls.head;
    while(temp!=NULL&&temp->data!=pos){
        temp=temp->next;
    }
    if(temp!=NULL){
        if(temp == ls.tail){
            addLast(ls,val);
        }else{
            Node*p=createNode(val);
            //Uu tien noi nhanh sau truoc nhe bae
            p->next=temp->next;
            temp->next->prev = p;
            temp->next=p;
            p->prev=temp;
        }
    }else{
        cout << "Couldn't find " << pos << " in list!\n";
    }
}
void input(Doublell& ls, int& n) {
    cout << "Num. of Node: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Val no." << i + 1 << ": ";
        cin >> val;
        addLast(ls, val);
    }
}
void output(Doublell ls) {
    if (!isEmpty(ls)) {
        Node* temp = ls.head;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}
void countNode(Doublell ls) {
    int count = 0;
    if (!isEmpty(ls)) {
        Node* temp = ls.head;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        cout << "List has " << count << " nodes\n";
    }
    else {
        cout << "List has 0 node" << endl;
    }
}
Doublell merge(Doublell& ls1, Doublell& ls2) {
    //neu ls1 rong, doi ls1 sang ls2
    if (isEmpty(ls1)) {
        ls1.head = ls2.head;
        ls1.tail = ls2.tail;
    } 
    //neu co day du ls1 va ls2
    else if (!isEmpty(ls2)) {
        ls1.tail->next = ls2.head;
        ls2.head->prev = ls1.tail;
        ls1.tail = ls2.tail;
    }
    //merge xong thi xoa ls2 di (QUAN TRONG !! neu k se bi lap)
    ls2.head = NULL;  
    ls2.tail = NULL;  

    return ls1;
}
// void merge(Doublell& ls1, Doublell& ls2, Doublell& ls3) {
//     Node* temp = ls1.head;
//     while (temp != NULL) {
//         addLast(ls3, temp->data); 
//         temp = temp->next;
//     }

//     temp = ls2.head;
//     while (temp != NULL) {
//         addLast(ls3, temp->data);
//         temp = temp->next;
//     }
// }
void free(Doublell& ls) {
    while (ls.head != NULL) {
        Node* temp = ls.head;
        ls.head = ls.head->next;
        delete temp;
    }
    ls.head = NULL;
    ls.tail = NULL;
}
int main() {
    Doublell ls1;
    Doublell ls2;
    Doublell ls3;
    int n;
    int choice;
    bool flag1 = false, flag2 = false;
    init(ls1);
    init(ls2);
    init(ls3);
    do {
        cout << "\n\t======MENU======\t\n";
        cout << "1. Input for list 1\n";
        cout << "2. Input for list 2\n";
        cout << "3. Output list 1\n";
        cout << "4. Output list 2\n";
        cout << "5. Count nodes in list 1\n";
        cout << "6. Count nodes in list 2\n";
        cout << "7. Merge 2 lists\n";
        cout << "8. Delete lists\n";
        cout << "9. Add after\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            free(ls1);
            input(ls1, n);
            output(ls1);
            flag1 = true;
            break;
        case 2:
            free(ls2);
            input(ls2, n);
            output(ls2);
            flag2 = true;
            break;
        case 3:
            if (flag1) {
                output(ls1);
            }
            else {
                cout << "List 1 is empty" << endl;
            }
            break;
        case 4:
            if (flag2) {
                output(ls2);
            }
            else {
                cout << "List 2 is empty" << endl;
            }
            break;
        case 5:
            if (flag1) {
                countNode(ls1);
            }
            else {
                cout << "List 1 is empty" << endl;
            }
            break;
        case 6:
            if (flag2) {
                countNode(ls2);
            }
            else {
                cout << "List 2 is empty" << endl;
            }
            break;
        case 7:
            if (flag1 || flag2) {
                ls1= merge(ls1, ls2);
                cout << "Merged list: ";
                output(ls1);
                // merge(ls1, ls2, ls3);
                // cout << "Merged list (ls3): ";
                // output(ls3);
            }
            else {
                cout << "Both lists are empty" << endl;
            }
            break;
        case 8:
            if (flag1) {
                free(ls1);
                flag1 = false;
            }
            if (flag2) {
                free(ls2);
                flag2 = false;
            }
            // if (!isEmpty(ls3)) {
            //     free(ls3);
            // }
            break;
        case 9:
            int pos,val;
            if(flag1){
                cout << "Enter value pos: "; cin >> pos;
                cout << "Enter value to add: ";cin >> val;
                addAfter(ls1, pos, val);
            }else if(flag2){
                cout << "Enter value pos: "; cin >> pos;
                cout << "Enter value to add: ";cin >> val;
                addAfter(ls2, pos, val);
            }else{
                cout << "Empty list!\n";
            }
            break;
        }
    } while (choice != 0);
    return 0;
}
