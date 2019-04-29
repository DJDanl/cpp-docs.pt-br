---
title: _fcvt
ms.date: 04/05/2018
apiname:
- _fcvt
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _fcvt
helpviewer_keywords:
- converting floating point, to strings
- _fcvt function
- floating-point functions, converting number to string
- fcvt function
- floating-point functions
ms.assetid: 74584c88-f0dd-4907-8fca-52da5df583f5
ms.openlocfilehash: ae9323e3bb629fd61b35a8c844b00bfcc73235bb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62334834"
---
# <a name="fcvt"></a>_fcvt

Converte um número de ponto flutuante em uma cadeia de caracteres. Uma versão mais segura dessa função está disponível. Consulte [_fcvt_s](fcvt-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *_fcvt(
   double value,
   int count,
   int *dec,
   int *sign
);
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
Número a ser convertido.

*count*<br/>
O número de dígitos após o ponto decimal.

*dec*<br/>
Ponteiro para a posição do ponto decimal armazenada.

*sign*<br/>
Ponteiro para o indicador de logon armazenado.

## <a name="return-value"></a>Valor de retorno

**fcvt** retorna um ponteiro para a cadeia de caracteres de dígitos, **nulo** em erro.

## <a name="remarks"></a>Comentários

O **fcvt** função converte um número de ponto flutuante em uma cadeia de caracteres terminada em nulo. O *valor* parâmetro é o número de ponto flutuante a ser convertido. **fcvt** armazena os dígitos de *valor* como uma cadeia de caracteres e acrescenta um caractere nulo ('\0'). O *contagem* parâmetro especifica o número de dígitos a serem armazenados após o ponto decimal. Dígitos em excesso são arredondados para *contagem* coloca. Se houver menos de *contagem* dígitos de precisão, a cadeia de caracteres será preenchida com zeros.

O número total de dígitos retornados por **fcvt** não excederá **_CVTBUFSIZE**.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* pode ser obtido *dec* e após a chamada. O *dec* parâmetro aponta para um valor inteiro; o valor inteiro dando a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro *sinal* aponta para um inteiro que indica o sinal do *valor*. O inteiro é definido como 0 se *valor* for positivo e é definido como um número diferente de zero se *valor* é negativo.

A diferença entre **ecvt** e **fcvt** está na interpretação do *contagem* parâmetro. **ecvt** interpreta *contagem* como o número total de dígitos na cadeia de saída, enquanto **fcvt** interpreta *contagem* como o número de dígitos após o ponto decimal.

**ecvt** e **fcvt** usam um único buffer alocado estaticamente para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.

Essa função valida seus parâmetros. Se *dec* ou *sinal* está **nulo**, ou *contagem* for 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [parâmetro Validação](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e **nulo** é retornado.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fcvt**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fcvt.c
// compile with: /W3
// This program converts the constant
// 3.1415926535 to a string and sets the pointer
// buffer to point to that string.

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   int  decimal, sign;
   char *buffer;
   double source = 3.1415926535;

   buffer = _fcvt( source, 7, &decimal, &sign ); // C4996
   // Note: _fcvt is deprecated; consider using _fcvt_s instead
   printf( "source: %2.10f   buffer: '%s'   decimal: %d   sign: %d\n",
            source, buffer, decimal, sign );
}
```

```Output
source: 3.1415926535   buffer: '31415927'   decimal: 1   sign: 0
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt](ecvt.md)<br/>
[_gcvt](gcvt.md)<br/>
