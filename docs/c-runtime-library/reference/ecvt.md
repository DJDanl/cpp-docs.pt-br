---
title: _ecvt
ms.date: 4/2/2020
api_name:
- _ecvt
- _o__ecvt
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
- api-ms-win-crt-convert-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _ecvt
helpviewer_keywords:
- _ecvt function
- numbers, converting
- converting double numbers
- ecvt function
ms.assetid: a916eb05-92d1-4b5c-8563-093acdb49dc8
ms.openlocfilehash: 227010fde5dc5ec82fc13c724c8d5a2f43788a8f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234192"
---
# <a name="_ecvt"></a>_ecvt

Converte um **`double`** número em uma cadeia de caracteres. Uma versão mais segura dessa função está disponível. Consulte [_ecvt_s](ecvt-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *_ecvt(
   double value,
   int count,
   int *dec,
   int *sign
);
```

### <a name="parameters"></a>parâmetros

*value*<br/>
Número a ser convertido.

*contagem*<br/>
Número de dígitos armazenados.

*dez*<br/>
Posição do ponto decimal armazenada.

*sign*<br/>
Sinal do número convertido.

## <a name="return-value"></a>Valor retornado

**_ecvt** retorna um ponteiro para a cadeia de caracteres de dígitos; **NULL** se ocorreu um erro.

## <a name="remarks"></a>Comentários

A função **_ecvt** converte um número de ponto flutuante em uma cadeia de caracteres. O parâmetro de *valor* é o número de ponto flutuante a ser convertido. Essa função armazena até dígitos da *contagem* de *valor* como uma cadeia de caracteres e acrescenta um caractere nulo (' \ 0 '). Se o número de dígitos no *valor* exceder a *contagem*, o dígito de ordem inferior será arredondado. Se houver menos de dígitos de *contagem* , a cadeia de caracteres será preenchida com zeros.

O número total de dígitos retornados por **_ecvt** não será excedido **_CVTBUFSIZE**.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* podem ser obtidas de *Dec* e *Sign* após a chamada. O parâmetro *Dec* aponta para um valor inteiro que dá a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de 0 ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro *Sign* aponta para um inteiro que indica o sinal do número convertido. Se o valor inteiro for 0, o número será positivo. Caso contrário, o resultado será negativo.

A diferença entre **_ecvt** e **_fcvt** está na interpretação do parâmetro de *contagem* . **_ecvt** interpreta a *contagem* como o número total de dígitos na cadeia de caracteres de saída, enquanto **_fcvt** interpreta a *contagem* como o número de dígitos após o ponto decimal.

**_ecvt** e **_fcvt** usar um único buffer alocado estaticamente para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.

Essa função valida seus parâmetros. Se *Dec* ou *Sign* for **NULL**ou *Count* for 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **errno** será definido como **EINVAL** e **NULL** será retornado.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_ecvt**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_ecvt.c
// compile with: /W3
// This program uses _ecvt to convert a
// floating-point number to a character string.

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   int     decimal,   sign;
   char    *buffer;
   int     precision = 10;
   double  source = 3.1415926535;

   buffer = _ecvt( source, precision, &decimal, &sign ); // C4996
   // Note: _ecvt is deprecated; consider using _ecvt_s instead
   printf( "source: %2.10f   buffer: '%s'  decimal: %d  sign: %d\n",
           source, buffer, decimal, sign );
}
```

```Output
source: 3.1415926535   buffer: '3141592654'  decimal: 1  sign: 0
```

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_fcvt](fcvt.md)<br/>
[_gcvt](gcvt.md)<br/>
