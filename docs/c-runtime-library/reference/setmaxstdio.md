---
title: _setmaxstdio
ms.date: 11/04/2016
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
helpviewer_keywords:
- maximum open files
- _setmaxstdio function
- setmaxstdio function
- open files, maximum
ms.assetid: 9e966875-9ff5-47c4-9b5f-e79e83b70249
ms.openlocfilehash: 58cffedf673e23a69c2d8040071b2e3353ff4502
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50445078"
---
# <a name="setmaxstdio"></a>_setmaxstdio

Define o máximo para o número de arquivos abertos simultaneamente na **stdio** nível.

## <a name="syntax"></a>Sintaxe

```C
int _setmaxstdio(
   int newmax
);
```

### <a name="parameters"></a>Parâmetros

*newmax*<br/>
Novo máximo para o número de arquivos abertos simultaneamente na **stdio** nível.

## <a name="return-value"></a>Valor de retorno

Retorna *newmax* se bem-sucedido; caso contrário, de -1.

Se *newmax* é menor que **_IOB_ENTRIES** ou maior que o número máximo de identificadores disponíveis no sistema operacional, o manipulador de parâmetro inválido é invocado, conforme descrito em [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará -1 e definirá **errno** à **EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **setmaxstdio** função altera o valor máximo para o número de arquivos que podem ser abertos simultaneamente na **stdio** nível.

A E/S em tempo de execução de C agora dá suporte a muito mais arquivos abertos em plataformas Win32 do que nas versões anteriores. Até 2.048 arquivos podem ser aberto simultaneamente na [nível lowio](../../c-runtime-library/low-level-i-o.md) (ou seja, abertos e acessados por meio das **Open**, **Read**, **Write**, e assim por diante família de funções de e/s). Até 512 arquivos podem ser aberto simultaneamente na [nível stdio](../../c-runtime-library/stream-i-o.md) (ou seja, abertos e acessados por meio das **fopen**, **fgetc**, **fputc** e assim por diante família de funções). O limite de 512 arquivos abertos na **stdio** nível pode ser aumentado para um máximo de 2.048 por meio das **setmaxstdio** função.

Porque **stdio**-funções no nível, como **fopen**, baseiam-se na parte superior dos **lowio** funções, o máximo de 2.048 é um limite superior rígido para o número de simultaneamente Abra arquivos acessados por meio da biblioteca de tempo de execução C.

> [!NOTE]
> Esse limite pode estar além do que tem suporte por uma determinada plataforma Win32 e sua respectiva configuração.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_setmaxstdio**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Ver [getmaxstdio](getmaxstdio.md) para obter um exemplo de como usar **setmaxstdio**.

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
