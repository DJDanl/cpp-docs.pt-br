---
title: __writecr8
ms.date: 11/04/2016
f1_keywords:
- _writecr8
helpviewer_keywords:
- _writecr8 intrinsic
ms.assetid: 6f8bd632-dddb-4335-971e-1acee24aa2b9
ms.openlocfilehash: d401673e7ee6cd18b8bc05140efc3b819e48a30f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50471989"
---
# <a name="writecr8"></a>__writecr8

**Seção específica da Microsoft**

Grava o valor `Data` ao registro de CR8.

## <a name="syntax"></a>Sintaxe

```
void writecr8( 
   unsigned __int64 Data 
);
```

#### <a name="parameters"></a>Parâmetros

*Dados*<br/>
[in] O valor a ser gravado para o registro de CR8.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writecr8`|X64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)