#ifndef REGISTR_I_AUTH_H
#define REGISTR_I_AUTH_H

#include <QWidget>

namespace Ui {
class registr_i_auth;
}

class registr_i_auth : public QWidget
{
    Q_OBJECT

signals:
    void auth(QString log, QString pass);
    void reg(QString log, QString pass, QString email);

public:
    explicit registr_i_auth(QWidget *parent = nullptr);
    ~registr_i_auth();

private slots:
    void on_authknopka_clicked();

    void on_regknopka_clicked();

    void on_cozdat_clicked();

    void on_voyti_clicked();

private:
    Ui::registr_i_auth *ui;
};

#endif // REGISTR_I_AUTH_H
