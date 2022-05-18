# include "TXLib.h"

void Man(int x, int y, double size, int widthLine, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, double rN);
void cloud(int xcl, int ycl, int sizecl);
void cat(int xc, int yc, int sizec, int cLine1, int cLine2int, int typec);
void stone(int xs, int ys, int sizes);
void mouse(int xm, int ym, int sizem, int nLinem1, int nLinem2, int type);
void Bat(int xb, int yb, int size, double RW);
void tree(int x, int y, int size, int widthLine, int nLine);
void FunScOne1(const char text[], int dx);
void Fun(const char text1[]);
void FonSc1(int dx);
void FonSc234(int dx);
void FunScThree(const char text2[], int dx);
void cloudmove(int dx);
void FonSc4(int dx);
void FonSc5(int dx);
void FunScFive(const char text3[], int dx);

//{------------------------------------------------------
//!@ingroup Object
//!
//! Рисует человечка
//!
//!@note <i>Человечек постоянно грустит, мечтая об улыбке</i>
//!
//! <table border = 0>
//! <tr><td> @image man.png </td>
//!
//!@param x            x, y      - координаты начальной точки
//!@param size         size      - размер мальчика (для масштабирования)
//!@param widthLine    widthLine - толщина линии
//!@param rHand        rHand     - расстояние между руками
//!@param CHat1        CHat1     - цвет шляпы
//!@param CHat2        CHat2     - цвет шляпы
//!@param CHat3        CHat3     - цвет шляпы
//!@param Mouth        Mouth     - улыбка
//!@param rN           rN        - расстояние между ногами
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par   Пример использования:
//!@code
//!       Man(200, 450, size, 3, 15, 34, 46, 79, 10, 30);
//!@endcode
//}------------------------------------------------------
void Man(int x, int y, double size, int widthLine, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, double rN)
    {
    //----- туловище
    txSetColor(RGB(5, 29, 28), widthLine);
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
    txSetColor(RGB(5, 29, 28), 6);
    txLine(x - 1*size, y + 60*size, x - 10 + (rN/2)*size, y + 120*size);
    txLine(x - 1*size, y + 60*size, x + 10 - (rN/2)*size, y + 120*size);
    txSetColor(RGB(5, 29, 28), widthLine);
    txRectangle(x - 20*size, y + 60*size, x + size, y + 100*size);
    txRectangle(x + size, y + 60*size, x + 20*size, y + 100*size);
    //--- шляпа
    txSetFillColor(RGB(CHat1, CHat2, CHat3));
    POINT hat[4]{{ROUND(x),           ROUND(y - 50*size)},
                 {ROUND(x + 15*size), ROUND(y - 30*size)},
                 {ROUND(x - 15*size), ROUND(y - 30*size)},
                 {ROUND(x),           ROUND(y - 50*size)}};
    txPolygon(hat, 4);
    }
//==========================================================================
//{------------------------------------------------------
//!@ingroup Object
//!
//! Рисует облачко
//!
//!@note <i>Нарисуй несколько облачков, чтобы им было не одиноко</i>
//!
//! <table border = 0>
//! <tr><td> @image man.png </td>
//!
//!@param xcl, ycl    xcl, ycl   - координаты начальной точки
//!@param size         sizecl    - размер облачка (для масштабирования)
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par   Пример использования:
//!@code
//!       cloud(200, 200, 3);
//!@endcode
//}------------------------------------------------------
void cloud(int xcl, int ycl, int sizecl)
    {
    txSetColor(RGB(255, 255, 255), 2);
    txSetFillColor(RGB(255, 255, 255));
    txCircle(xcl, ycl, 15*sizecl);
    txCircle(xcl - 20*sizecl, ycl - 5*sizecl, 15*sizecl);
    txCircle(xcl + 20*sizecl, ycl - 5*sizecl, 15*sizecl);
    }
