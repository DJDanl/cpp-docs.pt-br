---
title: __inword
ms.date: 09/02/2019
f1_keywords:
- __inword_cpp
- __inword
helpviewer_keywords:
- in instruction
- __inword intrinsic
ms.assetid: 5c617edd-6709-40a1-aad2-40d5e39283c6
ms.openlocfilehash: 7daaf1abd5089716061f118e30e9534e5c5c18ee
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440968"
---
# <a name="__inword"></a>__inword

**Seção específica da Microsoft**

Lê dados da porta especificada usando a instrução `in`.

## <a name="syntax"></a>Sintaxe

```C
unsigned short __inword(
   unsigned short Port
);
```

### <a name="parameters"></a>Parâmetros

\ de *porta*
no A porta da qual ler.

## <a name="return-value"></a>Valor retornado

A palavra de dados lida.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__inword`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
