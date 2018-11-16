#include <iostream>
using namespace std;

int knapsack(int *weight, int *values, int n, int maxWeight) {
	// Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	if(weight[0] > maxWeight) {
		return knapsack(weight + 1, values + 1, n - 1, maxWeight);
	}

	// Recursive calls
	int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
	int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);

	return max(x, y);
}



// --------------------

public class Solution { /* Your class should be named Solution. * Don't write main() function. * Don't read input, it is passed as function argument. * Return output and don't print it. * Taking input and printing output is handled automatically. */ public static int knapsack(int[] weight,int value[],int maxWeight){ int storagePrev[] = new int[maxWeight + 1]; int storageCurrent[] = new int[maxWeight + 1]; for(int i = 1; i < value.length+1; i++){ for(int w = 1; w < maxWeight+1; w++){ if(weight[i-1] > w){ storageCurrent[w] = storagePrev[w]; } else{ storageCurrent[w] = Math.max(storagePrev[w - weight[i - 1]] + value[i - 1], storagePrev[w]); } } storagePrev = storageCurrent; storageCurrent = new int[maxWeight + 1]; } return storagePrev[maxWeight]; } }