//{------------------------------------------------------
//!@ingroup Object
//!
//! Рисует мышку
//!
//!@note <i>Я слышу писк! Неужели это мыши?</i>
//!
//! <table border = 0>
//! <tr><td> @image man.png </td>
//!
//!@param xm, ym       xm, ym    - координаты начальной точки
//!@param sizem        sizem     - размер мышки (для масштабирования)
//!@param nLinem2      nLinem1   - толщина линии рисования мышки
//!@param nLinem2      nLinem2   - толщина хвоста
//!@param type         type      - тип положения мышки (меняется хвост)
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par   Пример использования:
//!@code
//!       mouse(-50 + 20*dk, 850, 1, 2, 4, (dk%2));
//!@endcode
//}------------------------------------------------------
void mouse(int xm, int ym, int sizem, int nLinem1, int nLinem2, int type)
    {
        if (type == 0)
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
        txSetColor(RGB(5, 29, 28), 2);
        }
         if (type == 1)
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
        txLine(xm - 25*sizem, ym - 90*sizem, xm - 5*sizem, ym - 100*sizem);
        txSetColor(    RGB(  5,  29, 28), nLinem1);
        txCircle(xm - 25*sizem, ym - 35*sizem, 15*sizem);
        txCircle(xm + 25*sizem, ym - 35*sizem, 15*sizem);
        txSetFillColor(RGB(17, 17, 17));
        txCircle(xm - 7*sizem, ym - 18*sizem, 5*sizem);
        txCircle(xm + 7*sizem, ym - 18*sizem, 5*sizem);
        txCircle(xm*sizem, ym*sizem, 3*sizem);
        txSetColor(RGB(5, 29, 28), 2);
        }

    }
//{------------------------------------------------------
//!@ingroup Object
//!
//! Рисует камень
//!
//!@note <i>Я не круг, я камень!</i>
//!
//! <table border = 0>
//! <tr><td> @image man.png </td>
//!
//!@param xs, ys       xs, ys   - координаты начальной точки
//!@param sizes        sizes    - размер камня (для масштабирования)
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par   Пример использования:
//!@code
//!       stone(555, 310, 2);
//!@endcode
//}------------------------------------------------------
//==========================================================================
void stone(int xs, int ys, int sizes)
    {
    txSetFillColor(RGB(17, 17, 17));
    txSetColor(RGB(5, 29, 28), 2);
    txCircle(xs*sizes, ys*sizes, 30*sizes);
    }
//{------------------------------------------------------
//!@ingroup Object
//!
//! Рисует кошку
//!
//!@note <i>Мяу, мяу, мяу!</i>
//!
//! <table border = 0>
//! <tr><td> @image man.png </td>
//!
//!@param xc, yc       xc, yc    - координаты начальной точки
//!@param sizec        sizec     - размер мышки (для масштабирования)
//!@param cLinem2      cLine1    - толщина линии рисования кошки
//!@param cLinem2      cLine2    - толщина усов и рта
//!@param type         typec     - тип положения кошки (лапки, усы)
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par   Пример использования:
//!@code
//!       cat(600 + 30*dk, 800, 2, 2, 1, (dk%2));
//!@endcode
//}------------------------------------------------------
//==========================================================================
void cat(int xc, int yc, int sizec, int cLine1, int cLine2, int typec)
    {
        if (typec == 0)
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
                          {ROUND(xc - 10*sizec), ROUND(yc           )},
                          {ROUND(xc           ), ROUND(yc           )}};
        txPolygon(cattttt, 19);
        txRectangle(xc - 56*sizec, yc + 20*sizec, xc - 46*sizec, yc + 30*sizec);
        txRectangle(xc - 32*sizec, yc + 20*sizec, xc - 22*sizec, yc + 30*sizec);
        txSetFillColor(RGB(17, 17, 17));
        txCircle(xc - 20*sizec, yc - 10*sizec, 1*sizec);
        txCircle(xc - 10*sizec, yc - 10*sizec, 1*sizec);
        txSetColor(RGB(  5,  29, 28), cLine2);
        txLine(xc - 15*sizec, yc - 8*sizec, xc - 15*sizec, yc -  3*sizec);
        txLine(xc - 20*sizec, yc - 3*sizec, xc - 10*sizec, yc -  3*sizec);
        txLine(xc -  7*sizec, yc - 8*sizec, xc + 15*sizec, yc - 15*sizec);
        txLine(xc -  7*sizec, yc - 8*sizec, xc + 15*sizec, yc -  8*sizec);
        txLine(xc - 22*sizec, yc - 8*sizec, xc - 45*sizec, yc - 15*sizec);
        txLine(xc - 22*sizec, yc - 8*sizec, xc - 45*sizec, yc -  8*sizec);
        }
        if (typec == 1)
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
                          {ROUND(xc - 10*sizec), ROUND(yc           )},
                          {ROUND(xc           ), ROUND(yc           )}};
        txPolygon(cattttt, 19);
        txSetFillColor(RGB(17, 17, 17));
        txCircle(xc - 20*sizec, yc - 10*sizec, 1*sizec);
        txCircle(xc - 10*sizec, yc - 10*sizec, 1*sizec);
        txSetColor(RGB(  5,  29, 28), cLine2);
        txLine(xc - 15*sizec, yc - 8*sizec, xc - 15*sizec, yc -  3*sizec);
        txLine(xc - 20*sizec, yc - 3*sizec, xc - 10*sizec, yc -  3*sizec);
        txLine(xc -  7*sizec, yc - 8*sizec, xc + 15*sizec, yc - 12*sizec);
        txLine(xc -  7*sizec, yc - 8*sizec, xc + 15*sizec, yc -  5*sizec);
        txLine(xc - 22*sizec, yc - 8*sizec, xc - 45*sizec, yc - 12*sizec);
        txLine(xc - 22*sizec, yc - 8*sizec, xc - 45*sizec, yc -  6*sizec);
        txSetColor(RGB(5, 29, 28), 2);
        }
    }
