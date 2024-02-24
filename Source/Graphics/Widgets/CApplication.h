#ifndef CAPPLICATION_H
#define CAPPLICATION_H


class CWindow;
class CApplication
{
public:
    CApplication(CWindow* window);

    int execute();
    void quit();

    CWindow *window();

private:
    CWindow* m_window;
};

#endif // CAPPLICATION_H
