#include<iostream>
using namespace std;
int main()
{
   int ID[100];
    float salary[100];
    char designation[100][20];
    char doj[100][20];
    int count = 0;
    int choice;
    do 
    {
        cout << "\n--------------------- EMPLOYEES MANAGEMENT SYSTEM ------------------\n";
        cout << "1. Enter the ID number of an employee\n";
        cout << "2. Update the details of an employee\n";
        cout << "3. Delete the details of a particular employee\n";
        cout << "4. Display the details of all employees\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                if (count < 100) 
                {
                    cout << "Enter Employee ID: ";
                    cin >> ID[count];
                    cout << "Enter Employee Salary: ";
                    cin >> salary[count];
                    cout << "Enter Joining Date (DD/MM/YYYY): ";
                    cin >> doj[count];
                    cout << "Enter Designation: ";
                    cin >> designation[count];
                    cout << "Employee added successfully at record" << endl;
                    count++;
                } 
                else 
                {
                    cout << "Employee limit reached.\n";
                }
                break;
            case 2: 
            {
                int id, i;
                cout << "Enter Employee ID to update: ";
                cin >> id;
                for (i = 0; i < count; i++)
                {
                    if (ID[i] == id)
                    {
                        cout << "Enter new Employee ID: ";
                        cin >> ID[i];
                        cout << "Enter new Salary: ";
                        cin >> salary[i];
                        cout << "Enter new Joining Date (DD/MM/YYYY): ";
                        cin >> doj[i];
                        cout << "Enter new Designation: ";
                        cin >> designation[i];
                        cout << "Employee details updated successfully!\n";
                        break;
                    }
                }
                if (i == count)
                {
                    cout << "Employee not found.\n";
                }
                break;
            }
            case 3: 
            {
                int id, i, j;
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                for (i = 0; i < count; i++) 
                {
                    if (ID[i] == id)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            ID[j] = ID[j + 1];
                            salary[j] = salary[j + 1];
                            for (int k = 0; k < 20; k++) 
                            {
                                doj[j][k] = doj[j + 1][k];
                                designation[j][k] = designation[j + 1][k];
                            }
                        }
                        count--;
                        cout << "Employee deleted successfully!\n";
                        break;
                    }
                }
                if (i == count) 
                {
                    cout << "Employee not found.\n";
                }
                break;
            }
            case 4:
                if (count == 0)
                {
                    cout << "No employee records to display.\n";
                } 
                else
                {
                    cout << "\n--- Employee List ---\n";
                    for (int i = 0; i < count; i++)
                    {
                        cout << "Record " << i + 1
                             << ": ID Number = " << ID[i]
                             << ", Salary = " << salary[i]
                             << ", Joining Date = " << doj[i]
                             << ", Designation = " << designation[i] << endl;
                    }
                }
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } 
    while (choice != 5);
    return 0;
}