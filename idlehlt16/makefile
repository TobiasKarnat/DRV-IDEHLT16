# -bt=os2    = Build target OS is OS/2
# -3         = Enable use of 80386 instructions   Optimize for 386 
# -o         = Optimization
#              h = repeated optimizations
#              r = optimize for 80486 and Pentium pipes
# -s         = Omit stack size checking from start of each function
# -zu        = Do not assume that SS contains segment of DGROUP
# -zl        = Place no library references into objects
# -zq        = Operate quietly
# -wx        = Warning level set to maximum

ASM     = wasm
CC      = wcc
LD      = wlink

OS21_H  = $(%WATCOM)\h;$(%WATCOM)\h\os21x
INCLUDE = $(OS21_H);.\include

.asm.obj: .AUTODEPEND
  $(ASM) $*.asm

.c.obj:   .AUTODEPEND
  $(CC) -i=$(INCLUDE) -bt=os2 -3 -ohr -s -zu -zl -zq -wx $*.c

OBJS = devsegs.obj header.obj init.obj strategy.obj ioctl.obj
SEGS = seg type DATA SHARED PRELOAD, '_TEXT' PRELOAD IOPL, '_INITCODE' PRELOAD IOPL

all: idlehlt.sys idlehlt.exe .SYMBOLIC

idlehlt.sys: $(OBJS)
  $(LD) name idlehlt.sys sys os2_dll initg op prot,st=0 lib os2 $(SEGS) FILE {$(OBJS)}

idlehlt.exe:
  $(CC) -i=$(INCLUDE) -bt=os2 -3 -ohr -s -zq -wx idlehlt.c
  $(LD) name idlehlt.exe sys os2 op prot,el,st=2k FILE idlehlt.obj

clean:    .SYMBOLIC
CLEANEXT = sys exe obj err lnk sym lst map lib
  @for %a in ($(CLEANEXT)) do -@rm *.%a
