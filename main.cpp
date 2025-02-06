#include <iostream>
#include <string>
#include <fstream>

const std::string helpMessageStr = "you should specify a filename like so\n\nhtmlentities yourfilename.txt";
const std::string fileOpeningError = "something went wrong while opening the file.\nEither the file doesn't exists or corrupted.";

int main(int argc, const char** argv) {

	if (argc != 2) {
		std::cout << helpMessageStr << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	if (!inputFile.is_open()) {
		std::cout << fileOpeningError << std::endl;
		return EXIT_FAILURE;
	}

	std::ofstream outputFile;

	return EXIT_SUCCESS;
}