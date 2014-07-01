// automodeController.c : implementation file
#include "automodeController.h"
#include "type.h"
//#include "automodeTasks.c"

void tasks()
{
test2();
//Add tasks here

}

void autoloop()
{

char quitloop = 0;

while (!quitloop)
{
syncBeforeLoop();

tasks();

syncAfterLoop();
}

}

