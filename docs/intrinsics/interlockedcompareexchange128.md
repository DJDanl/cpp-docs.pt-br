---
title: _InterlockedCompareExchange128 funções intrínsecas
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
ms.openlocfilehash: 6f6b36b238945f7d46e9817cdc85977d666e1e9b
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077621"
---
# <a name="_interlockedcompareexchange128-intrinsic-functions"></a>_InterlockedCompareExchange128 funções intrínsecas

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

### <a name="parameters"></a>parâmetros

\ de *destino*
[entrada, saída] Ponteiro para o destino, que é uma matriz de inteiros de 2 64 bits considerados como um campo de 128 bits. Os dados de destino devem ter 16 bytes alinhados para evitar uma falha geral de proteção.

\ *ExchangeHigh*
no Um inteiro de 64 bits que pode ser trocado com a parte superior do destino.

\ *ExchangeLow*
no Um inteiro de 64 bits que pode ser trocado com a parte inferior do destino.

\ *ComparandResult*
[entrada, saída] Ponteiro para uma matriz de inteiros de 2 64 bits (considerado um campo de 128 bits) para comparar com o destino.  Na saída, essa matriz é substituída pelo valor original do destino.

## <a name="return-value"></a>Valor retornado

1 se o termo de 128 bits for igual ao valor original do destino. `ExchangeHigh` e `ExchangeLow` substituir o destino de 128 bits.

0 se o termo não for igual ao valor original do destino. O valor do destino é inalterado, e o valor de termo é substituído pelo valor do destino.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|`_InterlockedCompareExchange128`|x64, ARM64|
|`_InterlockedCompareExchange128_acq`, `_InterlockedCompareExchange128_nf`, `_InterlockedCompareExchange128_rel`|ARM64|
|`_InterlockedCompareExchange128_np`|x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O `_InterlockedCompareExchange128` intrínseco gera a instrução `cmpxchg16b` (com o prefixo de `lock`) para executar uma comparação e um troca de 128 bits bloqueados. As versões anteriores do hardware AMD de 64 bits não dão suporte a essa instrução. Para verificar o suporte de hardware para a instrução `cmpxchg16b`, chame o `__cpuid` intrínseco com `InfoType=0x00000001 (standard function 1)`. O bit 13 de `CPUInfo[2]` (ECX) será 1 se houver suporte para a instrução.

> [!NOTE]
> O valor de `ComparandResult` é sempre substituído. Após a instrução de `lock`, essa intrínseca copia imediatamente o valor inicial de `Destination` para `ComparandResult`. Por esse motivo, `ComparandResult` e `Destination` devem apontar para locais de memória separados para evitar um comportamento inesperado.

Embora você possa usar `_InterlockedCompareExchange128` para a sincronização de threads de nível baixo, não será necessário sincronizar mais de 128 bits se você puder usar funções de sincronização menores (como a outra `_InterlockedCompareExchange` intrínsecas). Use `_InterlockedCompareExchange128` se você quiser acesso atômico a um valor de 128 bits na memória.

Se você executar o código que usa o intrínseco em hardware que não dá suporte à instrução `cmpxchg16b`, os resultados serão imprevisíveis.

Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. O ARM intrínseco com um sufixo de `_nf` ("sem limite") não atua como uma barreira de memória.

Intrínsecos com um sufixo `_np` ("no prefetch") impedem que uma possível operação de pré-busca seja inserida pelo compilador.

Essa rotina está disponível somente como intrínseca.

## <a name="example"></a>Exemplo

Este exemplo usa `_InterlockedCompareExchange128` para substituir a palavra alta de uma matriz de inteiros de 2 64 bits pela soma de suas palavras alta e baixa e incrementar a palavra inferior. O acesso à matriz de `BigInt.Int` é atômico, mas este exemplo usa um único thread e ignora o bloqueio para simplificar a simplicidade.

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

## <a name="see-also"></a>Confira também

\ [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
[_InterlockedCompareExchange funções intrínsecas](../intrinsics/interlockedcompareexchange-intrinsic-functions.md)\
[conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)
