#include "trem.h"
#include <iostream>
#include <QtCore>
#include <QMutex>
#include <QDebug>

QMutex mutex1;
QMutex mutex2;
QMutex mutex3;
QMutex mutex4;
QMutex mutex5;
QMutex mutex6;
QMutex mutex7;

bool isMutex1Lock = false;
bool isMutex2Lock = false;
bool isMutex3Lock = false;
bool isMutex4Lock = false;
bool isMutex5Lock = false;
bool isMutex6Lock = false;
bool isMutex7Lock = false;
//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 200; // Quanto maior mais lento
}

void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (x == 400 && y == 80){
                mutex1.lock();
                isMutex1Lock = true;
                x += 10;
            }
            else if (x == 400 && y == 200){
                mutex1.unlock();
                isMutex1Lock = false;
                x -= 10;
            }
            else if (x == 310 && y == 200){
                mutex2.lock();
                isMutex2Lock = true;
                x -= 10;
            }
            else if (x == 150 && y == 180){
                mutex2.unlock();
                isMutex2Lock = false;
                y -= 10;
            }
            else if (x == 420 && y == 180){
                mutex3.lock();
                y += 10;
            }
            else if (x == 270 && y == 200){
                mutex3.unlock();
                x -= 10;
            }
            else if (y == 80 && x < 420)
                x+=10;
            else if (x == 420 && y < 200)
                y+=10;
            else if (x > 150 && y == 200)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (x == 580 && y == 200){
                if (!isMutex1Lock && !isMutex4Lock){
                    mutex1.lock();
                    isMutex1Lock = true;
                    mutex4.lock();
                    isMutex4Lock = true;
                    x -= 10;
                }
                else{
                    break;
                }

            }
            else if (x == 420 && y == 80 && isMutex1Lock && isMutex4Lock){
                mutex1.unlock();
                isMutex1Lock = false;
                mutex4.unlock();              
                isMutex4Lock = false;
                x += 10;
            }
            else if (x == 690 && y == 180){
                mutex5.lock();
                isMutex5Lock = true;
                y += 10;
            }
            else if (x == 540 && y == 200){
                mutex5.unlock();
                isMutex5Lock = false;
                x -= 10;
            }
            else if (y == 80 && x < 690)
                x+=10;
            else if (x == 690 && y < 200)
                y+=10;
            else if (x > 420 && y == 200)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: // Trem3
            if (x == 130 && y == 200){
                if (!isMutex2Lock && !isMutex6Lock){
                    mutex2.lock();
                    isMutex2Lock = true;
                    mutex6.lock();
                    isMutex6Lock = true;

                    x += 10;
                }
                else{
                    break;
                }
            }
            else if (x == 270 && y == 320){
                if (isMutex2Lock && isMutex6Lock){
                    mutex2.unlock();
                    isMutex2Lock = false;
                    mutex6.unlock();
                    isMutex6Lock = false;

                    x -= 10;
                }
                else{
                    break;
                }
            }
            else if (y == 200 && x < 290)
                x+=10;
            else if (x == 290 && y < 320)
                y+=10;
            else if (x > 10 && y == 320)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: // Trem4
            if (x == 310 && y == 320){
                mutex6.lock();
                isMutex6Lock = true;
                x -= 10;
            }
            else if ((x == 310 && y == 200) && isMutex6Lock ){
                mutex6.unlock();
                isMutex6Lock = false;
                x += 10;
            }
            else if (x == 290 && y == 220){
                mutex3.lock();
                isMutex3Lock = true;
                y -= 10;
            }
            else if ((x == 440 && y == 200) && isMutex3Lock){
                mutex3.unlock();
                isMutex3Lock = false;
                x += 10;
            }
            else if (x == 400 && y == 200){
                mutex4.lock();
                isMutex4Lock = true;
                x += 10;
            }
            else if (x == 560 && y == 220){
                mutex4.unlock();
                isMutex4Lock = false;
                y += 10;
            }
            else if (x == 540 && y == 200){
                mutex7.lock();
                isMutex7Lock = true;
                x += 10;
            }
            else if (x == 540 && y == 320){
                mutex7.unlock();
                isMutex7Lock = false;
                x -= 10;
            }
            else if (y == 200 && x < 560)
                x+=10;
            else if (x == 560 && y < 320)
                y+=10;
            else if (x > 290 && y == 320)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: // Trem5
            if (x == 580 && y == 320){
                if (!isMutex5Lock && !isMutex7Lock){
                    mutex7.lock();
                    isMutex7Lock = true;
                    mutex5.lock();
                    isMutex5Lock = true;
                    x -= 10;
                }
                else {
                    break;
                }
            }
            else if ((x == 710 && y == 200) && isMutex7Lock && isMutex5Lock){
                mutex7.unlock();
                mutex5.unlock();
                isMutex7Lock = false;
                isMutex5Lock = false;
                x += 10;
            }
            else if (y == 200 && x < 820)
                x+=10;
            else if (x == 820 && y < 320)
                y+=10;
            else if (x > 560 && y == 320)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::setVelocidade(int novaVelocidade)
{
    if (novaVelocidade > 0)
    {
        int maxSliderValue = 200;

        // Calcule a velocidade inversamente proporcional ao valor do slider
        velocidade = (maxSliderValue - novaVelocidade) + 1;
        qDebug() << velocidade;

        if (velocidade > 180){
            this->terminate();
        }
        if (velocidade < 180){
            this->start();
        }

    }
    else
    {

    }
}