//{------------------------------------------------------
//!@ingroup Object
//!
//! Рисует дерево
//!
//!@note <i>Зимой и летом одним цветом</i>
//!
//! <table border = 0>
//! <tr><td> @image man.png </td>
//!
//!@param x, y         x, y      - координаты начальной точки
//!@param size         size      - размер дерева (для масштабирования)
//!@param widthLine    nLine     - толщина линии рисования ствола
//!@param nLinem2      nLine     - толщина линии рисования
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par   Пример использования:
//!@code
//!       tree(1300, 350, 5, 2, 30);
//!@endcode
//}------------------------------------------------------
//==========================================================================
void tree(int x, int y, int size, int widthLine, int nLine)
    {
    txSetColor(RGB(155, 110, 65), nLine);
    txLine(x, y + 40*size, x, y + 70*size);
    txSetFillColor(RGB(90, 194, 65));
    txSetColor(RGB( 0,   0,  0), widthLine);
    POINT b1[7]{{ROUND(x - 30*size), ROUND(y)}, {ROUND(x          ), ROUND(y - 40*size)},
                {ROUND(x + 30*size), ROUND(y)}, {ROUND(x + 15*size), ROUND(y -  5*size)},
                {ROUND(x          ), ROUND(y)}, {ROUND(x - 15*size), ROUND(y - 5*size)},
                {ROUND(x - 30*size), ROUND(y)}};
    txPolygon(b1, 7);
    txSetFillColor(RGB(90, 194, 65));
    POINT b2[7]{{ROUND(x - 30*size), ROUND(y + 40*size)}, {ROUND(x          ), ROUND(y          )},
                {ROUND(x + 30*size), ROUND(y + 40*size)}, {ROUND(x + 15*size), ROUND(y + 35*size)},
                {ROUND(x          ), ROUND(y + 40*size)}, {ROUND(x - 15*size), ROUND(y + 35*size)},
                {ROUND(x - 30*size), ROUND(y + 40*size)}};
    txPolygon(b2, 7);
    txSetColor(RGB(5, 29, 28), 2);
    }
