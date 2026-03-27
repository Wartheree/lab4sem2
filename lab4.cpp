//
// Created by danil on 27.03.2026.
//
#include <iostream>
#include <vector>

class School {
private:
    std::string name;
protected:
    int number_of_students;
public:
    School(std::string name, int number_of_students) {
        this->name = name;
        this->number_of_students = number_of_students;
    }
    virtual void print_dynamic() {
        std::cout << "Name: " << this->name << ", Number of students: " << this->number_of_students;
    }
    void print_static() {
        std::cout << "Name: " << this->name << ", Number of students: " << this->number_of_students;
    }
};
class Special_School : public School {
public:
    std::string specialisation;
public:
    Special_School(std::string name, int number_of_students, std::string specialisation):
        School(name, number_of_students){
        this->specialisation = specialisation;
    }
    void print_dynamic() override {
        School::print_dynamic();
        std::cout << ", Spesialisation: "<< specialisation << std::endl;
    }
    void print_static() {
        School::print_static();
        std::cout << ", Spesialisation: "<< specialisation << std::endl;
    }
};

int main() {
    School regular_school("Regular school", 10);
    Special_School math_school("Math school", 10, "math");
    School* ptr;
    ptr = &regular_school;
    std::cout<<"Regular school static print ---> ";
    ptr->print_static();
    std::cout<<std::endl;
    std::cout<<"Regular school dynamic print ---> ";
    ptr->print_dynamic();
    std::cout<<std::endl;

    ptr=&math_school;
    std::cout<<"Math school static print ---> ";
    ptr->print_static();
    std::cout<<std::endl;
    std::cout<<"Math school dynamic print ---> ";
    ptr->print_dynamic();
    std::cout<<std::endl;
    return 0;
}