//------------------------------------------------------------------
// FLF_HQTerminalUI.c
// FrontLine Framework — HQ Command Terminal UI
// Author: BushCoda
// Phase: 7
//------------------------------------------------------------------

[ComponentEditorProps(category: "FrontLine Framework/UI", description: "HQ Command Terminal UI for fortification and support call-ins")]
class FLF_HQTerminalUIClass : ScriptComponentClass
{
}

class FLF_HQTerminalUI : ScriptComponent
{
	protected override void OnPostInit(IEntity owner)
	{
		// TODO Phase 7: Initialise HQ terminal UI layout
	}

	void OpenTerminal()
	{
		// TODO Phase 7: Display fortification and support menu to player
	}

	void CloseTerminal()
	{
		// TODO Phase 7: Hide terminal UI
	}

	void RefreshSupplyDisplay(int currentSupplies)
	{
		// TODO Phase 7: Update supply pool counter in UI
	}
}
