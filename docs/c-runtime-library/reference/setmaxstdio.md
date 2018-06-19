---
title: _setmaxstdio | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _setmaxstdio
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
apitype: DLLExport
f1_keywords:
- setmaxstdio
- _setmaxstdio
dev_langs:
- C++
helpviewer_keywords:
- maximum open files
- _setmaxstdio function
- setmaxstdio function
- open files, maximum
ms.assetid: 9e966875-9ff5-47c4-9b5f-e79e83b70249
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 785fcc05c6b19086c14edc85983749894c867c18
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32407662"
---
# <a name="setmaxstdio"></a>_setmaxstdio

Define o máximo para o número de arquivos abertos simultaneamente no **stdio** nível.

## <a name="syntax"></a>Sintaxe

```C
int _setmaxstdio(
   int newmax
);
```

### <a name="parameters"></a>Parâmetros

*newmax*<br/>
Novo valor máximo para o número de arquivos abertos simultaneamente no **stdio** nível.

## <a name="return-value"></a>Valor de retorno

Retorna *newmax* se bem-sucedido; caso contrário, de -1.

Se *newmax* é menor que **_IOB_ENTRIES** ou maior, em seguida, o número máximo de identificadores disponíveis no sistema operacional, o manipulador de parâmetro inválido é invocado, conforme descrito em [ Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função retornará -1 e conjuntos de **errno** para **EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **setmaxstdio** função altera o valor máximo para o número de arquivos que podem ser abertas simultaneamente no **stdio** nível.

A E/S em tempo de execução de C agora dá suporte a muito mais arquivos abertos em plataformas Win32 do que nas versões anteriores. Até 2.048 arquivos pode ser aberto simultaneamente ao [lowio nível](../../c-runtime-library/low-level-i-o.md) (ou seja, aberto e acessado por meio do **abrir**, **Read**, **Write**, e assim por diante família de funções de e/s). Até 512 arquivos pode ser aberto simultaneamente ao [stdio nível](../../c-runtime-library/stream-i-o.md) (ou seja, aberto e acessado por meio do **fopen**, **fgetc**, **fputc** e assim por diante família de funções). O limite de 512 arquivos abertos no **stdio** nível pode ser aumentado para um máximo de 2.048 por meio do **setmaxstdio** função.

Porque **stdio**-nível de funções, como **fopen**, são criados sobre o **lowio** funções, o número máximo de 2.048 é um disco rígido limite superior para o número de simultaneamente Abra arquivos acessados por meio da biblioteca de tempo de execução C.

> [!NOTE]
> Esse limite pode estar além do que tem suporte por uma determinada plataforma Win32 e sua respectiva configuração.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_setmaxstdio**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte [getmaxstdio](getmaxstdio.md) para obter um exemplo do uso de **setmaxstdio**.

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
