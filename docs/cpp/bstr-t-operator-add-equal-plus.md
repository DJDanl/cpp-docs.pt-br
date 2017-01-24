---
title: "_bstr_t::operator +=, + | Microsoft Docs"
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
  - "_bstr_t::operator+"
  - "_bstr_t::operator+="
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador +, Objetos _bstr_t"
  - "Operador +=, acrescentando cadeias de caracteres"
ms.assetid: d28316ce-c2c8-4a38-bdb3-44fa4e582c44
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _bstr_t::operator +=, +
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Acrescenta caracteres ao final do objeto `_bstr_t` ou concatena duas cadeias de caracteres.  
  
## Sintaxe  
  
```  
  
      _bstr_t& operator+=(  
   const _bstr_t& s1   
);  
_bstr_t operator+(  
   const _bstr_t& s1   
);  
friend _bstr_t operator+(  
   const char* s2,  
   const _bstr_t& s1   
);  
friend _bstr_t operator+(  
   const wchar_t* s3,  
   const _bstr_t& s1   
);  
```  
  
#### Parâmetros  
 *s1*  
 Um objeto `_bstr_t`.  
  
 *s2*  
 Uma cadeia de caracteres multibyte.  
  
 `s3`  
 Uma cadeia de caracteres Unicode.  
  
## Comentários  
 Esses operadores executam a concatenação de cadeias de caracteres:  
  
-   **operador\+\=\(**  *s1*  **\)** Anexa os caracteres em `BSTR` encapsulado de *s1* ao final do `BSTR`encapsulado deste objeto.  
  
-   **operador\+\(**  *s1*  **\)** Retorna um novo `_bstr_t`, formado pela concatenação de `BSTR` deste objeto com o de *s1*.  
  
-   **operador\+\(**  *s2*  **&#124;**  *s1*  **\)** Retorna um novo `_bstr_t`, formado pela concatenação de uma cadeia de caracteres multibyte *s2*, convertida para Unicode, com `BSTR` encapsulada em *s1*.  
  
-   **operador\+\(**  `s3` **,**  *s1*  **\)** Retorna um novo `_bstr_t`, formado pela concatenação de uma cadeia de caracteres Unicode `s3` com `BSTR` encapsulada em *s1*.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_bstr\_t](../cpp/bstr-t-class.md)