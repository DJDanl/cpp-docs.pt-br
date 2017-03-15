---
title: "Makefile de exemplo para PCH | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "pch"
dev_langs: 
  - "C++"
ms.assetid: daf68983-77dc-45db-8701-aa89ad18910d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Makefile de exemplo para PCH
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O seguinte makefile usar macros e\! IF\! ELSE\! Estrutura de comando do fluxo de controle de ENDIF para simplificar sua adaptação ao seu projeto.  
  
```  
# Makefile : Illustrates the effective use of precompiled  
#            headers in a project  
# Usage:     NMAKE option  
# option:    DEBUG=[0|1]  
#            (DEBUG not defined is equivalent to DEBUG=0)  
#  
OBJS = myapp.obj applib.obj  
# List all stable header files in the STABLEHDRS macro.  
STABLEHDRS = stable.h another.h  
# List the final header file to be precompiled here:  
BOUNDRY = stable.h  
# List header files under development here:  
UNSTABLEHDRS = unstable.h  
# List all compiler options common to both debug and final  
# versions of your code here:  
CLFLAGS = /c /W3  
# List all linker options common to both debug and final  
# versions of your code here:  
LINKFLAGS = /NOD /ONERROR:NOEXE  
!IF "$(DEBUG)" == "1"  
CLFLAGS   = /D_DEBUG $(CLFLAGS) /Od /Zi /f  
LINKFLAGS = $(LINKFLAGS) /COD  
LIBS      = slibce  
!ELSE  
CLFLAGS   = $(CLFLAGS) /Oselg /Gs  
LINKFLAGS = $(LINKFLAGS)  
LIBS      = slibce  
!ENDIF  
myapp.exe: $(OBJS)  
    link $(LINKFLAGS) @<<  
$(OBJS), myapp, NUL, $(LIBS), NUL;  
<<  
# Compile myapp  
myapp.obj  : myapp.cpp $(UNSTABLEHDRS)  stable.pch  
    $(CPP) $(CLFLAGS) /Yu$(BOUNDRY)    myapp.cpp  
# Compile applib  
applib.obj : applib.cpp $(UNSTABLEHDRS) stable.pch  
    $(CPP) $(CLFLAGS) /Yu$(BOUNDRY)    applib.cpp  
# Compile headers  
stable.pch : $(STABLEHDRS)  
    $(CPP) $(CLFLAGS) /Yc$(BOUNDRY)    applib.cpp myapp.cpp  
```  
  
 Com exceção de macros de STABLEHDRS, LIMIT de, e de UNSTABLEHDRS mostrados na figura “estrutura de um Makefile que usa um cabeçalho Arquivo pré\-compilado” em [Arquivos de PCH no processo de criação](../Topic/PCH%20Files%20in%20the%20Build%20Process.md), esse makefile fornece um CLFLAGS macro e uma macro de LINKFLAGS.  Você deve usar esses macros para listar as opções do compilador e do vinculador que se aplicam se você criar uma depuração ou uma versão final do arquivo executável do aplicativo.  Há também uma macro LIB onde você lista as bibliotecas que requer seu projeto.  
  
 De makefile também usa o para\! IF\! ELSE\! ENDIF a detectar se você definir um símbolo de DEBUG na linha de comando de NMAKE:  
  
```  
NMAKE DEBUG=[1|0]  
```  
  
 Esse recurso é possível que você use o mesmo makefile durante o desenvolvimento e para as versões finais de seu programa — use DEBUG\=0 para as versões finais.  As seguintes linhas de comando são equivalentes:  
  
```  
NMAKE   
NMAKE DEBUG=0  
```  
  
 Para obter mais informações sobre os makefiles, consulte [Referência de NMAKE](../../build/nmake-reference.md).  Consulte também [Opções do compilador](../../build/reference/compiler-options.md) e [Opções do vinculador](../../build/reference/linker-options.md).  
  
## Consulte também  
 [Usando cabeçalhos pré\-compilados em um projeto](../../build/reference/using-precompiled-headers-in-a-project.md)