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
CCTransitionJumpZoom::transitionWithDuration(t, s);//��Ծʽ���������Ȼ���С��Ȼ����Ծ����
CCTransitionFade::transitionWithDuration(t, s);//�������룬ԭ�����������³�������
CCTransitionFade::transitionWithDuration(t, s, ccWHITE);//�����һ���ĺ�������3����������������������ǵ����������ɫ
CCTransitionFlipX::transitionWithDuration(t, s, kOrientationLeftOver);//x����
CCTransitionFlipX::transitionWithDuration(t, s, kOrientationRightOver);//x���ҷ�
CCTransitionFlipY::transitionWithDuration(t, s, kOrientationUpOver);//y���Ϸ�
CCTransitionFlipY::transitionWithDuration(t, s, kOrientationDownOver);//y���·�
CCTransitionFlipAngular::transitionWithDuration(t, s, kOrientationLeftOver);//�нǶ�ת����
CCTransitionFlipAngular::transitionWithDuration(t, s, kOrientationRightOver);//�нǶ�ת���ҷ�
CCTransitionZoomFlipX::transitionWithDuration(t, s, kOrientationLeftOver);//������Ч��x����
CCTransitionZoomFlipX::transitionWithDuration(t, s, kOrientationRightOver);//������Ч��x���ҷ�
CCTransitionZoomFlipY::transitionWithDuration(t, s, kOrientationUpOver);//������Ч��y���Ϸ�
CCTransitionZoomFlipY::transitionWithDuration(t, s, kOrientationDownOver);//������Ч��y���·� 
CCTransitionZoomFlipAngular::transitionWithDuration(t, s, kOrientationLeftOver);//������Ч��/�нǶ�ת����
CCTransitionZoomFlipAngular::transitionWithDuration(t, s, kOrientationRightOver);//������Ч���нǶ�ת���ҷ�
CCTransitionShrinkGrow::transitionWithDuration(t, s);//����
CCTransitionRotoZoom::transitionWithDuration(t, s);//ת�ǻ�
CCTransitionMoveInL::transitionWithDuration(t, s);//�³����������븲��
CCTransitionMoveInR::transitionWithDuration(t, s);//�³����������븲��
CCTransitionMoveInT::transitionWithDuration(t, s);//�³����������븲��
CCTransitionMoveInB::transitionWithDuration(t, s);//�³����������븲��
CCTransitionSlideInL::transitionWithDuration(t, s);//�������������Ƴ�ԭ����
CCTransitionSlideInR::transitionWithDuration(t, s);//�������������Ƴ�ԭ����
CCTransitionSlideInT::transitionWithDuration(t, s);//�������������Ƴ�ԭ����
CCTransitionSlideInB::transitionWithDuration(t, s);//�������������Ƴ�ԭ����
����������Ҫ���opengl�汾�Ƿ�֧��CCConfiguration::sharedConfiguration()->getGlesVersion() <= GLES_VER_1_0���Ϊ����Ϊ��֧��
CCTransitionCrossFade::transitionWithDuration(t,s);//�������뽻�棬ͬʱ����
CCTransitionRadialCCW::transitionWithDuration(t,s);//˳ʱ������
CCTransitionRadialCW::transitionWithDuration(t,s);//��ʱ������
����������Ҫ�������������ʹ��CCDirector::sharedDirector()->setDepthTest(true);
CCTransitionPageTurn::transitionWithDuration(t, s, false);//��ҳ��ǰ��
CCTransitionPageTurn::transitionWithDuration(t, s, true);//��ҳ����
CCTransitionFadeTR::transitionWithDuration(t, s);//�����ϲ���
CCTransitionFadeBL::transitionWithDuration(t, s);//�����²���
CCTransitionFadeUp::transitionWithDuration(t, s);//���ϰ�Ҷ��
CCTransitionFadeDown::transitionWithDuration(t, s);//���°�Ҷ��
CCTransitionTurnOffTiles::transitionWithDuration(t, s);//���С����
CCTransitionSplitRows::transitionWithDuration(t, s);//������
CCTransitionSplitCols::transitionWithDuration(t, s);//������
*/
}
