#ifndef CAPPLICATION_H
#define CAPPLICATION_H


class CWindow;
class SDL_Surface;
class CApplication
{
public:
    CApplication(CWindow* window);

    int execute();
    void quit();

    CWindow *window();
    SDL_Surface *windowSurface();


private:
    CWindow* m_window;
};

#endif // CAPPLICATION_H
