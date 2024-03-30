#include <iostream>

using namespace std;

struct Task
{
    int taskNumber;
    string taskDescription;
    string status;
};

class List
{
private:
    int size;
    int currSize;
    Task *workList;

public:
    List()
    {
        size = 100;
        currSize = 0;
        workList = new Task[size];
    }

    ~List() // destructor to dellocate memory
    {
        delete[] workList;
    }

    void AddTask()
    {
        // Checking if list size is not full
        if (currSize == size)
        {
            size *= 2;
            Task *newWorkList = new Task[size];
            for (int i = 0; i < currSize; ++i)
            {
                newWorkList[i] = workList[i];
            }

            delete[] workList;

            workList = newWorkList;
        }

        // Adding task by asking user to input
        workList[currSize].taskNumber = currSize + 1;
        cin.ignore();

        cout << " Enter Task Description: ";
        getline(cin, workList[currSize].taskDescription);

        // initializing all tasks to pending when they added
        workList[currSize].status = "Pending";

        currSize++;

        cout << "\nTask added successfully." << endl;
    }

    void RemoveTask()
    {
        int choice;
        // Removing task
        cout << "These Are Your Tasks:" << endl;

        ViewTask();

        cout << endl
             << "Enter Task Number you want to Remove: ";

        cin >> choice;

        // Checking if user number is valid
        if (choice < 1 || choice > currSize)
        {
            cout << "\nInvalid task number." << endl;

            return;
        }

        for (int i = choice - 1; i < currSize - 1; ++i)
        {
            workList[i].taskDescription = workList[i + 1].taskDescription;
            workList[i].status = workList[i + 1].status;
        }

        currSize--;
        cout << "\nTask removed successfully." << endl;
    }

    void ViewTask()
    {
        for (int i = 0; i < currSize; i++)
        {
            cout << workList[i].taskNumber << ". " << workList[i].taskDescription << " " << workList[i].status << endl;
        }

        cout << endl;
    }

    void ChangeStatus()
    {
        int choice;

        cout << "These Are Your Tasks:" << endl;

        ViewTask();

        cout << endl
             << "Enter the Task Number of the task that you have completed: ";

        cin >> choice;

        if (choice < 1 || choice > currSize)
        {
            cout << "Invalid task number." << endl;

            return;
        }

        workList[choice - 1].status = "Completed";

        cout << "\nStatus updated successfully." << endl;
    }
};

int main()
{
    cout << "---------------------------------------------------" << endl
         << "-----------Welcome To Zain's TASK MANAGER-----------" << endl
         << "----------------------------------------------------" << endl;

    List ToDo;
    int choice;

    do
    {

        cout << "------Menu----" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Task Completion" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice (1-5): ";

        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:

            cout << "You chose to add a task." << endl;
            ToDo.AddTask();

            break;

        case 2:

            cout << "You chose to remove a task." << endl;
            ToDo.RemoveTask();

            break;

        case 3:

            cout << "You chose to view tasks." << endl;
            ToDo.ViewTask();

            break;

        case 4:

            cout << "You chose to change task status to completed." << endl;
            ToDo.ChangeStatus();

            break;

        case 5:

            cout << "Exiting program..." << endl;

            break;

        default:

            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
        cout << endl;
    } while (choice != 5);

    cout << endl
         << endl
         << "---------------------------------------------------" << endl
         << "-------------THANK YOU! PLEASE COME AGAIN---------" << endl
         << "---------------------------------------------------" << endl;

    return 0;
}
