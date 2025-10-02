#include "hello.h"

#include <string>
#include <iostream>

void myproject::sayHello(std::string s = "world"){
	std::cout << "Hello, " << s << "!" << std::endl;
}
