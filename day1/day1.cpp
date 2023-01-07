#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("day1.in");
    std::string line;
    int maxCalories = 0;
    int currentElfCalories = 0;

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            if (line.size() == 0) {
                maxCalories = std::max(currentElfCalories, maxCalories);
                currentElfCalories = 0;
            } else {
                currentElfCalories += std::stoi(line);
            }
        }
        inputFile.close();
    }

    std::cout << "Max calories carried by one elf: " << maxCalories << std::endl;
    
    return 0;
    
}