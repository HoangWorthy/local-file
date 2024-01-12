#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct sinhvien
{
    char mssv[5];
    char hoten[10];
    char gioitinh[5];
    char lop[5];
    float dtb;
};
typedef struct sinhvien sv;
void nhapsv(sv a[],int m)
{
    for(int i = 0;i < m;i++){
        scanf("%s",&a[i].mssv);
        scanf("%s",&a[i].hoten);
        scanf("%s",&a[i].gioitinh);
        scanf("%s",&a[i].lop);
        scanf("%f",&a[i].dtb);
    }
}
void xuatsv(sv a[], int m)
{
    for(int i = 0;i < m;i++){
        printf("%s\n%s\n%s\n%s\n%f\n",a[i].mssv,a[i].hoten,a[i].gioitinh,a[i].lop,a[i].dtb);
    }
}
void xuatsvtren5(sv a[], int m)
{
    for(int i = 0;i < m;i++){
        if(a[i].dtb > 5)
        printf("%s\n%s\n%s\n%s\n%f\n",a[i].mssv,a[i].hoten,a[i].gioitinh,a[i].lop,a[i].dtb);
    }
}

int demnu(sv a[], int m)
{
    for(int i = 0;i < m;i++){
        if(*a[i].gioitinh == 'x')
        printf("%s\n%s\n%s\n%s\n%f\n",a[i].mssv,a[i].hoten,a[i].gioitinh,a[i].lop,a[i].dtb);
    }
}

void sapxep(sv a[], int m, sv n)
{
    int c = 1;
    float k;
    while(c!=0){
        c = 0;
        for(int i = 0;i < m-1;i++){
            if (a[i].dtb > a[i+1].dtb){
                c++;
                n = a[i];
                a[i] = a[i+1];
                a[i+1] = n;
            }
        }
    }
}

void max(sv a[],int m)
{
    printf("%s\n%s\n%s\n%s\n%f\n",a[m-1].mssv,a[m-1].hoten,a[m-1].gioitinh,a[m-1].lop,a[m-1].dtb);
}

int main()
{
    int m;
    scanf("%d",&m);
    sv a[m];
    sv n;
    nhapsv(a,m);
    xuatsv(a,m);
    xuatsvtren5(a,m);
    demnu(a,m);
    sapxep(a,m,n);
    max(a,m);
    return 0;
}