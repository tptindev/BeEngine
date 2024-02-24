#ifndef CAPPLICATION_H
#define CAPPLICATION_H


class AWindow;
class CApplication
{
public:
    CApplication(AWindow* window);

    int execute();
    void quit();

private:
    AWindow* m_window;
};

#endif // CAPPLICATION_H
