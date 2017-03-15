---
title: "__readgsbyte, __readgsdword, __readgsqword, __readgsword | Microsoft Docs"
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
  - "__readgsbyte"
  - "__readgsdword"
  - "__readgsqword"
  - "__readgsword"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__readgsword intrínseco"
  - "__readgsdword intrínseco"
  - "__readgsqword intrínseco"
  - "__readgsbyte intrínseco"
ms.assetid: f822632d-854c-4558-a71b-cdfc3eea2236
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __readgsbyte, __readgsdword, __readgsqword, __readgsword
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Ler a memória de um local especificado por um deslocamento relativo para o início do segmento GS.  
  
## Sintaxe  
  
```  
unsigned char __readgsbyte(   
   unsigned long Offset   
);  
unsigned short __readgsword(   
   unsigned long Offset   
);  
unsigned long __readgsdword(   
   unsigned long Offset  
);  
unsigned __int64 __readgsqword(   
   unsigned long Offset   
);  
```  
  
#### Parâmetros  
 \[in\]`Offset`  
 O deslocamento do início do `GS` ler.  
  
## Valor de retorno  
 O conteúdo da memória do byte, word, palavra dupla ou quadword \(conforme indicado pelo nome da função de chamada\) no local `GS:[``Offset``]`.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__readgsbyte`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__readgsdword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__readgsqword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__readgsword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Esses intrínsecos só estão disponíveis no modo kernel e as rotinas estão somente disponíveis como intrínsecos.  
  
## END Microsoft específicos  
  
## Consulte também  
 [\_\_writegsbyte, \_\_writegsdword, \_\_writegsqword, \_\_writegsword](../intrinsics/writegsbyte-writegsdword-writegsqword-writegsword.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)