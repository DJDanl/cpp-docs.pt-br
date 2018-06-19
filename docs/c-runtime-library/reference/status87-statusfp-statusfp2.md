---
title: _status87, _statusfp, _statusfp2 | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 69297d7ff1e3ec40cfe4fc22dec86c356d1697d4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32412550"
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

Para **status87** e **statusfp**, os bits no valor retornado indicam o status de ponto flutuante. Consulte o FLOAT. H incluir arquivo para uma definição dos bits que são retornados pelo **statusfp**. Muitas funções de biblioteca de matemática modificam a palavra de status de ponto flutuante, com resultados imprevisíveis. Otimização pode reordenar, combinar e eliminar as operações de ponto flutuante em chamadas para **status87**, **statusfp**e funções relacionadas. Use a opção do compilador [/Od (Desabilitar (Depurar))](../../build/reference/od-disable-debug.md) ou a diretiva pragma [fenv_access](../../preprocessor/fenv-access.md) para impedir otimizações que reordenem as operações de ponto flutuante. Retornar valores de **clearfp** e **statusfp**e também os parâmetros de retorno de **statusfp2**, são mais confiáveis se menos operações de ponto flutuantes são executadas entre os estados conhecidos da palavra de status de ponto flutuante.

## <a name="remarks"></a>Comentários

O **statusfp** função obtém a palavra de status de ponto flutuante. A palavra de status é uma combinação do status do processador de ponto flutuante e outras condições detectadas pelo manipulador de exceção de ponto flutuante – por exemplo, estouro positivo e negativo de pilha de ponto flutuante. Exceções sem máscara são verificadas antes de o conteúdo da palavra de status ser retornado. Isso significa que o chamador é informado sobre exceções pendentes. X86 plataformas, **statusfp** retorna uma combinação da x87 e status de ponto flutuante SSE2. Em plataformas x64, o status retornado é baseado no status MXCSR do SSE. Em plataformas ARM **statusfp** retorna o status do registro FPSCR.

**statusfp** é uma versão independente de plataforma e portátil do **status87**. Ele é idêntico ao **status87** em plataformas Intel (x86) e também é suportado por plataformas ARM e x64. Para garantir que seu código de ponto flutuante é portátil para todas as arquiteturas, use **statusfp**. Se sua meta for apenas x86 plataformas, você pode usar o **status87** ou **statusfp**.

É recomendável **statusfp2** para chips (como Pentium IV) que têm um x87 e um processador de ponto flutuante SSE2. Para **statusfp2**, os endereços são preenchidos para o x87 ou o processador de ponto flutuante SSE2 usando a palavra de status de ponto flutuante. Para um chip que dá suporte a x87 e processadores de ponto flutuantes SSE2, EM_AMBIGUOUS é definido como 1 se **statusfp** ou **controlfp** é usado e a ação foi ambígua porque ela pode se referir a x87 ou o SSE2 palavra de status de ponto flutuante. O **statusfp2** x86 somente oferece suporte a função plataformas.

Essas funções não são úteis para [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) porque o common language runtime (CLR) suporta apenas a precisão de ponto flutuante padrão.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**status87**, **statusfp**, **statusfp2**|\<float.h>|

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
