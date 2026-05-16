//------------------------------------------------------------------
// FLF_WinLoseConditions.c
// FrontLine Framework — Win & Lose Condition Checks
// Author: BushCoda
// Phase: 8
//------------------------------------------------------------------

[ComponentEditorProps(category: "FrontLine Framework/Game", description: "Monitors HQ capture state and triggers win/lose conditions")]
class FLF_WinLoseConditionsClass : ScriptComponentClass
{
}

class FLF_WinLoseConditions : ScriptComponent
{
	protected override void OnPostInit(IEntity owner)
	{
		// TODO Phase 8: Register HQ capture point listeners
	}

	void OnHQCaptureStateChanged(IEntity hq, FLF_E_CaptureState newState, bool isPlayerHQ)
	{
		if (isPlayerHQ && newState == FLF_E_CaptureState.ENEMY_OWNED)
		{
			TriggerLose();
		}
		else if (!isPlayerHQ && newState == FLF_E_CaptureState.PLAYER_OWNED)
		{
			TriggerWin();
		}
	}

	protected void TriggerWin()
	{
		// TODO Phase 8: Display victory screen and end session
	}

	protected void TriggerLose()
	{
		// TODO Phase 8: Display defeat screen and end session
	}
}
