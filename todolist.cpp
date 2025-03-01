#include <iostream>
#include <string>
using namespace std;

string todo[10];
int counter = 0;

void menu();
void error() {
    cout << "Invalid choice!" << endl;
    cout << "-----------------------------------" << endl;
    menu();
}
void check() {
    if(counter == 10){
        cout << "List is full!" << endl;
        cout << "-----------------------------------" << endl;
        menu();
    }
}
void add() {
    int choose;
    string task;
    check();
    cout << "Enter the task: ";
    getline(cin, task);
    todo[counter] = task;
    counter++;
    cout << "-----------------------------------" << endl;
    cout << "1) Add another task" << endl;
    cout << "2) Back to main menu" << endl;
    cout << "Choose: ";
    cin >> choose;
    cin.ignore();
    cout << "-----------------------------------" << endl;
    if (choose == 1) {
        add();
    } else if (choose == 2) {
        menu();
    } else {
        error();
    }
}

void erase() {
    int choose;
    cout << "Enter the done task number: ";
    cin >> choose;
    cin.ignore();
    if (choose > counter) {
        error();
    } else {
        for (int i = choose - 1; i < counter; i++) {
            todo[i] = todo[i + 1];
        }
        counter--;
    }
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < counter; i++) {
        cout << i + 1 << ". " << todo[i] << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "1) Tick another done task" << endl;
    cout << "2) Back to main menu" << endl;
    cout << "Choose: ";
    cin >> choose;
    cin.ignore();
    cout << "-----------------------------------" << endl;
    if (choose == 1) {
        erase();
    } else if (choose == 2) {
        menu();
    } else {
        error();
    }
}

void display() {
    cout << "Tasks: " << endl;
    if(counter == 0){
        cout << "No tasks!" << endl;
        cout << "-----------------------------------" << endl;
    }
    else{
        for (int i = 0; i < counter; i++) {
            cout << i + 1 << ". " << todo[i] << endl;
        }
    }
    cout << "1) Tick a done task" << endl;
    cout << "2) Back to main menu" << endl;
    int choose;
    cout << "Choose: ";
    cin >> choose;
    cin.ignore();
    cout << "-----------------------------------" << endl;
    if (choose == 1) {
        erase();
    } else if (choose == 2) {
        menu();
    } else {
        error();
    }
}

void menu() {
    int choose;
    cout << "1) add task" << endl;
    cout << "2) To-Do List" << endl;
    cout << "3) Exit" << endl;
    cout << "Choose: ";
    cin >> choose;
    cin.ignore();
    cout << "-----------------------------------" << endl;
    if (choose == 1) {
        add();
    } else if (choose == 2) {
        display();
    } else if (choose == 3) {
        cout << "Goodbye!" << endl;
        cout << "-----------------------------------" << endl;
    } else {
        error();
    }
}

int main() {
    menu();
    return 0;
}
