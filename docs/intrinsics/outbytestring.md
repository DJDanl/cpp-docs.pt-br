---
title: __outbytestring
ms.date: 11/04/2016
f1_keywords:
- __outbytestring
helpviewer_keywords:
- rep outsb instruction
- __outbytestring intrinsic
- outsb instruction
ms.assetid: c9150661-9c18-427f-bae8-710bba6ed78c
ms.openlocfilehash: 41064dda6a1a0b9ad4c15f98c3f3081f08ef8db6
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59032187"
---
# <a name="outbytestring"></a>__outbytestring

**Seção específica da Microsoft**

Gera o `rep outsb` instrução, que envia o primeiro `Count` bytes de dados apontado por `Buffer` para a porta especificada pelo `Port`.

## <a name="syntax"></a>Sintaxe

```
void __outbytestring(
   unsigned short Port,
   unsigned char* Buffer,
   unsigned long Count
);
```

#### <a name="parameters"></a>Parâmetros

*Porta*<br/>
[in] A porta para enviar os dados.

*buffer*<br/>
[in] Os dados a serem enviadas a porta especificada.

*Contagem*<br/>
[in] O número de bytes de dados a serem enviados.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__outbytestring`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)