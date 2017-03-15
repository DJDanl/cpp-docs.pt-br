---
title: "Palavras reservadas | Microsoft Docs"
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
  - "code"
  - "CONFORMING"
  - "DISCARDABLE"
  - "Description"
  - "base"
  - "APPLOADER"
  - "Data"
  - "DYNAMIC"
  - "DEV386"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .def [C++], palavras reservadas"
  - "arquivos def [C++], palavras reservadas"
  - "vinculador [C++], palavras reservadas"
  - "palavras reservadas [C++]"
ms.assetid: 9b9f49e5-0739-45ab-a37e-81e3915ceb25
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Palavras reservadas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As seguintes são palavras reservadas pelo vinculador.  Esses nomes podem ser usados como argumentos em [instruções de definição o](../Topic/Module-Definition%20\(.Def\)%20Files.md) somente se o nome for incluído entre aspas duplas \(""\).  
  
||||  
|-|-|-|  
|**APPLOADER**1|**INITINSTANCE**2|**PRÉ\-CARREGAMENTO**|  
|**BASE**|**IOPL**|**PRIVADO**|  
|**CÓDIGO**|**BIBLIOTECA**1|**PROTMODE**2|  
|**CONFORMAÇÃO**|**LOADONCALL**1|**PURE**1|  
|**DATABASE**|**LONGNAMES**2|**READONLY**|  
|**DESCRIÇÃO**|`MOVABLE`1|**READWRITE**|  
|**DEV386**|**MOVEABLE**1|**REALMODE**1|  
|**DISCARDABLE**|**MÚLTIPLO**|**RESIDENTE**|  
|**DYNAMIC**|**Nome**|**RESIDENTNAME**1|  
|**EXECUTE\-ONLY**|**NEWFILES**2|**SECTIONS**|  
|**EXECUTEONLY**|`NODATA`1|**SEGMENTOS**|  
|**EXECUTEREAD**|**NOIOPL**1|**COMPARTILHADO**|  
|**EXETYPE**|**NONAME**|**ÚNICO**|  
|**EXPORTAÇÕES**|**NONCONFORMING**1|**STACKSIZE**|  
|**FIXED**1|**NONDISCARDABLE**|**STUB**|  
|**FUNÇÕES**2|**NONE**|**VERSION**|  
|**HEAPSIZE**|**NONSHARED**|**WINDOWAPI**|  
|**IMPORTAÇÕES**|**NOTWINDOWCOMPAT**1|**WINDOWCOMPAT**|  
|**IMPURE**1|**OBJECTS**|**WINDOWS**|  
|**INCLUDE**2|**OLD**1||  
  
 1 O vinculador emite um aviso \(“”\) ignorado quando encontrar esse termo.  No entanto, as palavras reservadas são ainda.  
  
 2 O vinculador ignora essas palavras mas não emitem se nenhum aviso.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)