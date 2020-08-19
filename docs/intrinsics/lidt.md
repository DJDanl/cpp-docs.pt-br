---
title: __lidt
ms.date: 09/02/2019
f1_keywords:
- __lidt
- __lidt_cpp
helpviewer_keywords:
- LIDT instruction
- __lidt intrinsic
ms.assetid: 8298d25d-a19e-4900-828d-6b3b09841882
ms.openlocfilehash: 87a49643e7cd11ae57dc01130f250895cf012065
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562487"
---
# <a name="__lidt"></a>__lidt

**Específico da Microsoft**

Carrega o IDTR (registro de tabela do descritor de interrupção) com o valor no local da memória especificado.

## <a name="syntax"></a>Sintaxe

```C
void __lidt(void * Source);
```

### <a name="parameters"></a>Parâmetros

*Original*\
no Ponteiro para o valor a ser copiado para o IDTR.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__lidt`|x86, x64|

**Arquivo de cabeçalho** \<intrin.h>

## <a name="remarks"></a>Comentários

A `__lidt` função é equivalente à `LIDT` instrução da máquina e está disponível somente no modo kernel. Para obter mais informações, pesquise o documento "manual do desenvolvedor de software de arquitetura Intel, volume 2: referência do conjunto de instruções", no site da [Intel Corporation](https://software.intel.com/articles/intel-sdm) .

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__sidt](../intrinsics/sidt.md)
