---
title: _getdcwd, _wgetdcwd
ms.date: 11/04/2016
apiname:
- _getdcwd
- _wgetdcwd
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wgetdcwd
- getdcwd
- _getdcwd
- tgetdcwd
- _wgetdcwd
- _tgetdcwd
helpviewer_keywords:
- wgetdcwd function
- working directory
- getdcwd function
- _getdcwd function
- _wgetdcwd function
- current working directory
- directories [C++], current working
ms.assetid: 184152f5-c7b0-495b-918d-f9a6adc178bd
ms.openlocfilehash: 464a254775d9a1d2488247d6dafb4b85cd763f10
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702928"
---
# <a name="getdcwd-wgetdcwd"></a>_getdcwd, _wgetdcwd

Obtém o caminho completo do diretório de trabalho atual na unidade especificada.

## <a name="syntax"></a>Sintaxe

```C
char *_getdcwd(
   int drive,
   char *buffer,
   int maxlen
);
wchar_t *_wgetdcwd(
   int drive,
   wchar_t *buffer,
   int maxlen
);
```

### <a name="parameters"></a>Parâmetros

*drive*<br/>
Um inteiro não negativo que especifica a unidade (0 = unidade padrão, 1 = A, 2 = B e assim por diante).

Se a unidade especificada não estiver disponível, ou o tipo da unidade (por exemplo, removível, fixo, CD-ROM, disco RAM ou unidade de rede) não pode ser determinado, o manipulador de parâmetro inválido será invocado. Para saber mais, confira [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).

*buffer*<br/>
Local de armazenamento para o caminho ou **NULL**.

Se **nulo** for especificado, esta função alocará um buffer de pelo menos *maxlen* tamanho usando **malloc**e o valor de retorno **getdcwd**é um ponteiro para o buffer alocado. O buffer pode ser liberado chamando **livre** e passando-o ponteiro.

*maxlen*<br/>
Um inteiro positivo diferente de zero que especifica o comprimento máximo do caminho, em caracteres: **char** para **getdcwd** e **wchar_t** para **wgetdcwd**.

Se *maxlen* é menor que ou igual a zero, o manipulador de parâmetro inválido será invocado. Para saber mais, confira [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).

## <a name="return-value"></a>Valor de retorno

Ponteiro para uma cadeia de caracteres que representa o caminho completo do diretório de trabalho atual na unidade especificada, ou **nulo**, que indica um erro.

Se *buffer* é especificado como **nulo** e não há memória suficiente para alocar *maxlen* caracteres, ocorrerá um erro e **errno** é definido como **ENOMEM**. Se o comprimento do caminho incluindo o caractere nulo de terminação excede *maxlen*, ocorre um erro, e **errno** está definido como **ERANGE**. Para obter mais informações sobre esses códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **getdcwd** função obtém o caminho completo do diretório de trabalho atual na unidade especificada e a armazena em *buffer*. Se o diretório de trabalho atual estiver definido como o raiz, a cadeia de caracteres terminará com uma barra invertida (\\). Se o diretório de trabalho atual estiver definido como um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.

**wgetdcwd** é uma versão de caractere largo de **getdcwd**e sua *buffer* parâmetro e valor retornado são cadeias de caracteres largos. Caso contrário, **wgetdcwd** e **getdcwd** se comportam de forma idêntica.

Essa função é thread-safe, embora dependa de **GetFullPathName**, que não thread-safe. No entanto, você pode violar o acesso thread-safe se seu aplicativo multi-threaded chamar essa função e [GetFullPathNameA](/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea).

A versão dessa função que tem o **NOLOCK** sufixo comporta-se identicamente para essa função, exceto que ele não é thread-safe e não protegido contra interferência de outros threads. Para obter mais informações, consulte [_getdcwd_nolock, _wgetdcwd_nolock](getdcwd-nolock-wgetdcwd-nolock.md).

Quando **Debug** e **crtdbg_map_alloc** são definidos, chamadas para **getdcwd** e **wgetdcwd** são substituídos por chamadas para **getdcwd_dbg** e **wgetdcwd_dbg** para que você possa depurar alocações de memória. Para obter mais informações, consulte [_getdcwd_dbg, _wgetdcwd_dbg](getdcwd-dbg-wgetdcwd-dbg.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tgetdcwd**|**_getdcwd**|**_getdcwd**|**_wgetdcwd**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getdcwd**|\<direct.h>|
|**_wgetdcwd**|\<direct.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [_getdrive](getdrive.md).

## <a name="see-also"></a>Consulte também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_chdir, _wchdir](chdir-wchdir.md)<br/>
[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[_getdrive](getdrive.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_rmdir, _wrmdir](rmdir-wrmdir.md)<br/>
