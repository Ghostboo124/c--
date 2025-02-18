;--------------------------------
; Includes

  !include "MUI2.nsh"
  !include "logiclib.nsh"

;--------------------------------
; Custom defines

  !define NAME    "Application Opener"
  !define APPFILE "applicationOpener.exe"
  !define VERSION "1.1.0"
  !define SLUG    "${NAME} v${VERSION}"

;--------------------------------
; General

  Name                  "${NAME}"
  OutFile               "${NAME} Setup.exe"
  InstallDir            "$LOCALAPPDATA\${NAME}"
  InstallDirRegKey      HKCU "Software\${NAME}" ""
  RequestExecutionLevel user

;--------------------------------
; UI

  !define MUI_ICON                     "assets\icon.ico"
  !define MUI_HEADERIMAGE
  !define MUI_WELCOMEFINISHPAGE_BITMAP "assets\welcome.bmp"
  !define MUI_HEADERIMAGE_BITMAP       "assets\head.bmp"
  !define MUI_ABORTWARNING
  !define MUI_WELCOMEPAGE_TITLE        "${SLUG} Setup"

;--------------------------------
; Pages

  ; Installer Pages
  !insertmacro MUI_PAGE_WELCOME
  !insertmacro MUI_PAGE_LICENSE "license.txt"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  !insertmacro MUI_PAGE_FINISH

  ; Uninstaller Pages
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES
  !insertmacro MUI_UNPAGE_FINISH

  ; Set UI Language
  !insertmacro MUI_LANGUAGE "English"

;--------------------------------
; Example Section - DirectX

  ; Section "DirectX" DirectX
  ;   SetOutPath "$INSTDIR\Redist"
  ;   File "redist\directx\dxwebsetup.exe"
  ;   DetailPrint "Running DirectX Setup..."
  ;   ExecWait "$INSTDIR\Redist\dxwebsetup.exe"
  ;   DetailPrint "Finished DirectX Setup"
  ; SectionEnd

;--------------------------------
; Section - Install App

  Section "-hidden app"
    SectionIn RO
    SetOutPath "$INSTDIR"
    File /r "app\*.*"

    ; Write Registry changes
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" ""                     "(value not set)"
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "InstallLocation"      "$INSTDIR"
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "Version"              "${VERSION}"
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "DisplayName"          "${SLUG}"
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "DisplayIcon"          "$INSTDIR\data\icons\ase.ico"
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "DisplayVersion"       "${VERSION}"
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "UninstallString"      "$\"$INSTDIR\Uninstall.exe$\""
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "QuietUninstallString" "$\"$INSTDIR\Uninstall.exe$\" /S"
    WriteRegStr HKCU   "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "Publisher"            "Iagara Studio S.A."
    WriteRegDWORD HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "EstimatedSize"        0x00008995
    WriteRegDWORD HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "Language"             0x00000409
    WriteRegDWORD HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "NoModify"             0x00000001
    WriteRegDWORD HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}\" "NoRepair"             0x00000001

    ; Make an uninstaller
    WriteUninstaller "$INSTDIR\Uninstall.exe"
  SectionEnd

;--------------------------------
; Section Group - Shortcuts

  SectionGroup Shortcuts Shorts
    ; Section - Start Menu Shortcut
    Section "Start Menu Shortcut" StartShort
      CreateShortCut "$SMPROGRAMS\${NAME}.lnk" "$INSTDIR\${APPFILE}"
    SectionEnd

    ; Section - Desktop Shortcut
    Section "Desktop Shortcut" DeskShort
      CreateShortCut "$DESKTOP\${NAME}.lnk" "$INSTDIR\${APPFILE}"
    SectionEnd
  SectionGroupEnd

;--------------------------------
; Descriptions

  ; Language Strings
  LangString DESC_Shorts ${LANG_ENGLISH} "Creates shortcuts."
  LangString DESC_DeskShort ${LANG_ENGLISH} "Create a shortcut on the Desktop."
  LangString DESC_StartShort ${LANG_ENGLISH} "Creates a shortcut in your users Start Menu."

  ; Assign Language Strings to sections
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${Shorts} $(DESC_Shorts)
    !insertmacro MUI_DESCRIPTION_TEXT ${DeskShort} $(DESC_DeskShort)
    !insertmacro MUI_DESCRIPTION_TEXT ${StartShort} $(DESC_StartShort)
  !insertmacro MUI_FUNCTION_DESCRIPTION_END

; -------------------------------
; Remove empty parent directories

  Function un.RMDirUP
    !define RMDirUP '!insertmacro RMDirUPCall'

    !macro RMDirUPCall _PATH
      push '${_PATH}'
      Call un.RMDirUP
    !macroend

    ; $0 - current folder
    ClearErrors

    Exch $0
    ; DetailPrint "ASDF - $0\.."
    RMDIR "$0\.."

    IfErrors Skip
    ${RMDirUP} "$0\.."
    Skip:

    Pop $0
  FunctionEnd

; -------------------------------
; Section - Uninstaller

Section "Uninstall"
  ; Delete Desktop Shortcut
  Delete "$DESKTOP\${NAME}.lnk"
  Delete "$APPDATA\Microsoft\Windows\Start Menu\Programs\${NAME}.lnk"

  ; Delete Uninstall
  Delete "$INSTDIR\Uninstall.exe"

  ; Delete Folder
  RMDir /r "$INSTDIR"
  ${RMDirUP} "$INSTDIR"
  
  DeleteRegKey HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME}"
SectionEnd