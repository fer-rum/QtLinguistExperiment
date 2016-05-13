#include <QtGlobal>
#include <QCoreApplication>
#include <QObject>
#include <QString>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <iostream>

void printIdBasedText(){


    //% "Greetings"
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
    // note the different ways of loading translators
    translatorDE.load(":/translations/translations/TranslatableApplication_de.qm");
    translatorEN.load(QLocale(QLocale::English, QLocale::UnitedKingdom),
                      "TranslatableApplication", "_",
                      ":/translations/translations/", ".qm");

    std::cout << "=== Switching language to german ===" << std::endl;

    app.installTranslator(&translatorDE);
    printIdBasedText();

    std::cout << "=== Switching language to english ===" << std::endl;

    app.installTranslator(&translatorEN);
    printIdBasedText();


    std::string input;

    std::cout << "=== Live input ===" << std::endl;
    std::cout << "Type \"text_magic\" and watch stuff happen: ";
    std::cin >> input;

    std::cout << qtTrId(input.c_str()).toStdString() << std::endl;

    // show off multiple contexts not available in id-based mode
    // try composite strings

    std::string composite = QString("%1_%2").arg("text").arg("magic").toStdString();

    std::cout << "=== Composite id ===" << std::endl;
    std::cout << composite << " = "
              << qtTrId(composite.c_str()).toStdString()
              << std::endl;

    // show translation of multiplicities
    for(int i = 0; i < 10; i++){

        QString toPrint = qtTrId("%n apple", i);
        std::cout <<  toPrint.toStdString() << std::endl;
    }


    return 0;
}