//{------------------------------------------------------
//!@ingroup Object
//!
//! Рисует летучую мышь
//!
//!@note <i>Я похожа на вампира, но на самом деле очень добрая</i>
//!
//! <table border = 0>
//! <tr><td> @image man.png </td>
//!
//!@param xb, yb       xb, yb    - координаты начальной точки
//!@param size         size      - размер мышки (для масштабирования)
//!@param RW           RW        - расстояние между крыльями
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par   Пример использования:
//!@code
//!       Bat(990, 200, 2, 0 + 25 - 25*(dk % 2));
//!@endcode
//}------------------------------------------------------
//==========================================================================
void Bat(int xb, int yb, int size, double RW)
    {
    txSetColor(RGB(5, 29, 28), 2);
    txSetFillColor(RGB(151, 150, 149));
    POINT wing1[5]{{ROUND(xb - 90*size/2), ROUND(yb + 55*size/2)},
                   {ROUND(xb + 45*size/2), ROUND(yb + 10 + RW*size/2)},
                   {ROUND(xb - 30*size/2), ROUND(yb + 50 + RW*size/2)},
                   {ROUND(xb -  5*size/2), ROUND(yb + 80 + RW*size/2)},
                   {ROUND(xb - 80*size/2), ROUND(yb + 65*size/2)}};
    txPolygon(wing1, 5);
    POINT wing2[5]{{ROUND(xb -  90*size/2), ROUND(yb + 55*size/2)},
                   {ROUND(xb - 230*size/2), ROUND(yb + 10 + RW*size/2)},
                   {ROUND(xb - 140*size/2), ROUND(yb + 50 + RW*size/2)},
                   {ROUND(xb - 175*size/2), ROUND(yb + 80 + RW*size/2)},
                   {ROUND(xb - 100*size/2), ROUND(yb + 65*size/2)}};
    txPolygon(wing2, 5);
    POINT u1[5]{{ROUND(xb - 110*size/2), ROUND(yb - 20*size/2)},
                {ROUND(xb - 130*size/2), ROUND(yb - 30*size/2)},
                {ROUND(xb - 130*size/2), ROUND(yb - 50*size/2)},
                {ROUND(xb - 110*size/2), ROUND(yb - 40*size/2)},
                {ROUND(xb - 110*size/2), ROUND(yb - 20*size/2)}};
    txPolygon(u1, 5);
    POINT u2[5]{{ROUND(xb - 70*size/2), ROUND(yb - 20*size/2)},
                {ROUND(xb - 70*size/2), ROUND(yb - 40*size/2)},
                {ROUND(xb - 50*size/2), ROUND(yb - 50*size/2)},
                {ROUND(xb - 50*size/2), ROUND(yb - 30*size/2)},
                {ROUND(xb - 70*size/2), ROUND(yb - 20*size/2)}};
    txPolygon(u2, 5);
    txCircle(xb - 90*size/2, yb, 30*size/2);
    txSetFillColor(RGB(16, 16, 16));
    txCircle(xb - 100*size/2, yb, 3*size/2);
    txCircle(xb -  80*size/2, yb, 3*size/2);
    txSetFillColor(RGB(151, 150, 149));
    POINT teloz[4]{{ROUND(xb - 130*size/2), ROUND(yb + 100*size/2)},
                   {ROUND(xb -  90*size/2), ROUND(yb +  30*size/2)},
                   {ROUND(xb -  50*size/2), ROUND(yb + 100*size/2)},
                   {ROUND(xb - 130*size/2), ROUND(yb + 100*size/2)}};
    txPolygon(teloz, 4);
    POINT nos[4]{{ROUND(xb - 95*size/2), ROUND(yb + 10*size/2)},
                 {ROUND(xb - 85*size/2), ROUND(yb + 10*size/2)},
                 {ROUND(xb - 90*size/2), ROUND(yb + 15*size/2)},
                 {ROUND(xb - 95*size/2), ROUND(yb + 10*size/2)}};
    txPolygon(nos, 4);
    txLine(xb - 100*size/2, yb + 20*size/2, xb - 80*size/2, yb + 20*size/2);
    POINT tth1[3]{{ROUND(xb - 100*size/2), ROUND(yb + 20*size/2)},
                  {ROUND(xb -  95*size/2), ROUND(yb + 25*size/2)},
                  {ROUND(xb -  92*size/2), ROUND(yb + 20*size/2)}};
    txPolygon(tth1, 3);
    POINT tth2[3]{{ROUND(xb - 88*size/2), ROUND(yb + 20*size/2)},
                  {ROUND(xb - 85*size/2), ROUND(yb + 25*size/2)},
                  {ROUND(xb - 80*size/2), ROUND(yb + 20*size/2)}};
    txPolygon(tth2, 3);
    txSetColor(RGB(5, 29, 28), 2);
    }
