---
title: __writecr8
ms.date: 09/02/2019
f1_keywords:
- _writecr8
helpviewer_keywords:
- _writecr8 intrinsic
ms.assetid: 6f8bd632-dddb-4335-971e-1acee24aa2b9
ms.openlocfilehash: c8df13c15b5cd8a51b77d65ad930a1852809ee30
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219242"
---
# <a name="__writecr8"></a>__writecr8

**Seção específica da Microsoft**

Grava o valor `Data` no registro CR8.

## <a name="syntax"></a>Sintaxe

```C
void writecr8(
   unsigned __int64 Data
);
```

### <a name="parameters"></a>Parâmetros

*Dado*\
no O valor a ser gravado no registro de CR8.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writecr8`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O `__writecr8` intrínseco só está disponível no modo kernel, e a rotina só está disponível como intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
