---
title: _bstr_t::copy
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::copy
helpviewer_keywords:
- Copy method [C++]
- BSTR object [C++], copy
ms.assetid: 00ba7311-e82e-4a79-8106-5329fa2f869a
ms.openlocfilehash: 13ddf57e0bdbdbcc0c5b487e879e14b000de3ad0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50506828"
---
# <a name="bstrtcopy"></a>_bstr_t::copy

**Seção específica da Microsoft**

Constrói uma cópia do `BSTR` encapsulado.

## <a name="syntax"></a>Sintaxe

```
BSTR copy( bool fCopy = true ) const;
```

#### <a name="parameters"></a>Parâmetros

*fCopy*<br/>
Se for TRUE, **cópia** retorna uma cópia de independente `BSTR`; caso contrário, **cópia** retornará o BSTR real.

## <a name="remarks"></a>Comentários

Retorna uma cópia recém-alocada do objeto `BSTR` encapsulado.

## <a name="example"></a>Exemplo

```cpp
STDMETHODIMP CAlertMsg::get_ConnectionStr(BSTR *pVal){ //  m_bsConStr is _bstr_t
   *pVal = m_bsConStr.copy();
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _bstr_t](../cpp/bstr-t-class.md)