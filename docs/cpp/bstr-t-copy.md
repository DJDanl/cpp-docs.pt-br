---
title: _bstr_t::copy
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::copy
helpviewer_keywords:
- Copy method [C++]
- BSTR object [C++], copy
ms.assetid: 00ba7311-e82e-4a79-8106-5329fa2f869a
ms.openlocfilehash: 1fe8cfb5b644b3c7c34cf3325a91ebdf23a04946
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190320"
---
# <a name="_bstr_tcopy"></a>_bstr_t::copy

**Seção específica da Microsoft**

Constrói uma cópia do `BSTR` encapsulado.

## <a name="syntax"></a>Sintaxe

```
BSTR copy( bool fCopy = true ) const;
```

#### <a name="parameters"></a>parâmetros

*fCopy*<br/>
Se for TRUE, **Copy** retornará uma cópia do `BSTR`contido, caso contrário, **Copy** retornará o BSTR real.

## <a name="remarks"></a>Comentários

Retorna uma cópia recém-alocada do objeto `BSTR` encapsulado.

## <a name="example"></a>Exemplo

```cpp
STDMETHODIMP CAlertMsg::get_ConnectionStr(BSTR *pVal){ //  m_bsConStr is _bstr_t
   *pVal = m_bsConStr.copy();
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
