#include <iostream>
#include <fstream>
#include <array>
#include <numeric>

void updateMaxCalories(std::array<int, 3>& topThreeCalories, int currentElfCalories) {
    int tmp = 0;

    for (int i = 0; i < topThreeCalories.size(); ++i) {
        if (topThreeCalories[i] < currentElfCalories) {
            tmp = topThreeCalories[i];
            topThreeCalories[i] = currentElfCalories;
            currentElfCalories = tmp;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "No input file provided." << std::endl;
        return -1;
    }

    std::ifstream inputFile(argv[1]);
    std::string line;
    std::array<int, 3> topThreeCalories = {0, 0, 0};
    int currentElfCalories = 0;


    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            if (line.size() == 0) {
                updateMaxCalories(topThreeCalories, currentElfCalories);
                currentElfCalories = 0;
            } else {
                currentElfCalories += std::stoi(line);
            }
        }
        inputFile.close();
    }

    int caloriesSum = std::accumulate(topThreeCalories.begin(), topThreeCalories.end(), 0);

    std::cout << "Max calories carried by the top three elves: "
              << topThreeCalories[0] << ", "
              << topThreeCalories[1] << ", "
              << topThreeCalories[2] << "; "
              << "Sum = " << caloriesSum
              << std::endl;
    
    return 0;
    
}