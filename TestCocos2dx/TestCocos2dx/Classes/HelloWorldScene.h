#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <sstream>
#include "cocos2d.h"
#include "CCTouch.h"

#include "SimpleAudioEngine.h"

class cocos2d::CCLabelTTF;
class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    virtual void menuCloseCallback(CCObject* pSender);

	// a selector callback
	virtual void menuNumCallback(CCObject* pSender);

	// default implements are used to call script callback if exist
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);


    // implement the "static node()" method manually
    LAYER_NODE_FUNC(HelloWorld);

private:
	void ShowMousePos(cocos2d::CCSet *pTouches);

private:
	cocos2d::CCLabelTTF* m_pLabelMousePos;
	std::stringstream m_strstrMousePos;
};

#endif  // __HELLOWORLD_SCENE_H__