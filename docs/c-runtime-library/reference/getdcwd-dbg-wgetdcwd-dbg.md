---
title: _getdcwd_dbg, _wgetdcwd_dbg
ms.date: 11/04/2016
apiname:
- _getdcwd_dbg
- _wgetdcwd_dbg
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
ms.openlocfilehash: 700cfe732dc390ca59a976694403bb3d91af5980
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62331841"
---
# <a name="getdcwddbg-wgetdcwddbg"></a>_getdcwd_dbg, _wgetdcwd_dbg

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

### <a name="parameters"></a>Parâmetros

*drive*<br/>
Nome da unidade de disco.

*buffer*<br/>
Local de armazenamento para o caminho.

*maxlen*<br/>
Comprimento máximo do caminho em caracteres: **char** para **getdcwd_dbg** e **wchar_t** para **wgetdcwd_dbg**.

*blockType*<br/>
Tipo do bloco de memória solicitado: **client_block** ou **normal_block**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nulo**.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para *buffer*. Um **nulo** valor retornado indica um erro, e **errno** será definido como **ENOMEM**, indicando que há memória suficiente para alocar *maxlen* bytes (quando um **nulo** argumento é fornecido como *buffer*), ou **ERANGE**, que indica que o caminho é maior que *maxlen*  caracteres. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **getdcwd_dbg** e **wgetdcwd_dbg** funções são idênticas às **getdcwd** e **wgetdcwd** , exceto que, quando **Debug** é definido, essas funções usam a versão de depuração **malloc** e **malloc_dbg** para alocar memória se **nulo** é passado como o *buffer* parâmetro. Para obter mais informações, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir as **crtdbg_map_alloc** sinalizador. Quando **crtdbg_map_alloc** for definido, chamadas para **getdcwd** e **wgetdcwd** são remapeadas para **getdcwd_dbg** e **_ wgetdcwd_dbg**, respectivamente, com o *blockType* definido como **normal_block**. Portanto, você não precisa chamar essas funções explicitamente, a menos que você deseja marcar os blocos de heap como **client_block**. Para obter mais informações, consulte [Tipos de Blocos no Heap de Depuração](/visualstudio/debugger/crt-debug-heap-details).

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

## <a name="see-also"></a>Consulte também

[_getdcwd, _wgetdcwd](getdcwd-wgetdcwd.md)<br/>
[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
