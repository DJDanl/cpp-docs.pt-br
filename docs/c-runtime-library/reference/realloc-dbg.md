---
title: "_realloc_dbg | Microsoft Docs"
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
  - "_realloc_dbg"
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
  - "_realloc_dbg"
  - "realloc_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "realocando blocos de memória"
  - "Função realloc_dbg"
  - "blocos de memória, realocando"
  - "memória, realocando"
  - "Função _realloc_dbg"
ms.assetid: 7c3cb780-51ed-4d9c-9929-cdde606d846a
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _realloc_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Realoca especificado um bloco de memória heap movendo e\/ou redimensionando o bloco \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
void *_realloc_dbg(  
   void *userData,  
   size_t newSize,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### Parâmetros  
 `userData`  
 Ponteiro para o bloco de memória anteriormente atribuído.  
  
 `newSize`  
 Tamanho solicitado para o bloco realocado \(bytes\).  
  
 `blockType`  
 O tipo solicitado para o bloco realocado: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação ou NULL de `realloc` .  
  
 `linenumber`  
 Número de linha no arquivo de origem em que a operação de `realloc` foi solicitada ou NULL.  
  
 Os parâmetros de `filename` e de `linenumber` só estão disponíveis quando `_realloc_dbg` esteve chamado explicitamente ou a constante de pré\-processador de [\_CRTDBG\_MAP\_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) esteve definida.  
  
## Valor de retorno  
 Na conclusão com êxito, os essa função retornará um ponteiro para a parte do usuário do bloco de memória realocado, as chamadas a nova função de manipulador, ou retornará NULL.  Para obter uma descrição completa de comportamento de retorno, consulte a seção comentários.  Para obter mais informações sobre como a nova função de manipulador é usada, consulte a função de [realloc](../../c-runtime-library/reference/realloc.md) .  
  
## Comentários  
 `_realloc_dbg` é uma versão de depuração da função de [realloc](../../c-runtime-library/reference/realloc.md) .  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, cada chamada a `_realloc_dbg` será reduzido para uma chamada a `realloc`.  `realloc` e `_realloc_dbg` realocam um bloco de memória heap de base, mas `_realloc_dbg` acomode vários recursos de depuração: buffers em ambos os lados da parte do usuário do bloco para testar que ignora, um parâmetro em blocos para controlar tipos específicos de alocação, e `filename`\/informações de`linenumber` determina a origem de solicitações de alocação.  
  
 `_realloc_dbg` realoca o bloco de memória especificado com um pouco mais espaço do que `newSize`solicitado.  `newSize` pode ser maior ou menor que o tamanho do bloco de memória alocada originalmente.  O espaço adicional é usado pelo gerenciador de heap de depuração para vincular os blocos de memória de depuração e fornecer o aplicativo com informações de cabeçalho de depuração e para substituir os buffers.  A redistribuindo pode resultar em mover o bloco de memória original para um local diferente no heap, assim como alterar o tamanho do bloco de memória.  Se o bloco de memória é movido, o conteúdo do bloco original são substituídos.  
  
 `_realloc_dbg` define `errno` a `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória necessária \(incluindo a sobrecarga mencionada anteriormente\) excede `_HEAP_MAXREQ`.  Para obter informações sobre esse e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Para obter informações sobre como os blocos de memória são atribuídos, inicializados, e gerenciados na versão de depuração da heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  Para obter informações sobre o bloco de alocação digitar e como elas são usadas, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  Para obter informações sobre as diferenças entre chamar uma função padrão do heap e sua versão de depuração em uma compilação de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação da pilha](../Topic/Debug%20Versions%20of%20Heap%20Allocation%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_realloc_dbg`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Exemplo  
 Consulte o exemplo no tópico de [\_msize\_dbg](../../c-runtime-library/reference/msize-dbg.md) .  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md)