#include <queue> void reverseQueue(queue<int> &q) 
{ 
	if(q.size() <= 1) 
		 return; 
	
	int front = q.front(); q.pop(); 
	reverseQueue(q); 
	q.push(front); 
}
