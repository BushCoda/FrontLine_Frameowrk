# 🏆 Win & Lose Conditions
### FrontLine Framework — Design Document

---

## Overview

FrontLine Framework has a single clear win condition and a single clear lose condition. Both are tied to HQ capture — keeping the scenario focused and decisive.

---

## Win Condition

> ✅ **Players win when the Enemy Main HQ capture zone is fully captured.**

- Players must push through enemy territory, capture forward bases, and breach the Enemy Main HQ.
- The HQ capture zone follows the standard capture state machine: `EnemyOwned` → `BeingCaptured` → `PlayerOwned`.
- Once `PlayerOwned` is reached for the Enemy Main HQ → **match ends, players win**.
- A victory screen is displayed to all players.

---

## Lose Condition

> ❌ **Players lose when the Player Main HQ capture zone is fully captured by enemy AI.**

- Enemy AI can only attack the Player Main HQ if it is within an active enemy base signal radius.
- If the players lose all forward bases between the enemy and their HQ, the enemy signal network may reach the Player HQ.
- Once the Player HQ enters `BeingCaptured` state, players have time to respond and repel the enemy before it flips.
- Once `EnemyOwned` is reached for the Player Main HQ → **match ends, players lose**.
- A defeat screen is displayed to all players.

---

## End of Match Flow

```
Enemy HQ → PlayerOwned  ──► Victory Screen ──► Session End
Player HQ → EnemyOwned  ──► Defeat Screen  ──► Session End
```

- All AI activity stops on match end.
- Players are presented with a summary of the match (territory controlled, supplies earned, time elapsed).
- Session can be restarted from the lobby.

---

## HQ Capture Rules

- Player HQ and Enemy HQ both follow the standard capture point state machine.
- The **Enemy AI counter-attack rule applies** — enemy AI will only contest the Player HQ if it is within their signal network.
- Players defending the HQ can interrupt and reset enemy capture progress by eliminating all enemy units inside the capture zone.
- The HQ capture zone is larger than standard capture points to reflect its significance.

---

## Design Intent

- The win/lose conditions are intentionally simple and clearly communicated to players at all times via the HUD.
- Players always know what they need to do: **push to the Enemy HQ** and **defend their own**.
- The signal link and supply systems create natural tension — losing territory has cascading consequences that can ultimately lead to defeat.

---

## HUD Indicators

| Indicator | Description |
|---|---|
| Enemy HQ Capture Progress | Displayed prominently when players are contesting the Enemy HQ |
| Player HQ Capture Progress | Urgent alert displayed when enemy is contesting the Player HQ |
| Territory Control Overview | Minimap showing current ownership of all bases and depots |

---

## Related Systems

- [Capture Point System](./capture-point-system.md)
- [Base & HQ System](./base-hq-system.md)
- [Radio Signal Link System](./radio-signal-link.md)
