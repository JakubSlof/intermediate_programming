#include <iostream>

void promenne() {
    int cele_cislo = -1;

    unsigned int cele_nezaporne_cislo = 1;

    std::size_t index_v_poli = 0;

    double desetinne_cislo = 3.14;

    char znak = 'a';

    bool pravda_nebo_nepravda = true;

    std::string retezec = "Ahoj";
}

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b ){
    return a - b;
} 

void stars( int number_of_stars){
for (int i = 0; i < number_of_stars; i++){
    std::cout << "*";

}
}

void pyramid(int number_of_lines){
    std::string mezera = " ";
    std::string hvezda = "*";
    int counter = 1;
    int c = number_of_lines;
    for(int i = 0; i < number_of_lines;i++){
        for(int m = 0; m < c ; m++){
            std::cout << mezera;    
        }
        c = c - 1;
        for(int h = 0; h < counter; h++){
            std::cout << hvezda;  
        }
        counter = counter + 2;
        std::cout << std::endl;
    }   
} 

void pyramid1(int number_of_lines){
    std::string hvezda = "*";
    int counter = 0;
    for(int i = 0; i < number_of_lines;i++){
        for(int h = 0; h < counter; h++){
            std::cout << hvezda;  
        }
        counter = counter +1;
        std::cout << std::endl;
    }
    for(int i = 0; i < number_of_lines;i++){
        for(int h = 0; h < counter; h++){
            std::cout << hvezda;  
        }
        counter = counter -1;
        std::cout << std::endl;
    }
}

void rectangle(int number_of_lines, int line_lenght){
    std::string hvezda = "*";
    for(int i = 0; i < number_of_lines;i++){
        for(int h = 0; h < line_lenght; h++){
            std::cout << hvezda;  
        }
        std::cout << std::endl;
    }
}
int a = 0;

void scope() {
    int a = 5; 

    a = 3;

    std::cout << a << std::endl; // 3
    
    {
        int a = 4;
        std::cout << a << std::endl; // 4
        a = 6;
        std::cout << a << std::endl; // 6
    }

    std::cout << a << std::endl; // 3

}

void cykly() {
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    int i = 0;
    while (i < 10) {
        std::cout << i << std::endl;
        i++;
    }

    i = 0;
    do {
        std::cout << i << std::endl;
        i++;
    } while (i < 10);
}

int main() {
    std::cout << a << std::endl;
    scope();
    std::cout << a << std::endl;
    std::cout << sub(2,9) << std::endl;
    stars(10);
    std::cout << std::endl;
    pyramid(30);
    std::cout << std::endl;
    pyramid1(10);
    rectangle(10,5);
    return 0;
    
    

}
