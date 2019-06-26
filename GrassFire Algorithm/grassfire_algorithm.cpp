#include <bits/stdc++.h>
#include <math.h>
#include <vector>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll  long long

using namespace std;




int visited_arr[8][8] = {0};

vector< pair <int,int> > src;
vector< pair <int,int> > dest;



void printarr(int arr1[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(arr1[i][j] == -1)
                cout << "+" ;
            else
                cout << arr1[i][j] ;
            cout << "   ";
        }
        cout << endl;
    }
}

void printvisitarr()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout << visited_arr[i][j] ;
            cout << "   ";
        }
        cout << endl;
    }
}

int main()
{

int arr[8][8] = {0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 0, 0,
                 0, 0,-1,-1,-1,-1, 0, 0,
                 0, 0, 0,-1, 0, 0, 0, 0,
                 0, 0, 0, 0, 0,-1, 0,-1,
                 0, 0, 0, 0, 0, 0,-1,-1,
                 0, 0, 0, 0, 0, 0, 0, 0};
    IOS;
    printarr(arr);

    src.push_back(make_pair(1,1));
    dest.push_back(make_pair(7,7));

    int cnt=0;
    queue< pair<int,int> > q;
    q.push(dest[0]);
    while(!q.empty())
    {
        pair <int,int> val;
        val = q.front();
        q.pop();
        cout << endl;
        cout << "****************" << endl;
        cout << endl;
        cout << val.first << " , " << val.second << endl;
        cout << endl;
       cout << "****************" << endl;
        if (!(val.first+1 >7))
        {
            if(arr[val.first+1][val.second] == 0 && visited_arr[val.first+1][val.second] == 0)
            {
                cout << "updating" << endl;
                arr[val.first+1][val.second] = arr[val.first][val.second] + 1;
                cout << arr[val.first][val.second] + 1 << endl;
                cout << val.first << " " << val.second << endl;
                q.push(make_pair(val.first+1,val.second));
            }
        }

        if (!(val.first-1 <0))
        {
            if(arr[val.first-1][val.second] == 0 && visited_arr[val.first-1][val.second] == 0)
            {
                cout << "updating" << endl;
                arr[val.first-1][val.second] = arr[val.first][val.second] + 1;
                cout << arr[val.first][val.second] + 1 << endl;
                cout << val.first << " " << val.second << endl;
                q.push(make_pair(val.first-1,val.second));
            }
        }
        if (!(val.second+1 >7))
        {
            if(arr[val.first][val.second+1] == 0 && visited_arr[val.first][val.second+1] == 0)
            {
                cout << "updating" << endl;
                arr[val.first][val.second + 1] = arr[val.first][val.second] + 1;
                cout << arr[val.first][val.second] + 1 << endl;
                cout << val.first << " " << val.second << endl;
                q.push(make_pair(val.first,val.second+1));
            }
        }

        if (!(val.first-1 <0))
        {
            if(arr[val.first][val.second-1] == 0 && visited_arr[val.first][val.second-1] == 0)
            {
                cout << "updating" << endl;
                arr[val.first][val.second-1] = arr[val.first][val.second] + 1;
                cout << arr[val.first][val.second] + 1 << endl;
                cout << val.first << " " << val.second << endl;
                q.push(make_pair(val.first,val.second-1));
            }
        }
        visited_arr[val.first][val.second] = 1;
        cout << "Actual Array: " << endl;
        printarr(arr);
        cout << endl;
        cout << "Visited array" << endl;
        printvisitarr();
        cout << endl;
        cout << "------------------------------" << endl;
        cout << endl;

    }
    cout << "shortest path is " << arr[src[0].first][src[0].second] << endl;
}


