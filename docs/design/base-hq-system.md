# 🏠 Base & HQ System
### FrontLine Framework — Design Document

---

## Overview

Bases and HQs are the backbone of FrontLine Framework. They define faction territory, project signal coverage, garrison AI units, and serve as the win/lose condition anchors. All bases are manually placed in the World Editor.

---

## Base Types

| Type | Faction | Purpose |
|---|---|---|
| Player Main HQ | Player | Starting base, lose condition if captured |
| Player Forward Base | Player | Captured and held to push the frontline |
| Enemy Forward Base | Enemy | Enemy garrison and counter-attack origin points |
| Enemy Main HQ | Enemy | Final objective — win condition if captured |
| Supply Depot | Shared | Generates supplies when player-owned |

---

## Player Main HQ

- Randomly selected from a pool of manually placed candidate locations at match start.
- Cannot be moved once selected.
- Houses the **HQ Command Terminal** for fortification and support call-ins.
- Has a large signal radius to cover initial capture point access.
- If captured by enemy AI → **game over (lose condition)**.
- Players should fortify and defend the HQ as the match progresses.

---

## Enemy Main HQ

- Fixed location manually placed on Everon.
- Heavily pre-fortified with static defences.
- Large permanent garrison — does not send counter-attacks.
- Has its own large signal radius covering surrounding territory.
- If captured by players → **game over (win condition)**.

---

## Forward Bases

- Intermediate bases spread across Everon between the two HQs.
- Start as **Enemy-owned** at match start.
- Players capture forward bases to extend their signal network toward the enemy HQ.
- Each forward base has:
  - A garrison of enemy AI (pre-placed, replenished over time).
  - A radio tower projecting a signal radius.
  - A capture zone that follows the standard capture point state machine.

---

## Base Signal Coverage

Each base projects a signal radius from its radio tower:

| Base Type | Default Signal Radius |
|---|---|
| Small FOB | 1000m |
| Medium Forward Base | 1500m |
| Large Forward Base | 2000m |
| Main HQ | 2500m |

See [Radio Signal Link System](./radio-signal-link.md) for full details.

---

## Base Capture Flow

```
EnemyOwned ──► BeingCaptured (players inside zone) ──► PlayerOwned
                        │
                        ▼
              Enemy counter-attack triggered
              (if signal-linked to enemy base)
```

Once `PlayerOwned`:
- Enemy garrison is cleared.
- Player signal radius activates from this base.
- New capture points become accessible within the new signal radius.
- Players may spend supplies to fortify the base.

---

## Placement Notes

- All bases must be manually placed in the World Editor.
- Each base requires:
  - A capture zone trigger.
  - A radio tower entity with faction and radius assigned.
  - AI spawn points for garrison units.
  - An initial ownership state (`PlayerOwned` for Player HQ, `EnemyOwned` for all others).

---

## Related Systems

- [Radio Signal Link System](./radio-signal-link.md)
- [Capture Point System](./capture-point-system.md)
- [Supply Depot System](./supply-depot-system.md)
- [Fortification System](./fortification-system.md)
- [Win & Lose Conditions](./win-lose-conditions.md)
