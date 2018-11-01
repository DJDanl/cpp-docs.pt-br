---
title: __readcr8
ms.date: 11/04/2016
f1_keywords:
- __readcr8
helpviewer_keywords:
- __readcr8 intrinsic
ms.assetid: fce16953-87ff-4fbe-8081-7962b97ae46c
ms.openlocfilehash: 041d1b1574ff3d6d3f8bf14575758d1b3ea62e15
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602795"
---
# <a name="readcr8"></a>__readcr8

**Seção específica da Microsoft**

Lê o registro de CR8 e retorna seu valor.

## <a name="syntax"></a>Sintaxe

```
unsigned __int64 __readcr8(void);
```

## <a name="return-value"></a>Valor de retorno

O valor no registro CR8.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readcr8`|X64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)