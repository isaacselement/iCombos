#ifndef iCombos_Classes_h
#define iCombos_Classes_h


// Chinoiserie

#include "_Json_.h"

#include "_Frame_.h"

#include "_String_.h"

#include "_Number_.h"


// Cocos

#include "Interval.h"

#include "SimpleAudioEngine.h"





// data

#include "DataManager.h"

#include "StateManager.h"

#include "AudioManager.h"




// helpers

#include "CountdownTimer.h"
#include "ViewScheduler.h"


// views

#include "ViewManager.h"


// layers

#include "LayerManager.h"

#include "MainLayer.h"

#include "StatisticsPanel.h"

#include "StatisticsElement.h"

#include "TimerElement.h"


// effects

#include "EffectManager.h"


// sprites

#include "Role.h"
#include "Spear.h"
#include "Shield.h"



// events

#include "EventManager.h"


// PHYSICAL_BODY related
const int SHIELD_GROUP = -2;
const int SHIELD_BITMASK_CATEGORY = 0x01;
const int SHIELD_BITMASK_COLLISION = 0x02;
const int SHIELD_BITMASK_CONTACT_TEST = 0x02;

const int SPEAR_GROUP = -1;
const int SPEAR_BITMASK_CATEGORY = 0x02;
const int SPEAR_BITMASK_COLLISION = 0x01;
const int SPEAR_BITMASK_CONTACT_TEST = 0x01;



#endif
