---
title: _clear87, _clearfp
ms.date: 04/05/2018
apiname:
- _clearfp
- _clear87
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- clearfp
- _clearfp
- _clear87
- clear87
helpviewer_keywords:
- clearing floating point status word
- clearfp function
- _clear87 function
- _clearfp function
- clear87 function
ms.assetid: 72d24a70-7688-4793-ae09-c96d33fcca52
ms.openlocfilehash: 4148f85d82a4210033686455c73046081832e3c4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477253"
---
# <a name="clear87-clearfp"></a>_clear87, _clearfp

Obtém e limpa a palavra de status de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
unsigned int _clear87( void );
unsigned int _clearfp( void );
```

## <a name="return-value"></a>Valor de retorno

Os bits no valor retornado indicam o status de ponto flutuante antes da chamada para **_clear87** ou **clearfp**. Para obter uma definição completa dos bits retornados por **_clear87**, consulte float. h. Muitas das funções de biblioteca de matemática modificam a palavra de status 8087/80287, com resultados imprevisíveis. Valores de retorno de **_clear87** e **_status87** se tornar mais confiáveis conforme menos operações de ponto flutuantes são executadas entre estados conhecidos da palavra de status de ponto flutuante.

## <a name="remarks"></a>Comentários

O **_clear87** função limpa os sinalizadores de exceção na palavra de status de ponto flutuante, define o bit ocupado como 0 e retorna a palavra de status. A palavra de status de ponto flutuante é uma combinação da palavra de status 8087/80287 e outras condições detectadas pelo manipulador de exceção 8087/80287, como estouro e estouro negativo de pilha de ponto flutuante.

**clearfp** é uma versão portátil, independente de plataforma do **_clear87** rotina. Ela é idêntica à **_clear87** em plataformas Intel (x86) e também dá suporte a plataformas x64 e ARM. Para garantir que seu código de ponto flutuante seja portátil para x64 e ARM, use **clearfp**. Se você estiver direcionando apenas x86 plataformas, você pode usar tanto **_clear87** ou **clearfp**.

Essas funções foram preteridas ao compilar com [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) porque o common language runtime dá suporte apenas a precisão de ponto flutuante padrão.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_clear87**|\<float.h>|
|**_clearfp**|\<float.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_clear87.c
// compile with: /Od

// This program creates various floating-point
// problems, then uses _clear87 to report on these problems.
// Compile this program with Optimizations disabled (/Od).
// Otherwise the optimizer will remove the code associated with
// the unused floating-point values.
//

#include <stdio.h>
#include <float.h>

int main( void )
{
   double a = 1e-40, b;
   float x, y;

   printf( "Status: %.4x - clear\n", _clear87()  );

   // Store into y is inexact and underflows:
   y = a;
   printf( "Status: %.4x - inexact, underflow\n", _clear87() );

   // y is denormal:
   b = y;
   printf( "Status: %.4x - denormal\n", _clear87() );
}
```

```Output
Status: 0000 - clear
Status: 0003 - inexact, underflow
Status: 80000 - denormal
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_control87, _controlfp, \__control87_2](control87-controlfp-control87-2.md)<br/>
[_status87, _statusfp, _statusfp2](status87-statusfp-statusfp2.md)<br/>
