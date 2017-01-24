---
title: "__readfsbyte, __readfsdword, __readfsqword, __readfsword | Microsoft Docs"
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
  - "__readfsword"
  - "__readfsdword"
  - "__readfsbyte"
  - "__readfsqword"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__readfsword intrínseco"
  - "readfsword intrínseco"
  - "__readfsdword intrínseco"
  - "readfsbyte intrínseco"
  - "__readfsbyte intrínseco"
  - "readfsdword intrínseco"
  - "readfsqword intrínseco"
  - "__readfsqword intrínseco"
ms.assetid: f6ee7203-4179-402c-a464-0746c84ce6ac
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __readfsbyte, __readfsdword, __readfsqword, __readfsword
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Ler a memória de um local especificado por um deslocamento relativo para o início do segmento FS.  
  
## Sintaxe  
  
```  
unsigned char __readfsbyte(   
   unsigned long Offset   
);  
unsigned short __readfsword(   
   unsigned long Offset   
);  
unsigned long __readfsdword(   
   unsigned long Offset  
);  
unsigned __int64 __readfsqword(   
   unsigned long Offset   
);  
```  
  
#### Parâmetros  
 \[in\]`Offset`  
 O deslocamento do início do `FS` ler.  
  
## Valor de retorno  
 O conteúdo da memória do byte, palavra, doubleword ou quadword \(conforme indicado pelo nome da função de chamada\) no local `FS:[``Offset``]`.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__readfsbyte`|x86|  
|`__readfsdword`|x86|  
|`__readfsqword`|x86|  
|`__readfsword`|x86|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Essas rotinas estão disponíveis apenas como intrínsecos.  
  
## END Microsoft específicos  
  
## Consulte também  
 [\_\_writefsbyte, \_\_writefsdword, \_\_writefsqword, \_\_writefsword](../intrinsics/writefsbyte-writefsdword-writefsqword-writefsword.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)