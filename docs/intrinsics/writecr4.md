---
title: __writecr4 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _writecr4
dev_langs:
- C++
helpviewer_keywords:
- _writecr4 intrinsic
ms.assetid: ab7651d7-b86b-4be7-a0a0-7263099c70fc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fd03b9371c4026282ff9e01d16b937c73bc495ce
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390494"
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