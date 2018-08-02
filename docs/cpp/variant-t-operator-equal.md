---
title: _variant_t::Operator = | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _variant_t::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator= [C++], variant
- operator = [C++], variant
- = operator [C++], with specific Visual C++ objects
ms.assetid: 77622723-6e49-4dec-9e0f-fa74028f1a3c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d757c645ae131b88ffb99e571d1e08214eda8129
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39462859"
---
# <a name="varianttoperator-"></a>_variant_t::operator =
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
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3***)** atribui uma existente `VARIANT` para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;pvarSrc&lt;2}{3&gt;)&lt;3***)** atribui uma existente `VARIANT` para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;var_t_src&lt;2}{3&gt;)&lt;3***)** atribui uma existente `_variant_t` do objeto para um `_variant_t` objeto.      
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;SSRC&lt;2}{3&gt;)&lt;3***)** atribui uma **curto** valor inteiro para um `_variant_t` objeto.  
  
-   **operador = (**`lSrc`**)** atribui uma **longo** valor inteiro para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;fltsrc&lt;2}{3&gt;)&lt;3***)** atribui uma **float** valor numérico a um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;dblsrc&lt;2}{3&gt;)&lt;3***)** atribui uma **double** valor numérico a um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;cysrc&lt;2}{3&gt;)&lt;3***)** atribui uma `CY` do objeto para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;bstrsrc&lt;2}{3&gt;)&lt;3***)** atribui uma `BSTR` do objeto para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;wstrsrc&lt;2}{3&gt;)&lt;3***)** atribui uma cadeia de caracteres Unicode para um `_variant_t` objeto.  
  
-   **operador = (**`strSrc`**)** atribui uma cadeia de caracteres multibyte para um `_variant_t` objeto.  
  
-   **operador = (** `bSrc` **)** atribui uma **bool** valor para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;pdispsrc&lt;2}{3&gt;)&lt;3***)** atribui uma `VT_DISPATCH` do objeto para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;piunknownsrc&lt;2}{3&gt;)&lt;3***)** atribui uma `VT_UNKNOWN` do objeto para um `_variant_t` objeto.  
  
-   **operador = (***1&gt;Operator=(&lt;1}{2&gt;decsrc&lt;2}{3&gt;)&lt;3***)** atribui uma `DECIMAL` valor para um `_variant_t` objeto.  
  
-   **operador = (** `bSrc` **)** atribui uma `BYTE` valor para um `_variant_t` objeto.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)