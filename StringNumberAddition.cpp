#include <iostream>
#include <stack>
using namespace std;
int main()
{
	string op1, op2, dstring, lstring;
	cin >> op1 >> op2;
	int a, b, carry = 0, sum;
	stack<int> res;
	if (op1.length() >= op2.length()) {
		dstring = op1;
		lstring = op2;
	}
	else {
		dstring = op2;
		lstring = op1;
	}
	int* result = new int[dstring.length()];
	memset(result, 0, dstring.length());
		for (int i = dstring.length() - 1, c = 1; i >= 0; --i, ++c) {
			//cout << op1[i] << " ";
			a = dstring[i] - '0';
			b = 0;
			if (c <= lstring.length()) {
				b = lstring[i - dstring.length() + lstring.length()] - '0';
				//cout << op2[i - op1.length() + op2.length()] << endl;
			}
			if (carry > 0) {
				sum = a + b + carry;
			}
			else {
				sum = a + b;
			}
			if (sum < 10) {
				res.push(sum);
				*(result+i) = sum;
				//cout << sum << endl;
				carry = 0;
			}
			else if(sum >= 10) {
				res.push(sum - 10);
				*(result + i) = sum-10;

				carry = 1;
			}
			else if (i == 0) {
				res.push(sum);
				*(result + i) = sum;
			}
		}
	cout << "Using stack : ";
	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}
	cout << endl << "Without stack: ";
	int i = 0;
	while (i < dstring.length()) {
		cout << *(result + i);
		i++;
	}
}
