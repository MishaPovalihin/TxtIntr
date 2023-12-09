#include <iostream>
#include <cmath>
#include <string>
#define _USE_MATH_DEFINES 
#include <cmath>

using namespace std;

void Instruction(int argc, char* argv[]) {
    cout << "Поддерживаемые операции:" << endl;
    cout << "  -t grad 'x'   (Значение тангенса в градусах)" << endl;
    cout << "  -c grad 'x'   (Значение котангенса в градусах)" << endl;
	cout << "  -t rad 'x'   (Значение тангенса в радианах)" << endl;
	cout << "  -c rad 'x'   (Значение котангенса в радианах)" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Калькулятор тангенсов и котангенсов" << endl;
        Instruction(argc, argv);
        return 1;
    }

    string operation = argv[1];
	string operationType = argv[2]; 
	double operand = stod(argv[3]);
    if (operation == "-t" && argc > 2) { 
        if (operationType == "grad") {
            cout << "Результат: " << tan((operand*M_PI)/180) << endl;
        } else if (operationType == "rad") {
            cout << "Результат: " << tan(operand) << endl;
        } else {
            cout << "Неподдерживаемая операция! " << operationType << endl;
            Instruction(argc, argv);
            return 1;
        }
    }
	else if (operation == "-c" && argc > 2) { 
			if (operationType == "grad") {
				cout << "Результат: " << 1/(tan((operand*M_PI)/180)) << endl;
			} else if (operationType == "rad") {
				cout << "Результат: " << 1/(tan(operand)) << endl;
			} else {
				cout << "Неподдерживаемая операция! " << operationType << endl;
				Instruction(argc, argv);
				return 1;
			}
	}else {
        cout << "Неправильный формат команды." << endl;
        Instruction(argc, argv);
        return 1;
    } 
    
    return 0;
}
