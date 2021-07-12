#include <iostream>
#include <iomanip>
using namespace std;

void fill_layer1(int x, int y, int** layer1, int x_size, int y_size) {
	int new_y_value, new_x_value;

	new_y_value = layer1[y][x] + 10;
	new_x_value = layer1[y][x] + 1;

	

	//left top edge
	if (x == 0 && y == 0) {
		cout << "check 1 \n";
		//check the right cell
		if (layer1[y][x + 1] == 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size);
		}
		//check the below cell
		if (layer1[y + 1][x] == 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size);
		}
		
	}
	//right bottom edge
	else if (x == x_size - 1 && y == y_size - 1) {
		cout << "check 2 \n";
		//check the left cell
		if (layer1[y][x - 1] == 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size);
		}
		//check the above cell
		if (layer1[y - 1][x] == 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size);
		}
	}
	//right top edge
	else if (x == x_size - 1 && y == 0) {
		cout << "check 3 \n";
		//check the left cell
		if (layer1[y][x - 1] == 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size);
		}
		//check the below cell
		if (layer1[y + 1][x] == 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size);
		}
	}
	//left bottom edge
	else if (x == 0 && y == y_size - 1) {
		cout << "check 4 \n";
		//check the right cell
		if (layer1[y][x + 1] == 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size);
		}
		//check the top cell
		if (layer1[y - 1][x] == 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size);
		}
	}
	//left of the grid
	else if (x == 0) {
		cout << "check 5 \n";
		//check the right cell
		if (layer1[y][x + 1] == 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size);
		}
		//check the top cell
		if (layer1[y - 1][x] == 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size);
		}

	}
	//right of the grid
	else if (x == x_size - 1) {
		cout << "check 6 \n";
		//check the left cell
		if (layer1[y][x - 1] == 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size);
		}
		//check the top cell
		if (layer1[y - 1][x] == 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size);
		}
	}
	//top of the grid
	else if (y == 0) {
		cout << "check 7 \n";
		//check the left cell
		if (layer1[y][x - 1] == 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size);
		}
		//check the right cell
		if (layer1[y][x + 1] == 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size);
		}
	}
	//bottom of the grid
	else if (y == y_size - 1) {
	cout << "check 8 \n";
		//check the left cell
		if (layer1[y][x - 1] == 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size);
		}
		//check the right cell
		if (layer1[y][x + 1] == 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size);
		}
		//check the top cell
		if (layer1[y - 1][x] == 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size);
		}
	}
	//middle of the grid
	else {
	cout << "check 9 \n";
		//check the left cell
		if (layer1[y][x - 1] == 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size);
		}
		//check the right cell
		if (layer1[y][x + 1] == 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size);
		}
		//check the top cell
		if (layer1[y - 1][x] == 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size);
		}
	}
}


int main() {

	int x_source = 0, y_source = 0, x_size = 20, y_size = 20;
	int**layer1 = new int*[20];

	for (int i = 0; i < 20; i++)
		layer1[i] = new int[20];

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++) {
			layer1[i][j] = 1;
		}

	//source
	layer1[y_source][x_source] = 0;
	
	//obstacles
	layer1[2][6] = -1;
	layer1[5][6] = -1;
	layer1[3][11] = -1;
	layer1[2][19] = -1;
	layer1[10][10] = -1;

	//fill layer1
	fill_layer1(x_source, y_source, layer1, x_size, y_size);
	if(x_source == 0)
	layer1[y_source][x_source + 1] = 1;
	else if (x_source == x_size-1)
	layer1[y_source][x_source - 1] = 1;
	else {
		layer1[y_source][x_source + 1] = 1;
		layer1[y_source][x_source - 1] = 1;
	}
	


	layer1[y_source][x_source + 1] = 1;
	layer1[y_source][x_source - 1] = 1;
	cout << "check 10 \n";

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout <<setw(4) <<layer1[i][j];
		}
		cout << endl;
	}





	system("pause");
	return 0;
}

