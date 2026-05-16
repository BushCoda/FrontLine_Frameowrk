//------------------------------------------------------------------
// FLF_SupplySystem.c
// FrontLine Framework — Supply Generation & Friendly AI Convoys
// Author: BushCoda
// Phase: 6
//------------------------------------------------------------------

[ComponentEditorProps(category: "FrontLine Framework/Game", description: "Manages supply generation and friendly AI truck convoys")]
class FLF_SupplySystemClass : ScriptComponentClass
{
}

class FLF_SupplySystem : ScriptComponent
{
	[Attribute(defvalue: "10", desc: "Supplies generated per minute when depot is PlayerOwned", category: "Supply")]
	protected float m_GenerationRatePerMinute;

	[Attribute(defvalue: "100", desc: "Max supplies per truck load", category: "Supply")]
	protected int m_TruckCapacity;

	protected int m_SupplyPool = 0;

	protected override void OnPostInit(IEntity owner)
	{
		// TODO Phase 6: Initialise supply system and connect to HQ pool
	}

	void OnDepotCaptured(IEntity depot)
	{
		// TODO Phase 6: Begin supply generation and dispatch truck convoy
	}

	void OnDepotLost(IEntity depot)
	{
		// TODO Phase 6: Stop supply generation and recall/despawn trucks
	}

	void AddSupplies(int amount)
	{
		m_SupplyPool += amount;
		// TODO Phase 6: Update HQ supply pool and notify UI
	}

	int GetSupplyPool()
	{
		return m_SupplyPool;
	}
}
