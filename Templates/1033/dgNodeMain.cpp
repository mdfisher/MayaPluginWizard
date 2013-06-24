//
// Copyright (C) [!output VENDOR_NAME]
// 
// File: pluginMain.cpp
//
// Author: Maya Plug-in Wizard 2.0
//

#include "[!output MAYA_TYPE_NAME]Node.h"

#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
//
//	Description:
//		this method is called when the plug-in is loaded into Maya.  It 
//		registers all of the services that this plug-in provides with 
//		Maya.
//
//	Arguments:
//		obj - a handle to the plug-in object (use MFnPlugin to access it)
//
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "[!output VENDOR_NAME]", "[!output MAYA_VERSION]", "Any");

	status = plugin.registerNode( "[!output MAYA_TYPE_NAME]", [!output MAYA_TYPE_NAME]::id, [!output MAYA_TYPE_NAME]::creator,
								  [!output MAYA_TYPE_NAME]::initialize );
	if (!status) {
		status.perror("registerNode");
		return status;
	}

	return status;
}

MStatus uninitializePlugin( MObject obj)
//
//	Description:
//		this method is called when the plug-in is unloaded from Maya. It 
//		deregisters all of the services that it was providing.
//
//	Arguments:
//		obj - a handle to the plug-in object (use MFnPlugin to access it)
//
{
	MStatus   status;
	MFnPlugin plugin( obj );

	status = plugin.deregisterNode( [!output MAYA_TYPE_NAME]::id );
	if (!status) {
		status.perror("deregisterNode");
		return status;
	}

	return status;
}
