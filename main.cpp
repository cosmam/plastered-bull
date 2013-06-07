#include <QApplication>

#include "testchasis.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Test::TestChasis * chasis = new Test::TestChasis();

    chasis->CreateObjects();
    int status = chasis->RunTests();

    delete chasis;

    return status;
}
