# include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

string x_size;
string y_size;
deque<string> vec1,vec_2, vec_3;

struct paramters
{
	int layer;
	int x_value;
	int y_value;

};
paramters p;
vector <paramters> obstacles;
vector <int> num;
vector <int> num_2;
vector<vector<int>> nets;
int main()
{   
	fstream file;
	file.open("input.txt", ios::in);
	string line;
	while (file.good())
	{
		
		getline(file, line);
		vec1.push_back(line);

			//cout << line << endl

	}
	file.close();
	string s;
	for (int i = 0; i < vec1.size(); i++)
	{
		s.clear();
		cout << "Hello World"<<endl;
		//temp.clear();
		for (int j = 0; j < vec1[i].size(); j++)
		{
			
			if (vec1[i][j] == 'x')
			{
				x_size = s;
				s.clear();
			}
			
			else if (vec1[i][j] == 'S')
			{
				s.clear();
				j = j + 3;
				while (vec1[i][j] != ')')
				{

					if (vec1[i][j] != ',')
					{
						s = s + vec1[i][j];
						j = j + 1;
					}
					else
					{
						num.push_back(stoi(s.c_str()));
						s.clear();
						j = j + 1;
					}
				}

				num.push_back(stoi(s.c_str()));
				s.clear();
				
			


				
			}
			
			else if (vec1[i][j] == 't')
			{
				s.clear();
				j = j + 4;
				while (j < vec1[i].size())
				{
					while (vec1[i][j] != ')')
					{

						if (vec1[i][j] != ',')
						{
							s = s + vec1[i][j];
							j = j + 1;
						}
						else
						{
							num_2.push_back(stoi(s.c_str()));
							s.clear();
							j = j + 1;
						}
					}

					num_2.push_back(stoi(s.c_str()));
					s.clear();
					j = j + 3;


				}
				j = j - 3;
				
			}

			else
			{
				s=s+ vec1[i][j];
			}
			
			
		}
		nets.push_back(num_2);
		num_2.clear();
	}
	vector<vector<paramters>> nets2;
	paramters p1;
	vector<paramters> num_3;
	for (int i = 0; i < nets.size(); i++) {
		for (int j = 0; j < nets[i].size(); j = j + 3){
			p.layer = nets[i][j];
			p.x_value = nets[i][j+1];
			p.y_value = nets[i][j+2];
			num_3.push_back(p);
		
		}
		nets2.push_back(num_3);
		num_3.clear();
	}
	for (int i = 0; i < num.size(); i = i + 3)
	{
		p1.layer = num[i];
		p1.x_value = num[i + 1];
		p1.y_value = num[i + 2];
		obstacles.push_back(p1);
	}

	for (int i = 0; i < nets2.size(); i++) {
		for (int j = 0; j < nets2[i].size(); j++)
			cout << nets2[i][j].layer << "   " << nets2[i][j].x_value << "   " << nets2[i][j].y_value << "   ";
		cout << endl;
	}

	cout << "################################################### \n";
	
	for (int i = 0; i < obstacles.size(); i++)
	{
		cout << obstacles[i].layer << "      " << obstacles[i].x_value << "    " << obstacles[i].y_value << "  ";
		cout << endl;

	}
	

	system("pause");
}