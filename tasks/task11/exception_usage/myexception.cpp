#include "myexception.h"

MyException::MyException(const QString &message) : m_message{message} {}

const QString &MyException::getMsg() const {
    return m_message;
}

void MyException::raise() const {
    throw *this;
}

MyException* MyException::clone() const {
    return new MyException(*this);
}
