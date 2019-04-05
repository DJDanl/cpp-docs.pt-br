---
title: __indwordstring
ms.date: 11/04/2016
f1_keywords:
- __indwordstring
- __indwordstring_cpp
helpviewer_keywords:
- __indwordstring intrinsic
- rep insd instruction
ms.assetid: 96a1cf33-f691-4916-99e4-fa849b61e3a9
ms.openlocfilehash: 6f50aed8e6efe3b0b0a6e7eaebef5719475463ea
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59027864"
---
# <a name="indwordstring"></a>__indwordstring

**Específico da Microsoft**

Lê dados da porta especificada usando o `rep insd` instrução.

## <a name="syntax"></a>Sintaxe

```
void __indwordstring(
   unsigned short Port,
   unsigned long* Buffer,
   unsigned long Count
);
```

#### <a name="parameters"></a>Parâmetros

*Porta*<br/>
[in] A porta leiam.

*buffer*<br/>
[out] A leitura da porta de dados são gravados aqui.

*Contagem*<br/>
[in] O número de bytes de dados a serem lidos.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__indwordstring`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Essa rotina só está disponível como função intrínseca.

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)