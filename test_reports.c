#include <stdio.h>
#include <string.h>
#include "reports.h"

int main(void)
{ 
   int employeeIDs[3] = {101, 102, 103};
   char employeeNames[3][50] = {"Anna Smith", "John Doe", "Maria Nangolo"};
   float employeeSalaries[3] = {50000.00, 60000.00, 55000.00};

   char departments[3][50] = {"HR", "FINANACE", "IT"};
   float departmentBudgets[3] = {100000.00, 150000.00, 200000.00};
   float departmentSpent[3] = {90000.00, 160000.00, 180000.00};

   char supplierNames[3][100] = {"ABC Hardware", "Coastal Suppliers", "Tech Solutions"};
   char supplierEmails[3][100] = {"john@abchardware.com", "jane@coastalsuppliers.com", "bob@techsolutions.com"};
   char supplierPhones[3][30] = {"0812345678", "0819876543", "0813456789"};
   char supplierTowns[3][50] = {"Windhoek", "Swakopmund", "Walvis Bay"};

   char assetNames[3][50] = {"Laptop", "Projector", "Printer"};
   float assetValues[3] = {1500.00, 800.00, 300.00};

   displayReportsMenu(); 
   printf("\n");

   employeeReport(employeeIDs, employeeNames, employeeSalaries, 3);
   budgetReport(departments, departmentBudgets, departmentSpent, 3);
   supplierReport(supplierNames, supplierEmails, supplierPhones, supplierTowns, 2);
   assetReport(assetNames, assetValues, 3);

   return 0;
}