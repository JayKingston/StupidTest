#include "HelloWorldScene.h"
#include "LoginScene.h"

using namespace cocos2d;

CCScene* CLoginScene::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::node();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		CLoginScene *layer = CLoginScene::node();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool CLoginScene::init()
{
	bool bRet = false;
	do 
	{
		//////////////////////////////////////////////////////////////////////////
		// super init first
		//////////////////////////////////////////////////////////////////////////

		CC_BREAK_IF(! CCLayer::init());

		// 1. Add a menu item with "X" image, which is clicked to quit the program.

		// Create a "close" menu item with close icon, it's an auto release object.
		CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
			"Resources/ForNum_Normal.png",
			"Resources/ForNum_Select.png",
			this,
			menu_selector(CLoginScene::menuCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		// Place the menu item bottom-right conner.
		pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width / 2, CCDirector::sharedDirector()->getWinSize().height / 2));

		CCLabelTTF* pNumLabel = CCLabelTTF::labelWithString("Play Soduko", "Thonburi", 24);
		CC_BREAK_IF(! pNumLabel);

		pNumLabel->setPosition(pCloseItem->getPosition());
		this->addChild(pNumLabel, 3);

		// Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		// Add the menu to HelloWorld layer as a child layer.
		this->addChild(pMenu, 1);

		CCDirector::sharedDirector()->setDepthTest(true);

		bRet = true;
	} while (0);

	return bRet;
}

void CLoginScene::menuCloseCallback(CCObject* pSender)
{
	// "close" menu item clicked
//	CCDirector::sharedDirector()->end();

//	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());

	CCScene *pScene = CCTransitionFade::transitionWithDuration(1.5, HelloWorld::scene());
	CCDirector::sharedDirector()->replaceScene(pScene);

/*
CCTransitionJumpZoom::transitionWithDuration(t, s);//跳跃式，本场景先会缩小，然后跳跃进来
CCTransitionFade::transitionWithDuration(t, s);//淡出淡入，原场景淡出，新场景淡入
CCTransitionFade::transitionWithDuration(t, s, ccWHITE);//如果上一个的函数，带3个参数，则第三个参数就是淡出淡入的颜色
CCTransitionFlipX::transitionWithDuration(t, s, kOrientationLeftOver);//x轴左翻
CCTransitionFlipX::transitionWithDuration(t, s, kOrientationRightOver);//x轴右翻
CCTransitionFlipY::transitionWithDuration(t, s, kOrientationUpOver);//y轴上翻
CCTransitionFlipY::transitionWithDuration(t, s, kOrientationDownOver);//y轴下翻
CCTransitionFlipAngular::transitionWithDuration(t, s, kOrientationLeftOver);//有角度转的左翻
CCTransitionFlipAngular::transitionWithDuration(t, s, kOrientationRightOver);//有角度转的右翻
CCTransitionZoomFlipX::transitionWithDuration(t, s, kOrientationLeftOver);//带缩放效果x轴左翻
CCTransitionZoomFlipX::transitionWithDuration(t, s, kOrientationRightOver);//带缩放效果x轴右翻
CCTransitionZoomFlipY::transitionWithDuration(t, s, kOrientationUpOver);//带缩放效果y轴上翻
CCTransitionZoomFlipY::transitionWithDuration(t, s, kOrientationDownOver);//带缩放效果y轴下翻 
CCTransitionZoomFlipAngular::transitionWithDuration(t, s, kOrientationLeftOver);//带缩放效果/有角度转的左翻
CCTransitionZoomFlipAngular::transitionWithDuration(t, s, kOrientationRightOver);//带缩放效果有角度转的右翻
CCTransitionShrinkGrow::transitionWithDuration(t, s);//交错换
CCTransitionRotoZoom::transitionWithDuration(t, s);//转角换
CCTransitionMoveInL::transitionWithDuration(t, s);//新场景从左移入覆盖
CCTransitionMoveInR::transitionWithDuration(t, s);//新场景从右移入覆盖
CCTransitionMoveInT::transitionWithDuration(t, s);//新场景从上移入覆盖
CCTransitionMoveInB::transitionWithDuration(t, s);//新场景从下移入覆盖
CCTransitionSlideInL::transitionWithDuration(t, s);//场景从左移入推出原场景
CCTransitionSlideInR::transitionWithDuration(t, s);//场景从右移入推出原场景
CCTransitionSlideInT::transitionWithDuration(t, s);//场景从上移入推出原场景
CCTransitionSlideInB::transitionWithDuration(t, s);//场景从下移入推出原场景
以下三个需要检测opengl版本是否支持CCConfiguration::sharedConfiguration()->getGlesVersion() <= GLES_VER_1_0如果为真则为不支持
CCTransitionCrossFade::transitionWithDuration(t,s);//淡出淡入交叉，同时进行
CCTransitionRadialCCW::transitionWithDuration(t,s);//顺时针切入
CCTransitionRadialCW::transitionWithDuration(t,s);//逆时针切入
以下两个需要先设置摄像机，使用CCDirector::sharedDirector()->setDepthTest(true);
CCTransitionPageTurn::transitionWithDuration(t, s, false);//翻页，前翻
CCTransitionPageTurn::transitionWithDuration(t, s, true);//翻页，后翻
CCTransitionFadeTR::transitionWithDuration(t, s);//向右上波浪
CCTransitionFadeBL::transitionWithDuration(t, s);//向左下波浪
CCTransitionFadeUp::transitionWithDuration(t, s);//向上百叶窗
CCTransitionFadeDown::transitionWithDuration(t, s);//向下百叶窗
CCTransitionTurnOffTiles::transitionWithDuration(t, s);//随机小方块
CCTransitionSplitRows::transitionWithDuration(t, s);//按行切
CCTransitionSplitCols::transitionWithDuration(t, s);//按列切
*/
}
