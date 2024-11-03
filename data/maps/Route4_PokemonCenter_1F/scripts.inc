# 1 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
.equ MAGIKARP_PRICE, 500
# 3 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_MapScripts::
# 5 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
# 6 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_OnTransition::
# 10 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
# 11 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	setrespawn SPAWN_ROUTE4
# 12 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_Boy::
# 15 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
# 16 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 17 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 18 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_Gentleman::
# 19 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	lock
# 20 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
# 21 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 22 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 23 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 24 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale::
# 25 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500, MSGBOX_YESNO
# 26 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
# 27 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 28 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 29 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale::
# 30 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500, MSGBOX_YESNO
# 31 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
# 32 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 33 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 34 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp::
# 35 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
# 36 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	checkmoney MAGIKARP_PRICE
# 37 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
# 38 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 39 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
# 40 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	givemon SPECIES_MAGIKARP, 5
# 41 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
# 42 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
# 43 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
# 44 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 45 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 46 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
# 47 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
# 48 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 49 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
# 50 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 51 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 52 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 53 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	special ChangePokemonNickname
# 54 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	waitstate
# 55 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
# 56 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 57 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 58 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
# 59 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
# 60 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 61 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox
# 62 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 63 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 64 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	special ChangeBoxPokemonNickname
# 65 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	waitstate
# 66 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	lock
# 67 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	faceplayer
# 68 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
# 69 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 70 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 71 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox::
# 72 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	call EventScript_TransferredToPC
# 73 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
# 74 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 75 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 76 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
# 77 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	call EventScript_TransferredToPC
# 78 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
# 79 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 80 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 81 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp::
# 82 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 83 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
# 84 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 85 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 86 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
# 87 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	setflag FLAG_BOUGHT_MAGIKARP
# 88 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 89 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 90 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 91 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
# 92 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	removemoney MAGIKARP_PRICE
# 93 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	updatemoneybox
# 94 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 95 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
# 96 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	waitmessage
# 97 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 98 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
# 99 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	return
# 100 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 101 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
# 102 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou
# 103 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 104 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 105 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 106 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 107 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
# 108 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney
# 109 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 110 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 111 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 112 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 113 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
# 114 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds
# 115 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 116 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 117 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 118 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
# 119 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 120 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon
# 121 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	hidemoneybox
# 122 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 123 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 124 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 125 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_Nurse::
# 126 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	lock
# 127 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	faceplayer
# 128 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	call EventScript_PkmnCenterNurse
# 129 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 130 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 131 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 132 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_Youngster::
# 133 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
# 134 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end
# 135 "data/maps/Route4_PokemonCenter_1F/scripts.pory"

# 136 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
Route4_PokemonCenter_1F_EventScript_Newspaper::
# 137 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	lock
# 138 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_Text_ItsANewspaper
# 139 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	release
# 140 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	end

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
# 144 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	lock
# 145 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	faceplayer
# 146 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	msgbox Route4_PokemonCenter_1F_EventScript_MagikarpSalesman_Text_0, MSGBOX_NPC
# 147 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	givemon SPECIES_MAGIKARP, 5, ITEM_MYSTIC_WATER, ITEM_CHERISH_BALL
	return


Route4_PokemonCenter_1F_EventScript_MagikarpSalesman_Text_0:
# 146 "data/maps/Route4_PokemonCenter_1F/scripts.pory"
	.string "Normally i would give you this magikarp,\n"
	.string "only if you bought it for 500\l"
	.string "PokéDollars but im feeling generous\l"
	.string "today so here take this free magikarp\l"
	.string "my friend.$"
