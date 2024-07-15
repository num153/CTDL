#include <iostream>
#include <string>
using namespace std;
/* Khai bao cau truc Node */
struct Movie {
	string name;
	string genre;
	string director;
	int year;
};
struct Node {
	Movie data;
	Node* next;
};
void init(Node*& head) {
	head = NULL;
}
void free(Node*& head) {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
Node* createNode(Movie mv) {
	Node* p = new Node;
	p->data = mv;
	p-> next = NULL;
	return p;
}
/* ADD */
void addLast(Node*& head, Movie mv) {
	Node* p = createNode(mv);
	if (head != NULL) {
		Node* last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = p;
	}
	else //chu y neu nhu list dang rong (head = NULL)
	{
		head = p;
	}
}
void addFirst(Node*& head, Movie mv) {
	Node* p = createNode(mv);
	p->next = head;
	head = p;
}
/* NHAP VA XUAT DANH SACH PHIM */
void nhapMovie(Movie &mv) {
	cout << "Ten phim: "; getline(cin, mv.name);
	cout << "The loai: "; getline(cin, mv.genre);
	cout << "Dao dien: "; getline(cin, mv.director);
	cout << "Nam sx: "; cin >> mv.year;	cin.ignore();
}
void nhapLinkedList(Node* &head,Movie mv,int n)
{
	for (int i = 0; i < n; ++i)
	{	
		cout << "Nhap thong tin phim thu " << i + 1 << endl;
		nhapMovie(mv);
		addLast(head,mv);
	}

}
void xuatMovie(Movie mv){
	cout << "\nTen phim: " << mv.name << endl;
	cout << "The loai: " << mv.genre << endl;
	cout << "Dao dien: " << mv.director << endl;
	cout << "Nam sx: " << mv.year << endl;
}
void xuatNode(Node* head) {
	Node* flag = head;
	int i = 1;
	while (flag != NULL) {
		cout << "----Phim thu " << i << "----\n";
		xuatMovie(flag->data);
		flag = flag->next;
		i++;
	}
}
/* TIM KIEM PHIM */
bool checkList(string a, string b) {
	return a == b;
}
void findDirector(Node* head,string &x ) {
	cout << "Nhap ten dao dien can tim: "; getline(cin, x);
	Node* flag=head;
	bool check=false;
	while (flag != NULL) {
		if (checkList(flag->data.director, x)) {
			xuatMovie(flag->data);
			check = true;
		}
		flag = flag->next;
	}
	if (check==false) {
		cout << "Tim khong thay\n";
	}
}
int main() {
	Movie mv1;
	Node* head;
	int sl;
	string s;
	init(head);
	cout << "So luong phim: "; cin >> sl;cin.ignore();
	nhapLinkedList(head, mv1,sl);
	xuatNode(head);
	findDirector(head, s);
	free(head);
	system("pause");
	return 0;
}

//f.Viết hàm sắp xếp bộ phim tăng dần theo năm sản xuất.Hiển thị kết quả sắp xếp ra
//màn hình
