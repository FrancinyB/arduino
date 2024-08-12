#ifndef mESTADOS
#define mESTADOS

#include <Arduino.h>

class mEstados{
    public:
    mEstados();
    bool doIt(double now, float cycle);
    bool state;

    private:
    int nCycles;
};

#endif