//{--------------------------------------------
//! пишем текст на экране на фоне для сцены 1
//}--------------------------------------------
void FunScOne1(const char text[], int dx)
    {
    FonSc1(dx);
    Man(350, 450, 3, 3, -100, 1, 1, 1, 0, 30);
    Bat(890, 140, 2, 2);
    txSetTextAlign(TA_CENTER);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 50);
    txTextOut(800, 850, text);
    txSleep(3500);
    txSetFillColor(TX_WHITE);
    txClear();
    }
//{--------------------------------------------
//! пишем текст
//}--------------------------------------------
void Fun(const char text1[])
    {
    txSetTextAlign(TA_CENTER);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 50);
    txTextOut(800, 850, text1);
    txSleep(250);
    txSetFillColor(TX_WHITE);
    txClear();
    }
//{--------------------------------------------
//! рисуем фон для сцены 1
//}--------------------------------------------
void FonSc1(int dx)
    {
    txSetFillColor(TX_LIGHTGREEN);
    txRectangle(0, 600, 1600, 900);
    txSetFillColor(RGB(191, 242, 240));
    txRectangle(0, 0, 1600, 600);
    cloudmove(dx);
    stone(555, 310, 2);
    tree( 800, 400, 4, 2, 30);
    tree(1300, 350, 5, 2, 30);
    }
//{--------------------------------------------
//! рисуем фон для сцен 2, 3, 4
//}--------------------------------------------
void FonSc234(int dx)
    {
    txSetFillColor(TX_LIGHTGREEN);
    txRectangle(0, 600, 1600, 900);
    txSetFillColor(RGB(191, 242, 240));
    txRectangle(0, 0, 1600, 600);
    cloudmove(dx);
    tree( 800, 400, 4, 2, 30);
    tree(1300, 350, 5, 2, 30);
    stone(555, 310, 2);
    Man(350, 450, 3, 3, -100, 1, 1, 1, 0, 30);
    }
//{--------------------------------------------
//! пишем текст на экране на фоне для сцены 3
//}--------------------------------------------
void FunScThree(const char text2[], int dx)
    {
    FonSc234(dx);
    cat(600, 800, 2, 2, 1, 1);
    txSetTextAlign(TA_CENTER);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 50);
    txTextOut(800, 850, text2);
    txSleep(3500);
    txSetFillColor(TX_WHITE);
    txClear();
    }
//{--------------------------------------------
//! рисуем фон для сцены 4
//}--------------------------------------------
void FonSc4(int dx)
    {
    txSetFillColor(TX_LIGHTGREEN);
    txRectangle(0, 600, 1600, 900);
    txSetFillColor(RGB(191, 242, 240));
    txRectangle(0, 0, 1600, 600);
    cloudmove(dx);
    tree( 800, 400, 4, 2, 30);
    tree(1300, 350, 5, 2, 30);
    stone(555, 310, 2);
    }
//{--------------------------------------------
//! рисуем фон для сцены 5
//}--------------------------------------------
 void FonSc5(int dx)
    {
    txSetFillColor(TX_LIGHTGREEN);
    txRectangle(0, 600, 1600, 900);
    txSetFillColor(RGB(191, 242, 240));
    txRectangle(0, 0, 1600, 600);
    cloudmove(dx);
    tree( 300, 350, 5, 2, 30);
    tree( 600, 400, 4, 2, 30);
    tree(1300, 350, 5, 2, 30);
    }
//{----------------------------------------------------
//! рисуем несколько облачков, которые будут двигаться
//}----------------------------------------------------
void cloudmove(int dx)
    {
    cloud(200 + 6*dx ,200, 3);
    cloud(400 + 6*dx ,200, 1);
    cloud(300 + 6*dx ,350, 2);
    cloud(800 + 6*dx ,150, 2);
    cloud(700 + 6*dx ,300, 5);
    cloud(1200 + 6*dx,250, 4);
    cloud(-50 + 6*dx ,200, 2);
    cloud(-150 + 6*dx ,150, 3);
    cloud(350 + 6*dx ,50, 1);
    }
