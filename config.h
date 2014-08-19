#ifndef CONFIG_H
#define CONFIG_H
#include <QTextStream>

#define PRINT_LOG_OPEN  1

#if PRINT_LOG_OPEN == 1
#define print_log(...)     qDebug(__VA_ARGS__)
#else
#define print_log(...)
#endif


#define PRINT_COM_OPEN  0
#if PRINT_COM_OPEN == 1
#define print_com(...)     qDebug(__VA_ARGS__)
#else
#define print_com(...)
#endif

#endif // CONFIG_H
