#ifndef DRAWJOGO_H
#define DRAWJOGO_H

#include <QWidget>
#include <iostream>
#include <QTimerEvent>
#include <QMouseEvent>
#include <vector>
#include <time.h>

class DrawJogo : public QWidget
{
    Q_OBJECT
private:

    //posicao da esfera na tela;
    int esf_posx;
    int esf_posy;

    //variaveis de cor da esfera
    int color_R;
    int color_G;
    int color_B;

    // estado do jogo
    int gameState;

    // cor da esfera: 0 - Vermelho, 1 - Amarelo, 2 - Azul, 3 - Verde
    int corEsfera;

    // Calculo de tempo
    time_t userTmpInicio;
    time_t userTmpFim;
    std::vector<time_t> tmpUser;

    // variaveis de jogo
    int acertos;
    int erros;
    int tentativas;
    QString tempos;
    float tempoMedio;

public:
    explicit DrawJogo(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

public slots:
    void keyPress(QKeyEvent *tecla);
    void drawinit();
    void setPosition();
    void setColor();

};

#endif // DRAWJOGO_H
