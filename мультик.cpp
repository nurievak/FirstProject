# include "TXLib.h"
void cat(int xc, int yc, int sizec, int cLine1, int cLine2);
void stone(int xs, int ys, int sizes);
void mouse(int xm, int ym, int sizem, int nLinem1, int nLinem2);
void hare(int xh, int y, int size);
void tree(int x, int y, int size, int widthLine, int nLine);
void Man(int x, int y, double size, int widthLine, double rHand, int CHat1, int CHat2, int CHat3, double Mouth);
void SceneOne(int x, int xh, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth);
void start();
void SceneTwo(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xm);
void SceneThree(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xm, int ym);
void SceneFour1(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xc);
void SceneFour2(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xm, int ym);
void SceneSix(int x, int size, double rHand, int CHat1, int CHat2, int CHat3);
void SceneFive(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth);
void ending();


int main()
    {
    txCreateWindow(1600, 900);
    txSetFillColor(TX_WHITE);
    txRectangle(0, 0, 1600, 900);
    start();
    SceneOne(300, 750, 3, -100, 1, 1, 1, 0);
    SceneTwo(300, 3, -100, 1, 1, 1, 0, -50);
    SceneThree(300, 3, -100, 1, 1, 1, 0, 482, 850);
    SceneFour1(300, 3, -100, 1, 1, 1, 0, -1);
    SceneFour2(300, 3, -100, 1, 1, 1, 0, 1120, 660);
    SceneFive(-100, 3, -100, 100, 20, 26, 0);
    SceneSix(-100, 3, -100, 100, 20, 26);
    ending();

    txSleep(20000);
    txSetFillColor(RGB(255, 255, 255));
    txClear();

    return 0;
    }





//------------------------------------------------------
//{------------------------------------------------------
//!Рисует человечка
//!
//!@param x            x, y      -- координаты начальной точки
//!@param size         size      -- размер мальчика (для масштабирования)
//!@param widthLine    widthLine -- толщина линии
//!@param rHand        rHand     -- расстояние между руками
//!@param CHat1        CHat1     -- цвет шляпы
//!@param CHat2        CHat2     -- цвет шляпы
//!@param CHat3        CHat3     -- цвет шляпы
//!@param Mouth        Mouth     -- улыбка
//!
//!@par   Пример использования:
//!@code
//!       ClearScreen(TX_BLACK);
//!@endcode
//}------------------------------------------------------

void Man(int x, int y, double size, int widthLine, double rHand, int CHat1, int CHat2, int CHat3, double Mouth)
    {
    //----- туловище
    txSetColor(    RGB(  5,  29, 28), widthLine);
    txSetFillColor(RGB(255, 128,  0));
    txRectangle(x - 25*size, y, x + 25*size, y + 60*size);
    //--- голова
    txSetFillColor(RGB(255, 231, 213));
    txCircle(x, y - 15*size, 15*size);
    //--- глаза
    txSetFillColor(RGB(86, 172, 235));
    txCircle(x - 5.5*size, y - 19*size, 2*size);
    txCircle(x + 5.5*size, y - 19*size, 2*size);
    //--- рот
    txSetFillColor(RGB(255, 183, 185));
    POINT mouth[4]{{ROUND(x - 5*size), ROUND(y - 10 - Mouth*size)},
                   {ROUND(x - 2*size), ROUND(y - 10        *size)},
                   {ROUND(x + 2*size), ROUND(y - 10        *size)},
                   {ROUND(x + 5*size), ROUND(y - 10 - Mouth*size)}};
    txPolygon(mouth, 4);
    //--- рука левая
    txSetFillColor(RGB(255, 231, 213));
    POINT handleft[3]{{ROUND(x - 25            *size), ROUND(y + 30*size)},
                      {ROUND(x - 45            *size), ROUND(y + 30*size)},
                      {ROUND(x - 45 + (rHand/2)*size), ROUND(y + 10*size)}};
    txPolygon(handleft, 3);
    //--- рука правая
    POINT handright[3]{{ROUND(x + 25            *size), ROUND(y + 30*size)},
                       {ROUND(x + 45            *size), ROUND(y + 30*size)},
                       {ROUND(x + 45 - (rHand/2)*size), ROUND(y + 10*size)}};
    txPolygon(handright, 3);
    //--- ноги
    txSetFillColor(RGB(155, 244, 142));
    txRectangle(x - 25*size, y + 60*size, x -  5*size, y + 120*size);
    txRectangle(x +  5*size, y + 60*size, x + 25*size, y + 120*size);
    //--- шляпа
    txSetFillColor(RGB(CHat1, CHat2, CHat3));
    POINT hat[4]{{ROUND(x),           ROUND(y - 50*size)}, {ROUND(x + 15*size), ROUND(y - 30*size)},
                 {ROUND(x - 15*size), ROUND(y - 30*size)}, {ROUND(x),           ROUND(y - 50*size)}};
    txPolygon(hat, 4);
    }
