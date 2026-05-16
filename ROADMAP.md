# 🗺️ Development Roadmap
### FrontLine Framework — Arma Reforger Conflict PvE

---

## Current Status
> 🟡 **Phase 1 — In Progress**

---

## Phase Overview

| Phase | Title | Status |
|---|---|---|
| Phase 1 | Mod folder structure & Workbench project setup | 🟡 In Progress |
| Phase 2 | World Editor — Place capture points, start points, depots, HQs | ⬜ Not Started |
| Phase 3 | Capture point logic & state system | ⬜ Not Started |
| Phase 4 | Radio signal link system | ⬜ Not Started |
| Phase 5 | Enemy AI garrison & reactive counter-attack | ⬜ Not Started |
| Phase 6 | Supply depot generation & friendly AI truck convoys | ⬜ Not Started |
| Phase 7 | HQ Command Terminal UI, fortification & support systems | ⬜ Not Started |
| Phase 8 | Win/Lose conditions, HUD, map markers & balancing | ⬜ Not Started |
| Phase 9 | Full playtest → stable fallback → mod integration | ⬜ Not Started |

---

## Phase Details

### 🟡 Phase 1 — Mod Folder Structure & Workbench Setup
- [ ] Create mod folder structure inside Arma Reforger Tools
- [ ] Configure `.gproj` project file
- [ ] Set up initial EnforceScript file layout
- [ ] Verify project compiles cleanly with no errors

---

### ⬜ Phase 2 — World Editor Placement (Everon)
- [ ] Place player HQ candidate spawn points (random selection pool)
- [ ] Place Enemy Main HQ location
- [ ] Place all capture points across Everon
- [ ] Place all supply depot locations
- [ ] Assign signal link radii to all bases
- [ ] Verify layout balance across the map

---

### ⬜ Phase 3 — Capture Point Logic & State System
- [ ] Define capture point states: `Neutral` → `BeingCaptured` → `PlayerOwned` / `EnemyOwned`
- [ ] Implement zone detection for players and AI entering capture radius
- [ ] Implement capture progress bar logic
- [ ] Broadcast state change events to other systems
- [ ] Test state transitions with multiple players

---

### ⬜ Phase 4 — Radio Signal Link System
- [ ] Define signal radius per base
- [ ] Implement connectivity check between bases and capture points
- [ ] Update connectivity dynamically as bases change ownership
- [ ] Gate capture point contestability behind signal link check
- [ ] Test signal propagation across the Everon layout

---

### ⬜ Phase 5 — Enemy AI Garrison & Reactive Counter-Attack
- [ ] Set up AI garrison groups at enemy bases and HQ
- [ ] Implement counter-attack trigger — fires ONLY when a point enters `BeingCaptured` state
- [ ] Confirm enemy AI will NOT push already `PlayerOwned` points
- [ ] Cancel counter-attack orders if capture flips before AI arrives
- [ ] Set up mixed infantry + mechanized compositions for larger bases
- [ ] Configure heavily fortified Enemy Main HQ defence

---

### ⬜ Phase 6 — Supply System & Friendly AI Convoys
- [ ] Implement passive supply generation per captured depot (configurable rate)
- [ ] Spawn friendly AI supply trucks when a depot is secured
- [ ] Script truck route: depot → Main HQ
- [ ] Handle truck destruction (convoy lost, redispatch timer)
- [ ] Accumulate returned supplies into HQ supply pool

---

### ⬜ Phase 7 — HQ Terminal, Fortification & Support Systems
- [ ] Build HQ Command Terminal UI
- [ ] Connect terminal to HQ supply pool
- [ ] Implement fortification placement (sandbags, bunkers, emplacements, etc.)
- [ ] Implement support system call-ins (artillery, CAS, reinforcements, resupply, etc.)
- [ ] Add cooldown timers to support calls
- [ ] Test spend/receive supply balance

---

### ⬜ Phase 8 — Win/Lose Conditions, HUD & Balancing
- [ ] Implement win condition: Enemy Main HQ captured
- [ ] Implement lose condition: Player Main HQ captured by enemy
- [ ] Build supply counter HUD element
- [ ] Build minimap indicators (depot status, capture point status, convoys)
- [ ] Add objective status ticker
- [ ] Balance AI strength, supply rates and support costs

---

### ⬜ Phase 9 — Playtest & Stable Fallback
- [ ] Full co-op playtest session
- [ ] Log all bugs and balance issues
- [ ] Fix critical issues
- [ ] Tag repository as **v1.0-stable**
- [ ] Begin mod integration from stable fallback point

---

## Status Legend

| Symbol | Meaning |
|---|---|
| 🟢 | Complete |
| 🟡 | In Progress |
| 🔴 | Blocked |
| ⬜ | Not Started |
