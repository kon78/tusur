##подключаемые модули для сборки
#+= здесь используем core, также можно подключать к примеру widgets network sql и другие модули
#-= исключаем gui
QT += core
QT -= gui

#стадарт языка (2011, помоему год принятия)
CONFIG += c++11

#режим debug
#CONFIG(debug, debug|release) {
#    message(===Debug===)
#    SOURCES += main.cpp
#}

#режим release
#CONFIG(release, debug|release) {
#    message(===Release===)
#    SOURCES += main.cpp
#}

#цель сборки, нам нужна консоль, -= app_bundle - для платформы mac
TARGET = task_2_1
CONFIG += console
CONFIG -= app_bundle

#шаблон
TEMPLATE = app

#источники, здесь перечисляются файлы cpp, из которых будет строиться приложение
SOURCES += \
    main_task_2_1.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
