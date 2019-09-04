---
title: Funções intrínsecas _InterlockedCompareExchange128
ms.date: 09/02/2019
f1_keywords:
- _InterlockedCompareExchange128_cpp
- _InterlockedCompareExchange128
- _InterlockedCompareExchange128_acq
- _InterlockedCompareExchange128_nf
- _InterlockedCompareExchange128_np
- _InterlockedCompareExchange128_rel
helpviewer_keywords:
- cmpxchg16b instruction
- _InterlockedCompareExchange128 intrinsic
ms.assetid: f05918fc-716a-4f6d-b746-1456d6b96c56
ms.openlocfilehash: 525b0fd77323789eed05c47c944794ff389bfac5
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217695"
---
# <a name="_interlockedcompareexchange128-intrinsic-functions"></a>Funções intrínsecas _InterlockedCompareExchange128

**Seção específica da Microsoft**

Executa uma comparação e um intercâmbio de 128 bits intercadeados.

## <a name="syntax"></a>Sintaxe

```C
unsigned char _InterlockedCompareExchange128(
   __int64 volatile * Destination,
   __int64 ExchangeHigh,
   __int64 ExchangeLow,
   __int64 * ComparandResult
);
unsigned char _InterlockedCompareExchange128_acq(
   __int64 volatile * Destination,
   __int64 ExchangeHigh,
   __int64 ExchangeLow,
   __int64 * ComparandResult
);
unsigned char _InterlockedCompareExchange128_nf(
   __int64 volatile * Destination,
   __int64 ExchangeHigh,
   __int64 ExchangeLow,
   __int64 * ComparandResult
);
unsigned char _InterlockedCompareExchange128_np(
   __int64 volatile * Destination,
   __int64 ExchangeHigh,
   __int64 ExchangeLow,
   __int64 * ComparandResult
);
unsigned char _InterlockedCompareExchange128_rel(
   __int64 volatile * Destination,
   __int64 ExchangeHigh,
   __int64 ExchangeLow,
   __int64 * ComparandResult
);
```

### <a name="parameters"></a>Parâmetros

*Destino*\
[entrada, saída] Ponteiro para o destino, que é uma matriz de inteiros de 2 64 bits considerados como um campo de 128 bits. Os dados de destino devem ter 16 bytes alinhados para evitar uma falha geral de proteção.

*ExchangeHigh*\
no Um inteiro de 64 bits que pode ser trocado com a parte superior do destino.

*ExchangeLow*\
no Um inteiro de 64 bits que pode ser trocado com a parte inferior do destino.

*ComparandResult*\
[entrada, saída] Ponteiro para uma matriz de inteiros de 2 64 bits (considerado um campo de 128 bits) para comparar com o destino.  Na saída, essa matriz é substituída pelo valor original do destino.

## <a name="return-value"></a>Valor retornado

1 se o termo de 128 bits for igual ao valor original do destino. `ExchangeHigh`e `ExchangeLow` substitua o destino de 128 bits.

0 se o termo não for igual ao valor original do destino. O valor do destino é inalterado, e o valor de termo é substituído pelo valor do destino.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_InterlockedCompareExchange128`|x64, ARM64|
|`_InterlockedCompareExchange128_acq`, `_InterlockedCompareExchange128_nf`, `_InterlockedCompareExchange128_rel`|ARM64|
|`_InterlockedCompareExchange128_np`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O `_InterlockedCompareExchange128` intrínseco gera a `cmpxchg16b` instrução (com o `lock` prefixo) para executar uma comparação e o Exchange de 128 bits bloqueados. As versões anteriores do hardware AMD de 64 bits não dão suporte a essa instrução. Para verificar o suporte de hardware para `cmpxchg16b` a instrução, chame `__cpuid` o intrínseco `InfoType=0x00000001 (standard function 1)`com. O bit 13 `CPUInfo[2]` de (ecx) será 1 se houver suporte para a instrução.

> [!NOTE]
> O valor de `ComparandResult` é sempre substituído. Após a `lock` instrução, essa intrínseca copia imediatamente o valor inicial de `Destination` para `ComparandResult`. Por esse motivo, `ComparandResult` e `Destination` deve apontar para locais de memória separados para evitar um comportamento inesperado.

Embora você possa usar `_InterlockedCompareExchange128` para a sincronização de threads de nível baixo, não precisará sincronizar mais de 128 bits se você puder usar funções de sincronização menores ( `_InterlockedCompareExchange` como outras intrínsecas) em vez disso. Use `_InterlockedCompareExchange128` se você quiser acesso atômico a um valor de 128 bits na memória.

Se você executar o código que usa o intrínseco em hardware que não oferece `cmpxchg16b` suporte à instrução, os resultados serão imprevisíveis.

Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. O ARM intrínseco com um `_nf` sufixo ("sem limite") não atua como uma barreira de memória.

Intrínsecos com um sufixo `_np` ("no prefetch") impedem que uma possível operação de pré-busca seja inserida pelo compilador.

Essa rotina está disponível somente como intrínseca.

## <a name="example"></a>Exemplo

Este exemplo usa `_InterlockedCompareExchange128` para substituir a palavra alta de uma matriz de inteiros de 2 64 bits pela soma de suas palavras alta e baixa e incrementar a palavra inferior. O acesso à `BigInt.Int` matriz é atômico, mas este exemplo usa um único thread e ignora o bloqueio para simplificar a simplicidade.

```cpp
// cmpxchg16b.c
// processor: x64
// compile with: /EHsc /O2
#include <stdio.h>
#include <intrin.h>

typedef struct _LARGE_INTEGER_128 {
    __int64 Int[2];
} LARGE_INTEGER_128, *PLARGE_INTEGER_128;

volatile LARGE_INTEGER_128 BigInt;

// This AtomicOp() function atomically performs:
//   BigInt.Int[1] += BigInt.Int[0]
//   BigInt.Int[0] += 1
void AtomicOp ()
{
    LARGE_INTEGER_128 Comparand;
    Comparand.Int[0] = BigInt.Int[0];
    Comparand.Int[1] = BigInt.Int[1];
    do {
        ; // nothing
    } while (_InterlockedCompareExchange128(BigInt.Int,
                                            Comparand.Int[0] + Comparand.Int[1],
                                            Comparand.Int[0] + 1,
                                            Comparand.Int) == 0);
}

// In a real application, several threads contend for the value
// of BigInt.
// Here we focus on the compare and exchange for simplicity.
int main(void)
{
   BigInt.Int[1] = 23;
   BigInt.Int[0] = 11;
   AtomicOp();
   printf("BigInt.Int[1] = %d, BigInt.Int[0] = %d\n",
      BigInt.Int[1],BigInt.Int[0]);
}
```

```Output
BigInt.Int[1] = 34, BigInt.Int[0] = 12
```

**Fim da seção específica da Microsoft**


## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Funções intrínsecas _InterlockedCompareExchange](../intrinsics/interlockedcompareexchange-intrinsic-functions.md)\
[conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)
