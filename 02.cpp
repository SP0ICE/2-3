#include <iostream>
#include <fstream>

class Road {
public:
    double length;
    uint8_t width;
    Road();
    Road(double newLength, uint8_t newWidth);
    void readFromFile(const std::string& filename);
};

Road::Road() {
    length = 0.0;
    width = 0;
}

Road::Road(double newLength, uint8_t newWidth) {
    length = newLength;
    width = newWidth;
}

void Road::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    file >> length >> width;
    file.close();
}

int main() {
    using namespace std;
    cout << "test v2.01: OK. \n";
    Road road;
    Road road1(500, 4);
    Road* road2 = new Road(999, 5);
    cout << "road2 " << &road2 << "\n";
    cout << "road2.length: " << (*road2).length << "\n";
    cout << "road2.width: " << +road2->width << "\n";
    cout << "Values in constructor: \n";
    cout << "road.length: " << road.length << "\n";
    cout << "road.width: " << +road.width << "\n";

    road.readFromFile("input.txt"); 
    cout << "\nValues from file: \n";
    cout << "road.length: " << road.length << "\n";
    cout << "road.width: " << +road.width << "\n";

    road.length = 300;
    road.width = 3;
    cout << "\nValues in main: \n";
    cout << "road.length: " << road.length << "\n";
    cout << "road.width: " << +road.width << "\n";
    cout << "\nroad1.length: " << road1.length << "\n";
    cout << "road1.width: " << +road1.width << "\n";

    return 0;
}