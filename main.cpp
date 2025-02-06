#include <iostream>
#include <string>
#include <fstream>

//////////////////////////////////////////
// MADE BY OGAN OEZKUL (AKA RYUGUU CHAN) //
//////////////////////////////////////////

const std::string helpMessageStr	= "you should specify a filename like so\n\nhtmlentities yourfilename.txt";
const std::string fileOpeningError	= "something went wrong while opening the file.\nEither the file doesn't exists or corrupted.";
const std::string fileCreationError = "something went wrong while creating the result.html file!";

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

	std::string line;
	std::string output;

	while (std::getline(inputFile, line)) {
		for (int i = 0; i < line.length(); i++) {
			switch (line[i])
			{
				case '<':  output += "&lt;";   break;
				case '>':  output += "&gt;";   break;
				case '&':  output += "&amp;";  break;
				case '"':  output += "&quot;"; break;
				case '\'': output += "&apos;"; break;
				default:   output += line[i];  break;
			}
		}
		output += "\n";
	}

	line.clear();
	inputFile.close();

	std::ofstream outputFile("result.html");
	if (!outputFile.is_open()) {
		output.clear();
		std::cout << fileCreationError << std::endl;
		return EXIT_FAILURE;
	}

	outputFile << output;
	outputFile.close();

	std::cout << "the file has been generated as \"result.html\"" << std::endl;

	return EXIT_SUCCESS;
}