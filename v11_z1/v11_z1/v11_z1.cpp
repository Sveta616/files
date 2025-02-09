// v11_z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Person {
    char surname[50];
    char gender;
    union {
        int year;
        struct {
            bool isMarried;
            int children;
        } male;
    } details;
};

int main() {
    int sort = 2;
    Person persons[50];
    int count = 0;

    while (true) {
        std::cout << "Choose action:\n0. Add person\n1. Show single men without children\n2. Show all persons\n";
        int action;
        std::cin >> action;

        switch (action) {
        case 0: {
            if (count >= 50) {
                std::cout << "Maximum number of persons reached!\n";
                break;
            }

            Person person;
            std::cout << "Enter surname: ";
            std::cin >> person.surname;

            std::cout << "Enter gender (M/F): ";
            std::cin >> person.gender;

            if (person.gender == 'F' || person.gender == 'f') {
                std::cout << "Enter birth year: ";
                std::cin >> person.details.year;
            }
            else if (person.gender == 'M' || person.gender == 'm') {
                std::cout << "Is married? (1 - yes, 0 - no): ";
                std::cin >> person.details.male.isMarried;

                std::cout << "Enter number of children: ";
                std::cin >> person.details.male.children;
            }
            else {
                std::cout << "Error of gender\n";
                continue;
            }

            persons[count] = person; 
            count++;
            std::cout << "Person added\n";
            break;
        }
        case 1: {
            Person singleMen[50];
            int count = 0;


            for (int i = 0; i < count; i++) {
                if ((persons[i].gender == 'M' || persons[i].gender == 'm') &&
                    !persons[i].details.male.isMarried &&
                    persons[i].details.male.children == 0) {
                    singleMen[count++] = persons[i];
                }
            }

   
            int sort= count;
            while (sort--) {
                bool swapped = false;

                for (int i = 0; i < sort; i++) {

                    int k = 0;
                    while (singleMen[i].surname[k] == singleMen[i + 1].surname[k] &&
                        singleMen[i].surname[k] != '\0' &&
                        singleMen[i + 1].surname[k] != '\0') {
                        k++;
                    }

                    if (singleMen[i].surname[k] > singleMen[i + 1].surname[k]) {
                        Person temp = singleMen[i];
                        singleMen[i] = singleMen[i + 1];
                        singleMen[i + 1] = temp;

                        swapped = true;
                    }
                }

                if (!swapped) {
                    break;
                }
            }

            std::cout << "Sorted list of single men without children:\n";
            for (int i = 0; i < count; i++) {
                std::cout << "Surname: " << singleMen[i].surname << "\n";
            }
            break;
        }
        case 2: {
            std::cout << "All persons:\n";
            for (int i = 0; i < count; i++) {
                std::cout << "Surname: " << persons[i].surname << ", Gender: " << persons[i].gender << "\n";
            }
            break;
        }
       
        default: {
            std::cout << "Error\n";
            break;
        }
        }
    }
  
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
