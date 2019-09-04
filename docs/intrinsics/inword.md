---
title: __inword
ms.date: 09/02/2019
f1_keywords:
- __indword_cpp
- __indword
helpviewer_keywords:
- in instruction
- __inword intrinsic
ms.assetid: 5c617edd-6709-40a1-aad2-40d5e39283c6
ms.openlocfilehash: cfb6e5a11bed5feec3435ab604d22b8f532d3400
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217518"
---
# <a name="__inword"></a>__inword

**Seção específica da Microsoft**

Lê dados da porta especificada usando a `in` instrução.

## <a name="syntax"></a>Sintaxe

```C
unsigned short __inword(
   unsigned short Port
);
```

### <a name="parameters"></a>Parâmetros

*Porto*\
no A porta da qual ler.

## <a name="return-value"></a>Valor retornado

A palavra de dados lida.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__inword`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
