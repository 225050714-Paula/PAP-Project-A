#ifndef REPORTS_H
#define REPORTS_H

void displayReportsMenu(void);
void employeeReport(int employeeIDs[], char names[][100], float salaries[], int count);
void budgetReport(char departments[][100], float budgets[], float spent[], int count);
void supplierReport(char names[][100], char emails[][100], char phones[][30], char towns[][100], int count);
void assetReport(char assetNames[][50], float values[], int count);

#endif