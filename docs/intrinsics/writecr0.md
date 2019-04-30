---
title: __writecr0
ms.date: 11/04/2016
f1_keywords:
- _writecr0
helpviewer_keywords:
- _writecr0 intrinsic
ms.assetid: a143d08d-0333-4e1b-91b4-4acb2ae91b5a
ms.openlocfilehash: 24d9ffe0e07269fedf19f90a7c66a07e3c5e7d3e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389938"
---
# <a name="writecr0"></a>__writecr0

**Seção específica da Microsoft**

Grava o valor `Data` para o registro CR0.

## <a name="syntax"></a>Sintaxe

```
void writecr0(
   unsigned __int64 Data
);
```

#### <a name="parameters"></a>Parâmetros

*Dados*<br/>
[in] O valor para gravar o registro CR0.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writecr0`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco só está disponível no modo kernel e a rotina só está disponível como um intrínseco.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)