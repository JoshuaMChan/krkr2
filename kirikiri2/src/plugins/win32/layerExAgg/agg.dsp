# Microsoft Developer Studio Project File - Name="agg" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** �ҏW���Ȃ��ł������� **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=agg - Win32 Debug
!MESSAGE ����͗L����Ҳ�̧�قł͂���܂���B ������ۼު�Ă�����ނ��邽�߂ɂ� NMAKE ���g�p���Ă��������B
!MESSAGE [Ҳ�̧�ق̴���߰�] ����ނ��g�p���Ď��s���Ă�������
!MESSAGE 
!MESSAGE NMAKE /f "agg.mak".
!MESSAGE 
!MESSAGE NMAKE �̎��s���ɍ\�����w��ł��܂�
!MESSAGE ����� ײݏ��ϸۂ̐ݒ���`���܂��B��:
!MESSAGE 
!MESSAGE NMAKE /f "agg.mak" CFG="agg - Win32 Debug"
!MESSAGE 
!MESSAGE �I���\������� Ӱ��:
!MESSAGE 
!MESSAGE "agg - Win32 Release" ("Win32 (x86) Dynamic-Link Library" �p)
!MESSAGE "agg - Win32 Debug" ("Win32 (x86) Dynamic-Link Library" �p)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "agg - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\bin\win32\plugin"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AGG_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "../" /I "agg23/include" /I "agg23/svg" /I "c:/Expat-2.0.0/Source/lib" /I "../layerEx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AGG_EXPORTS" /D "XML_STATIC" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libexpatMT.lib /nologo /dll /debug /machine:I386 /libpath:"C:\Expat-2.0.0\StaticLibs" /COMMENT:"(--has-option--)"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "agg - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\bin\win32\plugin"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AGG_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../" /I "agg23/include" /I "agg23/svg" /I "c:/Expat-2.0.0/Source/lib" /I "../layerEx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "AGG_EXPORTS" /D "XML_STATIC" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libexpatMT.lib /nologo /dll /debug /machine:I386 /pdbtype:sept /libpath:"C:\Expat-2.0.0\StaticLibs" /COMMENT:"(--has-option--)"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "agg - Win32 Release"
# Name "agg - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\agg.def
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_bezier_arc.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_curves.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_path_storage.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_rasterizer_scanline_aa.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\svg\agg_svg_parser.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\svg\agg_svg_path_renderer.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\svg\agg_svg_path_tokenizer.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_trans_affine.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_vcgen_contour.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_vcgen_dash.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_vcgen_markers_term.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_vcgen_stroke.cpp
# End Source File
# Begin Source File

SOURCE=.\agg23\src\agg_vpgen_clip_polygon.cpp
# End Source File
# Begin Source File

SOURCE=..\layerEx\LayerExBase.cpp
# End Source File
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\Primitive.hpp
# End Source File
# Begin Source File

SOURCE=.\PrimitiveSVG.cpp
# End Source File
# Begin Source File

SOURCE=..\tp_stub.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\tp_stub.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project