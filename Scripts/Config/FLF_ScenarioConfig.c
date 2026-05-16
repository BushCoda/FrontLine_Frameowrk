//------------------------------------------------------------------
// FLF_ScenarioConfig.c
// FrontLine Framework — Centralised Scenario Configuration
// Author: BushCoda
// Phase: 1
//------------------------------------------------------------------

class FLF_ScenarioConfig
{
	// --- Capture Point Settings ---
	static float CAPTURE_RADIUS					= 50.0;		// metres
	static float CAPTURE_TIME_SECONDS			= 60.0;
	static float RECAPTURE_TIME_SECONDS			= 90.0;
	static bool  PROGRESS_RESET_ON_LEAVE		= true;

	// --- Radio Signal Settings ---
	static float SIGNAL_RADIUS_METERS			= 1500.0;
	static float HQ_SIGNAL_RADIUS_METERS		= 2500.0;
	static float SIGNAL_UPDATE_INTERVAL			= 5.0;		// seconds

	// --- Supply Settings ---
	static float SUPPLY_GENERATION_RATE			= 10.0;		// per minute per depot
	static int   TRUCK_CAPACITY					= 100;
	static float TRUCK_DISPATCH_INTERVAL		= 300.0;	// seconds
	static float TRUCK_REDISPATCH_DELAY			= 120.0;	// seconds after destruction

	// --- AI Settings ---
	static float COUNTER_ATTACK_DELAY			= 30.0;		// seconds
	static float GARRISON_REPLENISH_INTERVAL	= 120.0;	// seconds
	static float PATROL_RADIUS_METERS			= 500.0;

	// --- Support Cooldowns (seconds) ---
	static float COOLDOWN_ARTILLERY				= 600.0;
	static float COOLDOWN_CAS					= 900.0;
	static float COOLDOWN_REINFORCEMENT			= 480.0;
	static float COOLDOWN_RESUPPLY				= 300.0;
	static float COOLDOWN_SMOKE					= 180.0;
	static float COOLDOWN_MEDICAL				= 300.0;
	static float COOLDOWN_VEHICLE				= 720.0;

	// --- Fortification Supply Costs ---
	static int COST_SANDBAG_WALL				= 10;
	static int COST_RAZOR_WIRE					= 5;
	static int COST_BUNKER_SMALL				= 30;
	static int COST_BUNKER_LARGE				= 60;
	static int COST_HMG_EMPLACEMENT				= 50;
	static int COST_AT_GUN						= 75;
	static int COST_MORTAR_PIT					= 60;
	static int COST_VEHICLE_BARRIER				= 15;
	static int COST_WATCHTOWER					= 25;
}
