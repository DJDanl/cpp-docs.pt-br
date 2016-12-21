---
title: "__incgsbyte, __incgsword, __incgsdword, __incgsqword | Microsoft Docs"
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
  - "__incgsdword"
  - "__incgsqword_cpp"
  - "__incgsword_cpp"
  - "__incgsword"
  - "__incgsbyte"
  - "__incgsbyte_cpp"
  - "__incgsqword"
  - "__incgsdword_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__incgsbyte intrínseco"
  - "__incgsword intrínseco"
  - "__incgsqword intrínseco"
  - "__incgsdword intrínseco"
ms.assetid: 06bfdf4f-7643-4fe0-8455-60ce3068073e
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __incgsbyte, __incgsword, __incgsdword, __incgsqword
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Adicionar um ao valor em um local de memória especificado por um deslocamento relativo para o início do `GS` segmento.  
  
## Sintaxe  
  
```  
void __incgsbyte(   
   unsigned long Offset   
);  
void __incgsword(   
   unsigned long Offset   
);  
void __incgsdword(   
   unsigned long Offset  
);  
void __incgsqword(   
   unsigned long Offset   
);  
```  
  
#### Parâmetros  
 \[in\]`Offset`  
 O deslocamento do início do `GS`.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__incgsbyte`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__incgsword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__incgsdword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__incgsqword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
## Comentários  
 Esses intrínsecos só estão disponíveis no modo kernel e as rotinas estão somente disponíveis como intrínsecos.  
  
## END Microsoft específicos  
  
## Consulte também  
 [\_\_addgsbyte, \_\_addgsword, \_\_addgsdword, \_\_addgsqword](../intrinsics/addgsbyte-addgsword-addgsdword-addgsqword.md)   
 [\_\_readgsbyte, \_\_readgsdword, \_\_readgsqword, \_\_readgsword](../intrinsics/readgsbyte-readgsdword-readgsqword-readgsword.md)   
 [\_\_writegsbyte, \_\_writegsdword, \_\_writegsqword, \_\_writegsword](../intrinsics/writegsbyte-writegsdword-writegsqword-writegsword.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)