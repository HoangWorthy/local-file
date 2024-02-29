//Create a new format of account permission

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>



struct student
{
    char sid[20];
    char name[50];
    bool gender;
    char date[30];
    char pnumber[20];
};
struct accounts
{
    char username[20];
    char password[20];
    char perm[20];
};
FILE *fp;
int l = 0;
int line = 0;
int accountIndex;
typedef struct student sv;
typedef struct accounts acc;

bool checkInput(char a[])
{
    int i;
    for(i = 0;i < strlen(a);i++) if (!isdigit(a[i])) return false;
    return true;
}



//------------------------------------------------------------------------------------------------------------------------
//                                                       Student functions

void addSV(sv r[])
{
    int i,j;
    sv a;
    int q;
    char c[5];
    int p = 1;
    do{
        printf("Number of new students: ");
        scanf("%s",c);
        if(!checkInput(c)) printf("Wrong input. Please retry!\n");
    } while (!checkInput(c));
    q = atoi(c);
    for(i = 0;i < q;i++){
        printf("Student ID: ");
        scanf("%s",a.sid);
        getchar();
        printf("Student name: ");
        fgets(a.name, sizeof(a.name), stdin);
        a.name[strcspn(a.name, "\n")] = '\0';
        printf("Date of birth(DD/MM/YY): ");
        scanf("%s",a.date);
        
    }
}

void stringProcessing1(char c[],sv r[], int l)
{
    sscanf(c,"%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-\n]",r[l].sid,r[l].name,r[l].gender,r[l].date,r[l].pnumber);
}

