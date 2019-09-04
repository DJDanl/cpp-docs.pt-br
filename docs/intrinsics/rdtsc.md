---
title: __rdtsc
ms.date: 09/02/2019
f1_keywords:
- __rdtsc
helpviewer_keywords:
- __rdtsc intrinsic
- rdtsc instruction
- Read Time Stamp Counter instruction
ms.assetid: e31d0e51-c9bb-42ca-bbe9-a81ffe662387
ms.openlocfilehash: 837b68ca6ac63587cd43a7e8828777221c677e3c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217143"
---
# <a name="__rdtsc"></a>__rdtsc

**Seção específica da Microsoft**

Gera a `rdtsc` instrução, que retorna o carimbo de data/hora do processador. O carimbo de data/hora do processador registra o número de ciclos de relógio desde a última redefinição.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __rdtsc();
```

## <a name="return-value"></a>Valor retornado

Um inteiro sem sinal de 64 bits que representa uma contagem em escala.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__rdtsc`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essa rotina está disponível somente como intrínseca.

A interpretação do valor de TSC em gerações posteriores de hardware é diferente daquela em versões anteriores do x64. Para obter mais informações, consulte os manuais de hardware.

## <a name="example"></a>Exemplo

```cpp
// rdtsc.cpp
// processor: x86, x64
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(__rdtsc)

int main()
{
    unsigned __int64 i;
    i = __rdtsc();
    printf_s("%I64d ticks\n", i);
}
```

```Output
3363423610155519 ticks
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
