# mergesort

#include <iostream>
#include <sstream>

using namespace std;

bool read_numbers(int & n, int * array)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) {
		if (!(stream >> array[i])) {
			success = false;
			break;
		}
	}
	return success;
}


void mergesort(int * array, int left, int right) {

	int middle = (right + left) / 2;

	if (right == left) {
		return;
	}
	if (right - left == 1) {
		if (array[right] < array[left])
			swap(array[right], array[left]);
		return;
	}
	
	mergesort(array, left, middle);
	mergesort(array, middle + 1, right);

	int * tmp = new int [right - left + 1] ;
	int left_t = left, right_t = middle + 1, cur = 0;

	while (right - left + 1 != cur) {
		if (left_t > middle){
			tmp[cur++] = array[right_t++];
		}
		else if (right_t > right) {
			tmp[cur++] = array[left_t++];
		}
		else if (array[left_t] > array[right_t]) {
			tmp[cur++] = array[right_t++];
		}
		else tmp[cur++] = array[left_t++];

	}
	for (int i = 0; i < cur; i++)
		array[i + left] = tmp[i];
	
	delete[] tmp;
}

int main() {
	int n;
	string str;
	getline(cin, str);
	istringstream stream(str);
	if (stream >> n && n > 0) {
		int * array = new int[n];
		if (read_numbers(n, array)) {

			mergesort(array, 0, n - 1);

			for (int i = 0; i < n; i++) {
				cout << array[i] << " ";
			}
			delete[] array;

		}
		else {
			cout << "An error has occured while reading input data.";
			delete[] array;
		}
	}
	else {
		cout << "An error has occured while reading input data.";
	}

	cin.get();
	cin.get();
	return 0;
}
