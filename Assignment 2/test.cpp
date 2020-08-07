#include <iostream>

using namespace std;

void test(double marks[7]);


int main()
{
    cout << "Hello world!" << endl;

    double marks[7];

    test(marks);

    for (int i=0;i<7;i++){
        cout << marks[i] << endl;
    }
    cout << "done" << endl;

    return 0;
}

void test(double marks[7]){
    for (int i=0;i<7;i++){
        marks[i] = i*12;
    }
}
