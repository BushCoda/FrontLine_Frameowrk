# 📡 Radio Signal Link System
### FrontLine Framework — Design Document

---

## Overview

The Radio Signal Link system governs which capture points and supply depots each faction can actively contest. A base must have an active signal link to a point before its units are permitted to attack, defend, or capture it. This creates a natural and logical frontline that expands and contracts with territorial control.

---

## How It Works

Every base (player and enemy) projects a **signal radius** — a spherical range centred on the base's radio tower. Any capture point or supply depot that falls within this radius is considered **signal-linked** to that base.

```
[Base Radio Tower]
        │
        ▼
  ◉ Signal Radius
        │
  ┌─────┴─────┐
  │           │
[CP-01]    [Depot-03]
(linked)    (linked)
```

---

## Signal Link Rules

- A base must be **active** (not captured or destroyed) to project a signal.
- A capture point or depot is **linked** to a faction if it falls within **any** active base signal radius belonging to that faction.
- If a base is captured or destroyed, its signal radius **immediately collapses** — all points that were exclusively linked through that base lose their connection.
- Signal links are checked **dynamically** — they update in real time as bases change ownership.

---

## Faction Gating

| Condition | Result |
|---|---|
| Point is within player signal radius | Players can capture and contest the point |
| Point is within enemy signal radius | Enemy AI can defend and counter-attack the point |
| Point is within both signal radii | Both factions can contest the point simultaneously |
| Point is within neither signal radius | Point cannot be contested by either faction |

---

## Signal Radius Configuration

| Parameter | Default | Description |
|---|---|---|
| `SignalRadiusMeters` | 1500m | Radius projected by each base radio tower |
| `HQSignalRadiusMeters` | 2500m | Extended radius for Main HQ towers |
| `SignalUpdateIntervalSeconds` | 5s | How often signal links are recalculated |

> All values are configurable via the scenario config file.

---

## Radio Tower Destruction

- Enemy signal towers can be **destroyed by players** to sever enemy signal links.
- Destroying a tower **removes the enemy's ability to contest** all points exclusively linked through that base.
- Towers can be **repaired** by AI or players to restore signal coverage.
- Player towers can also be destroyed by enemy AI — players should defend or repair them to maintain their own network.

---

## Placement Notes

- Every base and HQ must have a **radio tower entity** placed in the World Editor.
- Each tower must be assigned:
  - A faction identifier (`Player` or `Enemy`).
  - A signal radius value (can use default or custom per-tower override).
- Signal tower placement should reflect realistic line-of-sight and communication range relative to the Everon terrain.

---

## Related Systems

- [Capture Point System](./capture-point-system.md)
- [Enemy AI Behaviour](./enemy-ai-behaviour.md)
- [Base & HQ System](./base-hq-system.md)
