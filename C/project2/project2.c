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
int l;
typedef struct sinhvien sv;
void addSinhvien(sv a[])
{
    int q;
    scanf("%d",&q);
    fp = fopen("sinhvien.txt","a");
    int i;
    for(i = 0;i < q;i++){
        scanf("%s",&a[i].id);
        scanf("%s",&a[i].name);
        scanf("%s",&a[i].semester);
        scanf("%s",&a[i].coursename);
        fprintf(fp,"%s\t%s\t%s\t%s\n",a[i].id,a[i].name,a[i].semester,a[i].coursename);
    }
    fclose(fp);
}

void stringProcessing(char c[],sv r[], int l)
{
    char* token = strtok(c,"\t");
    int k = 0;
    while(token != NULL){
        if (k==0) strcpy(r[l].id, token);
        else if (k == 1) strcpy(r[l].name, token);
        else if (k == 2) strcpy(r[l].semester, token);
        else if (k == 3) strcpy(r[l].coursename, token);
        token = strtok(0, "\t");
        k++;
    }
}

void getDatabase(sv r[])
{
    fp = fopen("sinhvien.txt","r");
    char c[100];
    int i,j;
    while(fgets(c,15,fp)!= NULL){
        stringProcessing(c,r,l);
        l++;
    }
    fclose(fp);
    //printf("%s\t%s\t%s\t%s",r[1].id,r[1].name,r[1].semester,r[1].coursename);
}

void report()
{

}

void search(sv r[], char c[], int o)
{
    int i;
    switch(o){
        case 1: {
            for(i = 0;i < l;i++) if (strcmp(r[i].id,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case 2: {
            for(i = 0;i < l;i++) if (strcmp(r[i].name,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case 3: {
            for(i = 0;i < l;i++) if (strcmp(r[i].semester,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case 4: {
            for(i = 0;i < l;i++) if (strcmp(r[i].coursename,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
    }
}

void update(sv r[], char c[],int o)
{
    int k;
    int i;
    char k[100];
    getDatabase(r);
    for(i = 0;i < l;i++) if (strcmp(r[i].id,c)==0) {
        k = i;
        break;
    }
    switch(o){
        case 1:{
            strcpy(r[k].id,c);
            break;
        }
        case 2:{
            strcpy(r[k].name,c);
            break;
        }
        case 3:{
            strcpy(r[k].semester,c);
            break;
        }
        case 4:{
            strcpy(r[k].coursename,c);
            break;
        }
        case 5:{
            char a[10],b[10],d[10],e[10];
            scanf("%s",&a);
            strcpy(r[k].id,a);
            scanf("%s",&b);
            strcpy(r[k].name,b);
            scanf("%s",&d);
            strcpy(r[k].semester,d);
            scanf("%s",&e);
            strcpy(r[k].coursename,e);
            break;
        }
    }
    fp = fopen("sinhvien.txt","w");
    for(i = 0; i < l; i++){
        fprintf(fp,"%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename);
    }
    fclose(fp);
}

int main()
{
    sv a[100];
    sv r[100];
    //nhapsv(a);
    getDatabase(r);
    //report();
    //update(a);
    //search(b);
    return 0;
}