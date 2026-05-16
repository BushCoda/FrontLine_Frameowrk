# 🔧 Mod Project Setup Guide
### FrontLine Framework — Setup Documentation

> 📖 This document is based on the official [Arma Reforger Mod Project Setup](https://community.bistudio.com/wiki/Arma_Reforger:Mod_Project_Setup) wiki page.

---

## Prerequisites

- Arma Reforger installed
- Arma Reforger Tools (Workbench) installed via Steam

---

## Workbench Launcher Setup

Before creating a new project, Enfusion Workbench Launcher must know where Reforger data is located.

### Adding the Arma Reforger Project

1. Start Workbench via **Steam → Tools → Arma Reforger Tools → START** or by double-clicking `ArmaReforgerWorkbenchSteam.exe`.
2. Click **Add Existing**.
3. Browse to `ArmaReforger.gproj` located at:
   ```
   <Arma Reforger installation directory>\addons\data\ArmaReforger.gproj
   ```
4. Select it — Arma Reforger is now listed in the Projects window.

### Adding Other Existing Projects (Dependencies)

1. Click **+ Add Project**.
2. Select **Scan for Projects**.
3. Select the folder where your addons/dependencies are located.
4. Confirm selection.

> ℹ️ The Projects list is stored in your user profile. You can use different profiles via the `-profile` command line parameter.

---

## Project Creation

1. Open Enfusion Workbench Launcher.
2. Click **Create New**.
3. Enter the project name.
   - Allowed characters: letters, numbers, spaces, `-` `_` `.`
4. Confirm or edit the project location.

> ⚠️ Do **NOT** create projects in OneDrive directories — they will fail to load!
> ⚠️ Ensure the location has write permissions (e.g. `C:\Users\Username\Documents`).

5. Pick dependencies:
   - **Arma Reforger** is a required default dependency.
   - Add any other mods your project depends on.
6. Click **OK** to create the project.

> ℹ️ The default project directory is `%userProfile%\Documents\My Games\ArmaReforgerWorkbench\addons`.

---

## Launching Your Project

Once projects are added to the list:

- **Double-click** the mod tile to open it.
- **Right-click → Open** to open from context menu.
- **Right-click → Open with Addons** to launch with additional mods that are not dependencies.

### Presets

- Addon selections in **Open with Addons** are saved in Presets.
- Up to **8 presets** are available, selectable from the top-right corner.

---

## Removing Projects

- Right-click the project → **Remove from List**.
- This removes it from the list only — project data on disk is unaffected.

---

## FrontLine Framework Project Setup Checklist

- [ ] Arma Reforger installed and launched at least once
- [ ] Arma Reforger Tools installed via Steam
- [ ] `ArmaReforger.gproj` added to Workbench Projects list
- [ ] `FrontLine_Framework` project created in Workbench
- [ ] Arma Reforger set as a dependency
- [ ] Project opens and compiles cleanly (**Shift + F7**)
- [ ] Scenario layer created in World Editor (`Worlds/FrontLine_Everon.ent`)

---

## Troubleshooting

### Arma Reforger project not found in Projects window
Manually add `ArmaReforger.gproj` via **Add Existing** — see [Adding the Arma Reforger Project](#adding-the-arma-reforger-project) above.

### Workbench loads without your mod
Ensure all dependencies (and their dependencies) are visible in the Projects list. Missing dependency error example:
```
ENGINE (E): Addon 'FrontLine_Framework' dependency '5614E48126E3ADF2' can't be added
```
Find the GUID on the workshop: `https://reforger.armaplatform.com/workshop/<GUID>`

### Project is read-only
- Ensure the project is **not** synced via OneDrive or Google Drive.
- Ensure the project is **not** in the same folder as downloaded Workshop mods.

To remove read-only attributes, run this batch script from the root of your addon:
```batch
@echo off
setlocal enabledelayedexpansion
echo Removing read-only attributes recursively...
for /d /r %%D in (*) do (
    attrib -r -s "%%D" /S /D
)
attrib -R *.* /S
echo Done.
pause
```

### Empty dependency error
If you see:
```
ENGINE (E): Addon 'FrontLine_Framework' dependency '' can't be added
```
Open your `.gproj` file in a text editor and manually remove the empty `''` entry from the Dependencies array.

---

## Related Documents

- [Workbench Setup Guide](./workbench-setup.md)
- [EnforceScript Overview](../scripting/enforcescript-overview.md)
