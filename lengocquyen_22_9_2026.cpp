#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float diemTongKet;
    string hanhKiem;
};

struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};

void khoiTaoCay(Node* &root) {
    root = NULL;
}

Node* taoNode(SinhVien sv) {
    Node* p = new Node();
    p->data = sv;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void chenNode(Node* &root, SinhVien sv) {
    if (root == NULL) {
        root = taoNode(sv);
        return;
    }
    if (sv.maSV < root->data.maSV) {
        chenNode(root->left, sv);
    } else if (sv.maSV > root->data.maSV) {
        chenNode(root->right, sv);
    } else {
        cout << "Ma sinh vien " << sv.maSV << " da ton tai!\n";
    }
}

Node* timKiem(Node* root, int maSV) {
    if (root == NULL || root->data.maSV == maSV) {
        return root;
    }
    if (maSV < root->data.maSV) {
        return timKiem(root->left, maSV);
    }
    return timKiem(root->right, maSV);
}

void inDongSinhVien(SinhVien sv) {
    cout << left << setw(10) << sv.maSV 
         << setw(25) << sv.tenSV 
         << setw(15) << sv.lop 
         << setw(15) << fixed << setprecision(2) << sv.diemTongKet 
         << setw(15) << sv.hanhKiem << "\n";
}

void inTieuDeBang() {
    cout << string(80, '-') << "\n";
    cout << left << setw(10) << "Ma SV" 
         << setw(25) << "Ho va Ten" 
         << setw(15) << "Lop" 
         << setw(15) << "Diem TK" 
         << setw(15) << "Hanh Kiem" << "\n";
    cout << string(80, '-') << "\n";
}

void duyetLNR(Node* root) {
    if (root != NULL) {
        duyetLNR(root->left);
        inDongSinhVien(root->data);
        duyetLNR(root->right);
    }
}

void giaiPhongCay(Node* &root) {
    if (root != NULL) {
        giaiPhongCay(root->left);
        giaiPhongCay(root->right);
        delete root;
        root = NULL;
    }
}

SinhVien nhapMotSinhVien() {
    SinhVien sv;
    cout << "Nhap Ma SV: ";
    cin >> sv.maSV;
    cin.ignore();

    cout << "Nhap Ho va Ten: ";
    getline(cin, sv.tenSV);

    cout << "Nhap Lop: ";
    getline(cin, sv.lop);

    cout << "Nhap Diem tong ket: ";
    cin >> sv.diemTongKet;
    cin.ignore();

    cout << "Nhap Hanh kiem: ";
    getline(cin, sv.hanhKiem);

    return sv;
}

int main() {
    Node* caySV;
    khoiTaoCay(caySV);

    int n;
    do {
        cout << "Nhap so luong sinh vien n: ";
        cin >> n;
    } while (n <= 0);

    for (int i = 0; i < n; ++i) {
        cout << "\nSinh vien thu " << i + 1 << ":\n";
        SinhVien sv = nhapMotSinhVien();
        chenNode(caySV, sv);
    }

    cout << "\nDANH SACH SINH VIEN TRONG CAY:\n";
    inTieuDeBang();
    duyetLNR(caySV);
    cout << string(80, '-') << "\n";

    int maCanTim;
    cout << "\nNhap ma sinh vien can tim: ";
    cin >> maCanTim;

    Node* kq = timKiem(caySV, maCanTim);
    if (kq != NULL) {
        cout << "\nThong tin sinh vien tim thay:\n";
        inTieuDeBang();
        inDongSinhVien(kq->data);
        cout << string(80, '-') << "\n";
    } else {
        cout << "\nKhong co sinh vien trong cay co ma: " << maCanTim << "\n";
    }

    giaiPhongCay(caySV);

    return 0;
}