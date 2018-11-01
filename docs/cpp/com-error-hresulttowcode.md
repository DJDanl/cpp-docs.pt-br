---
title: _com_error::HRESULTToWCode
ms.date: 11/04/2016
f1_keywords:
- _com_error::HRESULTToWCode
helpviewer_keywords:
- HRESULTToWCode method [C++]
ms.assetid: ff3789f5-1047-41a0-b7e3-86dd8f638dba
ms.openlocfilehash: d89503e822d92bf6a1fcb2b6bb658d532af32c5d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50581227"
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