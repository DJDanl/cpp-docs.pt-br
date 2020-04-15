---
title: _fcvt
ms.date: 4/2/2020
api_name:
- _fcvt
- _o__fcvt
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: a017ed58b962520793d5b10b088793dbc9b8a83d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347425"
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

*contagem*<br/>
O número de dígitos após o ponto decimal.

*Dezembro*<br/>
Ponteiro para a posição do ponto decimal armazenada.

*Sinal*<br/>
Ponteiro para o indicador de logon armazenado.

## <a name="return-value"></a>Valor retornado

**_fcvt** retorna um ponteiro para a seqüência de dígitos, **NULL** on error.

## <a name="remarks"></a>Comentários

A função **_fcvt** converte um número de ponto flutuante em uma seqüência de caracteres com término nulo. O parâmetro de *valor* é o número de ponto flutuante a ser convertido. **_fcvt** armazena os dígitos de *valor* como uma seqüência de caracteres e anexa um caractere nulo ('\0'). O parâmetro *de contagem* especifica o número de dígitos a serem armazenados após o ponto decimal. Os dígitos em excesso são arredondados para *contar* lugares. Se houver menos de *dígitos* de precisão, a seqüência é acolchoada com zeros.

O número total de dígitos devolvidos por **_fcvt** não excederá **_CVTBUFSIZE**.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* podem ser obtidos a partir *de dezembro* e assinar após a chamada. O parâmetro *dec* aponta para um valor inteiro; este valor inteiro dá a posição do ponto decimal em relação ao início da string. Um valor inteiro de zero ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O *sinal* de parâmetro aponta para um inteiro indicando o sinal de *valor*. O inteiro é definido como 0 se *o valor* for positivo e é definido como um número não zero se *o valor* for negativo.

A diferença entre **_ecvt** e **_fcvt** está na interpretação do parâmetro de *contagem.* **_ecvt** interpreta *a contagem* como o número total de dígitos na cadeia de saída, enquanto **_fcvt** interpreta *a contagem* como o número de dígitos após o ponto decimal.

**_ecvt** e **_fcvt** usar um único buffer estáticamente alocado para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.

Essa função valida seus parâmetros. Se *dec* ou *sinal* for **NULO,** ou *contagem* for 0, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e **NULL** é devolvido.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_ecvt](ecvt.md)<br/>
[_gcvt](gcvt.md)<br/>
