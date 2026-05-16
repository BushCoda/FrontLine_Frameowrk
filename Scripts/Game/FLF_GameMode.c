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
	// Called when the game mode initialises on the server
	//------------------------------------------------------------------
	override protected void OnGameStart()
	{
		super.OnGameStart();

		if (!GetGame().IsServer())
			return;

		// TODO Phase 3: Initialise all capture points to their default states
		// TODO Phase 4: Initialise radio signal link system
		// TODO Phase 5: Spawn enemy AI garrisons at all enemy bases
		// TODO Phase 6: Begin supply system monitoring
	}

	//------------------------------------------------------------------
	// Called every frame on the server
	//------------------------------------------------------------------
	override protected void OnUpdate(EUpdateSimFlags simFlags)
	{
		super.OnUpdate(simFlags);

		if (!GetGame().IsServer())
			return;

		// TODO Phase 3+: Tick game systems as needed
	}

	//------------------------------------------------------------------
	// Trigger win condition — called by FLF_WinLoseConditions
	//------------------------------------------------------------------
	void TriggerPlayerVictory()
	{
		if (!GetGame().IsServer())
			return;

		SCR_GameModeEndData endData = SCR_GameModeEndData.CreateSimple(EGameOverTypes.DEFENDER_WIN);
		EndGameMode(endData);
	}

	//------------------------------------------------------------------
	// Trigger lose condition — called by FLF_WinLoseConditions
	//------------------------------------------------------------------
	void TriggerPlayerDefeat()
	{
		if (!GetGame().IsServer())
			return;

		SCR_GameModeEndData endData = SCR_GameModeEndData.CreateSimple(EGameOverTypes.ATTACKER_WIN);
		EndGameMode(endData);
	}

	//------------------------------------------------------------------
	// Called when game state changes (PREGAME → GAME → POSTGAME)
	//------------------------------------------------------------------
	override protected void OnGameStateChanged(SCR_EGameModeState newState)
	{
		super.OnGameStateChanged(newState);

		switch (newState)
		{
			case SCR_EGameModeState.PREGAME:
				// TODO Phase 8: Show pre-game briefing UI
				break;

			case SCR_EGameModeState.GAME:
				// TODO Phase 8: Show in-game HUD
				break;

			case SCR_EGameModeState.POSTGAME:
				// TODO Phase 8: Show end-game scoreboard/summary
				break;
		}
	}
}
