#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actioncut_triggered();

    void on_actionUndo_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionAbout_triggered();

    void on_actionCopy_triggered();

    void on_actionRedo_triggered();

    void on_actionPaste_triggered();

private:
    Ui::MainWindow *ui;
    QString File_path;
};

#endif // MAINWINDOW_H
