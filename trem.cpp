#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100; // Quanto maior mais lento
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 80 && x < 420)
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
            if (y == 80 && x < 690)
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
            if (y == 200 && x < 290)
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
            if (y == 200 && x < 560)
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
            if (y == 200 && x < 820)
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
        // Atualize a velocidade do trem
        velocidade = novaVelocidade;
    }
    else
    {
        // Trate qualquer valor inválido aqui, como emitir um aviso ou lançar uma exceção.
    }
}




