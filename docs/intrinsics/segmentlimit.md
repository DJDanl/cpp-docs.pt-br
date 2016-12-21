---
title: "__segmentlimit | Microsoft Docs"
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
  - "__segmentlimit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__segmentlimit intrínseco"
  - "instrução LSL"
ms.assetid: d0bc3630-90cb-4185-8667-686fd41e23d4
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __segmentlimit
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera o `lsl` instrução \(limite do segmento de carga\).  
  
## Sintaxe  
  
```  
unsigned long __segmentlimit(   
   unsigned long a   
);  
```  
  
#### Parâmetros  
 \[in\]`a`  
 Uma constante que especifica o seletor de segmento.  
  
## Valor de retorno  
 O limite do segmento do seletor de segmento especificado por `a,` desde que o seletor é válido e visível no nível de permissão atual.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__segmentlimit`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Se o limite de segmento não pode ser recuperado, essa instrução falhará.  Em caso de falha, esta instrução limpa o sinalizador ZF e o valor de retorno é indefinido.  
  
 Esta rotina só está disponível como um intrínseco.  
  
## Exemplo  
  
```  
#include <stdio.h>  
  
#ifdef _M_IX86  
typedef unsigned int READETYPE;  
#else  
typedef unsigned __int64 READETYPE;  
#endif  
  
#define EFLAGS_ZF      0x00000040  
#define KGDT_R3_DATA    0x0020  
#define RPL_MASK        0x3  
  
extern "C"  
{  
unsigned long __segmentlimit (unsigned long);  
READETYPE __readeflags();  
}  
  
#pragma intrinsic(__readeflags)  
#pragma intrinsic(__segmentlimit)  
  
int main(void)  
{  
   const unsigned long initsl = 0xbaadbabe;  
   READETYPE eflags = 0;  
   unsigned long sl = initsl;  
  
   printf("Before: segment limit =0x%x eflags =0x%x\n", sl, eflags);  
   sl = __segmentlimit(KGDT_R3_DATA + RPL_MASK);  
  
   eflags = __readeflags();  
  
   printf("After: segment limit =0x%x eflags =0x%x eflags.zf = %s\n", sl, eflags, (eflags & EFLAGS_ZF) ? "set" : "clear");  
  
   // If ZF is set, the call to lsl succeeded; if ZF is clear, the call failed.  
   printf("%s\n", eflags & EFLAGS_ZF ? "Success!": "Fail!");  
  
   // You can verify the value of sl to make sure that the instruction wrote to it  
   printf("sl was %s\n", (sl == initsl) ? "unchanged" : "changed");  
  
   return 0;  
}  
```  
  
  **Antes: limite de segmento \= eflags 0xbaadbabe \= 0x0 após: limite de segmento \= 0xffffffff eflags \= 0x256 eflags.zf \= definir sucesso\!**  
 **SL foi alterado**   
## END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)