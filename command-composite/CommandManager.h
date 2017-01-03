#include <stack>
#include "BaseCommandManager.h"


#define EVENT_UNDOREDOSTATECHANGED  1

class BaseCommand;

class CommandManager : public BaseCommandManager, public Subject
{
    class UndoRedoStateInspector
    {
        friend class CommandManager;

    private:
        UndoRedoStateInspector(CommandManager * pCommandManager);
        ~UndoRedoStateInspector();

    private:
        CommandManager * m_pCommandManager;
        bool m_bUndoable;
        bool m_bRedoable;
    };

private:
    CommandManager();
	~CommandManager();
    CommandManager(const CommandManager& rhs);
    CommandManager& operator=(const CommandManager& rhs);

public:
    static CommandManager * Instance();

    bool CallCommand(BaseCommand * pCommand);
	void ClearAllCommands();
    void Undo();
    void Redo();
    bool CanUndo() const;
    bool CanRedo() const;

private:
    void PushUndoCommand(BaseCommand * pCommand);
    BaseCommand * PopUndoCommand();
    void PushRedoCommand(BaseCommand * pCommand);
    BaseCommand * PopRedoCommand();
    void DeleteUndoCommands();
    void DeleteRedoCommands();

private:
    std::stack<BaseCommand *> m_stackUndo;
    std::stack<BaseCommand *> m_stackRedo;
};
