#ifndef UTILS_H
#define UTILS_H

#define swap(a, b) \
        { \
            __typeof__(a) temp = a; \
            a = b; \
            b = temp; \
        }

#endif
