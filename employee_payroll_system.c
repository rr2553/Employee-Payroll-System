#include <stdio.h>
#include <stdlib.h>

// Structure to store employee information
struct Employee {
    char name[50];
    int id;
    float hourlyRate;
    float hoursWorked;
};

// Function to calculate salary
float calculateSalary(float hourlyRate, float hoursWorked) {
    return hourlyRate * hoursWorked;
}

// Function to display pay stub
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

    // Dynamically allocate memory for an array of employees
    struct Employee *employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));

    // Input employee information
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Hourly Rate: ");
        scanf("%f", &employees[i].hourlyRate);
        printf("Hours Worked: ");
        scanf("%f", &employees[i].hoursWorked);
    }

    // Calculate and display pay stubs
    for (int i = 0; i < numEmployees; i++) {
        float salary = calculateSalary(employees[i].hourlyRate, employees[i].hoursWorked);
        generatePayStub(employees[i], salary);
    }

    // Free allocated memory
    free(employees);

    return 0;
}
