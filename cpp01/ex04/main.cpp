#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " <filename>" << " <occurrence>" << " <replacement>" << std::endl;
        return 1;
    }
    std::ifstream file(av[1]);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << av[1] << std::endl;
        return 1;
    }
    std::string line;
    std::string occurrence = av[2];
    std::string replacement = av[3];
    std::string output;
    if (occurrence.empty() || replacement.empty()) {
        std::cerr << "Error: occurrence or replacement must not be empty\n";
        return 1;
    }
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(occurrence, pos)) != std::string::npos) {
            line.erase(pos, occurrence.length());
            line.insert(pos, replacement);
            pos += replacement.length();
        }
        output += line + '\n';
    }
    file.close();
    
    std::string outfileName = std::string(av[1]) + ".replace";
    std::ofstream outfile(outfileName.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error creating file: " << outfileName << std::endl;
        return 1;
    }
    outfile << output;
    outfile.close();
    return 0;
}
