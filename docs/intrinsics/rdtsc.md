---
title: "__rdtsc | Microsoft Docs"
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
  - "__rdtsc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__rdtsc intrínseco"
  - "instrução RDTSC"
  - "Instrução do contador de carimbo de hora de leitura"
ms.assetid: e31d0e51-c9bb-42ca-bbe9-a81ffe662387
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __rdtsc
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera o `rdtsc` instrução retorna a hora do processador.  O carimbo de hora do processador registra o número de ciclos de relógio desde a última reinicialização.  
  
## Sintaxe  
  
```  
unsigned __int64 __rdtsc();  
```  
  
## Valor de retorno  
 Inteiro não assinado de 64 bits que representa uma contagem em escala.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__rdtsc`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Esta rotina está disponível como um intrínseco.  
  
 A interpretação do valor TSC nessa geração de hardware é diferente do que em versões anteriores do [!INCLUDE[vcprx64](../Token/vcprx64_md.md)].  Consulte os manuais de hardware para obter mais informações.  
  
## Exemplo  
  
```  
// rdtsc.cpp  
// processor: x86, x64  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(__rdtsc)  
  
int main()  
{  
    unsigned __int64 i;  
    i = __rdtsc();  
    printf_s("%I64d ticks\n", i);  
}  
```  
  
  **3363423610155519 escalas**   
## END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)