#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

string tasks[MAX_TASKS];
bool isCompleted[MAX_TASKS];
int taskCount = 0;

// Function to add a task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!" << endl;
        return;
    }
    cin.ignore(); // Clear input buffer
    cout << "Enter the task: ";
    getline(cin, tasks[taskCount]);
    isCompleted[taskCount] = false;
    taskCount++;
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\n--- To-Do List ---\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << " [";
        cout << (isCompleted[i] ? "Completed" : "Pending") << "]\n";
    }
    cout << "------------------\n";
}

// Function to mark a task as completed
void markCompleted() {
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    if (index < 1 || index > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }
    isCompleted[index - 1] = true;
    cout << "Task marked as completed!\n";
}

// Function to delete a task
void deleteTask() {
    int index;
    cout << "Enter the task number to delete: ";
    cin >> index;
    if (index < 1 || index > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }
    for (int i = index - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
        isCompleted[i] = isCompleted[i + 1];
    }
    taskCount--;
    cout << "Task deleted successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n=== TO-DO LIST MANAGER ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
