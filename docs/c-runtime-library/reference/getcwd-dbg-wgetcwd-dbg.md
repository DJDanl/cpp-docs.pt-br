---
title: _getcwd_dbg, _wgetcwd_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _wgetcwd_dbg
- _getcwd_dbg
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _getcwd_dbg
- _wgetcwd_dbg
- getcwd_dbg
- wgetcwd_dbg
dev_langs:
- C++
helpviewer_keywords:
- wgetcwd_dbg function
- working directory
- _getcwd_dbg function
- getcwd_dbg function
- current working directory
- _wgetcwd_dbg function
- directories [C++], current working
ms.assetid: 8d5d151f-d844-4aa6-a28c-1c11a22dc00d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cc2538ce4e745917e23d67903b86677bacfbb979
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getcwddbg-wgetcwddbg"></a>_getcwd_dbg, _wgetcwd_dbg
Versões de depuração das funções [_getcwd, _wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md) (disponíveis somente durante a depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_getcwd_dbg(   
   char *buffer,  
   int maxlen,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
wchar_t *_wgetcwd_dbg(   
   wchar_t *buffer,  
   int maxlen,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Local de armazenamento para o caminho.  
  
 `maxlen`  
 Comprimento máximo do caminho em caracteres: `char` para `_getcwd_dbg` e `wchar_t` para `_wgetcwd_dbg`.  
  
 `blockType`  
 Tipo de bloco de memória solicitado: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para `buffer`. Um valor retornado `NULL` indica que houve um erro e `errno` é definido como `ENOMEM`, indicando que a memória não é suficiente para alocar os bytes de `maxlen` (quando um argumento `NULL` é informado como `buffer`), ou como `ERANGE`, indicando que o caminho tem mais caracteres que o definido pelo parâmetro `maxlen`.  
  
 Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 O `_getcwd_dbg` e `_wgetcwd_dbg` funções são idênticas aos `_getcwd` e `_wgetcwd` exceto que, quando `_DEBUG` é definida, essas funções usam a versão de depuração `malloc` e `_malloc_dbg` para alocar memória se `NULL` é passado como o primeiro parâmetro. Para obter mais informações, consulte [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md).  
  
 Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o sinalizador `_CRTDBG_MAP_ALLOC`. Quando `_CRTDBG_MAP_ALLOC` é definido, as chamadas a `_getcwd` e `_wgetcwd` são remapeadas para `_getcwd_dbg` e `_wgetcwd_dbg`, respectivamente, com o `blockType` definido como `_NORMAL_BLOCK`. Assim, não é necessário chamar essas funções explicitamente, a menos que você queira marcar os blocos de heap como `_CLIENT_BLOCK`. Para obter mais informações, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tgetcwd_dbg`|`_getcwd_dbg`|`_getcwd_dbg`|`_wgetcwd_dbg`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_getcwd_dbg`|\<crtdbg.h>|  
|`_wgetcwd_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [_getcwd, _wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)   
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)