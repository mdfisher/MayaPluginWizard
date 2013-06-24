#ifndef _[!output MAYA_TYPE_NAME]Node
#define _[!output MAYA_TYPE_NAME]Node
//
// Copyright (C) [!output VENDOR_NAME]
// 
// File: [!output MAYA_TYPE_NAME]Node.h
//
// Dependency Graph Node: [!output MAYA_TYPE_NAME]
//
// Author: Maya Plug-in Wizard 2.0
//

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MTypeId.h> 

 
class [!output MAYA_TYPE_NAME] : public MPxNode
{
public:
						[!output MAYA_TYPE_NAME]();
	virtual				~[!output MAYA_TYPE_NAME](); 

	virtual MStatus		compute( const MPlug& plug, MDataBlock& data );

	static  void*		creator();
	static  MStatus		initialize();

public:

[!if USE_VERBOSE_COMMENTS]
	// There needs to be a MObject handle declared for each attribute that
	// the node will have.  These handles are needed for getting and setting
	// the values later.
	//
[!endif]
	static  MObject		input;		// Example input attribute
	static  MObject		output;		// Example output attribute


[!if USE_VERBOSE_COMMENTS]
	// The typeid is a unique 32bit indentifier that describes this node.
	// It is used to save and retrieve nodes of this type from the binary
	// file format.  If it is not unique, it will cause file IO problems.
	//
[!endif]
	static	MTypeId		id;
};

#endif
