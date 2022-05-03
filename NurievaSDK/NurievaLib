# include "TXLib.h"
void Man(int x, int y, double size, int widthLine, double rHand, int CHat1, int CHat2, int CHat3, double Mouth, double rN);

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
    POINT hat[4]{{ROUND(x),           ROUND(y - 50*size)}, {ROUND(x + 15*size), ROUND(y - 30*size)},
                 {ROUND(x - 15*size), ROUND(y - 30*size)}, {ROUND(x),           ROUND(y - 50*size)}};
    txPolygon(hat, 4);
    }

