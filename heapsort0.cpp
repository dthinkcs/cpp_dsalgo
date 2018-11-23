#include <iostream>
using namespace std;

// MIN_PRIORITY
class PriorityQueue
{
	vector<int> pq;

public:
	PriorityQueue()
	{

	}

	int remove(int item)
	{

		if (pq.size() == 0)
			return -999;
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();
		int parentIndex = 0;
		while (true)
		{
			int child1Index = 2 * parentIndex + 1;
			int child2Index = 2 * parentIndex + 2;
			if (child1Index >= pq.size()) // leaf node
				break;

			// now CHILD1 exists check if child2 also exixts
			if (child2Index < pq.size())
			{
				// CHILD2 exists 
				if (pq[parentIndex] < pq[child1Index] && pq[parentIndex] < pq[child2Index])
					break; // parent is smaller than both the children
				else if (pq[child1Index] < pq[child2Index])
				{
					// swap parent with CHILD1
					int temp = pq[child1Index];
					pq[child1Index] = pq[parentIndex];
					pq[parentIndex] = temp;

					// UPDATE parent
					parentIndex = child1Index;
				}
				else
				{
					// swap parent with CHILD2
					int temp = pq[child2Index];
					pq[child2Index] = pq[parentIndex];
					pq[parentIndex] = temp;

					parentIndex = child2Index;

				}
				
			}
			else 
			{
				// only child1 exists
				if (pq[parentIndex] < pq[child1Index])
					break; // parent is smaller than both the children
				else
				{
					// swap parent with CHILD1
					int temp = pq[child1Index];
					pq[child1Index] = pq[parentIndex];
					pq[parentIndex] = temp;

					parentIndex = child1Index;

				}

			}

		}

		return ans;
	}


	void insert(int item)
	{
		pq.push_back(item);

		// up heapify
		int childIndex = pq.size() - 1;
		while (childIndex > 0) // childIndex == 0 means one element
		{
			int parentIndex = (childIndex - 1) / 2; 


			if (pq[childIndex] < pq[parentIndex])
			{
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];	
				pq[parentIndex] =  temp;
			}
			else
				break;

			childIndex = parentIndex;
		}
	}
};





int main(void)
{
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	cout << arr << endl;

	PriorityQueue pq;
	for (int i = 0; i < 10; i++)
		pq.insert(arr[i]);

	for (int i = 0; i < 10; i++)
		arr[i] = pq.remove();

	cout << "SORTED: " << arr << endl;	
}

