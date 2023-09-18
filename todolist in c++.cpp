#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << std::endl;
    }

    void viewTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description <<endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description <<endl;
        } else {
            cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description <<endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." <<endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        cout << "Options:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task description: ";
            string desc;
            cin.ignore();
            getline(cin, desc);
            todoList.addTask(desc);
        } else if (choice == 2) {
            todoList.viewTasks();
        } else if (choice == 3) {
            cout << "Enter task number to mark as completed: ";
            size_t index;
            cin >> index;
            todoList.markTaskAsCompleted(index);
        } else if (choice == 4) {
            cout << "Enter task number to remove: ";
            size_t index;
            cin >> index;
            todoList.removeTask(index);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." <<endl;
        }
    }

    return 0;
}

