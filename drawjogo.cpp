#include "drawjogo.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QTimerEvent>
#include <QMouseEvent>
#include <string>


DrawJogo::DrawJogo(QWidget *parent): QWidget (parent)
{

    lagura = 800;
    altura = 560;

    acertos = 0;
    erros = 0;
    tentativas = 10;
    tempos = "";
    tempoMedio = 0.0;

    userTmpInicio = time(0);
    gameState = 0;
    this->setPosition();
    this->setColor();
}

void DrawJogo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width()-1,height()-1);

    if(gameState == 0){
        painter.save();
        painter.drawText(QPoint(width()/2 - 85,height()/2), "Pressione Enter Pra Iniciar");
        painter.restore();

    } else if(gameState == 1){
        painter.save();

        brush.setColor(QColor(color_R, color_G, color_B));
        painter.setBrush(brush);
        painter.drawEllipse(QPoint(esf_posx,esf_posy),60,60);

        painter.restore();
    } else {
        painter.save();
        painter.drawText(QPoint(20,80), "Resultados:");
        painter.drawText(QPoint(20,120), "Acertos: "+QString::number(acertos));
        painter.drawText(QPoint(20,140), "Erros: "+QString::number(erros));
        painter.drawText(QPoint(20,160), "Tempos: "+tempos);
        painter.drawText(QPoint(20,180), "Tempo Médio: "+QString::number(tempoMedio) + " s");
        painter.drawText(QPoint(20,260), "Pressione Enter Para Retornar ao Inicio");

        painter.restore();

    }

}

void DrawJogo::keyPress(QKeyEvent *tecla)
{
    if(tecla->key() == Qt::Key_Enter){
        if(gameState == 0){
           gameState = 1;
           userTmpInicio = time(nullptr);

        }else if(gameState == 2){
            gameState = 0;
            erros = 0;
            acertos = 0;
            tempos = "";
            tempoMedio = 0.0;
        }
    } else if(gameState == 1){
        switch(tecla->key())
        {
        case Qt::Key_Left: // Seta para Esquerda
            if(corEsfera == 0){
                userTmpFim = time(nullptr);
                tmpUser.push_back(userTmpFim - userTmpInicio);
                acertos++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            } else {
                userTmpFim = time(nullptr);
                tmpUser.push_back(userTmpFim - userTmpInicio);
                erros++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            }
            tentativas--;
            break;
        case Qt::Key_Up: // Seta para cima
            if(corEsfera == 1){
                userTmpFim = time(nullptr);
                tmpUser.push_back(userTmpFim - userTmpInicio);
                acertos++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            } else {
                userTmpFim = time(nullptr);
                tmpUser.push_back(userTmpFim - userTmpInicio);
                erros++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            }
            tentativas--;
            break;
        case Qt::Key_Right: // Seta para Direita
            if(corEsfera == 2){
                userTmpFim = time(nullptr);
                tmpUser.push_back(userTmpFim - userTmpInicio);
                acertos++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            } else {
                userTmpFim = clock();
                tmpUser.push_back(userTmpFim - userTmpInicio);
                erros++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            }
            tentativas--;
            break;
        case Qt::Key_Down: // Seta para Baixo
            if(corEsfera == 3){
                userTmpFim = time(nullptr);
                tmpUser.push_back(userTmpFim - userTmpInicio);
                acertos++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            } else {
                userTmpFim = time(nullptr);
                tmpUser.push_back(userTmpFim - userTmpInicio);
                erros++;

                this->setColor();
                this->setPosition();

                userTmpInicio = time(nullptr);
            }
            tentativas--;
            break;
        }
    }

    if(tentativas == 0){
        time_t auxtempo;
        int interador = 0;
        while (!tmpUser.empty()) {
            interador++;
            auxtempo = float(tmpUser.back());
            tempos += "(" + QString::number(auxtempo) + " s) ";
            tempoMedio += auxtempo;
            tmpUser.pop_back();
        }
        if(tempoMedio > 0) tempoMedio = float(tempoMedio)/float(interador);
        gameState = 2;
        tentativas = 10;
    }
    repaint();
}

void DrawJogo::drawinit()
{
    repaint();
}

void DrawJogo::setPosition()
{
   srand(unsigned(clock()));
   esf_posx = 60 + (rand()%680);
   esf_posy = 60 + (rand()%440);
}

void DrawJogo::setColor()
{
    srand(unsigned(clock()));
    corEsfera = rand()%4;

    switch(this->corEsfera)
    {
    case 0:
        this->color_R = 255;
        this->color_G = 0;
        this->color_B = 0;
        break;
    case 1:
        this->color_R = 255;
        this->color_G = 255;
        this->color_B = 0;
        break;
    case 2:
        this->color_R = 0;
        this->color_G = 0;
        this->color_B = 255;
        break;
    case 3:
        this->color_R = 0;
        this->color_G = 255;
        this->color_B = 0;
        break;
    }

}

