---
title: _variant_t::operator =
ms.date: 11/04/2016
f1_keywords:
- _variant_t::operator=
helpviewer_keywords:
- operator= [C++], variant
- operator = [C++], variant
- = operator [C++], with specific Visual C++ objects
ms.assetid: 77622723-6e49-4dec-9e0f-fa74028f1a3c
ms.openlocfilehash: 2db26a378526cd5f48992cb32ea46e9677125e66
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226952"
---
# <a name="_variant_toperator-"></a>_variant_t::operator =

**Específico da Microsoft**

## <a name="syntax"></a>Sintaxe

```
_variant_t& operator=(
   const VARIANT& varSrc
);

_variant_t& operator=(
   const VARIANT* pVarSrc
);

_variant_t& operator=(
   const _variant_t& var_t_Src
);

_variant_t& operator=(
   short sSrc
);

_variant_t& operator=(
   long lSrc
);

_variant_t& operator=(
   float fltSrc
);

_variant_t& operator=(
   double dblSrc
);

_variant_t& operator=(
   const CY& cySrc
);

_variant_t& operator=(
   const _bstr_t& bstrSrc
);

_variant_t& operator=(
   const wchar_t* wstrSrc
);

_variant_t& operator=(
   const char* strSrc
);

_variant_t& operator=(
   IDispatch* pDispSrc
);

_variant_t& operator=(
   bool bSrc
);

_variant_t& operator=(
   IUnknown* pSrc
);

_variant_t& operator=(
   const DECIMAL& decSrc
);

_variant_t& operator=(
   BYTE bSrc
);

_variant_t& operator=(
   char cSrc
);

_variant_t& operator=(
   unsigned short usSrc
);

_variant_t& operator=(
   unsigned long ulSrc
);

_variant_t& operator=(
   int iSrc
);

_variant_t& operator=(
   unsigned int uiSrc
);

_variant_t& operator=(
   __int64 i8Src
);

_variant_t& operator=(
   unsigned __int64 ui8Src
);
```

## <a name="remarks"></a>Comentários

O operador atribui um novo valor ao objeto `_variant_t`:

- **Operator = (**  *varSrc*  **)** Atribui um existente `VARIANT` a um `_variant_t` objeto.

- **Operator = (**  *pVarSrc*  **)** Atribui um existente `VARIANT` a um `_variant_t` objeto.

- **Operator = (**  *var_t_Src*  **)** Atribui um `_variant_t` objeto existente a um `_variant_t` objeto.

- **Operator = (**  *sSrc*  **)** Atribui um **`short`** valor inteiro a um `_variant_t` objeto.

- **Operator = (** `lSrc` **)** atribui um **`long`** valor inteiro a um `_variant_t` objeto.    

- **Operator = (**  *fltSrc*  **)** Atribui um **`float`** valor numérico a um `_variant_t` objeto.

- **Operator = (**  *dblSrc*  **)** Atribui um **`double`** valor numérico a um `_variant_t` objeto.

- **Operator = (**  *cySrc*  **)** Atribui um `CY` objeto a um `_variant_t` objeto.

- **Operator = (**  *bstrSrc*  **)** Atribui um `BSTR` objeto a um `_variant_t` objeto.

- **Operator = (**  *wstrSrc*  **)** Atribui uma cadeia de caracteres Unicode a um `_variant_t` objeto.

- **Operator = (** `strSrc` **)** atribui uma cadeia de caracteres multibyte a um `_variant_t` objeto.    

- **Operator = (** `bSrc` **)** atribui um **`bool`** valor a um `_variant_t` objeto.  

- **Operator = (**  *pDispSrc*  **)** Atribui um `VT_DISPATCH` objeto a um `_variant_t` objeto.

- **Operator = (**  *pIUnknownSrc*  **)** Atribui um `VT_UNKNOWN` objeto a um `_variant_t` objeto.

- **Operator = (**  *decSrc*  **)** Atribui um `DECIMAL` valor a um `_variant_t` objeto.

- **Operator = (** `bSrc` **)** atribui um `BYTE` valor a um `_variant_t` objeto.  

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
