#include "AudioManager.h"
#include "Classes.h"

static AudionManager* s_sharedAudionManager = nullptr;
AudionManager* AudionManager::getInstance()
{
    if (!s_sharedAudionManager) {
        s_sharedAudionManager = new (std::nothrow) AudionManager();
        CCASSERT(s_sharedAudionManager, "Fatal: no enough memory");
        s_sharedAudionManager->init();
    }
    return s_sharedAudionManager;
}

AudionManager::AudionManager()
{
    
}

AudionManager::~AudionManager()
{
    
}

bool AudionManager::init()
{
    preloadGameAudios();
    return true;
}

rapidjson::Value& AudionManager::getAudioConfig()
{
    return DataManager::getInstance()->configs["Audio"];
}

void AudionManager::preloadGameAudios()
{
    rapidjson::Value& audioObj = getAudioConfig();
    for(rapidjson::Value::MemberIterator it = audioObj.MemberBegin(); it != audioObj.MemberEnd(); it++) {
        const char* value = (it->value).GetString();
        preloadAudio(value);
    }
}

void AudionManager::preloadAudio(const char* filename)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(filename);
}

void AudionManager::playAudio(const char *filename)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(filename);
}


#pragma mark - Public Methods

void AudionManager::playStartGameAudio()
{
    const char* audio_startgame = getAudioConfig()["StartGame"].GetString();
    playAudio(audio_startgame);
}

void AudionManager::playShootAudio()
{
    const char* audio_shoot = getAudioConfig()["Shoot"].GetString();
    playAudio(audio_shoot);
}

void AudionManager::playExplosionAudio()
{
    const char* audio_hit = getAudioConfig()["Hit"].GetString();
    playAudio(audio_hit);
}



