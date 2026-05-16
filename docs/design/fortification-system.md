# 🛠️ Fortification System
### FrontLine Framework — Design Document

---

## Overview

The fortification system allows players to spend supplies from the HQ supply pool to place defensive structures at player-owned bases and the Main HQ. Fortifications improve the defensive capability of held territory and make it significantly harder for enemy AI to recapture bases.

---

## How It Works

1. Players interact with the **HQ Command Terminal**.
2. Available fortification options are displayed with their supply costs.
3. Player selects a fortification type and placement location.
4. Supplies are deducted from the HQ pool.
5. The fortification is placed in the world.

---

## Fortification Types

| Fortification | Supply Cost | Description |
|---|---|---|
| Sandbag Wall | 10 | Basic infantry cover |
| Razor Wire | 5 | Slows enemy infantry movement |
| Bunker (Small) | 30 | Protected firing position for 2 infantry |
| Bunker (Large) | 60 | Protected firing position for 4 infantry |
| HMG Emplacement | 50 | Manned heavy machine gun position |
| AT Gun Emplacement | 75 | Manned anti-tank gun position |
| Mortar Pit | 60 | Manned mortar position |
| Vehicle Barrier | 15 | Blocks vehicle movement through chokepoints |
| Watchtower | 25 | Elevated observation and firing position |

> Supply costs are configurable via the scenario config file.

---

## Placement Rules

- Fortifications can only be placed at **PlayerOwned** bases and the Player Main HQ.
- Fortifications **cannot** be placed at neutral or enemy-owned locations.
- There is a maximum fortification count per base to prevent excessive build-up:

| Base Type | Max Fortifications |
|---|---|
| Small FOB | 10 |
| Medium Forward Base | 20 |
| Large Forward Base | 30 |
| Player Main HQ | 50 |

---

## Fortification Persistence

- Fortifications persist for the duration of the match.
- If a base is recaptured by the enemy, player fortifications are **destroyed**.
- If players recapture a base, they must rebuild fortifications from scratch.

---

## Strategic Value

- Early investment in HQ fortifications provides a strong defensive fallback.
- Forward base fortification slows enemy counter-attacks significantly.
- Manned emplacements (HMG, AT, Mortar) require players to operate them — they are not AI-controlled.

---

## Related Systems

- [Supply Depot System](./supply-depot-system.md)
- [Base & HQ System](./base-hq-system.md)
- [Support Systems](./support-systems.md)
- [HQ Command Terminal](./support-systems.md)
