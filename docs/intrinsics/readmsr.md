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
ms.openlocfilehash: 4398b9d42369e3a914dbec1ed2d14cafecf58483
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222343"
---
# <a name="__readmsr"></a>__readmsr

**Seção específica da Microsoft**

Gera a `rdmsr` instrução, que lê o registro específico do modelo especificado por `register` e retorna seu valor.

## <a name="syntax"></a>Sintaxe

```C
__int64 __readmsr(
   int register
);
```

### <a name="parameters"></a>Parâmetros

*Registr*\
no O registro específico do modelo a ser lido.

## <a name="return-value"></a>Valor retornado

O valor no registro especificado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readmsr`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essa função só está disponível no modo kernel e a rotina só está disponível como intrínseca.

Para obter mais informações, consulte a documentação do AMD.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
