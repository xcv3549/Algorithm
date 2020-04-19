#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void post_order(int root, int end);

int main()
{
	int num,size = 0;
	
	while(scanf("%d" , &num) != -1)
		arr.push_back(num);
	
	post_order(0,arr.size()-1);
}

void post_order(int root, int end)
{
	int idx;
	int root_key = arr[root];
	
	if(root <= end)
	{
		for(idx = root+1; idx<=end; idx++)
			if(arr[idx] > root_key)
				break;

		post_order(root+1 , idx-1);
		post_order(idx , end);	
		
		printf("%d\n",root_key);
	}
}