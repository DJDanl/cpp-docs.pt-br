---
title: _variant_t::_variant_t
ms.date: 11/04/2016
f1_keywords:
- _variant_t::_variant_t
helpviewer_keywords:
- _variant_t class [C++], constructor
- _variant_t method [C++]
ms.assetid: a50e5b33-d4c6-4a26-8e7e-a0a25fd9895b
ms.openlocfilehash: 50c10eb4ff617f4bcdc69d2e1781a9920b9eb0e5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233555"
---
# <a name="_variant_t_variant_t"></a>_variant_t::_variant_t

**Específico da Microsoft**

Constrói um objeto `_variant_t`.

## <a name="syntax"></a>Sintaxe

```
_variant_t( ) throw( );

_variant_t(
   const VARIANT& varSrc
);

_variant_t(
   const VARIANT* pVarSrc
);

_variant_t(
   const _variant_t& var_t_Src
);

_variant_t(
   VARIANT& varSrc,
   bool fCopy
);

_variant_t(
   short sSrc,
   VARTYPE vtSrc = VT_I2
);

_variant_t(
   long lSrc,
   VARTYPE vtSrc = VT_I4
);

_variant_t(
   float fltSrc
) throw( );

_variant_t(
   double dblSrc,
   VARTYPE vtSrc = VT_R8
);

_variant_t(
   const CY& cySrc
) throw( );

_variant_t(
   const _bstr_t& bstrSrc
);

_variant_t(
   const wchar_t *wstrSrc
);

_variant_t(
   const char* strSrc
);

_variant_t(
   IDispatch* pDispSrc,
   bool fAddRef = true
) throw( );

_variant_t(
   bool bSrc
) throw( );

_variant_t(
   IUnknown* pIUknownSrc,
   bool fAddRef = true
) throw( );

_variant_t(
   const DECIMAL& decSrc
) throw( );

_variant_t(
   BYTE bSrc
) throw( );

variant_t(
   char cSrc
) throw();

_variant_t(
   unsigned short usSrc
) throw();

_variant_t(
   unsigned long ulSrc
) throw();

_variant_t(
   int iSrc
) throw();

_variant_t(
   unsigned int uiSrc
) throw();

_variant_t(
   __int64 i8Src
) throw();

_variant_t(
   unsigned __int64 ui8Src
) throw();
```

#### <a name="parameters"></a>parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um objeto `VARIANT` a ser copiado no novo objeto `_variant_t`.

*pVarSrc*<br/>
Ponteiro para um `VARIANT` objeto a ser copiado para o novo `_variant_t` objeto.

*var_t_Src*<br/>
Um objeto `_variant_t` a ser copiado no novo objeto `_variant_t`.

*fCopy*<br/>
Se **`false`** , o `VARIANT` objeto fornecido será anexado ao novo `_variant_t` objeto sem fazer uma nova cópia `VariantCopy` .

*ISrc, sSrc*<br/>
Um valor inteiro a ser copiado no novo objeto `_variant_t`.

*vtSrc*<br/>
O `VARTYPE` para o novo `_variant_t` objeto.

*fltSrc, dblSrc*<br/>
Um valor numérico a ser copiado no novo objeto `_variant_t`.

*cySrc*<br/>
Um objeto `CY` a ser copiado no novo objeto `_variant_t`.

*bstrSrc*<br/>
Um objeto `_bstr_t` a ser copiado no novo objeto `_variant_t`.

*strSrc, wstrSrc*<br/>
Uma cadeia de caracteres a ser copiada no novo objeto `_variant_t`.

*bSrc*<br/>
Um **`bool`** valor a ser copiado para o novo `_variant_t` objeto.

*pIUknownSrc*<br/>
Ponteiro de interface COM para um objeto VT_UNKNOWN a ser encapsulado no novo `_variant_t` objeto.

*pDispSrc*<br/>
Ponteiro de interface COM para um objeto VT_DISPATCH a ser encapsulado no novo `_variant_t` objeto.

*decSrc*<br/>
Um valor `DECIMAL` a ser copiado no novo objeto `_variant_t`.

*bSrc*<br/>
Um valor `BYTE` a ser copiado no novo objeto `_variant_t`.

*cSrc*<br/>
Um **`char`** valor a ser copiado para o novo `_variant_t` objeto.

*usSrc*<br/>
Um **`unsigned short`** valor a ser copiado para o novo `_variant_t` objeto.

*ulSrc*<br/>
Um **`unsigned long`** valor a ser copiado para o novo `_variant_t` objeto.

*iSrc*<br/>
Um **`int`** valor a ser copiado para o novo `_variant_t` objeto.

*uiSrc*<br/>
Um **`unsigned int`** valor a ser copiado para o novo `_variant_t` objeto.

*i8Src*<br/>
Um **`__int64`** valor a ser copiado para o novo `_variant_t` objeto.

