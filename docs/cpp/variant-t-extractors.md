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
ms.openlocfilehash: 685df7285e58e0cf2ceeded5ac27641364897298
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187694"
---
# <a name="_variant_t-extractors"></a>Extratores _variant_t

**Seção específica da Microsoft**

Extrair dados do objeto de `VARIANT` encapsulado.

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

Extrai dados brutos de um `VARIANT`encapsulado. Se o `VARIANT` ainda não for o tipo apropriado, `VariantChangeType` será usado para tentar uma conversão e um erro será gerado após a falha:

- **operador Short ()** Extrai um valor inteiro **curto** .

- **operador Long ()** Extrai um valor inteiro **longo** .

- **operador float ()** Extrai um valor numérico **flutuante** .

- **operador Double ()** Extrai um valor inteiro **duplo** .

- **operador CY ()** Extrai um objeto `CY`.

- **operador bool ()** Extrai um valor **bool** .

- **Operador Decimal ()** Extrai um valor de `DECIMAL`.

- **byte do operador ()** Extrai um valor de `BYTE`.

- **_bstr_t do operador ()** Extrai uma cadeia de caracteres, que é encapsulada em um objeto `_bstr_t`.

- **operador IDispatch\*()** Extrai um ponteiro de dispinterface de um `VARIANT`encapsulado. `AddRef` é chamado no ponteiro resultante, portanto, cabe a você chamar `Release` para liberá-lo.

- **\*de operador IUnknown ()** Extrai um ponteiro de interface COM de um `VARIANT`encapsulado. `AddRef` é chamado no ponteiro resultante, portanto, cabe a você chamar `Release` para liberá-lo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
