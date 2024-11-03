#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee {
    char name[50];
    int age;
    float salary;
    char job_title[50];
    int id;
    struct employee *next;
};
float queue[50];
int top=-1,rear=-1;

struct employee *head = NULL;

void add_employee() {
    int c;
    struct employee *new_employee = (struct employee *)malloc(sizeof(struct employee));
    printf("Enter name: ");
    char name[50];
    scanf("%s",name);
    strncpy(new_employee->name,name, sizeof(new_employee->name) - 1);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter age: ");
    char age_str[10];
    fgets(age_str, sizeof(age_str),stdin);  
    new_employee->age = atoi(age_str);
    printf("Enter salary: ");
    char salary_str[20];
    fgets(salary_str, sizeof(salary_str), stdin);   
    new_employee->salary = atof(salary_str);
    printf("Enter job title: ");
    char job_tit[50];
    scanf("%s",job_tit);
    strncpy(new_employee->job_title, job_tit, sizeof(new_employee->job_title) - 1);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter ID: ");
    int Id_temp;
    scanf("%d",&Id_temp);
    new_employee->id=Id_temp;
    //new_employee->id = atoi(id_str);
    new_employee->next = NULL;
    if (head == NULL) {
        head = new_employee;
        return;
    }
    struct employee *current_employee = head;
    while (current_employee->next != NULL) {
        current_employee = current_employee->next;
    }
    current_employee->next = new_employee;
}

void delete_employee() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter ID of employee to delete: ");
    int id;
    scanf("%d",&id);
    if (head->id == id) {
        struct employee *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct employee *current_employee = head;
    while (current_employee->next != NULL) {
        if (current_employee->next->id == id) {
            struct employee *temp = current_employee->next;
            current_employee->next = current_employee->next->next;
            free(temp);
            return;
        }
        current_employee = current_employee->next;
    }
    printf("Employee with ID %d not found.\n", id);
}

void modify_employee()
{
    int id;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Enter ID of employee to modify: ");
    scanf("%d",&id);
    struct employee *current_employee = head;
    while (current_employee != NULL)
    {
        if (current_employee->id == id)
        {
            printf("Enter new name (Type %s to keep the same name): ", current_employee->name);
            char new_name[50];
            scanf("%s",new_name);
                strcpy(current_employee->name, new_name);
            printf("Enter new age (Type %d to keep the same age): ", current_employee->age);
            char new_age_str[10];
            scanf("%s",new_age_str);
                current_employee->age = atoi(new_age_str);
            printf("Enter new salary (Type %.2f to keep the same salary): ", current_employee->salary);
            char new_salary_str[20];
            scanf("%s",new_salary_str);
                current_employee->salary = atof(new_salary_str);
            printf("Enter new job title (Type %s to keep the same job title): ", current_employee->job_title);
            char new_job_title[50];
            scanf("%s",new_job_title);
                strcpy(current_employee->job_title, new_job_title);
            printf("Employee with ID %d modified.\n", id);
            return;
        }
        current_employee = current_employee->next;
    }
    printf("Employee with ID %d not found.\n", id);
}

void view_employee()
{
    int id;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Enter ID of employee to view: ");
    char id_str[10];
    scanf("%s",id_str);
    id = atoi(id_str);
    struct employee *current_employee = head;
    while (current_employee != NULL)
    {
        if (current_employee->id == id)
        {
            printf("Name: %s\n", current_employee->name);
            printf("Age: %d\n", current_employee->age);
            printf("Salary: %.2f\n", current_employee->salary);
            printf("Job Title: %s\n", current_employee->job_title);
            printf("ID: %d\n", current_employee->id);
            return;
        }
        current_employee = current_employee->next;
    }
    printf("Employee with ID %d not found.\n", id);
}

void view_all_employees()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct employee *current_employee = head;
    while (current_employee != NULL)
    {
        printf("Name: %s\n", current_employee->name);
        printf("Age: %d\n", current_employee->age);
        printf("Salary: %.2f\n", current_employee->salary);
        printf("Job Title: %s\n", current_employee->job_title);
        printf("ID: %d\n", current_employee->id);
        printf("\n");
        current_employee = current_employee->next;
    }
}

void enqueue(float elem)
{
    if(top==-1)
        top=0;
    rear+=1;
    queue[rear]=elem;
}
float dequeue()
{
    int temp;
    temp=queue[top];
    top+=1;
    return temp;
}

void sort_queue()
{
    int temp;
    float elem;
    repeat:
    temp=top;
    while(temp!=rear)
    {
        if(queue[temp]<queue[temp+1])
        {
            elem=queue[temp];
            queue[temp]=queue[temp+1];
            queue[temp+1]=elem;
            // if(queue[temp]=queue[temp+1])
            // {
                
            // }
            goto repeat;
        }
        temp=temp+1;
    }
}

void add_queue()
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    float temp;
    struct employee *Id_check = head;
    while(Id_check!=NULL)
    {
        temp=Id_check->salary;
        enqueue(temp);
        Id_check=Id_check->next;
    }
    sort_queue();
    printf("The employee list is updated\n");
    printf("You can now credit the salary\n");

}

void credit_salary()
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if(top==-1)
    {
        printf("Please update the employee list to credit salary\n");
        printf("Press 6 to update\n");
        return;
    }
    int no;
    float search_salary;
    int temp=top;
    // while(temp!=rear+1)
    // {
    //     printf("%d",queue[temp]);
    //     temp+=1;
    // }
    search_salary=dequeue();
    if(top>=rear+2)
    {
        printf("Salary has been creditd to all the employee");
        return;
    }
    printf("------ The salary is credited based on the the employee post------\n");
    printf("The salary to be credited to the employee is:\n");
    // printf("%d",top);
    // printf("%d",rear);
    // printf("%d",Id_emp);
    struct employee *search = head;
    while(search!=NULL)
    {
        if(search->salary==search_salary)
        {
            printf("ID: %d\n", search->id);
            printf("Name: %s\n", search->name);
            printf("Age: %d\n", search->age);
            printf("Job Title: %s\n",search->job_title);
            printf("Salary: %.2f\n", search->salary);
            printf("do you want to credit the salary now \n");
            printf("if yes 1\n");
            printf("if later 0 \n");
            scanf("%d",&no);
            if(no==1)
            {
                printf("The salary has been credited to the employee %s of Ruppes :%.2f\n",search->name,search->salary);
                return;
            }
            else
            {
                enqueue(search_salary);
            }

        }
        search=search->next;
    }
}

int main()
{
    int choice;
    do
    {
        printf("1. Add new employee\n");
        printf("2. Delete employee\n");
        printf("3. Modify employee\n");
        printf("4. View employee\n");
        printf("5. View all employees\n");
        printf("6. Update employee list to credit Salary\n");
        printf("7. Credit the salary to the employee\n");
        printf("8. exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            add_employee();
            break;
        case 2:
            delete_employee();
            break;
        case 3:
            modify_employee();
            break;
        case 4:
            view_employee();
            break;
        case 5:
            view_all_employees();
            break;
        case 6:
            add_queue();
            break;
        case 7:
            credit_salary();
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    }
    while (choice != 8);
    return 0;
}