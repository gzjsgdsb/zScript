#include "zconsole.h"

#include <iostream>
#include <cstdio>
#include <unistd.h>
#ifdef Q_OS_UNIX
#include <fcntl.h>
#include <termios.h>
#endif

Z_BEGIN_NAMESPACE

ZConsole::ZConsole(ZObject *parent)
    : ZObject(parent)
{
    Z_REGIST_SLOT(&ZConsole::log);
    Z_REGIST_SLOT(&ZConsole::getLine);
    Z_REGIST_SLOT(&ZConsole::getChar);
    Z_REGIST_SLOT(&ZConsole::getCh);
    Z_REGIST_SLOT(&ZConsole::getKey);
    Z_REGIST_SLOT(&ZConsole::kbhit);
    Z_REGIST_SLOT(&ZConsole::setEcho);
}

void ZConsole::log(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(retVals)

    if(args.isEmpty())
        return;

    for(int i = 0; i < args.count() - 1; ++i) {
        const ZVariant &val = args.at(i);

        zStandardPrint << variantToString(val).toStdString() << " ";
    }

    const ZVariant &val = args.last();

    zStandardPrint << variantToString(val).toStdString() << std::endl;

    return;
}

void ZConsole::getLine(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(args)

    char ch[100];

    std::cin.getline(ch, 100, '\n');

    retVals = QString(ch);
}

void ZConsole::getChar(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(args)

    retVals = QString(std::cin.get());
}

void ZConsole::getCh(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(args)

#ifdef Q_OS_UNIX
    struct termios newt, oldt;

    //获取终端属性
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    //设置字符不缓冲且不回显
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    retVals = QString(getchar());
    //还原终端属性
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
}

void ZConsole::getKey(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(args)

#ifdef Q_OS_UNIX
    int oldf;
    struct termios newt, oldt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    //设置字符不缓冲且不回显
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    retVals = int(getchar());
    //还原终端属性
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
#endif
}

void ZConsole::kbhit(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(args)

#ifdef Q_OS_UNIX
    struct termios oldt, newt;

    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        retVals = true;

        return;
    }
#endif

    retVals = false;
}

void ZConsole::setEcho(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(retVals)

    if (args.isEmpty())
        return;

#ifdef Q_OS_UNIX
    struct termios termios;

    tcgetattr(STDIN_FILENO, &termios);

    if (args.first().toBool())
        termios.c_lflag |= ECHO;
    else
        termios.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &termios);
#endif
}

QString ZConsole::variantToString(const ZVariant &val) const
{
    switch (val.type()) {
    case ZVariant::Object:
        return "[Object]";
    case ZVariant::Function:
        return "[Function]";
    case ZVariant::Undefined:
        return "undefined";
    case ZVariant::Tuple: {
        QString str = "<";
        const ZVariant::ZTuple &tuple = val.toTuple();

        for(int i = 0; i < tuple.count() - 1; ++i) {
            str.append(variantToString(*tuple.value(i))).append(", ");
        }

        if(tuple.isEmpty())
            return str.append(">");

        return str.append(variantToString(*tuple.last())).append(">");
    }
    case ZVariant::List: {
        QString str = "[";
        const QList<ZVariant> &list = val.toList();

        for(int i = 0; i < list.count() - 1; ++i) {
            str.append(variantToString(list.value(i))).append(", ");
        }

        if(list.isEmpty())
            return str.append("]");

        return str.append(variantToString(list.last())).append("]");
    }
    case ZVariant::Int:
    case ZVariant::Double:
        return QString::number(val.toDouble());
    default:
        return val.toString();
    }
}

Z_END_NAMESPACE
