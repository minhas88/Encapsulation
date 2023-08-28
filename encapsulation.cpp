#include<iostream>
#include<strings.h>
#include<cctype>

class operation
{
private:
    int a, b;
    char symbol;
    int(*functptr)(int, int);
public:
    operation();
    ~operation();
    void parseData(std::string *input);
    void result();
    int get_a();
    void set_a(int val);
    int get_b();
    void set_b(int val);
    int get_symbol();
    void set_symbol(char val);
    int (*get_funcptr())(int, int);
    void set_funcptr(int(*ptr)(int, int));
};

operation::operation(){
    a = 0;
    b = 0;
    symbol = '\0';
    functptr = nullptr;
}

operation::~operation(){}

void operation::parseData(std::string *input){
    std::string num1, num2;
    for (char ch : *input)
    {
        if(isdigit(ch)){
            if(symbol == '\0') num1 += ch;
            else num2 += ch;
        }
        else set_symbol(ch);
    }
    set_a(stoi(num1));
    set_b(stoi(num2));
}

void operation::result(){
    std::cout<<"Result of Operation is : " << functptr(a,b) << std::endl;
}

void operation::set_a(int val){
    a = val;
}

int operation::get_a(){
    return a;
}

void operation::set_b(int val){
    b = val;
}

int operation::get_b(){
    return b;
}

void operation::set_symbol(char val){
    symbol = val;
}

int operation::get_symbol(){
    return symbol;
}

void operation::set_funcptr(int(*ptr)(int, int)){
    functptr = ptr;
}

int (*operation::get_funcptr())(int, int) {
    return functptr;
}

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divide(int a, int b){
    if(b != 0){
        return a/b;
    }else{
        std::cerr << "Error: Division by zero!" << std::endl;
        return 1;
    }
}


int main(){
    std::string cmd_in;
    operation ops;

    std::cout << "Enter the Operation Statement: ";
    std::cin >> cmd_in;

    ops.parseData(&cmd_in);
    switch (ops.get_symbol())
    {
        case '+':
            ops.set_funcptr(add);
            break;

        case '-':
            ops.set_funcptr(subtract);
            break;

        case '*':
            ops.set_funcptr(multiply);
            break;

        case '/':
            ops.set_funcptr(divide);
            break;

        default:
            std::cerr << "Error: Unsupported operation!" << std::endl;
            break;
    }
    ops.result();

    std::cout << "Press any key to exit...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}