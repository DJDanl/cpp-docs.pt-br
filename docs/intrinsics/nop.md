---
title: __nop
ms.date: 11/04/2016
f1_keywords:
- __nop
helpviewer_keywords:
- nop instruction
- __nop intrinsic
ms.assetid: 7a2a938b-87e0-476d-a348-03ea7635b6b9
ms.openlocfilehash: b0033b0e3a62a16c2856b0e25daeebdb5df0c81f
ms.sourcegitcommit: a1fad0a266b20b313364a74b16c9ac45d089b1e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/11/2019
ms.locfileid: "54220381"
---
# <a name="nop"></a>__nop

**Seção específica da Microsoft**

Gera código de máquina específico da plataforma que não realiza nenhuma operação.

## <a name="syntax"></a>Sintaxe

```
void __nop();
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__nop`|x86, ARM, x64, ARM64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="remarks"></a>Comentários

O `__nop` função é equivalente ao `NOP` instruções de máquina. Para obter mais informações sobre o x86 e x64, procure o documento, "Manual do desenvolvedor de Software de arquitetura Intel, Volume 2: Instrução definir Reference"na [Intel Corporation](https://software.intel.com/articles/intel-sdm) site.

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__noop](../intrinsics/noop.md)
