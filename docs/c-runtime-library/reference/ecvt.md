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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 5e1760d5c68e650f6fbf44866d4e368b9d6233b6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348019"
---
# <a name="_ecvt"></a>_ecvt

Converte um número **duplo** em uma seqüência. Uma versão mais segura dessa função está disponível. Consulte [_ecvt_s](ecvt-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *_ecvt(
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
Número de dígitos armazenados.

*Dezembro*<br/>
Posição do ponto decimal armazenada.

*Sinal*<br/>
Sinal do número convertido.

## <a name="return-value"></a>Valor retornado

**_ecvt** retorna um ponteiro para a seqüência de dígitos; **NULO** se ocorreu um erro.

## <a name="remarks"></a>Comentários

A função **_ecvt** converte um número de ponto flutuante em uma seqüência de caracteres. O parâmetro de *valor* é o número de ponto flutuante a ser convertido. Esta função armazena até *contar* dígitos de *valor* como uma seqüência de caracteres e anexa um caractere nulo ('\0'). Se o número de dígitos em *valor* exceder a *contagem,* o dígito de baixo pedido será arredondado. Se houver menos de dígitos *de contagem,* a seqüência é acolchoada com zeros.

O número total de dígitos devolvidos por **_ecvt** não excederá **_CVTBUFSIZE**.

Somente dígitos são armazenados na cadeia de caracteres. A posição do ponto decimal e o sinal de *valor* podem ser obtidos a partir *de dezembro* e *assinar* após a chamada. O parâmetro *dec* aponta para um valor inteiro dando a posição do ponto decimal em relação ao início da seqüência. Um valor inteiro de 0 ou negativo indica que o ponto decimal se encontra à esquerda do primeiro dígito. O parâmetro *de sinal* aponta para um inteiro que indica o sinal do número convertido. Se o valor inteiro for 0, o número será positivo. Caso contrário, o resultado será negativo.

A diferença entre **_ecvt** e **_fcvt** está na interpretação do parâmetro de *contagem.* **_ecvt** interpreta *a contagem* como o número total de dígitos na cadeia de saída, enquanto **_fcvt** interpreta *a contagem* como o número de dígitos após o ponto decimal.

**_ecvt** e **_fcvt** usar um único buffer estáticamente alocado para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.

Essa função valida seus parâmetros. Se *dec* ou *sinal* for **NULO,** ou *contagem* for 0, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e **NULL** é devolvido.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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
[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](atof-atof-l-wtof-wtof-l.md)<br/>
[_fcvt](fcvt.md)<br/>
[_gcvt](gcvt.md)<br/>
