# 🔧 Workbench Setup Guide
### FrontLine Framework — Setup Documentation

---

## Overview

This guide covers how to set up the FrontLine Framework mod project inside Arma Reforger Tools (Workbench). Follow these steps before writing any gameplay scripts to ensure the project compiles cleanly from the start.

---

## Requirements

| Requirement | Details |
|---|---|
| **Game** | Arma Reforger (Steam) |
| **Tools** | Arma Reforger Tools (Steam — free) |
| **Map** | Base Everon (included with the game — no mods required) |
| **Scripting Language** | EnforceScript (`.c` files) |

---

## Step 1 — Install Arma Reforger Tools

1. Open Steam and navigate to your **Library**.
2. Search for **Arma Reforger Tools** — it is a free tool in your library if you own Arma Reforger.
3. Install it.
4. Launch **Workbench** from Steam.

---

## Step 2 — Create the Mod Folder Structure

Navigate to your Arma Reforger addons directory:

```
Documents/My Games/ArmaReforger/addons/
```

Create the following folder structure:

```
FrontLine_Framework/
├── Scripts/
│   ├── Game/
│   └── UI/
│   └── Config/
├── Worlds/
├── Prefabs/
└── FrontLine_Framework.gproj
```

---

## Step 3 — Create the `.gproj` File

Create a file named `FrontLine_Framework.gproj` in the root of your mod folder with the following content:

```json
{
    "ProjectName": "FrontLine_Framework",
    "ProjectVersion": "0.1.0",
    "Author": "BushCoda",
    "Description": "Conflict PvE Framework for Arma Reforger on Everon",
    "Dependencies": [
        {
            "ModID": "vanilla",
            "Name": "Arma Reforger"
        }
    ]
}
```

---

## Step 4 — Open the Project in Workbench

1. Launch **Workbench** from Steam.
2. Click **Open Project**.
3. Navigate to your `FrontLine_Framework/` folder.
4. Select the `FrontLine_Framework.gproj` file.
5. Workbench will load your project.

---

## Step 5 — Verify Clean Compile

1. In Workbench, open the **Script Editor**.
2. Press **Compile All** (or `F7`).
3. Confirm there are **zero errors** in the output log.
4. If errors appear, check that your folder structure matches Step 2 exactly.

---

## Step 6 — Open the Everon World

1. In Workbench, go to **File → Open World**.
2. Navigate to the base game Everon world file.
3. Open it — this is where you will manually place all capture points, bases, depots, and spawn points in Phase 2.

> ⚠️ Do NOT modify and save over the base Everon world file directly. Always work in a **scenario layer** on top of the base world.

---

## Step 7 — Create Your Scenario Layer

1. In the World Editor, create a **new scenario** using Everon as the base world.
2. Save your scenario inside your mod's `Worlds/` folder:
   ```
   FrontLine_Framework/Worlds/FrontLine_Everon.ent
   ```
3. All entity placements (capture points, bases, spawn points) will be saved to this file — the base Everon world remains untouched.

---

## Phase 1 Checklist

- [ ] Arma Reforger Tools installed
- [ ] Mod folder structure created
- [ ] `.gproj` file configured
- [ ] Project opens in Workbench without errors
- [ ] Script compile returns zero errors
- [ ] Everon world opens in World Editor
- [ ] Scenario layer created and saved to `Worlds/`

---

## Related Documents

- [EnforceScript Overview](../scripting/enforcescript-overview.md)
- [Capture Point System](../design/capture-point-system.md)
- [Base & HQ System](../design/base-hq-system.md)
