//
// Copyright (C) [!output VENDOR_NAME]
// 
// File: [!output MAYA_TYPE_NAME]Node.cpp
//
// Dependency Graph Node: [!output MAYA_TYPE_NAME]
//
// Author: Maya Plug-in Wizard 2.0
//

#include "[!output MAYA_TYPE_NAME]Node.h"

#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>

#include <maya/MGlobal.h>

// You MUST change this to a unique value!!!  The id is a 32bit value used
// to identify this type of node in the binary file format.  
//
#error change the following to a unique value and then erase this line 
MTypeId     [!output MAYA_TYPE_NAME]::id( 0x00001 );

[!if USE_VERBOSE_COMMENTS]
// Example attributes
// 
[!endif]
MObject     [!output MAYA_TYPE_NAME]::input;        
MObject     [!output MAYA_TYPE_NAME]::output;       

[!output MAYA_TYPE_NAME]::[!output MAYA_TYPE_NAME]() {}
[!output MAYA_TYPE_NAME]::~[!output MAYA_TYPE_NAME]() {}

MStatus [!output MAYA_TYPE_NAME]::compute( const MPlug& plug, MDataBlock& data )
//
//	Description:
//		This method computes the value of the given output plug based
//		on the values of the input attributes.
//
//	Arguments:
//		plug - the plug to compute
//		data - object that provides access to the attributes for this node
//
{
	MStatus returnStatus;
 
[!if USE_VERBOSE_COMMENTS]
	// Check which output attribute we have been asked to compute.  If this 
	// node doesn't know how to compute it, we must return 
	// MS::kUnknownParameter.
	// 
[!endif]
	if( plug == output )
	{
[!if USE_VERBOSE_COMMENTS]
		// Get a handle to the input attribute that we will need for the
		// computation.  If the value is being supplied via a connection 
		// in the dependency graph, then this call will cause all upstream  
		// connections to be evaluated so that the correct value is supplied.
		// 
[!endif]
		MDataHandle inputData = data.inputValue( input, &returnStatus );

		if( returnStatus != MS::kSuccess )
			MGlobal::displayError( "Node [!output MAYA_TYPE_NAME] cannot get value\n" );
		else
		{
[!if USE_VERBOSE_COMMENTS]
			// Read the input value from the handle.
			//
[!endif]
			float result = inputData.asFloat();

[!if USE_VERBOSE_COMMENTS]
			// Get a handle to the output attribute.  This is similar to the
			// "inputValue" call above except that no dependency graph 
			// computation will be done as a result of this call.
			// 
[!endif]
			MDataHandle outputHandle = data.outputValue( [!output MAYA_TYPE_NAME]::output );
[!if USE_VERBOSE_COMMENTS]
			// This just copies the input value through to the output.  
			// 
[!endif]
			outputHandle.set( result );
[!if USE_VERBOSE_COMMENTS]
			// Mark the destination plug as being clean.  This will prevent the
			// dependency graph from repeating this calculation until an input 
			// of this node changes.
			// 
[!endif]
			data.setClean(plug);
		}
	} else {
		return MS::kUnknownParameter;
	}

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

MStatus [!output MAYA_TYPE_NAME]::initialize()
//
//	Description:
//		This method is called to create and initialize all of the attributes
//      and attribute dependencies for this node type.  This is only called 
//		once when the node type is registered with Maya.
//
//	Return Values:
//		MS::kSuccess
//		MS::kFailure
//		
{
[!if USE_VERBOSE_COMMENTS]
	// This sample creates a single input float attribute and a single
	// output float attribute.
	//
[!endif]
	MFnNumericAttribute nAttr;
	MStatus				stat;

	input = nAttr.create( "input", "in", MFnNumericData::kFloat, 0.0 );
[!if USE_VERBOSE_COMMENTS]
	// Attribute will be written to files when this type of node is stored
[!endif]
 	nAttr.setStorable(true);
[!if USE_VERBOSE_COMMENTS]
	// Attribute is keyable and will show up in the channel box
[!endif]
 	nAttr.setKeyable(true);

	output = nAttr.create( "output", "out", MFnNumericData::kFloat, 0.0 );
[!if USE_VERBOSE_COMMENTS]
	// Attribute is read-only because it is an output attribute
[!endif]
	nAttr.setWritable(false);
[!if USE_VERBOSE_COMMENTS]
	// Attribute will not be written to files when this type of node is stored
[!endif]
	nAttr.setStorable(false);

[!if USE_VERBOSE_COMMENTS]
	// Add the attributes we have created to the node
	//
[!endif]
	stat = addAttribute( input );
		if (!stat) { stat.perror("addAttribute"); return stat;}
	stat = addAttribute( output );
		if (!stat) { stat.perror("addAttribute"); return stat;}

[!if USE_VERBOSE_COMMENTS]
	// Set up a dependency between the input and the output.  This will cause
	// the output to be marked dirty when the input changes.  The output will
	// then be recomputed the next time the value of the output is requested.
	//
[!endif]
	stat = attributeAffects( input, output );
		if (!stat) { stat.perror("attributeAffects"); return stat;}

	return MS::kSuccess;

}

