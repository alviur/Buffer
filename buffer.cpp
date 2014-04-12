#include "buffer.h"
#include "ui_buffer.h"

Buffer::Buffer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buffer)
{
    ui->setupUi(this);
    //Iniciar tiempo de actualizacion
      FPS=30;
      QTimer *timer = new QTimer(this);
      connect(timer, SIGNAL(timeout()), this, SLOT( actualizarFrame()));
      timer->start(FPS);

      video.open("/home/lex/Cv/Videos/monterrey6.avc");//carga video a usar
      intTamanoVector=10;
      contPosicionBuffer=0;


}

Buffer::~Buffer()
{
    delete ui;
}

/********************************************************************
Fecha de terminación:
Autor:Alexander Gomez Villa
Nombre de metodo: actualizarFrame
Descripción: se llama cada 33 milisegundos para actualizar la imagen que
se procesa
Parámetros de entrada(con explicación cada un de para que se usara):
Parámetros de salida(con explicación cada un de para que se usara):
**********************************************************************/


Buffer::actualizarFrame()
{

   if(imgFrameActual)
   {
        imgFrameActual.copyTo(imgFrameAnterior);//copia actual en el anterior
   }

   contPosicionBuffer++;
   video>>imgFrameActual; //actualizacion imagen


   imgFrameActual.copyTo(vectBufferPrincipal[contPosicionBuffer]);



}




//Cambio del tamaño del buffer
void Buffer::on_spinBox_valueChanged(int arg1)
{
    intTamanoVector=arg1;

}
