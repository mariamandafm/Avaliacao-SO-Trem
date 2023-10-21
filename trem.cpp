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
    velocidade = 1000; // Quanto maior mais lento
}

void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (x == 400 && y == 80){
                //qDebug() << "[Trem 1] Tenta entrar na R0";
                mutex1.lock();
                isMutex1Lock = true;
                //qDebug() << "[Trem 1] Fechou: no trilho R0";
                x += 10;
            }
            else if (x == 400 && y == 200){
                mutex1.unlock();
                isMutex1Lock = false;
                //qDebug() << "[Trem 1] Liberou: trilho livre R0";
                x -= 10;
            }
            else if (x == 310 && y == 200){
                //qDebug() << "[Trem 1] Tenta entrar na R1";
                mutex2.lock();
                isMutex2Lock = true;
                //qDebug() << "[Trem 1] Fechou: no trilho R1";
                x -= 10;
            }
            else if (x == 150 && y == 180){
                mutex2.unlock();
                isMutex2Lock = false;
                //qDebug() << "[Trem 1] Liberou: trilho livre R1";
                y -= 10;
            }
            else if (x == 420 && y == 180){
                //qDebug() << "[Trem 1] Tenta entrar na R2";
                mutex3.lock();
                //qDebug() << "[Trem 1] Fechou: no trilho R2";
                y += 10;
            }
            else if (x == 270 && y == 200){
                mutex3.unlock();
                //qDebug() << "[Trem 1] Liberou: trilho livre R2";
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
                    //qDebug() << "[Trem 2] Tenta entrar R3";
                    mutex1.lock();
                    isMutex1Lock = true;
                    mutex4.lock();
                    isMutex4Lock = true;
                    //qDebug() << "[Trem 2] Fechou: no trilho R3";
                    x -= 10;
                }
                else{
                    qDebug() << "[Trem 2] Não conseguir fechar os dois mutex";
                    break;
                }

            }
            else if (x == 420 && y == 80 && isMutex1Lock && isMutex4Lock){
                mutex1.unlock();
                isMutex1Lock = false;
                mutex4.unlock();              
                isMutex4Lock = false;
                //qDebug() << "[Trem 2] Liberou: trilho livre R3";
                x += 10;
            }
            else if (x == 690 && y == 180){
                //qDebug() << "[Trem 2] Tenta entrar R4";
                mutex5.lock();
                isMutex5Lock = true;
                //qDebug() << "[Trem 2] Fechou: no trilho R4";
                y += 10;
            }
            else if (x == 540 && y == 200){
                mutex5.unlock();
                isMutex5Lock = false;
                //qDebug() << "[Trem 2] Liberou: trilho livre R4";
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
                //qDebug() << "[Trem 3] Tenta entrar na R1";
                if (!isMutex2Lock && !isMutex6Lock){
                    mutex2.lock();
                    isMutex2Lock = true;
                    mutex6.lock();
                    isMutex6Lock = true;

                    //qDebug() << "[Trem 3] Fechou: no trilho R1";
                    x += 10;
                }
                else{
                    //qDebug() << "[Trem 3] Não conseguir pegar os dois mutex ao mesmo tempo";
                    break;
                }
            }
            else if (x == 270 && y == 320){
                if (isMutex2Lock && isMutex6Lock){
                    mutex2.unlock();
                    isMutex2Lock = false;
                    mutex6.unlock();
                    isMutex6Lock = false;

                    //qDebug() << "[Trem 3] Liberou: trilho livre R5";
                    x -= 10;
                }
                else{
                   // qDebug() << "[Trem 3] Não liberou os dois mutex";
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
                //qDebug() << "[Trem 4] Tenta entrar na R5";
                mutex6.lock();
                isMutex6Lock = true;
                //qDebug() << "[Trem 4] Fechou: no trilho R5";
                x -= 10;
            }
            else if ((x == 310 && y == 200) && isMutex6Lock ){
                mutex6.unlock();
                isMutex6Lock = false;
                //qDebug() << "[Trem 4] Liberou: trilho livre R5";
                x += 10;
            }
            else if (x == 290 && y == 220){
                //qDebug() << "[Trem 4] Tenta entrar na R4";
                mutex3.lock();
                isMutex3Lock = true;
                //qDebug() << "[Trem 4] Fechou: no trilho R4";
                y -= 10;
            }
            else if ((x == 440 && y == 200) && isMutex3Lock){
                mutex3.unlock();
                isMutex3Lock = false;
                //qDebug() << "[Trem 4] Liberou: trilho livre R4";
                x += 10;
            }
            else if (x == 400 && y == 200){
                //qDebug() << "[Trem 4] Tenta entrar na R3";
                mutex4.lock();
                isMutex4Lock = true;
                //qDebug() << "[Trem 4] Fechou: no trilho R3";
                x += 10;
            }
            else if (x == 560 && y == 220){
                mutex4.unlock();
                isMutex4Lock = false;
                //qDebug() << "[Trem 4] Liberou: trilho livre R3";
                y += 10;
            }
            else if (x == 540 && y == 200){
                //qDebug() << "[Trem 4] Tenta entrar na R6";
                mutex7.lock();
                isMutex7Lock = true;
                //qDebug() << "[Trem 4] Fechou: no trilho R6";
                x += 10;
            }
            else if (x == 540 && y == 320){
                mutex7.unlock();
                isMutex7Lock = false;
                //qDebug() << "[Trem 4] Liberou: trilho livre R6";
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
                    //qDebug() << "[Trem 5] Tenta entrar na R6";
                    mutex7.lock();
                    isMutex7Lock = true;
                    mutex5.lock();
                    isMutex5Lock = true;
                    //qDebug() << "[Trem 5] Fechou: no trilho R6";
                    x -= 10;
                }
                else {
                    //qDebug() << "[Trem 5] Não conseguir pegar os dois mutex";
                    break;
                }
            }
            else if ((x == 710 && y == 200) && isMutex7Lock && isMutex5Lock){
                mutex7.unlock();
                mutex5.unlock();
                isMutex7Lock = false;
                isMutex5Lock = false;
                //qDebug() << "[Trem 5] Liberou: trilho livre R6";
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
    // Certifique-se de que a nova velocidade seja válida (por exemplo, maior que zero)
    if (novaVelocidade > 0)
    {
        // Determine o valor máximo do slider
        int maxSliderValue = 100; // Substitua pelo valor máximo do seu slider

        // Calcule a velocidade inversamente proporcional ao valor do slider
        velocidade = (maxSliderValue - novaVelocidade) + 1; // Adicionando 1 para garantir que velocidade seja maior que zero

        // qDebug() << velocidade;
    }
    else
    {
        // Trate qualquer valor inválido aqui, como emitir um aviso ou lançar uma exceção.
    }
}
