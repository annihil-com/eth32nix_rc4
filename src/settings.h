// ETH32 - an Enemy Territory cheat for windows
// Copyright (c) 2007 eth32 team
// www.cheatersutopia.com & www.nixcoders.org

#pragma once
#define MAX_SETTING_VALUES	10

typedef enum {
	SETTING_INT,
	SETTING_FLOAT,
	SETTING_BOOL,
	SETTING_VEC3,
	SETTING_VEC4,
	SETTING_BYTE3,
	SETTING_STRING,
	MAX_SETTINGS
} settingtype_t;

typedef struct settingvalue_s {
	float value;
	char *text;
} settingvalue_t;

typedef struct settingdef_s {
	char *name;
	char *defaultValue;
	settingtype_t type;
	void *target;
	char *description;
	float min, max;
	settingvalue_t values[MAX_SETTING_VALUES];
} settingdef_t;

const static settingdef_t settingsDefs[] =
{
	// Name				Default			Type				Target
	//	Description
	//	Min / Max
	//	  Value				TextValue
	{ "champlayer",		"1",			SETTING_INT,		(void*)&eth32.settings.chamsPlayer,
		"set the style of chams to be applied to players",
		CHAMS_OFF, MAX_CHAMS-1,
		{
			{ (int)CHAMS_OFF,		"off" },
			{ (int)CHAMS_CRYSTAL,	"crystal" },
			{ (int)CHAMS_WAVE,		"wave" },
			{ (int)CHAMS_SOLID,		"solid" },
			{ (int)CHAMS_QUAD,		"quad" },
		},
	},
	{ "chamweapon",		"1",			SETTING_INT,		(void*)&eth32.settings.chamsWeapon,
		"set the style of chams to be applied to weapons",
		CHAMS_OFF, MAX_CHAMS-1,
		{
			{ (int)CHAMS_OFF,		"off" },
			{ (int)CHAMS_CRYSTAL,	"crystal" },
			{ (int)CHAMS_WAVE,		"wave" },
			{ (int)CHAMS_SOLID,		"solid" },
			{ (int)CHAMS_QUAD,		"quad" },
		},
	},
	{ "ourweapcham",	"false",		SETTING_BOOL,		(void*)&eth32.settings.chamsOurWeapon,
		"apply weapon chams to our own weapon",
	},
	{ "espname",		"true",			SETTING_BOOL,		(void*)&eth32.settings.espName,
		"display player names above their heads",
	},
	{ "esptracker",		"true",			SETTING_BOOL,		(void*)&eth32.settings.espTracker,
		"display ETH32 usernames above their heads",
	},
	{ "icontracker",	"true",			SETTING_BOOL,		(void*)&eth32.settings.iconTracker,
		"display an icon for ETH32 users",
	},
	{ "wallhack",		"true",			SETTING_BOOL,		(void*)&eth32.settings.wallhack,
		"view players and items through walls",
	},
	{ "wallhackdist",	"1000.0",		SETTING_FLOAT,		(void*)&eth32.settings.wallhackDistance,
		"distance over which to enable wallhack for players",
		0, 20000,
	},
	{ "wallhackdist_enable",	"false",	SETTING_BOOL,	(void*)&eth32.settings.doDistWallhack,
		"enable distance sensitive wallhack",
	},
	{ "blackout",		"false",		SETTING_BOOL,		(void*)&eth32.settings.blackout,
		"display the blackout around scoped weapons",
	},
	{ "weapzoom",		"false",		SETTING_BOOL,		(void*)&eth32.settings.weaponZoom,
		"toggle weapon zoom for scoped weapons",
	},
	{ "scopedspeed",	"1.0",			SETTING_FLOAT,		(void*)&eth32.settings.scopedTurnSpeed,
		"determines turning speed while scoped, (normal unscoped speed = 1.0)",
		0.1, 1.0,
	},
	{ "smoketransp",	"18",			SETTING_INT,		(void*)&eth32.settings.smoketrnsp,
		"set the transparency of smoke",
		0,	100,
	},
	{ "respawntimers",	"true",			SETTING_BOOL,		(void*)&eth32.settings.respawnTimers,
		"display friendly and enemy respawn times",
	},
	{ "autotapout",		"false",		SETTING_BOOL,		(void*)&eth32.settings.autoTapout,
		"when killed, auto-tapout and sends you instantly to the reinforcements queue",
	},
	{ "nameclick",		"false",		SETTING_BOOL,		(void*)&eth32.settings.nameClick,
		"allows you to click a name in chat window to setup a private message",
	},
 	{ "speclist",		"false",		SETTING_BOOL,		(void*)&eth32.settings.getSpeclist,
		 "show who is spectating you",
 	},
 	{ "specserv",		"",				SETTING_STRING,		(void*)eth32.settings.specServer,
 		"alternate server IP/port (in case of troublesome BNC)",
 	},
	{ "aimmode",		"1",			SETTING_INT,		(void*)&eth32.settings.aimMode,
		"master aimbot mode",
		AIMMODE_OFF, AIMMODE_MAX-1,
		{
			{ (int)AIMMODE_OFF,		"off" },
			{ (int)AIMMODE_NORMAL,	"normal" },
			{ (int)AIMMODE_HUMAN, 	"human" },
		},
	}, 
	{ "humanaimmode",	"1",			SETTING_INT,		(void*)&eth32.settings.humanAimMode,
		"type of human aim to do",
		HUMAN_AIM_OFF, HUMAN_AIM_MAX-1,
		{
			{ (int)HUMAN_AIM_OFF,		"off" },
			{ (int)HUMAN_AIM_LUCKYHEADSHOT,	"lucky" },
			{ (int)HUMAN_AIM_FULL, 	"full" },
		},
	}, 	
	{ "aimtype",		"1",			SETTING_INT,		(void*)&eth32.settings.aimType,
		"determines when the aimbot is to aim",
		AIM_OFF, AIM_MAX-1,
		{
			{ (int)AIM_OFF,		"off" },
			{ (int)AIM_ON_FIRE,	"onfire" },
			{ (int)AIM_ON_BUTTON, "onbutton" },
			{ (int)AIM_ALWAYS,	"always" },
		},
	},
	{ "aimsort",		"1",			SETTING_INT,		(void*)&eth32.settings.aimSort,
		"sets type of sort to be used with valid targets",
		SORT_OFF, SORT_MAX-1,
		{
			{ (int)SORT_OFF,			"off" },
			{ (int)SORT_DISTANCE,	"distance" },
			{ (int)SORT_CROSSHAIR,	"crosshair" },
			{ (int)SORT_KDRATIO,		"kdratio" },
			{ (int)SORT_ACCURACY,	"accuracy" },
			{ (int)SORT_TARGETING,	"targeting" },
			{ (int)SORT_THREAT,		"threat" },
		},
	},
	{ "autofire",		"false",		SETTING_BOOL,		(void*)&eth32.settings.autofire,
		"aimbot will fire for you when target available\n   (note: autofire must be turned on per weapon as well)",
	},
	{ "locktarget",		"false",		SETTING_BOOL,		(void*)&eth32.settings.lockTarget,
		"once a target is aquired, aimbot will stay on this target while it remains visible",
	},
	{ "headbody",		"4",			SETTING_INT,		(void*)&eth32.settings.headbody,
		"determines if the aimbot uses the head or body and which order",
		0, AP_MAX-1,
		{
			{ (int)BODY_ONLY,		"bodyonly" },
			{ (int)HEAD_ONLY,		"headonly" },
			{ (int)BODY_HEAD,		"bodyfirst" },
			{ (int)HEAD_BODY,		"headfirst" },
			{ (int)HEAD_PRIORITY,	"headpriority" },
		},
	},
	{ "atkvalid",		"false",		SETTING_BOOL,		(void*)&eth32.settings.atkValidate,
		"inhibits firing, even manually, until a valid target is visible",
	},
	{ "hitbox",			"1",			SETTING_INT,		(void*)&eth32.settings.hitboxType,
		"set the hitbox style to use for aimbot",
		HITBOX_OFF, HITBOX_MAX-1,
		{
			{ (int)HITBOX_ETMAIN,	"etmain" },
			{ (int)HITBOX_ETPUB,		"etpub" },
			{ (int)HITBOX_ETPRO,		"etpro" },
			{ (int)HITBOX_GENERIC,	"generic" },
			{ (int)HITBOX_CUSTOM,	"custom" },
		},
	},
	{ "trace",			"0",			SETTING_INT,		(void*)&eth32.settings.traceType,
		"set the style of trace used to determine if a target is visible",
		0, TRACE_MAX-2,
		{
			{ (int)TRACE_CENTER,				"center" },
			{ (int)TRACE_RANDOM_VOLUME,		"randvolume" },
			{ (int)TRACE_RANDOM_SURFACE,		"randsurface" },
			{ (int)TRACE_CAPSULE_VOLUME,		"capvolume" },
			{ (int)TRACE_CAPSULE_SURFACE,	"capsurface" },
		},
	},
	{ "trans_console",	"false",	SETTING_BOOL, (void*)&eth32.settings.transparantConsole,
		"make the console transparant so you can see whats going on :)"
	},
	{ "valgrentraj", "false",		SETTING_BOOL, (void*)&eth32.settings.valGrenTrajectory,
		"make additional calculations to make sure the grenade doesn't hit anything",
	},
	{ "valrifletraj", "true",		SETTING_BOOL, (void*)&eth32.settings.valRifleTrajectory,
		"make additional calculations to make sure the riflegrenade doesn't hit anything",
	},
	{ "grenadeZ",	"0.0",				SETTING_FLOAT,	(void*)&eth32.settings.grenadeZ,
		"z correction for grenade aimpoint",
	},
	{ "riflenadeZ",	"-10.0",			SETTING_FLOAT,	(void*)&eth32.settings.riflenadeZ,
		"z correction for rifle grenade aimpoint",
	},
	{ "grenadeautofire", "true",	SETTING_BOOL,	(void*)&eth32.settings.grenadeAutoFire,
		"auto-fire grenade so it will explode right on contact",
	},
	{ "rifleautofire", "true",		SETTING_BOOL,	(void*)&eth32.settings.rifleAutoFire,
		"auto-fire riflegrenade as soon as we have a firing solution",
	},
	{ "grenadetracer", "true",	SETTING_BOOL,				(void*)&eth32.settings.grenadeTracer,
		"shows trajectory of the grenade",
	},
	{ "rifletracer", "true",	SETTING_BOOL,				(void*)&eth32.settings.rifleTracer,
		"shows trajectory of the rifle grenade",
	},
	{ "grensenslock", "false",	SETTING_BOOL,				(void*)&eth32.settings.grenadeSenslock,
		"locks view if there is a valid firing solution",
	},
	{ "grenadebot", "true",	SETTING_BOOL,				(void*)&eth32.settings.grenadeBot,
		"toggles the grenade aimbot",
	},
	{ "riflebot", "true",	SETTING_BOOL,				(void*)&eth32.settings.rifleBot,
		"toggles the riflegrenade aimbot",
	},
	{ "grenblockfire", "true",	SETTING_BOOL,				(void*)&eth32.settings.grenadeBlockFire,
		"blocks firing grenades by accident if there isn't a firing solution",
	},
	{ "grenfiredelay",	"300",			SETTING_INT,		(void*)&eth32.settings.grenadeFireDelay,
		"the time it takes when releasing fire button and the grenade is launched (leave if you dont know what you're doing)",
		0, 1000,
	},
	{ "radiusdamage_enable", "false",	SETTING_BOOL,				(void*)&eth32.settings.ballisticRadiusDamage,
		"if target is not visible, try a point within the grenade's blast radius",
	},
	{ "radiusdamage",	"200.0",			SETTING_FLOAT,		(void*)&eth32.settings.radiusDamage,
		"the grenade blast radius to use",
		30, 1000,
	},
	{ "grenpredict",	"true",			SETTING_BOOL,		(void*)&eth32.settings.ballisticPredict,
		"predict targets for grenade aimbot",
	},
	{ "grenautotarg",	"true",			SETTING_BOOL,		(void*)&eth32.settings.autoGrenTargets,
		"automatically selects grenade targets based on crosshair distance",
	},
	{ "grenblockfire", "true",	SETTING_BOOL,				(void*)&eth32.settings.grenadeBlockFire,
		"blocks firing grenades by accident if there isn't a firing solution",
	},
	{ "fov",			"360.0",		SETTING_FLOAT,		(void*)&eth32.settings.fov,
		"set the field of vision that the aimbot can select targets from",
		0, 360,
	},
	{ "aimprotect",		"0",			SETTING_INT,		(void*)&eth32.settings.aimprotect,
		"turn off aimbot when people are watching",
		0, PROTECT_MAX-1,
		{
			{ (int)PROTECT_OFF,	"off" },
			{ (int)PROTECT_SPECS,	"specs" },
			{ (int)PROTECT_ALL,	"all" },
		},
	},
	{ "predtarget",		"0.0",			SETTING_FLOAT,		(void*)&eth32.settings.predTarget,
		"set amount of prediction to be applied to targets",
		-1, 1,
	},
	{ "predself",		"0.0",			SETTING_FLOAT,		(void*)&eth32.settings.predSelf,
		"set amount to prediction to applied to our own movement (only for manual)",
		-1, 1,
	},
	{ "predself_type",	"0",			SETTING_INT,		(void*)&eth32.settings.predSelfType,
		"set the type of self prediction to apply",
		0, SPR_MAX-1,
	},
	{ "dynamicHitbox",	"0.0",			SETTING_FLOAT,		(void*)&eth32.settings.dynamicHitboxScale,
		"set how much a hitbox will scale based on player movement",
		0, 10,
	},
	
	{ "killspam",		"false",		SETTING_BOOL,		(void*)&eth32.settings.killSpam,
		"enable automated message when a target is killed",
	},	
	{ "multikillspam",	"false",		SETTING_BOOL,		(void*)&eth32.settings.multikillSpam,
		"enable automated message when making a multikill",
	},	
	{ "deathspam",		"false",		SETTING_BOOL,		(void*)&eth32.settings.deathSpam,
		"enable automated message when you die",
	},	
	{ "suicidespam",	"false",		SETTING_BOOL,		(void*)&eth32.settings.suicideSpam,
		"enable automated PM when someone commits suicide",
	},
	{ "selfkillspam",	"false",		SETTING_BOOL,		(void*)&eth32.settings.selfkillSpam,
		"enable automated message when you /kill or suicide",
	},	
	{ "pmkillspam",		"false",		SETTING_BOOL,		(void*)&eth32.settings.pmKillspam,
		"make PM killspam to victim instead of global chat",
	},
	{ "killspamtype",	"0",			SETTING_INT,		(void*)&eth32.settings.KillspamType,
		"make killspam for everyone or only selected players",
		0, KILLSPAM_MAX-1,
		{
			{ (int)KILLSPAM_ALL,		"all" },
			{ (int)KILLSPAM_SELECTED,	"selected" },
		},		
	},	
	{ "killsounds",		"false",		SETTING_BOOL,		(void*)&eth32.settings.killSounds,
		"enables sounds to be played when a player is killed",
	},
	{ "hitsounds",		"false",		SETTING_BOOL,		(void*)&eth32.settings.hitsounds,
		"enable sounds when you do damage to another player",		
	},
	{ "mkillresettime",	"2000",			SETTING_INT,		(void*)&eth32.settings.mkResetTime,
		"period in milliseconds after which multikill sound gets reset",
		200, 10000,
	},
	{ "customsounds", "false",			SETTING_BOOL,		(void*)&eth32.settings.customSounds,
		"play custom sounds",
	},
	{ "hqsounds", 		"true",			SETTING_BOOL,		(void*)&eth32.settings.hqSounds,
		"play HQ sounds (like 'Dynamite Planted')",
	},
	{ "puresounds",		"false",		SETTING_BOOL,		(void*)&eth32.settings.pureSounds,
		"only play pure sounds, this will disable anoying custom voicechats",
	},
	{ "radarrange",		"3000.0",		SETTING_FLOAT,		(void*)&eth32.settings.radarRange,
		"set the range of the radar window",
		100, 10000,
	},
	{ "xhairinfo",		"true",			SETTING_BOOL,		(void*)&eth32.settings.xhairInfo,
		"enable the crosshair info window",
	},
	{ "xhairinfotime",	"335",			SETTING_INT,		(void*)&eth32.settings.xhairInfoTime,
		"set how long crosshair info window will stay up (in msec)",
		0, 3000,
	},
	{ "colorteam",		"0 88 33",		SETTING_BYTE3,		(void*)eth32.settings.colorTeam,
		"set the color of team chams",
	},
	{ "colorteamhid",	"0 114 110",		SETTING_BYTE3,		(void*)eth32.settings.colorTeamHidden,
		"set the color of team chams when hidden",
	},
	{ "colorenemy",		"171 14 26",		SETTING_BYTE3,		(void*)eth32.settings.colorEnemy,
		"set the color of enemy chams",
	},
	{ "colorenemyhid",	"97 2 890",		SETTING_BYTE3,		(void*)eth32.settings.colorEnemyHidden,
		"set the color of enemy chams when hidden",
	},
	{ "colorinvuln",	"255 255 0",	SETTING_BYTE3,		(void*)eth32.settings.colorInvulnerable,
		"set the color of player chams when they are invulnerable",
	},
	{ "colorteamweap",	"0 255 255",	SETTING_BYTE3,		(void*)eth32.settings.colorTeamWeapon,
		"set the color of team weapons",
	},
	{ "colorenemyweap", "251 234 10",	SETTING_BYTE3,		(void*)eth32.settings.colorEnemyWeapon,
		"set the color of enemy weapons",
	},
	{ "colorhealth",	"255 0 0",		SETTING_BYTE3,		(void*)eth32.settings.colorHealth,
		"set the color of health kits",
	},
	{ "colorammo",		"0 255 0",		SETTING_BYTE3,		(void*)eth32.settings.colorAmmo,
		"set the color of ammo boxes",
	},
	{ "ircchatmsgs",	"0",			SETTING_INT,		(void*)&eth32.settings.ircChatMsgs,
		"set which IRC channels are routed to main chat window",
		0, IRC_ROUTING_MAX-1,
		{
			{ (int)IRC_ROUTING_OFF,		"off" },
			{ (int)IRC_ROUTING_CURRENT,	"current" },
			{ (int)IRC_ROUTING_ALL,		"all" },
		},
	},
	{ "ircconsolemsgs",	"0",			SETTING_INT,		(void*)&eth32.settings.ircConsoleMsgs,
		"set which IRC channels are routed to console",
		0, IRC_ROUTING_MAX-1,
		{
			{ (int)IRC_ROUTING_OFF,		"off" },
			{ (int)IRC_ROUTING_CURRENT,	"current" },
			{ (int)IRC_ROUTING_ALL,		"all" },
		}
	},
	{ "ircmention",		"false",		SETTING_BOOL,		(void*)&eth32.settings.ircMention,
		"enable notification if someone mentions your player name or ETH32 username in IRC",
	},
	{ "coop",		"1",			SETTING_INT,		(void*)&eth32.settings.portalCoopMode,
		"set who you want to play cooperatively with",
		0, COOP_MAX-1,
		{
			{ (int)COOP_OFF,		"off" },
			{ (int)COOP_FRIENDS, "friends" },
			{ (int)COOP_ALL,		"all" },
		},
	},
	{ "portalanon",		"false",		SETTING_BOOL,		(void*)&eth32.settings.portalAnon,
		"enable anonymity on portal, others will not be able to tell which server you are on",
	},
	{ "rampagenum",		"5",			SETTING_INT,		(void*)&eth32.settings.portalRampageNum,
		"set the minimum number of players to qualify as a rampage",
		4, 32,
	},
	{ "rampagenotify",	"true",			SETTING_BOOL,		(void*)&eth32.settings.portalRampageNotify,
		"enable notification of rampages in progress",
	},

	// hitbox drawing, custom tracers
	{ "headhitbox",		"true",			SETTING_BOOL,		(void*)&eth32.settings.drawHeadHitbox,
		"enable head hitbox drawing",
	},
	{ "headaxes",		"false",		SETTING_BOOL,		(void*)&eth32.settings.drawHeadAxes,
		"enable hitbox axis drawing",
	},
	{ "bodyhitbox",		"false",		SETTING_BOOL,		(void*)&eth32.settings.drawBodyHitbox,
		"enable body hitbox drawing",
	},
	{ "bulletrail",		"false",		SETTING_BOOL,		(void*)&eth32.settings.drawBulletRail,
		"enable bullet tracers",
	},
	{ "railwallhack",	"false",		SETTING_BOOL,		(void*)&eth32.settings.railWallhack,
		"see bullet tracers through walls",
	},
	{ "colorheadhb",	"0 1 0",		SETTING_VEC3,		(void*)eth32.settings.colorHeadHitbox,
		"set the color of the head hitbox",
	},
	{ "colorbodyhb",	"1 0 0",		SETTING_VEC3,		(void*)eth32.settings.colorBodyHitbox,
		"set the color of the body hitbox",
	},
	{ "colorbulletrail",	"1 0 0",		SETTING_VEC3,		(void*)eth32.settings.colorBulletRail,
		"set the color of bullet tracers",
	},
	{ "colorxaxis",		"1 0 0",		SETTING_VEC3,		(void*)eth32.settings.colorXAxis,
		"set the color of hitbox x-axis",
	},
	{ "coloryaxis",		"0 1 0",		SETTING_VEC3,		(void*)eth32.settings.colorYAxis,
		"set the color of hitbox y-axis",
	},
	{ "colorzaxis",		"0 0 1",		SETTING_VEC3,		(void*)eth32.settings.colorZAxis,
		"set the color of hitbox z-axis",
	},
	{ "headhbtime",		"40",			SETTING_INT,		(void*)&eth32.settings.headRailTime,
		"set head hitbox stay time (in msec)",
		0, 1000,
	},
	{ "bodyhbtime",		"40",			SETTING_INT,		(void*)&eth32.settings.bodyRailTime,
		"set body hitbox stay time (in msec)",
		0, 1000,
	},
	{ "bulletrailtime",	"40",			SETTING_INT,		(void*)&eth32.settings.bulletRailTime,
		"set bullet tracer stay time (in msec)",
		0, 1000,
	},

	{ "etproOs",		"true",			SETTING_BOOL,		(void*)&eth32.settings.etproOs,
		"enable etpro os spoofing",
	},
	{ "ircserver",		"irc.rizon.net",SETTING_STRING,		(void*)eth32.settings.ircServer,
		"the IRC server the bot connects to (leave this if you dont know what you are doing)",
	},
	{ "pk3name",		"eth32_v2.pk3",	SETTING_STRING,		(void*)eth32.settings.pk3file,
		"the main eth32 pk3 file name",
	},
	{ "etproGuid",		"0",			SETTING_STRING,		(void*)eth32.settings.etproGuid,
		"set your custom etpro GUID",
	},
	{ "jaymac",		"0",				SETTING_STRING,		(void*)eth32.settings.jayMac,
		"set your custom jaymod MAC address (prevents bans based on MAC)",
	},
	{ "autopoints",		"0",			SETTING_INT,		(void*)&eth32.settings.autoPoints,
		"set automatic generation of multi aimpoints",
		0, AUTOPT_MAX-1,
		{
			{ (int)AUTOPT_OFF,	"off" },
			{ (int)AUTOPT_LOW,	"low" },
			{ (int)AUTOPT_HIGH,	"high" },
		},
	},
	{ "autocrouch",		"false",		SETTING_BOOL,		(void*)&eth32.settings.autoCrouch,
		"enable auto crouching when target is visible",
	},

	// view values
	{ "vw_origviewvalues",	"false",		SETTING_BOOL,		(void*)&eth32.settings.origViewValues,
		"enable unmodified view calculations",
	},
	{ "vw_interpolatedps",	"true",			SETTING_BOOL,		(void*)&eth32.settings.interpolatedPs,
		"enable interpolated playerstate",
	},
	{ "vw_thirdperson",	"false",		SETTING_BOOL,		(void*)&eth32.settings.thirdPerson,
		"enable third person view",
	},
	{ "vw_damagefeedback",	"false",		SETTING_BOOL,		(void*)&eth32.settings.dmgFeedback,
		"enable damage feedback",
	},

	{ "preaim",		"false",		SETTING_BOOL,			(void*)&eth32.settings.preAim,
		"preaim targets",
	},
	{ "preaimtime",		"400.0",		SETTING_FLOAT,			(void*)&eth32.settings.preAimTime,
		"preaim time - higher is earlier aiming",
		0, 5000,
	},

	{ "preshoot",		"false",		SETTING_BOOL,			(void*)&eth32.settings.preShoot,
		"pre-shoot at targets before they are logically visible",
	},
	{ "preshoottime",	"50.0",			SETTING_FLOAT,			(void*)&eth32.settings.preShootTime,
		"preshoot time - higher means earlier shot (and higher chance of miss)",
		0, 5000,
	},
	// custom hitbox
	{ "hb_stand",		"0 0 0",		SETTING_VEC3,		(void*)Aimbot.customHitbox.stand_offset,
		"set the hitbox center point for a standing player",
	},
	{ "hb_crouch",		"0 0 0",		SETTING_VEC3,		(void*)Aimbot.customHitbox.crouch_offset,
		"set the hitbox center point for a crouching player",
	},
	{ "hb_prone",		"0 0 0",		SETTING_VEC3,		(void*)Aimbot.customHitbox.prone_offset,
		"set the hitbox center point for a prone player",
	},
	{ "hb_run",		"0 0 0",		SETTING_VEC3,		(void*)Aimbot.customHitbox.stand_offset_moving,
		"set the hitbox center point for a running player",
	},
	{ "hb_crawl",		"0 0 0",		SETTING_VEC3,		(void*)Aimbot.customHitbox.crouch_offset_moving,
		"set the hitbox center point for a crawling player",
	},
	{ "hb_size",		"0 0 0",		SETTING_VEC3,		(void*)Aimbot.customHitbox.size,
		"set the size of head hitbox (length, width, height)",
	},

	{ "autopush",		"0",			SETTING_INT,	(void*)&eth32.settings.autoPush,
		"enable auto push players",
		0, MAX_AUTOPUSH-1,
		{
			{ (int)AUTOPUSH_OFF,	"off" },
			{ (int)AUTOPUSH_ENEMY,	"enemy" },
			{ (int)AUTOPUSH_TEAM,	"team" },
			{ (int)AUTOPUSH_BOTH,	"both" },
		},
	},
	{ "autopush_dist",	"96.0",			SETTING_FLOAT,	(void*)&eth32.settings.autoPushDistance,
		"maximum distance to player before pushing",
		0.0, 256.0,
	},
	{ "animcor", "0.0", SETTING_FLOAT, (void*)&eth32.settings.animCorrection,
		"animation correction for aimbot",
		-10.0, 10.0,
	},
	{ "showstats", "true", SETTING_BOOL, (void*)&eth32.settings.showStats,
		"show stats window",
	},


 	// LINUX ONLY BELOW HERE!
	{ "hackvisuals", "true", SETTING_BOOL, (void*)&eth32.settings.drawHackVisuals,
		"draw hack visuals",
	},
 	{ "pbscreenshot", "2", SETTING_INT, (void*)&eth32.settings.pbScreenShot,
		"type of PB screenshot",
  		0, PB_SS_MAX-1,
		{
			{ (int)PB_SS_NORMAL,	"normal" },
			{ (int)PB_SS_CUSTOM,	"custom" },
			{ (int)PB_SS_CLEAN,		"clean" },
		},
	},
	
	{ "test", "0", SETTING_INT, (void*)&eth32.settings.test,},
	
	{ "bannerfmt", "[N]  ^2-   ^7[n]&&^9hp: ^w[h] ^2| ^9am: ^w[a] ^2| ^9stats: ^o[k]^9/^o[d] ^9(^o[r]^9) ^2| ^9ss: ^2[s] | ^9spree: ^1[S]^9/^1[p] ^2| ^9limbo: ^7[L]", SETTING_STRING, (void*)eth32.settings.BannerFmt, 
		"banner format",
	},
	{ "bannerscale", "1.4", SETTING_FLOAT, (void*)&eth32.settings.BannerScale,
		"Banner font scale",
	},	
	{ "gui_banner", "true", SETTING_BOOL, (void*)&eth32.settings.guiBanner,
		"GUI: show stats banner",
	},
	{ "gui_chat", "true", SETTING_BOOL, (void*)&eth32.settings.guiChat,
		"GUI: show eth32 chat window",
	},
	{ "gui_cp", "true", SETTING_BOOL, (void*)&eth32.settings.guiCenterPrint,
		"GUI: show centerprint banner",
	},
	{ "gui_cpanim", "true", SETTING_BOOL, (void*)&eth32.settings.guiCenterPrintAnim,
		"GUI: do centerprint animation",
	},
	{ "gui_cpscale", "1.0", SETTING_FLOAT, (void*)&eth32.settings.guiCenterPrintScale,
		"GUI: centerprint font scale",
		0.0, 10.0,
	},
	{ "gui_orig", "false", SETTING_BOOL, (void*)&eth32.settings.guiOriginal,
		"GUI: use original ET hud",
	},
	
	// namesteal stuff
	{ "namesteal", "false", SETTING_BOOL, (void*)&eth32.settings.doNamesteal, 
		"Enable namestealing",
	}, 
	{ "namesteal_grace", "1000", SETTING_INT, (void*)&eth32.settings.NamestealGrace, 
		"Time to wait in ms to start stealing after joining a server",
		0, 10000,		
	},
	{ "namesteal_mode", "2", SETTING_INT, (void*)&eth32.settings.NamestealMode, 
		"Type of namestealing to do",
		0, NAMESTEAL_MAX-1,
		{ 
			{ (int)NAMESTEAL_TEAM,	"team" },
			{ (int)NAMESTEAL_ENEMY,	"enemy" },
			{ (int)NAMESTEAL_ALL,	"all" },
			{ (int)NAMESTEAL_FILE,	"file" },
		},					
	},
	{ "namesteal_delay", "5000", SETTING_INT, (void*)&eth32.settings.NamestealDelay,
		"Time to wait between changing names (in ms)",
		0, 999999999,
	},
	{ "disguised", 		"false", SETTING_BOOL, (void *)&eth32.settings.drawDisguised,
		"draw disguised ESP on players",
	},
	{ "panzersuicide",	"false",	SETTING_BOOL,	(void*)&eth32.settings.panzerSuicide,
		"auto suicide if we are about to be panzernoobed",
	},
	{ "panzerdistance",	"300",		SETTING_FLOAT,	(void*)&eth32.settings.panzerImpactDist,
		"max distance from impactpoint to procede with panzer suicide",
		40.0f, 500.0f,
	},
	{ "grenadedlight",	"true",		SETTING_BOOL,	(void*)&eth32.settings.grenadeDlight,
		"extra grenade lights inidicating blast area",	
	},
	{ "mortardlight",	"true",		SETTING_BOOL,	(void*)&eth32.settings.mortarDlight,
		"extra mortar lights inidicating blast area",	
	},
	{ "mortartrace",	"true",		SETTING_BOOL,	(void*)&eth32.settings.mortarTrace,
		"show mortar trace lines and impact ESP",	
	},
	{ "artymarkers",	"true",		SETTING_BOOL,	(void*)&eth32.settings.artyMarkers,
		"show arty blast area lights and ESP",	
	},
};
