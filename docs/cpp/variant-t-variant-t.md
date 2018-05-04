---
title: _variant_t::_variant_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _variant_t::_variant_t
dev_langs:
- C++
helpviewer_keywords:
- _variant_t class [C++], constructor
- _variant_t method [C++]
ms.assetid: a50e5b33-d4c6-4a26-8e7e-a0a25fd9895b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 59ec19adc66a72a7c98772db99aaab3eee4e3b2c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
 *varSrc*  
 Um **VARIANT** objeto a ser copiado para a nova `_variant_t` objeto.  
  
 *pVarSrc*  
 Ponteiro para um **VARIANT** objeto a ser copiado para a nova `_variant_t` objeto.  
  
 *var_t_Src*  
 Um objeto `_variant_t` a ser copiado no novo objeto `_variant_t`.  
  
 `fCopy`  
 Se for false, fornecido **VARIANT** objeto está anexado à nova `_variant_t` objeto sem fazer uma nova cópia por **VariantCopy**.  
  
 *ISrc, sSrc*  
 Um valor inteiro a ser copiado no novo objeto `_variant_t`.  
  
 `vtSrc`  
 O **VARTYPE** para o novo `_variant_t` objeto.  
  
 *fltSrc, dblSrc*  
 Um valor numérico a ser copiado no novo objeto `_variant_t`.  
  
 `cySrc`  
 Um **CY** objeto a ser copiado para a nova `_variant_t` objeto.  
  
 `bstrSrc`  
 Um objeto `_bstr_t` a ser copiado no novo objeto `_variant_t`.  
  
 *strSrc, wstrSrc*  
 Uma cadeia de caracteres a ser copiada no novo objeto `_variant_t`.  
  
 `bSrc`  
 Um valor `bool` a ser copiado no novo objeto `_variant_t`.  
  
 `pIUknownSrc`  
 Ponteiro de interface COM para um **VT_UNKNOWN** objeto a ser encapsulada em novo `_variant_t` objeto.  
  
 `pDispSrc`  
 Ponteiro de interface COM para um **VT_DISPATCH** objeto a ser encapsulada em novo `_variant_t` objeto.  
  
 `decSrc`  
 Um **DECIMAL** valor a ser copiado para a nova `_variant_t` objeto.  
  
 `bSrc`  
 Um **bytes** valor a ser copiado para a nova `_variant_t` objeto.  
  
 `cSrc`  
 Um valor `char` a ser copiado no novo objeto `_variant_t`.  
  
 *usSrc*  
 Um **unsigned short** valor a ser copiado para a nova `_variant_t` objeto.  
  
 *ulSrc*  
 Um valor `unsigned long` a ser copiado no novo objeto `_variant_t`.  
  
 `iSrc`  
 Um valor `int` a ser copiado no novo objeto `_variant_t`.  
  
 *uiSrc*  
 Um valor `unsigned int` a ser copiado no novo objeto `_variant_t`.  
  
 *i8Src*  
 Um _**int64** valor a ser copiado para a nova `_variant_t` objeto.  
  
 *ui8Src*  
 Um **Int64 sem sinal** valor a ser copiado para a nova `_variant_t` objeto.  
  
## <a name="remarks"></a>Comentários  
  
-   **( variant_t)** constrói vazio `_variant_t` objeto `VT_EMPTY`.  
  
-   **variant_t (VARIANT &***varSrc***)** constrói um `_variant_t` o objeto de uma cópia do **VARIANT** objeto. O tipo de variante é mantido.  
  
-   **variant_t (VARIANT\****pVarSrc***)** constrói um `_variant_t` o objeto de uma cópia do **VARIANT** objeto. O tipo de variante é mantido.  
  
-   **variant_t ( variant_t &***var_t_Src***)** constrói um `_variant_t` objeto de outro `_variant_t` objeto. O tipo de variante é mantido.  
  
