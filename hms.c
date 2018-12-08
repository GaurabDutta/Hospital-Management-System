#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu();
void create_details();
void save_txt();
void save_bin();
void display_all();
void display_id();
void display_name();
void display_ward();
void delete_id();
void delete_all();

struct hms
{
    int id;
    char name[20];
    int ward_no;
    char gender;
    int age;
    char blood_group[10];
    struct hms*next;
};

typedef struct hms node;
node *first=NULL, *last=NULL;
static int id;

void create()
{
    int op;
    printf("\t1. Create three new entries\n\n");
    printf("\t2. Create one more new entry\n\n");
    printf("\n\n\tEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            system("clear");
            printf("\n\n\t***Create Three New Entries***\n\n");
            create_details();
            create_details();
            create_details();
            getchar();
            getchar();
            break;
        case 2:
            system("clear");
            printf("\n\n\t***Create One More New Entry***\n\n");
            create_details();
            getchar();
            getchar();
            break;
        default:
            system("clear");
            printf("\n\n\tInvalid Option!\n\n");
            getchar();
            getchar();
    }
}

void create_details()
{
    node *new=(node*)malloc(sizeof(node));
	printf("\tEnter the patient Name: ");
    getchar();
    fgets(new->name,32,stdin);
	printf("\tEnter ward number: ");
	scanf("%d",&new->ward_no);
	printf("\tEnter Gender(M/F): ");
    getchar();
	scanf("%c",&new->gender);
	printf("\tEnter Age: ");
	scanf("%d",&new->age);
    printf("\tEnter blood group: ");
    scanf("%s",new->blood_group);

    if(first==NULL)
    {
        id=id+1;
        new->id=id;
        printf("\tPatient ID: %d\n",new->id);
        new->next=NULL;
        first=last=new;
    }
    else
    {
        id=id+1;
        new->id=id;
        new->next=NULL;
        printf("\tPatient ID: %d\n",new->id);
        last->next=new;
        last=new;
    }
    printf("\n");
}

void save()
{
    int op;
    printf("\n\n\t***Save Entries***\n\n");
    printf("\n\t1. Save in text mode\n");
    printf("\n\t2. Save in binary mode\n");
    printf("\n\n\tChoose one option: ");
    //getchar();
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            system("clear");
            save_txt();
            break;
        case 2:
            system("clear");
            save_bin();
            break;
        default:
            system("clear");
            printf("\n\n\tInvalid option!\n\n");
            getchar();
            getchar();
    }
}

void save_txt()
{
    FILE *fp =fopen("file.txt","a+");
    node *temp=first;
    while(temp!=NULL)
    {
        fprintf(fp,"\tPatient ID:%d\n",temp->id);
        fprintf(fp,"\tPatient Name:%s\n",temp->name);
        fprintf(fp,"\tWard Number:%d\n",temp->ward_no);
        fprintf(fp,"\tGender:%c\n",temp->gender);
        fprintf(fp,"\tAge:%d\n",temp->age);
        fprintf(fp,"\tBlood Group :%s\n",temp->blood_group);
        temp=temp->next;
    }
    free(temp);
    fclose(fp);
    printf("\n\n\t***File Saved in Text mode***\n\n");
    getchar();
    getchar();
}

void save_bin()
{
    FILE *fp=fopen("file_bin.txt","a+");
    node *temp=first;
    char str1[11]="Patient ID:";
    char str2[5]="Name:";
    char str3[12]="Ward Number:";
    char str4[7]="Gender:";
    char str5[4]="Age:";
    char str6[12]="Blood Group:";
    char str='\n';
    while(temp!=NULL)
    {
        fwrite(str1, strlen(str1)+1, 1, fp);
        fwrite(&temp->id, sizeof(temp->id), 1, fp);
        fwrite(&str, 1, 1, fp);
        fwrite(str2, strlen(str1)+1, 1, fp);
        fwrite(&temp->id, sizeof(temp->name), 1, fp);
        fwrite(&str, 1, 1, fp);
        fwrite(str3, strlen(str1)+1, 1, fp);
        fwrite(&temp->id, sizeof(temp->ward_no), 1, fp);
        fwrite(&str, 1, 1, fp);
        fwrite(str4, strlen(str1)+1, 1, fp);
        fwrite(&temp->id, sizeof(temp->gender), 1, fp);
        fwrite(&str, 1, 1, fp);
        fwrite(str5, strlen(str1)+1, 1, fp);
        fwrite(&temp->id, sizeof(temp->age), 1, fp);
        fwrite(&str, 1, 1, fp);
        fwrite(str6, strlen(str1)+1, 1, fp);
        fwrite(&temp->id, sizeof(temp->blood_group), 1, fp);
        fwrite(&str, 1, 1, fp);
        fwrite(&str, 1, 1, fp);
        temp=temp->next;
    }
    free(temp);
    fclose(fp);
    printf("\n\n\t***File Saved in Binary Mode***\n\n");
    getchar();
    getchar();

}

