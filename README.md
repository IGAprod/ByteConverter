### Работа приложения
Приложение работает слудующим образом:

1. Класс ```Source``` читатет байты в заданном формате из файла

2. Класс ```ByteCodeConverter``` запускает отдельный поток для конвертации полученных байт в символы. Для этого на каждой итерации цикла запрашивается блок данных (8 байт) у ```Source```, даннные байты конвертируются и передаются в класс ```Sink```, который в свою очередь получает строку и записывает ее в файл.

3.  Поток прекращает выполнение если либо не останется данных для обработки, либо был вызван метод остановки конвертации у класса ```ByteCodeConverter::stop_convert_bytes```

Структура проекта:

```
├── Google_tests
├── main.cpp
├── resources
│   ├── Source
│   │   ├── data.bin
│   │   └── save.txt
│   └── Test
│       ├── data_test.bin
│       └── save_test.txt
├── Sources
│   ├── ByteCodeConverter
│   │   ├── ByteCodeConverter.cpp
│   │   └── ByteCodeConverter.h
│   └── Utilities
│       ├── Utilities.cpp
│       └── Utilities.h
└── Test
    ├── CMakeLists.txt
    ├── convert_test.cpp
    └── convert_test.h
```

1. Исходные коды программ расположены в директории ```Sources```
2. Исходные коды тестов расположены в директории ```Test```
3. Файлы расположены в директории ```resources```

### Тесты

Были реализованы следующе тесты с использованием библиотеки GoogleTest:

1. Тест ```Convert``` проверет правильно ли считываются, конвертируются и сохраняются данные. В качестве входных данных выступает различиные вариации байтов (целочисленное беззнаковое число, знакове целочисленное, буква) и на выходе проверяется полученная строка с ожидаемой.

2. Тест ```ConvertWithBrokenBytes``` проверят работу метода если в файле есть байты, которые не соотвествуют формату (данные байты должны быть пропущены).

3. Тест ```StopConvert``` проеряет остановку потока конвертации байт

### Заметки

1. К сожалению, сейчас захардкожены пути к файлам. Необходимо в коде прописывать абсолютный путь в файлах ```convert_test.cpp``` и  ```main.cpp```

2. Также я загрузил GoogleTest с репозитория https://github.com/google/googletest. Необходио будет в данной директории сбилдить googlemock и googletest.

3. Для запуска тестов необходимо отдельно собирать проект в самой папке Test.
