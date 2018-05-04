---
title: _clear87, _clearfp | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- clearing floating point status word
- clearfp function
- _clear87 function
- _clearfp function
- clear87 function
ms.assetid: 72d24a70-7688-4793-ae09-c96d33fcca52
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 195bd9f78ed9edfa47ec9ebbd2babbee676e5644
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="clear87-clearfp"></a>_clear87, _clearfp

Obtém e limpa a palavra de status de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
unsigned int _clear87( void );
unsigned int _clearfp( void );
```

## <a name="return-value"></a>Valor de retorno

Os bits no valor retornado indicam o status de ponto flutuante antes da chamada para **clear87** ou **clearfp**. Para obter uma definição completa dos bits retornado por **clear87**, consulte float. h. Muitas das funções de biblioteca de matemática modificam a palavra de status 8087/80287, com resultados imprevisíveis. Retornar valores de **clear87** e **status87** se tornam mais confiável conforme menos operações de ponto flutuantes são executadas entre estados conhecidos da palavra de status de ponto flutuante.

## <a name="remarks"></a>Comentários

O **clear87** função limpa os sinalizadores de exceção da palavra de status de ponto flutuante, define o bit ocupado como 0 e retorna a palavra de status. A palavra de status de ponto flutuante é uma combinação da palavra de status 8087/80287 e outras condições detectadas pelo manipulador de exceção 8087/80287, como estouro e estouro negativo de pilha de ponto flutuante.

**clearfp** é uma versão independente de plataforma e portátil do **clear87** rotina. Ele é idêntico ao **clear87** em plataformas Intel (x86) e também é suportado por plataformas ARM e x64. Para garantir que seu código de ponto flutuante é portátil para x64 e ARM, use **clearfp**. Se sua meta for apenas x86 plataformas, você pode usar o **clear87** ou **clearfp**.

Essas funções são substituídas durante a compilação com [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) porque o common language runtime suporta apenas a precisão de ponto flutuante padrão.

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
