---
title: "__addgsbyte, __addgsword, __addgsdword, __addgsqword | Microsoft Docs"
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
  - "__addgsdword"
  - "__addgsqword"
  - "__addgsword_cpp"
  - "__addgsword"
  - "__addgsbyte_cpp"
  - "__addgsqword_cpp"
  - "__addgsbyte"
  - "__addgsdword_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__addgsword intrínseco"
  - "__addgsqword intrínseco"
  - "__addgsdword intrínseco"
  - "__addgsbyte intrínseco"
ms.assetid: 4fa03e69-d849-49ed-ba37-1d3aa23c2a21
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __addgsbyte, __addgsword, __addgsdword, __addgsqword
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Adicionar um valor para um local de memória especificado por um deslocamento relativo para o início do `GS` segmento.  
  
## Sintaxe  
  
```  
void __addgsbyte(   
   unsigned long Offset,   
   unsigned char Data   
);  
void __addgsword(   
   unsigned long Offset,   
   unsigned short Data   
);  
void __addgsdword(   
   unsigned long Offset,   
   unsigned long Data   
);  
void __addgsqword(   
   unsigned long Offset,   
   unsigned __int64 Data   
);  
```  
  
#### Parâmetros  
 \[in\]`Offset`  
 O deslocamento do início do `GS`.  
  
 \[in\]`Data`  
 O valor a adicionar o local de memória.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__addgsbyte`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__addgsword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__addgsdword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__addgsqword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
## Comentários  
 Esses intrínsecos estão disponíveis somente no modo kernel e essas rotinas estão somente disponíveis como intrínsecos.  
  
## END Microsoft específicos  
  
## Consulte também  
 [\_\_incgsbyte, \_\_incgsword, \_\_incgsdword, \_\_incgsqword](../intrinsics/incgsbyte-incgsword-incgsdword-incgsqword.md)   
 [\_\_readgsbyte, \_\_readgsdword, \_\_readgsqword, \_\_readgsword](../intrinsics/readgsbyte-readgsdword-readgsqword-readgsword.md)   
 [\_\_writegsbyte, \_\_writegsdword, \_\_writegsqword, \_\_writegsword](../intrinsics/writegsbyte-writegsdword-writegsqword-writegsword.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)