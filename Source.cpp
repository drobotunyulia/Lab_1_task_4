#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;


string base_to_ten(string str, string &finished_number_str);

int main(int argc, char* argv[])
{
	cout << "Laba 1 Task 4\nDrobotun Yulia M8o-210B-20\n" << endl << endl;
	vector<string> value_array;
	string value_string;
	char in_byte;
	ifstream file_in(argv[1], ios::binary);
	while (!file_in.eof())
	{
		file_in.get(in_byte);
		if (isalpha(in_byte) || isdigit(in_byte))
		    value_array.push_back(value_string);
		while (isalpha(in_byte) || isdigit(in_byte))
		{
			value_array[value_array.size() - 1].push_back(in_byte);
			file_in.get(in_byte);
			
		}
	}
	file_in.close();
	string value_str;
	string base_str;
	ofstream file_out;
	file_out.open(argv[2]);
	for (size_t i = 0; i < value_array.size(); i++)
	{
		base_str = base_to_ten(value_array[i], value_str);
		file_out << value_array[i] << " " << value_str << " " << base_str << endl;
	}
	cout << "Success!" << endl;
	return 0;
}


string base_to_ten(string str, string &finished_number_str)
{
	char max_dig = str[0];
	int finished_number = 0;
	string base_str;
	int	max_index = 0, base;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] > max_dig)
		{
			max_dig = str[i];
			max_index = i;
		}
	}
	if (max_dig - '0' <= 9)
	{
		base = max_dig - '0' + 1;
	}
	else
	{
		base = max_dig + 10 - 'A' + 1;
	}
	for(int i = 0; i < str.length(); i++)
	{
		finished_number = finished_number * base + (isdigit(str[i]) ? str[i] - '0' : str[i] - 'A' + 10);
	}
	finished_number_str = to_string(finished_number);
	base_str = to_string(base);
	return base_str;
}
