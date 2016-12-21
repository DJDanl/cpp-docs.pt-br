---
title: "__writegsbyte, __writegsdword, __writegsqword, __writegsword | Microsoft Docs"
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
  - "__writegsbyte"
  - "__writegsqword"
  - "__writegsdword"
  - "__writegsword"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__writegsqword intrínseco"
  - "__writegsbyte intrínseco"
  - "__writegsword intrínseco"
  - "__writegsdword intrínseco"
ms.assetid: 7746cf6d-2259-4139-9aab-c07dd75c8037
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __writegsbyte, __writegsdword, __writegsqword, __writegsword
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Memória de gravação para um local especificado por um deslocamento relativo para o início do segmento GS.  
  
## Sintaxe  
  
```  
void __writegsbyte(   
   unsigned long Offset,   
   unsigned char Data   
);  
void __writegsword(   
   unsigned long Offset,   
   unsigned short Data   
);  
void __writegsdword(   
   unsigned long Offset,   
   unsigned long Data   
);  
void __writegsqword(   
   unsigned long Offset,   
   unsigned __int64 Data   
);  
```  
  
#### Parâmetros  
 \[in\]`Offset`  
 O deslocamento do início do GS para gravar.  
  
 \[in\]`Data`  
 O valor para escrever.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__writegsbyte`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__writegsdword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__writegsqword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`__writegsword`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Esses intrínsecos estão disponíveis somente no modo kernel e essas rotinas estão somente disponíveis como intrínsecos.  
  
## END Microsoft específicos  
  
## Consulte também  
 [\_\_readgsbyte, \_\_readgsdword, \_\_readgsqword, \_\_readgsword](../intrinsics/readgsbyte-readgsdword-readgsqword-readgsword.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)