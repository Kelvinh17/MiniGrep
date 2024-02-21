#include <iostream>
#include <fstream>
#include <string>

//Colores 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
    std::ifstream file("programacion.txt");
    std::string word = "programacion"; //Escoje la palabra que quieres buscar 
    std::string text;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            text += line + "\n";
        }
        file.close();

        size_t pos = text.find(word);
        while (pos != std::string::npos) {
            text.replace(pos, word.length(), BLUE + word + RESET); //Aqui puedes cambiar el color
            pos = text.find(word, pos + 4 + word.length());
        }

        std::cout << text << std::endl;
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    return 0;
}

