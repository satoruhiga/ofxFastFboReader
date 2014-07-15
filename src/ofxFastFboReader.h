#pragma once

#include "ofMain.h"

class ofxFastFboReader
{
public:
	
	ofxFastFboReader(const int num_buffers = 3);
	~ofxFastFboReader();
	
	bool readToPixels(ofFbo &fbo, ofPixelsRef pix, ofImageType type = OF_IMAGE_COLOR);
	
	bool getAsync() { return async; }
	void setAsync(bool v) { async = v; }
	
protected:
	
	const int num_buffers;
	
	GLuint *pboIds;
	int index, nextIndex;
	size_t num_bytes;
	bool async;
	
	ofxFastFboReader(const ofxFastFboReader&);
	ofxFastFboReader& operator=(const ofxFastFboReader&);
	
	void genPBOs();
	void setupPBOs(int num_bytes);
	
};