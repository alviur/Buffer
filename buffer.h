#ifndef BUFFER_H
#define BUFFER_H

#include <QMainWindow>

namespace Ui {
class Buffer;
}

class Buffer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Buffer(QWidget *parent = 0);
    ~Buffer();
    
private:
    Ui::Buffer *ui;
};

#endif // BUFFER_H
