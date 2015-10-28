#ifndef __JW_SCENE_H__
#define __JW_SCENE_H__

#include "Sling.h"

class JWScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void ChangeToMainScene(Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(JWScene);

	//mouse listener
	void onMouseDown(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);
	void onMouseMove(cocos2d::Event* event);
	void onMouseScroll(cocos2d::Event* event);

private:
	Sling sling;

};

#endif // __JW_Scene_H__
