#ifndef _[!output MAYA_TYPE_NAME]Cmd
#define _[!output MAYA_TYPE_NAME]Cmd
//
// Copyright (C) [!output VENDOR_NAME]
// 
// File: [!output MAYA_TYPE_NAME]Cmd.h
//
// MEL Command: [!output MAYA_TYPE_NAME]
//
// Author: Maya Plug-in Wizard 2.0
//

#include <maya/MPxCommand.h>

class MArgList;

class [!output MAYA_TYPE_NAME] : public MPxCommand
{

public:
				[!output MAYA_TYPE_NAME]();
	virtual		~[!output MAYA_TYPE_NAME]();

	MStatus		doIt( const MArgList& );
	MStatus		redoIt();
	MStatus		undoIt();
	bool		isUndoable() const;

	static		void* creator();

[!if USE_VERBOSE_COMMENTS]
private:
	// Store the data you will need to undo the command here
	//
[!endif]
};

#endif
