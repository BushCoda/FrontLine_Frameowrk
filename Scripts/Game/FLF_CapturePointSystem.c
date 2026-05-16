//------------------------------------------------------------------
// FLF_CapturePointSystem.c
// FrontLine Framework — Capture Point State Machine
// Author: BushCoda
// Phase: 3
//------------------------------------------------------------------

enum FLF_E_CaptureState
{
	NEUTRAL,
	BEING_CAPTURED,
	PLAYER_OWNED,
	ENEMY_OWNED
}

class FLF_CapturePointComponent : ScriptedGameComponent
{
	protected FLF_E_CaptureState m_CaptureState = FLF_E_CaptureState.NEUTRAL;

	override void OnInit(IEntity owner)
	{
		// TODO Phase 3: Initialise capture point state
	}

	override void OnUpdate(IEntity owner, float timeSlice)
	{
		// TODO Phase 3: Handle capture progress logic
	}

	FLF_E_CaptureState GetCaptureState()
	{
		return m_CaptureState;
	}

	void SetCaptureState(FLF_E_CaptureState newState)
	{
		m_CaptureState = newState;
		// TODO Phase 3: Broadcast state change event
	}
}
