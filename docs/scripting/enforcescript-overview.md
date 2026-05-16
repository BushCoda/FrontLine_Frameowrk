# 📜 EnforceScript Overview
### FrontLine Framework — Scripting Reference

---

## Overview

FrontLine Framework is scripted entirely in **EnforceScript** — the scripting language used by Arma Reforger. This document serves as a quick reference for patterns and conventions used throughout the mod's codebase.

---

## EnforceScript Basics

EnforceScript is a statically typed, object-oriented scripting language similar to C++/C#. It is compiled at load time and runs on both server and client contexts depending on how classes and methods are decorated.

### Key Characteristics

| Feature | Detail |
|---|---|
| Typing | Statically typed |
| Paradigm | Object-oriented |
| Execution | Server-authoritative with client replication |
| File Extension | `.c` |
| Entry Points | `OnGameStart()`, `OnGameEnd()`, component `OnInit()` |

---

## Project File Structure

```
Scripts/
├── Game/
│   ├── FLF_CapturePointSystem.c       # Capture point state machine
│   ├── FLF_RadioSignalSystem.c        # Signal radius and link checks
│   ├── FLF_EnemyAIController.c        # AI counter-attack and garrison logic
│   ├── FLF_SupplySystem.c             # Supply generation and convoy logic
│   ├── FLF_FortificationSystem.c      # Fortification placement logic
│   ├── FLF_SupportSystem.c            # Support call-in logic
│   └── FLF_WinLoseConditions.c        # Win/lose condition checks
├── UI/
│   ├── FLF_HQTerminalUI.c             # HQ Command Terminal UI
│   └── FLF_HUD.c                      # Supply counter and objective HUD
└── Config/
    └── FLF_ScenarioConfig.c           # Centralised configuration values
```

---

## Naming Conventions

All FrontLine Framework scripts use the `FLF_` prefix to avoid conflicts with base game classes.

| Element | Convention | Example |
|---|---|---|
| Classes | `FLF_PascalCase` | `FLF_CapturePointComponent` |
| Methods | `camelCase` | `onCaptureStateChanged()` |
| Variables | `camelCase` | `captureProgress` |
| Constants | `UPPER_SNAKE_CASE` | `MAX_CAPTURE_TIME` |
| Enums | `FLF_E_PascalCase` | `FLF_E_CaptureState` |

---

## Capture Point State Enum

```cpp
enum FLF_E_CaptureState
{
    NEUTRAL,
    BEING_CAPTURED,
    PLAYER_OWNED,
    ENEMY_OWNED
}
```

---

## Key Patterns

### Event Broadcasting
State changes are broadcast via game events so that all systems can react independently without tight coupling:

```cpp
// Broadcast capture state change
GetGame().GetCallqueue().CallLater(OnCaptureStateChanged, 0, false, capturePoint, newState);
```

### Server Authority
All state-changing logic runs **server-side only**. Client UI receives replicated data:

```cpp
if (!GetGame().IsServer())
    return;
```

### Component-Based Architecture
Each system is implemented as a **ScriptedGameComponent** attached to relevant world entities:

```cpp
class FLF_CapturePointComponent : ScriptedGameComponent
{
    override void OnInit(IEntity owner) { ... }
    override void OnUpdate(IEntity owner, float timeSlice) { ... }
}
```

---

## Useful Arma Reforger API References

| API | Usage |
|---|---|
| `GetGame()` | Access to core game instance |
| `GetGame().IsServer()` | Check for server authority |
| `GetGame().GetCallqueue()` | Schedule delayed calls |
| `QueryEntitiesInSphere()` | Detect entities within a radius (used for signal and capture checks) |
| `AIGroup` | Managing AI unit groups |
| `SCR_BaseGameMode` | Base class for custom game modes |

---

## Related Files

- [Workbench Setup Guide](../setup/workbench-setup.md)
