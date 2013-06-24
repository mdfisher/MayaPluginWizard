//
// Copyright (C) [!output VENDOR_NAME]
// 
// File: [!output MAYA_TYPE_NAME]Cmd.cpp
//
// MEL Command: [!output MAYA_TYPE_NAME]
//
// Author: Maya Plug-in Wizard 2.0
//

[!if USE_VERBOSE_COMMENTS]
// Includes everything needed to register a simple MEL command with Maya.
// 
[!endif]
#include <maya/MSimple.h>

[!if USE_VERBOSE_COMMENTS]
// Use helper macro to register a command with Maya.  It creates and
// registers a command that does not support undo or redo.  The 
// created class derives off of MPxCommand.
//
[!endif]
DeclareSimpleCommand( [!output MAYA_TYPE_NAME], "[!output VENDOR_NAME]", "[!output MAYA_VERSION]");

MStatus [!output MAYA_TYPE_NAME]::doIt( const MArgList& args )
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
	// Since this class is derived off of MPxCommand, you can use the 
	// inherited methods to return values and set error messages
	//
[!endif]
	setResult( "[!output MAYA_TYPE_NAME] command executed!\n" );

	return stat;
}
