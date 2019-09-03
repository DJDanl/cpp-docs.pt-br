---
title: __faststorefence
ms.date: 09/02/2019
f1_keywords:
- __faststorefence_cpp
- __faststorefence
helpviewer_keywords:
- __faststorefence intrinsic
- sfence instruction
ms.assetid: 6c6eb973-3cf0-4306-b3af-cfde9b0210a5
ms.openlocfilehash: d11a20666612fe1bca22f5d46b93e898dae375f6
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222183"
---
# <a name="__faststorefence"></a>__faststorefence

**Seção específica da Microsoft**

Garante que cada referência de memória anterior, incluindo as referências de memória de carga e armazenamento, seja globalmente visível antes de qualquer referência de memória subsequente.

## <a name="syntax"></a>Sintaxe

```C
void __faststorefence();
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__faststorefence`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Gera uma sequência de instrução de barreira de memória completa que garante que as operações de carregamento e armazenamento emitidas antes do intrínseco são visíveis globalmente antes de a execução continuar. O efeito é comparável a, mas mais rápido `_mm_mfence` do que o intrínseco em todas as plataformas x64.

Na plataforma AMD64, essa rotina gera uma instrução que é um limite de armazenamento mais rápido do `sfence` que a instrução. Para código de tempo crítico, use essa intrínseca em vez `_mm_sfence` de apenas em plataformas AMD64. Em plataformas Intel x64, a `_mm_sfence` instrução é mais rápida.

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
