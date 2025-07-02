; Installation script for Inno Setup

[Setup]
; Basic information about the installation
AppName=SaveDovacre
AppVersion=1.0
DefaultDirName={pf}\SaveDovacre
DefaultGroupName=SaveDovacre
OutputDir=.
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
; Include all necessary files
Source: "SaveDovacre.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Dovacre.ico"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
; Create a shortcut on the desktop
Name: "{userdesktop}\SaveDovacre"; Filename: "{app}\SaveDovacre.exe"; IconFilename: "{app}\Dovacre.ico"

[Run]
; Lancer le batch file après l'installation si nécessaire
Filename: "{app}\SaveDovacre.exe";
