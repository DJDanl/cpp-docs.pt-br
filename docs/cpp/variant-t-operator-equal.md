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
ms.openlocfilehash: 402251592a87b723d75fd1b2cd0786be7b17dbfc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187616"
---
# <a name="_variant_toperator-"></a>_variant_t::operator =

**Seção específica da Microsoft**

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

- **Operator = (**  *varSrc*  **)** Atribui um `VARIANT` existente a um objeto `_variant_t`.

- **Operator = (**  *pVarSrc*  **)** Atribui um `VARIANT` existente a um objeto `_variant_t`.

- **Operator = (**  *var_t_Src*  **)** Atribui um objeto de `_variant_t` existente a um objeto `_variant_t`.

- **Operator = (**  *sSrc*  **)** Atribui um valor inteiro **curto** a um objeto `_variant_t`.

- **Operator = (** `lSrc` **)** Atribui um valor inteiro **longo** a um objeto `_variant_t`.

- **Operator = (**  *fltSrc*  **)** Atribui um valor numérico **flutuante** a um objeto `_variant_t`.

- **Operator = (**  *dblSrc*  **)** Atribui um valor numérico **duplo** a um objeto `_variant_t`.

- **Operator = (**  *cySrc*  **)** Atribui um objeto `CY` a um objeto `_variant_t`.

- **Operator = (**  *bstrSrc*  **)** Atribui um objeto `BSTR` a um objeto `_variant_t`.

- **Operator = (**  *wstrSrc*  **)** Atribui uma cadeia de caracteres Unicode a um objeto `_variant_t`.

- **Operator = (** `strSrc` **)** Atribui uma cadeia de caracteres multibyte a um objeto `_variant_t`.

- **Operator = (** `bSrc` **)** Atribui um valor **bool** a um objeto `_variant_t`.

- **Operator = (**  *pDispSrc*  **)** Atribui um objeto `VT_DISPATCH` a um objeto `_variant_t`.

- **Operator = (**  *pIUnknownSrc*  **)** Atribui um objeto `VT_UNKNOWN` a um objeto `_variant_t`.

- **Operator = (**  *decSrc*  **)** Atribui um valor de `DECIMAL` a um objeto `_variant_t`.

- **Operator = (** `bSrc` **)** Atribui um valor de `BYTE` a um objeto `_variant_t`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
