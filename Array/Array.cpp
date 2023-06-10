#include<iostream>
using namespace std;
#define MAXLIST 100
template<typename T>class Array
{
    private:
        T *ptr;
        int number;
        int index_last;
    public:
        Array()
        {
            ptr=NULL;
            number=0;
            index_last=-1;
        }
        Array(int number_in)
        {
            ptr=new T[number_in];
            number=number_in;
            index_last=-1;
        }
        int GetIndexLast(){return index_last;}
        T& operator[](int i)
        {
            if (i < 0 || i > index_last)
                return new T;
            return ptr[i];
        }

        void push(T New)
        {
            if (index_last == number - 1) {
                T* temp;
                temp = new T[number + 10]; // tạo mảng mới 
                for (int i = 0; i < number; i++) {
                    temp[i] = ptr[i];
                }
                temp[index_last + 1] = New;
                delete[] ptr; // xóa mảng cũ
                ptr = temp; // gán con trỏ vào mảng mới
                index_last++;
                number+=10;
            }
            else {
                ptr[++index_last] = New;
            }
        }

        void erase(int i)
        {
            if (i < 0 || i > index_last)
                return;
            if (i == index_last) {
                index_last--;
                return;
            }
            for (int k = i; k < index_last; k++) {
                ptr[k] = ptr[k + 1];
            }
            index_last--;
        }
        void show()
        {
            cout<<"number"<<number<<"  index_last:"<<index_last<<endl;
            for(int i=0;i<=index_last;i++)cout<<ptr[i]<<endl;//<<" "<<ptr[i].b<<endl;
        }
        void destroy()
        {
            delete []ptr;
        }
};;
//Cấp phát tĩnh
struct StaticList
{
    int n;
    int nodes[MAXLIST];
};
//cấp phát động
struct DinamicList
{
    int n;
    int* nodes;
};
struct SV
{
    string name;
    string gender;
    double score;
};
struct SDList
{
    int n;
    int* nodes[MAXLIST];
};
int Insert1(StaticList& List,int data,int index)
{
    if(List.n==MAXLIST||index>List.n||index<0)return -1;
    for(int i=List.n-1;i>=index;i--)List.nodes[i+1]=List.nodes[i];
    List.nodes[index]=data;
    List.n++;
    return 1;
}
int main()
{
    return 0;
}