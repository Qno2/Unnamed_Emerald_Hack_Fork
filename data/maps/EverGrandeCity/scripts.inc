.set LOCALID_RIVAL, 3

EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"


PetalburgCity_EventScript_RivalEncounter::
	lockall
	setobjectxyperm LOCALID_RIVAL, 18, 50
	addobject LOCALID_RIVAL
	goto_if_set FLAG_RIVAL_EVERGRANDE, EvergrandeCity_EventScript_NoRival
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EvergrandeCity_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EvergrandeCity_EventScript_PlayBrendanMusic
	delay 65
	applymovement LOCALID_RIVAL, EvergrandeCity_Movement_RivalEnter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, EvergrandeCity_Movement_FaceRival
	waitmovement 0
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EvergrandeCity_EventScript_BattleMay
	goto_if_eq VAR_RESULT, FEMALE, EvergrandeCity_EventScript_BattleBrendan
	releaseall
	end

EvergrandeCity_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto EvergrandeCity_EventScript_RivalEncounter
	end

EvergrandeCity_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto EvergrandeCity_EventScript_RivalEncounter
	end

EvergrandeCity_EventScript_NoRival::
	removeobject LOCALID_RIVAL
	end

EvergrandeCity_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return	

EvergrandeCity_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return	

EvergrandeCity_EventScript_BattleMay::
	msgbox EvergrandeCity_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, EvergrandeCity_EventScript_BattleMayTreecko
	case 1, EvergrandeCity_EventScript_BattleMayTorchic
	case 2, EvergrandeCity_EventScript_BattleMayMudkip
	end

EvergrandeCity_EventScript_BattleBrendan::
	msgbox EvergrandeCity_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, EvergrandeCity_EventScript_BattleBrendanTreecko
	case 1, EvergrandeCity_EventScript_BattleBrendanTorchic
	case 2, EvergrandeCity_EventScript_BattleBrendanMudkip
	end

EvergrandeCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_EVERGRAND_TREECKO, EvergrandeCity_Text_MayDefeat
	msgbox EvergrandeCity_Text_MayAfterBattle, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, EvergrandeCity_Movement_RivalLeave
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_RIVAL
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RIVAL_EVERGRANDE
	releaseall
	end

EvergrandeCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_EVERGRAND_TORCHIC, EvergrandeCity_Text_MayDefeat
	msgbox EvergrandeCity_Text_MayAfterBattle, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, EvergrandeCity_Movement_RivalLeave
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_RIVAL
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RIVAL_EVERGRANDE
	releaseall
	end

EvergrandeCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_EVERGRAND_MUDKIP, EvergrandeCity_Text_MayDefeat
	msgbox EvergrandeCity_Text_MayAfterBattle, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, EvergrandeCity_Movement_RivalLeave
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_RIVAL
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RIVAL_EVERGRANDE
	releaseall
	end

EvergrandeCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_EVERGRAND_TREECKO, EvergrandeCity_Text_BrendanDefeat
	msgbox EvergrandeCity_Text_BrendanAfterBattle, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, EvergrandeCity_Movement_RivalLeave
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_RIVAL
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RIVAL_EVERGRANDE
	releaseall
	end

EvergrandeCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_EVERGRAND_TORCHIC, EvergrandeCity_Text_BrendanDefeat
	msgbox EvergrandeCity_Text_BrendanAfterBattle, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, EvergrandeCity_Movement_RivalLeave
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_RIVAL
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RIVAL_EVERGRANDE
	releaseall
	end

EvergrandeCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_EVERGRAND_MUDKIP, EvergrandeCity_Text_BrendanDefeat
	msgbox EvergrandeCity_Text_BrendanAfterBattle, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, EvergrandeCity_Movement_RivalLeave
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_RIVAL
	fadescreen FADE_FROM_BLACK
	setflag FLAG_RIVAL_EVERGRANDE
	releaseall
	end

EvergrandeCity_Movement_RivalEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EvergrandeCity_Movement_FaceRival:
	face_down
	step_end

EvergrandeCity_Movement_RivalLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EvergrandeCity_Text_MayIntro:
	.string "MAY: Hi {PLAYER}.\p"
	.string "I heard you got involved\n"
	.string "in that mess at Sootopolos.\p"
	.string "I hope you didn't get\n"
	.string "hurt.\p"
	.string "Anyway, if you're off into\n"
	.string "Victory Road, I need to see\n"
	.string "if you are ready first.\p"
	.string "Here I come!$"

EvergrandeCity_Text_MayDefeat:
	.string "Wow. You're as strong as\n"
	.string "ever.$"

EvergrandeCity_Text_MayAfterBattle:
	.string "Looks like I had no\n"
	.string "chance.\p"
	.string "For now, I'm heading\n"
	.string "back to Littleroot as I\n"
	.string "need to help my Dad.\p"
	.string "Good luck with your\n"
	.string "Pokemon League challange.\n"
	.string "You'll be great!$"

EvergrandeCity_Text_BrendanIntro:
	.string "BRENDAN: "Hey {PLAYER}.\p"
	.string "I heard you fixed that\n"
	.string "freak weather in Sootopolos.\p"
	.string "I know you're strong but I\n"
	.string "think I need to see one\n"
	.string "more time for myself.\p"
	.string "Let's go!$"

EvergrandeCity_Text_BrendanDefeat:
	.string "I expected this but\n"
	.string "it still stings.$"

EvergrandeCity_Text_BrendanAfterBattle:
	.string "I even had a headstart on\n"
	.string "you as a trainer so it\n"
	.string "doesn't feel great to\n"
	.string "lose to you./p"
	.string ".../p"
	.string "I'm heading back to\n"
	.string "Littleroot to help out\n"
	.string "my Dad with some things.\p"
	.string "I'll see you around.$"
