---
title: "_aligned_recalloc_dbg | Microsoft Docs"
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
  - "_aligned_recalloc_dbg"
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
  - "_aligned_recalloc_dbg"
  - "aligned_recalloc_dbg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _aligned_recalloc_dbg"
  - "Função aligned_recalloc_dbg"
ms.assetid: 55c3c27e-561c-4d6b-9bf9-1e34cc556e4b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_recalloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um bloco de memória alocado com [\_aligned\_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) e inicializa a memória como 0 \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
void * _aligned_recalloc_dbg(  
   void * memblock,   
   size_t num,  
   size_t size,   
   size_t alignment,  
   const char *filename,  
   int linenumber  
);  
```  
  
#### Parâmetros  
 \[in\] `memblock`  
 O ponteiro do bloco de memória atual.  
  
 \[in\] `num`  
 O número de elementos.  
  
 \[in\] `size`  
 O tamanho, em bytes, de cada elemento.  
  
 \[in\] `alignment`  
 O valor do alinhamento, que deve ser um número inteiro de potência de dois.  
  
 \[in\] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 \[in\] `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
## Valor de retorno  
 `_aligned_recalloc_dbg` retorna um ponteiro nulo para o bloco de memória realocado \(e possivelmente migrado\).  O valor retornado é `NULL` se o tamanho for zero e o argumento do buffer não for `NULL`, ou se não houver memória suficiente para expandir o bloco para o tamanho determinado.  No primeiro caso, o bloco original é liberado.  No segundo caso, ele permanece inalterado.  O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo que não seja nulo, digite a conversão no valor retornado.  
  
 Realocar a memória e alterar o alinhamento de um bloco é um erro.  
  
## Comentários  
 `_aligned_recalloc_dbg` é uma versão de depuração de [\_aligned\_recalloc](../../c-runtime-library/reference/aligned-recalloc.md) função.  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, cada chamada a `_aligned_recalloc_dbg` é reduzida a uma chamada para `_aligned_recalloc`.  `_aligned_recalloc` e `_aligned_recalloc_dbg` realocam um bloco de memória no heap de base, mas `_aligned_recalloc_dbg` acomoda diversos recursos de depuração: buffers em cada um dos lados da parte do usuário do bloco para testar vazamentos, um parâmetro de tipo de bloco para controlar tipos de alocação específicos e informações de `filename`\/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_aligned_recalloc_dbg` Realoca o bloco de memória especificado com um pouco mais espaço do que o tamanho solicitado \(`num` \* `size`\) que pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente.  O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers.  A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória.  A parte do usuário do bloco é preenchida com o valor 0xCD e os buffers de substituição são preenchidos com 0xFD.  
  
 `_aligned_recalloc_dbg` define `errno` para `ENOMEM` se uma alocação de memória falhar; `EINVAL` será retornado se a quantidade de memória necessária \(incluindo a sobrecarga mencionada anteriormente\) excede `_HEAP_MAXREQ`.  Para obter informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Além disso,  valida seus parâmetros.  Se `alignment` não for uma potência de 2, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre como blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre os tipos de bloco de alocação e como elas são usadas, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função heap padrão e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_recalloc_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)