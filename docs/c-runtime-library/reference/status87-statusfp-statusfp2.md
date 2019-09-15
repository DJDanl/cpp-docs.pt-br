---
title: _status87, _statusfp, _statusfp2
ms.date: 04/05/2018
api_name:
- _statusfp2
- _statusfp
- _status87
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
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _statusfp2
- _statusfp
- statusfp2
- _status87
- status87
- statusfp
helpviewer_keywords:
- floating-point functions, getting status word
- floating-point numbers, status word
- status87 function
- status word, getting floating point
- statusfp function
- _statusfp function
- _statusfp2 function
- statusfp2 function
- _status87 function
- floating-point functions
- status word
ms.assetid: 7ef963fa-b1fb-429d-94d6-fbf282ab7432
ms.openlocfilehash: 54faf70296ef41f2682f88a8edaa82ee0d2071d4
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70958086"
---
# <a name="_status87-_statusfp-_statusfp2"></a>_status87, _statusfp, _statusfp2

Obtém a palavra de status de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
unsigned int _status87( void );
unsigned int _statusfp( void );
void _statusfp2(unsigned int *px86, unsigned int *pSSE2)
```

### <a name="parameters"></a>Parâmetros

*px86*<br/>
Esse endereço é preenchido com a palavra de status para a unidade de ponto flutuante x87.

*pSSE2*<br/>
Esse endereço é preenchido com a palavra de status para a unidade de ponto flutuante SSE2.

## <a name="return-value"></a>Valor de retorno

Para **_status87** e **_statusfp**, os bits no valor retornado indicam o status de ponto flutuante. Consulte o FLOAT. H incluir arquivo para uma definição dos bits retornados por **_statusfp**. Muitas funções de biblioteca de matemática modificam a palavra de status de ponto flutuante, com resultados imprevisíveis. A otimização pode reordenar, combinar e eliminar operações de ponto flutuante em chamadas para **_status87**, **_statusfp**e funções relacionadas. Use a opção do compilador [/Od (Desabilitar (Depurar))](../../build/reference/od-disable-debug.md) ou a diretiva pragma [fenv_access](../../preprocessor/fenv-access.md) para impedir otimizações que reordenem as operações de ponto flutuante. Valores de retorno de **_clearfp** e **_statusfp**, e também os parâmetros de retorno de **_statusfp2**, são mais confiáveis se menos operações de ponto flutuante forem executadas entre os Estados conhecidos da palavra de status de ponto flutuante.

## <a name="remarks"></a>Comentários

A função **_statusfp** Obtém a palavra de status de ponto flutuante. A palavra de status é uma combinação do status do processador de ponto flutuante e outras condições detectadas pelo manipulador de exceção de ponto flutuante – por exemplo, estouro positivo e negativo de pilha de ponto flutuante. Exceções sem máscara são verificadas antes de o conteúdo da palavra de status ser retornado. Isso significa que o chamador é informado sobre exceções pendentes. Em plataformas x86, **_statusfp** retorna uma combinação do status de ponto flutuante x87 e SSE2. Em plataformas x64, o status retornado é baseado no status MXCSR do SSE. Em plataformas ARM, **_statusfp** retorna o status do registro FPSCR.

**_statusfp** é uma versão portátil e independente de plataforma do **_status87**. Ele é idêntico ao **_status87** em plataformas Intel (x86) e também é compatível com as plataformas x64 e ARM. Para garantir que seu código de ponto flutuante seja portátil para todas as arquiteturas, use **_statusfp**. Se você estiver direcionando apenas para plataformas x86, poderá usar **_status87** ou **_statusfp**.

Recomendamos **_statusfp2** para chips (como o Pentium IV) que têm um x87 e um processador de ponto flutuante SSE2. Para **_statusfp2**, os endereços são preenchidos usando a palavra de status de ponto flutuante para o processador de ponto flutuante x87 ou SSE2. Para um chip que dá suporte a processadores de ponto flutuante x87 e SSE2, EM_AMBIGUOUS é definido como 1 se **_statusfp** ou **_controlfp** for usado e a ação for ambígua porque ela poderia se referir ao x87 ou à palavra de status de ponto flutuante SSE2. A função **_statusfp2** só tem suporte em plataformas x86.

Essas funções não são úteis para a [compilação/CLR (Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md) porque o Common Language Runtime (CLR) só dá suporte à precisão de ponto flutuante padrão.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_status87**, **_statusfp**, **_statusfp2**|\<float.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_statusfp.c
// Build by using: cl /W4 /Ox /nologo crt_statusfp.c
// This program creates various floating-point errors and
// then uses _statusfp to display messages that indicate these problems.

#include <stdio.h>
#include <float.h>
#pragma fenv_access(on)

double test( void )
{
   double a = 1e-40;
   float b;
   double c;

   printf("Status = 0x%.8x - clear\n", _statusfp());

   // Assignment into b is inexact & underflows:
   b = (float)(a + 1e-40);
   printf("Status = 0x%.8x - inexact, underflow\n", _statusfp());

   // c is denormal:
   c = b / 2.0;
   printf("Status = 0x%.8x - inexact, underflow, denormal\n",
            _statusfp());

   // Clear floating point status:
   _clearfp();
   return c;
}

int main(void)
{
   return (int)test();
}
```

```Output
Status = 0x00000000 - clear
Status = 0x00000003 - inexact, underflow
Status = 0x00080003 - inexact, underflow, denormal
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_clear87, _clearfp](clear87-clearfp.md)<br/>
[_control87, _controlfp, \__control87_2](control87-controlfp-control87-2.md)<br/>
