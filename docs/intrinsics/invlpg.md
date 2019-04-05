---
title: __invlpg
ms.date: 11/04/2016
f1_keywords:
- __invlpg
- __invlpg_cpp
helpviewer_keywords:
- invlpg instruction
- __invlpg intrinsic
ms.assetid: 3fb3633f-d9b7-4ec0-9e7f-a7f2fa8ed794
ms.openlocfilehash: b4f941baae9f03ed288a99d59e2b06262962e339
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59023303"
---
# <a name="invlpg"></a>__invlpg

**Específico da Microsoft**

Gera o x86 `invlpg` instrução, o que invalida o buffer de conversão à parte (TLB) para a página associada com a memória apontada por `Address`.

## <a name="syntax"></a>Sintaxe

```
void __invlpg(
   void* Address
);
```

#### <a name="parameters"></a>Parâmetros

*Endereço*<br/>
[in] Um endereço de 64 bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__invlpg`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O intrínseco `__invlpg` emite uma instrução privilegiada e só está disponível no modo de kernel com um nível de privilégio (CPL) igual a 0.

Essa rotina só está disponível como função intrínseca.

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)