using namespace std;
#include <iostream>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void allsubset(int X[], int current, int end, bool S[]){
	//cout << "P-" << start << "-" << end << endl;  
	if (current == end) {
		for (int i=0; i<end; i++){
			if (S[i]) {
				cout << X[i] << "\t";
			} else {
				cout << ".\t";
			}
		}
		cout << endl;
		return;
	}
	
	S[current] = true;
	allsubset(X, current+1, end, S);
	S[current] = false;
	allsubset(X, current+1, end, S);
}

void subsetSum(int X[], int current, int end, 
               bool S[], int total){
	//cout << "P-" << start << "-" << end << endl;  
	if (current == end) {
		int sum = 0;
		for (int i=0; i<end; i++){
			if (S[i]) {
				sum += X[i];
			} 
		}
		
		if (sum == total) cout << "Yes!"<< endl;
		return;
	}
	
	S[current] = true;
	subsetSum(X, current+1, end, S, total);
	S[current] = false;
	subsetSum(X, current+1, end, S, total);
}

int main ()
{
	int n=3;
	int total = 5;
	int X[] = {1, 2, 3};
	bool S[] = {0, 0, 0};
	subsetSum(X, 0, n, S, total);
	return 0;	
}
  
