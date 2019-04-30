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
ms.openlocfilehash: ab97238cf13accf3db593b5c4a81550297a53d6d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62403328"
---
# <a name="variantt-extractors"></a>Extratores _variant_t

**Seção específica da Microsoft**

Extrair dados de encapsulado `VARIANT` objeto.

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

Extrai dados brutos de um encapsulado `VARIANT`. Se o `VARIANT` já não é do tipo apropriado, `VariantChangeType` é usado para tentar uma conversão, e um erro será gerado mediante falha:

- **1&gt;operador short** extrai um **curto** valor inteiro.

- **1&gt;operador long** extrai um **longo** valor inteiro.

- **{1&gt;operador float** extrai um **float** valor numérico.

- **1&gt;operador double** extrai um **duplo** valor inteiro.

- **{1&gt;operador CY** extrai um `CY` objeto.

- **1&gt;operador bool** extrai um **bool** valor.

- **operador (DECIMAL)** extrai um `DECIMAL` valor.

- **operador (bytes)** extrai um `BYTE` valor.

- **1&gt;operador bstr_t** extrai uma cadeia de caracteres, que é encapsulada em um `_bstr_t` objeto.

- **operador IDispatch\*()** extrai um ponteiro dispinterface de um encapsulado `VARIANT`. `AddRef` é chamado no ponteiro resultante, portanto, cabe a você chamar `Release` para liberá-la.

- **operador IUnknown\*()** extrai um ponteiro de interface COM de um encapsulado `VARIANT`. `AddRef` é chamado no ponteiro resultante, portanto, cabe a você chamar `Release` para liberá-la.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)