---
title: __readcr8
ms.date: 11/04/2016
f1_keywords:
- __readcr8
helpviewer_keywords:
- __readcr8 intrinsic
ms.assetid: fce16953-87ff-4fbe-8081-7962b97ae46c
ms.openlocfilehash: d4c0b22d38d725566062d2da98839579c22d571c
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59036858"
---
# <a name="readcr8"></a>__readcr8

**Específico da Microsoft**

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

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)