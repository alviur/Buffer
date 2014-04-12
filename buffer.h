/********************************************************************
Fecha de terminación:
Autor: Alexander Gomez - German Diez - Sebastian Guzman
Nombre de clase:Buffer
Descripción:
**********************************************************************/

#ifndef BUFFER_H
#define BUFFER_H

#include <QMainWindow>
#include<opencv2/opencv.hpp>
#include<stdio.h>
#include <QTimer>

using namespace std;
using namespace cv;

namespace Ui {
class Buffer;
}

class Buffer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Buffer(QWidget *parent = 0);
    ~Buffer();

    int  intTamanoVector;//sera el tamaño del buffer
    int contPosicionBuffer;//lleva la cuenta de la posicion actual de buffer
    std::vector<cv::Mat> vectBufferPrincipal; //vector que cotiene el buffer principal
    cv::capture video;//video procesado
    cv::Mat imgFrameActual;
    cv::Mat imgFrameAnterior;



    //actualizacion Video

     QTimer* tmrTimer;
     int     FPS;//frames por segundo


public slots:


     //Metodo de actualizacion

      void actualizarFrame();


    
private slots:
      void on_spinBox_valueChanged(int arg1);

private:
    Ui::Buffer *ui;
};

#endif // BUFFER_H
