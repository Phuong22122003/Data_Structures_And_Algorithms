#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int i, j, n, a[50], frames[5], frame, k, available, count = 0;
    int time[50] = {0}, max = 0, index, empty = 0, tmp;
    printf("\nNhap so phan tu chuoi tham chieu: \n");
    cin >> n;
    printf("\nNhap vao chuoi tham chieu: \n");
    for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
    cout << "\nNhap vao so khung trang: \n";
    cin >> frame;
    for (int i = 0; i < frame; i++)   frames[i] = -1;
    j = 0;
    printf("\t|Chuoi|\t|Khung trang");
    for (k = 0; k < frame - 1; k++)printf("\t");
    printf("|\n");
    for (i = 1; i <= n; i++){
        printf("\t|  %d  |\t", a[i]);
        available = 0;
        for (k = 0; k < frame; k++)if (frames[k] == a[i])available = 1; // Same value with value in frames
        if (available == 0){
            empty = 0;
            for (k = 0; k < frame; k++){ // check to find empty frame
                if (frames[k] == -1){frames[k] = a[i];empty = 1;break;}}
            if (empty == 0){
                max = 0;
                for (k = 0; k < frame; k++){
                    tmp = frames[k];
                    if (max == 0){
                        max = time[tmp];index = k;
                    }
                    else if (max <= time[tmp]){
                        max = time[tmp];index = k;
                    }
                }
                frames[index] = a[i];
            }
            cout << "|";
            for (k = 0; k < frame; k++)
                printf("%d\t", frames[k]);
            cout<<"|";
            if (empty == 0){
                printf("F");count++;
            }
        }
        else
        {
            printf("|");
            for (k = 0; k < frame; k++)printf("%d\t", frames[k]);
            printf("|");
        }
        time[a[i]]=-1;
        for (k = 0; k < frame; k++)if (frames[k] != -1)time[frames[k]]++;
        printf("\n");
    }
    printf("so trang loi la: %d\n", count);
    getch();
}