#include"mEstados.h"

mEstados::mEstados(){
    bool state=false;
    int nCycles = 1;
}

bool mEstados::doIt(double now, float cycle){
    float dif = now/1000;
    float wait = cycle*nCycles;
    if(dif > wait){
        state=!state;
        nCycles++;                            
    }
    return state;
}
