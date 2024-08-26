/*
        Chu y dieu kien chay cua i j khi sort
        node != NULL & node->next != NULL
        HAM FREE !!! SAI 2 lan roi, head chay, temp bi xoa chu k phai temp chay
*/
#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *next;
};
void init(Node *&head) { head = NULL; }
Node *createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}
bool isEmpty(Node *head) { return head == NULL; }
void free(Node *&head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}
void addLast(Node *&head, int val) {
    Node *p = createNode(val);
    // list rong
    if (isEmpty(head)) {
        head = p;
    } else {
        Node *temp = head;
        // list chi co 1 node (k can dau vi neu co mot node thi tmp->next = NULL se
        // k chay while) list > 2 node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}
void addFirst(Node *&head, int val) {
    Node *p = createNode(val);
    // list rong
    if (isEmpty(head)) {
        head = p;
    } else {
        // list > 2 node
        p->next = head;
        head = p;
    }
}
void output(Node *head) {
    if (!isEmpty(head)) {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << '\t';
            temp = temp->next;
        }
    }
}
void input(Node *&head, int &val, int &n) {
    cout << "Number of node: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Value no." << i + 1 << ": ";
        cin >> val;
        addLast(head, val);
    }
}
bool asc(int a, int b) { return a > b; }
bool des(int a, int b) { return a < b; }
void interchangeSort(Node *head, bool funct(int a, int b)) {
    for (Node *i = head; i->next != NULL;
             i = i->next) { // int i = 0; i < n - 1; i++
        for (Node *j = i->next; j != NULL;
                 j = j->next) { // int j = i + 1; j < n; j++
            if (funct(i->data, j->data)) {
                swap(i->data, j->data);
            }
        }
    }
}
void selectionSort(Node *&head) {
    for (Node *i = head; i != NULL; i = i->next) {
        Node *min_node = i;
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (min_node->data > j->data) {
                min_node = j;
            }
        }
        swap(i->data, min_node->data);
    }
}
void insertionSort(Node *&head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *sorted = NULL;
    Node *current = head;

    while (current != NULL) {
        Node *next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
}
Node* binarySearch(Node* head, int target) {
    if (head == NULL) {
        return NULL;
    }

    Node *start = head;
    Node *end = NULL;

    while (start != end) {
        // Tìm node ở vị trí giữa
        Node *slow = start;
        Node *fast = start->next;
        while (fast != end) {
            fast = fast->next;
            if (fast != end) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // slow hiện đang trỏ tới node ở vị trí giữa
        if (slow->data == target) {
            return slow;
        } else if (slow->data < target) {
            start = slow->next;
        } else {
            end = slow;
        }
    }

    return NULL; // Không tìm thấy phần tử
}

int binarySearchPos(Node* head, int target) {
    if (head == NULL) {
        return -1;
    }

    Node *start = head;
    Node *end = NULL;
    int startIndex = 0;

    do {
        // Tìm node ở vị trí giữa
        Node *slow = start;
        Node *fast = start->next;
        int midIndex = startIndex;

        while (fast != end) {
            fast = fast->next;
            if (fast != end) {
                slow = slow->next;
                fast = fast->next;
                midIndex++;
            }
        }

        // slow hiện đang trỏ tới node ở vị trí giữa
        if (slow->data == target) {
            return midIndex;
        } else if (slow->data < target) {
            start = slow->next;
            startIndex = midIndex + 1;
        } else {
            end = slow;
        }
    } while (end == NULL || end != start);

    return -1; // Không tìm thấy phần tử
}

int main() {
    Node *ls;
    int x, n;
    int choice;
    bool flag = false;
    init(ls);
    do {
        cout << "\n\t========MENU========\t\n";
        cout << "1. Input\n";
        cout << "2. Output\n";
        cout << "3. Add Last\n";
        cout << "4. Add First\n";
        cout << "5. Ascending Sort\n";
        cout << "6. Descending Sort\n";
        cout << "7. Delete list\n";
        cout << "8. Insertion list\n";
        cout << "9. Binary Search\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            input(ls, x, n);
            output(ls);
            flag = true;
            break;
        case 2:
            if (flag) {
                output(ls);
            } else {
                cout << "Empty list\n";
            }
            break;
        case 3:
            if (flag) {
                cout << "New last value: ";
                cin >> x;
                addLast(ls, x);
            } else {
                cout << "Empty list\n";
            }
            break;
        case 4:
            if (flag) {
                cout << "New first value: ";
                cin >> x;
                addFirst(ls, x);
            } else {
                cout << "Empty list\n";
            }
            break;
        case 5:
            if (flag) {
                interchangeSort(ls, asc);
                cout << "Sorted!\n";
                output(ls);
            } else {
                cout << "Empty list\n";
            }
            break;
        case 6:
            if (flag) {
                interchangeSort(ls, des);
                cout << "Sorted!\n";
                output(ls);
            } else {
                cout << "Empty list\n";
            }
            break;
        case 7:
            if (flag) {
                free(ls);
                flag = false;
                cout << "List deleted!\n";
            } else {
                cout << "Empty list\n";
            }
            break;
        case 8:
            if (flag) {
                insertionSort(ls);
                cout << "Sorted!\n";
                output(ls);
            } else {
                cout << "Empty list\n";
            }
            break;
        case 9:
            if (flag) {
                int target;
                cout << "Enter value to search: ";
                cin >> target;
                Node* result = binarySearch(ls, target);
                if (result != NULL) {
                    cout << "Value found: " << result->data << endl;
                } else {
                    cout << "Value not found in the list.\n";
                }
            } else {
                cout << "Empty list\n";
            }
            break;

        }
    } while (choice != 0);
    return 0;
}
/*
        Node* reverseList(Node* head) {

      // Initialize three pointers: curr, prev and next
    Node *curr = head, *prev = nullptr, *next;

      // Traverse all the nodes of Linked List
    while (curr != nullptr) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

      // Return the head of reversed linked list
    return prev;
}
    use in main: head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);
*/
