---
title: __readcr2
ms.date: 11/04/2016
f1_keywords:
- __readcr2
helpviewer_keywords:
- __readcr2 intrinsic
ms.assetid: d02c97d8-1953-46e7-a79e-a781e2c5bf27
ms.openlocfilehash: e26ccbb3db1dfc113f84210314379b06dae93542
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59031096"
---
# <a name="readcr2"></a>__readcr2

**Seção específica da Microsoft**

Lê o registro CR2 e retorna seu valor.

## <a name="syntax"></a>Sintaxe

```
unsigned __int64 __readcr2(void);
```

## <a name="return-value"></a>Valor de retorno

O valor no registro CR2.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readcr2`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)