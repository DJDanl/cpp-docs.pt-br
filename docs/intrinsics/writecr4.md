---
title: __writecr4
ms.date: 11/04/2016
f1_keywords:
- _writecr4
helpviewer_keywords:
- _writecr4 intrinsic
ms.assetid: ab7651d7-b86b-4be7-a0a0-7263099c70fc
ms.openlocfilehash: bbeb282e0e2c386d95009bef277546a260057334
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59032460"
---
# <a name="writecr4"></a>__writecr4

**Seção específica da Microsoft**

Grava o valor `Data` ao registro de CR4.

## <a name="syntax"></a>Sintaxe

```
void writecr4(
   unsigned __int64 Data
);
```

#### <a name="parameters"></a>Parâmetros

*Dados*<br/>
[in] O valor a ser gravado para o registro de CR4.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writecr4`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)