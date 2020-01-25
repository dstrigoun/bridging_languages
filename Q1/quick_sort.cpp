#include <iostream>
#include <fstream>
using namespace std;
int qsorthelper(int *arr, int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for (int j = low; j <= high-1; j++){
		if (arr[j] <= pivot){
			i++;
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	int tmp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = tmp;
	return i+1;	
}
void qsort(int *arr, int low, int high){
	if(low < high){
		int partition = qsorthelper(arr, low, high);
		qsort(arr, partition+1, high);
		qsort(arr, low, partition-1);
	}
	return;
}
int main(int argc, char* argv[]){
	if (argc < 2){
		return 0;
	}
	cout << argv[1] << endl;
	string STRING;
	// ifstream in(argv[1]);
	// string line;
 //    while ( getline(in, line)){
 //    	cout << line << endl;
 //    }
	fstream in(argv[1]);
	int* array;
	int length;
	bool found = false;
	int value;
	int i = 0;
	while (in >> value) {
		// cout << value << endl;
		if (!found) {
			length = value;
			array = new int[length];
			found = true;
		} else {
			array[i] = value;
			i++;
			//cout << array[i] << endl;
		}
	}
    qsort(array, 0, length-1);  
    cout << "Sorted array: \n";  
    for (int i = 0; i < length-1; ++i)
    {
    	cout << array[i] << " ";
    }
}