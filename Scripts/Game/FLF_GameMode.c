//------------------------------------------------------------------
// FLF_GameMode.c
// FrontLine Framework — Custom Game Mode
// Author: BushCoda
// Phase: 1 / 8
//
// Extends SCR_BaseGameMode — the lowest usable game mode in Arma Reforger.
// All FLF systems hook into this game mode via components.
//
// Required world entities (place via World Editor prefabs):
//   - GameMode_Base.et         → attach this script as component
//   - FactionManager_Base.et   → manage US/USSR or custom factions
//   - LoadoutManager_Base.et   → manage player loadouts
//   - SpawnPoint_Base.et       → player spawn points
//------------------------------------------------------------------

class FLF_GameModeClass : SCR_BaseGameModeClass
{
}

class FLF_GameMode : SCR_BaseGameMode
{
	//------------------------------------------------------------------
	// Called on every machine when the match starts
	//------------------------------------------------------------------
	override void OnGameModeStart()
	{
		super.OnGameModeStart();

		if (RplSession.Mode() == RplMode.Client)
			return;

		// TODO Phase 3: Initialise all capture points to their default states
		// TODO Phase 4: Initialise radio signal link system
		// TODO Phase 5: Spawn enemy AI garrisons at all enemy bases
		// TODO Phase 6: Begin supply system monitoring
	}

	//------------------------------------------------------------------
	// Called when the match finishes (win or lose)
	//------------------------------------------------------------------
	override void OnGameModeEnd(SCR_GameModeEndData endData)
	{
		super.OnGameModeEnd(endData);

		// TODO Phase 8: Show end-game scoreboard/summary based on endData
	}

	//------------------------------------------------------------------
	// Called when a player is killed
	//------------------------------------------------------------------
	override void OnPlayerKilled(int playerId, IEntity playerEntity, IEntity killerEntity, notnull Instigator killer)
	{
		super.OnPlayerKilled(playerId, playerEntity, killerEntity, killer);

		// TODO Phase 8: Handle player death (respawn logic, ticket system, etc.)
	}

	//------------------------------------------------------------------
	// Trigger win condition — called by FLF_WinLoseConditions
	//------------------------------------------------------------------
	void TriggerPlayerVictory()
	{
		if (RplSession.Mode() == RplMode.Client)
			return;

		SCR_GameModeEndData endData = SCR_GameModeEndData.CreateSimple(EGameOverTypes.VICTORY);
		EndGameMode(endData);
	}

	//------------------------------------------------------------------
	// Trigger lose condition — called by FLF_WinLoseConditions
	//------------------------------------------------------------------
	void TriggerPlayerDefeat()
	{
		if (RplSession.Mode() == RplMode.Client)
			return;

		SCR_GameModeEndData endData = SCR_GameModeEndData.CreateSimple(EGameOverTypes.LOOSE);
		EndGameMode(endData);
	}
}
