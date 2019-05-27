---
title: _setmaxstdio
ms.date: 05/21/2019
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
ms.openlocfilehash: 94b768d920ffd86a5bd762f8994244dda67fb15f
ms.sourcegitcommit: bde3279f70432f819018df74923a8bb895636f81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2019
ms.locfileid: "66174828"
---
# <a name="setmaxstdio"></a>_setmaxstdio

Define o máximo de arquivos abertos simultaneamente no nível de E/S de fluxo.

## <a name="syntax"></a>Sintaxe

```C
int _setmaxstdio(
   int new_max
);
```

### <a name="parameters"></a>Parâmetros

*new_max*<br/>
Novo valor máximo de arquivos abertos simultaneamente no nível de E/S de fluxo.

## <a name="return-value"></a>Valor de retorno

Retorna *new_max*, se bem-sucedido; caso contrário, -1.

Se *new_max* for menor que **_IOB_ENTRIES** ou superior ao número máximo de identificadores disponíveis no sistema operacional, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará um valor -1 e definirá **errno** como **EINVAL**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_setmaxstdio** altera o valor máximo para o número de arquivos que podem ser abertos simultaneamente no nível de E/S do fluxo.

A E/S do tempo de execução C agora é compatível com até 8.192 arquivos abertos simultaneamente no [nível de E/S baixo](../../c-runtime-library/low-level-i-o.md). Esse nível inclui os arquivos abertos e acessados usando a família **_open**, **_read** e **_write** de funções de E/S. Por padrão, até 512 arquivos podem ser abertos simultaneamente no [nível de E/S de fluxo](../../c-runtime-library/stream-i-o.md). Esse nível inclui os arquivos abertos e acessados usando a família **fopen**, **fgetc** e **fputc** de funções. O limite de 512 arquivos abertos no nível de E/S do fluxo pode ser elevado para um máximo de 8.192 usando a função **_setmaxstdio**.

Devido às funções no nível de E/S do fluxo, como **fopen**, serem compiladas sobre as funções de nível de E/S baixo, o número máximo de 8.192 é um limite superior rígido para o número de arquivos abertos simultaneamente acessados por meio da biblioteca em tempo de execução C.

> [!NOTE]
> Esse limite superior pode estar além do que é compatível com uma determinada plataforma Win32 e sua respectiva configuração.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_setmaxstdio**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte [_getmaxstdio](getmaxstdio.md) para obter um exemplo de como usar **_setmaxstdio**.

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
