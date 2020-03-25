---
title: _variant_t::_variant_t
ms.date: 11/04/2016
f1_keywords:
- _variant_t::_variant_t
helpviewer_keywords:
- _variant_t class [C++], constructor
- _variant_t method [C++]
ms.assetid: a50e5b33-d4c6-4a26-8e7e-a0a25fd9895b
ms.openlocfilehash: fff116ef04967a1887eaa075d92d3ea0283d5427
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187525"
---
# <a name="_variant_t_variant_t"></a>_variant_t::_variant_t

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

#### <a name="parameters"></a>parâmetros

*varSrc*<br/>
Um objeto `VARIANT` a ser copiado no novo objeto `_variant_t`.

*pVarSrc*<br/>
Ponteiro para um objeto `VARIANT` a ser copiado para o novo objeto `_variant_t`.

*var_t_Src*<br/>
Um objeto `_variant_t` a ser copiado no novo objeto `_variant_t`.

*fCopy*<br/>
Se **for false**, o objeto `VARIANT` fornecido será anexado ao novo objeto `_variant_t` sem fazer uma nova cópia por `VariantCopy`.

*ISrc, sSrc*<br/>
Um valor inteiro a ser copiado no novo objeto `_variant_t`.

*vtSrc*<br/>
O `VARTYPE` para o novo objeto `_variant_t`.

*fltSrc, dblSrc*<br/>
Um valor numérico a ser copiado no novo objeto `_variant_t`.

*cySrc*<br/>
Um objeto `CY` a ser copiado no novo objeto `_variant_t`.

*bstrSrc*<br/>
Um objeto `_bstr_t` a ser copiado no novo objeto `_variant_t`.

*strSrc, wstrSrc*<br/>
Uma cadeia de caracteres a ser copiada no novo objeto `_variant_t`.

*bSrc*<br/>
Um valor **bool** a ser copiado para o novo objeto `_variant_t`.

*pIUknownSrc*<br/>
Ponteiro de interface COM para um objeto VT_UNKNOWN a ser encapsulado no novo objeto `_variant_t`.

*pDispSrc*<br/>
Ponteiro de interface COM para um objeto VT_DISPATCH a ser encapsulado no novo objeto `_variant_t`.

*decSrc*<br/>
Um valor `DECIMAL` a ser copiado no novo objeto `_variant_t`.

*bSrc*<br/>
Um valor `BYTE` a ser copiado no novo objeto `_variant_t`.

*cSrc*<br/>
Um valor **Char** a ser copiado para o novo objeto `_variant_t`.

*usSrc*<br/>
Um valor **curto não assinado** a ser copiado para o novo objeto `_variant_t`.

*ulSrc*<br/>
Um valor **longo não atribuído** a ser copiado para o novo objeto `_variant_t`.

*iSrc*<br/>
Um valor **int** a ser copiado para o novo objeto `_variant_t`.

*uiSrc*<br/>
Um valor **int não assinado** a ser copiado para o novo objeto `_variant_t`.

*i8Src*<br/>
Um valor de **__int64** a ser copiado para o novo objeto `_variant_t`.

*ui8Src*<br/>
Um valor de **__int64 não assinado** a ser copiado para o novo objeto `_variant_t`.

## <a name="remarks"></a>Comentários

- **_variant_t ()** Constrói um objeto `_variant_t` vazio, `VT_EMPTY`.

- **_variant_t (variant &**  *varSrc*  **)** Constrói um objeto `_variant_t` de uma cópia do objeto `VARIANT`. O tipo de variante é mantido.

- **_variant_t (variant** <strong>\*</strong> *pVarSrc* **)** Constrói um objeto `_variant_t` de uma cópia do objeto `VARIANT`. O tipo de variante é mantido.

- **_variant_t (_variant_t &**  *var_t_Src*  **)** Constrói um objeto `_variant_t` de outro objeto `_variant_t`. O tipo de variante é mantido.

