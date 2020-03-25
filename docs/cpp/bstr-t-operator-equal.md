---
title: _bstr_t::operator =
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::operator=
helpviewer_keywords:
- operator = [C++], bstr
- operator= [C++], bstr
ms.assetid: fb31bb1b-ce29-4388-b5fd-8dac830cf18a
ms.openlocfilehash: 5b7f499dd84a67020232aab84966647378daadad
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181064"
---
# <a name="_bstr_toperator-"></a>_bstr_t::operator =

**Seção específica da Microsoft**

Atribui um novo valor a um objeto `_bstr_t` existente.

## <a name="syntax"></a>Sintaxe

```
_bstr_t& operator=(const _bstr_t& s1) throw ( );
_bstr_t& operator=(const char* s2);
_bstr_t& operator=(const wchar_t* s3);
_bstr_t& operator=(const _variant_t& var);
```

#### <a name="parameters"></a>parâmetros

*s1*<br/>
Um objeto `_bstr_t` a ser atribuído a um objeto existente `_bstr_t`.

*s2*<br/>
Uma cadeia de caracteres multibyte a ser atribuída a um objeto `_bstr_t` existente.

*Estado*<br/>
Uma cadeia de caracteres Unicode a ser atribuída a um objeto `_bstr_t` existente.

*var*<br/>
Um objeto `_variant_t` a ser atribuído a um objeto existente `_bstr_t`.

**Fim da seção específica da Microsoft**

## <a name="example"></a>Exemplo

Consulte [_bstr_t:: assign](../cpp/bstr-t-assign.md) para obter um exemplo de uso de **Operator =** .

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
