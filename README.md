#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    int id;
    float hourlyRate;
    float hoursWorked;
};

float calculateSalary(float hourlyRate, float hoursWorked) {
    return hourlyRate * hoursWorked;
}

void generatePayStub(struct Employee emp, float salary) {
    printf("\n------ Pay Stub ------\n");
    printf("Employee ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Hourly Rate: $%.2f\n", emp.hourlyRate);
    printf("Hours Worked: %.2f\n", emp.hoursWorked);
    printf("Total Salary: $%.2f\n", salary);
    printf("----------------------\n");
}

int main() {
    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    struct Employee *employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));

    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        
        // Clear the input buffer
        while (getchar() != '\n');

        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);

        printf("Employee ID: ");
        scanf("%d", &employees[i].id);

        printf("Hourly Rate: ");
        scanf("%f", &employees[i].hourlyRate);

        printf("Hours Worked: ");
        scanf("%f", &employees[i].hoursWorked);
    }

    for (int i = 0; i < numEmployees; i++) {
        float salary = calculateSalary(employees[i].hourlyRate, employees[i].hoursWorked);
        generatePayStub(employees[i], salary);
    }

    free(employees);

    return 0;
}
