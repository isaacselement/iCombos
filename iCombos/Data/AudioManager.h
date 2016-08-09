#ifndef __iCombos__AudioManager__
#define __iCombos__AudioManager__

#include "Interval.h"

class AudionManager
{
private:
    
    rapidjson::Value& getAudioConfig();
    void preloadAudio(const char* filename);
    void playAudio(const char* filename);
    
    
public:
    
    static AudionManager* getInstance();
    AudionManager();
    virtual ~AudionManager();
    virtual bool init();
    
    
    
    void preloadGameAudios();
    
    void playStartGameAudio();
    void playShootAudio();
    void playExplosionAudio();
};

#endif /* defined(__iCombos__AudioManager__) */
