---
title: "_aligned_offset_malloc_dbg | Microsoft Docs"
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
  - "_aligned_offset_malloc_dbg"
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
  - "_aligned_offset_malloc_dbg"
  - "aligned_offset_malloc_dbg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _aligned_offset_malloc_dbg"
  - "Função aligned_offset_malloc_dbg"
ms.assetid: 6c242307-c59e-4d63-aae5-d8cbec8e021c
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _aligned_offset_malloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Aloca memória em um limite de alinhamento especificado \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
void * _aligned_offset_malloc_dbg(  
   size_t size,   
   size_t alignment,   
   size_t offset,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### Parâmetros  
 \[entrada\] `size`  
 O tamanho da alocação de memória solicitada.  
  
 \[entrada\] `alignment`  
 O valor de alinhamento, que deve ser uma potência de inteiro de 2.  
  
 \[entrada\] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
 \[entrada\] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação ou NULL de alocação.  
  
 \[entrada\] `linenumber`  
 Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou NULL.  
  
## Valor de retorno  
 Um ponteiro para o bloco de memória que foi atribuído a `NULL` ou se houve falha na operação.  
  
## Comentários  
 `_aligned_offset_malloc_dbg` é uma versão de depuração da função de [\_aligned\_offset\_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) .  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, cada chamada a `_aligned_offset_malloc_dbg` será reduzido para uma chamada a `_aligned_offset_malloc`.  `_aligned_offset_malloc` e `_aligned_offset_malloc_dbg` atribuem um bloco de memória heap de base, mas ofertas de `_aligned_offset_malloc_dbg` vários recursos de depuração: buffers em ambos os lados da parte do usuário do bloco para testar que ignora, um parâmetro em blocos para controlar tipos específicos de alocação, e `filename`\/informações de`linenumber` determina a origem de solicitações de alocação.  
  
 `_aligned_offset_malloc_dbg` atribui o bloco de memória com um pouco mais espaço do que `size`solicitado.  O espaço adicional é usado pelo gerenciador de heap de depuração para vincular os blocos de memória de depuração e fornecer o aplicativo com informações de cabeçalho de depuração e para substituir os buffers.  Quando o pacote é atribuído, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers substituir for preenchido com 0xFD.  
  
 `_aligned_offset_malloc_dbg` é útil em situações em que o alinhamento será necessário em um elemento aninhado; por exemplo, se o alinhamento foi necessário em uma classe aninhada.  
  
 `_aligned_offset_malloc_dbg` é baseado em `malloc`; para obter mais informações, consulte [malloc](../../c-runtime-library/reference/malloc.md).  
  
 Esta função define `errno` a `ENOMEM` se a alocação de memória falhou ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`.  Para obter mais informações sobre `errno`, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  Além disso, `_aligned_offset_malloc` valida seus parâmetros.  Se `alignment` não é uma potência de 2 ou se `offset` é maior ou igual a `size` e diferente de zero, essa função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 Para obter informações sobre o bloco de alocação digitar e como elas são usadas, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_aligned_offset_malloc_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)