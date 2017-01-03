#include "command.h"

int main()
{
	Commander *p = new Commander( new InputCommand( "[empty]" ) );

	p->ExecuteCommand( new InputCommand( "beef noodle" ) );
	p->ExecuteCommand( new InputCommand( "curry rice" ) );
	p->ExecuteCommand( new InputCommand( "apple pie" ) );

	p->Undo();
	p->Undo();

	p->ExecuteCommand( new InputCommand( "banana pancake" ) );

	p->Undo();
    p->Undo();

    p->Redo();

	p->Undo();

	delete p;
	return 0;
}