*ui8Src*<br/>
Um valor de **__int64 não assinado** a ser copiado para o novo `_variant_t` objeto.

## <a name="remarks"></a>Comentários

- **_variant_t ()** Constrói um objeto vazio `_variant_t` , `VT_EMPTY` .

- **_variant_t (variant&** *varSrc***)** Constrói um `_variant_t` objeto a partir de uma cópia do `VARIANT` objeto.     O tipo de variante é mantido.

- **_variant_t (Variant** <strong>\*</strong> *pVarSrc***)** constrói um `_variant_t` objeto a partir de uma cópia do `VARIANT` objeto.     O tipo de variante é mantido.

- **_variant_t (_variant_t&** *var_t_Src***)** Constrói um `_variant_t` objeto de outro `_variant_t` objeto.     O tipo de variante é mantido.

- **_variant_t (Variant&** *varSrc* **, bool** `fCopy` **)** constrói um `_variant_t` objeto de um objeto existente `VARIANT` .       Se *fCopy* for **`false`** , o objeto **Variant** será anexado ao novo objeto sem fazer uma cópia.

- **_variant_t (Short***sSrc* **, VARTYPE** `vtSrc` **= VT_I2)** constrói um `_variant_t` objeto do tipo VT_I2 ou VT_BOOL de um **`short`** valor inteiro.       Qualquer outro `VARTYPE` resulta em um erro de E_INVALIDARG.

- **_variant_t (Long** `lSrc` **, VARTYPE** `vtSrc` **= VT_I4)** constrói um `_variant_t` objeto do tipo VT_I4, VT_BOOL ou VT_ERROR de um **`long`** valor inteiro.       Qualquer outro `VARTYPE` resulta em um erro de E_INVALIDARG.

- **_variant_t (float** `fltSrc` **)** constrói um `_variant_t` objeto do tipo VT_R4 a partir de um **`float`** valor numérico.    

- **_variant_t (Double** `dblSrc` **, VARTYPE** `vtSrc` **= VT_R8)** constrói um `_variant_t` objeto do tipo VT_R8 ou VT_DATE de um **`double`** valor numérico.       Qualquer outro `VARTYPE` resulta em um erro de E_INVALIDARG.

- **_variant_t (CY&** `cySrc` **)** constrói um `_variant_t` objeto do tipo VT_CY de um `CY` objeto.    

- **_variant_t (_bstr_t&** `bstrSrc` **)** constrói um `_variant_t` objeto do tipo VT_BSTR de um `_bstr_t` objeto.     Um novo `BSTR` é alocado.

- **_variant_t (wchar_t** <strong>\*</strong> *wstrSrc*  **)** constrói um `_variant_t` objeto do tipo VT_BSTR de uma cadeia de caracteres Unicode. Um novo `BSTR` é alocado.

- **_variant_t (Char** <strong>\*</strong> `strSrc` **)** Constrói um `_variant_t` objeto do tipo VT_BSTR de uma cadeia de caracteres.     Um novo `BSTR` é alocado.

- **_variant_t (bool** `bSrc` **)** constrói um `_variant_t` objeto do tipo VT_BOOL a partir de um **`bool`** valor.    

- **_variant_t (IUnknown** <strong>\*</strong> `pIUknownSrc` **, bool** `fAddRef` **= true)** Constrói um `_variant_t` objeto do tipo VT_UNKNOWN de um ponteiro de interface com.       Se `fAddRef` for **`true`** , `AddRef` será chamado no ponteiro de interface fornecido para corresponder à chamada para `Release` que ocorrerá quando o `_variant_t` objeto for destruído. Cabe a você chamar `Release` o ponteiro de interface fornecido. Se `fAddRef` for **`false`** , esse construtor assumirá a propriedade do ponteiro de interface fornecido; não chame `Release` no ponteiro de interface fornecido.

- **_variant_t (IDispatch** <strong>\*</strong> `pDispSrc` **, bool** `fAddRef` **= true)** Constrói um `_variant_t` objeto do tipo VT_DISPATCH de um ponteiro de interface com.       Se `fAddRef` for **`true`** , `AddRef` será chamado no ponteiro de interface fornecido para corresponder à chamada para `Release` que ocorrerá quando o `_variant_t` objeto for destruído. Cabe a você chamar `Release` o ponteiro de interface fornecido. Se `fAddRef` for **`false`** , esse construtor assumirá a propriedade do ponteiro de interface fornecido; não chame `Release` no ponteiro de interface fornecido.

- **_variant_t (decimal&** `decSrc` **)** constrói um `_variant_t` objeto do tipo VT_DECIMAL a partir de um `DECIMAL` valor.    

- **_variant_t (byte** `bSrc` **)** constrói um `_variant_t` objeto do tipo `VT_UI1` a partir de um `BYTE` valor.    

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
