#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

void fill_layer1(int x, int y, int** layer1, int x_size, int y_size, int smallest_value) {
	int new_y_value, new_x_value;

	new_y_value = layer1[y][x] + 10;
	new_x_value = layer1[y][x] + 1;

	

	//left top edge
	if (x == 0 && y == 0) {
		//check the right cell
		if (layer1[y][x + 1] == smallest_value + 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the below cell
		if (layer1[y + 1][x] == smallest_value + 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size, smallest_value );
		}
		
	}
	//right bottom edge
	else if (x == x_size - 1 && y == y_size - 1) {
		//check the left cell
		if (layer1[y][x - 1] == smallest_value + 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the above cell
		if (layer1[y - 1][x] == smallest_value + 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size, smallest_value);
		}
	}
	//right top edge
	else if (x == x_size - 1 && y == 0) {
		//check the left cell
		if (layer1[y][x - 1] == smallest_value + 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the below cell
		if (layer1[y + 1][x] == smallest_value + 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size, smallest_value);
		}
	}
	//left bottom edge
	else if (x == 0 && y == y_size - 1) {
		//check the right cell
		if (layer1[y][x + 1] == smallest_value + 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer1[y - 1][x] == smallest_value + 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size, smallest_value);
		}
	}
	//left of the grid
	else if (x == 0) {
		//check the right cell
		if (layer1[y][x + 1] == smallest_value + 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer1[y - 1][x] == smallest_value + 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == smallest_value + 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size, smallest_value);
		}

	}
	//right of the grid
	else if (x == x_size - 1) {
		//check the left cell
		if (layer1[y][x - 1] == smallest_value + 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer1[y - 1][x] == smallest_value + 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == smallest_value + 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size, smallest_value);
		}
	}
	//top of the grid
	else if (y == 0) {
		//check the left cell
		if (layer1[y][x - 1] == smallest_value + 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the right cell
		if (layer1[y][x + 1] == smallest_value + 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == smallest_value + 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size, smallest_value);
		}
	}
	//bottom of the grid
	else if (y == y_size - 1) {
		//check the left cell
		if (layer1[y][x - 1] == smallest_value + 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the right cell
		if (layer1[y][x + 1] == smallest_value + 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer1[y - 1][x] == smallest_value + 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size, smallest_value);
		}
	}
	//middle of the grid
	else {
		//check the left cell
		if (layer1[y][x - 1] == smallest_value + 1 || new_x_value < layer1[y][x - 1]) {
			layer1[y][x - 1] = new_x_value;
			fill_layer1(x - 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the right cell
		if (layer1[y][x + 1] == smallest_value + 1 || new_x_value < layer1[y][x + 1]) {
			layer1[y][x + 1] = new_x_value;
			fill_layer1(x + 1, y, layer1, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer1[y - 1][x] == smallest_value + 1 || new_y_value < layer1[y - 1][x]) {
			layer1[y - 1][x] = new_y_value;
			fill_layer1(x, y - 1, layer1, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer1[y + 1][x] == smallest_value + 1 || new_y_value < layer1[y + 1][x]) {
			layer1[y + 1][x] = new_y_value;
			fill_layer1(x, y + 1, layer1, x_size, y_size, smallest_value);
		}
	}
}


void fill_layer2(int x, int y, int** layer1, int** layer2, int x_size, int y_size, int smallest_value) {
	int new_y_value, new_x_value, via_cost;

	new_y_value = layer2[y][x] + 1;
	new_x_value = layer2[y][x] + 10;
	via_cost = 10;


	//left top edge
	if (x == 0 && y == 0) {
		//check the right cell
		if (layer2[y][x + 1] == smallest_value + 1 || new_x_value < layer2[y][x + 1] || ((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1)) {
			layer2[y][x + 1] = new_x_value;
			if (((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1))
				layer2[y][x + 1] = layer1[y][x + 1] + via_cost;
			fill_layer2(x + 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the below cell
		if (layer2[y + 1][x] == smallest_value + 1 || new_y_value < layer2[y + 1][x] || ((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y+1][x] != -1)) {
			layer2[y + 1][x] = new_y_value;

		if (((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1))
			layer2[y + 1][x] = layer1[y + 1][x] + via_cost;

			fill_layer2(x, y + 1, layer1, layer2, x_size, y_size, smallest_value);
		}

	}
	//right bottom edge
	else if (x == x_size - 1 && y == y_size - 1) {
		//check the left cell
		if (layer2[y][x - 1] == smallest_value + 1 || new_x_value < layer2[y][x - 1] || ((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1)) {
			layer2[y][x - 1] = new_x_value;

			if (((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1))
				layer2[y][x - 1] = layer1[y][x - 1] + via_cost;

			fill_layer2(x - 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the above cell
		if (layer2[y - 1][x] == smallest_value + 1 || new_y_value < layer2[y - 1][x] || ((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y-1][x] != -1)) {
			layer2[y - 1][x] = new_y_value;
			
			if (((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1))
				layer2[y - 1][x] = layer1[y - 1][x] + via_cost;

			fill_layer2(x, y - 1, layer1, layer2, x_size, y_size, smallest_value);
		}
	}
	//right top edge
	else if (x == x_size - 1 && y == 0) {
		//check the left cell
		if (layer2[y][x - 1] == smallest_value + 1 || new_x_value < layer2[y][x - 1] || ((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1)) {
			layer2[y][x - 1] = new_x_value;
			if (((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1))
				layer2[y][x - 1] = layer1[y][x - 1] + via_cost;
			fill_layer2(x - 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the below cell
		if (layer2[y + 1][x] == smallest_value + 1 || new_y_value < layer2[y + 1][x] || ((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1)) {
			layer2[y + 1][x] = new_y_value;

			if (((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1))
				layer2[y + 1][x] = layer1[y + 1][x] + via_cost;

			fill_layer2(x, y + 1, layer1, layer2, x_size, y_size, smallest_value);
		}
	}
	//left bottom edge
	else if (x == 0 && y == y_size - 1) {
		//check the right cell
		if (layer2[y][x + 1] == smallest_value + 1 || new_x_value < layer2[y][x + 1] || ((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1)) {
			layer2[y][x + 1] = new_x_value;
			if (((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1))
				layer2[y][x + 1] = layer1[y][x + 1] + via_cost;
			fill_layer2(x + 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer2[y - 1][x] == smallest_value + 1 || new_y_value < layer2[y - 1][x] || ((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1)) {
			layer2[y - 1][x] = new_y_value;

			if (((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1))
				layer2[y - 1][x] = layer1[y - 1][x] + via_cost;

			fill_layer2(x, y - 1, layer1, layer2, x_size, y_size, smallest_value);
		}
	}
	//left of the grid
	else if (x == 0) {
		//check the right cell
		if (layer2[y][x + 1] == smallest_value + 1 || new_x_value < layer2[y][x + 1] || ((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1)) {
			layer2[y][x + 1] = new_x_value;
			if (((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1))
				layer2[y][x + 1] = layer1[y][x + 1] + via_cost;
			fill_layer2(x + 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer2[y - 1][x] == smallest_value + 1 || new_y_value < layer2[y - 1][x] || ((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1)) {
			layer2[y - 1][x] = new_y_value;

			if (((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1))
				layer2[y - 1][x] = layer1[y - 1][x] + via_cost;

			fill_layer2(x, y - 1, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer2[y + 1][x] == smallest_value + 1 || new_y_value < layer2[y + 1][x] || ((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1)) {
			layer2[y + 1][x] = new_y_value;

			if (((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1))
				layer2[y + 1][x] = layer1[y + 1][x] + via_cost;

			fill_layer2(x, y + 1, layer1, layer2, x_size, y_size, smallest_value);
		}

	}
	//right of the grid
	else if (x == x_size - 1) {
		//check the left cell
		if (layer2[y][x - 1] == smallest_value + 1 || new_x_value < layer2[y][x - 1] || ((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1)) {
			layer2[y][x - 1] = new_x_value;
			if (((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1))
				layer2[y][x - 1] = layer1[y][x - 1] + via_cost;
			fill_layer2(x - 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer2[y - 1][x] == smallest_value + 1 || new_y_value < layer2[y - 1][x] || ((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1)) {
			layer2[y - 1][x] = new_y_value;

			if (((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1))
				layer2[y - 1][x] = layer1[y - 1][x] + via_cost;

			fill_layer2(x, y - 1, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer2[y + 1][x] == smallest_value + 1 || new_y_value < layer2[y + 1][x] || ((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1)) {
			layer2[y + 1][x] = new_y_value;

			if (((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1))
				layer2[y + 1][x] = layer1[y + 1][x] + via_cost;

			fill_layer2(x, y + 1, layer1, layer2, x_size, y_size, smallest_value);
		}
	}
	//top of the grid
	else if (y == 0) {
		//check the left cell
		if (layer2[y][x - 1] == smallest_value + 1 || new_x_value < layer2[y][x - 1] || ((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1)) {
			layer2[y][x - 1] = new_x_value;
			if (((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1))
				layer2[y][x - 1] = layer1[y][x - 1] + via_cost;
			fill_layer2(x - 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the right cell
		if (layer2[y][x + 1] == smallest_value + 1 || new_x_value < layer2[y][x + 1] || ((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1)) {
			layer2[y][x + 1] = new_x_value;
			if (((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1))
				layer2[y][x + 1] = layer1[y][x + 1] + via_cost;
			fill_layer2(x + 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer2[y + 1][x] == smallest_value + 1 || new_y_value < layer2[y + 1][x] || ((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1)) {
			layer2[y + 1][x] = new_y_value;

			if (((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1))
				layer2[y + 1][x] = layer1[y + 1][x] + via_cost;

			fill_layer2(x, y + 1, layer1, layer2, x_size, y_size, smallest_value);
		}
	}
	//bottom of the grid
	else if (y == y_size - 1) {
		//check the left cell
		if (layer2[y][x - 1] == smallest_value + 1 || new_x_value < layer2[y][x - 1] || ((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1)) {
			layer2[y][x - 1] = new_x_value;
			if (((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1))
				layer2[y][x - 1] = layer1[y][x - 1] + via_cost;
			fill_layer2(x - 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the right cell
		if (layer2[y][x + 1] == smallest_value + 1 || new_x_value < layer2[y][x + 1] || ((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1)) {
			layer2[y][x + 1] = new_x_value;
			if (((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1))
				layer2[y][x + 1] = layer1[y][x + 1] + via_cost;
			fill_layer2(x + 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer2[y - 1][x] == smallest_value + 1 || new_y_value < layer2[y - 1][x] || ((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1)) {
			layer2[y - 1][x] = new_y_value;

			if (((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1))
				layer2[y - 1][x] = layer1[y - 1][x] + via_cost;

			fill_layer2(x, y - 1, layer1, layer2, x_size, y_size, smallest_value);
		}
	}
	//middle of the grid
	else {
		//check the left cell
		if (layer2[y][x - 1] == smallest_value + 1 || new_x_value < layer2[y][x - 1] || ((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1)) {
			layer2[y][x - 1] = new_x_value;
			if (((layer1[y][x - 1] + via_cost) < layer2[y][x - 1] && layer1[y][x - 1] != -1))
				layer2[y][x - 1] = layer1[y][x - 1] + via_cost;
			fill_layer2(x - 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the right cell
		if (layer2[y][x + 1] == smallest_value + 1 || new_x_value < layer2[y][x + 1] || ((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1)) {
			layer2[y][x + 1] = new_x_value;
			if (((layer1[y][x + 1] + via_cost) < layer2[y][x + 1] && layer1[y][x + 1] != -1))
				layer2[y][x + 1] = layer1[y][x + 1] + via_cost;
			fill_layer2(x + 1, y, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the top cell
		if (layer2[y - 1][x] == smallest_value + 1 || new_y_value < layer2[y - 1][x] || ((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1)) {
			layer2[y - 1][x] = new_y_value;

			if (((layer1[y - 1][x] + via_cost) < layer2[y - 1][x] && layer1[y - 1][x] != -1))
				layer2[y - 1][x] = layer1[y - 1][x] + via_cost;

			fill_layer2(x, y - 1, layer1, layer2, x_size, y_size, smallest_value);
		}
		//check the bottom cell
		if (layer2[y + 1][x] == smallest_value + 1 || new_y_value < layer2[y + 1][x] || ((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1)) {
			layer2[y + 1][x] = new_y_value;

			if (((layer1[y + 1][x] + via_cost) < layer2[y + 1][x] && layer1[y + 1][x] != -1))
				layer2[y + 1][x] = layer1[y + 1][x] + via_cost;

			fill_layer2(x, y + 1, layer1, layer2, x_size, y_size, smallest_value);
		}
	}
}

struct paramters
{
	int layer;
	int x_value;
	int y_value;

};

vector<vector<paramters>> file_read(string filename) {

	paramters p;
	vector <paramters> obstacles;
	vector <int> num;
	vector <int> num_2;
	vector<vector<int>> nets;
	string x_size;
	string y_size;
	deque<string> vec1, vec_2, vec_3;

	fstream file;
	file.open(filename, ios::in);
	string line;
	while (file.good())
	{

		getline(file, line);
		vec1.push_back(line);
	}
	file.close();
	string s;
	for (int i = 0; i < vec1.size(); i++)
	{
		s.clear();
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
				s = s + vec1[i][j];
			}


		}
		nets.push_back(num_2);
		num_2.clear();
	}
	vector<vector<paramters>> nets2;
	paramters p1;
	vector<paramters> num_3;
	for (int i = 0; i < nets.size(); i++) {
		for (int j = 0; j < nets[i].size(); j = j + 3) {
			p.layer = nets[i][j];
			p.x_value = nets[i][j + 1];
			p.y_value = nets[i][j + 2];
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


	return nets2;
}


vector<paramters> Back_Track(paramters target, int** layer1, int** layer2, int x_size, int y_size) {
	vector<paramters> path;
	path.push_back(target);
	//assign the current cell value
	int current_cell_value;
	if (target.layer == 1)
		current_cell_value = layer1[target.y_value][target.x_value];
	else
		current_cell_value = layer2[target.y_value][target.x_value];

	//loop till it reach the source

	while (current_cell_value != 0) {
		//check the edges
		//check top left edge
		if (target.x_value == 0 && target.y_value == 0) {
			

			switch (target.layer)
			{
			case 1: {
				int right_cost, bottom_cost, via_cost;
				//calculate the right cost
				if (layer1[target.y_value][target.x_value + 1] == -1 || layer1[target.y_value][target.x_value + 1] >= layer1[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value + 1];
				//calculate the bottom cost
				if (layer1[target.y_value + 1][target.x_value] == -1 || layer1[target.y_value + 1][target.x_value] >= layer1[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= bottom_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}

				//move down if the bottom cost is the minimum
				else if (bottom_cost <= right_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= bottom_cost) {
					target.layer = 2;
					path.push_back(target);
				}
			}
					break;
			case 2: {

				int right_cost, bottom_cost, via_cost;
				//calculate the right cost
				if (layer2[target.y_value][target.x_value + 1] == -1 || layer2[target.y_value][target.x_value + 1] >= layer2[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value + 1];
				//calculate the bottom cost
				if (layer2[target.y_value + 1][target.x_value] == -1 || layer2[target.y_value + 1][target.x_value] >= layer2[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= bottom_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}
				//move down if the bottom cost is the minimum
				else if (bottom_cost <= right_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= bottom_cost) {
					target.layer = 1;
					path.push_back(target);
				}

			}
					break;
			}

		}
		//check bottom left edge
		else if (target.x_value == 0 && target.y_value == y_size - 1) {


			switch (target.layer)
			{
			case 1: {
				int right_cost, top_cost, via_cost;
				//calculate the right cost
				if (layer1[target.y_value][target.x_value + 1] == -1 || layer1[target.y_value][target.x_value + 1] >= layer1[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value + 1];
				//calculate the top cost
				if (layer1[target.y_value - 1][target.x_value] == -1 || layer1[target.y_value - 1][target.x_value] >= layer1[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value - 1][target.x_value];
				//calculate via cost
				if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= top_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}

				//move up if the top cost is the minimum
				else if (top_cost <= right_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= top_cost) {
					target.layer = 2;
					path.push_back(target);
				}
			}
					break;
			case 2: {

				int right_cost, top_cost, via_cost;
				//calculate the right cost
				if (layer2[target.y_value][target.x_value + 1] == -1 || layer2[target.y_value][target.x_value + 1] >= layer2[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value + 1];
				//calculate the top cost
				if (layer2[target.y_value - 1][target.x_value] == -1 || layer2[target.y_value - 1][target.x_value] >= layer2[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value - 1][target.x_value];
				
				//calculate via cost
				if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= top_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}
				//move up if the top cost is the minimum
				else if (top_cost <= right_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}

				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= top_cost) {
					target.layer = 1;
					path.push_back(target);
				}

			}
					break;
			}

		}
		//check top right edge
		else if (target.x_value == x_size - 1 && target.y_value == 0) {

		switch (target.layer)
		{
		case 1: {
			int left_cost, bottom_cost, via_cost;

			//calculate the left cost
			if (layer1[target.y_value][target.x_value - 1] == -1 || layer1[target.y_value][target.x_value - 1] >= layer1[target.y_value][target.x_value])
				left_cost = 999999;
			else
				left_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value - 1];
			//calculate the bottom cost
			if (layer1[target.y_value + 1][target.x_value] == -1 || layer1[target.y_value + 1][target.x_value] >= layer1[target.y_value][target.x_value])
				bottom_cost = 999999;
			else
				bottom_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value + 1][target.x_value];
			//calculate via cost
			if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
				via_cost = 999999;
			else
				via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

			//check the min cost direction
			//move left if the left cost is the minimum
			if (left_cost <= bottom_cost && left_cost <= via_cost) {
				target.x_value--;
				path.push_back(target);
			}
			//move down if the bottom cost is the minimum
			else if (bottom_cost <= left_cost && bottom_cost <= via_cost) {
				target.y_value++;
				path.push_back(target);
			}
			//move to layer2 if the via cost is the minimum
			else if (via_cost <= left_cost && via_cost <= bottom_cost) {
				target.layer = 2;
				path.push_back(target);
			}
		}
				break;
		case 2: {

			int left_cost, bottom_cost, via_cost;

			//calculate the left cost
			if (layer2[target.y_value][target.x_value - 1] == -1 || layer2[target.y_value][target.x_value - 1] >= layer2[target.y_value][target.x_value])
				left_cost = 999999;
			else
				left_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value - 1];
			//calculate the bottom cost
			if (layer2[target.y_value + 1][target.x_value] == -1 || layer2[target.y_value + 1][target.x_value] >= layer2[target.y_value][target.x_value])
				bottom_cost = 999999;
			else
				bottom_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value + 1][target.x_value];
			//calculate via cost
			if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
				via_cost = 999999;
			else
				via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

			//check the min cost direction

			//move left if the left cost is the minimum
			if (left_cost <= bottom_cost && left_cost <= via_cost) {
				target.x_value--;
				path.push_back(target);
			}
			//move down if the bottom cost is the minimum
			else if (bottom_cost <= left_cost && bottom_cost <= via_cost) {
				target.y_value++;
				path.push_back(target);
			}
			//move to layer2 if the via cost is the minimum
			else if (via_cost <= left_cost && via_cost <= bottom_cost) {
				target.layer = 1;
				path.push_back(target);
			}

		}
				break;
		}

		}
		//check bottom right edge
		else if (target.x_value == x_size - 1 && target.y_value == y_size - 1) {
		switch (target.layer)
		{
		case 1: {
			int top_cost, left_cost, via_cost;

			//calculate the left cost
			if (layer1[target.y_value][target.x_value - 1] == -1 || layer1[target.y_value][target.x_value - 1] >= layer1[target.y_value][target.x_value])
				left_cost = 999999;
			else
				left_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value - 1];
			//calculate the top cost
			if (layer1[target.y_value - 1][target.x_value] == -1 || layer1[target.y_value - 1][target.x_value] >= layer1[target.y_value][target.x_value])
				top_cost = 999999;
			else
				top_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value - 1][target.x_value];

			//calculate via cost
			if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
				via_cost = 999999;
			else
				via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

			//check the min cost direction
			//move left if the left cost is the minimum
			if (left_cost <= top_cost && left_cost <= via_cost) {
				target.x_value--;
				path.push_back(target);
			}
			//move up if the top cost is the minimum
			else if (top_cost <= left_cost && top_cost <= via_cost) {
				target.y_value--;
				path.push_back(target);
			}

			//move to layer2 if the via cost is the minimum
			else if (via_cost <= left_cost && via_cost <= top_cost) {
				target.layer = 2;
				path.push_back(target);
			}
		}
				break;
		case 2: {

			int top_cost, left_cost, via_cost;

			//calculate the left cost
			if (layer2[target.y_value][target.x_value - 1] == -1 || layer2[target.y_value][target.x_value - 1] >= layer2[target.y_value][target.x_value])
				left_cost = 999999;
			else
				left_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value - 1];
			//calculate the top cost
			if (layer2[target.y_value - 1][target.x_value] == -1 || layer2[target.y_value - 1][target.x_value] >= layer2[target.y_value][target.x_value])
				top_cost = 999999;
			else
				top_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value - 1][target.x_value];
			//calculate via cost
			if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
				via_cost = 999999;
			else
				via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

			//check the min cost direction

			//move left if the left cost is the minimum
			if (left_cost <= top_cost && left_cost <= via_cost) {
				target.x_value--;
				path.push_back(target);
			}
			//move up if the top cost is the minimum
			else if (top_cost <= left_cost && top_cost <= via_cost) {
				target.y_value--;
				path.push_back(target);
			}
			//move to layer2 if the via cost is the minimum
			else if (via_cost <= left_cost && via_cost <= top_cost) {
				target.layer = 1;
				path.push_back(target);
			}

		}
				break;
		}
		}
		//check left
		else if (target.x_value == 0) {


			switch (target.layer)
			{
			case 1: {
				int right_cost, top_cost, bottom_cost, via_cost;
				//calculate the right cost
				if (layer1[target.y_value][target.x_value + 1] == -1 || layer1[target.y_value][target.x_value + 1] >= layer1[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value + 1];
				//calculate the top cost
				if (layer1[target.y_value - 1][target.x_value] == -1 || layer1[target.y_value - 1][target.x_value] >= layer1[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value - 1][target.x_value];
				//calculate the bottom cost
				if (layer1[target.y_value + 1][target.x_value] == -1 || layer1[target.y_value + 1][target.x_value] >= layer1[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= top_cost && right_cost <= bottom_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}

				//move up if the top cost is the minimum
				else if (top_cost <= right_cost && top_cost <= bottom_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}
				//move down if the bottom cost is the minimum
				else if (bottom_cost <= right_cost && bottom_cost <= top_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= top_cost && via_cost <= bottom_cost) {
					target.layer = 2;
					path.push_back(target);
				}
			}
					break;
			case 2: {

				int right_cost, top_cost, bottom_cost, via_cost;
				//calculate the right cost
				if (layer2[target.y_value][target.x_value + 1] == -1 || layer2[target.y_value][target.x_value + 1] >= layer2[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value + 1];
				//calculate the top cost
				if (layer2[target.y_value - 1][target.x_value] == -1 || layer2[target.y_value - 1][target.x_value] >= layer2[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value - 1][target.x_value];
				//calculate the bottom cost
				if (layer2[target.y_value + 1][target.x_value] == -1 || layer2[target.y_value + 1][target.x_value] >= layer2[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= top_cost && right_cost <= bottom_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}
				//move up if the top cost is the minimum
				else if (top_cost <= right_cost && top_cost <= bottom_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}
				//move down if the bottom cost is the minimum
				else if (bottom_cost <= right_cost && bottom_cost <= top_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= top_cost && via_cost <= bottom_cost) {
					target.layer = 1;
					path.push_back(target);
				}

			}
					break;
			}
		}
		//check top
		else if (target.y_value == 0) {

			switch (target.layer)
			{
			case 1: {
				int right_cost, left_cost, bottom_cost, via_cost;
				//calculate the right cost
				if (layer1[target.y_value][target.x_value + 1] == -1 || layer1[target.y_value][target.x_value + 1] >= layer1[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value + 1];
				//calculate the left cost
				if (layer1[target.y_value][target.x_value - 1] == -1 || layer1[target.y_value][target.x_value - 1] >= layer1[target.y_value][target.x_value])
					left_cost = 999999;
				else
					left_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value - 1];
				//calculate the bottom cost
				if (layer1[target.y_value + 1][target.x_value] == -1 || layer1[target.y_value + 1][target.x_value] >= layer1[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= left_cost && right_cost <= bottom_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}
				//move left if the left cost is the minimum
				else if (left_cost <= right_cost && left_cost <= bottom_cost && left_cost <= via_cost) {
					target.x_value--;
					path.push_back(target);
				}
				//move down if the bottom cost is the minimum
				else if (bottom_cost <= right_cost && bottom_cost <= left_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= left_cost && via_cost <= bottom_cost) {
					target.layer = 2;
					path.push_back(target);
				}
			}
					break;
			case 2: {

				int right_cost, left_cost, bottom_cost, via_cost;
				//calculate the right cost
				if (layer2[target.y_value][target.x_value + 1] == -1 || layer2[target.y_value][target.x_value + 1] >= layer2[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value + 1];
				//calculate the left cost
				if (layer2[target.y_value][target.x_value - 1] == -1 || layer2[target.y_value][target.x_value - 1] >= layer2[target.y_value][target.x_value])
					left_cost = 999999;
				else
					left_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value - 1];
				//calculate the bottom cost
				if (layer2[target.y_value + 1][target.x_value] == -1 || layer2[target.y_value + 1][target.x_value] >= layer2[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= left_cost && right_cost <= bottom_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}
				//move left if the left cost is the minimum
				else if (left_cost <= right_cost && left_cost <= bottom_cost && left_cost <= via_cost) {
					target.x_value--;
					path.push_back(target);
				}
				//move down if the bottom cost is the minimum
				else if (bottom_cost <= right_cost && bottom_cost <= left_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= left_cost && via_cost <= bottom_cost) {
					target.layer = 1;
					path.push_back(target);
				}

			}
					break;
			}
		}
		//check right
		else if (target.x_value == x_size - 1) {
			switch (target.layer)
			{
			case 1: {
				int top_cost, left_cost, bottom_cost, via_cost;

				//calculate the left cost
				if (layer1[target.y_value][target.x_value - 1] == -1 || layer1[target.y_value][target.x_value - 1] >= layer1[target.y_value][target.x_value])
					left_cost = 999999;
				else
					left_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value - 1];
				//calculate the top cost
				if (layer1[target.y_value - 1][target.x_value] == -1 || layer1[target.y_value - 1][target.x_value] >= layer1[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value - 1][target.x_value];
				//calculate the bottom cost
				if (layer1[target.y_value + 1][target.x_value] == -1 || layer1[target.y_value + 1][target.x_value] >= layer1[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

				//check the min cost direction
				//move left if the left cost is the minimum
				if (left_cost <= top_cost && left_cost <= bottom_cost && left_cost <= via_cost) {
					target.x_value--;
					path.push_back(target);
				}
				//move up if the top cost is the minimum
				else if (top_cost <= left_cost && top_cost <= bottom_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}
				//move down if the bottom cost is the minimum
				else if (bottom_cost <= left_cost && bottom_cost <= top_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= left_cost && via_cost <= top_cost && via_cost <= bottom_cost) {
					target.layer = 2;
					path.push_back(target);
				}
			}
					break;
			case 2: {

				int top_cost, left_cost, bottom_cost, via_cost;
				
				//calculate the left cost
				if (layer2[target.y_value][target.x_value - 1] == -1 || layer2[target.y_value][target.x_value - 1] >= layer2[target.y_value][target.x_value])
					left_cost = 999999;
				else
					left_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value - 1];
				//calculate the top cost
				if (layer2[target.y_value - 1][target.x_value] == -1 || layer2[target.y_value - 1][target.x_value] >= layer2[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value - 1][target.x_value];
				//calculate the bottom cost
				if (layer2[target.y_value + 1][target.x_value] == -1 || layer2[target.y_value + 1][target.x_value] >= layer2[target.y_value][target.x_value])
					bottom_cost = 999999;
				else
					bottom_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value + 1][target.x_value];
				//calculate via cost
				if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

				//check the min cost direction
				
				//move left if the left cost is the minimum
				if (left_cost <= top_cost && left_cost <= bottom_cost && left_cost <= via_cost) {
					target.x_value--;
					path.push_back(target);
				}
				//move up if the top cost is the minimum
				else if (top_cost <= left_cost && top_cost <= bottom_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}
				//move down if the bottom cost is the minimum
				else if (bottom_cost <= left_cost && bottom_cost <= top_cost && bottom_cost <= via_cost) {
					target.y_value++;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= left_cost && via_cost <= top_cost && via_cost <= bottom_cost) {
					target.layer = 1;
					path.push_back(target);
				}

			}
					break;
			}
		}
		//check bottom
		else if (target.y_value == y_size - 1) {
			switch (target.layer)
			{
			case 1: {
				int right_cost, top_cost, left_cost, via_cost;
				//calculate the right cost
				if (layer1[target.y_value][target.x_value + 1] == -1 || layer1[target.y_value][target.x_value + 1] >= layer1[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value + 1];
				//calculate the left cost
				if (layer1[target.y_value][target.x_value - 1] == -1 || layer1[target.y_value][target.x_value - 1] >= layer1[target.y_value][target.x_value])
					left_cost = 999999;
				else
					left_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value - 1];
				//calculate the top cost
				if (layer1[target.y_value - 1][target.x_value] == -1 || layer1[target.y_value - 1][target.x_value] >= layer1[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value - 1][target.x_value];
				
				//calculate via cost
				if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= left_cost && right_cost <= top_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}
				//move left if the left cost is the minimum
				else if (left_cost <= right_cost && left_cost <= top_cost && left_cost <= via_cost) {
					target.x_value--;
					path.push_back(target);
				}
				//move up if the top cost is the minimum
				else if (top_cost <= right_cost && top_cost <= left_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= left_cost && via_cost <= top_cost) {
					target.layer = 2;
					path.push_back(target);
				}
			}
					break;
			case 2: {

				int right_cost, top_cost, left_cost, via_cost;
				//calculate the right cost
				if (layer2[target.y_value][target.x_value + 1] == -1 || layer2[target.y_value][target.x_value + 1] >= layer2[target.y_value][target.x_value])
					right_cost = 999999;
				else
					right_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value + 1];
				//calculate the left cost
				if (layer2[target.y_value][target.x_value - 1] == -1 || layer2[target.y_value][target.x_value - 1] >= layer2[target.y_value][target.x_value])
					left_cost = 999999;
				else
					left_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value - 1];
				//calculate the top cost
				if (layer2[target.y_value - 1][target.x_value] == -1 || layer2[target.y_value - 1][target.x_value] >= layer2[target.y_value][target.x_value])
					top_cost = 999999;
				else
					top_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value - 1][target.x_value];
				
				//calculate via cost
				if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
					via_cost = 999999;
				else
					via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

				//check the min cost direction
				//move right if the right cost is the minimum
				if (right_cost <= left_cost && right_cost <= top_cost && right_cost <= via_cost) {
					target.x_value++;
					path.push_back(target);
				}
				//move left if the left cost is the minimum
				else if (left_cost <= right_cost && left_cost <= top_cost && left_cost <= via_cost) {
					target.x_value--;
					path.push_back(target);
				}
				//move up if the top cost is the minimum
				else if (top_cost <= right_cost && top_cost <= left_cost && top_cost <= via_cost) {
					target.y_value--;
					path.push_back(target);
				}
				//move to layer2 if the via cost is the minimum
				else if (via_cost <= right_cost && via_cost <= left_cost && via_cost <= top_cost) {
					target.layer = 1;
					path.push_back(target);
				}

			}
					break;
			}
		}
		else {
				switch (target.layer)
				{
				case 1: {
					int right_cost, top_cost, left_cost, bottom_cost, via_cost;
					//calculate the right cost
					if (layer1[target.y_value][target.x_value + 1] == -1 || layer1[target.y_value][target.x_value + 1] >= layer1[target.y_value][target.x_value])
						right_cost = 999999;
					else
						right_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value + 1];
					//calculate the left cost
					if (layer1[target.y_value][target.x_value - 1] == -1 || layer1[target.y_value][target.x_value - 1] >= layer1[target.y_value][target.x_value])
						left_cost = 999999;
					else
						left_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value][target.x_value - 1];
					//calculate the top cost
					if (layer1[target.y_value - 1][target.x_value] == -1 || layer1[target.y_value - 1][target.x_value] >= layer1[target.y_value][target.x_value])
						top_cost = 999999;
					else
						top_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value - 1][target.x_value];
					//calculate the bottom cost
					if (layer1[target.y_value + 1][target.x_value] == -1 || layer1[target.y_value + 1][target.x_value] >= layer1[target.y_value][target.x_value])
						bottom_cost = 999999;
					else
						bottom_cost = layer1[target.y_value][target.x_value] - layer1[target.y_value + 1][target.x_value];
					//calculate via cost
					if (layer2[target.y_value][target.x_value] == -1 || layer2[target.y_value][target.x_value] >= layer1[target.y_value][target.x_value])
						via_cost = 999999;
					else
						via_cost = layer1[target.y_value][target.x_value] - layer2[target.y_value][target.x_value];

					//check the min cost direction
					//move right if the right cost is the minimum
					if (right_cost <= left_cost && right_cost <= top_cost && right_cost <= bottom_cost && right_cost <= via_cost) {
						target.x_value++;
						path.push_back(target);
					}
					//move left if the left cost is the minimum
					else if (left_cost <= right_cost && left_cost <= top_cost && left_cost <= bottom_cost && left_cost <= via_cost) {
						target.x_value--;
						path.push_back(target);
					}
					//move up if the top cost is the minimum
					else if (top_cost <= right_cost && top_cost <= left_cost && top_cost <= bottom_cost && top_cost <= via_cost) {
						target.y_value--;
						path.push_back(target);
					}
					//move down if the bottom cost is the minimum
					else if (bottom_cost <= right_cost && bottom_cost <= left_cost && bottom_cost <= top_cost && bottom_cost <= via_cost) {
						target.y_value++;
						path.push_back(target);
					}
					//move to layer2 if the via cost is the minimum
					else if (via_cost <= right_cost && via_cost <= left_cost && via_cost <= top_cost && via_cost <= bottom_cost) {
						target.layer = 2;
						path.push_back(target);
					}
				}
						break;
				case 2: {

					int right_cost, top_cost, left_cost, bottom_cost, via_cost;
					//calculate the right cost
					if (layer2[target.y_value][target.x_value + 1] == -1 || layer2[target.y_value][target.x_value + 1] >= layer2[target.y_value][target.x_value])
						right_cost = 999999;
					else
						right_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value + 1];
					//calculate the left cost
					if (layer2[target.y_value][target.x_value - 1] == -1 || layer2[target.y_value][target.x_value - 1] >= layer2[target.y_value][target.x_value])
						left_cost = 999999;
					else
						left_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value][target.x_value - 1];
					//calculate the top cost
					if (layer2[target.y_value - 1][target.x_value] == -1 || layer2[target.y_value - 1][target.x_value] >= layer2[target.y_value][target.x_value])
						top_cost = 999999;
					else
						top_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value - 1][target.x_value];
					//calculate the bottom cost
					if (layer2[target.y_value + 1][target.x_value] == -1 || layer2[target.y_value + 1][target.x_value] >= layer2[target.y_value][target.x_value])
						bottom_cost = 999999;
					else
						bottom_cost = layer2[target.y_value][target.x_value] - layer2[target.y_value + 1][target.x_value];
					//calculate via cost
					if (layer1[target.y_value][target.x_value] == -1 || layer1[target.y_value][target.x_value] >= layer2[target.y_value][target.x_value])
						via_cost = 999999;
					else
						via_cost = layer2[target.y_value][target.x_value] - layer1[target.y_value][target.x_value];

					//check the min cost direction
					//move right if the right cost is the minimum
					if (right_cost <= left_cost && right_cost <= top_cost && right_cost <= bottom_cost && right_cost <= via_cost) {
						target.x_value++;
						path.push_back(target);
					}
					//move left if the left cost is the minimum
					else if (left_cost <= right_cost && left_cost <= top_cost && left_cost <= bottom_cost && left_cost <= via_cost) {
						target.x_value--;
						path.push_back(target);

					}
					//move up if the top cost is the minimum
					else if (top_cost <= right_cost && top_cost <= left_cost && top_cost <= bottom_cost && top_cost <= via_cost) {
						target.y_value--;
						path.push_back(target);

					}
					//move down if the bottom cost is the minimum
					else if (bottom_cost <= right_cost && bottom_cost <= left_cost && bottom_cost <= top_cost && bottom_cost <= via_cost) {
						target.y_value++;
						path.push_back(target);

					}
					//move to layer2 if the via cost is the minimum
					else if (via_cost <= right_cost && via_cost <= left_cost && via_cost <= top_cost && via_cost <= bottom_cost) {
						target.layer = 1;
						path.push_back(target);

					}
				}
						break;
				}
		}

		if (target.layer == 1)
			current_cell_value = layer1[target.y_value][target.x_value];
		else
			current_cell_value = layer2[target.y_value][target.x_value];
	}

	return path;
}

int main() {

	int x_source = 3, y_source = 5, x_size = 25, y_size = 25;
	int**layer1 = new int*[y_size];
	int**layer2 = new int*[y_size];


	for (int i = 0; i < y_size; i++) {
		layer1[i] = new int[x_size];
		layer2[i] = new int[x_size];
	}


	for (int i = 0; i < y_size; i++)
		for (int j = 0; j < x_size; j++) {
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
	fill_layer1(x_source, y_source, layer1, x_size, y_size, 0);
	if(x_source == 0)
	layer1[y_source][x_source + 1] = 1;
	else if (x_source == x_size-1)
	layer1[y_source][x_source - 1] = 1;
	else {
		layer1[y_source][x_source + 1] = 1;
		layer1[y_source][x_source - 1] = 1;
	}

	//fill layer2

	for (int i = 0; i < y_size; i++)
		for (int j = 0; j < x_size; j++) {
			layer2[i][j] = 11;
		}

	fill_layer2(x_source, y_source, layer1, layer2, x_size, y_size, 10);
	layer2[y_source][x_source] = layer1[y_source][x_source] + 10;

	if (y_source == 0)
		layer2[y_source + 1][x_source] = 11;
	else if (y_source == y_size - 1)
		layer2[y_source - 1][x_source] = 11;
	else {
		layer2[y_source + 1][x_source] = 11;
		layer2[y_source - 1][x_source] = 11;
	}


	vector<vector<paramters>> nets = file_read("input.txt");


	for (int i = 0; i < nets.size(); i++) {
		nets[i][0].layer
		for (int j = 1; j < nets[i].size(); j++) {


		}
	}


	paramters target;
	target.layer = 1;
	target.x_value = 1;
	target.y_value = 1;
	vector<paramters> path = Back_Track(target, layer1, layer2, x_size, y_size);


	system("pause");
	return 0;
}