//-------------------------------------------------------------------------
void mouse(int xm, int ym, int sizem, int nLinem1, int nLinem2)
    {
    txSetColor(    RGB(  5,  29, 28), nLinem1);
    txSetFillColor(RGB(218, 159, 112));


    POINT telmouse[9]{{ROUND(xm           ), ROUND(ym)},
                      {ROUND(xm - 25*sizem), ROUND(ym - 30*sizem)},
                      {ROUND(xm - 25*sizem), ROUND(ym - 50*sizem)},
                      {ROUND(xm - 20*sizem), ROUND(ym - 65*sizem)},
                      {ROUND(xm -  5*sizem), ROUND(ym - 70*sizem)},
                      {ROUND(xm + 20*sizem), ROUND(ym - 65*sizem)},
                      {ROUND(xm + 25*sizem), ROUND(ym - 50*sizem)},
                      {ROUND(xm + 25*sizem), ROUND(ym - 30*sizem)},
                      {ROUND(xm           ), ROUND(ym           )}};
    txPolygon(telmouse, 9);
    txSetColor(RGB(105, 61, 99), nLinem2);
    txLine(xm - 5*sizem, ym - 70*sizem, xm - 25*sizem, ym - 90*sizem);
    txLine(xm - 25*sizem, ym - 90*sizem, xm - 55*sizem, ym - 80*sizem);
    txSetColor(    RGB(  5,  29, 28), nLinem1);
    txCircle(xm - 25*sizem, ym - 35*sizem, 15*sizem);
    txCircle(xm + 25*sizem, ym - 35*sizem, 15*sizem);
    txSetFillColor(RGB(17, 17, 17));
    txCircle(xm - 7*sizem, ym - 18*sizem, 5*sizem);
    txCircle(xm + 7*sizem, ym - 18*sizem, 5*sizem);
    txCircle(xm*sizem, ym*sizem, 3*sizem);
    }
//-------------------------------------------------------------------------
void stone(int xs, int ys, int sizes)
    {
    txSetFillColor(RGB(17, 17, 17));
    txCircle(xs*sizes, ys*sizes, 30*sizes);
    }
//-------------------------------------------------------------------------
void cat(int xc, int yc, int sizec, int cLine1, int cLine2)
    {
    txSetColor(    RGB(  5,  29, 28), cLine1);
    txSetFillColor(RGB(250, 155, 78));
    POINT cattttt[19]{{ROUND(xc           ), ROUND(yc)},
                      {ROUND(xc           ), ROUND(yc - 30*sizec)},
                      {ROUND(xc - 10*sizec), ROUND(yc - 30*sizec)},
                      {ROUND(xc - 10*sizec), ROUND(yc - 20*sizec)},
                      {ROUND(xc - 20*sizec), ROUND(yc - 20*sizec)},
                      {ROUND(xc - 20*sizec), ROUND(yc - 30*sizec)},
                      {ROUND(xc - 30*sizec), ROUND(yc - 30*sizec)},
                      {ROUND(xc - 30*sizec), ROUND(yc - 10*sizec)},
                      {ROUND(xc - 60*sizec), ROUND(yc - 10*sizec)},
                      {ROUND(xc - 60*sizec), ROUND(yc - 30*sizec)},
                      {ROUND(xc - 70*sizec), ROUND(yc - 30*sizec)},
                      {ROUND(xc - 70*sizec), ROUND(yc + 30*sizec)},
                      {ROUND(xc - 60*sizec), ROUND(yc + 30*sizec)},
                      {ROUND(xc - 60*sizec), ROUND(yc + 20*sizec)},
                      {ROUND(xc - 20*sizec), ROUND(yc + 20*sizec)},
                      {ROUND(xc - 20*sizec), ROUND(yc + 30*sizec)},
                      {ROUND(xc - 10*sizec), ROUND(yc + 30*sizec)},
                      {ROUND(xc - 10*sizec), ROUND(yc)},
                      {ROUND(xc), ROUND(yc)}};
    txPolygon(cattttt, 19);
    txSetFillColor(RGB(17, 17, 17));
    txCircle(xc - 20*sizec, yc - 10*sizec, 1*sizec);
    txCircle(xc - 10*sizec, yc - 10*sizec, 1*sizec);
    txSetColor(    RGB(  5,  29, 28), cLine2);
    txLine(xc - 15*sizec, yc - 8*sizec, xc - 15*sizec, yc - 3*sizec);
    txLine(xc - 20*sizec, yc - 3*sizec, xc - 10*sizec, yc - 3*sizec);

    }

