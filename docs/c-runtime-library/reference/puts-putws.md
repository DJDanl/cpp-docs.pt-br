---
title: puts, _putws
ms.date: 4/2/2020
api_name:
- _putws
- puts
- _o__putws
- _o_puts
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _putts
- _putws
- puts
helpviewer_keywords:
- strings [C++], writing
- _putts function
- standard output, writing to
- putws function
- puts function
- putts function
- _putws function
ms.assetid: 32dada12-ed45-40ac-be06-3feeced9ecd6
ms.openlocfilehash: 9681373ccf338daf05be3120fbadd39ba471e86a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332953"
---
# <a name="puts-_putws"></a>puts, _putws

Grava uma cadeia de caracteres para **stdout**.

## <a name="syntax"></a>Sintaxe

```C
int puts(
   const char *str
);
int _putws(
   const wchar_t *str
);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Cadeia de caracteres de saída.

## <a name="return-value"></a>Valor retornado

Retorna um valor não negativo se for bem-sucedido. Se **as colocações** falharem, ela retorna **o EOF;** se **_putws** falhar, ele retorna **WEOF**. Se *str* for um ponteiro nulo, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, as funções se configuram **para** **EINVAL** e retornam **EOF** ou **WEOF**.

Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **puts** grava *str* para o fluxo de saída padrão **stdout**, substituindo o caractere nulo de terminação da seqüência da seqüência ('\0') por um caractere de linha nova ('\n') no fluxo de saída.

**_putws** é a versão de grande caráter de **puts;** as duas funções se comportam de forma idêntica se o fluxo for aberto no modo ANSI. **puts** não suporta atualmente a saída em um fluxo UNICODE.

**_putwch** grava caracteres Unicode usando a configuração locale do console atual.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_putts**|**puts**|**puts**|**_putws**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**puts**|\<stdio.h>|
|**_putws**|\<stdio.h>|

O console não é suportado em aplicativos Universal Windows Platform (UWP). As alças de fluxo padrão associadas ao console, **stdin**, **stdout**e **stderr,** devem ser redirecionadas antes que as funções de tempo de execução C possam usá-las em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_puts.c
// This program uses puts to write a string to stdout.

#include <stdio.h>

int main( void )
{
   puts( "Hello world from puts!" );
}
```

### <a name="output"></a>Saída

```Output
Hello world from puts!
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fputs, fputws](fputs-fputws.md)<br/>
[fgets, fgetws](fgets-fgetws.md)<br/>
