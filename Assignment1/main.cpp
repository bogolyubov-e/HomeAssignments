#include "hello.h"

#include <string>
#include <iostream>

int main(){
	using namespace std;
	sayHello();
	string s;
	while (1){
		cin >> s;
		sayHello(s);
	}
	return 0;
}
