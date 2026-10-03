#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 10

extern char departmentNames[MAX_DEPARTMENTS][100];
extern float allocatedBudgets[MAX_DEPARTMENTS];
extern float expenditures[MAX_DEPARTMENTS];
extern int departmentCount;

void addBudget();
void displayBudgets();
void checkBudget();

#endif