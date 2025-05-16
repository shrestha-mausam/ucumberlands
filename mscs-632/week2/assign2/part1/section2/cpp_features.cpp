#include <iostream>
#include <string>
#include <functional>

using namespace std;

// Demonstrating type system with function overloading
int processData(int data) {
    return data * 2;
}

double processData(double data) {
    return data * 2.5;
}

string processData(string data) {
    string result = data;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}

// Demonstrating scopes and closures using function objects
class Counter {
private:
    int count;  // Private member variable in class scope
    static int totalCount;  // Static variable in global scope
    
public:
    Counter() : count(0) {
        totalCount++;  // Accessing static member
    }
    
    int operator()() {  // Function object (similar to closure)
        count++;  // Accessing instance variable
        return count;
    }
    
    static int getTotalCount() {  // Static method accessing static variable
        return totalCount;
    }
};

// Initialize static member
int Counter::totalCount = 0;

// Demonstrating scope resolution
namespace Math {
    int value = 42;  // Variable in namespace scope
    
    int add(int a, int b) {
        return a + b;
    }
}

int main() {
    // Type system demonstration
    cout << "Type system demonstration:\n";
    int num = 42;
    double dbl = 3.14;
    string str = "hello";
    
    cout << "Integer: " << processData(num) << "\n";
    cout << "Double: " << processData(dbl) << "\n";
    cout << "String: " << processData(str) << "\n\n";
    
    // Scope and closure demonstration
    cout << "Scope and closure demonstration:\n";
    Counter counter1;
    Counter counter2;
    
    cout << "Counter1 values: ";
    for (int i = 0; i < 3; ++i) {
        cout << counter1() << " ";
    }
    cout << "\n";
    
    cout << "Counter2 values: ";
    for (int i = 0; i < 2; ++i) {
        cout << counter2() << " ";
    }
    cout << "\n";
    
    cout << "Total counters created: " << Counter::getTotalCount() << "\n\n";
    
    // Namespace scope demonstration
    cout << "Namespace scope demonstration:\n";
    cout << "Math::value = " << Math::value << "\n";
    cout << "Math::add(5, 3) = " << Math::add(5, 3) << "\n";
    
    return 0;
} 