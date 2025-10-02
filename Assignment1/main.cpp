#include "hello.h"

#include <iostream>

int main(){
	using namespace std;
	myproject::sayHello();
	string s;
	while (1){
		cin >> s;
		myproject::sayHello(s);
	}
	return 0;
}
