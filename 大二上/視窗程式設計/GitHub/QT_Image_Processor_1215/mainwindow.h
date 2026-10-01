#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QImage>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString filename);

private slots:
    void showOpenFile();
    void zoon_in();
    void zoon_out();

private:
    QWidget     *central;
    QMenu       *fileMenu;
    QMenu       *fileMenuTools;
    QToolBar    *fileTool;
    QAction     *openFileAction;
    QAction     *exitAction;
    QAction     *zoonInAction;
    QAction     *zoonOutAction;

    QImage      img;
    QLabel      *imgWin;
    QString     filename;
};
#endif // MAINWINDOW_H
