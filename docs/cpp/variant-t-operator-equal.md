---
title: _variant_t::Operator = | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: _variant_t::operator=
dev_langs: C++
helpviewer_keywords:
- operator= [C++], variant
- operator = [C++], variant
- = operator [C++], with specific Visual C++ objects
ms.assetid: 77622723-6e49-4dec-9e0f-fa74028f1a3c
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 88998f18c750e064ee8eae254ca7ee4487be7176
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
-   **operador = (***varSrc***)** atribui uma existente **VARIANT** para um `_variant_t` objeto.  
  
-   **operador = (***pVarSrc***)** atribui uma existente **VARIANT** para um `_variant_t` objeto.  
  
-   **operador = (***var_t_Src***)** atribui uma existente `_variant_t` o objeto para um `_variant_t` objeto.  
  
-   **operador = (***sSrc***)** atribui um **curto** valor inteiro para um `_variant_t` objeto.  
  
-   **operador = (**`lSrc`**)** atribui um **longo** valor inteiro para um `_variant_t` objeto.  
  
-   **operador = (***fltSrc***)** atribui um **float** valor numérico para um `_variant_t` objeto.  
  
-   **operador = (***dblSrc***)** atribui um **duplo** valor numérico para um `_variant_t` objeto.  
  
-   **operador = (***cySrc***)** atribui um **CY** o objeto para um `_variant_t` objeto.  
  
-   **operador = (***bstrSrc***)** atribui um `BSTR` o objeto para um `_variant_t` objeto.  
  
-   **operador = (***wstrSrc***)** atribui uma cadeia de caracteres Unicode para um `_variant_t` objeto.  
  
-   **operador = (**`strSrc`**)** atribui uma cadeia de caracteres multibyte para um `_variant_t` objeto.  
  
-   **operador = (** `bSrc` **)** atribui um `bool` valor para um `_variant_t` objeto.  
  
-   **operador = (***pDispSrc***)** atribui um **VT_DISPATCH** o objeto para um `_variant_t` objeto.  
  
-   **operador = (***pIUnknownSrc***)** atribui um **VT_UNKNOWN** o objeto para um `_variant_t` objeto.  
  
-   **operador = (***decSrc***)** atribui um **DECIMAL** valor para um `_variant_t` objeto.  
  
-   **operador = (** `bSrc` **)** atribui um **bytes** valor para um `_variant_t` objeto.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)