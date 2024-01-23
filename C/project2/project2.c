//Note:
// 1.Check char o, it's gonna run the switch if o = 12 or o = 13...
// 2.Fix the login and register, username should be all downcase. Should add validation.
// 3.Looping and exiting the loop in login and register and also other functions can retry it.
// 4.Add classes into the program.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct class{
    char name[20];
    char teacher[20];
    char students[500];
};
struct sinhvien
{
    char id[10];
    char name[50];
    char semester[3];
    char coursename[10];
};
struct accounts
{
    char name[30];
    char username[20];
    char passowrd[20];
    char perm[2];
};
FILE *fp;
int l = 0;
int line = 0;
char perm[2];
typedef struct sinhvien sv;
typedef struct accounts acc;

void createAcc()
{
    char d[30],a[30],b[30],s[10];
    fgets(d,sizeof(d),stdin);
    d[strcspn(d,"\n")] = '\0';
    fgets(d,sizeof(d),stdin);
    a[strcspn(a,"\n")] = '\0';
    fgets(b,sizeof(b),stdin);
    b[strcspn(b,"\n")] = '\0';
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")] = '\0';
    fp = fopen("user.data","a");
    fprintf(fp,"%s-%s-%s-%s\n",d,a,b,s);
    fclose(fp);
}

void login(acc all[])
{
    char a[20],b[20];
    int i;
    int k = 0;
    bool c = false;
    while(!c){
        printf("Username: ");
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\n")] = '\0';
        printf("Password: ");
        fgets(b,sizeof(b),stdin);
        b[strcspn(b,"\n")] = '\0';
        for(i = 0;i < line;i++){ 
            if (strcmp(a,all[i].username)==0 && strcmp(b,all[i].passowrd) != 0){
                printf("Wrong password!\n");
                k++;
            }
            else if (strcmp(a,all[i].username)==0 && strcmp(b,all[i].passowrd) == 0){
            c = true;
            k++;
            strcpy(perm,all[i].perm);
            perm[strcspn(perm,"\n")] = '\0';
            printf("Welcome %s to the program\n",all[i].name);
            break;
            }
        }
        if (k == 0) printf("There is no account with that username\n");
        k = 0;
    }
}

void registers(acc all[])
{
    int i;
    bool c = false;
    char a[20],b[20],d[20],s[20];
    while(true){
        c = false;
        printf("Username: ");
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\n")] = '\0'; 
        printf("Password: ");
        fgets(b,sizeof(b),stdin);
        b[strcspn(b,"\n")] = '\0';
        printf("Retype password: ");
        fgets(s,sizeof(s),stdin);
        s[strcspn(s,"\n")] = '\0';
        if (strcmp(b,s) != 0){
            printf("Password does not match. Please retype\n");
            continue;
        }
        if (strcmp(a,b) == 0) {
            printf("Username cannot match the password\n");
            continue;
        }
        for(i = 0;i < line;i++) if(strcmp(a,all[i].username)==0){
            printf("Username occupied\n");
            c = true;
            break;
        }
        if (c) continue;
        if (strchr(a,' ') == NULL && strchr(b,' ') == NULL) break;
        else printf("Wrong input! Please retry\n");
    }
    printf("Successful\n");
    printf("Please enter your name: ");
    fgets(d,sizeof(d),stdin);
    d[strcspn(d,"\n")] = '\0';
    fp = fopen("user.data","a");
    fprintf(fp,"%s-%s-%s-2\n",d,a,b);
    fclose(fp);
    strcpy(perm,"2");
}
void stringProcessing2(acc all[], char c[], int line)
{
    sscanf(c,"%[^-]-%[^-]-%[^-]-%[^-\n]",all[line].name,all[line].username,all[line].passowrd,all[line].perm);
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
    //printf("%s-%s-%s-%s",all[1].name,all[1].username,all[1].passowrd,all[1].perm);
}

void addSV(sv a[], sv r[])
{
    int q;
    int p = 1;
    printf("Number of new students: ");
    scanf("%d",&q);
    fp = fopen("sinhvien.txt","a");
    int i,j;
    for(i = 0;i < q;i++){
        while(p != 0){
            p = 0;
            printf("ID: ");
            scanf("%s",&a[i].id);
            for(j = 0;j < l;j++){
                if (strcmp(a[i].id,r[j].id) == 0){
                    printf("ID Occupied! Please retry.\n");
                    p++;
                }
            }
        }
        getchar();
        printf("Name: ");
        fgets(a[i].name, sizeof(a[i].name), stdin);
        a[i].name[strcspn(a[i].name, "\n")] = '\0';
        printf("Semester: ");
        scanf("%s",&a[i].semester);
        printf("Course Name: ");
        scanf("%s",&a[i].coursename);
        fprintf(fp,"%s-%s-%s-%s\n",a[i].id,a[i].name,a[i].semester,a[i].coursename);
    }
    printf("Successfully!\n");
    fclose(fp);
}

