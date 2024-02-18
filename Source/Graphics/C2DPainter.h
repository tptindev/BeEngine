#ifndef C2DPAINTER_H
#define C2DPAINTER_H

#include "APainter.h"

class CLine;
class CPoint;
class CRect;
class CPolygon;
class CImage;

class C2DPainter : public APainter
{
public:
    C2DPainter();

    void drawImage(CRect* target, CImage* image, CRect* source) {}
    void drawConvexPolygon(CPolygon* polygon) {}
    void drawConvexPolygon(CPoint* points, int pointCount) {}
    void drawRect(int x, int y, CRect* rectangle) {};
    void drawRect(int x, int y, int width, int height) {};
    void drawEllipse(int x, int y, CRect* rectangle) {};
    void drawEllipse(int x, int y, int width, int height) {};
    void drawLine(CLine* line) {}
    void drawLine(int x1, int y1, int x2, int y2) {}
};

#endif // C2DPAINTER_H
