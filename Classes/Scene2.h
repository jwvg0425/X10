#ifndef __SCENE2_H__
#define __SCENE2_H__

#include "cocos2d.h"

USING_NS_CC;

class Scene2 : public Layer
{
public:
	static Scene* scene();
	void nextSceneCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(Scene2);
	virtual bool init();
};
#endif