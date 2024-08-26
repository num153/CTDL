#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void init(Node *&head) {
    head = NULL;
}

Node *createNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

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
    if (isEmpty(head)) {
        head = p;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void output(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << '\t';
        temp = temp->next;
    }
    cout << endl;
}

// Hàm lấy nút cuối cùng trong danh sách
Node *getTail(Node *cur) {
    while (cur != NULL && cur->next != NULL) cur = cur->next;
    return cur;
}

// Hàm phân đoạn (Partition)
Node *partition(Node *head, Node *end, Node *&newHead, Node *&newEnd) {
    Node *pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    // Duyệt qua danh sách để phân đoạn
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (newHead == NULL) newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (newHead == NULL) newHead = pivot;
    newEnd = tail;

    return pivot;
}

// Hàm QuickSort chính
Node *quickSortRecur(Node *head, Node *end) {
    if (!head || head == end) return head;

    Node *newHead = NULL, *newEnd = NULL;

    Node *pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Node *temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node *&head) {
    head = quickSortRecur(head, getTail(head));
}

int main() {
    Node *ls;
    int x, n;
    init(ls);

    cout << "Number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Value no." << i + 1 << ": ";
        cin >> x;
        addLast(ls, x);
    }

    cout << "Original list:\n";
    output(ls);

    quickSort(ls);

    cout << "Sorted list:\n";
    output(ls);

    free(ls);
    return 0;
}
