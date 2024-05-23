#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
 
	int n = atoi(argv[1]);
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		a[i] = rnd.next(-100000, 100000);	
		
	println(n);
	println(a);
}