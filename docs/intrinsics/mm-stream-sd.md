---
title: "_mm_stream_sd | Microsoft Docs"
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
  - "_mm_stream_sd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_mm_stream_sd intrínseco"
  - "instrução movntsd"
ms.assetid: 2b4bea5e-e64e-45fa-9afc-88a2e4b82cfc
caps.latest.revision: 14
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mm_stream_sd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Grava dados de 64 bits para um local de memória sem polua os caches.  
  
## Sintaxe  
  
```  
void _mm_stream_sd(  
   double * Dest,  
   __m128d Source  
);  
```  
  
#### Parâmetros  
 \[out\]`Dest`  
 Um ponteiro para o local onde serão gravados os dados de origem.  
  
 \[in\]`Source`  
 Um valor de 128 bits que contém o `double` valor a ser gravado em sua parte inferior de 64 bits..  
  
## Valor de retorno  
 Nenhum.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`_mm_stream_sd`|SSE4a|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Nesse intrínsecas gera o `movntsd` instrução.  Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseca com `InfoType=0x80000001` e verificar o bit 6 do `CPUInfo[2] (ECX)`.  Esse bit será 1 se o hardware suporta esta instrução e 0 caso contrário.  
  
 Se você executar o código que usa o `_mm_stream_sd` intrínseca em hardware não oferece suporte a `movntsd` instruções, os resultados são imprevisíveis.  
  
## Exemplo  
  
```  
// Compile this sample with: /EHsc  
#include <iostream>  
#include <intrin.h>  
using namespace std;  
  
int main()  
{  
    __m128d vals;  
    double d[2];  
  
    d[0] = -1.;  
    d[1] = -2.;  
    vals.m128d_f64[0] = 0.;  
    vals.m128d_f64[1] = 1.;  
    _mm_stream_sd(&d[1], vals);  
    cout << "d[0] = " << d[0] << ", d[1] = " << d[1] << endl;  
}  
  
```  
  
  **\[0\] d \= \-1, d \[1\] \= 1**   
## END Microsoft específicos  
 Copyright 2007 pela Advanced Micro dispositivos, Inc. todos os direitos reservados.  Reproduzido com permissão do Advanced Micro dispositivos, Inc.  
  
## Consulte também  
 [\_mm\_stream\_ss](../Topic/_mm_stream_ss.md)   
 [\_mm\_store\_sd](http://msdn.microsoft.com/pt-br/8e672d0d-0a96-45b9-a783-392a2457de42)   
 [\_mm\_sfence](http://msdn.microsoft.com/pt-br/b6c0d18e-3628-4318-826b-45f66782e870)   
 [Streaming SIMD Extensions that Support the Cache](http://msdn.microsoft.com/pt-br/8f03493a-d5f5-4457-892e-0b6540494872)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)