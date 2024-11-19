#include "test.h"
#include "wait.h"

int main(){
    volatile long index = 350000;
    while (index) index--;
    run_test();
}
