import matplotlib.pyplot as plt
import numpy as np
import multiprocessing
list1 = []
x2 = []
y2 = []
x1 = []
y1 = []
f = open('output40x40.txt', 'r').read()
lines = f.split('\n')
for line in lines:
    l = str(line)
    l = l.replace('net1', '')
    l = l.replace('net2', '')
    l = l.replace('net3', '')
    l = l.replace('net4', '')
    l = l.replace('net5', '')
    l = l.replace('net6', '')
    l = l.replace('net7', '')
    l = l.replace('net8', '')
    l = l.replace('net9', '')
    l = l.replace('net10', '')
    l = l.replace(')  (', '/')
    l = l.replace('(', '')
    l = l.replace(')', '')
    l = l.replace(' ', '')
    list = l.split('/')
    for points in list:
        point = points.split(',')
        list1.append(point)
for point in list1:
    if point[0] == '2':
        x2.append(int(point[1]))
        y2.append(int(point[2]))
    elif point[0] == '1':
        x1.append(int(point[1]))
        y1.append(int(point[2]))
I2 = np.zeros((max(y2)+1, max(x2)+1))
I1 = np.zeros((max(y1)+1, max(x1)+1))
counter = 0
xTicks2 = []
yTicks2 = []
xTicks2cnt = 0
yTicks2cnt = 0
for xtrick2 in range(max(x2)+3):
    xTicks2.append(xTicks2cnt)
    xTicks2cnt += 1
for ytrick2 in range(max(y2)+3):
    yTicks2.append(yTicks2cnt)
    yTicks2cnt += 1
for counter in range(len(x2)):
    if counter == 0 or counter == len(x2)-1:
        I2[y2[counter]][x2[counter]] = 2
    else:
        I2[y2[counter]][x2[counter]] = 1
    counter += 1
counter = 0
xTicks1 = []
yTicks1 = []
xTicks1cnt = 0
yTicks1cnt = 0
for xtrick1 in range(max(x1)+3):
    xTicks1.append(xTicks1cnt)
    xTicks1cnt += 1
for ytrick1 in range(max(y1)+3):
    yTicks1.append(yTicks1cnt)
    yTicks1cnt += 1
for counter in range(len(x1)):
    if counter == 0 or counter == len(x1)-1:
        I1[y1[counter]][x1[counter]] = 2
    else:
        I1[y1[counter]][x1[counter]] = 1*(counter+1)*0.2
    counter += 1
def plot1():
    plt.imshow(I2)
    plt.gca().invert_yaxis()
    plt.xticks(xTicks2)
    plt.yticks(yTicks2)
    plt.show()
def plot2():
    plt.imshow(I1)
    plt.gca().invert_yaxis()
    plt.xticks(xTicks1)
    plt.yticks(yTicks1)
    plt.show()
p1 = multiprocessing.Process(target = plot1)
p2 = multiprocessing.Process(target = plot2)
if __name__ == "__main__":
    p1.start()
    p2.start()
