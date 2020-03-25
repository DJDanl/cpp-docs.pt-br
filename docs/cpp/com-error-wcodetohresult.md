---
title: _com_error::WCodeToHRESULT
ms.date: 11/04/2016
f1_keywords:
- _com_error::WCodeToHRESULT
helpviewer_keywords:
- WCodeToHRESULT method [C++]
ms.assetid: 0ec43a4b-ca91-42d5-b270-3fde9c8412ea
ms.openlocfilehash: f2194e0e54a93d3227b84d893f9d3f208d972d09
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180505"
---
# <a name="_com_errorwcodetohresult"></a>_com_error::WCodeToHRESULT

**Seção específica da Microsoft**

Mapeia *wCode* de 16 bits para HRESULT de 32 bits.

## <a name="syntax"></a>Sintaxe

```
static HRESULT WCodeToHRESULT(
   WORD wCode
) throw( );
```

#### <a name="parameters"></a>parâmetros

*wCode*<br/>
O *wCode* de 16 bits a ser MAPEADO para HRESULT de 32 bits.

## <a name="return-value"></a>Valor retornado

HRESULT de 32 bits mapeado do *wCode*de 16 bits.

## <a name="remarks"></a>Comentários

Consulte a função membro [WCode](../cpp/com-error-wcode.md) .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[_com_error::WCode](../cpp/com-error-wcode.md)<br/>
[_com_error::HRESULTToWCode](../cpp/com-error-hresulttowcode.md)<br/>
[Classe _com_error](../cpp/com-error-class.md)
