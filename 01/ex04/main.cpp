#include <iostream>
#include <fstream>

static void replace(std::string &str, const std::string &target, const std::string &replacement)
{
    size_t targetLength = target.length();
    size_t replacementLength = replacement.length();

    size_t pos = 0;
    while ((pos = str.find(target, pos)) != std::string::npos)
    {
        str.erase(pos, targetLength);
        str.insert(pos, replacement);
        pos += replacementLength;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cerr << "Missing arguments" << std::endl;
        return 1;
    }

    if (argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];

    std::fstream inputFile;
    inputFile.open(argv[1], std::ios::in);
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open input file" << std::endl;
        return 1;
    }

    std::fstream outputFile;
    outputFile.open((inputFileName + ".replace").c_str(), std::ios::out);
    if (!outputFile.is_open())
    {
        std::cerr << "Could not open output file" << std::endl;
        return 1;
    }

    std::string target = argv[2];
    std::string replacement = argv[3];
    while (!inputFile.eof())
    {
        std::string line;
        std::getline(inputFile, line);
        replace(line, target, replacement);
        outputFile << line << std::endl;
    }
}