void getStudentData(sv r[])
{
    fp = fopen("student.data","r");
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
    char c[50];
    int i;
    char o[10];
    int a = 0;
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Semester\n");
    printf("4. Search by Course name\n");
    printf("5. Back");
    while(true){
        scanf("%s",o);
        a = 0;
        if (strcmp(o,"1") == 0) {
            printf("Type ID: ");
            scanf("%s",c);  
            for(i = 0;i < l;i++) 
                if (strcmp(r[i].id,c)==0){
                    a++;
                    printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
                    break;
                }
            if (a == 0) printf("Not found!\n");
        }
        else if (strcmp(o,"2") == 0) {
            printf("Type name: ");
            getchar();
            fgets(c,sizeof(c),stdin);
            c[strcspn(c,"\n")] = '\0';
            for(i = 0;i < l;i++) 
                if (strcmp(r[i].name,c)==0){ 
                    a++;
                    printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
                }
            if (a == 0) printf("Not found!\n");
        }
        else if (strcmp(o,"3") == 0) {
            printf("Type semester: ");
            scanf("%s",c);  
            for(i = 0;i < l;i++)
                if (strcmp(r[i].semester,c)==0){
                    a++;
                    printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
                }
            if (a == 0) printf("Not found!\n");
        }
        else if (strcmp(o,"4") == 0) {
            printf("Type coursename: ");
            scanf("%s",c);  
            for(i = 0;i < l;i++)
                if (strcmp(r[i].coursename,c)==0){
                    a++;
                    printf("%s\t%s\t%s\t%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename); 
                }
            if (a == 0) printf("Not found!\n");
        }
        else if (strcmp(o,"5") == 0) {
            break;
        }
        else printf("Wrong. Please retry!\n");
    }
}

void update(sv r[])
{
    char a[50];
    int k;
    int i;
    char c[100];
    char o[10];
    int n = 0;
    printf("1. Update ID\n");
    printf("2. Update Name\n");
    printf("3. Update Semester\n");
    printf("4. Update Course name\n");
    printf("5. Back\n");
    scanf("%s",o);
    while(n == 0){
        printf("Type ID: ");
        scanf("%s",c);
        for(i = 0;i < l;i++) if (strcmp(r[i].id,c)==0) {
            k = i;
            n++;
            break;
        }
        if (n == 0) printf("ID not found. Please retry!\n");
    }
    n = 0;
    while(true){
        if (strcmp(o,"1") == 0) {
            printf("Type Updated ID: ");
            while(n == 0){
                n = 0;
                scanf("%s",a);
                for(i = 0;i < l;i++)
                    if (strcmp(a,r[i].id) == 0){
                        n++;
                        printf("ID occupied. Please retry!\n");
                        break;
                    }
            }
            strcpy(r[k].id,a);
        }
        else if (strcmp(o,"2") == 0){
            printf("Type Updated Name: ");
            getchar();
            fgets(a,sizeof(a),stdin);
            a[strcspn(a,"\n")] = '\0';
            strcpy(r[k].name,a);
        }
        else if (strcmp(o,"3") == 0){
            while(true){
                printf("Type Updated Semester: ");
                scanf("%s",a);
                if (!checkInput(a)) {printf("Only accept numbers. Please try again!\n");continue;}
                if(atoi(a) > 1 || atoi(a) <= 8) break;
                else printf("Semester should be in range of 1 to 8. Please try again!\n");
            }
                strcpy(r[k].semester,a);
        }
        else if (strcmp(o,"4") == 0){
            printf("Type Updated Course name: ");
            scanf("%s",a);
            strcpy(r[k].coursename,a);
        }
        else if (strcmp(o,"5") == 0){
            break;
        }
        else printf("Wrong option. Please try again!\n");
    }
    fp = fopen("student.data","w");
    for(i = 0; i < l; i++){
        fprintf(fp,"%s-%s-%s-%s\n",r[i].id,r[i].name,r[i].semester,r[i].coursename);
    }
    fclose(fp);
}

void deleteStudent(sv r[])
{
    int i;
    char id[10];
    printf("Type ID: ");
    scanf("%s",&id);
    fp = fopen("student.data","w");
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
//------------------------------------------------------------------------------------------------------------------------
//                                                     Login/register functions

void stringProcessing2(acc all[], char c[], int line)
{
    sscanf(c,"%[^-]-%[^-]-%[^-\n]",all[line].username,all[line].password,all[line].perm);
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
    //printf("%s-%s-%s-%s",all[1].name,all[1].username,all[1].password,all[1].perm);
}

bool passwordValidate(char c[])
{
    int a = 0;
    int b = 0;
    int d = 0;
    int i;
    for(i = 0;i < strlen(c);i++) {
        if (isupper(c[i])) a++;
        else if (isdigit(c[i])) b++;
        else if (!isalnum(c[i])) d++;
    }
    if (strchr(c,' ') != NULL) {printf("Password should not contain spaces!\n");return false;}
    if (a > 0 && b > 0 && d > 0) return true;
    else {printf("Password must contain uppercase characters, numbers and special characters!\n");return false;}
}

void createAcc(acc all[],sv r[])
{
    getchar();
    char d[30],a[30],b[30],s[10];
    int i;
    int c = 0;
    bool q = false;
        while(!q){
        printf("User ID: ");
        fgets(d,sizeof(d),stdin);
        d[strcspn(d,"\n")] = '\0';
        for(i = 0; i < l;i ++) if (strcmp(d,r[i].id) == 0) {q = true;break;}
        for(i = 0; i < tline;i++) if (strcmp(d,t[i].nname) == 0) {q = true;break;}
        printf("ID not available for teacher or student!\n");
    }
    while(c == 0){
        c = 0;
        printf("Username: ");
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\n")] = '\0';
        if (strchr(a,' ') != NULL) {printf("Username should not contain spaces\n");continue;}
        for(i = 0;i < line;i++)
            if (strcmp(a,all[i].username) == 0){
                printf("Username Occupied. Please try again!\n");
                c++;
                break;
            }
        if (c == 0) break;
        else c = 0;
    }
    do{
        printf("Password: ");
        fgets(b,sizeof(b),stdin);
        b[strcspn(b,"\n")] = '\0';
    }while(!passwordValidate(b));
    do {
    printf("Permission(0 = administrator, 1 = teacher, 2 = student): ");
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")] = '\0';
    if (strcmp(s,"0") != 0 || strcmp(s,"1") != 0 || strcmp(s,"2") != 0) printf("Permission should be 0 or 1 or 2. Please try again!\n");
    } while(strcmp(s,"0") != 0 || strcmp(s,"1") != 0 || strcmp(s,"2") != 0);
    fp = fopen("user.data","a");
    fprintf(fp,"%s-%s-%s-%s\n",d,a,b,s);
    fclose(fp);
}

void welcome(acc all[], int i, sv r[], tea t[])
{
    int j;
    for(j = 0;j < l;j++) if (strcmp(all[i].id,r[j].id) == 0){
        printf("Welcome %s to the program\n",r[j].id);
        break;
    }
    for(j = 0;j < tline;j++) if (strcmp(all[i].id,t[j].nname) == 0){
        printf("Welcome %s to the program\n",t[j].name);
        break;
    }
}


void removeAccount(acc all[])
{
    int i,k;
    int c = 0;
    char a[20];
    char o[10] = "N";
    while (strcmp(o,"N") == 0){
        strcpy(o,"\0");
        printf("Enter account ID: ");
        scanf("%s",a);
        for(i = 0;i < line;i++) if (strcmp(a,all[i].id) == 0) {k = i;c++;line--;break;}
        if (c != 0) {
            while(printf("Are you sure? (Y/N)\n") && scanf("%s",o)){
                if (strcmp(o,"Y") == 0 || strcmp(o,"N") == 0) break;
            }
        }
        else {printf("Account not found. Please retry!\n");strcpy(o,"N");}
    }
    fp = fopen("user.data","w");
    for(i = 0;i < line;i++){
        if (i == k) continue;
        fprintf(fp,"%s-%s-%s-%s\n",all[i].id,all[i].username,all[i].password,all[i].perm);
    }
    fclose(fp);
}


void login(acc all[])
{
    getchar();
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
            if (strcmp(a,all[i].username)==0 && strcmp(b,all[i].password) != 0){
                printf("Wrong password!\n");
                k++;
            }
            else if (strcmp(a,all[i].username)==0 && strcmp(b,all[i].password) == 0){
            c = true;
            accountIndex = i;
            k++;
            strcpy(perm,all[i].perm);
            perm[strcspn(perm,"\n")] = '\0';
            welcome(all,i,r,t);
            break;
            }
        }
        if (k == 0) printf("There is no account with that username\n");
        k = 0;
    }
}

