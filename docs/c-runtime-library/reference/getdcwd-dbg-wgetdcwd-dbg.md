---
title: _getdcwd_dbg, _wgetdcwd_dbg
ms.date: 11/04/2016
api_name:
- _getdcwd_dbg
- _wgetdcwd_dbg
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _getdcwd_dbg
- getdcwd_dbg
- _wgetdcwd_dbg
- wgetdcwd_dbg
helpviewer_keywords:
- working directory
- _getdcwd_dbg function
- wgetdcwd_dbg function
- current working directory
- getdcwd_dbg function
- _wgetdcwd_dbg function
- directories [C++], current working
ms.assetid: 266bf6f0-0417-497f-963d-2e0f306d9385
ms.openlocfilehash: a31617445ccb0640042be41ee4f710e528b9ceb7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229448"
---
# <a name="_getdcwd_dbg-_wgetdcwd_dbg"></a>_getdcwd_dbg, _wgetdcwd_dbg

Versões de depuração das funções [_getdcwd, _wgetdcwd](getdcwd-wgetdcwd.md) (disponíveis somente durante a depuração).

## <a name="syntax"></a>Sintaxe

```C
char *_getdcwd_dbg(
   int drive,
   char *buffer,
   int maxlen,
   int blockType,
   const char *filename,
   int linenumber
);
wchar_t *_wgetdcwd_dbg(
   int drive,
   wchar_t *buffer,
   int maxlen,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>parâmetros

*Dirigir*<br/>
Nome da unidade de disco.

*completo*<br/>
Local de armazenamento para o caminho.

*maxlen*<br/>
Comprimento máximo do caminho em caracteres: **`char`** para **_getdcwd_dbg** e **`wchar_t`** para **_wgetdcwd_dbg**.

*blockType*<br/>
Tipo solicitado do bloco de memória: **_CLIENT_BLOCK** ou **_NORMAL_BLOCK**.

*nome do arquivo*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*LineNumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nula**.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o *buffer*. Um valor de retorno **nulo** indica um erro e **errno** é definido como **ENOMEM**, indicando que não há memória suficiente para alocar *maxlen* bytes (quando um argumento **nulo** é fornecido como *buffer*) ou para **ERANGE**, indicando que o caminho tem mais de *maxlen* caracteres. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

As funções **_getdcwd_dbg** e **_wgetdcwd_dbg** são idênticas a **_getdcwd** e **_wgetdcwd** , exceto que, quando **_DEBUG** é definido, essas funções usam a versão de depuração de **malloc** e **_malloc_dbg** para alocar memória se **NULL** for passado como o parâmetro de *buffer* . Para obter mais informações, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o sinalizador de **_CRTDBG_MAP_ALLOC** . Quando **_CRTDBG_MAP_ALLOC** é definido, as chamadas para **_getdcwd** e **_wgetdcwd** são remapeadas para **_getdcwd_dbg** e **_wgetdcwd_dbg**, respectivamente, com o *blockType* definido como **_NORMAL_BLOCK**. Portanto, você não precisa chamar essas funções explicitamente, a menos que queira marcar os blocos de heap como **_CLIENT_BLOCK**. Para obter mais informações, consulte [tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tgetdcwd_dbg**|**_getdcwd_dbg**|**_getdcwd_dbg**|**_wgetdcwd_dbg**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getdcwd_dbg**|\<crtdbg.h>|
|**_wgetdcwd_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[_getdcwd, _wgetdcwd](getdcwd-wgetdcwd.md)<br/>
[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[Versões de depuração das funções de alocação da pilha](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