-   **variant_t (VARIANT &***varSrc* **, bool**`fCopy`**)** constrói um `_variant_t` objeto a partir de um existente  **VARIANT** objeto. Se `fCopy` é **false**, o **VARIANT** objeto está anexado ao novo objeto sem fazer uma cópia.  
  
-   **variant_t (curto***sSrc* **, VARTYPE**`vtSrc`**= VT_I2)** constrói um `_variant_t` objeto do tipo `VT_I2` ou `VT_BOOL` de um **curto** valor inteiro. Qualquer outro **VARTYPE** resulta em um `E_INVALIDARG` erro.  
  
-   **variant_t (longo** `lSrc` **, VARTYPE**`vtSrc`**= VT_I4)** constrói um `_variant_t` objeto do tipo `VT_I4`, `VT_BOOL`, ou `VT_ERROR`de um **longo** valor inteiro. Qualquer outro **VARTYPE** resulta em um `E_INVALIDARG` erro.  
  
-   **variant_t (float**`fltSrc`**)** constrói um `_variant_t` objeto do tipo `VT_R4` de um **float** valor numérico.  
  
-   **variant_t (double** `dblSrc` **, VARTYPE**`vtSrc`**= VT_R8)** constrói um `_variant_t` objeto do tipo `VT_R8` ou `VT_DATE` de um **duplo** valor numérico. Qualquer outro **VARTYPE** resulta em um `E_INVALIDARG` erro.  
  
-   **variant_t (CY &**`cySrc`**)** constrói um `_variant_t` objeto do tipo `VT_CY` de um **CY** objeto.  
  
-   **variant_t ( bstr_t &**`bstrSrc`**)** constrói um `_variant_t` objeto do tipo `VT_BSTR` de um `_bstr_t` objeto. Um novo `BSTR` é alocado.  
  
-   **variant_t (wchar_t \***  *wstrSrc***)** constrói um `_variant_t` objeto do tipo `VT_BSTR` de uma cadeia de caracteres Unicode. Um novo `BSTR` é alocado.  
  
-   **variant_t (char\***`strSrc`**)** constrói um `_variant_t` objeto do tipo `VT_BSTR` de uma cadeia de caracteres. Um novo `BSTR` é alocado.  
  
-   **variant_t (bool**`bSrc`**)** constrói um `_variant_t` objeto do tipo `VT_BOOL` de uma `bool` valor.  
  
-   **variant_t (IUnknown\***  `pIUknownSrc` **, bool**`fAddRef`**= true)** constrói um `_variant_t` objeto do tipo **VT_UNKNOWN** de um ponteiro de interface COM. Se `fAddRef` é **true**, em seguida, `AddRef` é chamado no ponteiro de interface fornecida para corresponder a chamada para **versão** que ocorrerá quando o `_variant_t` objeto é destruído. Cabe a você chamar **versão** no ponteiro de interface fornecido. Se `fAddRef` é **false**, este construtor assume a propriedade do ponteiro de interface fornecida; não chame **versão** no ponteiro de interface fornecido.  
  
-   **variant_t (IDispatch\***  `pDispSrc` **, bool**`fAddRef`**= true)** constrói um `_variant_t` objeto do tipo **VT_DISPATCH** de um ponteiro de interface COM. Se `fAddRef` é **true**, em seguida, `AddRef` é chamado no ponteiro de interface fornecida para corresponder a chamada para **versão** que ocorrerá quando o `_variant_t` objeto é destruído. Cabe a você chamar **versão** no ponteiro de interface fornecido. Se **fAddRef** é false, o construtor assume a propriedade do ponteiro de interface fornecida; não chame **versão** no ponteiro de interface fornecido.  
  
-   **variant_t (DECIMAL &**`decSrc`**)** constrói um `_variant_t` objeto do tipo **VT_DECIMAL** de um **DECIMAL** valor.  
  
-   **variant_t (BYTE**`bSrc`**)** constrói um `_variant_t` objeto do tipo `VT_UI1` de um **bytes** valor.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)