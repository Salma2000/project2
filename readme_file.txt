to run the project:
the project needs an input file "input.txt" and produces an output.txt using c++ on visual studio

the input file should be on the following format:
25x25
OBS (1,3,4)
OBS (1,5,7)
OBS (1,9,8)
net1 (1,10,20) (2,3,5) (1,4,5) (1,10,5)
net2 (1,10,5) (2,1,1)
net3 (1,13,15) (1,1,1)

then the visiualization python code should take the output.txt file and generate the visualization of the grids


The algorithm declares two layers grid
Sources are initialized to 0 and obstacles are initialized to -1
The algorithm recursively fill layer1 then layer2
Then the algorithm loop on the target pins and backtrack to the source producing a path
The path is then initialized to 0 and is considered source points
The algorithm keeps looping and connecting the target points with shortest point on the path
