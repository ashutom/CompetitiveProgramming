//https://www.hackerrank.com/challenges/richie-rich/copy-from/68773073

#include <vector>
#include<string>
#include<iostream>

using namespace std;

vector<string> split_string(string);


/*
* Complete the highestValuePalindrome function below.
*/
int places[100000 + 5];
string highestValuePalindrome(string s, int n, int k) {
	string temp = s; int c_p = 0;
	int low = 0; int high = n - 1; int tal = k;
	while (low<high) {
		if (temp[low] != temp[high]) {
			if (tal) {
				if (temp[low]>temp[high]) {
					temp[high] = temp[low];
				}
				else {
					temp[low] = temp[high];
				}
				places[c_p++]=low;
				tal--;
			}
			else {
				break;
			}
		}
		low++; high--;
	}
	//cout<<"\n Currently Palindrome Str ="<<temp<<" Places = "<<places<<endl;
	if (low<high) {
		return string("-1");
	}
	high = c_p - 1; int i = 0;
	while (tal && (i<high)) {
		if (temp[places[i]] == '9') {
			i++;
		}
		else {
			temp[places[i]] = temp[n -i - 1] = '9';
			tal--; i++;
		}
	}
	low = 0; high = n - 1;
	while (low<high && tal>1) {
		if (temp[low] != '9') {
			temp[low] = temp[high] = '9';
			tal -= 2;
		}
		low++; high--;
	}
	if (n & 1) {
		if (tal) {
			low = (n - 1) / 2;
			temp[low] = '9';
		}
	}
	return temp;
}


int main()
{
	int n, k;
	string s;
	cin >> n >> k >> s;
	string result = highestValuePalindrome(s, n, k);

	cout << result <<endl;

	//fout.close();

	return 0;
}
/*
vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
*/