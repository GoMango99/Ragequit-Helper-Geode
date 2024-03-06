#include <Geode/Geode.hpp>


FLAlertLayer* info_alert = nullptr;

class $modify(ModPauseLayer, PauseLayer) {
	static void onModify(auto& self) {
        self.setHookPriority("PauseLayer::customSetup", INT_MIN);
    }

	void customSetup() {
		PauseLayer::customSetup();

		auto winSize = CCDirector::get()->getWinSize();
		auto level = PlayLayer::get()->m_level;

		auto menu = this->getChildByID("bottom-button-menu");

		auto btn_spr = CCSprite::createWithSpriteFrameName("GJ_deleteBtn_001.png");
		auto btn = CCMenuItemSpriteExtra::create(
			btn_spr,
			this,
			menu_selector(ModPauseLayer::onInfo)
		);

		btn->setID("info-button");
		btn->setPosition({menu->getContentSize().width/2, btn->getContentSize().height/2});
		menu->addChild(btn);

		menu->setLayout(
			ColumnLayout::create()
				->setGap(4.f)
				->setAutoScale(true)
				->setAxisAlignment(AxisAlignment::Start)
				->setCrossAxisAlignment(AxisAlignment::Center)
   		);
		menu->updateLayout();

	}

	void onInfo(CCObject* sender) {
geode::createQuickPopup(
    "RAGE QUIT",            // title
    "Do you want to ragequit?",   // content
    "Nah", "Yeah",      // buttons
    [](auto, bool btn2) {
        if (btn2) {
            geode::createQuickPopup(
    "RAGE QUIT CONFIRM",            // title
    "Are you sure?",   // content
    "Nevermind", "Yes I'm ANGRY",      // buttons
    [](auto, bool btn2) {
        if (btn2) {
            exit(0);
        }
    }
);
        }
    }
);

	}

	void onResume(CCObject* sender) {
		CCDirector::get()->getRunningScene()->removeChildByID("info-alert");
		PauseLayer::onResume(sender);
	}
};