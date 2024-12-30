def playing_field(arr) #Вывод игрового поля на экран. С англ. Игровое поле
  for i in 0..8
    if i == 1 or i == 4 or i == 7
      print " | "  
      print arr[i]  
      print " | "
    else
      print arr[i]  
    end
    if i == 2 or i == 5
            puts "\n-----------"
    end 
  end
end
#основной код
Background_of_playing_field = ["1","2","3", "4","5","6", "7","8","9"] #с англ.Фон игрового поля 
player = "x" #иксы ходят первыми(условно)
counter = 0 #счётчик для обнаружения перегру3ки
while true
  counter = 0 #сброс счётчика
  playing_field(Background_of_playing_field) #Вывод игрового поля на экран
  print "\n", player, " ходят \n", "> " 
  players_turn = (gets.to_i) - 1 #с англ. ход игрока
  system("cls")   #очистка экрана
  if ((Background_of_playing_field[players_turn] != "x") and (Background_of_playing_field[players_turn] != "0")) 
    Background_of_playing_field[players_turn] = player #присвоение 3аднику 3начения
  else
    puts "Клетка 3анята!"
    redo
  end
 
  if (((Background_of_playing_field[0] == player) and (Background_of_playing_field[1] == player) and (Background_of_playing_field[2] == player)) or #Проверка условий победа
    ((Background_of_playing_field[3] == player) and (Background_of_playing_field[4] == player) and (Background_of_playing_field[5] == player)) or
    ((Background_of_playing_field[6] == player) and (Background_of_playing_field[7] == player) and (Background_of_playing_field[8] == player)) or 
    ((Background_of_playing_field[0] == player) and (Background_of_playing_field[3] == player) and (Background_of_playing_field[6] == player)) or
    ((Background_of_playing_field[1] == player) and (Background_of_playing_field[4] == player) and (Background_of_playing_field[7] == player)) or
    ((Background_of_playing_field[2] == player) and (Background_of_playing_field[5] == player) and (Background_of_playing_field[8] == player)) or
    ((Background_of_playing_field[0] == player) and (Background_of_playing_field[4] == player) and (Background_of_playing_field[8] == player)) or
    ((Background_of_playing_field[6] == player) and (Background_of_playing_field[4] == player) and (Background_of_playing_field[2] == player)) )
    print player, " победил!\n"
    playing_field(Background_of_playing_field) #Вывод игрового поля на экран
    puts " "
    system("pause")
    exit
  end
  for i in 0..8 #проверка на перегру3ку
      if   (Background_of_playing_field[i] == "x") or  (Background_of_playing_field[i] == "0")
        counter += 1
      end
      if counter == 9 
        puts "Поле перегруженно! Ничья!"  
        playing_field(Background_of_playing_field) #Вывод игрового поля на экран
        puts " "
        system("pause")
        exit
      end
  end
  if player == "x" #смена игрока
    player = "0"
  else
    player = "x"
  end
end
