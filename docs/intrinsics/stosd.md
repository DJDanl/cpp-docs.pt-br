---
title: "__stosd | Microsoft Docs"
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
  - "__stosd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução stosd"
  - "instrução de stosd rep"
  - "__stosd intrínseco"
ms.assetid: 03104247-1cea-49f6-b6f8-287917bf5680
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __stosd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera uma instrução de seqüência de armazenamento \(`rep stosd`\).  
  
## Sintaxe  
  
```  
void __stosd(   
   unsigned long* Dest,   
   unsigned long Data,   
   size_t Count   
);  
```  
  
#### Parâmetros  
 \[out\]`Dest`  
 O destino da operação.  
  
 \[in\]`Data`  
 Os dados para armazenar.  
  
 \[in\]`Count`  
 O comprimento do bloco de doublewords de gravação.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__stosd`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O resultado é que o doubleword `Data` gravados em um bloco de `Count` doublewords na posição de memória apontada por `Dest`.  
  
 Esta rotina só está disponível como um intrínseco.  
  
## Exemplo  
  
```  
// stosd.c  
// processor: x86, x64  
  
#include <stdio.h>  
#include <memory.h>  
#include <intrin.h>  
  
#pragma intrinsic(__stosd)  
  
int main()  
{  
    unsigned long val = 99999;  
    unsigned long a[10];  
  
    memset(a, 0, sizeof(a));  
    __stosd(a+1, val, 2);  
  
printf_s( "%u %u %u %u",  
              a[0], a[1], a[2], a[3]);   
}  
```  
  
  **0 99999 99999 0**   
## END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)