//-------------------------------------------------------------------------
void tree(int x, int y, int size, int widthLine, int nLine)
    {
    txSetColor(RGB(155, 110, 65), nLine);
    txLine(x, y + 40*size, x, y + 70*size);
    txSetFillColor(RGB(90, 194, 65));
    txSetColor(    RGB( 0,   0,  0), widthLine);
    POINT b1[7]{{ROUND(x - 30*size), ROUND(y)}, {ROUND(x),           ROUND(y - 40*size)},
                {ROUND(x + 30*size), ROUND(y)}, {ROUND(x + 15*size), ROUND(y -  5*size)},
                {ROUND(x),           ROUND(y)}, {ROUND(x - 15*size), ROUND(y - 5*size)},
                {ROUND(x - 30*size), ROUND(y)}};
    txPolygon(b1, 7);
    txSetFillColor(RGB(90, 194, 65));
    POINT b2[7]{{ROUND(x - 30*size), ROUND(y + 40*size)}, {ROUND(x),           ROUND(y)},
                {ROUND(x + 30*size), ROUND(y + 40*size)}, {ROUND(x + 15*size), ROUND(y + 35*size)},
                {ROUND(x),           ROUND(y + 40*size)}, {ROUND(x - 15*size), ROUND(y + 35*size)},
                {ROUND(x - 30*size), ROUND(y + 40*size)}};
    txPolygon(b2, 7);
    }
//-------------------------------------------------------------------------
void hare(int xh, int y, int size)
    {
    txSetFillColor(RGB(151, 150, 149));
    POINT u1[5]{{ROUND(xh - 110*size/2), ROUND(y - 20*size/2)},
                {ROUND(xh - 130*size/2), ROUND(y - 30*size/2)},
                {ROUND(xh - 130*size/2), ROUND(y - 50*size/2)},
                {ROUND(xh - 110*size/2), ROUND(y - 40*size/2)},
                {ROUND(xh - 110*size/2), ROUND(y - 20*size/2)}};
    txPolygon(u1, 5);
    POINT u2[5]{{ROUND(xh - 70*size/2), ROUND(y - 20*size/2)},
                {ROUND(xh - 70*size/2), ROUND(y - 40*size/2)},
                {ROUND(xh - 50*size/2), ROUND(y - 50*size/2)},
                {ROUND(xh - 50*size/2), ROUND(y - 30*size/2)},
                {ROUND(xh - 70*size/2), ROUND(y - 20*size/2)}};
    txPolygon(u2, 5);
    txCircle(xh - 90*size/2, y, 30*size/2);
    txSetFillColor(RGB(16, 16, 16));
    txCircle(xh - 100*size/2, y, 3*size/2);
    txCircle(xh -  80*size/2, y, 3*size/2);
    txSetFillColor(RGB(151, 150, 149));
    POINT teloz[4]{{ROUND(xh - 130*size/2), ROUND(y + 100*size/2)},
                   {ROUND(xh -  90*size/2), ROUND(y +  30*size/2)},
                   {ROUND(xh -  50*size/2), ROUND(y + 100*size/2)},
                   {ROUND(xh - 130*size/2), ROUND(y + 100*size/2)}};
    txPolygon(teloz, 4);
    POINT nos[4]{{ROUND(xh - 95*size/2), ROUND(y + 10*size/2)},
                 {ROUND(xh - 85*size/2), ROUND(y + 10*size/2)},
                 {ROUND(xh - 90*size/2), ROUND(y + 15*size/2)},
                 {ROUND(xh - 95*size/2), ROUND(y + 10*size/2)}};
    txPolygon(nos, 4);
    txLine(  xh - 100*size/2, y + 20*size/2, xh - 80*size/2, y + 20*size/2);
    txCircle(xh -  60*size/2, y + 70*size/2, 10*size/2);
    }
