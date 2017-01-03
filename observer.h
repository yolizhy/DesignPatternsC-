#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>
#include <iterator>
#include <iostream>
#include <cstdlib>

using namespace std;


class Subject;

class Observer
{
public:
    virtual void Listen(Subject *aSubject) = 0;
    virtual ~Observer(){}
protected:
    Observer(){};
};

class Waiter : public Observer
{
public:
    Waiter(char* = "waiter");
    char *GetName() const;
    virtual void Listen(Subject *aSubject);
private:
    char *name;
};

class Subject
{
public:
    virtual ~Subject(){};
    virtual void Attach(Observer *aObserver) = 0;
    virtual void Talk() = 0;
    virtual char *GetContent() const = 0;
    virtual void SetContent(char *aContent) = 0;
protected:
    Subject(){};
};

class Cook : public Subject
{
public:
    Cook();
    virtual void Attach(Observer *aObserver);
    virtual void Talk();
    virtual char *GetContent() const;
    virtual void SetContent(char *aContent);
private:
    std::list<Observer *> observerList;
    char *content;
};

Waiter::Waiter(char *aName)
{
    name = aName;
}

void Waiter::Listen(Subject *aSubject)
{
    cout << GetName() << "- the cook says:" << aSubject->GetContent() << std::endl;
}

char *Waiter::GetName() const
{
    return name;
}

Cook::Cook()
{
    content = "Please deliver the menus";
}

void Cook::Attach(Observer *aObserver)
{
    observerList.push_back(aObserver);
}

void Cook::SetContent(char *aContent)
{
    content = aContent;
}

void Cook::Talk()
{
    std::list<Observer *>::iterator waiters;
    for(waiters = observerList.begin() ; waiters != observerList.end() ; ++waiters)
    {
    ((Observer *)(*waiters))->Listen(this);
    }
}

char *Cook::GetContent() const
{
    return content;
}

#endif

