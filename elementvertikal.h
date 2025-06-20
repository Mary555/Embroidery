#ifndef ELEMENTVERTIKAL_H
#define ELEMENTVERTIKAL_H

#include <QWidget>

namespace Ui {
class ElementVertikal;
}

class ElementVertikal : public QWidget
{
    Q_OBJECT

public:
    explicit ElementVertikal(QWidget *parent = nullptr);
    ~ElementVertikal();

    void addWidget(QWidget *parent);

private:
    Ui::ElementVertikal *ui;
};

#endif // ELEMENTVERTIKAL_H
