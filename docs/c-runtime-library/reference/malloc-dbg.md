---
title: "_malloc_dbg | Microsoft Docs"
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
  - "_malloc_dbg"
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
  - "malloc_dbg"
  - "_malloc_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _malloc_dbg"
  - "Função malloc_dbg"
  - "alocação de memória"
ms.assetid: c97eca51-140b-4461-8bd2-28965b49ecdb
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _malloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Aloca um bloco de memória no heap com espaço adicional para um cabeçalho de depuração e buffers de substituição \(apenas versão de depuração\).  
  
## Sintaxe  
  
```  
void *_malloc_dbg(    size_t size,    int blockType,    const char *filename,    int linenumber  );  
```  
  
#### Parâmetros  
 `size`  
 Tamanho solicitado do bloco de memória \(em bytes\).  
  
 `blockType`  
 Tipo de bloco de memória solicitado: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou NULL.  
  
 `linenumber`  
 Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou NULL.  
  
 Os parâmetros `filename` e `linenumber` estão disponíveis apenas quando `_malloc_dbg` for chamado explicitamente ou a constante do pré\-processador [\_CRTDBG\_MAP\_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) for definida.  
  
## Valor de retorno  
 Mediante a conclusão bem\-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória alocado, chama a nova função do manipulador ou retorna NULL.  Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir.  Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [malloc](../../c-runtime-library/reference/malloc.md).  
  
## Comentários  
 `_malloc_dbg` é uma versão de depuração da função [malloc](../../c-runtime-library/reference/malloc.md).  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, cada chamada a `_malloc_dbg` é reduzida a uma chamada para `malloc`.  O `malloc` e o `_malloc_dbg` alocam um bloco de memória no heap de base, mas o `_malloc_dbg` oferece vários recursos de depuração: buffers em qualquer um dos lados da parte do usuário do bloco para testar se há vazamentos, um parâmetro do tipo bloco para rastrear tipos de alocação específicos e informações de `filename`\/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_malloc_dbg` aloca o bloco de memória com um pouco mais de espaço que o `size` solicitado.  O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers.  Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.  
  
 `_malloc_dbg` define `errno` para `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória necessária \(incluindo a sobrecarga mencionada anteriormente\) exceder `_HEAP_MAXREQ`.  Para obter informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função heap padrão e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_malloc_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 Para obter uma amostra de como usar `_malloc_dbg`, consulte [crt\_dbg1](http://msdn.microsoft.com/pt-br/17b4b20c-e849-48f5-8eb5-dca6509cbaf9).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [\_calloc\_dbg](../../c-runtime-library/reference/calloc-dbg.md)   
 [\_calloc\_dbg](../../c-runtime-library/reference/calloc-dbg.md)