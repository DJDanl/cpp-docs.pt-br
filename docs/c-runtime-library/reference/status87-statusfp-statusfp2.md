---
title: _status87, _statusfp, _statusfp2
ms.date: 04/05/2018
apiname:
- _statusfp2
- _statusfp
- _status87
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
ms.openlocfilehash: 271c28dd4e267e5b3b702858cc398689e3e35d6f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50597506"
---
# <a name="status87-statusfp-statusfp2"></a>_status87, _statusfp, _statusfp2

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

Para **_status87** e **statusfp**, os bits no valor retornado indicam o status de ponto flutuante. Consulte o FLOAT. H incluir arquivo para obter uma definição dos bits retornados por **statusfp**. Muitas funções de biblioteca de matemática modificam a palavra de status de ponto flutuante, com resultados imprevisíveis. Otimização pode reordenar, combinar e eliminar as operações de ponto flutuantes em torno das chamadas para **_status87**, **statusfp**e funções relacionadas. Use a opção do compilador [/Od (Desabilitar (Depurar))](../../build/reference/od-disable-debug.md) ou a diretiva pragma [fenv_access](../../preprocessor/fenv-access.md) para impedir otimizações que reordenem as operações de ponto flutuante. Valores de retorno de **clearfp** e **statusfp**e também os parâmetros de retorno **_statusfp2**, são mais confiáveis se menos operações de ponto flutuantes são executadas entre estados conhecidos da palavra de status de ponto flutuante.

## <a name="remarks"></a>Comentários

O **statusfp** função obtém a palavra de status de ponto flutuante. A palavra de status é uma combinação do status do processador de ponto flutuante e outras condições detectadas pelo manipulador de exceção de ponto flutuante – por exemplo, estouro positivo e negativo de pilha de ponto flutuante. Exceções sem máscara são verificadas antes de o conteúdo da palavra de status ser retornado. Isso significa que o chamador é informado sobre exceções pendentes. Em x86 plataformas **statusfp** retorna uma combinação do x87 e status de ponto flutuante SSE2. Em plataformas x64, o status retornado é baseado no status MXCSR do SSE. Em plataformas ARM **statusfp** retorna o status do registro fpscr.

**statusfp** é uma versão portátil, independente de plataforma do **_status87**. Ela é idêntica à **_status87** em plataformas Intel (x86) e também dá suporte a plataformas x64 e ARM. Para garantir que seu código de ponto flutuante seja portátil para todas as arquiteturas, use **statusfp**. Se você estiver direcionando apenas x86 plataformas, você pode usar tanto **_status87** ou **statusfp**.

É recomendável **_statusfp2** para chips (como Pentium IV) que têm um x87 e um processador de ponto flutuante SSE2. Para **_statusfp2**, os endereços são preenchidos pelo uso da palavra de status de ponto flutuante para o processador de ponto flutuante SSE2 ou x87. Para um chip que dá suporte a x87 e processadores de ponto flutuantes SSE2, EM_AMBIGUOUS é definido como 1 se **statusfp** ou **controlfp** é usado e a ação foi ambígua porque ela pode se referir do SSE2 ou x87 palavra de status de ponto flutuante. O **_statusfp2** função só é compatível com x86 plataformas.

Essas funções não são úteis para [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) porque o common language runtime (CLR) dá suporte apenas a precisão de ponto flutuante padrão.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_status87**, **statusfp**, **_statusfp2**|\<float.h>|

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
