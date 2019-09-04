---
title: __nop
ms.date: 09/02/2019
f1_keywords:
- __nop
helpviewer_keywords:
- nop instruction
- __nop intrinsic
ms.assetid: 7a2a938b-87e0-476d-a348-03ea7635b6b9
ms.openlocfilehash: 4561bcb84063f3707825c8ca164867d41500e2db
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221666"
---
# <a name="__nop"></a>__nop

**Seção específica da Microsoft**

Gera um código de máquina específico da plataforma que não executa nenhuma operação.

## <a name="syntax"></a>Sintaxe

```C
void __nop();
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__nop`|x86, ARM, x64, ARM64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="remarks"></a>Comentários

A `__nop` função é equivalente à instrução `NOP` da máquina. Para obter mais informações sobre x86 e x64, pesquise o documento "manual do desenvolvedor de software de arquitetura Intel, volume 2: Referência de conjunto de instruções ", no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__noop](../intrinsics/noop.md)
