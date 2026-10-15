#include <iostream>
#include <cstdio>

using namespace std;

#define VOCUNG 1000000000


struct Graph {
    int N;       
    int **A;     
};


struct Dijkstra {
    Graph graph;
    int start;
    int end;
};

void Nhap(Dijkstra &d)
{

    FILE* f = freopen("Grap.txt", "r", stdin);
    if (f == NULL) {
        cout << "Khong the mo file Grap.txt!" << endl;
        return;
    }

    
    cin >> d.graph.N;

  
    d.graph.A = new int*[d.graph.N];
    for (int i = 0; i < d.graph.N; i++)
    {
        d.graph.A[i] = new int[d.graph.N];
        for (int j = 0; j < d.graph.N; j++)
        {
            cin >> d.graph.A[i][j];
           
            if (d.graph.A[i][j] == 0 && i != j) {
                d.graph.A[i][j] = VOCUNG;
            }
        }
    }

    fclose(f);
}


void HienThi(Dijkstra d)
{
    cout << "Do thi vua nhap la:" << endl;
    cout << "- So dinh cua do thi: " << d.graph.N << endl;
    cout << "- Ma tran trong so cua do thi:" << endl;
    for (int i = 0; i < d.graph.N; i++)
    {
        for (int j = 0; j < d.graph.N; j++)
        {
            if (d.graph.A[i][j] == VOCUNG)
                cout << 0 << "\t";
            else 
                cout << d.graph.A[i][j] << "\t";
        }
        cout << endl;
    }
}


int main()
{
    Dijkstra d;

    Nhap(d);
    

    HienThi(d);

    return 0;
}
