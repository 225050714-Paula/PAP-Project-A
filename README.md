# Municipal Financial Management System (MFMS)

## Course: PAP521S – Programming in Practice
## Project: Project A 

## Group Members: 

Eckylas Eliaser	        225160536,	

Penouua Kahorere	      225120216,

Glen Kulobone	          225050293,

Ngeseuako K Hambira	    225030713, 

Maundjiro Kanguatjivi	  225047500,

Iyambo Matti-Uva	      225144662,

Paula Monder	          225050714 

## Project Description:

The Municipal Financial Management System (MFMS) is a menu-driven console application written in C for a municipality. It stores and manages employee, budget, supplier and asset information, performs salary and budget calculations, searches records and produces summary reports. This is the foundation version of the system and will be extended and refactored in Project B.

## System Features:
Main menu: clear navigation between modules, with invalid choices handled.
Employee management: add, display and search employees (by name), and calculate total salary (basic salary + housing and transport allowances).
Budget management: enter departmental budgets and expenditure, calculate the remaining budget, show WITHIN BUDGET or EXCEEDED, and list departments that exceeded their budget.
Supplier management: add and display suppliers, search by ID or name (not case-sensitive, partial match), and compare suppliers by town.
Asset management: add and display assets, and search by asset ID.
Reports: employee report (total, average, highest and lowest salary), budget report, supplier report and asset report.
Input validation: rejects negative salaries and budgets, empty names, invalid emails, duplicate supplier IDs and invalid menu choices.

## Compilation:

## Make sure GCC is installed, then run this from the project folder:

gcc -std=c99 -Wall -Wextra main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
How to Run

Linux / macOS:

./mfms

Windows:

mfms.exe

Use the number keys to choose an option from the main menu. Choose Exit to close the program.

## Individual Responsibilities:

 Eckylas Eliaser (225160536) – Employee Management: employees.c and employees.h. Functions: addEmployee(), displayEmployees(), searchEmployee(), calculateSalary().

 Penouua Kahorere (225120216) – Budget Management: budget.c and budget.h. Functions: addBudget(), displayBudgets(), checkBudget().

 Glen Kulobone (225050293) – Supplier Management: suppliers.c and suppliers.h. Functions: addSupplier(), displaySuppliers(), searchSupplier(), compareSupplier(), plus helper functions for safe number input, email validation and duplicate ID checks.

 Ngeseuako K Hambira (225030713) – Asset Management: assets.c and assets.h. Functions: addAsset(), displayAssets(), searchAsset().

 Maundjiro Kanguatjivi (225047500) – Reports: reports.c and reports.h. Functions: displayReportsMenu(), employeeReport(), budgetReport(), supplierReport(), assetReport().

 Iyambo Matti-Va (225144662) – Functions, integration and validation: main.c and the main menu, and integration of all modules into one program.

 Paula Monder (225050714) – Testing, documentation and Git coordination: testing across modules, this README, the technical report, and repository management.
