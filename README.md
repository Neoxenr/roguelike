## Фичи игры
1) В комнате каждого уровня находятся одиночные или длинные стены, при этом уровень проходимый.
2) Игра цветная. Цвета используются как для текста, так и для символов.
3) Появились враги, которые отображаются символов E. При столкновении игрока с врагом происходит бой и у игрока отнимается здоровье. Враги пока что умеют ходить горизонтально. На уровне может находится вплоть до 3-х врагов.


## BearLibTerminal demo
   BearLibTerminal — это небольшая в интерфейсном плане библиотека для организации терминал-подобного окна, вывода текста, обработки простого ввода.
   Большое количество roguelike совершенно осознанно используют аскетичное символьное/псевдографическое оформление. 
   Однако, использование стандартных средств вывода посредством командной строки ОС сопряжено с досадными ограничениями скорости вывода, цветовой гаммы, используемого шрифта. 
   Нередко проблемы вызывает применение расширенного набора символов, например одновременно нескольких языков и/или псевдографики. 
   BearLibTerminal позволяет обойти упомянутые ограничения, предоставляя собственное окно с прямоугольной сеткой ячеек-знакомест и лаконичный, но мощный API для вывода отдельных символов и текста.
   
## Как запустить демку
   Запустите из терминала команду make - она сделает всю магию:
   
   почистит проект (make clean)
   проинициализирует cmake (make reload)
   проверит код на соответсвие style-guide (make lint)
   скомпилимрует исходники (make build)
   запустит приложение (make exec)
   
## Структура проекта


src - cpp исходники приложения

include - хедеры .h приложения (в данном проекте их нет, поскольку он очень простой)

misc - тут лежит cpplint, который проверяет код на соответсвие style-guide

lib - тут лежат вспомогательные библиотеки, в том числе скомпилированные части

CMake- вспомогательные скрипты для системы сборки cmake

CMakeLists.txt - основной скрипт описания сборки приложения

Makefile - вспомогательные скрипты запуска, сборки приложения

.clang-format - описание стиля кода в проекте

.editorconfig - конфигурация отступов для редактора кода