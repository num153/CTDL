#include <iostream>
using namespace std;
void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int arr[], int n) {

    for (int i = (n / 2) - 1; i >= 0; i--)

        heapify(arr, n, i);

    for (int i = (n - 1); i >= 0; i--) {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
void merge(int a[], int left, int mid, int right) {
    // cap phat de tao mang dong
    int *temp = new int[right - left + 1];
    int m = 0; // index mang temp
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
        if (a[i] < a[j]) {
            temp[m++] = a[i++];
        } else {
            temp[m++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[m++] = a[i++];
    }
    for (int i = 0; i < m; i++) {
        a[left + i] = temp[i];
    }
    delete[] temp;
}
void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
int main() {
    int a[9] = {4, 7, 2, 9, 1, 3, 8, 99, 33};
    // int left = 0;
    int right = 8;
    for (int i = 0; i <= right; i++) {
        cout << a[i] << " ";
    }
    // cout << "\nSort: \n";
    // mergeSort(a, left, right);
    // for (int i = 0; i <= right; i++) {
    //     cout << a[i] << " ";
    // }
    cout << "\nSort: \n";
    heapSort(a, 9);
    for (int i = 0; i <= right; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
