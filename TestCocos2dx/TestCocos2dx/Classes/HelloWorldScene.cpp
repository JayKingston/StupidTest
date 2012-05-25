#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
            "Resources/CloseNormal.png",
            "Resources/CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);


		// ����1-9����
		CCMenuItemImage *pNumItem = 0;
		std::vector<CCMenuItemImage*> vecMenuItem;
		CCMenu* pNumMenu = 0;
		for (int idx = 0; idx < 9; ++idx) {
			pNumItem = CCMenuItemImage::itemFromNormalImage(
				"Resources/ForNum_Normal.png",
				"Resources/ForNum_Select.png",
				this,
				menu_selector(HelloWorld::menuNumCallback));
			CC_BREAK_IF(!pNumItem);
			pNumItem->setTag(idx + 1);
			pNumItem->setPosition(ccp(280 + idx * 48, 60));
			vecMenuItem.push_back(pNumItem);
		}
		pNumMenu = CCMenu::menuWithItems(vecMenuItem[0], vecMenuItem[1], vecMenuItem[2], vecMenuItem[3],
										 vecMenuItem[4], vecMenuItem[5], vecMenuItem[6], vecMenuItem[7],
										 vecMenuItem[8], NULL);
		CC_BREAK_IF(!pNumMenu);
		pNumMenu->setPosition(CCPointZero);
		this->addChild(pNumMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello Soduko", "Thonburi", 64);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 40));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::spriteWithFile("Resources/bk.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);


		// ���ÿ���touch
		setIsTouchEnabled(true);
		m_pLabelMousePos = 0;

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void HelloWorld::menuNumCallback(CCObject* pSender)
{
	if (!pSender) {
		return;
	}

	CCNode* pNode = (CCNode*)pSender;
	if (!pNode) {
		return;
	}

	switch (pNode->getTag()) {
	case 1:
		{
			int a = 0;
		}
		break;
	case 2:
		{
			int a = 0;
		}
		break;
	case 3:
		{
			int a = 0;
		}
		break;
	case 4:
		{
			int a = 0;
		}
		break;
	case 5:
		{
			int a = 0;
		}
		break;
	case 6:
		{
			int a = 0;
		}
		break;
	case 7:
		{
			int a = 0;
		}
		break;
	case 8:
		{
			int a = 0;
		}
		break;
	case 9:
		{
			int a = 0;
		}
		break;
	default:
		break;
	}
}

void HelloWorld::ShowMousePos(CCSet *pTouches)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);

	CCPoint location = touch->locationInView( touch->view() );
	CCPoint convertedLocation = CCDirector::sharedDirector()->convertToGL(location);

	m_strstrMousePos.str("");
	m_strstrMousePos << "Pos:" << convertedLocation.x << "," << convertedLocation.y;
	if (m_pLabelMousePos)
	{
		m_pLabelMousePos->setString(m_strstrMousePos.str().c_str());
	} else
	{

		// ���½����һ����ʾ��ǰ���λ�õ�lable
		m_pLabelMousePos = CCLabelTTF::labelWithString(m_strstrMousePos.str().c_str(), "Arial", 24);
		if (!m_pLabelMousePos) {
			return;
		}
		m_pLabelMousePos->setPosition(ccp(150, 12));
		this->addChild(m_pLabelMousePos, 0);
	}
}


// default implements are used to call script callback if exist
void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	this->ShowMousePos(pTouches);
}
void HelloWorld::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	this->ShowMousePos(pTouches);
}
void HelloWorld::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	this->ShowMousePos(pTouches);
}
