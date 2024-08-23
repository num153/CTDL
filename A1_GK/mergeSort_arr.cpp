#include <iostream>
using namespace std;
void merge(int a[], int left, int mid, int right) {
  //cap phat de tao mang dong
  int *temp = new int[right - left + 1];
  int m = 0; //index mang temp
  int i = left;
  int j = mid + 1;
  while (i <= mid && j <= right) {
    if (a[i] < a[j]) {
      temp[m++] = a[i++];
    } else {
      temp[m++] = a[j++];
    }
  }
  while(i<=mid){
    temp[m++]=a[i++];
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
  int a[9] = {4, 7, 2, 9, 1,3,8,99,33};
  int left = 0;
  int right = 8;
  for (int i = 0; i <= right; i++) {
      cout << a[i] << " ";
  }
  cout << "\nSort: \n";
  mergeSort(a, left, right);
  for (int i = 0; i <= right; i++) {
      cout << a[i] << " ";
  }
  return 0;
}
