---
title: _com_error::WCodeToHRESULT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::WCodeToHRESULT
dev_langs:
- C++
helpviewer_keywords:
- WCodeToHRESULT method [C++]
ms.assetid: 0ec43a4b-ca91-42d5-b270-3fde9c8412ea
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5b6712734cd7283558ad5776444586f8c0b3fa6e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077553"
---
# <a name="comerrorwcodetohresult"></a>_com_error::WCodeToHRESULT

**Seção específica da Microsoft**

Mapas de 16 bits *wCode* para HRESULT de 32 bits.

## <a name="syntax"></a>Sintaxe

```
static HRESULT WCodeToHRESULT(
   WORD wCode
) throw( );
```

#### <a name="parameters"></a>Parâmetros

*wCode*<br/>
16-bit *wCode* a ser mapeada para um HRESULT de 32 bits.

## <a name="return-value"></a>Valor de retorno

mapeada a partir de 16 bits HRESULT de 32 bits *wCode*.

## <a name="remarks"></a>Comentários

Consulte a [WCode](../cpp/com-error-wcode.md) função de membro.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[_com_error::WCode](../cpp/com-error-wcode.md)<br/>
[_com_error::HRESULTToWCode](../cpp/com-error-hresulttowcode.md)<br/>
[Classe _com_error](../cpp/com-error-class.md)