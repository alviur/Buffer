#include "buffer.h"
#include "ui_buffer.h"

Buffer::Buffer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buffer)
{
    ui->setupUi(this);
}

Buffer::~Buffer()
{
    delete ui;
}
