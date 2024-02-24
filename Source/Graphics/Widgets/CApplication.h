#ifndef CAPPLICATION_H
#define CAPPLICATION_H


class CWindow;
class CApplication
{
public:
    CApplication(CWindow* window);

    void execute();
    void quit();

private:
    CWindow* m_window;
};

#endif // CAPPLICATION_H
