---
title: __readcr2
ms.date: 09/02/2019
f1_keywords:
- __readcr2
helpviewer_keywords:
- __readcr2 intrinsic
ms.assetid: d02c97d8-1953-46e7-a79e-a781e2c5bf27
ms.openlocfilehash: 482f4548a692d6aa3b65fbc42caabda29bb393c1
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217113"
---
# <a name="__readcr2"></a>__readcr2

**Seção específica da Microsoft**

Lê o registro de CR2 e retorna seu valor.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __readcr2(void);
```

## <a name="return-value"></a>Valor retornado

O valor no registro CR2.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readcr2`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O intrínseco só está disponível no modo kernel, e a rotina só está disponível como intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
