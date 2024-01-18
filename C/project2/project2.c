#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct sinhvien
{
    char id[10];
    char name[50];
    char semester[3];
    char coursename[10];
};
struct accounts
{
    char username[20];
    char passowrd[20];
    char perm[10];
};
FILE *fp;
int l = 0;
int line = 0;
typedef struct sinhvien sv;
typedef struct accounts acc;


void registers()
{
    char a[20],b[20];
    while(true){
        fgets(a,sizeof(a),stdin);
        fgets(b,sizeof(b),stdin);
        if (strchr(a,' ') == NULL && strchr(b,' ') == NULL) break;
        else printf("Wrong input! Please retry\n");
    }

}
void stringProcessing2(acc all[], char c[], int line)
{
    sscanf(c,"%[^-]-%[^-]-%[^-]",all[line].username,all[line].passowrd,all[line].perm);
}

void getUserAccounts(acc all[])
{
    char c[100];
    fp = fopen("user.data","r");
    while (fgets(c,sizeof(c),fp) != NULL)
    {
        stringProcessing2(all,c,line);
        line++;
    }
    fclose(fp);
    printf("%s-%s-%s",all[0].username,all[0].passowrd,all[0].perm);
}

void addSV(sv a[])
{
    int q;
    scanf("%d",&q);
    fp = fopen("sinhvien.txt","a");
    int i;
    for(i = 0;i < q;i++){
        scanf("%s",&a[i].id);
        getchar();
        fgets(a[i].name, sizeof(a[i].name), stdin);
        a[i].name[strcspn(a[i].name, "\n")] = '\0';
        scanf("%s",&a[i].semester);
        scanf("%s",&a[i].coursename);
        fprintf(fp,"%s-%s-%s-%s\n",a[i].id,a[i].name,a[i].semester,a[i].coursename);
    }
    fclose(fp);
}

void stringProcessing1(char c[],sv r[], int l)
{
    sscanf(c,"%[^-]-%[^-]-%[^-]-%[^-]",r[l].id,r[l].name,r[l].semester,r[l].coursename);
}

void getDatabase(sv r[])
{
    fp = fopen("sinhvien.txt","r");
    char c[100];
    int i,j;
    while(fgets(c,sizeof(c),fp)!= NULL){
        stringProcessing1(c,r,l);
        l++;
    }
    fclose(fp);
    //printf("%s-%s-%s-%s",r[0].id,r[0].name,r[0].semester,r[0].coursename);
}


void search(sv r[])
{
    char c[100];
    int i;
    char o;
    scanf("%d",&o);
    scanf("%s",&c);
    switch(o){
        case '1': {
            for(i = 0;i < l;i++) if (strcmp(r[i].id,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case '2': {
            for(i = 0;i < l;i++) if (strcmp(r[i].name,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case '3': {
            for(i = 0;i < l;i++) if (strcmp(r[i].semester,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case '4': {
            for(i = 0;i < l;i++) if (strcmp(r[i].coursename,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
    }
}

void update(sv r[])
{
    char a[10];
    int k;
    int i;
    char c[100];
    char o;
    scanf("%s",&o);
    scanf("%s",&c);
    scanf("%s",&a);
    for(i = 0;i < l;i++) if (strcmp(r[i].id,c)==0) {
        k = i;
        break;
    }
    switch(o){
        case '1':{
            strcpy(r[k].id,a);
            break;
        }
        case '2':{
            strcpy(r[k].name,a);
            break;
        }
        case '3':{
            strcpy(r[k].semester,a);
            break;
        }
        case '4':{
            strcpy(r[k].coursename,a);
            break;
        }
        case '5':{
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
        fprintf(fp,"%s-%s-%s-%s",r[i].id,r[i].name,r[i].semester,r[i].coursename);
    }
    fclose(fp);
}

void delete(sv r[])
{
    int i;
    char id[10];
    scanf("%s",&id);
    fp = fopen("sinhvien.txt","w");
    for(i = 0; i < l; i++){
        if (strcmp(r[i].id,id) == 0) continue;
        fprintf(fp,"%s-%s-%s-%s",r[i].id,r[i].name,r[i].semester,r[i].coursename);
    }
    l--;
    fclose(fp);
}

void report(sv r[])
{
    int i;
    for(i = 0; i < l; i++){
        printf("%s | %s | %s | %s",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
    }
}

int main()
{
    sv a[100];
    sv r[100];
    acc all[100];
    // char o;
    /*while(true){
        scanf("%s",&o);
        getDatabase(r);
        switch (o)
        {
            case '1':{
                addSV(a);
                getDatabase(r);
                break;
            }
            case '2':{
                search(r);
                break;
            }
            case '3':{
                update(r);
                delete(r);
                getDatabase(r);
                break;
            }
            case '4':{
                report(r);
                break;
            }
            case '5':
                exit(1);
        }
        return 0;
    }*/
    // addSV(a);
    // getDatabase(r);
    // search(r);
    // update(r);
    // delete(r);
    // getDatabase(r);
    // report(r);
    //getUserAccounts(all);
    registers();
}