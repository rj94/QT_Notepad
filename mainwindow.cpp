#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString File_open = QFileDialog::getOpenFileName(this,"Open The File");
    QFile file(File_open);
    File_path = File_open;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","File Not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionNew_triggered()
{
    File_path = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionSave_triggered()
{
//    QString File_open = QFileDialog::getSaveFileName(this,"Open The File");
    QFile file(File_path);              //File_path global variable contain the dat of already open file
    if(!file.open(QFile::WriteOnly| QFile::Text))
    {
        QMessageBox::warning(this,"..","File Not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
        QString File_open = QFileDialog::getSaveFileName(this,"Open The File");
        QFile file(File_open);
        File_path = File_open;              //File_path global variable contain the dat of already open file
        if(!file.open(QFile::WriteOnly| QFile::Text))
        {
            QMessageBox::warning(this,"..","File Not open");
            return;
        }
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.flush();
        file.close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionFont_triggered()
{
    bool font_is_ok;
    QFont font = QFontDialog::getFont(&font_is_ok,this);
    if(font_is_ok)
    {
        ui->textEdit->setFont(font);
    }
    else
    {
        return;
    }
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
//        QMessageBox::information(this,"color is not valid");
        return;
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QString about;
    about =  "Author  : Rahul\n";
    about += "App     : NotePad\n";
    about += "Version : 00.00.01";
    QMessageBox::about(this,"About Notepad",about);
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
