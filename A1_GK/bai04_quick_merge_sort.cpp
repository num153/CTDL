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
//=========QUICK SORT=========
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
//=============HEAP SORT============
// Hàm đếm số lượng nút trong danh sách liên kết
int getListSize(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Hàm lấy nút tại chỉ số cụ thể
Node *getNodeAt(Node *head, int index) {
    Node *temp = head;
    while (temp != NULL && index > 0) {
        temp = temp->next;
        index--;
    }
    return temp;
}

// Hàm hoán đổi giá trị giữa hai nút
void swapNodeValues(Node *a, Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Hàm heapify cho danh sách liên kết
void heapify(Node *head, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    Node *largestNode = getNodeAt(head, largest);
    Node *leftNode = getNodeAt(head, left);
    Node *rightNode = getNodeAt(head, right);

    if (left < size && leftNode && leftNode->data > largestNode->data) {
        largest = left;
        largestNode = leftNode;
    }

    if (right < size && rightNode && rightNode->data > largestNode->data) {
        largest = right;
        largestNode = rightNode;
    }

    if (largest != i) {
        Node *iNode = getNodeAt(head, i);
        swapNodeValues(iNode, largestNode);
        heapify(head, size, largest);
    }
}

// Hàm heap sort cho danh sách liên kết
void heapSortList(Node *&head) {
    int size = getListSize(head);

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(head, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        Node *iNode = getNodeAt(head, i);
        Node *rootNode = getNodeAt(head, 0);
        swapNodeValues(rootNode, iNode);
        heapify(head, i, 0);
    }
}
//=========MERGE SORT=========
Node* merge(Node* a, Node* b) {
    // BASE CASE
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    //REC CASE
    Node* c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
Node* midPoint(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void mergeSort(Node*& head) {
    // BASE CASE
    if (head == NULL || head->next == NULL) {
        return;
    }
    // REC CASE
    Node* mid = midPoint(head);
    // BREAK AT THE MID
    Node* l = head;
    Node* m = mid->next;
    mid->next = NULL;
    mergeSort(l);
    mergeSort(m);
    head = merge(l, m);
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
