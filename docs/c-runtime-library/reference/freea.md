---
title: "_freea | Microsoft Docs"
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
  - "_freea"
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
apitype: "DLLExport"
f1_keywords: 
  - "freea"
  - "_freea"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _freea"
  - "Função freea"
  - "desalocação de memória"
ms.assetid: dcd30584-dd9d-443b-8c4c-13237a1cecac
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _freea
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Desaloca ou libera um bloco de memória.  
  
## Sintaxe  
  
```  
void _freea(   
   void *memblock   
);  
```  
  
#### Parâmetros  
 `memblock`  
 Bloco de memória alocado anteriormente seja liberado.  
  
## Valor de retorno  
 Nenhum.  
  
## Comentários  
 A função de `_freea` desaloca um bloco de memória \(`memblock`\) que é atribuído anteriormente por uma chamada a [\_malloca](../../c-runtime-library/reference/malloca.md).  `_freea` verifica se a memória foi alocada no heap ou na pilha.  Se foi alocada na pilha, `_freea` não fará nada.  Se foi alocada no heap, o número de bytes liberados equivale ao número de bytes necessários quando o pacote foi atribuído.  Se `memblock` é `NULL`, o ponteiro será ignorado e `_freea` retorna imediatamente.  Tente liberar um ponteiro inválido \(um ponteiro para um bloco de memória que não foi atribuído por `_malloca`\) podem afetar solicitações subsequentes de alocação e causar erros.  
  
 o \_`freea` chama `free` internamente se encontra o que a memória é atribuída no heap.  Se a memória estiver no heap ou na pilha é determinado por um marcador colocado na memória do endereço imediatamente antes da memória alocada.  
  
 Se ocorrer um erro em liberar a memória, `errno` é definido com informações do sistema operacional na natureza da falha.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Depois que um bloco de memória foi liberado, [\_heapmin](../../c-runtime-library/reference/heapmin.md) minimiza a quantidade de memória livre no heap coalescendo as regiões não usado e liberação dos de volta ao sistema operacional.  A memória liberada que não é liberada para o sistema operacional for restaurada para o pool livre e está disponível para alocação novamente.  
  
 Uma chamada para `_freea` deve controlar todas as chamadas a `_malloca`.  Também é um erro para chamar duas vezes `_freea` na mesma memória.  Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, especialmente com recursos de [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md) habilitada definindo `_CRTDBG_MAP_ALLOC`, é mais fácil localizar ausentes ou chamadas duplicados a `_freea`.  Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [O heap de depuração do CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 `_freea` é marcado `__declspec(noalias)`, o que significa que a função não é garantida para modificar as variáveis globais.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_freea`|\<stdlib.h\> e \<malloc.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [\_malloca](../../c-runtime-library/reference/malloca.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [\_malloca](../../c-runtime-library/reference/malloca.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [\_free\_dbg](../../c-runtime-library/reference/free-dbg.md)   
 [\_heapmin](../../c-runtime-library/reference/heapmin.md)