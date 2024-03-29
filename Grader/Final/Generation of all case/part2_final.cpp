#include <iostream>
using namespace std;
int ar[1000] = {0};

void calculator(int current, int target, int steps){
    if(current >= target){
        if(current == target){
            cout<<steps;
        }
    }
    calculator(current*2, target, steps+1);
    calculator(current+1, target, steps+1);
}

int main()
{
    
}