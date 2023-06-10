#include<iostream>
#include<math.h>
#include<conio.h>
#include<fstream>
using namespace std;
void quick_sort(int A[],int start,int end)
{
    int mid,i,j;
    i=start;
    j=end;
    mid=(start+end)/2;
    do
    {
        while(A[i]<A[mid])i++;//không dùng dấu bằng vì bị lặp vô hạn ,xắp xếp sai 
        while(A[j]>A[mid])j--;//vd :4 6 5 7  i=0,j=3,mid=1 ->i=3,j=2 thoát và chạy lại giống vậy
        if(i<=j)
        {
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<end)quick_sort(A,i,end);
    if(j>start)quick_sort(A,start,j);
}

void SortFile(ifstream &ta,ofstream &tb1,ofstream &tb2)
{
    int arr[3],i;
    while(!ta.eof())
    {
        for(i=0;i<3&&!ta.eof();i++)
        {
            ta>>arr[i];
        }
        quick_sort(arr,0,i-1);
        for(int j=0;j<i;j++)
            tb1<<arr[j]<<" ";
        if(i<3)break;
        for(i=0;i<3&&!ta.eof();i++)
        {
            ta>>arr[i];
        }
        quick_sort(arr,0,i-1);
        for(int k=0;k<i;k++)tb2<<arr[k]<<" ";
        if(i<3)break;
    }

}
void Merge(ifstream &s1,ifstream &s2,ofstream &d1,ofstream &d2,int length)
{
    int temp1,temp2,i,j;
    s1.seekg(ios::beg);
    s2.seekg(ios::beg);
    d1.seekp(ios::beg);
    d2.seekp(ios::beg);
    while(!s1.eof()&&!s2.eof())
    {
        s1>>temp1;
        s2>>temp2;
        for(i=1,j=1;i<=length&&j<=length;)
        {
            if(s2.eof())
            {
                while(!s1.eof())
                {
                    d2<<temp1<<" ";
                    s1>>temp1;
                }
                return;
            }
            if(temp1<temp2)
            {
                d1<<temp1<<" ";
                if(i<length)s1>>temp1;
                if(s1.eof())
                {
                    while(!s2.eof())
                    {
                        d1<<temp2<<" ";
                        s2>>temp2;
                    }
                    return;
                }
                i++;
            }else
            {
                d1<<temp2<<" ";
                if(j<length) s2>>temp2;
                if(s2.eof())
                {
                    while(!s1.eof())
                    {
                        d1<<temp1<<" ";
                        s1>>temp1;
                    }
                    return;
                }
                j++;
            }
        }

        // xữ lý các số còn xót
        if(i==length+1)
        {
            while(j<=length&&!s2.eof())
            {
                d1<<temp2<<" ";
                if(j<length)s2>>temp2;
                j++;
            }
        }
        else
        {
            while(i<=length&&!s1.eof())
            {
                d1<<temp1<<" ";
                if(i<length)s1>>temp1;
                i++;
            }
        }
        s1>>temp1;
        s2>>temp2;
        cout<<temp1<<" "<<temp2<<endl;
        for(i=1,j=1;i<=length&&j<=length;)
        {
            cout<<"a";
            if(s2.eof())
            {
                while(!s1.eof())
                {
                    d2<<temp1<<" ";
                    s1>>temp1;
                }
                return;
            }
            if(temp1<temp2)
            {
                d2<<temp1<<" ";
                if(i<length)s1>>temp1;
                if(s1.eof())
                {
                    while(!s2.eof())
                    {
                        d2<<temp2<<" ";
                        s2>>temp2;
                    }
                    return;
                }
                i++;
            }else
            {
                d2<<temp2<<" ";
                if(j<length) s2>>temp2;
                if(s2.eof())
                {
                    while(!s1.eof())
                    {
                        d1<<temp1<<" ";
                        s1>>temp1;
                    }
                    return;
                }
                j++;
            }
        }

        if(i==length+1)
        {
            while(j<=length&&!s2.eof())
            {
                d2<<temp2<<" ";
                if(j<length)s2>>temp2;
                j++;
            }
        }
        else
        {
            while(i<=length&&!s1.eof())
            {
                d2<<temp1<<" ";
                if(i<length)s1>>temp1;
                i++;
            }
        }

    }
}
void merge_sort(ifstream &f_Tb1,ifstream &f_Tb2,ofstream &f_Ta1,ofstream &f_Ta2, int n){
    int a,b,i(1),j(1);  

    while(!f_Tb1.eof() && !f_Tb2.eof()){
        f_Tb1 >> a; 
        f_Tb2 >> b;
        i=j=1; 
       //======= Ghi vao file Ta1 ===========//
        while(i <= n && j <= n){ 
            if(f_Tb2.eof()){ // De xu ly khi Tb2 toi cuoi file roi doc het r�i 
                while(!f_Tb1.eof()){
                    f_Ta1 << a << " ";
                    f_Tb1 >> a;    // 
                }
                return; 
            }
            
            if(a > b){ 
                f_Ta1 << b << " "; 
                if(j < n){         
                    f_Tb2 >> b; 
                } 
                
                j++; 
                
                if(f_Tb2.eof()){ 
                    while(!f_Tb1.eof()){ 
                        f_Ta1 << a << " ";
                        f_Tb1 >> a;
                    }
                    return;
                }
            }
            else{ // ( a <= b ) 
                f_Ta1 << a << " "; 
                if(i < n){
                    f_Tb1 >> a;
                }
                i++;

                if(f_Tb1.eof()){
                    while(!f_Tb2.eof()){
                        f_Ta1 << b << " ";
                        f_Tb2 >> b;
                    }
                    return;
                }

            }
            
//            if(f_Tb1.eof() && f_Tb2.eof())  return;
            
            while(i==n+1 && j<=n){  
                if(f_Tb2.eof()) return; // ?
                f_Ta1 << b << " ";
                if(j<n) f_Tb2 >> b;
                j++;
            }
            while(j==n+1 && i<=n){
//                if(f_Tb1.eof()) return;
                f_Ta1 << a << " ";
                if(i<n) f_Tb1 >> a;
                i++;
            }
        }
        
        
        //==== Ghi vao file Ta2 ======//
        f_Tb1 >> a;
        f_Tb2 >> b;
        i=j=1;
        while(i <= n && j<=n){
            if(f_Tb2.eof()){
                while(!f_Tb1.eof()){
                    f_Ta2 << a << " ";
                    f_Tb1 >> a;
                }
                return;
            }
            
            if(a > b){
                f_Ta2 << b << " ";     
                if(j < n){             
                    f_Tb2 >> b;   
                } 
                j++;         
                if(f_Tb2.eof()){
                    while(!f_Tb1.eof()){
                        f_Ta2 << a << " ";
                        f_Tb1 >> a;
                    }
                    return;
                }
                //
            }
            else{
                f_Ta2 << a << " "; 
                if(i<n){
                    f_Tb1 >> a; 
                }
                i++;
                 // 
                if(f_Tb1.eof()){
                    while(!f_Tb2.eof()){
                        f_Ta2 << b << " ";
                        f_Tb2 >> b;
                    }
                    return;
                }
                //
            }
            if(f_Tb1.eof() && f_Tb2.eof())  break;
            while(i==n+1 && j<=n){
                if(f_Tb2.eof()) return;
                f_Ta2 << b << " ";
                if(j<n) f_Tb2 >> b;
                j++;
            }
            while(j==n+1 && i<=n){
                if(f_Tb1.eof()) return;
                f_Ta2 << a << " ";
                if(i<n) f_Tb1 >> a;
                i++;
            }
        }          
    }
}
void ExternalSorting(int length)
{
    ifstream ta("ta.txt");
    ofstream tb1("tb1.txt");
    ofstream tb2("tb2.txt");
    SortFile(ta,tb1,tb2);
    ta.close();
    tb1.close();
    tb2.close();
    while(1)
    {
        ifstream tb1("tb1.txt");
        ifstream tb2("tb2.txt");
        ofstream ta1("ta1.txt");
        ofstream ta2("ta2.txt");
        merge_sort(tb1,tb2,ta1,ta2,length);
        tb1.close();
        tb2.close();
        ta1.close();
        ta2.close();
        ifstream ta2a("ta2.txt");
        ta2a.seekg(0,ios::end);
        if(ta2a.tellg()==0)
        {
            cout<<"XONG";
            ta2a.close();
            break;
        }
        length*=2;
        ifstream ta11("ta1.txt");
        ifstream ta21("ta2.txt");
        ofstream tb11("tb1.txt");
        ofstream tb21("tb2.txt");
        merge_sort(ta11,ta21,tb11,tb21,length);
        tb11.close();
        tb21.close();
        ta11.close();
        ta21.close();
        length=length*2;
    }
}
int main()
{
    ExternalSorting(3);
    return 0;
}