---
title: srand
ms.date: 4/2/2020
api_name:
- srand
- _o_srand
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
- srand
helpviewer_keywords:
- random starting point
- random starting point, setting
- random numbers, generating
- srand function
- numbers, pseudorandom
- numbers, random
- pseudorandom numbers
- starting points, setting random
- starting points
ms.openlocfilehash: a8d018d429b2a484f88b7c1e0679f1f799983910
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355494"
---
# <a name="srand"></a>srand

Define o valor da semente inicial para o gerador de números pseudoaleatório usado pela função **rand.**

## <a name="syntax"></a>Sintaxe

```C
void srand(
   unsigned int seed
);
```

### <a name="parameters"></a>Parâmetros

*seed*<br/>
Semente para geração de números pseudoaleatórios

## <a name="remarks"></a>Comentários

A função **srand** define o ponto de partida para gerar uma série de inteiros pseudoaleatórios no segmento atual. Para reinicializar o gerador para criar a mesma seqüência de resultados, ligue para a função **srand** e use o mesmo argumento *de sementenovamente.* Qualquer outro valor para *sementes* define o gerador para um ponto de partida diferente na seqüência pseudoaleatória. **rand** recupera os números pseudoaleatórios que são gerados. Chamar **rand** antes de qualquer chamada para **srand** gera a mesma seqüência que chamar **srand** com *sementes passadas* como 1.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**srand**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [rand](rand.md).

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Rand](rand.md)<br/>
