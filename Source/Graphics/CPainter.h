#ifndef CPAINTER_H
#define CPAINTER_H

class CWindow;
class CLine;
class CPoint;
class CRect;
class CPolygon;
class CImage;
class CText;

class CPainter
{
public:
    CPainter(CWindow* window);

    void drawImage(CRect* target, CImage* image, CRect* source) {}
    void drawConvexPolygon(CPolygon* polygon) {}
    void drawConvexPolygon(CPoint* points, int pointCount) {}
    void drawRect(int x, int y, CRect* rectangle) {};
    void drawRect(int x, int y, int width, int height, int r, int g, int b, int a = 255);
    void drawEllipse(int x, int y, CRect* rectangle) {};
    void drawEllipse(int x, int y, int width, int height) {};
    void drawLine(CLine* line) {}
    void drawLine(int x1, int y1, int x2, int y2) {}
    void drawText(const char* text, int x, int y);




private:
    CWindow* m_window;
};

#endif // CPAINTER_H
