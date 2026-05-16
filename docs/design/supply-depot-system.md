# 📦 Supply Depot System
### FrontLine Framework — Design Document

---

## Overview

Supply depots are capturable locations spread across Everon that passively generate supplies for the player faction. Captured depots dispatch friendly AI supply trucks that haul resources back to the Player Main HQ, where they are added to the central supply pool used for fortification and support call-ins.

---

## Depot States

| State | Description |
|---|---|
| `EnemyOwned` | Depot is held by enemy — no player supplies generated |
| `BeingCaptured` | Players are contesting the depot |
| `PlayerOwned` | Depot is generating supplies and dispatching convoys |

---

## Supply Generation

- Each `PlayerOwned` depot generates supplies at a **configurable passive rate**.
- Supplies are not instantly added to the HQ pool — they must be **physically transported** by friendly AI trucks.
- If a truck is destroyed en route, that load of supplies is **lost**.
- A new truck is dispatched after a configurable redispatch delay.

### Supply Generation Configuration

| Parameter | Default | Description |
|---|---|---|
| `SupplyGenerationRatePerMinute` | 10 | Supplies generated per minute per depot |
| `TruckCapacity` | 100 | Max supplies per truck load |
| `TruckDispatchIntervalSeconds` | 300s | Time between truck dispatches per depot |
| `TruckDestroyedRedispatchSeconds` | 120s | Delay before a new truck is sent after one is destroyed |

---

## Friendly AI Supply Trucks

- Spawned automatically when a depot reaches `PlayerOwned` state.
- Follow the road network from the depot to the Player Main HQ.
- Unload supplies at the HQ terminal on arrival.
- Return to depot and repeat the cycle.
- Players are encouraged to escort convoys to prevent ambushes.

### Truck Behaviour

| Event | Result |
|---|---|
| Truck arrives at HQ | Supplies added to HQ pool |
| Truck is destroyed | Supplies lost, redispatch timer starts |
| Depot is recaptured by enemy | Active trucks are recalled or despawned |
| Road is blocked | Truck attempts alternate route or waits |

---

## Strategic Importance

- More depots captured = faster supply income.
- Supplies fund **fortifications** and **support call-ins** at the HQ Terminal.
- Enemy AI may attempt to ambush convoys if players are careless.
- Players must balance attacking new objectives vs. defending active supply routes.

---

## Placement Notes

- All depots are manually placed in the World Editor.
- Each depot requires:
  - A capture zone trigger (same state machine as capture points).
  - A truck spawn point near the depot.
  - A defined route waypoint toward the Player HQ (road network preferred).
  - An initial ownership state (`EnemyOwned` at match start).

---

## Related Systems

- [Capture Point System](./capture-point-system.md)
- [Base & HQ System](./base-hq-system.md)
- [Fortification System](./fortification-system.md)
- [Support Systems](./support-systems.md)
