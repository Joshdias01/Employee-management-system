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
int front=-1,rear=-1;
struct employee *head = NULL;
void add_employee() {
    int c;
    struct employee *new_employee = (struct employee *)malloc(sizeof(struct employee));
    printf("Enter name: ");
    getchar();
    scanf("%[^\n]s",new_employee->name);
    getchar();
    printf("Enter age: ");
    scanf("%d",&new_employee->age);
    printf("Enter salary: ");
    scanf("%f",&new_employee->salary);
    printf("Enter job title: ");
    getchar();
    scanf("%[^\n]s",new_employee->job_title);
    getchar();
    printf("Enter ID: ");
    scanf("%d",&new_employee->id);
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
            printf("Enter new name (type %s to keep the same): ", current_employee->name);
            char new_name[50];
            getchar();
            scanf("%[^\n]s",new_name);
            getchar();
            if (strlen(new_name) > 0)
            {
                strcpy(current_employee->name, new_name);
            }
            printf("Enter new age (type %d to keep the same): ", current_employee->age);
            scanf("%d",&current_employee->age);
            printf("Enter new salary (type %.2f to keep the same): ", current_employee->salary);
            scanf("%f",&current_employee->salary);
            // char new_salary[50];
            // getchar();
            // scanf("%s",new_salary);
            // getchar();
            // if (strlen(new_salary) > 0)
            // {
            //     current_employee->salary = atof(new_salary);
            // }
            // scanf("%f",current_employee->salary);
            printf("Enter new job title (type %s to keep the same): ", current_employee->job_title);
            char new_job_title[50];
            getchar();
            scanf("%[^\n]s",new_job_title);
            getchar();
            if (strlen(new_job_title) > 0)
            {
                strcpy(current_employee->job_title, new_job_title);
            }
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
    if(front==-1)
        front=0;
    rear+=1;
    queue[rear]=elem;
}
float dequeue()
{
    int temp;
    temp=queue[front];
    front+=1;
    return temp;
}
void sort_queue()
{
    int temp;
    float elem;
    repeat:
    temp=front;
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
void credit_salary() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (front == -1) {
        printf("Please update the employee list to credit salary first.\n");
        printf("Press 6 to update the list.\n");
        return;
    }

    printf("------ Salary Crediting Based on Employee Post ------\n");

    while (front <= rear) {
        // Get the salary to be credited (dequeue the front element)
        float current_salary = dequeue();

        int found = 0; // Flag to check if any employee matches the salary
        struct employee *current = head;

        while (current != NULL) {
            if (current->salary == current_salary) {
                found = 1; 
                printf("\nEmployee Details:\n");
                printf("ID: %d\n", current->id);
                printf("Name: %s\n", current->name);
                printf("Age: %d\n", current->age);
                printf("Job Title: %s\n", current->job_title);
                printf("Salary: %.2f\n", current->salary);

                int choice;
                printf("Do you want to credit the salary now?\n");
                printf("1. Yes\n");
                printf("0. No (credit later)\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("The salary of Rs. %.2f has been credited to employee %s (ID: %d).\n", current->salary, current->name, current->id);
                } else {
                    enqueue(current_salary);
                    printf("Salary of %.2f will be credited later.\n", current_salary);
                }
            }
            current = current->next;
        }

        if (!found) {
            printf("No employee found with a salary of %.2f.\n", current_salary);
        }
    }

    if (front > rear) {
        printf("\nAll salaries have been processed.\n");
        front = rear = -1; 
    }
}
void admin()
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
    return;
}
void access_admin()
{
    int a;
    char Username[50],password[50];
    strcpy(Username,"joshua");
    strcpy(password,"josh12");
    char user[50],pass[50];
    printf("Enter username :");
    scanf("%s",user);
    printf("Enter password :");
    scanf("%s",pass);
    if(strcmp(user,Username)==0 && strcmp(pass,password)==0)
    {
        admin();
    }
    else 
    {
        printf("Acess denied !!\n Invalid Username or Password \n");
        return;
    }

}
void emp_view(int id)
{
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

            int temp = front;
            int credited = 0;
            if(temp==-1)
                credited=1;
            while (temp <= rear && temp != -1)
            {
                if (queue[temp] == current_employee->salary)
                {
                    credited = 1;
                    break;
                }
                temp++;
            }
            if (credited)
            {
                printf("Your salary for this month has NOT been credited yet.\n");
            }
            else
            {
                printf("Your salary for this month has been credited.\n");
            }
            return;
        }
        current_employee = current_employee->next;
    }
    printf("Employee with ID %d not found.\n", id);
    return;
}
void main()
{
    int choice,emp_id;
    do
    {
        printf("1.ADMIN Login\n");
        printf("2.EMPLOYEE Login\n");
        printf("3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: access_admin();
            break;
            case 2:
            printf("Enter your Employee ID : ");
            scanf("%d",&emp_id);
            emp_view(emp_id);
            break;
            case 3:
            printf("Exiting.....");
            break;
            default :
            printf(" Invalid choice !");
        }
    }while(choice != 3);
}