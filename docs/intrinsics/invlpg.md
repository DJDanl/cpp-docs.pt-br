---
title: __invlpg
ms.date: 09/02/2019
f1_keywords:
- __invlpg
- __invlpg_cpp
helpviewer_keywords:
- invlpg instruction
- __invlpg intrinsic
ms.assetid: 3fb3633f-d9b7-4ec0-9e7f-a7f2fa8ed794
ms.openlocfilehash: ba8bd81498f805992336b0dc4163fe18fa157a2c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221888"
---
# <a name="__invlpg"></a>__invlpg

**Seção específica da Microsoft**

Gera a instrução `invlpg` x86, que invalida o TLB (buffer à parte de conversão) da página associada à memória apontada por *endereço*.

## <a name="syntax"></a>Sintaxe

```C
void __invlpg(
   void* Address
);
```

### <a name="parameters"></a>Parâmetros

*Corrigir*\
no Um endereço de 64 bits.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__invlpg`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O intrínseco `__invlpg` emite uma instrução privilegiada e só está disponível no modo kernel com um nível de privilégio (CPL) de 0.

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
