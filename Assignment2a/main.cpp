#include <iostream>
#include <fstream>
#include <filesystem>

void swap(char& letter1, char& letter2){
	char tmp = letter1;
	letter1 = letter2;
	letter2 = tmp;
}

void reverse_array(char* data, size_t size){
	for(size_t i = 0; i < size / 2; i++){
		swap(data[i], data[size - 1 - i]);
	}
}


int main(){
	std::string filename;
	std::cout << "Enter filename:";
	std::cin >> filename;
	const size_t file_size = std::filesystem::file_size(filename);
	
	char* buffer = new char[file_size];
	
	std::ifstream file(filename, std::ios::binary);
	file.read(buffer, file_size);
	file.close();
	
	reverse_array(buffer, file_size);

	std::ofstream outfile;
	const std::string output_filename = "output_" + filename;
	
	outfile.open(output_filename, std::ios::binary | std::ios::out);
	outfile.write(buffer, file_size);
	outfile.close();
	
	std::cout << output_filename << " was created." << std::endl;
	delete[] buffer;
	return 0;
}
