---
title: __writecr3
ms.date: 09/02/2019
f1_keywords:
- _writecr3
helpviewer_keywords:
- _writecr3 intrinsic
ms.assetid: 959d49fa-69d5-47cf-88d2-7688367fe38f
ms.openlocfilehash: f2472a21fe42f10dbf0918480ef02f7e48109747
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219282"
---
# <a name="__writecr3"></a>__writecr3

**Seção específica da Microsoft**

Grava o valor `Data` no registro CR3.

## <a name="syntax"></a>Sintaxe

```C
void writecr3(
   unsigned __int64 Data
);
```

### <a name="parameters"></a>Parâmetros

*Dado*\
no O valor a ser gravado no registro de CR3.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writecr3`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
