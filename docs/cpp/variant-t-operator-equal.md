---
title: "_variant_t::operator = | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_variant_t.operator="
  - "_variant_t::operator="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador =, com objetos Visual C++ específicos"
  - "Operador =, variante"
  - "operator=, variante"
ms.assetid: 77622723-6e49-4dec-9e0f-fa74028f1a3c
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _variant_t::operator =
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
## Sintaxe  
  
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
  
## Comentários  
 O operador atribui um novo valor ao objeto `_variant_t`:  
  
-   **operator\=\(**  *varSrc*  **\)** Atribui um **VARIANT** existente a um objeto `_variant_t`.  
  
-   **operator\=\(**  *pVarSrc*  **\)** Atribui um **VARIANT** existente a um objeto `_variant_t`.  
  
-   **operator\=\(**  *var\_t\_Src*  **\)** Atribui um objeto `_variant_t` existente a um objeto `_variant_t`.  
  
-   **operator\=\(**  *sSrc*  **\)** Atribui um valor inteiro **short** a um objeto `_variant_t`.  
  
-   **operator\=\(**  `lSrc`  **\)** Atribui um valor inteiro **long** a um objeto `_variant_t`.  
  
-   **operator\=\(**  *fltSrc*  **\)** Atribui um valor numérico **float** a um objeto `_variant_t`.  
  
-   **operator\=\(**  *dblSrc*  **\)** Atribui um valor numérico **double** a um objeto `_variant_t`.  
  
-   **operator\=\(**  *cySrc*  **\)** Atribui um objeto **CY** a um objeto `_variant_t`.  
  
-   **operator\=\(**  *bstrSrc*  **\)** Atribui um objeto `BSTR` a um objeto `_variant_t`.  
  
-   **operator\=\(**  *wstrSrc*  **\)** Atribui uma cadeia de caracteres Unicode a um objeto `_variant_t`.  
  
-   **operator\=\(**  `strSrc`  **\)** Atribui uma cadeia de caracteres multibyte a um objeto `_variant_t`.  
  
-   **operator\=\(**  `bSrc` **\)** Atribui um valor `bool` a um objeto `_variant_t`.  
  
-   **operator\=\(**  *pDispSrc*  **\)** Atribui um objeto **VT\_DISPATCH** a um objeto `_variant_t`.  
  
-   **operator\=\(**  *pIUnknownSrc*  **\)** Atribui um objeto **VT\_UNKNOWN** a um objeto `_variant_t`.  
  
-   **operator\=\(**  *decSrc*  **\)** Atribui um valor **DECIMAL** a um objeto `_variant_t`.  
  
-   **operator\=\(**  `bSrc` **\)** Atribui um valor **BYTE** a um objeto `_variant_t`.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_variant\_t](../cpp/variant-t-class.md)