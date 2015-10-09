#include "manager.h"
#include <chrono>

int main(int argc, char **argv)
{	
	Manager man;
	man.ParseIn(argc,argv);
	
	getchar();
	return 0;
}