OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "When POKéMON battle, they eventually\n"
	.string "level up and become stronger.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "If the POKéMON with you become\n"
	.string "stronger, you'll be able to go farther\l"
	.string "away from here.$"


OldaleTown_House2_EventScript_RareCandy::
	lock
	faceplayer
	msgbox OldaleTown_House2_Text_RareCandy, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleTown_House2_EventScript_PlayerSaidNo
	checkitemspace ITEM_RARE_CANDY, 990
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_House2_EventScript_NoSpace
	msgbox OldaleTown_House2_Text_GivingRareCandy, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 990
	msgbox OldaleTown_House2_Text_GivenCandy, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_PlayerSaidNo::
	msgbox OldaleTown_House2_Text_PlayerSaidNo, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_NoSpace::
	msgbox OldaleTown_House2_Text_NoSpace, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Text_RareCandy:
	.string "I can give you 990 Rare Candies.\n"
	.string "Would you like that?$"

OldaleTown_House2_Text_PlayerSaidNo:
	.string "Oh, ok then. Come back if\n"
	.string "you change your mind.$"

OldaleTown_House2_Text_NoSpace:
	.string "Oh, I'm sorry. You don't\n"
	.string "appear to have enough space.$"

OldaleTown_House2_Text_GivingRareCandy:
	.string "Ok, here you go!$"

OldaleTown_House2_Text_GivenCandy:
	.string "Just come back if you need more.$"


OldaleTown_House2_EventScript_ExplainerMan::
	lock
	faceplayer
	msgbox OldaleTown_House2_Text_Explainer, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Text_Explainer:
	.string "Hello and welcome to the\n"
	.string "Cheat House.\p"
	.string "The people in here can give\n"
	.string "you things that some may find\l"
	.string "give you an unfair advantage.\p"
	.string "So please read carfully what\n"
	.string "they offer before accepting.\p"
	.string "The man on the right of the\n"
	.string "table will give you rare candies.\p"
	.string "This might be useful to nuzlockers\n"
	.string "who play with level caps.\p"
	.string "The woman on the left will give\n"
	.string "you heart scales.\p"
	.string "The dev hasn't given the other\n"
	.string "people roles yet so don't worry\l"
	.string "about them. Enjoy!$"


OldaleTown_House2_EventScript_HeartScale::
	lock
	faceplayer
	msgbox OldaleTown_House2_Text_HeartScale, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq OldaleTown_House2_EventScript_PlayerSaidNo
	checkitemspace ITEM_HEART_SCALE, 90 
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_House2_EventScript_NoSpace
	msgbox OldaleTown_House2_Text_GivingHeartScale, MSGBOX_DEFAULT
	giveitem ITEM_HEART_SCALE, 90
	msgbox OldaleTown_House2_Text_GivenScale, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Text_HeartScale:
	.string "I can give you 90 heart scales.\n"
	.string "Do you want that?$"

OldaleTown_House2_Text_GivingHeartScale:
	.string "Ok, take them.$"

OldaleTown_House2_Text_GivenScale:
	.string "I hope you don't need more.$"


OldaleTown_House2_EventScript_ExpShare::
	lock
	faceplayer
	msgbox OldaleTown_House2_Text_ExpShare, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq OldaleTown_House2_EventScript_YesToExpShare
	setvar VAR_EXP_SHARE, 0
	msgbox OldaleTown_House2_Text_ExpShare_No
	release
	end

OldaleTown_House2_EventScript_YesToExpShare::
	setvar VAR_EXP_SHARE, 1
	msgbox OldaleTown_House2_Text_ExpShare_Yes
	release
	end

OldaleTown_House2_Text_ExpShare:
	.string "I can toggle the exp share\n"
	.string "mechanic in the game for you.\p"
	.string "Please be aware that the game\n"
	.string "is balanced around this feature\l"
	.string "being enabled, as it is by default.\p"
	.string "Do you wish for the Exp Share to\n"
	.string "be turned on?$"

OldaleTown_House2_Text_ExpShare_No:
	.string "Ok. The Exp Share is now off.$"

OldaleTown_House2_Text_ExpShare_Yes:
	.string "Ok. The Exp Share is now on.$"
