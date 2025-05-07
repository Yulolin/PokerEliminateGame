#include "LevelConfigLoader.h"

std::vector<CardModel> LevelConfigLoader::loadLevelJson(const char* path) {
	// ʹ�������������ȡjson�ļ��Զ����Ƶ���ʽ��ȡ
	std::fstream ifs;
	ifs.open(path, std::ios::binary | std::ios::in);
	if (!ifs.is_open()) {
		printf("Error  loading: %s\n", path);
		return std::vector<CardModel>();
	}
	// ��ȡ���Ķ������ļ� ����jsoncpp��ȡ���е�����
	Json::Reader reader;
	Json::Value root;

	std::vector<CardModel> cardModels;
	if (ifs.is_open())
	{
		if (reader.parse(ifs, root))
		{
			// �Ѿ�����ȡ���ı��ĵ����뵽Json::Value root��������
			// Json::Value ���͵Ķ������
			for each (auto var in root["Playfield"])
			{
				int cardSuit = var["CardSuit"].asInt();
				int cardFace = var["CardFace"].asInt();
				cocos2d::Vec2 position = cocos2d::Vec2(var["Position"]["x"].asFloat(), var["Position"]["y"].asFloat());
				CardFieldType cardField = CFT_PLAYERFIELD;
				cardModels.push_back(CardModel(cardFace, cardSuit, position, cardField));
			}
			for each (auto var in root["Stack"])
			{
				int cardSuit = var["CardSuit"].asInt();
				int cardFace = var["CardFace"].asInt();
				cocos2d::Vec2 position = cocos2d::Vec2(var["Position"]["x"].asFloat(), var["Position"]["y"].asFloat());
				CardFieldType cardField = CFT_HAND;
				cardModels.push_back(CardModel(cardFace, cardSuit, position, cardField));
			}
		}
	}
	return cardModels;
}
