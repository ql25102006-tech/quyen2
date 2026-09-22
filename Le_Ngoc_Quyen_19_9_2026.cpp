#include <iostream>
using namespace std;

struct hanghoa{
	int mahang;
	string tenhang;
	string ngay;
	float gia;
};

void nhap(hanghoa *a,int n){
	for(int i=0;i<n;i++){
		cout<<"\nNhap hang hoa thu "<<i+1<<":";
		
		cout<<"\nMa hang: ";
		cin>>a[i].mahang;
		cin.ignore();
		
		cout<<"Ten hang: ";
		getline(cin,a[i].tenhang);
		
		cout<<"Ngay xuat hang: ";
		getline(cin,a[i].ngay);
		
		cout<<"Gia xuat hang: ";
		cin>>a[i].gia;
	}
}

void xuat(hanghoa *a,int n){
	for(int i=0;i<n;i++){
		cout<<"\n"<<a[i].mahang<<" - "
			<<a[i].tenhang<<" - "
			<<a[i].ngay<<" - "
			<<a[i].gia;
	}
}

void sapxep(hanghoa *a,int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j].gia<a[min].gia)
				min=j;
		}
		swap(a[i],a[min]);
	}
}

void timkiem(hanghoa *a,int n,float x){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		
		if(a[mid].gia==x){
			int i=mid;
			while(i>=0&&a[i].gia==x) i--;
			i++;
			
			while(i<n&&a[i].gia==x){
				cout<<"\n"<<a[i].mahang<<" - "
					<<a[i].tenhang<<" - "
					<<a[i].ngay<<" - "
					<<a[i].gia;
				i++;
			}
			return;
		}
		
		if(a[mid].gia<x)
			left=mid+1;
		else
			right=mid-1;
	}
	
	cout<<"\nKhong tim thay!";
}

int main(){
	int n;
	cout<<"Nhap so hang hoa: ";
	cin>>n;
	
	hanghoa *a=new hanghoa[n];
	
	cout<<"\n===== NHAP =====";
	nhap(a,n);
	
	cout<<"\n\n===== DANH SACH VUA NHAP =====";
	xuat(a,n);
	
	sapxep(a,n);
	
	cout<<"\n\n===== SAU KHI SAP XEP =====";
	xuat(a,n);
	
	float x;
	cout<<"\n\nNhap gia can tim: ";
	cin>>x;
	
	cout<<"\n===== KET QUA TIM KIEM =====";
	timkiem(a,n,x);
	
	delete[] a;
	return 0;
}

