---
title: _getdcwd, _wgetdcwd
ms.date: 4/2/2020
api_name:
- _getdcwd
- _wgetdcwd
- _o__getdcwd
- _o__wgetdcwd
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-environment-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: 3a4ca8ff3f1153893282c65bc4c2becd687138ce
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344392"
---
# <a name="_getdcwd-_wgetdcwd"></a>_getdcwd, _wgetdcwd

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

*Dirigir*<br/>
Um inteiro não negativo que especifica a unidade (0 = unidade padrão, 1 = A, 2 = B e assim por diante).

Se a unidade especificada não estiver disponível ou o tipo de unidade (por exemplo, removível, fixo, CD-ROM, disco RAM ou unidade de rede) não puder ser determinado, o manipulador de parâmetros inválidos será invocado. Para saber mais, confira [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).

*Buffer*<br/>
Local de armazenamento para o caminho ou **NULL**.

Se **NULL** for especificado, esta função aloca um buffer de pelo menos *maxlen* tamanho usando **malloc**, e o valor de retorno de **_getdcwd** é um ponteiro para o buffer alocado. O buffer pode ser liberado ligando **livremente** e passando-o o ponteiro.

*maxlen*<br/>
Um inteiro positivo não zero que especifica o comprimento máximo do caminho, em caracteres: **char** para **_getdcwd** e **wchar_t** para **_wgetdcwd**.

Se *maxlen* for menor ou igual a zero, o manipulador de parâmetros inválidos é invocado. Para saber mais, confira [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).

## <a name="return-value"></a>Valor retornado

Ponteiro para uma seqüência que representa o caminho completo do diretório de trabalho atual na unidade especificada, ou **NULL**, o que indica um erro.

Se *o buffer* for especificado como **NULL** e não houver memória suficiente para alocar caracteres *maxlen,* um erro ocorrerá e **errno** será definido **como ENOMEM**. Se o comprimento do caminho, incluindo o caractere nulo terminante, exceder *maxlen,* ocorrerá um erro e **errno** será definido **como ERANGE**. Para obter mais informações sobre esses códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_getdcwd** obtém o caminho completo do diretório de trabalho atual na unidade especificada e armazena-a no *buffer*. Se o diretório de trabalho atual estiver definido como o raiz, a cadeia de caracteres terminará com uma barra invertida (\\). Se o diretório de trabalho atual estiver definido como um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.

**_wgetdcwd** é uma versão de grande caractere de **_getdcwd**, e seu parâmetro *de buffer* e valor de retorno são strings de caracteres amplos. Caso contrário, **_wgetdcwd** e **_getdcwd** se comportem de forma idêntica.

Essa função é thread-safe, embora dependa de **GetFullPathName**, que não thread-safe. No entanto, você pode violar o acesso thread-safe se seu aplicativo multi-threaded chamar essa função e [GetFullPathName](/windows/win32/api/fileapi/nf-fileapi-getfullpathnamew).

A versão desta função que tem o **sufixo _nolock** se comporta de forma idêntica a esta função, exceto que não é segura para rosca e não está protegida contra interferências por outros segmentos. Para obter mais informações, consulte [_getdcwd_nolock, _wgetdcwd_nolock](getdcwd-nolock-wgetdcwd-nolock.md).

Quando **_DEBUG** e **_CRTDBG_MAP_ALLOC** são definidas, as chamadas para **_getdcwd** e **_wgetdcwd** são substituídas por chamadas para **_getdcwd_dbg** e **_wgetdcwd_dbg** para que você possa depurar alocações de memória. Para obter mais informações, consulte [_getdcwd_dbg, _wgetdcwd_dbg](getdcwd-dbg-wgetdcwd-dbg.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_chdir, _wchdir](chdir-wchdir.md)<br/>
[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[_getdrive](getdrive.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_rmdir, _wrmdir](rmdir-wrmdir.md)<br/>
