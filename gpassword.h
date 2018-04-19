#ifndef GPASSWORD_H
#define GPASSWORD_H
#include <QLineEdit>
#include <QWidget>

class GPassword : public QWidget
{
    Q_OBJECT
public:
    explicit GPassword(QWidget *parent = 0);
    QString text();
private:
        QLineEdit* lineEditPasswd;
        ~GPassword();
signals:

public slots:
        void boutonPresse();


};

#endif // GPASSWORD_H
