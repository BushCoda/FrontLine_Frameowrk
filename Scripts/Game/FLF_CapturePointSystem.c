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

[ComponentEditorProps(category: "FrontLine Framework/Game", description: "Manages capture point state machine")]
class FLF_CapturePointComponentClass : ScriptComponentClass
{
}

class FLF_CapturePointComponent : ScriptComponent
{
	protected FLF_E_CaptureState m_CaptureState = FLF_E_CaptureState.NEUTRAL;

	protected override void OnPostInit(IEntity owner)
	{
		m_CaptureState = FLF_E_CaptureState.NEUTRAL;
		SetEventMask(owner, EntityEvent.FRAME);
	}

	override void EOnFrame(IEntity owner, float timeSlice)
	{
		super.EOnFrame(owner, timeSlice);
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
