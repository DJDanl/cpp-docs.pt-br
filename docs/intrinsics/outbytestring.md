---
title: __outbytestring | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __outbytestring
dev_langs:
- C++
helpviewer_keywords:
- rep outsb instruction
- __outbytestring intrinsic
- outsb instruction
ms.assetid: c9150661-9c18-427f-bae8-710bba6ed78c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7ef1bb6e4804fc71531f694a3dac4c5504941bf0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393757"
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