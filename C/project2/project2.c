#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct sinhvien
{
    char id[5];
    char name[10];
    char semester[2];
    char coursename[5];
};
FILE *fp;
typedef struct sinhvien sv;
void nhapsv(sv a[])
{
    int i;
    for(i = 0;i < 2;i++){
        scanf("%s",&a[i].id);
        scanf("%s",&a[i].name);
        scanf("%s",&a[i].semester);
        scanf("%s",&a[i].coursename);
    }
    fp = fopen("sinhvien.txt","w");
    for (i = 0;i < 2;i++){
        fprintf(fp,"%s\t%s\t%s\t%s\n",a[i].id,a[i].name,a[i].semester,a[i].coursename);
    }
    fclose(fp);
}
/*void report(sv a[])
{
    for(int i = 0;i < sizeof(a);i++){
        printf("%s\n%s\n%s\n%s\n%f\n",a[i].id,a[i].name,a[i].semester,a[i].coursename);
    }
}

void fands(sv a[], int m)
{
    for(int i = 0;i < sizeof(a);i++){
        printf("");
    }
}
*/

void search(sv a[]){
    char c[1000],p[1000];
    int k=0;
    fp = fopen("sinhvien.txt","r");
    fgets(c,1000,fp);
    while(c[k]!='\t'){
        p[k] = c[k];
        k++;
    }
    printf("%s",p);
    fclose(fp);
}

void update(sv a[]){
    char c[100];
    fp = fopen("sinhvien.txt","r");
    fclose(fp);
}

int main()
{
    sv a[100];
    //nhapsv(a);
    //update(a);
    search(a);
    return 0;
}