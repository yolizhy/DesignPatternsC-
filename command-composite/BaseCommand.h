

class BaseCommand
{
public:
    virtual ~BaseCommand() {}
    virtual bool Execute() = 0;
    virtual bool Unexecute() = 0;

    static BaseCommand * CreateCommand(const std::string& strCommand)
    {}
};

template <class DerivedCommand>
class RegisterCommandClass
{
public:
    static BaseCommand * Create()
    {
        return new DerivedCommand;
    }
    RegisterCommandClass(const std::string& strId)
    {}
};

