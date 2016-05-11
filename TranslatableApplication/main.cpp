#include <QtGlobal>
#include <QCoreApplication>
#include <QObject>
#include <QString>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <iostream>

void printDirectText(){

    QString directText = QObject::tr("Hello World!");
    std::cout << "Direct text: " << directText.toStdString() << std::endl;
}

void printIdBasedText(){

    QString idText = qtTrId("text_greeting");
    std::cout << "Replaced Id: " << idText.toStdString() << std::endl;
}


// NOTE you can not mix id-based and direct translation!
// what you can use depends on whether you pass "-idbased" to lrelease or not.
// c.f. http://doc.qt.io/qt-5/linguist-id-based-i18n.html


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTranslator translatorDE;
    QTranslator translatorEN;

    // loading translation files from ressources
    translatorDE.load(":/translations/translations/TranslatableApplication_de.qm");
    translatorEN.load(":/translations/translations/TranslatableApplication_en.qm");

    app.installTranslator(&translatorDE);

    // TODO show off multiple contexts
    // TODO try composite strings
    // TODO show translation of multiplicities

    printDirectText();
    printIdBasedText();

    std::cout << "=== Switching language to english ===" << std::endl;

    app.installTranslator(&translatorEN);
    printDirectText();
    printIdBasedText();

    return 0;
}
