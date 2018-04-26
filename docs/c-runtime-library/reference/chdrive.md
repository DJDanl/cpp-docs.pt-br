---
title: _chdrive | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _chdrive
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- chdrive
- _chdrive
dev_langs:
- C++
helpviewer_keywords:
- drives, changing
- _chdrive function
- chdrive function
ms.assetid: 212a1a4b-4fa8-444e-9677-7fca4c8c47e3
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d2ea43a3c6d890a1e101ae3f3c390b031c5f5ee9
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="chdrive"></a>_chdrive

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

*Dirigir*<br/>
Um inteiro de 1 a 26 que especifica a unidade de trabalho atual (1 = A, B = 2 e assim por diante).

## <a name="return-value"></a>Valor de retorno

Zero (0) se a unidade de trabalho atual tiver sido alterada com sucesso; caso contrário, -1.

## <a name="remarks"></a>Comentários

Se *unidade* está fora do intervalo de 1 a 26, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, o **ChDrive** função retornará -1, **errno** é definido como **EACCES**, e **doserrno** é definido como  **ERROR_INVALID_DRIVE**.

A função **_chdrive** não é thread-safe porque ela depende da função **SetCurrentDirectory**, que, em si, não é thread-safe. Para usar **_chdrive** com segurança em um aplicativo multithread, você deve fornecer sua própria sincronização de thread. Para obter mais informações, vá para a [Biblioteca MSDN](http://go.microsoft.com/fwlink/p/?linkid=150542) e pesquise por **SetCurrentDirectory**.

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
