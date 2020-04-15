---
title: rand
ms.date: 4/2/2020
api_name:
- rand
- _o_rand
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
- api-ms-win-crt-utility-l1-1-0.dll
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- rand
helpviewer_keywords:
- generating pseudorandom numbers
- random numbers, generating
- numbers, pseudorandom
- rand function
- pseudorandom numbers
- numbers, generating pseudorandom
ms.openlocfilehash: 944c512d0102b459afc2924ef7515311e46cd43c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338159"
---
# <a name="rand"></a>rand

Gera um número pseudoaleatório usando um algoritmo bem conhecido e totalmente reprodutível. Uma versão mais programática mente segura desta função está disponível; veja [rand_s](rand-s.md). Os números gerados pelo **rand** não são criptograficamente seguros. Para uma geração de números aleatórios mais seguras criptograficamente, use [rand_s](rand-s.md) ou as funções declaradas na Biblioteca Padrão C++ em [ \<>aleatórias ](../../standard-library/random.md).

## <a name="syntax"></a>Sintaxe

```C
int rand( void );
```

## <a name="return-value"></a>Valor retornado

**rand** retorna um número pseudoaleatório, como descrito acima. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

A função **rand** retorna um inteiro pseudoaleatório na faixa 0 a **RAND_MAX** (32767). Use a função [srand](srand.md) para semear o gerador de número pseudoaleatório antes de chamar **rand**.

A função **rand** gera uma seqüência bem conhecida e não é apropriada para uso como função criptográfica. Para uma geração de números aleatórios mais seguras criptograficamente, use [rand_s](rand-s.md) ou as funções declaradas na Biblioteca Padrão C++ em [ \<>aleatórias ](../../standard-library/random.md). Para obter informações sobre o que \<há de errado com **o rand** e como> aleatórios abordam essas deficiências, consulte este vídeo intitulado [rand Considerado Prejudicial](https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Rand**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_rand.c
// This program seeds the random-number generator
// with the time, then exercises the rand function.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void SimpleRandDemo( int n )
{
   // Print n random numbers.
   int i;
   for( i = 0; i < n; i++ )
      printf( "  %6d\n", rand() );
}

void RangedRandDemo( int range_min, int range_max, int n )
{
   // Generate random numbers in the half-closed interval
   // [range_min, range_max). In other words,
   // range_min <= random number < range_max
   int i;
   for ( i = 0; i < n; i++ )
   {
      int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
            + range_min;
      printf( "  %6d\n", u);
   }
}

int main( void )
{
   // Seed the random-number generator with the current time so that
   // the numbers will be different every time we run.
   srand( (unsigned)time( NULL ) );

   SimpleRandDemo( 10 );
   printf("\n");
   RangedRandDemo( -100, 100, 10 );
}
```

```Output
22036
18330
11651
27464
18093
3284
11785
14686
11447
11285

   74
   48
   27
   65
   96
   64
   -5
  -42
  -55
   66
```

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[srand](srand.md)<br/>
[rand_s](rand-s.md)<br/>
