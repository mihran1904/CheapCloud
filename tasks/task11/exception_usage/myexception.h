#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <QException>
class MyException : public QException
{
public:
    MyException(const QString &message);
    const QString &getMsg() const;
    void raise() const override;
    MyException *clone() const override;
private:
    QString m_message;
};

#endif // MYEXCEPTION_H
