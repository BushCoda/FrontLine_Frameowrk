# 📞 Support Systems
### FrontLine Framework — Design Document

---

## Overview

The support system allows players to call in various battlefield assets by spending supplies at the HQ Command Terminal. Support options provide tactical advantages ranging from fire missions to troop reinforcements. Each support type has a supply cost and a cooldown timer to prevent abuse.

---

## HQ Command Terminal

- Physical terminal entity placed at the Player Main HQ in the World Editor.
- Players interact with the terminal to access the support menu.
- Displays current supply pool balance.
- All support calls are gated behind available supplies and active cooldowns.

---

## Support Options

| Support Type | Supply Cost | Cooldown | Description |
|---|---|---|---|
| Artillery Strike | 75 | 10 min | Fire mission on a designated target area |
| Close Air Support (CAS) | 100 | 15 min | Attack aircraft strike on a target area |
| Reinforcement Drop | 50 | 8 min | Deploy a squad of friendly AI infantry at a forward base |
| Resupply Drop | 40 | 5 min | Airdrop supplies directly to a forward base |
| Smoke Screen | 15 | 3 min | Deploy smoke to conceal player movement |
| Medical Resupply | 20 | 5 min | Restock medical supplies at a designated base |
| Vehicle Drop | 80 | 12 min | Deliver a vehicle to a player-owned base |

> All supply costs and cooldowns are configurable via the scenario config file.

---

## Cooldown System

- Each support type has an **independent cooldown timer**.
- Cooldown begins immediately after the support is called — not after it resolves.
- Players can see remaining cooldown timers in the HQ Terminal UI.
- Calling a support type while on cooldown is not permitted.

---

## Targeting

- **Artillery & CAS:** Player designates a target map grid via the terminal UI or a handheld designator.
- **Reinforcement Drop:** Player selects a target player-owned forward base from a list.
- **Resupply Drop:** Player selects a target player-owned base — supplies are added to that base's local pool.
- **Smoke Screen:** Player designates a map location — smoke is deployed at ground level.
- **Medical Resupply & Vehicle Drop:** Player selects a target player-owned base.

---

## Strategic Considerations

- Support calls consume supplies that could otherwise be spent on fortifications.
- Players must prioritise between defensive investment and offensive support tools.
- Artillery and CAS are powerful but expensive — best saved for assaulting the Enemy Main HQ.
- Reinforcement drops are useful for bolstering a base under heavy counter-attack pressure.

---

## Related Systems

- [Supply Depot System](./supply-depot-system.md)
- [Fortification System](./fortification-system.md)
- [Base & HQ System](./base-hq-system.md)
- [Win & Lose Conditions](./win-lose-conditions.md)
