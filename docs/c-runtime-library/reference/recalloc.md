---
title: "_recalloc | Microsoft Docs"
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
  - "_recalloc"
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
  - "_recalloc"
  - "recalloc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _recalloc"
  - "Função recalloc"
ms.assetid: 1db8305a-3f03-418c-8844-bf9149f63046
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _recalloc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma combinação de `realloc` e de `calloc`.  Realoca uma matriz na memória e inicializa os elementos como 0.  
  
## Sintaxe  
  
```  
void *_recalloc(   
   void *memblock  
   size_t num,  
   size_t size   
);  
```  
  
#### Parâmetros  
 `memblock`  
 Ponteiro para o bloco de memória anteriormente atribuído.  
  
 `num`  
 Número de elementos.  
  
 `size`  
 Comprimento em bytes de cada elemento.  
  
## Valor de retorno  
 `_recalloc` retorna um ponteiro de `void` \(movido e possivelmente\) no bloco de memória realocado.  
  
 Se não houver memória suficiente disponível para expandir o bloco ao tamanho especificado, o bloco original permanecerá inalterado, e `NULL` é retornado.  
  
 Se o tamanho solicitado for zero, o bloco apontado por `memblock` será liberado; o valor de retorno é `NULL`, aponte para e `memblock` é deixado em um bloco liberado.  
  
 O valor de retorno para um espaço de armazenamento que é garantia de ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto.  Para obter um ponteiro para um tipo diferente de `void`, use uma conversão de tipos no valor de retorno.  
  
## Comentários  
 A função de`recalloc` \_o tamanho de um bloco de memória alocada.  O argumento de `memblock` ao início do bloco de memória.  Se `memblock` é `NULL`, \_`recalloc` se comporta da mesma maneira que [calloc](../../c-runtime-library/reference/calloc.md) e atribui\-se um novo bloco de `num` \*os bytes de `size` .  Cada elemento é inicializado como 0.  Se `memblock` não é `NULL`, deve ser um ponteiro retornado por uma chamada a `calloc`anterior, a [malloc](../../c-runtime-library/reference/malloc.md), ou a [realloc](../../c-runtime-library/reference/realloc.md).  
  
 Como o novo bloco pode estar em um novo local na memória, o ponteiro retornado pelo`recalloc` \_não é garantido como o ponteiro passado pelo argumento de `memblock` .  
  
 `_recalloc` define `errno` a `ENOMEM` se a alocação de memória falhar ou se a quantidade de memória solicitada exceder `_HEAP_MAXREQ`.  Para obter mais informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 chamadas `realloc` de`recalloc` para usar a função C\+\+ [\_set\_new\_mode](../../c-runtime-library/reference/set-new-mode.md) para definir o novo modo do manipulador.  O novo modo de manipulador indica se, em caso de falha, `realloc` deve chamar a nova rotina do manipulador conforme definido por [\_set\_new\_handler](../Topic/_set_new_handler.md).  Por padrão, `realloc` não chama a nova rotina do manipulador em caso de falha para alocar memória.  Você pode substituir esse comportamento padrão de modo que, quando o \_`recalloc` não aloca memória, `realloc` chama a nova rotina do manipulador da mesma forma que o operador de `new` faz quando falhar pela mesma razão.  Para substituir o padrão, chame  
  
```  
_set_new_mode(1)  
```  
  
 no início do programa, ou no link com o NEWMODE.OBJ.  
  
 Quando o aplicativo é vinculado a uma versão de depuração das bibliotecas de tempo de execução C, \_`recalloc` resolve a [\_recalloc\_dbg](../../c-runtime-library/reference/recalloc-dbg.md).  Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [O heap de depuração do CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
 `_recalloc` é `__declspec(noalias)` marcado e `__declspec(restrict)`, o que significa que a função não é garantida para modificar as variáveis globais, e que o ponteiro retornado não possui alias.  Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrinja](../../cpp/restrict.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_recalloc`|\<stdlib.h\> e \<malloc.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [\_recalloc\_dbg](../../c-runtime-library/reference/recalloc-dbg.md)   
 [\_aligned\_recalloc](../../c-runtime-library/reference/aligned-recalloc.md)   
 [\_aligned\_offset\_recalloc](../../c-runtime-library/reference/aligned-offset-recalloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [Opções de link](../Topic/Link%20Options.md)