#pragma once
#include <fstream>
#include <utils/json/json.h>
#include <cocos2d.h>
#include <models/CardModel.h>
#include <vector>

// �ؿ���Ϣ������������json�ؿ��ļ�
class LevelConfigLoader
{
public:
	std::vector<CardModel> loadLevelJson(const char* path);
};

