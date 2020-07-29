---
title: _getcwd_dbg, _wgetcwd_dbg
ms.date: 11/04/2016
api_name:
- _wgetcwd_dbg
- _getcwd_dbg
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _getcwd_dbg
- _wgetcwd_dbg
- getcwd_dbg
- wgetcwd_dbg
helpviewer_keywords:
- wgetcwd_dbg function
- working directory
- _getcwd_dbg function
- getcwd_dbg function
- current working directory
- _wgetcwd_dbg function
- directories [C++], current working
ms.assetid: 8d5d151f-d844-4aa6-a28c-1c11a22dc00d
ms.openlocfilehash: 982a7c94ef3cbe5adf1e8e8a8a4c28443d8a5b8f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220659"
---
# <a name="_getcwd_dbg-_wgetcwd_dbg"></a>_getcwd_dbg, _wgetcwd_dbg

Versões de depuração das funções [_getcwd, _wgetcwd](getcwd-wgetcwd.md) (disponíveis somente durante a depuração).

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>parâmetros

*completo*<br/>
Local de armazenamento para o caminho.

*maxlen*<br/>
Comprimento máximo do caminho em caracteres: **`char`** para **_getcwd_dbg** e **`wchar_t`** para **_wgetcwd_dbg**.

*blockType*<br/>
Tipo solicitado do bloco de memória: **_CLIENT_BLOCK** ou **_NORMAL_BLOCK**.

*nome do arquivo*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*LineNumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nula**.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o *buffer*. Um valor de retorno **nulo** indica um erro e **errno** é definido como **ENOMEM**, indicando que não há memória suficiente para alocar *maxlen* bytes (quando um argumento **nulo** é fornecido como *buffer*) ou para **ERANGE**, indicando que o caminho tem mais de *maxlen* caracteres.

Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

As funções **_getcwd_dbg** e **_wgetcwd_dbg** são idênticas a **_getcwd** e **_wgetcwd** , exceto que, quando **_DEBUG** é definido, essas funções usam a versão de depuração de **malloc** e **_malloc_dbg** para alocar memória se **NULL** for passado como o primeiro parâmetro. Para obter mais informações, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o sinalizador de **_CRTDBG_MAP_ALLOC** . Quando **_CRTDBG_MAP_ALLOC** é definido, as chamadas para **_getcwd** e **_wgetcwd** são remapeadas para **_getcwd_dbg** e **_wgetcwd_dbg**, respectivamente, com o *blockType* definido como **_NORMAL_BLOCK**. Portanto, você não precisa chamar essas funções explicitamente, a menos que queira marcar os blocos de heap como **_CLIENT_BLOCK**. Para obter mais informações, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

## <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tgetcwd_dbg**|**_getcwd_dbg**|**_getcwd_dbg**|**_wgetcwd_dbg**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getcwd_dbg**|\<crtdbg.h>|
|**_wgetcwd_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[Versões de depuração das funções de alocação da pilha](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
