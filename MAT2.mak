# Microsoft Developer Studio Generated NMAKE File, Based on MAT2.dsp
!IF "$(CFG)" == ""
CFG=MAT2 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to MAT2 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "MAT2 - Win32 Release" && "$(CFG)" != "MAT2 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MAT2.mak" CFG="MAT2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MAT2 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MAT2 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MAT2 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MAT2.exe"

!ELSE 

ALL : "$(OUTDIR)\MAT2.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MAT2.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\MAT2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D\
 "_MBCS" /Fp"$(INTDIR)\MAT2.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MAT2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)\MAT2.pdb" /machine:I386 /out:"$(OUTDIR)\MAT2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MAT2.obj"

"$(OUTDIR)\MAT2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MAT2 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MAT2.exe"

!ELSE 

ALL : "$(OUTDIR)\MAT2.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MAT2.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\MAT2.exe"
	-@erase "$(OUTDIR)\MAT2.ilk"
	-@erase "$(OUTDIR)\MAT2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /D "_MBCS" /Fp"$(INTDIR)\MAT2.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c\
 
CPP_OBJS=.\Debug/
CPP_SBRS=.
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MAT2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)\MAT2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MAT2.exe"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MAT2.obj"

"$(OUTDIR)\MAT2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "MAT2 - Win32 Release" || "$(CFG)" == "MAT2 - Win32 Debug"
SOURCE=.\MAT2.c
DEP_CPP_MAT2_=\
	".\calc_2.h"\
	".\calc_fn.h"\
	".\calc_fn_.h"\
	".\calc_fn_2k.h"\
	".\calc_fn_2kx.h"\
	".\calc_fn_fx.h"\
	".\calc_fn_k.h"\
	".\calc_fn_kl.h"\
	".\calc_fn_komb.h"\
	".\calc_fn_matrix.h"\
	".\calc_fn_sim.h"\
	".\calc_fn_tab.h"\
	".\calc_profil.h"\
	".\MAT2.h"\
	".\MAT3.h"\
	

"$(INTDIR)\MAT2.obj" : $(SOURCE) $(DEP_CPP_MAT2_) "$(INTDIR)"



!ENDIF 

