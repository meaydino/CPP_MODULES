#include <fstream>
#include <iostream>
#include <random>
#include <string>

int main()
{
    const int count = 3000;
    const std::string outputFile = "numbers.txt";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000000);

    std::ofstream out(outputFile);
    if (!out)
    {
        std::cerr << "Dosya acilamadi: " << outputFile << std::endl;
        return 1;
    }

    for (int i = 0; i < count; ++i)
        out << dist(gen) << " ";

    out.close();
    std::cout << count << " adet sayi " << outputFile << " dosyasina yazildi." << std::endl;
    return 0;
}
