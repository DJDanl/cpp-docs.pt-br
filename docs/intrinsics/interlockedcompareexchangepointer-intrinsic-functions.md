---
title: Funções intrínsecas _InterlockedCompareExchangePointer
ms.date: 09/02/2019
f1_keywords:
- _InterlockedCompareExchangePointer_HLERelease
- _InterlockedCompareExchangePointer_rel
- _InterlockedCompareExchangePointer_acq_cpp
- _InterlockedCompareExchangePointer
- _InterlockedCompareExchangePointer_cpp
- _InterlockedCompareExchangePointer_np
- _InterlockedCompareExchangePointer_rel_cpp
- _InterlockedCompareExchangePointer_HLEAcquire
- _InterlockedCompareExchangePointer_acq
- _InterlockedCompareExchangePointer_nf
helpviewer_keywords:
- InterlockedCompareExchangePointer_acq intrinsic
- _InterlockedCompareExchangePointer_rel intrinsic
- _InterlockedCompareExchangePointer_acq intrinsic
- InterlockedCompareExchangePointer_rel intrinsic
- InterlockedCompareExchangePointer intrinsic
- _InterlockedCompareExchangePointer_HLERelease intrinsic
- _InterlockedCompareExchangePointer_HLEAcquire intrinsic
- _InterlockedCompareExchangePointer intrinsic
- _InterlockedCompareExchangePointer_nf intrinsic
- _InterlockedCompareExchangePointer_np intrinsic
ms.assetid: 97fde59d-2bf9-42aa-a0fe-a5b6befdd44b
ms.openlocfilehash: c0a0083c19df51d2d2eccb7a7bbf6521303c1f85
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222043"
---
# <a name="_interlockedcompareexchangepointer-intrinsic-functions"></a>Funções intrínsecas _InterlockedCompareExchangePointer

**Seção específica da Microsoft**

Executa uma operação atômica que armazena o endereço do `Exchange` no endereço `Destination` se os endereços `Comparand` e `Destination` forem iguais.

## <a name="syntax"></a>Sintaxe

```C
void * _InterlockedCompareExchangePointer (
   void * volatile * Destination,
   void * Exchange,
   void * Comparand
);
void * _InterlockedCompareExchangePointer_acq (
   void * volatile * Destination,
   void * Exchange,
   void * Comparand
);
void * _InterlockedCompareExchangePointer_HLEAcquire (
   void * volatile * Destination,
   void * Exchange,
   void * Comparand
);
void * _InterlockedCompareExchangePointer_HLERelease (
   void * volatile * Destination,
   void * Exchange,
   void * Comparand
);
void * _InterlockedCompareExchangePointer_nf (
   void * volatile * Destination,
   void * Exchange,
   void * Comparand
);
void * _InterlockedCompareExchangePointer_np (
   void * volatile * Destination,
   void * Exchange,
   void * Comparand
);
long _InterlockedCompareExchangePointer_rel (
   void * volatile * Destination,
   void * Exchange,
   void * Comparand
);
```

### <a name="parameters"></a>Parâmetros

*Destino*\
[entrada, saída] Ponteiro para um ponteiro para o valor de destino. O sinal é ignorado.

*Transferência*\
no Ponteiro do Exchange. O sinal é ignorado.

*Termo*\
no Ponteiro para comparar com o destino. O sinal é ignorado.

## <a name="return-value"></a>Valor retornado

O valor de retorno é o valor inicial do destino.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_InterlockedCompareExchangePointer`|x86, ARM, x64, ARM64|\<intrin.h>|
|`_InterlockedCompareExchangePointer_acq`, `_InterlockedCompareExchangePointer_nf`, `_InterlockedCompareExchangePointer_rel`|ARM, ARM64|\<iiintrin.h>|
|`_InterlockedCompareExchangePointer_HLEAcquire`, `_InterlockedCompareExchangePointer_HLERelease`|x86, x64|\<immintrin.h>|

## <a name="remarks"></a>Comentários

`_InterlockedCompareExchangePointer` realiza uma comparação atômica do endereço `Destination` com o endereço `Comparand`. Se o endereço `Destination` for igual ao endereço `Comparand`, o endereço `Exchange` será armazenado no endereço especificado pelo `Destination`. Caso contrário, nenhuma operação será executada.

`_InterlockedCompareExchangePointer`fornece suporte intrínseco do compilador para a função [InterlockedCompareExchangePointer](/windows-hardware/drivers/ddi/content/wdm/nf-wdm-interlockedcompareexchangepointer) do Win32 SDK do Windows.

Para obter um exemplo de como usar `_InterlockedCompareExchangePointer`o, consulte [_InterlockedDecrement](../intrinsics/interlockeddecrement-intrinsic-functions.md).

Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. O ARM intrínseco com um `_nf` sufixo ("sem limite") não atua como uma barreira de memória.

Intrínsecos com um sufixo `_np` ("no prefetch") impedem que uma possível operação de pré-busca seja inserida pelo compilador.

Em plataformas Intel que suportam instruções HLE (Elisão de Bloqueio de Hardware), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware. Se esses intrínsecos forem chamados em plataformas que não dão suporte a HLE, a dica será ignorada.

Essas rotinas somente estão disponíveis como intrínsecos.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
