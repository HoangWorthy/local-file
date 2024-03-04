// 3/4/24: Added search students with filter options 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<unistd.h>
#include<windows.h>


struct student
{
    char sid[20];
    char name[50];
    char gender[10];
    char date[30];
    char pnumber[20];
};
struct accounts
{
    char username[20];
    char password[20];
    bool add;
    bool update;
    bool delete;
    bool search;
    bool createacc;
    bool manageacc;
    bool deleteacc;
    bool showacc;
};
FILE *fp;
int l = 0;
int line = 0;
int accountIndex;
typedef struct student sv;
typedef struct accounts acc;

// Function to get the width of the terminal
int getTerminalWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}

// Function to print centered text
void printCentered(const char *text) {
    int width = getTerminalWidth();
    int padding = (width - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) {
        putchar(' ');
    }
    printf("%s", text);
}

bool checkInput(char a[])
{
    int i;
    for(i = 0;i < strlen(a);i++) if (!isdigit(a[i])) return false;
    return true;
}

void bubbleSort(int arr[], int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool checkInappropriateChar(char a[])
{
    if (strchr(a,'-') != NULL) {printf("It mustn't contain '-'\n");return false;}
    return true;
}

//------------------------------------------------------------------------------------------------------------------------
//                                                     Login/register functions

/*void stringProcessing2(acc all[], char c[], int line)
{
    sscanf(c,"%[^-]-%[^-]-%d-%d-%d-%d-%d-%d-%d-%d",all[line].username,all[line].password,all[line].add,all[line].update,all[line].delete,all[line].search,all[line].createacc,all[line].manageacc,all[line].deleteacc,all[line].showacc);
}*/
void stringProcessing2(acc all[], char c[], int line) {
    int add, update, del, search, create, manage, deleteacc, show;
    if (sscanf(c, "%[^-]-%[^-]-%d-%d-%d-%d-%d-%d-%d-%d",all[line].username, all[line].password,&add, &update, &del, &search,&create, &manage, &deleteacc, &show) == 10) {
        all[line].add = add != 0;
        all[line].update = update != 0;
        all[line].delete = del != 0;
        all[line].search = search != 0;
        all[line].createacc = create != 0;
        all[line].manageacc = manage != 0;
        all[line].deleteacc = deleteacc != 0;
        all[line].showacc = show != 0;
    }
}

void getUserAccounts(acc all[])
{
    char c[100];
    fp = fopen("user.data","r");
    line = 0;
    while (fgets(c,sizeof(c),fp) != NULL)
    {
        stringProcessing2(all,c,line);
        line++;
    }
    fclose(fp);
    //printf("%s-%s\n",all[0].username,all[0].password);
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
    if(!checkInappropriateChar(c)) return false;
    if (strchr(c,' ') != NULL) {printf("Password should not contain spaces!\n");return false;}
    if (a > 0 && b > 0 && d > 0) return true;
    else {printf("Password must contain uppercase characters, numbers and special characters!\n");return false;}
}

void createAcc(acc all[])
{
    system("cls");
    char o[5];
    char d[5],perm[5];
    int i,q,j;
    int c = 0;
    do {
        do{
            printf("Number of new account: ");
            scanf("%s",d);
            if (strcmp(d,"exit") == 0) return;
            if(!checkInput(d)) printf("Wrong input. Please retry!\n");
        } while (!checkInput(d));
        q = atoi(d);
        for(j = 0;j < q;j++){
            acc new;
            while(c == 0){
                c = 0;
                do{
                    printf("Username: ");
                    scanf("%s",new.username);
                } while(!checkInappropriateChar(new.username)); 
                if (strcmp(new.username,"exit") == 0) return;
                if (strchr(new.username,' ') != NULL) {printf("Username should not contain spaces\n");continue;}
                for(i = 0;i < line;i++)
                    if (strcmp(new.username,all[i].username) == 0){
                        printf("Username Occupied. Please try again!\n");
                        c++;
                        break;
                    }
                if (c == 0) break;
                else c = 0;
            }
            do{
                printf("Password: ");
                scanf("%s",new.password);
                if (strcmp(new.password,"exit") == 0) return;
            }while(!passwordValidate(new.password) || !checkInappropriateChar(new.password));
            printf("-----------------Permission----------------\n");
                printf("1.Add students(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.add = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.add = false;break;}
                }
                printf("2.Update students(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.update = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.update = false;break;}
                }
                printf("3.Delete students(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.delete = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.delete = false;break;}
                }
                printf("4.Search students(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.search = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.search = false;break;}
                }
                printf("5.Create account(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.createacc = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.createacc = false;break;}
                }
                printf("6.Manage account(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.manageacc = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.manageacc = false;break;}
                }
                printf("7.Delete account(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.deleteacc = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.deleteacc = false;break;}
                }
                printf("8.Show accounts(Y/N): ");
                while(scanf("%s",perm)){
                    if (strcmp(perm,"exit") == 0) return;
                    if (strcmp(perm,"Y") == 0) {new.showacc = true;break;}
                    else if (strcmp(perm,"N") == 0) {new.showacc = false;break;}
                }
            fp = fopen("user.data","a");
            fprintf(fp,"%s-%s-%i-%i-%i-%i-%i-%i-%i-%i\n",new.username,new.password,new.add,new.update,new.delete,new.search,new.createacc,new.manageacc,new.deleteacc,new.showacc);
            fclose(fp);
            system("cls");
            printf("Create successfully!");
            sleep(1);
            system("cls");
        }
        printf("Do you want to continue creating account?(Y/N)\n");
        while(scanf("%s",o)){
            if (strcmp(o,"exit") == 0) return;
            if (strcmp(o,"Y") == 0) break;
            else if (strcmp(o,"N") == 0) break;
        }
    } while (strcmp(o,"Y") == 0);
    system("cls");
    printf("Exiting to menu...");
    sleep(1);
}
//Fix removeaccount() to be the same as deletestudent();

void removeAccount(acc all[])
{
    int i;
    int n = 0;
    int c = 0;
    char id[20],o[10];
    int count;
    do{
        system("cls");
        int b[20];
        c = 0;
        while(true){
                    n = 0;
                    printf("Type username (type 0 to stop): ");
                    scanf("%s",id);
                    if (strcmp(id,"exit") == 0) return;
                    if (strcmp(id,"0") == 0) break;
                    for(i = 0;i < l;i++) if (strcmp(all[i].username,id)==0) {
                        n++;
                        b[c] = i;
                        c++;
                        break;
                    }
                    if (n == 0) printf("Username not found!\n");
        }
        printf("Are you sure to delete below student?(Y/N)\n");
        for(i = 0;i < c;i++){
                printf("Username: %s | Password: %s\n",all[b[i]].username,all[b[i]].password); 
            }
        while(scanf("%s",o)){
            if (strcmp(o,"exit") == 0) return;
            if (strcmp(o,"Y") == 0) break;
            else if (strcmp(o,"N") == 0) break;
        }
        if (strcmp(o,"Y") == 0){
            bubbleSort(b,c);
            fp = fopen("user.data","w");
            count = 0;
            for(i = 0;i < line;i++){
                if (b[count] == i) {count++;printf("%d\n",b[count]);continue;}
                fprintf(fp,"%s-%s-%d-%d-%d-%d-%d-%d-%d-%d\n",all[i].username,all[i].password,all[i].add,all[i].update,all[i].delete,all[i].search,all[i].createacc,all[i].manageacc,all[i].deleteacc,all[i].showacc);
            }
            fclose(fp);
            l -= c;
            system("cls");
            printf("Delete successfully!");
            sleep(1);
            system("cls");
        }
        printf("Do you want to continue deleting?(Y/N)\n");
        while(scanf("%s",o)){
            if (strcmp(o,"exit") == 0) return;
            if (strcmp(o,"Y") == 0) break;
            else if (strcmp(o,"N") == 0) break;
        }
    }while(strcmp(o,"Y") == 0);
    system("cls");
    printf("Exiting to menu...");
    sleep(1);
}

/*
void removeAccount(acc all[])
{
    system("cls");
    int i,k,q,j;
    int c = 0;
    char a[20],o[5],d[5];
    do{
        while (true){
            c = 0;
            do{
                printf("Enter username(type '0' to stop): ");
                scanf("%s",a);
                if (strcmp(d,"exit") == 0) return;

            while(strcmp(a,"0") != 0);
            system("cls");
            printf("You are about to delete accounts below: \n");
            printf("Username: %s | Password: %s\n",all[k].username,all[k].password);
            while(scanf("%s",o)){
                if (strcmp(o,"exit") == 0) return;
                if (strcmp(o,"Y") == 0) break;
                else if (strcmp(o,"N") == 0) break;
            }
            if (strcmp(o,"Y") == 0){
                fp = fopen("user.data","w");
                for(i = 0;i < line;i++){
                    if (i == k) continue;
                    fprintf(fp,"%s-%s-%i-%i-%i-%i-%i-%i-%i-%i\n",all[i].username,all[i].password,all[i].add,all[i].update,all[i].delete,all[i].search,all[i].createacc,all[i].manageacc,all[i].deleteacc,all[i].showacc);
                }
                fclose(fp);
                system("cls");
                printf("Delete successfully!\n");
                sleep(1);
                system("cls");
                line--;
                break;
            }
        }
        printf("Do you want to continue deleting?(Y/N)\n");
        while(scanf("%s",o)){
            if (strcmp(o,"exit") == 0) return;
            if (strcmp(o,"Y") == 0) break;
            else if (strcmp(o,"N") == 0) break;
        }
    }while(strcmp(o,"Y") == 0);
    system("cls");
    printf("Exiting back to menu...\n");
    sleep(1);
}
*/

void login(acc all[])
{
    system("cls");
    char a[20],b[20];
    int pos = 0;
    int i;
    int k = 0;
    bool c = false;
    while(!c){
        printCentered("-----------Login------------\n");
        k = 0;
        printCentered("Username: ");
        scanf("%s",a);
        printCentered("Password: ");
        scanf("%s",b);
        for(i = 0;i < line;i++){ 
            if (strcmp(a,all[i].username)==0) k++;
            if (strcmp(a,all[i].username)==0 && strcmp(b,all[i].password) != 0){
                system("cls");
                printCentered("Wrong password!\n");
                sleep(1);
                system("cls");
                break;
            }
            else if (strcmp(a,all[i].username)==0 && strcmp(b,all[i].password) == 0){
                c = true;
                accountIndex = i;
                system("cls");
                printCentered("Login successfully!\n");
                sleep(1);
                break;
            }
        }
        if (k == 0) {system("cls");printf("Username not found!\n");sleep(1);system("cls");}
    }
}


/*void registers(acc all[])
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
*/

void accountManagement(acc all[])
{
    system("cls");
    char o[5];
    char a[50],b[50],c[50],d[20];
    int k = 1;
    int dem = 0;
    int i,index;
    bool bol = false;
    while (true){
        dem = 0;
        printf("Username of the account: ");
        do{
            scanf("%s",d);
        } while(!checkInappropriateChar(d));
        if (strcmp(d,"exit") == 0) return;
        for(i = 0;i < line;i++) 
            if (strcmp(d,all[i].username) == 0) {index = i;dem++;break;}
        if (dem == 0) printf("Username not found!\n");
        else break;
    }
    while(true){
        system("cls");
        printf("Username: %s | Password: %s\n",all[index].username,all[index].password);
        printf("1.Change username\n");
        printf("2.Change password\n");
        printf("3.Change permission\n");
        printf("4.Change account\n");
        printf("5.Save and back to menu\n");
        scanf("%s",o);
        if (strcmp(o,"exit") == 0) return;
        if (strcmp(o,"1") == 0) {
            bol = false;
            while(!bol){
                do{
                    printf("New username: "); 
                    scanf("%s",a);
                }while (!checkInappropriateChar);
                if (strcmp(a,"exit") == 0) return;
                if (strchr(a,' ') != NULL) {printf("Username should not contain spaces. Please retype!\n");continue;}
                bol = true;
            }
            strcpy(all[index].username,a);
        }
        else if (strcmp(o,"2") == 0){
            while(k >= 1){
                k = 0;
                printf("Old password: ");
                scanf("%s",a);
                if (strcmp(a,"exit") == 0) return;
                printf("New password: ");
                scanf("%s",b);
                if (strcmp(b,"exit") == 0) return;
                printf("Retype password: ");
                scanf("%s",c);
                if (strcmp(c,"exit") == 0) return;
                if (strcmp(a,all[index].password) != 0){
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
                if (!passwordValidate(b) || !checkInappropriateChar(b)) k++;
            }
            strcpy(all[index].password,b);
        }
        else if (strcmp(o,"3") == 0){
            system("cls");
            printf("Permissions for Account: %s\n", all[index].username);
            printf("1.Add student: %s\n", all[index].add ? "Allowed" : "Denied");
            printf("2.Update student: %s\n", all[index].update ? "Allowed" : "Denied");
            printf("3.Delete student: %s\n", all[index].delete ? "Allowed" : "Denied");
            printf("4.Search student: %s\n", all[index].search ? "Allowed" : "Denied");
            printf("5.Create Account: %s\n", all[index].createacc ? "Allowed" : "Denied");
            printf("6.Manage Account: %s\n", all[index].manageacc ? "Allowed" : "Denied");
            printf("7.Delete Account: %s\n", all[index].deleteacc ? "Allowed" : "Denied");
            printf("8.Show Account: %s\n", all[index].showacc ? "Allowed" : "Denied");
            printf("Type the permission number to revert it (Input '0' to stop): \n");
            while(true){
                scanf("%s",o);
                if (strcmp(o,"exit") == 0) return;
                if (strcmp(o,"1") == 0) {all[index].add = !all[index].add;printf("Add student now is %s\n",all[index].add ? "Allowed" : "Denied");}
                else if (strcmp(o,"2") == 0) {all[index].update = !all[index].update;printf("Update student now is %s\n",all[index].update ? "Allowed" : "Denied");}
                else if (strcmp(o,"3") == 0) {all[index].delete = !all[index].delete;printf("Delete student now is %s\n",all[index].delete ? "Allowed" : "Denied");}
                else if (strcmp(o,"4") == 0) {all[index].search = !all[index].search;printf("Search student now is %s\n",all[index].search ? "Allowed" : "Denied");}
                else if (strcmp(o,"5") == 0) {all[index].createacc = !all[index].createacc;printf("Create account now is %s\n",all[index].createacc ? "Allowed" : "Denied");}
                else if (strcmp(o,"6") == 0) {all[index].manageacc = !all[index].manageacc;printf("Manage account now is %s\n",all[index].manageacc ? "Allowed" : "Denied");}
                else if (strcmp(o,"7") == 0) {all[index].deleteacc = !all[index].deleteacc;printf("Delete account now is %s\n",all[index].deleteacc ? "Allowed" : "Denied");}
                else if (strcmp(o,"8") == 0) {all[index].showacc = !all[index].showacc;printf("Show account now is %s\n",all[index].showacc ? "Allowed" : "Denied");}
                else if (strcmp(o,"0") == 0) break;
            }
        }
        else if (strcmp(o,"4") == 0){
            while (true){
                dem = 0;
                printf("Username of the account: ");
                scanf("%s",d);
                if (strcmp(d,"exit") == 0) return;
                for(i = 0;i < line;i++) 
                    if (strcmp(d,all[i].username) == 0) {index = i;dem++;break;}
                if (dem == 0) printf("Username not found!\n");
                else break;
            }
        }
        else if (strcmp(o,"5") == 0){
            fp = fopen("user.data","w");
            for(i = 0;i < line;i++){
                fprintf(fp,"%s-%s-%d-%d-%d-%d-%d-%d-%d-%d\n",all[i].username,all[i].password,all[i].add,all[i].update,all[i].delete,all[i].search,all[i].createacc,all[i].manageacc,all[i].deleteacc,all[i].showacc);
            }
            fclose(fp);
            system("cls");
            printf("Update successfully!\n");
            sleep(1);
            system("cls");
            break;
        }
        else {printf("Wrong option. Please try again!\n");continue;}
    }
}

void showAccount(acc all[])
{
    system("cls");
    int i;
    for(i = 0;i < line;i++) {
        printf("-----------------%d----------------\n",i+1);
        printf("Username: %s\n",all[i].username);
        printf("Password: %s\n",all[i].password);
        printf("-----------------Permission----------------\n");
        printf("1.Add student: %s\n", all[i].add ? "Allowed" : "Denied");
        printf("2.Update student: %s\n", all[i].update ? "Allowed" : "Denied");
        printf("3.Delete student: %s\n", all[i].delete ? "Allowed" : "Denied");
        printf("4.Search student: %s\n", all[i].search ? "Allowed" : "Denied");
        printf("5.Create Account: %s\n", all[i].createacc ? "Allowed" : "Denied");
        printf("6.Manage Account: %s\n", all[i].manageacc ? "Allowed" : "Denied");
        printf("7.Delete Account: %s\n", all[i].deleteacc ? "Allowed" : "Denied");
        printf("8.Show Account: %s\n", all[i].showacc ? "Allowed" : "Denied");
        printf("\n");
    }
    getch();
}

void modifyAccount(acc all[])
{
    system("cls");
    int i;
    char o[5];
    char a[20],b[20],c[20];
    int k = 1;
    bool bol;
    while(true){
        printf("1.Change username\n");
        printf("2.Change password\n");
        printf("3.Change permission\n");
        printf("4.Change account\n");
        printf("5.Back\n");
        scanf("%s",o);
        if (strcmp(o,"exit") == 0) return;
        if (strcmp(o,"1") == 0) {
            bol = false;
            while(!bol){
                printf("New username: "); 
                scanf("%s",a);
                if (strcmp(a,"exit") == 0) return;
                if (strchr(a,' ') != NULL) {printf("Username should not contain spaces. Please retype!\n");continue;}
                bol = true;
            }
            strcpy(all[accountIndex].username,a);
            fp = fopen("user.data","w");
            for(i = 0;i < line;i++){
                fprintf(fp,"%s-%s-%i-%i-%i-%i-%i-%i-%i-%i\n",all[i].username,all[i].password,all[i].add,all[i].update,all[i].delete,all[i].search,all[i].createacc,all[i].manageacc,all[i].deleteacc,all[i].showacc);
            }
            fclose(fp);
        }
        else if (strcmp(o,"2") == 0){
            while(k >= 1){
                k = 0;
                printf("Old password: ");
                scanf("%s",a);
                if (strcmp(a,"exit") == 0) return;
                printf("New password: ");
                scanf("%s",b);
                if (strcmp(b,"exit") == 0) return;
                printf("Retype password: ");
                scanf("%s",c);
                if (strcmp(c,"exit") == 0) return;
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
                fprintf(fp,"%s-%s-%i-%i-%i-%i-%i-%i-%i-%i\n",all[i].username,all[i].password,all[i].add,all[i].update,all[i].delete,all[i].search,all[i].createacc,all[i].manageacc,all[i].deleteacc,all[i].showacc);
            }
            fclose(fp);
        }
    }
}


//------------------------------------------------------------------------------------------------------------------------
//                                                       Student functions

void ucaseName(char a[])
{
    int i;
    a[0] = toupper(a[0]);
    for(i = 1;i < strlen(a);i++){
        if (a[i] == ' ') a[i+1] = toupper(a[i+1]);
    }
}

bool isValidDate(int day, int month, int year) {
    if (year < 1950 || year > 2023)
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth;
    switch (month) {
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                daysInMonth = 29;
            else
                daysInMonth = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }
    if (day < 1 || day > daysInMonth)
        return false;

    return true;
}

void addStudent(sv r[])
{
    system("cls");
    int i,j;
    char m[5],n[5],k[5],f[20],o[5];
    sv a;
    int q;
    char c[5];
    int p = 1;
    int d = 1;
    bool bol = false;
    do{
        do{
            printf("Number of new students: ");
            scanf("%s",c);
            if (strcmp(c,"exit") == 0) return;
            if(!checkInput(c)) printf("Wrong input. Please retry!\n");
        } while (!checkInput(c));
        q = atoi(c);
        for(i = 0;i < q;i++){
            while (d >= 1){
                d = 0;
                do {
                    printf("Student ID: ");
                    scanf("%s",a.sid);
                }while(!checkInappropriateChar(a.sid));
                if (strcmp(a.sid,"exit") == 0) return;
                for(j = 0;j < l;j++) 
                    if (strcmp(a.sid,r[j].sid) == 0) {printf("Occupied ID. Please try again!\n");d++;break;}
            }
            getchar();
            do{
                do{
                    printf("Student name: ");
                    fgets(a.name, sizeof(a.name), stdin);
                    a.name[strcspn(a.name, "\n")] = '\0';
                } while(!checkInappropriateChar(a.name));
                if (strcmp(a.name,"exit") == 0) return;
                if (strchr(a.name,' ') != NULL) break;
                else printf("Wrong name format. Please retry!\n");
            } while(true);
            strlwr(a.name);
            ucaseName(a.name);
            do{
                printf("Gender(male/female): ");
                scanf("%s",a.gender);
                if (strcmp(a.gender,"exit") == 0) return;
                if (strcmp(a.gender,"male") == 0 || strcmp(a.gender,"female") == 0) break;
                else printf("Male or female only!\n");
            }while(true);
            do{
                printf("Date of birth(DD/MM/YY): ");
                scanf("%s",a.date);
                if (strcmp(a.date,"exit") == 0) return;
                sscanf(a.date,"%[0-9]/%[0-9]/%[0-9]",m,n,k);
                strcpy(f,m);
                strcat(f,"/");
                strcat(f,n);
                strcat(f,"/");
                strcat(f,k);
                if (strcmp(a.date,f) == 0 && isValidDate(atoi(m),atoi(n),atoi(k))) break;
                else printf("Invalid date. Please retry!\n");
            } while(true);
            do{
                bol = true;
                printf("Phone number: ");
                scanf("%s",a.pnumber);
                if (strcmp(a.pnumber,"exit") == 0) return;
                if (strlen(a.pnumber) < 7 || strlen(a.pnumber) > 11) {printf("Phone number too long or too short!\n");bol = false;}
                for(j = 0;j < l;j++) if (strcmp(a.pnumber,r[j].pnumber) == 0) {printf("Occupied phone number!\n");bol = false;break;}
                if (!checkInput(a.pnumber)) bol = false;
            }while (!bol);
            fp = fopen("student.data","a");
            fprintf(fp,"%s-%s-%s-%s-%s\n",a.sid,a.name,a.gender,a.date,a.pnumber);
            fclose(fp);
            system("cls");
            printf("Added successfully!");
            sleep(1);
            system("cls");
        }
        printf("Do you still want to continue?(Y/N)\n");
        while(scanf("%s",o)){
                if (strcmp(o,"exit") == 0) return;
                if (strcmp(o,"Y") == 0) break;
                else if (strcmp(o,"N") == 0) break;
            }
    } while(strcmp(o,"Y") == 0);
    system("cls");
    printf("Exiting to menu...");
    sleep(1);
}

void stringProcessing1(char c[],sv r[], int l)
{
    sscanf(c,"%[^-]-%[^-]-%[^-]-%[^-]-%[^-\n]",r[l].sid,r[l].name,r[l].gender,r[l].date,r[l].pnumber);
}

void getStudentData(sv r[])
{
    fp = fopen("student.data","r");
    char c[100];
    l = 0;
    int i,j;
    while(fgets(c,sizeof(c),fp)!= NULL){
        stringProcessing1(c,r,l);
        l++;
    }
    fclose(fp);
    //printf("%s-%s-%s-%s",r[0].id,r[0].name,r[0].semester,r[0].coursename);
}

void report(sv r[])
{
    int i;
    for(i = 0; i < l; i++){
        printf("%s | %s | %s | %s | %s\n",r[i].sid,r[i].name,r[i].gender,r[i].date,r[i].pnumber); 
    }
    getch();
}

void search(sv r[])
{
    char id[20],name[20],date[20],gender[10],pnumber[20];
    char m[10],n[10],k[10],f[20];
    char c[50];
    int i;
    char o[10];
    int a = 0;
    while(true){
        system("cls");
        printf("1. Search by ID\n");
        printf("2. Search by Name\n");
        printf("3. Search by Phone number\n");
        printf("4. Search by Date of birth\n");
        printf("5. Search by filters\n");
        printf("6. Show all students\n");
        printf("7. Back to menu\n");
        scanf("%s",o);
        if (strcmp(o,"exit") == 0) return;
        a = 0;
        if (strcmp(o,"1") == 0) {
            system("cls");
            printf("Type ID: ");
            scanf("%s",c);  
            if (strcmp(c,"exit") == 0) return;
            for(i = 0;i < l;i++) 
                if (strstr(r[i].sid,c) != NULL){
                    a++;
                    printf("%s | %s | %s | %s | %s\n",r[i].sid,r[i].name,r[i].gender,r[i].date,r[i].pnumber);
                }
            if (a == 0) printf("Not found!\n");
        }
        else if (strcmp(o,"2") == 0) {
            system("cls");
            printf("Type name: ");
            getchar();
            fgets(c,sizeof(c),stdin);
            c[strcspn(c,"\n")] = '\0';
            if (strcmp(c,"exit") == 0) return;
            for(i = 0;i < l;i++) 
                if (strstr(strlwr(r[i].name),c) != NULL){ 
                    a++;
                    printf("%s | %s | %s | %s | %s\n",r[i].sid,r[i].name,r[i].gender,r[i].date,r[i].pnumber); 
                }
            if (a == 0) printf("Not found!\n");
        }
        else if (strcmp(o,"3") == 0) {
            system("cls");
            printf("Type phone number: ");
            scanf("%s",c);
            if (strcmp(c,"exit") == 0) return;
            for(i = 0;i < l;i++)
                if (strstr(r[i].pnumber,c) != NULL){
                    a++;
                    printf("%s | %s | %s | %s | %s\n",r[i].sid,r[i].name,r[i].gender,r[i].date,r[i].pnumber); 
                }
            if (a == 0) printf("Not found!\n");
        }
        else if (strcmp(o,"4") == 0) {
            system("cls");
            do{
            printf("Date of birth(DD/MM/YY): ");
            scanf("%s",date);
            if (strcmp(date,"exit") == 0) return;
            sscanf(date,"%[0-9]/%[0-9]/%[0-9]",m,n,k);
            strcpy(f,m);
            strcat(f,"/");
            strcat(f,n);
            strcat(f,"/");
            strcat(f,k);
            if (strcmp(date,f) == 0 && isValidDate(atoi(m),atoi(n),atoi(k))) break;
            else printf("Invalid date. Please retry!\n");
        } while(true);
            for(i = 0;i < l;i++)
                if(strcmp(date,r[i].date) == 0){
                    a++;
                    printf("%s | %s | %s | %s | %s\n",r[i].sid,r[i].name,r[i].gender,r[i].date,r[i].pnumber); 
                }
            if (a == 0) printf("Not found!\n");
        
        }
        else if (strcmp(o,"5") == 0) {
            system("cls");
            sv new;
            getchar();
            printf("ID (Enter to skip): ");
            fgets(new.sid,sizeof(new.sid),stdin);
            new.sid[strcspn(new.sid,"\n")] = '\0';
            if (strcmp(new.sid,"exit") == 0) return;
            printf("Name (Enter to skip): ");
            fgets(new.name,sizeof(new.name),stdin);
            new.name[strcspn(new.name,"\n")] = '\0';
            if (strcmp(new.name,"exit") == 0) return;
            printf("Gender (male/female) (Enter to skip): ");
            fgets(new.gender,sizeof(new.gender),stdin);
            new.gender[strcspn(new.gender,"\n")] = '\0';
            if (strcmp(new.gender,"exit") == 0) return;
            printf("Date of birth (Enter to skip): ");
            fgets(new.date,sizeof(new.date),stdin);
            new.date[strcspn(new.date,"\n")] = '\0';
            if (strcmp(new.date,"exit") == 0) return;
            printf("Phone number (Enter to skip): ");
            fgets(new.pnumber,sizeof(new.pnumber),stdin);
            new.pnumber[strcspn(new.pnumber,"\n")] = '\0';
            if (strcmp(new.pnumber,"exit") == 0) return;
            int found = 0;
            for(i = 0; i < l; i++) {
                if((new.sid[0] == '\0' || strstr(r[i].sid,new.sid) != NULL) &&
                (new.name[0] == '\0' || strstr(r[i].name,new.name) != NULL) &&
                (new.gender[0] == '\0' || strcmp(r[i].gender,new.gender) == 0) &&
                (new.date[0] == '\0' || strstr(r[i].date,new.date) != NULL) &&
                (new.pnumber[0] == '\0' || strstr(r[i].pnumber,new.pnumber) != NULL)) {
                    printf("%s | %s | %s | %s | %s\n", r[i].sid, r[i].name, r[i].gender, r[i].date, r[i].pnumber); 
                    found++;
                }
            }
            if (found == 0) printf("No student found!\n");
            getch();
        }
        else if (strcmp(o,"6") == 0) {
            report(r);
        }
        else if (strcmp(o,"7") == 0) {
            break;
        }
        else printf("Wrong. Please retry!\n");
    }
}

void update(sv r[])
{
    char a[50],m[10],b[10],d[10],f[20];
    int k;
    int i;
    char c[100];
    char o[10],o2[10];
    int n = 0;
    int dem = 1;
    while(true){
	    system("cls");
        printf("1.Update using ID\n");
        printf("2.Search for ID\n");
        printf("3.Show all students\n");
        printf("4.Back to main menu\n");
        scanf("%s",o);
        if (strcmp(o,"exit") == 0) return;
        if (strcmp(o,"1") == 0) {
            n = 0;
            while(n == 0){
                system("cls");
                printf("Type ID: ");
                scanf("%s",c);
                if (strcmp(c,"exit") == 0) return;
                for(i = 0;i < l;i++) if (strcmp(r[i].sid,c)==0) {
                    k = i;
                    n++;
                    break;
                }
                if (n == 0) printf("ID not found. Please retry!\n");
            }
            system("cls");
            while(true){
                system("cls");
                printf("%s | %s | %s | %s | %s\n",r[k].sid,r[k].name,r[k].gender,r[k].date,r[k].pnumber);
                printf("1. Update ID\n");
                printf("2. Update Name\n");
                printf("3. Update Phone number\n");
                printf("4. Update Date of birth\n");
                printf("5. Update Gender\n");
                printf("6. Save and back\n");
                scanf("%s",o2);
                if (strcmp(c,"exit") == 0) return;
                if (strcmp(o2,"1") == 0) {
                    do{
                        dem = 0;
                        do{
                            printf("Type Updated ID: ");
                            scanf("%s",a);
                        }while(!checkInappropriateChar(a));
                        if (strcmp(c,"exit") == 0) return;
                        for(i = 0;i < l;i++)
                            if (strcmp(a,r[i].sid) == 0){
                                dem++;
                                printf("ID occupied. Please retry!\n");
                                break;
                            }
                    } while (dem >=1);
                    strcpy(r[k].sid,a);
                }
                else if (strcmp(o2,"2") == 0){
                    getchar();
                    do{
                        printf("Type Updated Name: ");
                        fgets(a,sizeof(a),stdin);
                        a[strcspn(a,"\n")] = '\0';
                    }while(!checkInappropriateChar(a));
                    if (strcmp(a,"exit") == 0) return;
                    strcpy(r[k].name,a);
                }
                else if (strcmp(o2,"3") == 0){
                    do{
                        printf("Type Updated Phone number: ");
                        scanf("%s",a);
                        if (strcmp(a,"exit") == 0) return;
                        if (!checkInput) printf("Invalid phone number!\n");
                        else break;
                    } while(true);
                    strcpy(r[k].pnumber,a);
                }
                else if (strcmp(o2,"4") == 0){
                    do{
                        printf("Type Updated Date of birth(DD/MM/YY): ");
                        scanf("%s",a);
                        if (strcmp(a,"exit") == 0) return;
                        sscanf(m,b,d,"%[0-9]/%[0-9]/%[0-9]",a);
                        strcpy(f,m);
                        strcat(f,"/");
                        strcat(f,b);
                        strcat(f,"/");
                        strcat(f,d);
                        if (strcmp(a,f) == 0) break;
                        else printf("Invalid date. Please retry!\n");
                    } while(true);
                    strcpy(r[k].date,a);
                }
                else if (strcmp(o2,"5") == 0){
                    do{
                        printf("Type Updated Gender(male/female): ");
                        scanf("%s",a);
                        if (strcmp(c,"exit") == 0) return;
                        if (strcmp(a,"male") == 0 || strcmp(a,"female") == 0) break;
                        else printf("Wrong input!\n");
                    } while(true);
                    strcpy(r[k].gender,a);
                }
                else if (strcmp(o2,"6") == 0){
                    fp = fopen("student.data","w");
                    for(i = 0; i < l; i++){
                        fprintf(fp,"%s-%s-%s-%s-%s\n",r[i].sid,r[i].name,r[i].gender,r[i].date,r[i].pnumber);
                    }
                    fclose(fp);
                    system("cls");
                    printf("Update successfully!");
                    sleep(1);
					system("cls");
                    break;
                }
                else printf("Wrong option. Please try again!\n");
            }
        }
        else if (strcmp(o,"2") == 0) search(r);
        else if (strcmp(o,"3") == 0) report(r);
        else if (strcmp(o,"4") == 0) {
            break;
        }
        else printf("Wrong option. Please try again!\n");
    }
}

void deleteStudent(sv r[])
{
    system("cls");
    int i;
    int n = 0;
    int c = 0;
    char id[20],o[10];
    int count;
    do{
        int b[20];
        c = 0;
        while(true){
                    n = 0;
                    printf("Type ID (enter to stop): ");
                    fgets(id,sizeof(id),stdin);
                    id[strcspn(id,"\n")] = '\0';
                    if (strcmp(id,"exit") == 0) return;
                    if (strcmp(id,"0") == 0) break;
                    for(i = 0;i < l;i++) if (strcmp(r[i].sid,id)==0) {
                        n++;
                        b[c] = i;
                        c++;
                        break;
                    }
                    if (n == 0) printf("ID not found\n");
        }
        printf("Are you sure to delete below student?(Y/N)\n");
        for(i = 0;i < c;i++){
                printf("%s\t%s\t%s\t%s\t%s\n",r[b[i]].sid,r[b[i]].name,r[b[i]].gender,r[b[i]].date,r[b[i]].pnumber); 
            }
        while(scanf("%s",o)){
            if (strcmp(o,"exit") == 0) return;
            if (strcmp(o,"Y") == 0) break;
            else if (strcmp(o,"N") == 0) break;
        }
        if (strcmp(o,"Y") == 0){
            bubbleSort(b,c);
            fp = fopen("student.data","w");
            count = 0;
            for(i = 0;i < l;i++){
                if (b[count] == i) {count++;printf("%d\n",b[count]);continue;}
                fprintf(fp,"%s-%s-%s-%s-%s\n",r[i].sid,r[i].name,r[i].gender,r[i].date,r[i].pnumber);
            }
            fclose(fp);
            l -= c;
            system("cls");
            printf("Delete successfully!");
            sleep(1);
            system("cls");
        }
        printf("Do you want to continue deleting?(Y/N)\n");
        while(scanf("%s",o)){
            if (strcmp(o,"exit") == 0) return;
            if (strcmp(o,"Y") == 0) break;
            else if (strcmp(o,"N") == 0) break;
        }
    }while(strcmp(o,"Y") == 0);
    system("cls");
    printf("Exiting to menu...");
    sleep(1);
}

//------------------------------------------------------------------------------------------------------------------------
//                                                       Main function


int main()
{
    sv r[100];
    acc all[100];
    char o[10];
    while(true){
        getUserAccounts(all);
        system("cls");
        do{
            printCentered("Welcome to the Student Management System!\n");
            printCentered("------------------------------------------\n");
            printCentered("1.Login\n");
            printCentered("2.Exit\n");
            printCentered("Enter your choice: ");
            scanf("%s",o);
            if (strcmp(o,"1") == 0) login(all);
            else if (strcmp(o,"2") == 0) exit(0);
            else printf("Wrong option. Please retry!\n");
        } while(strcmp(o,"1") != 0 && strcmp(o,"2") != 0);
        while(true){
            system("cls");
            printf("----------------Features--------------\n");
            printf("1.Add student\n");
            printf("2.Update student\n");
            printf("3.Delete student\n");
            printf("4.Search student\n");
            printf("5.Create Account\n");
            printf("6.Manage Account\n");
            printf("7.Delete Account\n");
            printf("8.Show Account\n");
            printf("9.Logout\n");
            printf("----------------------------------------\n");
            printf("Note: If you want to go back to the menu immediately, type 'exit'\n");
            printf("Enter your choice: ");
            scanf("%s",o);
            getStudentData(r);
            getUserAccounts(all);
            if (strcmp(o,"1") == 0 && all[accountIndex].add) addStudent(r);
            else if (strcmp(o,"1") == 0 && !all[accountIndex].add) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"2") == 0 && all[accountIndex].update) update(r);
            else if (strcmp(o,"2") == 0 && !all[accountIndex].update) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"3") == 0 && all[accountIndex].delete) deleteStudent(r);
            else if (strcmp(o,"3") == 0 && !all[accountIndex].delete) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"4") == 0 && all[accountIndex].search) search(r);
            else if (strcmp(o,"4") == 0 && !all[accountIndex].search) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"5") == 0 && all[accountIndex].createacc) createAcc(all);
            else if (strcmp(o,"5") == 0 && !all[accountIndex].createacc) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"6") == 0 && all[accountIndex].manageacc) accountManagement(all);
            else if (strcmp(o,"6") == 0 && !all[accountIndex].manageacc) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"7") == 0 && all[accountIndex].deleteacc) removeAccount(all);
            else if (strcmp(o,"7") == 0 && !all[accountIndex].deleteacc) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"8") == 0 && all[accountIndex].showacc) showAccount(all);
            else if (strcmp(o,"8") == 0 && !all[accountIndex].showacc) {system("cls");printf("You don't have permission to access this feature!\n");sleep(1);system("cls");}
            else if (strcmp(o,"9") == 0 ) break;
            else if (strcmp(o,"exit") == 0 ) break;
        }
    }
}
