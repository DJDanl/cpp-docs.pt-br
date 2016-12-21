---
title: "_aligned_free_dbg | Microsoft Docs"
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
  - "_aligned_free_dbg"
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
  - "_aligned_free_dbg"
  - "aligned_free_dbg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _aligned_free_dbg"
  - "Função aligned_free_dbg"
ms.assetid: eb0cb3c8-0992-4db8-bac3-65f1b8311ca6
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_free_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Libera um bloco de memória alocado com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) \(apenas depuração\).  
  
## Sintaxe  
  
```  
void _aligned_free_dbg(    void *memblock );  
```  
  
#### Parâmetros  
 `memblock`  
 Um ponteiro para o bloco de memória que foi retornado para a função `_aligned_malloc` ou `_aligned_offset_malloc`.  
  
## Comentários  
 A função `_aligned_free_dbg`  é uma versão de depuração da função [\_aligned\_free](../../c-runtime-library/reference/aligned-free.md).  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, cada chamada a `_aligned_free_dbg` é reduzida a uma chamada a \_`aligned_free`.  O \_`aligned_free` e o `_aligned_free_dbg` liberam um bloco de memória no heap de base, mas o `_aligned_free_dbg`  acomoda um recurso de depuração: a habilidade de manter blocos liberados na lista vinculada do heap para simular condições de baixa memória.  
  
 O `_aligned_free_dbg` realiza uma verificação de validade em todos os arquivos e locais de bloco especificados antes de realizar a ação de liberação.  O aplicativo não deve fornecer essas informações.  Ao liberar um bloco de memória, o gerenciador de heap de depuração verifica automaticamente a integridade dos buffers nos dois lados da parte do usuário e emite um relatório de erro se tiver ocorrido substituição.  Se o campo de bit `_CRTDBG_DELAY_FREE_MEM_DF`  do sinalizador [\_crtDbgFlag](../Topic/_crtDbgFlag.md) estiver definido, o bloco liberado é preenchido com o valor 0xDD, atribuído ao tipo de bloco `_FREE_BLOCK` e mantido na lista de blocos de memória vinculada do heap.  
  
 Se ocorrer um erro ao liberar a memória, o `errno` é definido com informações do sistema operacional sobre a natureza da falha.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função heap padrão e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_free_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)