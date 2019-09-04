---
title: __indword
ms.date: 09/02/2019
f1_keywords:
- __indword_cpp
- __indword
helpviewer_keywords:
- in instruction
- __indword intrinsic
ms.assetid: 1068d686-586e-4e36-b962-d1d7c3315260
ms.openlocfilehash: 790b65c8a565124df92b82b7ea17174788086a96
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222109"
---
# <a name="__indword"></a>__indword

**Seção específica da Microsoft**

Lê uma palavra dupla de dados da porta especificada usando a `in` instrução.

## <a name="syntax"></a>Sintaxe

```C
unsigned long __indword(
   unsigned short Port
);
```

### <a name="parameters"></a>Parâmetros

*Porto*\
no A porta da qual ler.

## <a name="return-value"></a>Valor retornado

A palavra lida da porta.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__indword`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
