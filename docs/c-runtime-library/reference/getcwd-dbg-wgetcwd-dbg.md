---
title: _getcwd_dbg, _wgetcwd_dbg
ms.date: 11/04/2016
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
helpviewer_keywords:
- wgetcwd_dbg function
- working directory
- _getcwd_dbg function
- getcwd_dbg function
- current working directory
- _wgetcwd_dbg function
- directories [C++], current working
ms.assetid: 8d5d151f-d844-4aa6-a28c-1c11a22dc00d
ms.openlocfilehash: 9616c5f7e29b4f003d3943ba058d1f1a1d5adb5c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50521128"
---
# <a name="getcwddbg-wgetcwddbg"></a>_getcwd_dbg, _wgetcwd_dbg

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

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Local de armazenamento para o caminho.

*MaxLen*<br/>
Comprimento máximo do caminho em caracteres: **char** para **getcwd_dbg** e **wchar_t** para **wgetcwd_dbg**.

*blockType*<br/>
Tipo do bloco de memória solicitado: **client_block** ou **normal_block**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nulo**.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para *buffer*. Um **nulo** valor retornado indica um erro, e **errno** será definido como **ENOMEM**, indicando que há memória suficiente para alocar *maxlen* bytes (quando um **nulo** argumento é fornecido como *buffer*), ou **ERANGE**, que indica que o caminho é maior que *maxlen*  caracteres.

Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **getcwd_dbg** e **wgetcwd_dbg** funções são idênticas às **getcwd** e **wgetcwd** , exceto que, quando **_ Depurar** é definido, essas funções usam a versão de depuração **malloc** e **malloc_dbg** para alocar memória se **nulo** é passado como o primeiro parâmetro. Para obter mais informações, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir as **crtdbg_map_alloc** sinalizador. Quando **crtdbg_map_alloc** for definido, chamadas para **getcwd** e **wgetcwd** são remapeadas para **getcwd_dbg** e **_ wgetcwd_dbg**, respectivamente, com o *blockType* definido como **normal_block**. Portanto, você não precisa chamar essas funções explicitamente, a menos que você deseja marcar os blocos de heap como **client_block**. Para obter mais informações, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

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

## <a name="see-also"></a>Consulte também

[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
