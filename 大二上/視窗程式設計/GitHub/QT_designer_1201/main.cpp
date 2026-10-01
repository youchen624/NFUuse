#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Apply dark theme stylesheet
    QString darkStyle = R"(
        QMainWindow {
            background-color: #2b2b2b;
        }
        QMenuBar {
            background-color: #3c3f41;
            color: #bbbbbb;
            border-bottom: 1px solid #4e5254;
        }
        QMenuBar::item {
            background-color: transparent;
            padding: 4px 10px;
        }
        QMenuBar::item:selected {
            background-color: #4e5254;
        }
        QMenuBar::item:pressed {
            background-color: #4e5254;
        }
        QMenu {
            background-color: #3c3f41;
            color: #bbbbbb;
            border: 1px solid #4e5254;
        }
        QMenu::item {
            padding: 5px 30px 5px 20px;
        }
        QMenu::item:selected {
            background-color: #4e5254;
        }
        QMenu::separator {
            height: 1px;
            background: #4e5254;
            margin: 5px 0px;
        }
        QStatusBar {
            background-color: #3c3f41;
            color: #bbbbbb;
        }
        QWidget {
            background-color: #2b2b2b;
            color: #bbbbbb;
        }
        QPushButton {
            background-color: #4e5254;
            color: #bbbbbb;
            border: 1px solid #5e6164;
            padding: 5px 15px;
            border-radius: 3px;
        }
        QPushButton:hover {
            background-color: #5e6164;
        }
        QPushButton:pressed {
            background-color: #3c3f41;
        }
        QLabel {
            color: #bbbbbb;
        }
        QTextEdit {
            background-color: #2b2b2b;
            color: #bbbbbb;
            border: 1px solid #4e5254;
        }
        QLineEdit {
            background-color: #2b2b2b;
            color: #bbbbbb;
            border: 1px solid #4e5254;
            padding: 3px;
        }
        QMessageBox {
            background-color: #3c3f41;
        }
    )";

    a.setStyleSheet(darkStyle);

    MainWindow w;
    w.show();
    return a.exec();
}
