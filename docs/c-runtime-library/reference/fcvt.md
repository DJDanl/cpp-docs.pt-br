---
title: _fcvt
ms.date: 04/05/2018
api_name:
- _fcvt
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _fcvt
helpviewer_keywords:
- converting floating point, to strings
- _fcvt function
- floating-point functions, converting number to string
- fcvt function
- floating-point functions
ms.assetid: 74584c88-f0dd-4907-8fca-52da5df583f5
ms.openlocfilehash: a90f8510e734c8459867d323eccccc75e94983d1
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70941323"
---
# <a name="_fcvt"></a>_fcvt

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

**_fcvt** retorna um ponteiro para a cadeia de caracteres de dígitos, **NULL** em erro.

## <a name="remarks"></a>Comentários

A função **_fcvt** converte um número de ponto flutuante em uma cadeia de caracteres de caractere terminada em nulo. O parâmetro de *valor* é o número de ponto flutuante a ser convertido. **_fcvt** armazena os dígitos de *valor* como uma cadeia de caracteres e acrescenta um caractere nulo (' \ 0 '). O parâmetro *Count* especifica o número de dígitos a serem armazenados após o ponto decimal. Os dígitos em excesso são arredondados para os locais de *contagem* . Se houver menos de dígitos de *contagem* de precisão, a cadeia de caracteres será preenchida com zeros.

O número total de dígitos retornados por **_fcvt** não excederá **_CVTBUFSIZE**.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* podem ser obtidas de *Dec* e Sign após a chamada. O parâmetro *Dec* aponta para um valor inteiro; Esse valor inteiro fornece a posição do ponto decimal em relação ao início da cadeia de caracteres. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O *sinal* de parâmetro aponta para um inteiro que indica o sinal de *valor*. O inteiro será definido como 0 se o *valor* for positivo e será definido como um número diferente de zero se o *valor* for negativo.

A diferença entre **_ecvt** e **_fcvt** está na interpretação do parâmetro *Count* . **_ecvt** interpreta a *contagem* como o número total de dígitos na cadeia de caracteres de saída, enquanto **_fcvt** interpreta a *contagem* como o número de dígitos após o ponto decimal.

**_ecvt** e **_fcvt** usam um único buffer alocado estaticamente para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.

Essa função valida seus parâmetros. Se *Dec* ou *Sign* for **NULL**ou *Count* for 0, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **errno** será definido como **EINVAL** e **NULL** será retornado.

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
