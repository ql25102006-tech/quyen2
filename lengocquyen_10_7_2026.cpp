#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct KhachHang {
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTien;
};

void nhapMotKH(KhachHang &kh) {
    cout << "Nhap ma KH: ";
    cin >> kh.maKH;
    cin.ignore(); // Xoa bo nho dem sau khi nhap so
    cout << "Nhap ten KH: ";
    getline(cin, kh.tenKH);
    cout << "Nhap so dien thoai: ";
    getline(cin, kh.soDienThoai);
    cout << "Nhap tong tien thanh toan: ";
    cin >> kh.tongTien;
}

void nhapDanhSach(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin khach hang thu " << i + 1 << " ---\n";
        nhapMotKH(a[i]);
    }
}


void inTieuDe() {
    cout << left << setw(10) << "Ma KH"
         << setw(25) << "Ten KH"
         << setw(15) << "So DT"
         << right << setw(18) << "Tong Tien (VND)" << endl;
    cout << string(68, '-') << endl;
}

void inMotKH(const KhachHang &kh) {
    cout << left << setw(10) << kh.maKH
         << setw(25) << kh.tenKH
         << setw(15) << kh.soDienThoai
         << right << setw(18) << fixed << setprecision(2) << kh.tongTien << endl;
}

void xuatDanhSach(KhachHang a[], int n) {
    inTieuDe();
    for (int i = 0; i < n; i++) {
        inMotKH(a[i]);
    }
}

void insertionSort(KhachHang a[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang key = a[i];
        int j = i - 1;

    
        while (j >= 0 && a[j].tongTien > key.tongTien) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void timKiemTheoTongTien(KhachHang a[], int n, double X) {
    int left = 0;
    int right = n - 1;
    int viTri = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid].tongTien == X) {
            viTri = mid;
            break;
        } else if (a[mid].tongTien < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (viTri == -1) {
        cout << "Khong tim thay khach hang nao co tong tien bang " << fixed << setprecision(2) << X << endl;
        return;
    }

   
    int start = viTri;
    while (start - 1 >= 0 && a[start - 1].tongTien == X) {
        start--;
    }

    int end = viTri;
    while (end + 1 < n && a[end + 1].tongTien == X) {
        end++;
    }

    cout << "\nDanh sach khach hang co tong tien bang " << fixed << setprecision(2) << X << ":\n";
    inTieuDe();
    for (int i = start; i <= end; i++) {
        inMotKH(a[i]);
    }
}

// Câu 6: Hàm chính
int main() {
    int n;
    cout << "Nhap so luong khach hang n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong khach hang phai lon hon 0!" << endl;
        return 0;
    }

    KhachHang a[100]; // Mang chua toi da 100 khach hang


    nhapDanhSach(a, n);
    cout << "\n=== DANH SACH KHACH HANG VUA NHAP ===" << endl;
    xuatDanhSach(a, n);


    insertionSort(a, n);
    cout << "\n=== DANH SACH SAU KHI SAP XEP TANG DAN THEO TONG TIEN ===" << endl;
    xuatDanhSach(a, n);


    double X;
    cout << "\nNhap tong tien X can tim: ";
    cin >> X;
    timKiemTheoTongTien(a, n, X);

    return 0;
}
