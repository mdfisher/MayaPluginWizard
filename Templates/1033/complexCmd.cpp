//
// Copyright (C) [!output VENDOR_NAME]
// 
// File: [!output MAYA_TYPE_NAME]Cmd.cpp
//
// MEL Command: [!output MAYA_TYPE_NAME]
//
// Author: Maya Plug-in Wizard 2.0
//

#include "[!output MAYA_TYPE_NAME]Cmd.h"

#include <maya/MGlobal.h>

MStatus [!output MAYA_TYPE_NAME]::doIt( const MArgList& )
//
//	Description:
//		implements the MEL [!output MAYA_TYPE_NAME] command.
//
//	Arguments:
//		args - the argument list that was passes to the command from MEL
//
//	Return Value:
//		MS::kSuccess - command succeeded
[!if USE_VERBOSE_COMMENTS]
//		MS::kFailure - command failed (returning this value will cause the 
//                     MEL script that is being run to terminate unless the
//                     error is caught using a "catch" statement.
[!else]
//		MS::kFailure - command failed
[!endif]
//
{
	MStatus stat = MS::kSuccess;


[!if USE_VERBOSE_COMMENTS]
	// Typically, the doIt() method only collects the infomation required
	// to do/undo the action and then stores it in class members.  The 
	// redo method is then called to do the actuall work.  This prevents
	// code duplication.
	//
[!endif]
	return redoIt();
}

MStatus [!output MAYA_TYPE_NAME]::redoIt()
//
//	Description:
//		implements redo for the MEL [!output MAYA_TYPE_NAME] command. 
//
[!if USE_VERBOSE_COMMENTS]
//		This method is called when the user has undone a command of this type
//		and then redoes it.  No arguments are passed in as all of the necessary
//		information is cached by the doIt method.
[!endif]
//
//	Return Value:
//		MS::kSuccess - command succeeded
//		MS::kFailure - redoIt failed.  this is a serious problem that will
//                     likely cause the undo queue to be purged
//
{
[!if USE_VERBOSE_COMMENTS]
	// Since this class is derived off of MPxCommand, you can use the 
	// inherited methods to return values and set error messages
	//
[!endif]
	setResult( "[!output MAYA_TYPE_NAME] command executed!\n" );

	return MS::kSuccess;
}

MStatus [!output MAYA_TYPE_NAME]::undoIt()
//
//	Description:
//		implements undo for the MEL [!output MAYA_TYPE_NAME] command.  
//
[!if USE_VERBOSE_COMMENTS]
//		This method is called to undo a previous command of this type.  The 
//		system should be returned to the exact state that it was it previous 
//		to this command being executed.  That includes the selection state.
[!endif]
//
//	Return Value:
//		MS::kSuccess - command succeeded
//		MS::kFailure - redoIt failed.  this is a serious problem that will
//                     likely cause the undo queue to be purged
//
{

[!if USE_VERBOSE_COMMENTS]
	// You can also display information to the command window via MGlobal
	//
[!endif]
    MGlobal::displayInfo( "[!output MAYA_TYPE_NAME] command undone!\n" );

	return MS::kSuccess;
}

void* [!output MAYA_TYPE_NAME]::creator()
//
//	Description:
//		this method exists to give Maya a way to create new objects
//      of this type. 
//
//	Return Value:
//		a new object of this type
//
{
	return new [!output MAYA_TYPE_NAME]();
}

[!output MAYA_TYPE_NAME]::[!output MAYA_TYPE_NAME]()
//
//	Description:
//		[!output MAYA_TYPE_NAME] constructor
//
{}

[!output MAYA_TYPE_NAME]::~[!output MAYA_TYPE_NAME]()
//
//	Description:
//		[!output MAYA_TYPE_NAME] destructor
//
{
}

bool [!output MAYA_TYPE_NAME]::isUndoable() const
//
//	Description:
//		this method tells Maya this command is undoable.  It is added to the 
//		undo queue if it is.
//
//	Return Value:
//		true if this command is undoable.
//
{
	return true;
}
