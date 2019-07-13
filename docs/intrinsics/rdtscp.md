---
title: __rdtscp
ms.date: 07/11/2019
f1_keywords:
- __rdtscp
helpviewer_keywords:
- rdtscp intrinsic
- __rdtscp intrinsic
- rdtscp instruction
ms.assetid: f17d9a9c-88bb-44e0-b69d-d516bc1c93ee
ms.openlocfilehash: b8a31c6d19cd171cbe909c75a27c2389866bd578
ms.sourcegitcommit: 0e3da5cea44437c132b5c2ea522bd229ea000a10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/12/2019
ms.locfileid: "67861097"
---
# <a name="rdtscp"></a>__rdtscp

**Seção específica da Microsoft**

Gera o `rdtscp` instrução, grava `TSC_AUX[31:0`] à memória e retorna o contador de carimbo de data / hora 64-bit (`TSC)` resultado.

## <a name="syntax"></a>Sintaxe

```
unsigned __int64 __rdtscp(
   unsigned int * Aux
);
```

#### <a name="parameters"></a>Parâmetros

*Aux*<br/>
[out] Ponteiro para um local que conterá o conteúdo do registro específicas do computador `TSC_AUX[31:0]`.

## <a name="return-value"></a>Valor de retorno

Uma contagem de tiques do inteiro sem sinal de 64 bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__rdtscp`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco gera o `rdtscp` instrução. Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseco com `InfoType=0x80000001` e marque pouco 27 de `CPUInfo[3] (EDX)`. Esse bit é 1 se a instrução for compatível e 0, caso contrário.  Se você executar o código que usa esse intrínseco no hardware que não oferece suporte a `rdtscp` instrução, os resultados serão imprevisíveis.

Essa instrução aguarda até que todas as instruções anteriores foram executadas e todos os carregamentos anteriores são visíveis globalmente. No entanto, não é uma instrução de serialização. Consulte os manuais Intel e AMD, para obter mais informações.

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

[__rdtsc](../intrinsics/rdtsc.md)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)