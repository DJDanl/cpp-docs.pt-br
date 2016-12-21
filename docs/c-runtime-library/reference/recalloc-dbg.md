---
title: "_recalloc_dbg | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_recalloc_dbg"
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
  - "recalloc_dbg"
  - "_recalloc_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _recalloc_dbg"
  - "Função recalloc_dbg"
ms.assetid: 43c3e9b2-be6d-4508-9b0f-3220c8a47ca3
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _recalloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Realoca uma matriz e inicializa seus elementos como 0 \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
void *_recalloc_dbg(     void *userData,    size_t num,    size_t size,    int blockType,    const char *filename,    int linenumber  );  
```  
  
#### Parâmetros  
 `userData`  
 Ponteiro para o bloco de memória alocado anteriormente.  
  
 `num`  
 Número necessário de blocos de memória.  
  
 `size`  
 Tamanho necessário de cada bloco de memória \(bytes\).  
  
 `blockType`  
 Tipo de bloco de memória solicitado:  `_CLIENT_BLOCK`ou `_NORMAL_BLOCK`.  
  
 Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
 Os parâmetros `filename` e `linenumber` estão disponíveis apenas quando `_recalloc_dbg` for chamado explicitamente ou a constante do pré\-processador [\_CRTDBG\_MAP\_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) for definida.  
  
## Valor de retorno  
 Após a conclusão bem\-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória realocado, chama a nova função do manipulador ou retorna NULL.  Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir.  Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [\_recalloc](../../c-runtime-library/reference/recalloc.md).  
  
## Comentários  
 `_recalloc_dbg` é uma versão de depuração da função [\_recalloc](../../c-runtime-library/reference/recalloc.md).  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, cada chamada a `_recalloc_dbg` é reduzida a uma chamada para `_recalloc`.  `_recalloc` e `_recalloc_dbg` realocam um bloco de memória no heap de base, mas `_recalloc_dbg` acomoda diversos recursos de depuração: buffers em cada um dos lados da parte do usuário do bloco para testar vazamentos, um parâmetro de tipo de bloco para controlar tipos de alocação específicos e informações de `filename`\/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_recalloc_dbg` realoca o bloco de memória especificado com um pouco mais espaço do que o tamanho solicitado \(`num` \* `size`\), o que pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente.  O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers.  A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória.  A parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição são preenchidos com 0xFD.  
  
 `_recalloc_dbg` define `errno` como `ENOMEM` se uma alocação de memória falhar; `EINVAL` é retornado se uma quantia de memória necessária \(incluindo a sobrecarga mencionada anteriormente\) exceder `_HEAP_MAXREQ`.  Para obter informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre as diferenças entre chamar uma função heap padrão e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_recalloc_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)