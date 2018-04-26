---
title: srand | Microsoft Docs
ms.custom: ''
ms.date: 1/02/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
apitype: DLLExport
f1_keywords:
- srand
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a01e56159bf4f04f2c8a53f39e3fcd1e7dd450b5
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="srand"></a>srand

Define o valor de semente inicial para o gerador de números pseudoaleatórios usado pelo **rand** função.

## <a name="syntax"></a>Sintaxe

```C
void srand(
   unsigned int seed
);
```

### <a name="parameters"></a>Parâmetros

*semente* semente para a geração de números pseudoaleatórios

## <a name="remarks"></a>Comentários

O **srand** função define o ponto de partida para gerar uma série de números pseudoaleatórios inteiros no thread atual. Para reinicializar o gerador para criar a mesma sequência de resultados, chame o **srand** de função e usar o mesmo *semente* argumento novamente. Qualquer outro valor para *semente* define o gerador de outro ponto de partida na sequência de números pseudoaleatórios. **RAND** recupera os números pseudoaleatórios que são gerados. Chamando **rand** antes de qualquer chamada para **srand** gera a mesma sequência de chamada **srand** com *semente* passado como 1.

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
