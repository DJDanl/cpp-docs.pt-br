---
title: __rdtscp
ms.date: 09/02/2019
f1_keywords:
- __rdtscp
helpviewer_keywords:
- rdtscp intrinsic
- __rdtscp intrinsic
- rdtscp instruction
ms.assetid: f17d9a9c-88bb-44e0-b69d-d516bc1c93ee
ms.openlocfilehash: 4dcabd6ed0f7fb3f422927815cbdc91f2b4b9d43
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221313"
---
# <a name="__rdtscp"></a>__rdtscp

**Seção específica da Microsoft**

Gera a `rdtscp` instrução, grava `TSC_AUX[31:0`] na memória e retorna o contador de carimbo de data/hora de`TSC)` 64 bits (resultado.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __rdtscp(
   unsigned int * AUX
);
```

### <a name="parameters"></a>Parâmetros

*INDICAÇÃO*\
fora Ponteiro para um local que conterá o conteúdo do registro `TSC_AUX[31:0]`específico do computador.

## <a name="return-value"></a>Valor retornado

Uma contagem de tiques de inteiros sem sinal de 64 bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__rdtscp`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O `__rdtscp` intrínseco gera a `rdtscp` instrução. Para determinar o suporte de hardware para essa instrução, `__cpuid` chame o `InfoType=0x80000001` intrínseco e verifique o bit `CPUInfo[3] (EDX)`27 de. Esse bit será 1 se a instrução tiver suporte e 0 caso contrário.  Se você executar o código que usa o intrínseco em hardware que não oferece `rdtscp` suporte à instrução, os resultados serão imprevisíveis.

Essa instrução aguarda até que todas as instruções anteriores sejam executadas e todas as cargas anteriores sejam visíveis globalmente. No entanto, não é uma instrução de serialização. Para obter mais informações, consulte os manuais Intel e AMD.

O significado do valor em `TSC_AUX[31:0]` depende do sistema operacional.

## <a name="example"></a>Exemplo

```cpp
#include <intrin.h>
#include <stdio.h>
int main()
{
    unsigned __int64 i;
    unsigned int ui;
    i = __rdtscp(&ui);
    printf_s("%I64d ticks\n", i);
    printf_s("TSC_AUX was %x\n", ui);
}
```

```Output
3363423610155519 ticks
TSC_AUX was 0
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__rdtsc](../intrinsics/rdtsc.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
