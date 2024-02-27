//Note: Add clearscreen last.
// 3.Looping and exiting the loop in login and register and also other functions can retry it.
// 4.Add classes into the program.
// 7.Add logout function
// 8.Change permission of the teacher,admin and students
// 11.Draw a database relationship diagram
// 12.Add validation in every input
// 14.Think about ID distribution
// 15.To get out of loop, whenever user type exit, it will go back to previous menu.
// 16.Add admin.noti
// 17.Create a menu
// 18.Make a pause at every function & make a loop to reuse the function without going back to the menu

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <ctype.h>

struct classdata{
    char name[20];
    char teacher[20];
    char students[500];
};
struct teacher{
    char nname[50];
    char name[50];
    char gmail[100];
};

struct student
{
    char id[10];
    char name[50];
    char semester[3];
    char coursename[10];
};
struct accounts
{
    char id[30];
    char username[20];
    char password[20];
    char perm[2];
};
FILE *fp;
int l = 0;
int line = 0;
int cline = 0;
int tline = 0;
int accountIndex;
char perm[2];
typedef struct classdata cl;
typedef struct student sv;
typedef struct accounts acc;
typedef struct teacher tea;

bool checkInput(char a[])
{
    int i;
    for(i = 0;i < strlen(a);i++) if (!isdigit(a[i])) return false;
    return true;
}


//------------------------------------------------------------------------------------------------------------------------
//                                                       Teacher functions

void stringProcessing4(char c[],tea t[], int tline)
{
    sscanf(c,"%[^-]-%[^-]-%[^-\n]",t[tline].nname,t[tline].name,t[tline].gmail);
}

void getTeacherData(tea t[])
{
    fp = fopen("teacher.data","r");
    char c[100];
    int i,j;
    while(fgets(c,sizeof(c),fp)!= NULL){
        stringProcessing4(c,t,tline);
        tline++;
    }
    fclose(fp);
    //printf("%s-%s-%s",t[1].nname,t[1].name,t[1].gmail);
}

bool validateGmail(char c[])
{
    char name[20];
    sscanf(c,"%[a-zA-Z0-9]@mail.com",name);
    strcat(name,"@gmail.com");
    if(strcmp(name,c) == 0) return true;
    else return false;
}

void ucaseName(char a[])
{
    int i;
    a[0] = toupper(a[0]);
    for(i = 1;i < strlen(a);i++){
        if (a[i] == ' ') a[i+1] = toupper(a[i+1]);
    }
}

void addTeacher(tea t[])
{
    int n,i,j;
    int p = 0;
    int q;
    char b[30],c[50],a[20],e[10],d[10];
    do{
        printf("Number of teacher: ");
        scanf("%s",d);
        if (!checkInput(d)) printf("Invalid number!\n");
    } while (!checkInput(d));
    q = atoi(d);
    for (i = 0;i < q;i++) {
        do{
            p = 0;
            printf("Input Nickname: ");
            scanf("%s",a);
            if (strchr(a,' ') != NULL) {printf("There should be no spaces in nickname. Please try again!\n");p++;}
            for(j = 0;j < tline;j++) if (strcmp(a,t[i].nname) == 0) {
                p++;
                printf("Nickname occupied!\n");
                break;
            }
        } while(p > 0);
        getchar();
        do{
            printf("Input name: ");
            fgets(b,sizeof(b),stdin);
            if(strchr(b,' ') == NULL) printf("There should be some spaces in your name. Please try again!\n");
        } while(strchr(b,' ') == NULL);
        b[strcspn(b,"\n")] = '\0';
        strlwr(b);
        ucaseName(b);
        do{
            printf("Input gmail: ");
            scanf("%s",c);
            if(!validateGmail(c)) printf("Wrong gmail format. Please retry!\n");
        } while (!validateGmail(c));
        fp = fopen("teacher.data","a");
        fprintf(fp,"%s-%s-%s\n",a,b,c);
        fclose(fp);
    }
}

void removeTeacher(tea t[])
{
    getchar();
    int i,k;
    int c = 0;
    char a[20];
    while (c == 0){
        printf("Enter teacher name: ");
        fgets(a,sizeof(a),stdin);
        a[strcspn(a,"\n")] = '\0';
        for(i = 0;i < tline;i++) if (strcmp(a,t[i].name) == 0) {k = i;c++;break;}
        if (c != 0) break;
        else printf("Teacher name not found. Please retry!\n");
    } 
    fp = fopen("teacher.data","w");
    for(i = 0;i < tline;i++){
        if (i == k) continue;
        fprintf(fp,"%s-%s-%s\n",t[i].nname,t[i].name,t[i].gmail);
    }
    fclose(fp);
}

