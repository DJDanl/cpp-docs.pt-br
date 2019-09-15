---
title: _chdrive
ms.date: 11/04/2016
api_name:
- _chdrive
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
- api-ms-win-crt-filesystem-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- chdrive
- _chdrive
helpviewer_keywords:
- drives, changing
- _chdrive function
- chdrive function
ms.assetid: 212a1a4b-4fa8-444e-9677-7fca4c8c47e3
ms.openlocfilehash: 3ee292c03c9d31944e0a555c2159d7a5dd2cd0eb
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939237"
---
# <a name="_chdrive"></a>_chdrive

Altera a unidade de trabalho atual.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _chdrive(
   int drive
);
```

### <a name="parameters"></a>Parâmetros

*drive*<br/>
Um inteiro de 1 a 26 que especifica a unidade de trabalho atual (1 = A, B = 2 e assim por diante).

## <a name="return-value"></a>Valor de retorno

Zero (0) se a unidade de trabalho atual tiver sido alterada com sucesso; caso contrário, -1.

## <a name="remarks"></a>Comentários

Se a *unidade* não estiver no intervalo de 1 a 26, o manipulador de parâmetro inválido será invocado conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função **_chdrive** retornará-1, **errno** será definido como **EACCES**e **_doserrno** será definido como **ERROR_INVALID_DRIVE**.

A função **_chdrive** não é thread-safe porque ela depende da função **SetCurrentDirectory**, que, em si, não é thread-safe. Para usar **_chdrive** com segurança em um aplicativo multithread, você deve fornecer sua própria sincronização de thread. Para obter mais informações, consulte [SetCurrentDirectory](/windows/win32/api/winbase/nf-winbase-setcurrentdirectory).

A função **_chdrive** altera somente unidade de trabalho atual;  **_chdir** altera o diretório de trabalho atual.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_chdrive**|\<direct.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo de [_getdrive](getdrive.md).

## <a name="see-also"></a>Consulte também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_chdir, _wchdir](chdir-wchdir.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_getcwd, _wgetcwd](getcwd-wgetcwd.md)<br/>
[_getdrive](getdrive.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_rmdir, _wrmdir](rmdir-wrmdir.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
