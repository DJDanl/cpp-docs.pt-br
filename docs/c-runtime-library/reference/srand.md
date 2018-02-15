---
title: srand | Microsoft Docs
ms.custom: 
ms.date: 1/02/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
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
ms.openlocfilehash: 4cc76b80ca6c01d6512c69cc13fb0934e79b6ae5
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="srand"></a>srand

Define o valor de semente inicial para o gerador de números pseudoaleatórios usado pelo `rand` função.

## <a name="syntax"></a>Sintaxe

```C
void srand(
   unsigned int seed
);
```

### <a name="parameters"></a>Parâmetros

*seed*  
Semente para geração de números pseudoaleatórios

## <a name="remarks"></a>Comentários

A função `srand` define o ponto de partida para gerar uma série de inteiros pseudoaleatórios no thread atual. Para reinicializar o gerador para criar a mesma sequência de resultados, chame o `srand` de função e usar o mesmo *semente* argumento novamente. Qualquer outro valor para *semente* define o gerador de outro ponto de partida na sequência de números pseudoaleatórios. `rand` recupera os números pseudoaleatórios que são gerados. Chamando `rand` antes de qualquer chamada para `srand` gera a mesma sequência de chamada `srand` com *semente* passado como 1.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`srand`|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.

## <a name="example"></a>Exemplo

Veja o exemplo de [rand](../../c-runtime-library/reference/rand.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)  
[rand](../../c-runtime-library/reference/rand.md)  