void display()
{
    int op;
    printf("\n\n\t***Display Details!***\n\n");
    printf("\n\t1. Display All\n");
    printf("\n\t2. Display by ID\n");
    printf("\n\t3. Display by Name\n");
    printf("\n\t4. Display by Ward Number\n");
    printf("\n\n\tEnter your choice: ");
    scanf("%d",&op);
    printf("\n");
    switch(op)
    {
        case 1:
            system("clear");
            display_all();
            break;
        case 2:
            system("clear");
            display_id();
            break;
        case 3:
            system("clear");
            display_name();
            break;
        case 4:
            system("clear");
            display_ward();
            break;
        default:
            system("clear");
            printf("\n\n\tInvalid Option!\n\n");
            getchar();
            getchar();
    }
    printf("\n");
}

void display_all()
{
    node *temp=first;
    if (first==NULL)
    {
        printf("\n\n\tNo patient information found!\n\n");
    }
    while(temp!=NULL)
    {
        printf("\n\tPatient id: %d ",temp->id);
        printf("\n\tPatient Name: %s",temp->name);
	    printf("\tWard Number: %d",temp->ward_no);
	    printf("\n\tPatient Gender: %c",temp->gender);
	    printf("\n\tPatient Age: %d",temp->age);
        printf("\n\tPatient Blood Group: %s",temp->blood_group);
        printf("\n");
        temp=temp->next;
    }
    free(temp);
    getchar();
    getchar();
}

void display_id()
{
    int i;
    FILE *fp=fopen("file.txt","r");
    node *temp=first;
    printf("\n\n\tEnter Patient ID: ");
    scanf("%d",&i);
    if(temp==NULL)
        printf("\n\n\tNo patient information found!\n\n");
    while(temp!=NULL)
    {
        if(temp->id==i)
        {
            printf("\n\tPatient ID: %d ",temp->id);
	        printf("\n\tPatient Name: %s",temp->name);
	        printf("\tWard Number: %d",temp->ward_no);
	        printf("\n\tPatient Gender: %c",temp->gender);
    	    printf("\n\tPatient Age: %d",temp->age);
            printf("\n\tPatient Blood Group: %s",temp->blood_group);
            printf("\n");
        }
        temp=temp->next;
    }
    printf("\n");
    free(temp);
    fclose(fp);
    getchar();
    getchar();
}

void display_name()
{
    char str[32];
    node *temp=first, *temp1=first;
    getchar();
    printf("\n\n\tEnter Patient Name: ");
    fgets(str,32,stdin);
    while(temp!=NULL)
    {
        if(strcmp(temp->name,str)==0)
        {
            printf("\n\tPatient ID: %d ",temp->id);
	        printf("\n\tPatient Name: %s",temp->name);
	        printf("\tWard Number: %d",temp->ward_no);
	        printf("\n\tPatient Gender: %c",temp->gender);
    	    printf("\n\tPatient Age: %d",temp->age);
            printf("\n\tPatient Blood Group: %s",temp->blood_group);
            printf("\n");
        }
        else
        temp1=temp1->next;
        temp=temp->next;
    }
    if (temp1==NULL)
    {
        printf("\n\n\tNo patient information found!\n\n");
    }
    printf("\n");
    getchar();
}

