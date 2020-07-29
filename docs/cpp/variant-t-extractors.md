---
title: Extratores _variant_t
ms.date: 11/04/2016
f1_keywords:
- _variant_t.operatordouble
- operatorlong
- _variant_t::operator_bstr_t
- operatordouble
- _variant_t.operatorCY
- operatorCY
- _variant_t::operatorCY
- _variant_t::operatordouble
- operatorfloat
- operatorBYTE
- _variant_t.operatorDECIMAL
- _variant_t::operatorlong
- operatorIDispatch
- _variant_t.operatorBYTE
- operatorDECIMAL
- _variant_t.operator_bstr_t
- _variant_t::operatorDECIMAL
- _variant_t.operatorIUnknown
- _variant_t.operatorlong
- _variant_t::operatorIDispatch
- _variant_t::operatorIUnknown
- operatorIUnknown
- _variant_t.operatorbool
- _variant_t::operatorBYTE
- _variant_t.operatorfloat
- operator_bstr_t
- _variant_t::operatorbool
- operatorshort
- _variant_t::operatorshort
- _variant_t::operatorfloat
- _variant_t.operatorIDispatch
- _variant_t.operatorshort
helpviewer_keywords:
- extractors, _variant_t class
- operator CY
- operator IDispatch
- operator SHORT
- operator double
- operator long
- operator _bstr_t
- operator DECIMAL
- operator float
- operator bool
- operator BYTE
- operator IUnknown
ms.assetid: 33c1782f-045a-4673-9619-1d750efc83a9
ms.openlocfilehash: a1b7c713b5d82ff54250b622f2d4afe17abac468
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87185600"
---
# <a name="_variant_t-extractors"></a>Extratores _variant_t

**Específico da Microsoft**

Extrair dados do objeto encapsulado `VARIANT` .

## <a name="syntax"></a>Sintaxe

```
operator short( ) const;
operator long( ) const;
operator float( ) const;
operator double( ) const;
operator CY( ) const;
operator _bstr_t( ) const;
operator IDispatch*( ) const;
operator bool( ) const;
operator IUnknown*( ) const;
operator DECIMAL( ) const;
operator BYTE( ) const;
operator VARIANT() const throw();
operator char() const;
operator unsigned short() const;
operator unsigned long() const;
operator int() const;
operator unsigned int() const;
operator __int64() const;
operator unsigned __int64() const;
```

## <a name="remarks"></a>Comentários

Extrai dados brutos de um encapsulado `VARIANT` . Se o `VARIANT` não for o tipo correto, `VariantChangeType` será usado para tentar uma conversão e um erro será gerado após a falha:

- **operador Short ()** Extrai um **`short`** valor inteiro.

- **operador Long ()** Extrai um **`long`** valor inteiro.

- **operador float ()** Extrai um **`float`** valor numérico.

- **operador Double ()** Extrai um **`double`** valor inteiro.

- **operador CY ()** Extrai um `CY` objeto.

- **operador bool ()** Extrai um **`bool`** valor.

- **Operador Decimal ()** Extrai um `DECIMAL` valor.

- **byte do operador ()** Extrai um `BYTE` valor.

- **_bstr_t do operador ()** Extrai uma cadeia de caracteres, que é encapsulada em um `_bstr_t` objeto.

- o **operador IDispatch \* ()** extrai um ponteiro de dispinterface de um encapsulado `VARIANT` . `AddRef`é chamado no ponteiro resultante, portanto, cabe a você chamar `Release` para liberá-lo.

- o **operador IUnknown \* ()** extrai um ponteiro de interface com de um encapsulado `VARIANT` . `AddRef`é chamado no ponteiro resultante, portanto, cabe a você chamar `Release` para liberá-lo.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
