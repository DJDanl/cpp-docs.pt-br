---
title: _com_error::HRESULTToWCode
ms.date: 11/04/2016
f1_keywords:
- _com_error::HRESULTToWCode
helpviewer_keywords:
- HRESULTToWCode method [C++]
ms.assetid: ff3789f5-1047-41a0-b7e3-86dd8f638dba
ms.openlocfilehash: 35a497c273f15c9755d3607e7907a3a48dad8dc8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180557"
---
# <a name="_com_errorhresulttowcode"></a>_com_error::HRESULTToWCode

**Seção específica da Microsoft**

Mapeia 32 bits de HRESULT para `wCode`de 16 bits.

## <a name="syntax"></a>Sintaxe

```
static WORD HRESULTToWCode(
   HRESULT hr
) throw( );
```

#### <a name="parameters"></a>parâmetros

*Human*<br/>
O HRESULT de 32 bits a ser mapeado para `wCode`de 16 bits.

## <a name="return-value"></a>Valor retornado

`wCode` de 16 bits mapeada do HRESULT de 32 bits.

## <a name="remarks"></a>Comentários

Consulte [_com_error:: WCode](../cpp/com-error-wcode.md) para obter mais informações.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[_com_error::WCode](../cpp/com-error-wcode.md)<br/>
[_com_error::WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)<br/>
[Classe _com_error](../cpp/com-error-class.md)
