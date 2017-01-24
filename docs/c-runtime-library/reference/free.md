---
title: "free | Microsoft Docs"
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
  - "free"
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
  - "free"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "blocos de memória, desalocando"
  - "Função free"
ms.assetid: 74ded9cf-1863-432e-9306-327a42080bb8
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# free
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Desaloca ou libera um bloco de memória.  
  
## Sintaxe  
  
```  
void free(   
   void *memblock   
);  
```  
  
#### Parâmetros  
 `memblock`  
 Bloco de memória alocado anteriormente seja liberado.  
  
## Comentários  
 A função de `free` desaloca um bloco de memória \(`memblock`\) que é atribuído anteriormente por uma chamada a `calloc`, a `malloc`, ou a `realloc`.  O número de bytes liberados equivale ao número de bytes necessários quando o pacote foi atribuído \(ou realocado, no caso de `realloc`\).  Se `memblock` é `NULL`, o ponteiro será ignorado e `free` retorna imediatamente.  Tente liberar um ponteiro inválido \(um ponteiro para um bloco de memória que não é atribuído por `calloc`, a `malloc`, ou a `realloc`\) pode afetar solicitações subsequentes de alocação e causar erros.  
  
 Se ocorrer um erro em liberar a memória, `errno` é definido com informações do sistema operacional na natureza da falha.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Depois que um bloco de memória foi liberado, [\_heapmin](../../c-runtime-library/reference/heapmin.md) minimiza a quantidade de memória livre no heap coalescendo as regiões não usado e liberação dos de volta ao sistema operacional.  A memória liberada que não é liberada para o sistema operacional for restaurada para o pool livre e está disponível para alocação novamente.  
  
 Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, `free` resolve a [\_free\_dbg](../../c-runtime-library/reference/free-dbg.md).  Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [O heap de depuração do CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 `free` é marcado `__declspec(noalias)`, o que significa que a função não é garantida para modificar as variáveis globais.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md).  
  
 Para liberar a memória alocada com [\_malloca](../../c-runtime-library/reference/malloca.md), use [\_freea](../../c-runtime-library/reference/freea.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`free`|\<stdlib.h\> e \<malloc.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [malloc](../../c-runtime-library/reference/malloc.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [\_alloca](../../c-runtime-library/reference/alloca.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [\_free\_dbg](../../c-runtime-library/reference/free-dbg.md)   
 [\_heapmin](../../c-runtime-library/reference/heapmin.md)   
 [\_freea](../../c-runtime-library/reference/freea.md)