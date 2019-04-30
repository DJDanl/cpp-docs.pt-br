---
title: _variant_t::_variant_t
ms.date: 11/04/2016
f1_keywords:
- _variant_t::_variant_t
helpviewer_keywords:
- _variant_t class [C++], constructor
- _variant_t method [C++]
ms.assetid: a50e5b33-d4c6-4a26-8e7e-a0a25fd9895b
ms.openlocfilehash: b3575226199c15c4a9796fb439f65efb5a539225
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62403276"
---
# <a name="varianttvariantt"></a>_variant_t::_variant_t

**Seção específica da Microsoft**

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

#### <a name="parameters"></a>Parâmetros

*varSrc*<br/>
Um objeto `VARIANT` a ser copiado no novo objeto `_variant_t`.

*pVarSrc*<br/>
Ponteiro para um `VARIANT` o objeto a ser copiado para o novo `_variant_t` objeto.

*var_t_Src*<br/>
Um objeto `_variant_t` a ser copiado no novo objeto `_variant_t`.

*fCopy*<br/>
Se **falsos**, fornecida `VARIANT` objeto é anexado ao novo `_variant_t` objeto sem fazer uma nova cópia por `VariantCopy`.

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
Um **bool** valor a ser copiado no novo `_variant_t` objeto.

*pIUknownSrc*<br/>
Ponteiro de interface COM para um objeto VT_UNKNOWN a ser encapsulado no novo `_variant_t` objeto.

*pDispSrc*<br/>
Ponteiro de interface COM para um objeto VT_DISPATCH a ser encapsulado no novo `_variant_t` objeto.

*decSrc*<br/>
Um valor `DECIMAL` a ser copiado no novo objeto `_variant_t`.

*bSrc*<br/>
Um valor `BYTE` a ser copiado no novo objeto `_variant_t`.

*cSrc*<br/>
Um **char** valor a ser copiado no novo `_variant_t` objeto.

*usSrc*<br/>
Um **unsigned short** valor a ser copiado no novo `_variant_t` objeto.

*ulSrc*<br/>
Um **unsigned long** valor a ser copiado no novo `_variant_t` objeto.

*iSrc*<br/>
Uma **int** valor a ser copiado no novo `_variant_t` objeto.

*uiSrc*<br/>
Uma **int sem sinal** valor a ser copiado no novo `_variant_t` objeto.

*i8Src*<br/>
Uma **__int64** valor a ser copiado no novo `_variant_t` objeto.

*ui8Src*<br/>
Uma **unsigned __int64** valor a ser copiado no novo `_variant_t` objeto.

## <a name="remarks"></a>Comentários

- **_variant_t(.)** constrói um vazio `_variant_t` objeto, `VT_EMPTY`.

- **_variant_t (VARIANT &**  *varSrc*  **)** constrói uma `_variant_t` objeto a partir de uma cópia do `VARIANT` objeto. O tipo de variante é mantido.

- **variant_t (VARIANTES**<strong>\*</strong>*1&gt;Operator=(&lt;1}{2&gt;pvarSrc&lt;2}{3&gt;)&lt;3***)** constrói um `_variant_t` de uma cópia do objeto do `VARIANT` objeto.     O tipo de variante é mantido.

- **_variant_t( _variant_t&**  *var_t_Src*  **)** constrói uma `_variant_t` objeto de outro `_variant_t` objeto. O tipo de variante é mantido.

- **_variant_t( VARIANT&** *varSrc* **, bool**  `fCopy`  **)** constrói um `_variant_t` objeto de uma já existente `VARIANT` objeto. Se *fCopy* é **falso**, o **VARIANT** objeto é anexado ao novo objeto sem fazer uma cópia.

- **_variant_t( curto**  *sSrc* **, VARTYPE**  `vtSrc`  **= VT_I2)** constrói um `_variant_t` objeto do tipo VT_I2 ou VT_BOOL de um **curto** valor inteiro. Qualquer outro `VARTYPE` resulta em um erro E_INVALIDARG.

- **_variant_t( longo**  `lSrc` **, VARTYPE**  `vtSrc`  **= VT_I4 )** constrói uma `_variant_t` objeto do tipo VT_I4, VT_BOOL ou VT_ERROR de um **longo**  valor inteiro. Qualquer outro `VARTYPE` resulta em um erro E_INVALIDARG.

- **_variant_t( float**  `fltSrc`  **)** constrói um `_variant_t` objeto do tipo VT_R4 de um **float** valor numérico.

- **_variant_t( duplas**  `dblSrc` **, VARTYPE**  `vtSrc`  **= VT_R8)** constrói uma `_variant_t` objeto do tipo VT_R8 ou VT_DATE de um **duplo** valor numérico. Qualquer outro `VARTYPE` resulta em um erro E_INVALIDARG.

- **_variant_t ( CY&**  `cySrc`  **)** constrói um `_variant_t` VT_CY a partir do objeto do tipo um `CY` objeto.

- **_variant_t( bstr_t&**  `bstrSrc`  **)** constrói um `_variant_t` objeto do tipo VT_BSTR de um `_bstr_t` objeto. Um novo `BSTR` é alocado.

- **_variant_t( wchar_t** <strong>\*</strong> *wstrSrc*  **)** constrói um `_variant_t` objeto do tipo VT_BSTR de uma cadeia de caracteres Unicode.   Um novo `BSTR` é alocado.

- **_variant_t (char**<strong>\*</strong>  `strSrc`  **)** constrói um `_variant_t` objeto do tipo VT_BSTR de uma cadeia de caracteres.     Um novo `BSTR` é alocado.

- **_variant_t( bool**  `bSrc`  **)** constrói um `_variant_t` objeto do tipo VT_BOOL de um **bool** valor.

- **_variant_t( IUnknown**<strong>\*</strong>  `pIUknownSrc` **, bool**  `fAddRef`  **= true)** constrói um `_variant_t` objeto do tipo VT_UNKNOWN a partir de um ponteiro de interface COM.       Se `fAddRef` é **verdadeira**, em seguida, `AddRef` é chamado no ponteiro de interface fornecido para corresponder a chamada para `Release` que ocorrerá quando o `_variant_t` objeto é destruído. Cabe a você chamar `Release` no ponteiro de interface fornecido. Se `fAddRef` está **falsos**, o construtor assume a propriedade do ponteiro de interface fornecido; não chame `Release` no ponteiro de interface fornecido.

- **_variant_t( IDispatch** <strong>\*</strong> `pDispSrc` **, bool**`fAddRef`**= true)** constrói um `_variant_t` objeto do Digite VT_DISPATCH a partir de um ponteiro de interface COM.       Se `fAddRef` é **verdadeira**, em seguida, `AddRef` é chamado no ponteiro de interface fornecido para corresponder a chamada para `Release` que ocorrerá quando o `_variant_t` objeto é destruído. Cabe a você chamar `Release` no ponteiro de interface fornecido. Se `fAddRef` está **falsos**, o construtor assume a propriedade do ponteiro de interface fornecido; não chame `Release` no ponteiro de interface fornecido.

- **_variant_t( DECIMAL&**  `decSrc`  **)** constrói um `_variant_t` VT_DECIMAL a partir do objeto do tipo um `DECIMAL` valor.

- **_variant_t( BYTE**  `bSrc`  **)** constrói um `_variant_t` objeto do tipo `VT_UI1` de uma `BYTE` valor.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)