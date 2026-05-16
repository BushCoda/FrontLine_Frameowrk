//------------------------------------------------------------------
// FLF_SupplySystem.c
// FrontLine Framework — Supply Generation & Friendly AI Convoys
// Author: BushCoda
// Phase: 6
//------------------------------------------------------------------

class FLF_SupplySystem : ScriptedGameComponent
{
	protected int m_SupplyPool = 0;
	protected float m_GenerationRatePerMinute = 10.0;

	override void OnInit(IEntity owner)
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
