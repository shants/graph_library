refer to my blog listed below, it talks about how to create a library and use it. This repos contains all code and files generate / used. 

http://shantans.wordpress.com/2014/07/02/create-a-shared-lib-and-use-it/

listing the steps from the blog 

step 1 :
create adjList.h and adjList.cpp 

step 2 :
an object file : g++ -c -fpic adjList.cpp
after this step, you will find adjList.o 

step 3 :
create the sharedLibrary using the .o file
g++ -shared -o libadjList.so adjList.o

step 4 :
set the library path, 
export LD_LIBRARY_PATH=/home/ss/graphs:$LD_LIBRARY_PATH

echo $LD_LIBRARY_PATH to see the updated lib path

step 5 :
generate your executable, 
g++ -L/home/ss/graphs -o test dijkstra.cpp -ladjList

if you skip step 4, you may get following error on running the executable

ss@ubuntu:~/graphs$ ./test
./test: error while loading shared libraries: libadjList.so: cannot open shared object file: No such file or directory


