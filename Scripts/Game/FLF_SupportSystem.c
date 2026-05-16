//------------------------------------------------------------------
// FLF_SupportSystem.c
// FrontLine Framework — Support Call-In System
// Author: BushCoda
// Phase: 7
//------------------------------------------------------------------

[ComponentEditorProps(category: "FrontLine Framework/Game", description: "Manages support call-ins from the HQ Terminal")]
class FLF_SupportSystemClass : ScriptComponentClass
{
}

class FLF_SupportSystem : ScriptComponent
{
	protected override void OnPostInit(IEntity owner)
	{
		// TODO Phase 7: Initialise support system and cooldown timers
	}

	bool CallSupport(string supportType, vector targetPosition)
	{
		// TODO Phase 7: Check cooldown and supply cost
		// TODO Phase 7: Execute support call (artillery, CAS, reinforcements, etc.)
		return false;
	}

	protected bool IsOnCooldown(string supportType)
	{
		// TODO Phase 7: Check if support type is on cooldown
		return false;
	}

	protected void StartCooldown(string supportType)
	{
		// TODO Phase 7: Start cooldown timer for support type
	}
}
