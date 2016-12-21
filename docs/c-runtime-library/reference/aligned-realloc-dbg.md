---
title: "_aligned_realloc_dbg | Microsoft Docs"
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
  - "_aligned_realloc_dbg"
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
  - "aligned_realloc_dbg"
  - "_aligned_realloc_dbg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _aligned_realloc_dbg"
  - "Função aligned_realloc_dbg"
ms.assetid: 8aede920-991e-44cd-867f-83dc2165db47
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_realloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um bloco de memória alocado com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
void * _aligned_realloc_dbg(    void *memblock,     size_t size,     size_t alignment,    const char *filename,    int linenumber  );  
```  
  
#### Parâmetros  
 \[in\] `memblock`  
 O ponteiro do bloco de memória atual.  
  
 \[in\] `size`  
 Tamanho da alocação de memória solicitada.  
  
 \[in\] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 \[in\] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação `realloc` ou NULL.  
  
 \[in\] `linenumber`  
 Número da linha do arquivo de origem em que a operação `realloc` foi solicitada ou NULL.  
  
## Valor de retorno  
 `_aligned_realloc_dbg` retorna um ponteiro nulo para o bloco de memória realocado \(e possivelmente migrado\).  O valor retornado é `NULL` se o tamanho for zero e o argumento do buffer não for `NULL`, ou se não houver memória suficiente para expandir o bloco para o tamanho determinado.  No primeiro caso, o bloco original é liberado.  No segundo caso, ele permanece inalterado.  O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.  
  
 Realocar a memória e alterar o alinhamento de um bloco é um erro.  
  
## Comentários  
 `_aligned_realloc_dbg` é uma versão de depuração da função [\_aligned\_realloc](../../c-runtime-library/reference/aligned-realloc.md).  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, cada chamada a `_aligned_realloc_dbg` é reduzida a uma chamada a \_`aligned_realloc`.  Tanto \_, quanto  realocam um bloco de memória no heap básico, mas  acomoda diversos recursos de depuração: buffers dos dois lados da porção do usuário do bloco para verificar se há perdas, um parâmetro de tipo de bloco para acompanhar tipos específicos de alocação e informações `filename`\/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_aligned_realloc_dbg` realoca o bloco de memória especificado com um pouco mais de espaço que o `newSize` solicitado.  `newSize` pode ser maior ou menor que o espaço do bloco de memória alocado originalmente.  O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers.  A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória.  Se o bloco de memória for movido, o conteúdo do bloco original será substituído.  
  
 `_aligned_realloc_dbg` define `errno` para `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória necessária \(incluindo a sobrecarga mencionada anteriormente\) exceder `_HEAP_MAXREQ`.  Para obter informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Além disso, `_aligned_realloc_dbg` valida seus parâmetros.  Se `alignment` não for um número elevado à segunda potência, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função heap padrão e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_realloc_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)