# Laboratory work. Windows console.

> Win+R cmd

![screen_1_win_r.png](pictures/screen_1_win_r.png)

```bash
date
time
```

>Проверка даты и времени. Позволяют проверить и изменить при наличии прав дату и время на хосте.

![screen_2_date_time.png](pictures/screen_2_date_time.png)

>Смена директории. Команда pwd показывает в какой папке сейчас находимся.

![screen_3_folder_test.png](pictures/screen_3_folder_test.png)

>Создание файла в консоли, редактирование и запись. Для завершения редактирования ctrl+z.

![screen_4_copycon.png](pictures/screen_4_copycon.png)

```bash
copy con File.txt
dir
```

>Копирование файла File.txt в каталог Cat с именами File1.txt File2.txt. Объединение скопрированных файлов File1.txt и File2.txt в oneFile.txt Перемещение файла oneFile.txt в папку Test.

![screen_5_copy_files.png](pictures/screen_5_copy_files.png)
![screen_6_copy_files_dir.png](pictures/screen_6_copy_files_dir.png)
![screen_7_move.png](pictures/screen_7_move.png)

```bash
copy File.txt Cat\File1.txt
copy File.txt Cat\File2.txt
copy Cat\File1.txt+Cat\File2.txt Cat\oneFile.txt
move Cat\oneFile.txt oneFile.txt
type oneFile.txt
dir
```

>Переименование файлов и расширений командой rename.

![screen_8_rename.png](pictures/screen_8_rename.png)
![screen_9_rename_dir.png](pictures/screen_9_rename_dir.png)

```bash
rename oneFile.txt newFile.txt
cd Cat
rename *.txt *.cmd
dir
dir Cat
```

