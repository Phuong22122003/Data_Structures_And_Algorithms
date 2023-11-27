#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int i, j, n, a[50], frames[5], frame, k, available, count = 0;
    printf("\nNhap so phan tu chuoi tham chieu: \n");
    cin >> n;
    printf("\nNhap vao chuoi tham chieu: \n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    cout << "\nNhap vao so khung trang: \n";
    cin >> frame;
    for (int i = 0; i < frame; i++)
    {
        frames[i] = -1;
    }
    j = 0;
    printf("\t|Chuoi|\t|Khung trang");
    for(k =0;k<frame-1;k++)
        printf("\t");
    printf("|\n");
    for (i = 1; i <= n; i++)
    {
        printf("\t|  %d  |\t", a[i]);
        available = 0;
        for (k = 0; k < frame; k++)
            if (frames[k] == a[i])
                available = 1;
        if (available == 0)
        {
            frames[j] = a[i];
            j = (j + 1) % frame;
            count++;
            cout << "|";
            for (k = 0; k < frame; k++)
                printf("%d\t", frames[k]);
            printf("| F");
        }
        else
        {
            printf("|");
            for (k = 0; k < frame; k++)
                printf("%d\t", frames[k]);
            printf("|");
        }
        printf("\n");
    }
    printf("so trang loi la: %d\n", count);
    getch();
}