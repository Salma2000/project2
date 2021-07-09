def fill_layer1(x, y, starting_point_i=0, starting_point_j=0, **layer1):
    for i in range(starting_point_i, 1000):
        for j in range(starting_point_j, 1000):
            if layer1[i][j] != 0 and x != i and y != j:
                layer1[i][j] = 10 * (x - i) + (y - j)


def fill_layer2(x, y, starting_point_i=0, starting_point_j=0, **layer2):
    for i in range(starting_point_i, 1000):
        for j in range(starting_point_j, 1000):
            if layer2[i][j] != 0 and x != i and y != j:
                layer2[i][j] = (x - i) + 10 * (y - j)


class Pin:
    layer_number = 1
    x_location = 0
    y_location = 0


def main():
    nets_array = [[]]
    for i in range(len(nets_array)):
        for j in range(len(nets_array[i])):
            layer_number = nets_array[i][j].layer_number
            source_x = nets_array[i][j].x_location
            source_y = nets_array[i][j].y_location
            if layer_number == 1:
                
