---
title: _com_error::HRESULTToWCode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::HRESULTToWCode
dev_langs:
- C++
helpviewer_keywords:
- HRESULTToWCode method [C++]
ms.assetid: ff3789f5-1047-41a0-b7e3-86dd8f638dba
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c39b638451aa8ea89191e323eae5f2c140563990
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46082060"
---
# <a name="comerrorhresulttowcode"></a>_com_error::HRESULTToWCode

**Seção específica da Microsoft**

Mapeia o HRESULT de 32 bits para 16 bits `wCode`.

## <a name="syntax"></a>Sintaxe

```
static WORD HRESULTToWCode(
   HRESULT hr
) throw( );
```

#### <a name="parameters"></a>Parâmetros

*hr*<br/>
O HRESULT de 32 bits a ser mapeada para 16 bits `wCode`.

## <a name="return-value"></a>Valor de retorno

16-bit `wCode` mapeada a partir o HRESULT de 32 bits.

## <a name="remarks"></a>Comentários

Ver [_com_error::WCode](../cpp/com-error-wcode.md) para obter mais informações.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[_com_error::WCode](../cpp/com-error-wcode.md)<br/>
[_com_error::WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)<br/>
[Classe _com_error](../cpp/com-error-class.md)