---
title: __readmsr
ms.date: 09/02/2019
f1_keywords:
- __readmsr
helpviewer_keywords:
- Read Model Specific Register
- rdmsr instruction
- __readmsr intrinsic
ms.assetid: 7ab1f8e8-72cb-4ce4-817d-3e728a3c9716
ms.openlocfilehash: 029119bc47d0172c7e9cc5fbf8cd20c4ee23e0f0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219645"
---
# <a name="__readmsr"></a>__readmsr

**Específico da Microsoft**

Gera a `rdmsr` instrução, que lê o registro específico do modelo especificado por **`register`** e retorna seu valor.

## <a name="syntax"></a>Sintaxe

```C
__int64 __readmsr(
   int register
);
```

### <a name="parameters"></a>parâmetros

*Registr*\
no O registro específico do modelo a ser lido.

## <a name="return-value"></a>Valor retornado

O valor no registro especificado.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__readmsr`|x86, x64|

**Arquivo de cabeçalho** \<intrin.h>

## <a name="remarks"></a>Comentários

Essa função só está disponível no modo kernel e a rotina só está disponível como intrínseca.

Para obter mais informações, consulte a documentação do AMD.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
