// C++ program demonstrating manual memory management
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class MemoryDemo {
private:
    vector<int>* data;
    static int instanceCount;
    const int id;

public:
    MemoryDemo() : data(new vector<int>()), id(++instanceCount) {
        cout << "Created MemoryDemo instance " << id << endl;
    }

    ~MemoryDemo() {
        delete data;
        cout << "Destroyed MemoryDemo instance " << id << endl;
    }

    void addData(int value) {
        data->push_back(value);
    }

    void printData() {
        cout << "Data in instance " << id << ": ";
        for (int value : *data) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int MemoryDemo::instanceCount = 0;

int main() {
    // Demonstrate manual memory management with raw pointers
    cout << "Demonstrating manual memory management:" << endl;
    MemoryDemo* demo1 = new MemoryDemo();
    demo1->addData(1);
    demo1->addData(2);
    demo1->printData();
    delete demo1;  // Manual cleanup

    // Demonstrate potential memory leak (commented out to prevent actual leak)
    /*
    cout << "\nDemonstrating potential memory leak:" << endl;
    MemoryDemo* demo3 = new MemoryDemo();
    demo3->addData(5);
    demo3->addData(6);
    demo3->printData();
    // Forgot to delete demo3 - this would cause a memory leak
    */

    // No need to delete - smart pointers handle cleanup

    return 0;
} 