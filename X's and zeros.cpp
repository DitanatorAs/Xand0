#include <iostream> 
auto show_playing_filed(char arr[9]){ //вывод игрового поля в консоль
         for (int i = 0; i < 7;i = i + 3) {
            std::cout << 
            arr[i] << " | " << arr[i + 1] << " | " << arr[i + 2]
            << std::endl;
            if (i < 6) std::cout 
                << "---------"
                << std::endl; 
    }
}

int main(){
    system("chcp 65001 > nul"); //изменение кодировки в консоли
    char 
        Background_of_playing_field[9] = //с англ.Фон игрового поля 
        {' ', ' ', ' ', //изначальный вид игрового поля
        ' ', ' ', ' ',
        ' ', ' ', ' '}, 
        current_course = 'x'; //с англ. текущий ход. 
    int combinations[8][3] = //комбинации для победы
        {{0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}, 
        {0, 3, 6}, 
        {1, 4, 7}, 
        {2, 5, 8}, 
        {0, 4, 8}, 
        {2, 4, 6}},
        motion, // c англ. ход
        counter; // с англ. счётчик 

    while (true) {
        counter = 0; //сброс счётчика
        std::cout << current_course << " ходят\n\n";
        show_playing_filed(Background_of_playing_field);
        std::cout << "\nХоди\n >";
        std::cin >> motion; //игрок выбирает клетку, куда будет ходить
        system("cls");
        if ((std::cin.fail()) || ((motion > 9) || (motion < 1))){ //конструкция на случай, если пользователь ввёл не то
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Внимание! Вводите только номер клетки, куда собираетесь ходить (начиная с 1 и заканчивая 9)" << std::endl;
            continue;
        }
        if (Background_of_playing_field[motion - 1] != '0' & //проверка на то, не занята ли клетка
        Background_of_playing_field[motion - 1] != 'x') {
            Background_of_playing_field[motion - 1] = current_course;
        }
        else{
            std::cout << "Кто то уже сделал ход сюда(" <<  Background_of_playing_field[motion - 1] << ")" << std::endl;     
            continue;
        }
        for (int i = 0; i < 8; ++i){
                if (Background_of_playing_field[combinations[i][0]] == current_course & //Проверка условий победы
                Background_of_playing_field[combinations[i][1]] == current_course & 
                Background_of_playing_field[combinations[i][2]] == current_course ){
                    std::cout << "Игрок " << current_course << " победил!\n";
                    show_playing_filed(Background_of_playing_field);
                    system("pause");
                    return 0;
                }
        }
        for (int i = 0; i < 9; ++i){ //проверка на перегрузку 
            if(Background_of_playing_field[i] != ' '){
                counter++;
            }
            if (counter == 9){ //условия перегрузки
                std::cout << "Поле перегруженно! Ничья!" << std::endl;
                show_playing_filed(Background_of_playing_field);
                system("pause");
                return 0;
            }
        }
        if (current_course =='x'){ //рокировка
            current_course = '0';
        }
        else{
            current_course = 'x';
        }
    }
} 