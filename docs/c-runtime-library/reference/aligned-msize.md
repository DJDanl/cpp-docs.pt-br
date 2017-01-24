---
title: "_aligned_msize | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_aligned_msize"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-heap-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_aligned_msize"
  - "aligned_msize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _aligned_msize"
  - "Função aligned_msize"
ms.assetid: 10995edc-2110-4212-9ca9-5e0220a464f4
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_msize
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o tamanho de um bloco de memória alocado no heap.  
  
## Sintaxe  
  
```  
size_t _msize(  
   void *memblock,  
   size_t alignment,  
   size_t offset  
);  
```  
  
#### Parâmetros  
 \[entrada\] `memblock`  
 Ponteiro para o bloco de memória.  
  
 \[entrada\] `alignment`  
 O valor de alinhamento, que deve ser uma potência de inteiro de 2.  
  
 \[entrada\] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## Valor de retorno  
 Retorna o tamanho \(em bytes\) como um número inteiro sem sinal.  
  
## Comentários  
 A função de `_aligned_msize` retorna o tamanho, em bytes, do bloco de memória alocado por uma chamada a [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou a [\_aligned\_realloc](../../c-runtime-library/reference/aligned-realloc.md).  Os valores de `alignment` e de `offset` devem ser iguais aos valores passados para a função que alocou o bloco.  
  
 Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, `_aligned_msize` resolve a [\_aligned\_msize\_dbg](../../c-runtime-library/reference/aligned-msize-dbg.md).  Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [O heap de depuração do CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 Essa função valida seu parâmetro.  Se `memblock` for um ponteiro nulo ou `alignment` não é uma potência de 2, `_msize` invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se o erro é tratado, a função `errno` define a `EINVAL` e retorna \-1.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_msize`|\<malloc.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)