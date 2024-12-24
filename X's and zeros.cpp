#include <iostream>
auto  playing_field(char array[3][3]){ // c англ. игровое поле.
     for (int i = 0; i < 3; ++i) {
            std::cout << array[i][0] << " | " << array[i][1] << " | " << array[i][2] << std::endl;
            if (i < 2) std::cout << "---------\n"; 
        }
}
int main(){
    system("chcp 65001 > nul"); 
    char  
        main_field[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}, // с анг. главное поле.  
        motion = 'x'; // с англ. ход.
    int 
        row, // с англ. ряд.
        column, // с англ. столбец.
        counter; // с англ. счётчик.
    while (true){
        counter = 0; //сброс счётчика
        playing_field(main_field);
        std::cout << "Введите ряд: ";
        std::cin >> row;
        std::cout <<  "Введите столбец: ";
        std::cin >> column;
        system("cls");
        if ((main_field[row-1][column-1] != 'x') & (main_field[row-1][column-1] != '0')) { //Проверка, на то, есть ли в данной ячейки крестик или нолик
            main_field[row-1][column-1] = motion;
        }
        else{
            std::cout << "Кто-то уже поставил сюда свой крестик или нолик" << std::endl;
            continue;
        }
        for (int i = 0; i < 3; ++i) { 
            if ((main_field[i][0] == motion && main_field[i][1] == motion && main_field[i][2] == motion) || (main_field[0][i] == motion && main_field[1][i] == motion && main_field[2][i] == motion)) {//Проверка условий победы 
                std::cout << "Игрок " << motion << " выиграл!" << std::endl;
                playing_field(main_field);
                system("pause");
                return 0;
            }       
        }
        if ((main_field[0][0] == motion && main_field[1][1] == motion && main_field[2][2] == motion) || (main_field[0][2] == motion && main_field[1][1] == motion && main_field[2][0] == motion)) { //Проверка условий победы
                std::cout << "Игрок " << motion << " выиграл!" << std::endl;
                playing_field(main_field);
                system("pause");  
                return 0;
        }
        for (int r = 0; r < 3; ++r){ //Проверка на перегру3ку игрового поля
            for (int c = 0; c < 3; ++c){
                if (main_field[r][c] != ' '){ //r - row,c - column
                    counter++;
                }
                if (counter == 9){ 
                    std::cout << "Поле перегруженно! Ничья!" << std::endl;
                    playing_field(main_field);
                    system("pause");  
                    return 0;
                }
                
            }
        }
  
            if (motion == 'x') { //передача хода следующему игроку
                motion = '0';
                std::cout <<  "Ходят нолики " << std::endl;
            }
            else{
                motion = 'x';
                std::cout <<  "Ходят крестики " << std::endl;
            }
        }
}