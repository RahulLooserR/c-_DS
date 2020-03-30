/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : main.cpp
 * Created on    : Saturday 28 March 2020 03:31:57 PM IST
 * Last modified : Saturday 28 March 2020 05:00:02 PM IST
 * Description   : using heap to find max or min. 
 * ***********************************************************************/

#include <iostream>

using namespace std;

class Heap{
	public:
		int n; // number of elements
		int* arr;
		Heap(int n):n{n}
		{
			arr = new int[n];
		}

		void initialise()
		{
			for(int i = 0; i < n; i++)
				arr[i] = rand() % 97 + 1;
		}

		void display()
		{
			for(int i = 0; i < n; i++)
				cout << arr[i] << " ";
			cout << endl;
		}

		void swap(int a, int b)
		{
			//			cout << "swap" << endl;
			int temp;
			temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}

		void max_heapify(int i)
		{
			//			cout << "heapify" << endl;
			int left = 2 * i + 1;
			int right  = 2 * i + 2;

			//			if(right < n){
			//				cout << "left: " << arr[left] << " right: " << arr[right] 
			//					<< " i: " << arr[i] << endl;
			if(arr[i] < arr[left] || arr[i] < arr[right]){
				if(arr[left] > arr[right]){
					swap(left, i);
				}
				else{
					swap(right, i);
				}
			}
			//		}
		}

		void buildHeap()
		{
			//			cout << "building heap" << endl;
			for(int i = n/2 - 1; i >= 0; i--){
				max_heapify(i);
			}
		}

		int extractMax()
		{
			int result = arr[0];
			arr[0] = arr[n-1];
			n = n - 1;
			buildHeap();
			return result;
		}
};

int main()
{
	Heap h(9);
	h.initialise();
	h.display();
	h.buildHeap();
	h.display();
	for(int i = 0; i < 9; i++){
		cout << "max: " << h.extractMax() << endl;
		h.display();
	}
	return 0;
}
