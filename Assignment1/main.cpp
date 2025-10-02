/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment1
*/

#include "hello.h"

#include <iostream>

int main(){
	using namespace std;
	myproject::sayHello();
	string s;
	while (true){
		cin >> s;
		myproject::sayHello(s);
	}
	return 0;
}
