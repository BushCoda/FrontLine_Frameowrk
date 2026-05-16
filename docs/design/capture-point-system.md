# 🚩 Capture Point System
### FrontLine Framework — Design Document

---

## Overview

The capture point system is the core territorial mechanic of FrontLine Framework. Players and enemy AI contest defined zones across Everon to push the frontline toward the enemy Main HQ.

---

## Capture Point States

Every capture point operates on the following state machine:

```
Neutral ──► BeingCaptured ──► PlayerOwned
                │                  │
                ▼                  ▼
           EnemyOwned ◄── BeingCaptured (enemy recapture)
```

| State | Description |
|---|---|
| `Neutral` | Point is unclaimed, no active capture in progress |
| `BeingCaptured` | Players are inside the zone and capture is progressing |
| `PlayerOwned` | Point is fully secured by players |
| `EnemyOwned` | Point is held by enemy AI |

---

## Capture Rules

- Capture progress begins when **one or more players** enter the capture zone.
- Progress is **paused** if both players and enemy AI are present in the zone simultaneously (contested).
- Progress **resets** if all players leave the zone before capture completes.
- Once `PlayerOwned`, the point **cannot be recaptured** by the enemy unless an enemy AI unit enters the zone **and** the point is within an active enemy base signal radius.

---

## Enemy Counter-Attack Rule

> ⚠️ **Critical Rule:** Enemy AI will ONLY respond to a capture point when it enters the `BeingCaptured` state.

- Enemy AI will **not** attack `PlayerOwned` points unprovoked.
- Enemy AI will **not** patrol toward secured player territory.
- Counter-attack orders are **cancelled** if the capture point flips to `PlayerOwned` before enemy AI arrives.
- Enemy response is only valid if the point is **within signal range** of an active enemy base.

---

## Signal Link Requirement

A capture point can only be contested by a faction if:

1. That faction has an **active base** (not destroyed/captured).
2. The capture point is **within the signal radius** of that base.

If the enemy has no signal-linked base near a point, they **cannot contest it** regardless of capture state.

---

## Capture Progress Configuration

| Parameter | Default | Description |
|---|---|---|
| `CaptureRadius` | 50m | Radius of the capture zone |
| `CaptureTimeSeconds` | 60s | Time to fully capture a neutral point |
| `RecaptureTimeSeconds` | 90s | Time to flip an enemy-owned point |
| `ProgressResetOnLeave` | true | Whether progress resets if players leave |

> All values are configurable via the scenario config file.

---

## Placement Notes

- All capture points are **manually placed** in the Arma Reforger World Editor.
- Each point must be assigned:
  - A unique identifier / name.
  - An initial ownership state (`Neutral` or `EnemyOwned`).
  - A reference to its nearest base for signal link calculations.
- Capture points should be placed at **tactically meaningful locations** across Everon (towns, crossroads, high ground).

---

## Related Systems

- [Radio Signal Link System](./radio-signal-link.md)
- [Enemy AI Behaviour](./enemy-ai-behaviour.md)
- [Supply Depot System](./supply-depot-system.md)
