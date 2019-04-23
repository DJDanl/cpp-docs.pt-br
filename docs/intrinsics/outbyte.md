---
title: __outbyte
ms.date: 11/04/2016
f1_keywords:
- __outbyte
helpviewer_keywords:
- out instruction
- __outbyte intrinsic
ms.assetid: c4cd1a34-8a02-4e37-993d-3201bc17901a
ms.openlocfilehash: 234892369572a2ee315687f5d70533a0c8cf4b59
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59033911"
---
# <a name="outbyte"></a>__outbyte

**Seção específica da Microsoft**

Gera o `out` instrução, que envia 1 byte especificado por `Data` para a porta de e/s especificada pelo `Port`.

## <a name="syntax"></a>Sintaxe

```
void __outbyte(
   unsigned short Port,
   unsigned char Data
);
```

#### <a name="parameters"></a>Parâmetros

*Porta*<br/>
[in] A porta para enviar os dados.

*Dados*<br/>
[in] O byte sejam enviadas a porta especificada.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__outbyte`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)