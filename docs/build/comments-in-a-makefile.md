---
title: "Coment&#225;rios em makefile | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "makefiles, comentários"
ms.assetid: 76fd9e3d-5966-47f4-a091-c9e80b232b49
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Coment&#225;rios em makefile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Antecedeu um comentário com um sinal de número \(\#\).  NMAKE ignora o texto de sinal numérico para o caractere de nova linha seguinte.  Exemplos:  
  
```  
# Comment on line by itself  
OPTIONS = /MAP  # Comment on macro definition line  
  
all.exe : one.obj two.obj  # Comment on dependency line  
    link one.obj two.obj  
# Comment in commands block  
#   copy *.obj \objects  # Command turned into comment  
    copy one.exe \release  
  
.obj.exe:  # Comment on inference rule line  
    link $<  
  
my.exe : my.obj ; link my.obj  # Err: cannot comment this  
 # Error: # must be the first character  
.obj.exe: ; link $<  # Error: cannot comment this  
```  
  
 Para especificar um sinal numérico literal, coloque um sinal de intercalação \(**^**\), como segue:  
  
```  
DEF = ^#define  #Macro for a C preprocessing directive  
```  
  
## Consulte também  
 [Conteúdo de um makefile](../build/contents-of-a-makefile.md)