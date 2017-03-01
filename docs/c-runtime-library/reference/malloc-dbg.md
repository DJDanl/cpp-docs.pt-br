---
title: malloc_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _malloc_dbg
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- malloc_dbg
- _malloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- malloc_dbg function
- memory allocation
- _malloc_dbg function
ms.assetid: c97eca51-140b-4461-8bd2-28965b49ecdb
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 2bdbd0b6bc0a9af533aa41b5d29a171bb56ac382
ms.lasthandoff: 02/25/2017

---
# <a name="mallocdbg"></a>_malloc_dbg
Aloca um bloco de memória no heap com espaço adicional para um cabeçalho de depuração e buffers de substituição (apenas versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_malloc_dbg(  
   size_t size,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `size`  
 Tamanho solicitado do bloco de memória (em bytes).  
  
 `blockType`  
 Tipo de bloco de memória solicitado: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou NULL.  
  
 `linenumber`  
 Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou NULL.  
  
 Os parâmetros `filename` e `linenumber` estarão disponíveis apenas quando `_malloc_dbg` tiver sido chamado explicitamente ou quando a constante do pré-processador [_CRTDBG_MAP_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) tiver sido definida.  
  
## <a name="return-value"></a>Valor de retorno  
 Mediante a conclusão bem-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória alocado, chama a nova função do manipulador ou retorna NULL. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [malloc](../../c-runtime-library/reference/malloc.md).  
  
## <a name="remarks"></a>Comentários  
 `_malloc_dbg` é uma versão de depuração da função [malloc](../../c-runtime-library/reference/malloc.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_malloc_dbg` é reduzida a uma chamada para `malloc`. Tanto o `malloc` quanto o `_malloc_dbg` alocam um bloco de memória no heap de base, mas o `_malloc_dbg` oferece vários recursos de depuração: buffers em qualquer um dos lados da parte do usuário do bloco para testar se há vazamentos, um parâmetro de tipo do bloco para rastrear tipos de alocação específicos e as informações de `filename`/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_malloc_dbg` aloca o bloco de memória com um pouco mais de espaço que o `size` solicitado. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.  
  
 `_malloc_dbg` define `errno` para `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) exceder `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_malloc_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Para obter uma amostra de como usar `_malloc_dbg`, consulte [crt_dbg1](http://msdn.microsoft.com/en-us/17b4b20c-e849-48f5-8eb5-dca6509cbaf9).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [_calloc_dbg](../../c-runtime-library/reference/calloc-dbg.md)   
 [_calloc_dbg](../../c-runtime-library/reference/calloc-dbg.md)
