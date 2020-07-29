---
title: _bstr_t::copy
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::copy
helpviewer_keywords:
- Copy method [C++]
- BSTR object [C++], copy
ms.assetid: 00ba7311-e82e-4a79-8106-5329fa2f869a
ms.openlocfilehash: b6029e98e83b171d9ab9f8f3f0282fa3f46ca167
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227589"
---
# <a name="_bstr_tcopy"></a>_bstr_t::copy

**Específico da Microsoft**

Constrói uma cópia do `BSTR` encapsulado.

## <a name="syntax"></a>Sintaxe

```
BSTR copy( bool fCopy = true ) const;
```

#### <a name="parameters"></a>parâmetros

*fCopy*<br/>
Se **`true`** , **Copy** retorna uma cópia do contido `BSTR` , caso contrário, **Copy** retorna o BSTR real.

## <a name="remarks"></a>Comentários

Retorna uma cópia recém-alocada do objeto `BSTR` encapsulado.

## <a name="example"></a>Exemplo

```cpp
STDMETHODIMP CAlertMsg::get_ConnectionStr(BSTR *pVal){ //  m_bsConStr is _bstr_t
   *pVal = m_bsConStr.copy();
}
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
