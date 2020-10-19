#include <bits/stdc++.h>
using namespace std;
template<class T1, class T2=T1>
class pQueue
{
private:
	// pair of element, priority
	vector<pair<T1, T2>> arr;
	int parent(int i)
	{
		i++;
		return (i+1)/2 - 1;
	}
	int left_child(int i)
	{
		i++;
		return 2*i - 1;
	}
	int right_child(int i)
	{
		i++;
		return 2*i+1 - 1;
	}
	void shift_up(int i)
	{
		// recursive approach
		if(i==0)
			return;
		if(arr[parent(i)].second < arr[i].second)
			swap(arr[i], arr[parent(i)]);
		shift_up(parent(i));
		// iterative approach
		// while(i > 0 && arr[parent(i)] < arr[i])
		// {
		// 	swap(arr[i], arr[parent(i)]);
		// 	i = parent(i);
		// }
	}
	void shift_down(int i)
	{
		int max_index = i;
		int left_child = this->left_child(i), right_child = this->right_child(i);
		if(left_child < arr.size() and arr[left_child].second > arr[max_index].second)
			max_index = left_child;
		if(right_child < arr.size() and arr[right_child].second > arr[max_index].second)
			max_index = right_child;	
		if(i!=max_index)
			{
				swap(arr[i], arr[max_index]);
				shift_down(max_index);
			}	
	}
public:
	int min_or_max = 1;
	void insert(pair<T1, T2> element)
	{
		arr.push_back(element);
		this->shift_up(arr.size()-1);
	}
	pair<T1, T2> extract_max()
	{
		pair<T1, T2> result = arr[0];
		arr[0] = arr.back();
		arr.pop_back();
		shift_down(0);
		return result;
	}
	void remove(int i)
	{
		arr[i] = INT_MAX;
		shift_up(i);
		this->extract_max();
	}
	void change_priority(int i, T2 p)
	{
		int oldp = arr[i].second;
		arr[i].second = p;
		if(p<oldp)
			shift_down(i);
		else
			shift_up(i);
	}
	pair<T1, T2> get_max()
	{
		return arr[0];
	}
	int empty()
	{
		return arr.size()==0;
	}
};
int main()
{
	pQueue<int> pq;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		pq.insert({x, x});
	}
	while(!pq.empty())
	{
		cout << pq.extract_max().first << " ";
	}
}