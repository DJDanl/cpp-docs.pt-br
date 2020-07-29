---
title: _getdcwd_nolock, _wgetdcwd_nolock
ms.date: 11/04/2016
api_name:
- _wgetdcwd_nolock
- _getdcwd_nolock
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
- _wgetdcwd_nolock
- tgetdcwd_nolock
- wgetdcwd_nolock
- _getdcwd_nolock
- _tgetdcwd_nolock
- getdcwd_nolock
helpviewer_keywords:
- getdcwd_nolock function
- _tgetdcwd_nolock function
- working directory
- tgetdcwd_nolock function
- _getdcwd_nolock function
- current working directory
- wgetdcwd_nolock function
- _wgetdcwd_nolock function
- directories [C++], current working
ms.assetid: d9bdf712-43f8-4173-8f9a-844e82beaa97
ms.openlocfilehash: c07c52e0dcfe84c5f00a9a0b67d872a860941c6f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229435"
---
# <a name="_getdcwd_nolock-_wgetdcwd_nolock"></a>_getdcwd_nolock, _wgetdcwd_nolock

Obtém o caminho completo do diretório de trabalho atual na unidade especificada.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
char *_getdcwd_nolock(
   int drive,
   char *buffer,
   int maxlen
);
wchar_t *_wgetdcwd_nolock(
   int drive,
   wchar_t *buffer,
   int maxlen
);
```

### <a name="parameters"></a>parâmetros

*Dirigir*<br/>
Unidade de disco.

*completo*<br/>
Local de armazenamento para o caminho.

*maxlen*<br/>
Comprimento máximo do caminho em caracteres: **`char`** para **_getdcwd** e **`wchar_t`** para **_wgetdcwd**.

## <a name="return-value"></a>Valor retornado

Consulte [_getdcwd, _wgetdcwd](getdcwd-wgetdcwd.md).

## <a name="remarks"></a>Comentários

**_getdcwd_nolock** e **_wgetdcwd_nolock** são idênticos a **_getdcwd** e **_wgetdcwd**, respectivamente, exceto que eles não estão protegidos contra interferência por outros threads. Elas podem ser mais rápidas, porque não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tgetdcwd_nolock**|**_getdcwd_nolock**|**_getdcwd_nolock**|**_wgetdcwd_nolock**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getdcwd_nolock**|\<direct.h>|
|**_wgetdcwd_nolock**|\<direct.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_chdir, _wchdir](chdir-wchdir.md)<br/>
[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[_getdrive](getdrive.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_rmdir, _wrmdir](rmdir-wrmdir.md)<br/>
