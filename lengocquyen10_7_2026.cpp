#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

struct NhanVien {
    string maNV;
    string hoTen;
    Date ngaySinh;
    double luong;
};

void nhapMotNV(NhanVien &nv) {
    cout << "Nhap ma nhan vien: ";
    getline(cin, nv.maNV);
    cout << "Nhap ho va ten: ";
    getline(cin, nv.hoTen);
    
    char slash;
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin >> nv.ngaySinh.ngay >> slash >> nv.ngaySinh.thang >> slash >> nv.ngaySinh.nam;
    
    cout << "Nhap luong (trieu dong): ";
    cin >> nv.luong;
    cin.ignore();
}

void nhapDanhSach(NhanVien a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        nhapMotNV(a[i]);
    }
}

void inTieuDe() {
    cout << left << setw(12) << "Ma NV"
         << setw(25) << "Ho va Ten"
         << setw(16) << "Ngay Sinh"
         << right << setw(18) << "Luong (Trieu dong)" << endl;
    cout << string(71, '-') << endl;
}

void inMotNV(const NhanVien &nv) {
    string strNgaySinh = (nv.ngaySinh.ngay < 10 ? "0" : "") + to_string(nv.ngaySinh.ngay) + "/"
                       + (nv.ngaySinh.thang < 10 ? "0" : "") + to_string(nv.ngaySinh.thang) + "/"
                       + to_string(nv.ngaySinh.nam);

    cout << left << setw(12) << nv.maNV
         << setw(25) << nv.hoTen
         << setw(16) << strNgaySinh
         << right << setw(18) << fixed << setprecision(2) << nv.luong << endl;
}

void xuatDanhSach(NhanVien a[], int n) {
    inTieuDe();
    for (int i = 0; i < n; i++) {
        inMotNV(a[i]);
    }
}

void bubbleSort(NhanVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].luong > a[j + 1].luong) {
                NhanVien temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void timKiemTheoLuong(NhanVien a[], int n, double X) {
    int left = 0;
    int right = n - 1;
    int viTri = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid].luong == X) {
            viTri = mid;
            break;
        } else if (a[mid].luong < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (viTri == -1) {
        cout << "\nKhong tim thay nhan vien nao co muc luong bang " 
             << fixed << setprecision(2) << X << " trieu dong.\n";
        return;
    }

    int start = viTri;
    while (start - 1 >= 0 && a[start - 1].luong == X) {
        start--;
    }

    int end = viTri;
    while (end + 1 < n && a[end + 1].luong == X) {
        end++;
    }

    cout << "\nDanh sach nhan vien co muc luong bang " 
         << fixed << setprecision(2) << X << " trieu dong:\n";
    inTieuDe();
    for (int i = start; i <= end; i++) {
        inMotNV(a[i]);
    }
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien n: ";
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "So luong nhan vien phai lon hon 0!" << endl;
        return 0;
    }

    NhanVien a[100];

    nhapDanhSach(a, n);
    cout << "\n=== DANH SACH NHAN VIEN VUA NHAP ===" << endl;