bool checkOccuppied(char d[], acc all[])
{
    int i;
    for (i = 0;i < line;i++){
        if (strcmp(d,all[i].id) == 0) {
            return false;
        }
    }
    return true;
}

void registers(acc all[])
{
    getchar();
    int i;
    bool m = true;
    bool n = true;
    char a[20],b[20],d[20],s[20];
    while(m){
        m = false;
        printf("Username: ");
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\n")] = '\0'; 
        for(i = 0;i < line;i++) if(strcmp(a,all[i].username)==0){
            printf("Username occupied\n");
            m = true;
            break;
        }
        if (strchr(a,' ') != NULL) {printf("Username should not contain spaces. Please retry!\n");m = true;}
    }
    do{
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
        else if (strcmp(a,b) == 0) {
            printf("Username cannot match the password\n");
            continue;
        }
    } while(!passwordValidate(b));

    printf("Successful\n");
    do{
        printf("Please enter your ID: ");
        fgets(d,sizeof(d),stdin);
        d[strcspn(d,"\n")] = '\0';
        if (!checkOccuppied(d,all)){
            printf("There's already a user with ID %s. Please retry!\n",d);
            continue;
        }
    } while(!checkOccuppied(d,all));
    fp = fopen("user.data","a");
    fprintf(fp,"%s-%s-%s-2\n",d,a,b);
    fclose(fp);
    strcpy(perm,"2");
}

void accountManagement(acc all[])
{
    char o[5];
    char a[50],b[50],c[50];
    int k = 1;
    int i;
    bool bol = false;
    while(true){
        printf("1.Change username\n");
        printf("2.Change password\n");
        printf("3.Back\n");
        scanf("%s",o);
        if (strcmp(o,"1") == 0) {
            while(!bol){
                printf("New username: "); 
                scanf("%s",a);
                if (strchr(a,' ') != NULL) {printf("Username should not contain spaces. Please retype!\n");continue;}
                bol = true;
            }
            strcpy(all[accountIndex].username,a);
            fp = fopen("user.data","w");
            for(i = 0;i < line;i++){
                fprintf(fp,"%s-%s-%s-%s\n",all[i].id,all[i].username,all[i].password,all[i].perm);
            }
            fclose(fp);
        }
        else if (strcmp(o,"2") == 0){
            while(k >= 1){
                k = 0;
                printf("Old password: ");
                scanf("%s",a);
                printf("New password: ");
                scanf("%s",b);
                printf("Retype password: ");
                scanf("%s",c);
                if (strcmp(a,all[accountIndex].password) != 0){
                    k++;
                    printf("Wrong password!\n");
                }
                if (strcmp(b,c) != 0){
                    k++;
                    printf("Password does not match!\n");
                }
                if (strcmp(a,b) == 0){
                    k++;
                    printf("New password must be different\n");
                }
                if (!passwordValidate(b)) k++;
            }
            strcpy(all[accountIndex].password,b);
            fp = fopen("user.data","w");
            for(i = 0;i < line;i++){
                fprintf(fp,"%s-%s-%s-%s\n",all[i].id,all[i].username,all[i].password,all[i].perm);
            }
            fclose(fp);
        }
        else if (strcmp(o,"3") == 0){
            break;
        }
        else {printf("Wrong option. Please try again!\n");continue;}
    }
}

void logOut()
{
    accountIndex = -1;
    strcpy(perm,"\0");
}


//------------------------------------------------------------------------------------------------------------------------
//                                                       Main function


int main()
{
    sv r[100];
    acc all[100];
    // char o[10];
    // while(true){
    //     getUserAccounts(all);
    //     do{
    //         printf("1.Login\n");
    //         printf("2.Register\n");
    //         printf("3.Exit\n");
    //         scanf("%s",o);
    //         if (strcmp(o,"1") == 0) login(all);
    //         else if (strcmp(o,"2") == 0) registers(all);
    //         else if (strcmp(o,"3") == 0) exit(0);
    //         else printf("Wrong option. Please retry!\n");
    //     } while(strcmp(o,"1") != 0 && strcmp(o,"2") != 0 && strcmp(o,"3") != 0);
    //     system("cls");
    // }
    getStudentData(r);
}