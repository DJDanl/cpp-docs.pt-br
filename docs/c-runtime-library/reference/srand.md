---
title: srand
ms.date: 01/02/2018
apiname:
- srand
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
- api-ms-win-crt-utility-l1-1-0.dll
- ntoskrnl.exe
apitype: DLLExport
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
ms.openlocfilehash: d74ae4cbec5a76df48bb2b56acab7329e6cf8aa5
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70927412"
---
# <a name="srand"></a>srand

Define o valor de semente inicial para o gerador de número pseudoaleatória usado pela função **Rand** .

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

A função **srand** define o ponto de partida para gerar uma série de inteiros de pseudoaleatória no thread atual. Para reinicializar o gerador para criar a mesma sequência de resultados, chame a função **srand** e use o mesmo argumento de *semente* novamente. Qualquer outro valor para *Seed* define o gerador para um ponto de partida diferente na sequência pseudoaleatória. **Rand** recupera os números de pseudoaleatória que são gerados. Chamar **Rand** antes de qualquer chamada para **srand** gera a mesma sequência que chamar **srand** com a *semente* passada como 1.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**srand**|\<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [rand](rand.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[rand](rand.md)<br/>
