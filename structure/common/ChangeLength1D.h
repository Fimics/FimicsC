//
// Created by pengju.li on 2019-11-01.
//

#ifndef FIMICSCSTRUCTURE_CHANGELENGTH1D_H
#define FIMICSCSTRUCTURE_CHANGELENGTH1D_H

#include "Expect.h"

/**
 * 改变一个数组的长度
 * @tparam T
 * @param a
 * @param oldLength
 * @param newLength
 */
template<class T>
void changeLength1D(T *&a, int oldLength, int newLength) {
    if (newLength < 0) {
        throw illegalParameterValue("new length must be >=0");
    }

    T *temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

#endif //FIMICSCSTRUCTURE_CHANGELENGTH1D_H
