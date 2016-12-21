---
title: "__rdtscp | Microsoft Docs"
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
  - "__rdtscp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "rdtscp intrínseco"
  - "__rdtscp intrínseco"
  - "instrução rdtscp"
ms.assetid: f17d9a9c-88bb-44e0-b69d-d516bc1c93ee
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __rdtscp
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera o `rdtscp` gravações de instrução, `TSC_AUX[31:0`\] a memória e retorna o contador de carimbo de tempo de 64 bits \(`TSC)` resultado.  
  
## Sintaxe  
  
```  
unsigned __int64 __rdtscp(  
   unsigned int * Aux  
);  
```  
  
#### Parâmetros  
 \[out\]`Aux`  
 Ponteiro para um local que irá conter o conteúdo do registro específicas da máquina de `TSC_AUX[31:0]`.  
  
## Valor de retorno  
 Contagem de tiques uma inteiro não assinado de 64 bits.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__rdtscp`|Família de NPT AMD 0Fh ou versões posteriores|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Nesse intrínsecas gera o `rdtscp` instrução.  Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseca com `InfoType=0x80000001` e verificar o bit 27 de `CPUInfo[3] (EDX)`.  Este bit é 1 se houver suporte para a instrução e 0 caso contrário.  Se você executa código que usa intrínseca neste hardware não oferece suporte a `rdtscp` as instruções, os resultados são imprevisíveis.  
  
> [!CAUTION]
>  Ao contrário de `rdtsc`, `rdtscp` é uma instrução de serialização; No entanto, o compilador pode mover o código ao redor isso intrínseca.  
  
 A interpretação do valor TSC nessa geração de hardware é diferente do que em versões anteriores do [!INCLUDE[vcprx64](../Token/vcprx64_md.md)].  Consulte os manuais de hardware para obter mais informações.  
  
 O significado do valor em `TSC_AUX[31:0]` depende do sistema operacional.  
  
## Exemplo  
  
```  
#include <intrin.h>   
#include <stdio.h>  
int main()   
{  
 unsigned __int64 i;  
 unsigned int ui;  
 i = __rdtscp(&ui);  
 printf_s("%I64d ticks\n", i);  
 printf_s("TSC_AUX was %x\n", ui);  
}  
```  
  
  **3363423610155519 escalas era 0**   
## END Microsoft específicos  
 Copyright 2007 pela Advanced Micro dispositivos, Inc. todos os direitos reservados.  Reproduzido com permissão do Advanced Micro dispositivos, Inc.  
  
## Consulte também  
 [\_\_rdtsc](../intrinsics/rdtsc.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)