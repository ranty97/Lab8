#include <iostream>
#include "tasks/benchmark.h"
#include "tasks/DNS.h"
#include "etc/Menu.h"

int main(int argc, char** argv) {
    if(argc < 2){
        std::cout << "Configure file path";
        return 0;
    }

    MenuElement elements[] = { {"Benchmark", checkPerformance}, {"Read N lines", readDataFromFile}, {"Print table", printTable}, {"Find IP address", findIP}, {"Add record", addRecord}, {"Delete record", deleteRecord}, {"Delete record by value", deleteByValue}, {"Save to file", saveHashmapToFile} };
    Menu menu = { elements, sizeof(elements) / sizeof(elements[0]) };
    startMenu(menu, argv[1]);
}
