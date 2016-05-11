QT += core
QT -= gui

CONFIG += c++11

TARGET = TranslatableApplication
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

TRANSLATIONS += \
    translations/TranslatableApplication_en.ts \
    translations/TranslatableApplication_de.ts

RESOURCES += \
    translations.qrc
