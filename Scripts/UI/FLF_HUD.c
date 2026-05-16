//------------------------------------------------------------------
// FLF_HUD.c
// FrontLine Framework — Player HUD
// Author: BushCoda
// Phase: 8
//------------------------------------------------------------------

[ComponentEditorProps(category: "FrontLine Framework/UI", description: "Player HUD displaying supplies, objectives and alerts")]
class FLF_HUDClass : ScriptComponentClass
{
}

class FLF_HUD : ScriptComponent
{
	protected override void OnPostInit(IEntity owner)
	{
		// TODO Phase 8: Initialise HUD elements
	}

	void UpdateSupplyCounter(int supplies)
	{
		// TODO Phase 8: Update supply count display
	}

	void UpdateObjectiveTicker(string objectiveText)
	{
		// TODO Phase 8: Update objective status ticker
	}

	void ShowHQAlert(bool isUnderAttack)
	{
		// TODO Phase 8: Show/hide urgent HQ under attack alert
	}
}
