// SPDX-License-Identifier: Apache-2.0
// Copyright 2021 - 2025, the Anboto author and contributors
#ifndef _FTGL_Demo_TrackBall_h_
#define _FTGL_Demo_TrackBall_h_

#include <CtrlLib/CtrlLib.h>

namespace Upp {
	
class TrackBall {
public:
	typedef TrackBall CLASSNAME;

	TrackBall();
	void Init(int buttonRot);
	
	void Matrix(void);
	void Reshape(int width, int height);
	void SetZoomAngle(double angle)			{zoomAngle = angle;}
	double GetZoomAngle()					{return zoomAngle;}
	void SetButtonRot(int but = Ctrl::LEFT) {buttonRot = but; }
	
	virtual Image MouseEvent(int event, Point p, int zdelta, dword keyflags);
	
	void Zoom(int zdelta);
	void ViewXYZ(bool x, bool y, bool z);
	
	double curquat[4];
	
private:
	double lastquat[4];
	int beginx, beginy;
	
	int width, height;
	
	int buttonRot = Ctrl::LEFT;
	bool tracking;
	bool sign;
	
	double zoomAngle;
};

}

#endif
