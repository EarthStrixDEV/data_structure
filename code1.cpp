#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Employee {
private:
    string name = "no name";
    int salary = 0;
public:
    Employee(){
        cout << "Create Constructor of Employee" << endl;
    }
    Employee(string n){
        name = n;
    }
    Employee(string n ,int s){
        name = n;
        salary = s;
    }
    Employee(int s,string n){
        salary = s;
        name = n;
    }
    void setName(string n){
        name = n;
    }
    void setSalary(int s){
        salary = s;
    }
    string getName(){
        return name;
    }
    int getSalary(){
        return salary;
    }
    void showData(){
        cout << "Name = " << name << endl;
        cout << "Salary = " << salary << endl;
    }
};
class IT : public Employee{
public:
    IT() {
        cout << "Create IT Object" << endl;
    }
    IT(string n ,int s) : Employee(n,s){
        
    }
};
class Sale : public Employee{
public:
    Sale() {
        cout << "Create Sale Object" << endl;
    }
    Sale(string n,int s) : Employee(n,s) {
        
    }
};
int main(){
    IT emp1;
    emp1.setName("Kong");
    emp1.setSalary(15000);

    cout << emp1.getName() << endl;
    cout << emp1.getSalary() << endl;

    Sale emp2;
    emp2.setName("jane");
    emp2.setSalary(50000);
    cout << emp2.getName() << endl;
    cout << emp2.getSalary() << endl;
    
}