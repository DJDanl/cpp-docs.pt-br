---
title: "_bittestandcomplement, _bittestandcomplement64 | Microsoft Docs"
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
  - "_bittestandcomplement64"
  - "_bittestandcomplement64_cpp"
  - "_bittestandcomplement_cpp"
  - "_bittestandcomplement"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_bittestandcomplement intrínseca"
  - "_bittestandcomplement64 intrínseca"
  - "instrução BTC"
ms.assetid: 53fa12dd-835e-4e5d-baec-a431c8678806
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _bittestandcomplement, _bittestandcomplement64
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Gere uma instrução que examina o bit `b` do endereço `a` e retorna seu valor atual e define o bit para seu complemento.  
  
## Sintaxe  
  
```  
unsigned char _bittestandcomplement(    long *a,    long b ); unsigned char _bittestandcomplement64(    __int64 *a,    __int64 b );  
```  
  
#### Parâmetros  
 \[in, out\] `a`  
 Um ponteiro para a memória a examinar.  
  
 \[in\] `b`  
 A posição de bit a testar.  
  
## Valor de retorno  
 O bit na posição especificada.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`_bittestandcomplement`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|`_bittestandcomplement64`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Essa rotina só está disponível como função intrínseca.  
  
## Exemplo  
  
```  
// bittestandcomplement.cpp  
// processor: x86, IPF, x64  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(_bittestandcomplement)  
#ifdef _M_AMD64  
#pragma intrinsic(_bittestandcomplement64)  
#endif  
  
int main()  
{  
   long i = 1;  
   __int64 i64 = 0x1I64;  
   unsigned char result;  
   printf("Initial value: %d\n", i);  
   printf("Testing bit 1\n");  
   result = _bittestandcomplement(&i, 1);  
   printf("Value changed to %d, Result: %d\n", i, result);  
#ifdef _M_AMD64  
   printf("Testing bit 0\n");  
   result = _bittestandcomplement64(&i64, 0);  
   printf("Value changed to %I64d, Result: %d\n", i64, result);  
#endif  
}  
```  
  
## Exemplo de saída  
  
```  
Initial value: 1  
Testing bit 1  
Value changed to 3, Result: 0  
Testing bit 0  
Value changed to 0, Result: 1  
```  
  
### FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)