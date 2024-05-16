#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void RSA(QString text);
    void hash(QString text);
    void Delenie(QString  massiv, QString chislo);
    void Graf(QString learningRate, QString maxIterations, QString precision);

public slots:
    void rechenie(QString text);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Reshit_clicked();

    void on_another_clicked();

private:
    Ui::MainWindow *ui;
    enum Task {rsa, sha512, delenie, graf};
    Task currentTask;
};

#endif // MAINWINDOW_H
