---
title: _com_error::WCodeToHRESULT
ms.date: 11/04/2016
f1_keywords:
- _com_error::WCodeToHRESULT
helpviewer_keywords:
- WCodeToHRESULT method [C++]
ms.assetid: 0ec43a4b-ca91-42d5-b270-3fde9c8412ea
ms.openlocfilehash: f2fc84be53d95754d21c30eaea8dd981447453d6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62154923"
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