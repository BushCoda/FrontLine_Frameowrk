//------------------------------------------------------------------
// FLF_EnemyAIController.c
// FrontLine Framework — Enemy AI Garrison & Counter-Attack Controller
// Author: BushCoda
// Phase: 5
//------------------------------------------------------------------

class FLF_EnemyAIController : ScriptedGameComponent
{
	override void OnInit(IEntity owner)
	{
		// TODO Phase 5: Initialise garrison groups at this base
	}

	void OnCaptureStateChanged(IEntity capturePoint, FLF_E_CaptureState newState)
	{
		// TODO Phase 5: React to capture state changes
		// Only dispatch counter-attack if newState == BEING_CAPTURED
		// and capture point is within signal radius
	}

	protected void DispatchCounterAttack(IEntity capturePoint)
	{
		// TODO Phase 5: Assemble and dispatch counter-attack squad
	}

	protected void CancelCounterAttack(IEntity capturePoint)
	{
		// TODO Phase 5: Cancel counter-attack orders and return units
	}
}