- **_variant_t (variant &** *varSrc* **, bool**`fCopy` **)** Constrói um objeto `_variant_t` de um objeto `VARIANT` existente. Se *fCopy* for **false**, o objeto **Variant** será anexado ao novo objeto sem fazer uma cópia.

- **_variant_t (Short***sSrc* **, VARTYPE**`vtSrc` **= VT_I2)** Constrói um objeto `_variant_t` do tipo VT_I2 ou VT_BOOL de um valor inteiro **curto** . Qualquer outro `VARTYPE` resulta em um erro de E_INVALIDARG.

- **_variant_t (long**`lSrc` **, VARTYPE**`vtSrc` **= VT_I4)** Constrói um objeto `_variant_t` do tipo VT_I4, VT_BOOL ou VT_ERROR de um valor inteiro **longo** . Qualquer outro `VARTYPE` resulta em um erro de E_INVALIDARG.

- **_variant_t (float**`fltSrc` **)** Constrói um objeto `_variant_t` do tipo VT_R4 a partir de um valor numérico **flutuante** .

- **_variant_t (double**`dblSrc` **, VARTYPE**`vtSrc` **= VT_R8)** Constrói um objeto `_variant_t` do tipo VT_R8 ou VT_DATE a partir de um valor numérico **duplo** . Qualquer outro `VARTYPE` resulta em um erro de E_INVALIDARG.

- **_variant_t (ac &** `cySrc` **)** Constrói um objeto `_variant_t` do tipo VT_CY de um objeto `CY`.

- **_variant_t (_bstr_t &** `bstrSrc` **)** Constrói um objeto `_variant_t` do tipo VT_BSTR de um objeto `_bstr_t`. Um novo `BSTR` é alocado.

- **_variant_t (wchar_t** <strong>\*</strong> *wstrSrc*  **)** Constrói um objeto `_variant_t` do tipo VT_BSTR de uma cadeia de caracteres Unicode. Um novo `BSTR` é alocado.

- **_variant_t (char** <strong>\*</strong>`strSrc` **)** Constrói um objeto `_variant_t` do tipo VT_BSTR de uma cadeia de caracteres. Um novo `BSTR` é alocado.

- **_variant_t (bool**`bSrc` **)** Constrói um objeto `_variant_t` do tipo VT_BOOL a partir de um valor **bool** .

- **_variant_t (IUnknown** <strong>\*</strong>`pIUknownSrc` **, bool**`fAddRef` **= true)** Constrói um objeto `_variant_t` do tipo VT_UNKNOWN de um ponteiro de interface COM. Se `fAddRef` for **true**, `AddRef` será chamado no ponteiro de interface fornecido para corresponder à chamada para `Release` que ocorrerá quando o objeto `_variant_t` for destruído. Cabe a você chamar `Release` no ponteiro de interface fornecido. Se `fAddRef` for **false**, esse construtor assumirá a propriedade do ponteiro de interface fornecido; Não chame `Release` no ponteiro de interface fornecido.

- **_variant_t (IDispatch** <strong>\*</strong>`pDispSrc` **, bool**`fAddRef` **= true)** Constrói um objeto `_variant_t` do tipo VT_DISPATCH de um ponteiro de interface COM. Se `fAddRef` for **true**, `AddRef` será chamado no ponteiro de interface fornecido para corresponder à chamada para `Release` que ocorrerá quando o objeto `_variant_t` for destruído. Cabe a você chamar `Release` no ponteiro de interface fornecido. Se `fAddRef` for **false**, esse construtor assumirá a propriedade do ponteiro de interface fornecido; Não chame `Release` no ponteiro de interface fornecido.

- **_variant_t (DECIMAL &** `decSrc` **)** Constrói um objeto `_variant_t` do tipo VT_DECIMAL de um valor `DECIMAL`.

- **_variant_t (BYTE**`bSrc` **)** Constrói um objeto `_variant_t` do tipo `VT_UI1` de um valor `BYTE`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
