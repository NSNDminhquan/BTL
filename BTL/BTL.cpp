#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
	string name, mssv, lop, ngaysinh;
	double gpa;
};

struct SV {
	Student s;
	SV* next;
};

typedef struct SV* sv;
sv makeNode() {
	Student s;
	cout << "Nhap thong tin sinh vien :\n";
	cout << "Nhap MSSV :"; cin >> s.mssv;
	cout << "Nhap ten :"; cin.ignore();
	getline(cin, s.name);
	cout << "Nhap lop :"; cin >> s.lop;
	cout << "Nhap ngay sinh :"; cin >> s.ngaysinh;
	cout << "Nhap gpa :"; cin >> s.gpa;
	sv tmp = new SV();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}
bool empty(sv a) {
	return a == NULL;
}
int Size(sv a) {
	int cnt = 0;
	while (a != NULL) {
		++cnt;
		a = a->next;
	}
	return cnt;
}
void insertFirst(sv& a) {
	sv tmp = makeNode();
	if (a == NULL) {
		a = tmp;
	}
	else {
		tmp->next = a;
		a = tmp;
	}
}
void insertLast(sv& a) {
	sv tmp = makeNode();
	if (a == NULL) {
		a = tmp;
	}
	else {
		sv p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}
void insertMiddle(sv& a, int pos) {
	int n = Size(a);
	if (pos <= 0 || pos > n + 1) {
		cout << "Vi tri chen khong hop le !\n"; return;
	}
	if (pos == 1) {
		insertFirst(a); return;
	}
	else if (pos == n + 1) {
		insertLast(a); return;
	}
	sv p = a;
	for (int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	sv tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}
void deleteFirst(sv& a) {
	if (a == NULL) return;
	a = a->next;
}
void deleteLast(sv& a) {
	if (a == NULL) return;
	sv truoc = NULL, sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}
void deleteMiddle(sv& a, int pos) {
	if (pos <= 0 || pos > Size(a)) return;
	sv truoc = NULL, sau = a;
	for (int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = a->next;
	}
	else {
		truoc->next = sau->next;
	}
}

void in(Student s) {
	cout << "--------------------------------\n";
	cout << "MSSV : " << s.mssv << endl;
	cout << "Ho ten :" << s.name << endl;
	cout << "Lop :" << s.lop << endl;
	cout << "Ngay sinh :" << s.ngaysinh << endl;
	cout << "GPA : " << fixed << setprecision(2) << s.gpa << endl;
	cout << "--------------------------------\n";
}

void inds(sv a) {
	cout << "Danh sach sinh vien :\n";
	while (a != NULL) {
		in(a->s);
		a = a->next;
	}
	cout << endl;
}

void sapxep(sv& a) {
	for (sv p = a; p->next != NULL; p = p->next) {
		sv min = p;
		for (sv q = p->next; q != NULL; q = q->next) {
			if (q->s.gpa < min->s.gpa) {
				min = q;
			}
		}
		Student tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}
void timkiemtheomssv(sv a)
{
	string x;
	cout << "Nhap MSSV can tim: ";
	cin.ignore();
	getline(cin, x);
	while (a != NULL)
	{
		if (a->s.mssv == x)
		{
			cout << "Da tim thay sv";
			in(a->s);
			return;
		}
		a = a->next;
	}
	cout << "Khong tim thay sinh vien\n";
	return;
}
int main() {
	sv head = NULL;
	while (1) {
		cout << "------------------------------------\n";
		cout << "1. Chen sinh vien vao dau danh sach\n";
		cout << "2. Chen sinh vien vao cuoi danh sach\n";
		cout << "3. Chen sinh vien vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lien ket\n";
		cout << "8. Sap xep cac sinh vien gpa tang dan\n";
		cout << "9. Tim sinh vien theo MSSV\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if (lc == 1) {
			insertFirst(head);
		}
		else if (lc == 2) {
			insertLast(head);
		}
		else if (lc == 3) {
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			insertMiddle(head, pos);
		}
		else if (lc == 4) {
			deleteFirst(head);
		}
		else if (lc == 5) {
			deleteLast(head);
		}
		else if (lc == 6) {
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			deleteMiddle(head, pos);
		}
		else if (lc == 7) {
			inds(head);
		}
		else if (lc == 8) {
			sapxep(head);
		}
		else if (lc == 9)
		{
			timkiemtheomssv(head);
		}
		else if (lc == 0) {
			break;
		}
	}
	return 0;
}
