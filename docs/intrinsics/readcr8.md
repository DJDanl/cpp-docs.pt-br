---
title: __readcr8
ms.date: 09/02/2019
f1_keywords:
- __readcr8
helpviewer_keywords:
- __readcr8 intrinsic
ms.assetid: fce16953-87ff-4fbe-8081-7962b97ae46c
ms.openlocfilehash: 525775fde4cb96cecfcabef878780d5a2aa6743a
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221239"
---
# <a name="__readcr8"></a>__readcr8

**Seção específica da Microsoft**

Lê o registro de CR8 e retorna seu valor.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __readcr8(void);
```

## <a name="return-value"></a>Valor retornado

O valor no registro CR8.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readcr8`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O intrínseco só está disponível no modo kernel, e a rotina só está disponível como intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
