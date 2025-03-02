# +подключаем -не подключаем модули
# core gui - модули qt
QT += core
QT -= gui

# стандарт языка, год принятия
CONFIG += c++11

# цель сборки
TARGET = Lab_1
# в консоли
CONFIG += console
# - mac
CONFIG -= app_bundle

# шаблон
TEMPLATE = app

# файлы из которых строится приложение
SOURCES += main.cpp

#  (макросы)
# сообщения от компилятора при сборке приложения, можно выключить, сейчас включены
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
