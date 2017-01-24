---
title: "_aligned_offset_recalloc_dbg | Microsoft Docs"
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
  - "_aligned_offset_recalloc_dbg"
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
  - "aligned_offset_recalloc_dbg"
  - "_aligned_offset_recalloc_dbg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _aligned_offset_recalloc_dbg"
  - "Função aligned_offset_recalloc_dbg"
ms.assetid: 7ab719c3-77e0-4d2e-934f-01529d062fbf
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_offset_recalloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um bloco de memória alocado com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
void * _aligned_offset_recalloc_dbg(    void *memblock,     size_t num,     size_t size,     size_t alignment,    size_t offset,    const char *filename,    int linenumber );  
```  
  
#### Parâmetros  
 \[in\] `memblock`  
 O ponteiro do bloco de memória atual.  
  
 \[in\] `num`  
 Número de elementos.  
  
 \[in\] `size`  
 O comprimento, em bytes, de cada elemento.  
  
 \[in\] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 \[in\] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
 \[in\] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação `realloc` ou NULL.  
  
 \[in\] `linenumber`  
 Número da linha do arquivo de origem em que a operação `realloc` foi solicitada ou NULL.  
  
## Valor de retorno  
 `_aligned_offset_recalloc_dbg` retorna um ponteiro nulo para o bloco de memória realocado \(e possivelmente migrado\).  O valor retornado é `NULL` se o tamanho for zero e o argumento do buffer não for `NULL`, ou se não houver memória suficiente para expandir o bloco para o tamanho determinado.  No primeiro caso, o bloco original é liberado.  No segundo caso, ele permanece inalterado.  O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.  
  
## Comentários  
 `_aligned_offset_realloc_dbg` é uma versão de depuração da função [\_aligned\_offset\_recalloc](../../c-runtime-library/reference/aligned-offset-recalloc.md).  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, cada chamada a `_aligned_offset_recalloc_dbg` é reduzida a uma chamada a \_`aligned_offset_recalloc`.  Tanto \_`aligned_offset_recalloc`, quanto `_aligned_offset_recalloc_dbg` realocam um bloco de memória no heap básico, mas `_aligned_offset_recalloc_dbg` acomoda diversos recursos de depuração: buffers dos dois lados da porção do usuário do bloco para verificar se há perdas, um parâmetro de tipo de bloco para acompanhar tipos específicos de alocação e informações `filename`\/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_aligned_offset_realloc_dbg` realoca o bloco de memória especificado com um pouco mais de espaço que o `newSize` solicitado.  `newSize` pode ser maior ou menor que o espaço do bloco de memória alocado originalmente.  O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers.  A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória.  Se o bloco de memória for movido, o conteúdo do bloco original será substituído.  
  
 Essa função define `errno` como `ENOMEM` se a alocação da memória tiver falhado ou se o tamanho solicitado \(`num` \* `size`\) for maior que `_HEAP_MAXREQ`.  Para obter mais informações sobre `errno`, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  Além disso, `_aligned_offset_recalloc_dbg` valida seus parâmetros.  Se `alignment` não for um número elevado à segunda potência ou se `offset` for maior ou igual ao tamanho solicitado e diferente de zero, essa função invoca o indicador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função heap padrão e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_offset_recalloc_dbg`|\<malloc.h\>|  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)