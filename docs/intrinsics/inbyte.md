---
title: __inbyte
ms.date: 09/02/2019
f1_keywords:
- __inbyte
- __inbyte_cpp
helpviewer_keywords:
- in instruction
- __inbyte intrinsic
ms.assetid: 03b61799-2a08-474d-adc4-2cbf7c81a4d5
ms.openlocfilehash: f0036763ed7315a54fbfe6dcc873b46b52f0730c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222147"
---
# <a name="__inbyte"></a>__inbyte

**Seção específica da Microsoft**

Gera a `in` instrução, retornando uma leitura de byte único da porta especificada `Port`por.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __inbyte(
   unsigned short Port
);
```

### <a name="parameters"></a>Parâmetros

*Porto*\
no A porta da qual ler.

## <a name="return-value"></a>Valor retornado

O byte lido da porta especificada.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__inbyte`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="remarks"></a>Comentários

Essa rotina só está disponível como função intrínseca.

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
