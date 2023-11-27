#include <iostream>
using namespace std;
struct Process
{
    int come;
    int start;
    int finish;
    int brustime=0;
    int time_remaining;
};
bool isHappenEvent(int time, int event[])
{
    for (int i = 0; i < 100; i++)
    {
        if (event[i] == time)
            return true;
    }
    return false;
}
bool finishAll(Process arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].time_remaining != 0)
            return false;
    }
    return true;
}
int main(int argc, char *argv)
{
    int n;
    cout << "Nhap so tien trinh:";
    cin >> n;
    Process arr[10];
    int event[100]={-1};
    for (int i = 0; i < n; i++)
    {
        cout << "Tien trinh " << i << endl;
        cout << "Nhap thoi gian den: ";
        cin >> arr[i].come;
        cout << "Nhap thoi gian can thuc thi (brushtime): ";
        cin >> arr[i].brustime;
        arr[i].time_remaining = arr[i].brustime;
        event[i] = arr[i].come;
    }
    int time = 0, min = 0, index = 0, tmp = n-1;
    while (!finishAll(arr,n))
    {
        if (isHappenEvent(time, event))
        {
            min =0;
            for (int i = 0; i < n; i++)
            {
                if ((min == 0 || arr[i].time_remaining < min && arr[i].time_remaining > 0) && arr[i].come <= time)
                {
                    min = arr[i].time_remaining;
                    index = i;
                }
            }
            arr[index].start = time;
        }
        arr[index].time_remaining--;
        time++;
        if (arr[index].time_remaining == 0)
        {
            arr[index].finish = time;
            tmp ++;
            event[tmp] = time;
        }
        if(time > 10)break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].come <<"   "<<arr[i].start<< "  " << arr[i].finish << endl;
    }
}
