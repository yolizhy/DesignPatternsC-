#include "observer.h"


int main()
{
    Waiter *waiter1 = new Waiter("Lily");
    Waiter *waiter2 = new Waiter("Tom");
    Waiter *waiter3 = new Waiter("John");
    Waiter *waiter4 = new Waiter("Yoli");
    Cook cook;

    cook.Attach(waiter1);
    cook.Attach(waiter2);
    cook.Attach(waiter3);
    cook.Attach(waiter4);
    cook.Talk();
    cook.SetContent("The apple pie is done");
    cook.Talk();
    cook.SetContent("The seafood pizza is done");
    cook.Talk();

    system("PAUSE");

    return 0;
}
