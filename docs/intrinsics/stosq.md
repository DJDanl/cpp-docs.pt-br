---
title: "__stosq | Microsoft Docs"
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
  - "__stosq"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução de stosq rep"
  - "instrução stosq"
  - "__stosq intrínseco"
ms.assetid: 3ea28297-4369-4c2d-bf0c-91fa539ce209
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __stosq
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera uma instrução de seqüência de armazenamento \(`rep stosq`\).  
  
## Sintaxe  
  
```  
void __stosb(   
   unsigned __int64* Dest,   
   unsigned __int64 Data,   
   size_t Count   
);  
```  
  
#### Parâmetros  
 \[out\]`Dest`  
 O destino da operação.  
  
 \[in\]`Data`  
 Os dados para armazenar.  
  
 \[in\]`Count`  
 O comprimento do bloco de quadwords de gravação.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__stosq`|AMD64|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O resultado é que o quadword `Data` gravados em um bloco de `Count` quadwords na `Dest` seqüência de caracteres.  
  
 Esta rotina só está disponível como um intrínseco.  
  
## Exemplo  
  
```  
// stosq.c  
// processor: x64  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(__stosq)  
  
int main()  
{  
   unsigned __int64 val = 0xFFFFFFFFFFFFI64;  
   unsigned __int64 a[10];  
   memset(a, 0, sizeof(a));  
   __stosq(a+1, val, 2);  
   printf("%I64x %I64x %I64x %I64x", a[0], a[1], a[2], a[3]);   
}  
```  
  
## Saída  
  
```  
0 ffffffffffff ffffffffffff 0  
```  
  
### END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)