void display_ward()
{
    int i;
    node *temp=first, *temp1=first;
    printf("\n\n\tEnter Ward number: ");
    scanf("%d",&i);
    if(temp==NULL)
        printf("\n\n\tNo patient information found!\n\n");
    while(temp!=NULL)
    {
        if(temp->ward_no==i)
        {
            printf("\n\tPatient ID: %d ",temp->id);
	        printf("\n\tPatient Name: %s",temp->name);
	        printf("\tWard Number: %d",temp->ward_no);
	        printf("\n\tPatient Gender: %c",temp->gender);
    	    printf("\n\tPatient Age: %d",temp->age);
            printf("\n\tPatient Blood Group: %s",temp->blood_group);
            printf("\n");
        }
        else
        temp1=temp1->next;
        temp=temp->next;

        if(temp1==NULL)
        {
            printf("\n\n\tNo patient information found!/n/n");
        }
    }
    printf("\n");
    getchar();
    getchar();
}

void delete()
{
    int op;
    printf("\n\n\t***Delete Entry***\n\n");
    printf("\n\t1. Delete by ID\n");
    printf("\n\t2. Delete all\n");
    printf("\n\n\tChoose one option: ");
    //getchar();
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            system("clear");
            delete_id();
            break;
        case 2:
            system("clear");
            printf("\n\n\tDo you want to continue[Y/N]: ");
            getchar();
            char ch= fgetc(stdin);
            getchar();
            if (ch=='Y'||ch=='y')
                delete_all();
            else if(ch=='N'||ch=='n')
                return;
            else
                printf("\n\n\tInvalid Option!\n\n");
            break;
        default:
            system("clear");
            printf("\n\n\tInvalid option!\n\n");
            getchar();
            getchar();
    }
}

void delete_id()
{
    int key;
	printf("\n\n\tEnter the ID: ");
	scanf("%d",&key);
	node*temp=first, *temp1;
    if(temp==NULL)
    {
        printf("\n\n\t***Database is empty***\n\n");
        getchar();
        getchar();
        return;
    }
    else
    {
        printf("\n\n\tDo you want to continue[Y/N]: ");
        getchar();
        char ch= fgetc(stdin);
        getchar();
        if(ch=='y'||ch=='Y')
        {
            if(temp==first)
            {
                first=first->next;
            }
            else
            {
                while(temp->id!=key)
	            {
		            temp1=temp;
                    temp=temp->next;
	            }
                temp1->next=temp->next;
            }
            free(temp);
            printf("\n\n\tID Deleted!\n\n");   
        }
        else if(ch=='n'||ch=='N')
            return;
        else
            printf("\n\n\tInvalid Option!\n\n");
    }
    //getchar();
    getchar();
}

void delete_all()
{
    node *temp=first, *temp1;
    if(first==NULL)
    {
        printf("\n\n\t***Database is already empty***\n\n");
        getchar();
        return;
    }
	while(temp!=NULL)
	{
		temp1=temp->next;
        free(temp);
        temp=temp1;
	}
    first=NULL;
    printf("\n\n\t***All Data Deleted***\n\n");
    //getchar();
    getchar();
}

void menu()
{
    int choice;
    system("clear");
    printf("\n\n\tHOSPITAL MANAGEMENT SYSTEM\n\n\n\n");
    printf("\t1. Create entries\n\n");
    printf("\t2. Save entries\n\n");
    printf("\t3. Display entries\n\n");
    printf("\t4. Delete entries\n\n");
    printf("\t5. Exit\n\n");
    printf("\n\tEnter your choice: ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
        case 1:
            system("clear");
            printf("\n\n\t***Create New Entries***\n\n\n");
            create();
            break;
        case 2:
            system("clear");
            save();
            break;
        case 3:
            system("clear");
            display();
            break;
        case 4:
            system("clear");
            delete();
            break;
        case 5:
            system("clear");
            exit(1);
            break;
        default:
            system("clear");
            printf("\n\n\tInvalid Option!\n\n");
            getchar();
            getchar();
    }
}

void main()
{
    int i=0;
    char str[10]="*****";
    char pw[10];
    system("clear");
    printf("\n\n\tEnter password: ");
    scanf("%s",pw);
    while(1)
    {
        if(strcmp(str,pw)==0)
            break;
        else
        {
            if(i==2)
            {
                printf("\n\n\t***Maximum attemp reached!***\n\n\n");
                exit(1);
            }
            else
            {
                i++;
                printf("\n\tIncorrect Password!\n\n");
                printf("\n\tEnter password again: ");
                scanf("%s",pw);
            }
        }
    }
    printf("\n\n\t\tWelcome!!!\n");
    getchar();
    getchar();
    system("clear");
    while(1)
    {
    //    system("clear");
        menu();
    }
}
