#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>

class QDynamicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    static int ResID;   // Статическая переменная, счетчик номеров кнопок
    int getID();        // Функция для возврата локального номера кнопки

private:
    int buttonID = 0;   // Локальная переменная, номер кнопки
};

#endif // CELLBUTTON_H