void stringProcessing1(char c[],sv r[], int l)
{
    sscanf(c,"%[^-]-%[^-]-%[^-]-%[^-\n]",r[l].id,r[l].name,r[l].semester,r[l].coursename);
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
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Semester\n");
    printf("4. Search by Course name\n");
    scanf("%s",&o);
    switch(o){
        case '1': {
            printf("Type ID: ");
            scanf("%s",&c);  
            for(i = 0;i < l;i++) if (strcmp(r[i].id,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case '2': {
            printf("Type name: ");
            getchar();
            fgets(c,sizeof(c),stdin);
            c[strcspn(c,"\n")] = '\0';
            for(i = 0;i < l;i++) if (strcmp(r[i].name,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case '3': {
            printf("Type semester: ");
            scanf("%s",&c);  
            for(i = 0;i < l;i++) if (strcmp(r[i].semester,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        case '4': {
            printf("Type coursename: ");
            scanf("%s",&c);  
            for(i = 0;i < l;i++) if (strcmp(r[i].coursename,c)==0) printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
            break;
        }
        default:
            printf("Wrong!");
    }
}

void update(sv r[])
{
    char a[50];
    int k;
    int i;
    char c[100];
    char o;
    printf("1. Update ID\n");
    printf("2. Update Name\n");
    printf("3. Update Semester\n");
    printf("4. Update Course name\n");
    printf("5. Update All\n");
    scanf("%s",&o);
    printf("Type ID: ");
    scanf("%s",&c);
    for(i = 0;i < l;i++) if (strcmp(r[i].id,c)==0) {
        k = i;
        break;
    }
    switch(o){
        case '1':{
            printf("Type Updated ID: ");
            scanf("%s",&a);
            strcpy(r[k].id,a);
            break;
        }
        case '2':{
            printf("Type Updated Name: ");
            getchar();
            fgets(a,sizeof(a),stdin);
            a[strcspn(a,"\n")] = '\0';
            strcpy(r[k].name,a);
            break;
        }
        case '3':{
            printf("Type Updated Semester: ");
            scanf("%s",&a);
            strcpy(r[k].semester,a);
            break;
        }
        case '4':{
            printf("Type Updated Course name: ");
            scanf("%s",&a);
            strcpy(r[k].coursename,a);
            break;
        }
        case '5':{
            char x[10],b[10],d[10],e[10];
            printf("Type Updated ID: ");
            scanf("%s",&x);
            strcpy(r[k].id,x);
            printf("Type Updated Name: ");
            scanf("%s",&b);
            strcpy(r[k].name,b);
            printf("Type Updated Semester: ");
            scanf("%s",&d);
            strcpy(r[k].semester,d);
            printf("Type Updated Course name: ");
            scanf("%s",&e);
            strcpy(r[k].coursename,e);
            break;
        }
    }
    fp = fopen("sinhvien.txt","w");
    for(i = 0; i < l; i++){
        fprintf(fp,"%s-%s-%s-%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename);
    }
    fclose(fp);
    printf("Successfully\n");
}

void delete(sv r[])
{
    int i;
    char id[10];
    printf("Type ID: ");
    scanf("%s",&id);
    fp = fopen("sinhvien.txt","w");
    for(i = 0; i < l; i++){
        if (strcmp(r[i].id,id) == 0) continue;
        fprintf(fp,"%s-%s-%s-%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename);
    }
    l--;
    fclose(fp);
    printf("Successfully!\n");
}

void report(sv r[])
{
    int i;
    for(i = 0; i < l; i++){
        printf("%s | %s | %s | %s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
    }
}

int main()
{
    sv a[100];
    sv r[100];
    acc all[100];
    char lg;
    scanf("%s",&lg);
    getchar();
    switch (lg)
    {
        case '1':{
            getUserAccounts(all);
            login(all);
            break;
        }
        case '2':{
            registers(all);
            getUserAccounts(all);
            break;
        }
    }
    getDatabase(r);
    char o;
    while(strcmp(perm,"2") == 0){
        printf("1. Search\n");
        printf("2. Exit\n");
        scanf("%s",&o);
        switch (o)
        {
        case '1':
            search(r);
            break;
        case '2':
            exit(1);
        }
    }
    while(strcmp(perm,"1") == 0){
        printf("1. Search\n");
        printf("1. Report\n");
        printf("3. Exit\n");
        scanf("%s",&o);
        switch (o)
        {
            case '1':
                search(r);
                break;
            case '2':
                report(r);
                break;
            case '3':
                exit(1);
        }
    }
    while(strcmp(perm,"0") == 0){
        printf("1. Add more students\n");
        printf("2. Update students\n");
        printf("3. Delete students\n");
        printf("4. Search students\n");
        printf("5. Student reports\n");
        printf("6. Create accounts\n");
        printf("7. Exit\n");
        scanf("%s",&o);
        switch (o)
        {
            case '1':
                addSV(a,r);
                getDatabase(r);
                break;
            case '2':
                update(r);
                getDatabase(r);
                break;
            case '3':
                delete(r);
                getDatabase(r);
                break;
            case '4':
                search(r);
                break;
            case '5':
                report(r);
                break;
            case '6':
                createAcc();
                break;
            case '7':
                exit(1);
        }
    }
}