//-------------------------------------------------------------------------
 void SceneOne(int x, int xh, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth)
       {
    for(int z = 0; z <= 20; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       stone(555, 310, 2);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       hare(750, 650, size);
       Man(x - 500, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       x = x + 2*z;
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Ничего не радует, вот бы снова улыбаться, - говорит мальчик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
       }
    for(int z = 0; z <= 15; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       stone(555, 310, 2);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(x - 500, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       hare(750, 650, size);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Не расстраивайся, я тебе помогу, - сказал стоявший на поляне зайчик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
       }
    for(int z = 0; z <= 15; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       stone(555, 310, 2);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(x - 500, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       hare(750, 650, size);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Выручи кого-нибудь, твоя шапка замигает, и ты вернёшь улыбку, - произнёс зайчик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
       }
    for(int z = 0; z <= 25; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       stone(555, 310, 2);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(x - 500, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       hare(xh, 650, size);
       xh = xh + 8*z;
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Странно это всё, но я попробую, - промолвил мальчик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
       }
       }
void SceneTwo(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xm)
    {
   for(int z = 0; z <= 12; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       mouse(xm, 850, 1, 2, 4);
       xm = xm + 8*z;
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Помогите, убивают, - кричал выбежавший зверёк.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 12; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       mouse(482, 850, 1, 2, 4);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Мышка, я тебе помогу. Спрячься за тот камень, - сказал мальчик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
    }
void SceneThree(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xm, int ym)
    {
   for(int z = 0; z <= 14; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       mouse(xm, 850, 1, 2, 4);
       xm = xm + 6*z;
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 14; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       mouse(1120, ym, 1, 2, 4);
       stone(555, 310, 2);
       ym = ym - 2*z;
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
    }
void SceneFour1(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xc)
    {
   for(int z = 0; z <= 16; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       cat(xc, 800, 2, 2, 1);
       xc = xc + 5*z;
       stone(555, 310, 2);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 16; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       cat(600, 800, 2, 2, 1);
       stone(555, 310, 2);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Мальчик, ты не видел мышку, - спросил котик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 16; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       cat(600, 800, 2, 2, 1);
       stone(555, 310, 2);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Нет, не видел, - ответил мальчик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 16; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       cat(600, 800, 2, 2, 1);
       stone(555, 310, 2);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Эх, жаль, - произнесло животное.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 25; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       cat(xc, 800, 2, 2, 1);
       xc = xc + 5*z;
       stone(555, 310, 2);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Эх, жаль, - произнесло животное.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
    }
void SceneFour2(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, int xm, int ym)
    {
   for(int z = 0; z <= 14; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       mouse(1120, ym, 1, 2, 4);
       stone(555, 310, 2);
       ym = ym + 2*z;
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 14; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       mouse(1120, 850, 1, 2, 4);
       stone(555, 310, 2);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Спасибо тебе! Я очень благодарна, ты спас меня, - сказала мышка.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 25; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       mouse(xm, 850, 1, 2, 4);
       xm = xm + 2*z;
       stone(555, 310, 2);
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
   for(int z = 0; z <= 45; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       stone(555, 310, 2);
       Man(x, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       for(int n = 1; n <= 100; n++)
          {
          CHat1 = CHat1 + 1*n;
          CHat2 = CHat2 + 2*n;
          CHat3 = CHat3 + 1*n;
          }
       x = x + 2*z;
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
    }
    }
//-------------------------------------------------------------------------
void SceneFive(int x, int size, double rHand, int CHat1, int CHat2, int CHat3, double Mouth)
    {
    for(int z = 0; z <= 47; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 300, 350, 5, 2, 30);
       tree( 600, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(x - 100, 450, size, 3, rHand, CHat1, CHat2, CHat3, Mouth);
       if(z <= 7)
         {
         for(int a = 1; a <= 20; a++)
            {
            Mouth = Mouth + 1.5*a;
            break;
            }
         }
       for(long rast = 1; rast <= 4; rast++)
          {
          rHand = rHand + 0.58*rast;
          }
       x = x + 2*z;
       for(int n = 1; n <= 100; n++)
          {
          CHat1 = CHat1 + 1*n;
          CHat2 = CHat2 + 2*n;
          CHat3 = CHat3 + 1*n;
          }
        txSetTextAlign(TA_CENTER);
        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 50);
        txTextOut(800, 850, "Ура, получилось, как же меня выручил зайчик, - кричал мальчик.");
        txSleep(250);
        txSetFillColor(TX_WHITE);
        txClear();
        }
    }
//-------------------------------------------------------------------------
void SceneSix(int x, int size, double rHand, int CHat1, int CHat2, int CHat3)
    {
    for(int z = 0; z <= 20; z++)
       {
        txSetFillColor(TX_LIGHTGREEN);
        txRectangle(0, 600, 1600, 900);
        txSetFillColor(RGB(191, 242, 240));
        txRectangle(0, 0, 1600, 600);
        tree( 800, 400, 4, 2, 30);
        tree(1300, 350, 5, 2, 30);
        Man(x - 100, 450, size, 3, rHand, CHat1, CHat2, CHat3, 10);
        x = x + 2*z;
        hare(650, 550, size);
        for(int n = 1; n <= 100; n++)
            {
            CHat1 = CHat1 + 1*n;
            CHat2 = CHat2 + 2*n;
            CHat3 = CHat3 + 1*n;
            }
        txSleep(150);
        txSetFillColor(TX_WHITE);
        txClear();
        }
    for(int z = 0; z <= 23; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(200, 450, size, 3, rHand, CHat1, CHat2, CHat3, 10);
       hare(650, 550, size);
       for(int n = 1; n <= 100; n++)
          {
          CHat1 = CHat1 + 1*n;
          CHat2 = CHat2 + 2*n;
          CHat3 = CHat3 + 1*n;
          }
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Понравилось ли тебе делать кого-то другого счастливым, - спросил зайчик.");
       txSleep(250);
       txSetFillColor(TX_WHITE);
       txClear();
       }
    for(int z = 0; z <= 23; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor (RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(200, 450, size, 3, rHand, CHat1, CHat2, CHat3, 10);
       hare(650, 550, size);
       for(int n = 1; n <= 100; n++)
          {
          CHat1 = CHat1 + 1*n;
          CHat2 = CHat2 + 2*n;
          CHat3 = CHat3 + 1*n;
          }
          txSetTextAlign(TA_CENTER);
          txSetColor(TX_BLACK);
          txSelectFont("Comic Sans MS", 50);
          txTextOut(800, 850, "Да, от этого стало теплее на душе, - ответил ему мальчик.");
          txSleep(250);
          txSetFillColor(TX_WHITE);
          txClear();
          }
    for(int z = 0; z <= 23; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor(RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(200, 450, size, 3, rHand, CHat1, CHat2, CHat3, 10);
       hare(650, 550, size);
       for(int n = 1; n <= 100; n++)
          {
          CHat1 = CHat1 + 1*n;
          CHat2 = CHat2 + 2*n;
          CHat3 = CHat3 + 1*n;
          }
          txSetTextAlign(TA_CENTER);
          txSetColor(TX_BLACK);
          txSelectFont("Comic Sans MS", 50);
          txTextOut(800, 850, "Это простая шапка. От улыбок других и сам начинаешь улыбаться, - раскрыл секрет зверёк.");
          txSleep(250);
          txSetFillColor(TX_WHITE);
          txClear();
          }
    for(int z = 0; z <= 23; z++)
       {
       txSetFillColor(TX_LIGHTGREEN);
       txRectangle(0, 600, 1600, 900);
       txSetFillColor (RGB(191, 242, 240));
       txRectangle(0, 0, 1600, 600);
       tree( 800, 400, 4, 2, 30);
       tree(1300, 350, 5, 2, 30);
       Man(200, 450, size, 3, rHand, CHat1, CHat2, CHat3, 10);
       hare(650, 550, size);
       for(int n = 1; n <= 100; n++)
          {
          CHat1 = CHat1 + 1*n;
          CHat2 = CHat2 + 2*n;
          CHat3 = CHat3 + 1*n;
          }
       txSetTextAlign(TA_CENTER);
       txSetColor(TX_BLACK);
       txSelectFont("Comic Sans MS", 50);
       txTextOut(800, 850, "Ничего себе, а ведь и правда!");
       txSleep(250);
       txSetFillColor (TX_WHITE);
       txClear();
       }
    }
//-------------------------------------------------------------------------
void start()
    {
    txSetFillColor (TX_LIGHTGREEN);
    txRectangle(0, 0, 1600, 900);
    txSetColor(RGB(0, 0, 0));
    txSelectFont("Comic Sans MS", 60);
    txTextOut(400, 450, "МУЛЬТИК *ВОЛШЕБНАЯ ШАПОЧКА*");
    txSleep(2000);
    }
//-------------------------------------------------------------------------
void ending()
    {
    txSetFillColor (TX_LIGHTGREEN);
    txRectangle(0, 0, 1600, 900);
    txSetColor(RGB(0, 0, 0));
    txSelectFont("Comic Sans MS", 60);
    txTextOut(800, 450, "КОНЕЦ");
    txSleep(2000);
    }

