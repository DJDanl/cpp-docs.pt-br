---
title: _recalloc_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _recalloc_dbg
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
- recalloc_dbg
- _recalloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- _recalloc_dbg function
- recalloc_dbg function
ms.assetid: 43c3e9b2-be6d-4508-9b0f-3220c8a47ca3
caps.latest.revision: 8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 18c1e36c2671c1c04ae8dd317a14234eda4c09a3
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="recallocdbg"></a>_recalloc_dbg
Realoca uma matriz e inicializa seus elementos como 0 (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_recalloc_dbg(   
   void *userData,  
   size_t num,  
   size_t size,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `userData`  
 Ponteiro para o bloco de memória alocado anteriormente.  
  
 `num`  
 Número necessário de blocos de memória.  
  
 `size`  
 Tamanho necessário de cada bloco de memória (bytes).  
  
 `blockType`  
 Tipo solicitado de bloco de memória: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração).  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
 Os parâmetros `filename` e `linenumber` estarão disponíveis apenas quando `_recalloc_dbg` tiver sido chamado explicitamente ou quando a constante do pré-processador [_CRTDBG_MAP_ALLOC](../../c-runtime-library/crtdbg-map-alloc.md) tiver sido definida.  
  
## <a name="return-value"></a>Valor de retorno  
 Após a conclusão bem-sucedida, essa função retorna um ponteiro para a parte do usuário do bloco de memória realocado, chama a nova função do manipulador ou retorna NULL. Para obter uma descrição completa do comportamento de retorno, consulte a seção Comentários a seguir. Para obter mais informações sobre como a nova função do manipulador é usada, consulte a função [_recalloc](../../c-runtime-library/reference/recalloc.md).  
  
## <a name="remarks"></a>Comentários  
 `_recalloc_dbg` é uma versão de depuração da função [_recalloc](../../c-runtime-library/reference/recalloc.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_recalloc_dbg` é reduzida a uma chamada para `_recalloc`. `_recalloc` e `_recalloc_dbg` realocam um bloco de memória no heap de base, mas `_recalloc_dbg` acomoda diversos recursos de depuração: buffers nos dois lados da parte do usuário do bloco para testar se há perdas, um parâmetro de tipo de bloco para rastrear tipos de alocação específicos e informações de `filename`/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_recalloc_dbg` realoca o bloco de memória especificado com um pouco mais de espaço do que o tamanho solicitado (`num` * `size`), que pode ser maior ou menor que o tamanho do bloco de memória alocado originalmente. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. A realocação pode resultar no deslocamento do bloco de memória original para outro local do heap e alterar o tamanho do bloco de memória. A parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição são preenchidos com 0xFD.  
  
 `_recalloc_dbg` definirá `errno` como `ENOMEM` se uma alocação de memória falhar; `EINVAL` será retornado se uma quantidade de memória necessária (incluindo a sobrecarga mencionada anteriormente) exceder `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_recalloc_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)
