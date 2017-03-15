---
title: "_umul128 | Microsoft Docs"
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
  - "__umul128"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__umul128 intrínseca"
ms.assetid: 13684df3-3ac7-467c-b258-a0e93bc490b5
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _umul128
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Multiplica dois inteiros sem sinal de 64 bits passados como os primeiros dois argumentos e coloca os 64 bits altos do produto no inteiro de 64 bits sem sinal apontado pelo `HighProduct` e retorna os 64 bits baixos do produto.  
  
## Sintaxe  
  
```  
unsigned __int64 _umul128(     unsigned __int64 Multiplier,     unsigned __int64 Multiplicand,     unsigned __int64 *HighProduct  );  
```  
  
#### Parâmetros  
 \[in\] `Multiplier`  
 O primeiro inteiro de 64 bits para multiplicar.  
  
 \[in\] `Multiplicand`  
 O segundo inteiro de 64 bits para multiplicar.  
  
 \[out\] `HighProduct`  
 Os 64 bits altos do produto.  
  
## Valor de retorno  
 Os 64 bits baixos do produto.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`_umul128`|ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
  
## Exemplo  
  
```  
// umul128.c  
// processor: IPF, x64  
  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(_umul128)  
  
int main()  
{  
    unsigned __int64 a = 0x0fffffffffffffffI64;  
    unsigned __int64 b = 0xf0000000I64;  
    unsigned __int64 c, d;  
  
    d = _umul128(a, b, &c);  
  
    printf_s("%#I64x * %#I64x = %#I64x%I64x\n", a, b, c, d);  
}  
```  
  
  **0xfffffffffffffff \* 0xf0000000 \= 0xeffffffffffffff10000000**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)