void printTeacherProfiles()
{

}

void printTeacherClasses()
{
    
}

//------------------------------------------------------------------------------------------------------------------------
//                                                       Student functions

void addSV(sv a[], sv r[])
{
    int q;
    char c[5];
    int p = 1;
    do{
        printf("Number of new students: ");
        scanf("%s",c);
        if(!checkInput(c)) printf("Wrong input. Please retry!\n");
    } while (!checkInput(c));
    q = atoi(c);
    fp = fopen("student.data","a");
    int i,j;
    for(i = 0;i < q;i++){
        while(p != 0){
            p = 0;
            printf("ID: ");
            scanf("%s",a[i].id);
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
        while(true){
            printf("Semester: ");
            scanf("%s",&a[i].semester);
            if (atoi(a[i].semester) == 0) printf("Only accept numbers. Please try again!\n");
            if (atoi(a[i].semester) > 1 || atoi(a[i].semester) <= 8) break;
            else printf("Semester should be in range of 1 to 8. Please try again!\n");
        }
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
//                                                       Class functions

void stringProcessing3(char c[], cl class[], int cline)
{
    sscanf(c,"%[^-]-%[^-]-%[^-\n]",class[cline].name,class[cline].teacher,class[cline].students);
}

void getClassData(cl class[])
{
    fp = fopen("class.data","r");
    char c[100];
    int i,j;
    cline = 0;
    while(fgets(c,sizeof(c),fp)!= NULL){
        stringProcessing3(c,class,cline);
        cline++;
    }
    fclose(fp);
    //printf("%s-%s-%s",class[0].name,class[0].teacher,class[0].students);
}


void printStudents(cl class[], int i, sv r[])
{
    int j;
    char *token = strtok(class[i].students,".");
    while (token != NULL)
    {
        for(j = 0;j < l;j++) if (strcmp(r[j].id,token)==0) printf("%s|%s|%s|%s\n",r[j].id,r[j].name,r[j].semester,r[j].coursename); 
        token = strtok(NULL,".");
    }
    
}

void printClass(cl class[], sv r[], acc all[])
{
    int i;
    if (strcmp(perm,"0") == 0){
        for(i = 0;i < cline;i++){
            printf("%d.Class: %s\nTeacher : %s\nStudents: \n",i+1,class[i].name,class[i].teacher);
            printStudents(class,i,r);
        }
    }
    if (strcmp(perm,"1") == 0){
        for(i = 0;i < cline;i++) if (strcmp(all[accountIndex].id,class[i].teacher) == 0){
            printf("%d.Class: %s\nTeacher : %s\nStudents: \n",i+1,class[i].name,class[i].teacher);
            printStudents(class,i,r);
        }
    }
}


void printClassToFile(cl class[])
{
    int i;
    fp = fopen("class.data","w");
    for(i = 0;i < cline;i++) fprintf(fp,"%s-%s-%s\n",class[i].name,class[i].teacher,class[i].students);
    fclose(fp);
}

void addStudents(cl class[], int k, sv r[])
{
    // Add teacher permission to request
    int i,j;
    int q;
    char p[10];
    bool a = false;
    int b = 0;
    char c[20];
    char *token = strtok(class[k].students,".");
    do
    {
        printf("Number of student: ");
        scanf("%s",p);
        if (!checkInput(p)) printf("Invalid number. Please retry!\n");
    } while (!checkInput(p));
    q = atoi(p);
    for(j = 0;j < q;j++){
        while(!a || b == 0){
            a = false;
            b = 1;
            printf("Student ID: ");
            scanf("%s",c);
            for(i = 0; i < l; i++) if (strcmp(c,r[i].id) == 0){
                a = true;
                break;
            }
            while(token != NULL){
                if (strcmp(c,token) == 0){
                    printf("Student is already in the class. Please retry!\n");
                    b = 0;
                    break;
                }
                token = strtok(NULL,".");   
            }
            if (!a) printf("Student ID not found. Please retry!\n");
        }
        getClassData(class);
        strcat(class[k].students,".");
        strcat(class[k].students,c);
        printClassToFile(class);
    }
}

void deleteStudentsFromClass(cl class[], int k, sv r[])
{
    // Add teacher permission to request
    cl new;
    strcpy(new.students,"\0");
    char c[20];
    int i;
    int a = 0;
    while(a == 0){
        printf("Input ID: ");
        scanf("%s",c);
        for(i = 0;i < l;i++) if (strcmp(c,r[i].id) == 0) {a++;break;}
        if(a == 0) printf("Student is not in the class. Please retry!\n");
    }
    char *token = strtok(class[k].students,".");
    while(token != NULL){
        if (strcmp(token,c) == 0) {token = strtok(NULL,".");continue;}
        strcat(new.students,token);
        token = strtok(NULL,".");
        if (token!= NULL) strcat(new.students,".");
    }
    strcpy(class[k].students,new.students);
    if (class[k].students[strlen(class[k].students)-1] == '.') class[k].students[strlen(class[k].students)-1] = '\0';
    printClassToFile(class);
}

void modifyClass(cl class[], sv r[])
{
    // Show all classes || search by class name and teacher name.
    int i,k;
    char o[5],c[5];
    for(i = 0; i < cline; i++){
        printf("%d.Class: %s\tTeacher: %s\n",i+1,class[i].name,class[i].teacher);
    }
    do{
        printf("Select class: ");
        scanf("%s",c);
        k = atoi(c) - 1;
        if (k > cline && k < 0) printf("Class %s unavailable. Please retry!",c);
    } while (k > cline && k < 0);
    do{
        printf("1. Add students to class\n");
        printf("2. Delete students from class\n");
        printf("3. Back\n");
        scanf("%s",o);
        if (strcmp(o,"1") == 0) {
            addStudents(class,k,r);
        }
        else if (strcmp(o,"2") == 0) {
            deleteStudentsFromClass(class,k,r);
        }
        else if (strcmp(o,"3") == 0) {
            break;
        }
        else printf("Wrong input. Please retry!\n");
    } while (strcmp(o,"1") != 0 && (strcmp(o,"2") != 0));
}

void addClass(sv r[], tea t[])
{
    int i,n,j;
    int q = 0;
    bool p;
    char a[20],b[20],c[100],d[20],k[10];
    strcpy(c,"\0");
    printf("Class name: ");
    scanf("%s",a);
    while(q == 0){
        printf("Teacher in charge: ");
        scanf("%s",b);
        for(i = 0;i < tline;i++) if (strcmp(b,t[i].nname) == 0) {q++;break;}
        if (q == 0) printf("Teacher not found. Please retry!\n");
    }
    printf("Number of student: ");
    scanf("%s",k);
    n = atoi(k);
    for(i = 0;i < n;i++){
        do
        {
            scanf("%s",d);
            for(j = 0;j < l; j++) {
                if (strcmp(d,r[j].id) == 0) {p = true;break;}
            }
            if (!p) printf("ID not found. Please retry!\n");
        } while (!p);
            strcat(c,d);
        if(i!=n-1) strcat(c,".");
    }
    fp = fopen("class.data","a");
    fprintf(fp,"%s-%s-%s\n",a,b,c);
    fclose(fp);
    cline++;
}

void deleteClass(cl class[])
{
    int i,k;
    char a[20],b[20];
    scanf("%s",a);
    scanf("%s",b);
    for(i = 0;i < cline;i++) if (strcmp(a,class[i].name) == 0 && strcmp(b,class[i].teacher) == 0) {k = i;break;}
    fp = fopen("class.data","w");
    for(i = 0;i < cline;i++){
        if (i == k) continue;
        fprintf(fp,"%s-%s-%s\n",class[i].name,class[i].teacher,class[i].students);
    }
    fclose(fp);
}


//------------------------------------------------------------------------------------------------------------------------
//                                                     Login/register functions

void stringProcessing2(acc all[], char c[], int line)
{
    sscanf(c,"%[^-]-%[^-]-%[^-]-%[^-\n]",all[line].id,all[line].username,all[line].password,all[line].perm);
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

void createAcc(acc all[],sv r[],tea t[])
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


void login(acc all[],sv r[],tea t[])
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
    cl class[100];
    sv a[100];
    sv r[100];
    acc all[100];
    tea t[100];
    char o[10];
    while(true){
        getUserAccounts(all);
        do{
            printf("1.Login\n");
            printf("2.Register\n");
            printf("3.Exit\n");
            scanf("%s",o);
            if (strcmp(o,"1") == 0) login(all,r,t);
            else if (strcmp(o,"2") == 0) registers(all);
            else if (strcmp(o,"3") == 0) exit(0);
            else printf("Wrong option. Please retry!\n");
        } while(strcmp(o,"1") != 0 && strcmp(o,"2") != 0 && strcmp(o,"3") != 0);
        system("cls");
        do{
            if (strcmp(perm,"0") == 0) {
                printf("1.Student management\n");
                printf("2.Teacher management\n");
                printf("3.Class management\n");
                printf("4.Account management\n");
                printf("5.Logout\n");
                scanf("%s",o);
                if (strcmp(o,"1") == 0){
                    while(true){
                        printf("1.Add students\n");
                        printf("2.Delete students\n");
                        printf("3.Modify students\n");
                        printf("4.Search students\n");
                        printf("5.Student reports\n");
                        printf("6.Back\n");
                        scanf("%s",o);
                        getStudentData(r);
                        if (strcmp(o,"1") == 0) addSV(a,r);
                        else if (strcmp(o,"2") == 0) deleteStudent(r);
                        else if (strcmp(o,"3") == 0) update(r);
                        else if (strcmp(o,"4") == 0) search(r);
                        else if (strcmp(o,"5") == 0) report(r);
                        else if (strcmp(o,"6") == 0) break;
                        else printf("Wrong option!\n");
                    }
                }
                else if (strcmp(o,"2") == 0){
                    while(true){
                        printf("1.Add teacher\n");
                        printf("2.Delete teacher\n");
                        printf("3.Back\n");
                        scanf("%s",o);
                        getTeacherData(t);
                        if (strcmp(o,"1") == 0) addTeacher(t);
                        else if (strcmp(o,"2") == 0) removeTeacher(t);
                        else if (strcmp(o,"3") == 0) break;
                        else printf("Wrong option!\n");
                    }
                }
                else if (strcmp(o,"3") == 0){
                    while(true){
                        printf("1.Add class\n");
                        printf("2.Delete class\n");
                        printf("3.Modify class\n");
                        printf("4.Class reports\n");
                        printf("5.Back\n");
                        scanf("%s",o);
                        getClassData(class);
                        getTeacherData(t);
                        getStudentData(r);
                        if (strcmp(o,"1") == 0) addClass(r,t);
                        else if (strcmp(o,"2") == 0) deleteClass(class);
                        else if (strcmp(o,"3") == 0) modifyClass(class,r);
                        else if (strcmp(o,"4") == 0) printClass(class,r,all);
                        else if (strcmp(o,"5") == 0) break;
                        else printf("Wrong option!\n");
                    }
                }
                else if (strcmp(o,"4") == 0){
                    while(true){
                        printf("1.Add account\n");
                        printf("2.Delete account\n");
                        printf("3.Modify account\n");
                        printf("4.Back\n");
                        scanf("%s",o);
                        getUserAccounts(all);
                        if (strcmp(o,"1") == 0) createAcc(all,r,t);
                        else if (strcmp(o,"2") == 0) removeAccount(all);
                        else if (strcmp(o,"3") == 0) accountManagement(all);
                        else if (strcmp(o,"4") == 0) break;
                        else printf("Wrong option!\n");
                    }
                }
                else if (strcmp(o,"5") == 0){
                    logOut();
                }
            }
            else if (strcmp(perm,"1") == 0) {
                printf("1.Student management\n");
                printf("2.Class management\n");
                printf("3.Account management\n");
                scanf("%s",o);
                if (strcmp(o,"1") == 0){
                    while(true){
                        printf("1.Search students\n");
                        printf("2.Back\n");
                        scanf("%s",o);
                        getStudentData(r);
                        if (strcmp(o,"1") == 0) search(r);
                        else if (strcmp(o,"2") == 0) break;
                        else printf("Wrong option!\n");
                    }
                }
                else if (strcmp(o,"2") == 0){
                    while(true){
                        printf("1.Modify class\n");
                        printf("2.Class reports\n");
                        printf("3.Back\n");
                        scanf("%s",o);
                        getClassData(class);
                        if (strcmp(o,"1") == 0) modifyClass(class,r);
                        else if (strcmp(o,"3") == 0) ;
                        else if (strcmp(o,"2") == 0) break;
                        else printf("Wrong option!\n");
                    }
                }
            }
            else if (strcmp(perm,"2") == 0) {
                printf("1.Class management\n");
                printf("2.Account management\n");
                scanf("%s",o);
            }
        } while(strcmp(perm,"\0") != 0);
    }
}