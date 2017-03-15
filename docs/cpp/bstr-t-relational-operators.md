---
title: "Operadores relacionais _bstr_t | Microsoft Docs"
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
  - "_bstr_t::operator>"
  - "_bstr_t::operator=="
  - "_bstr_t::operator>="
  - "_bstr_t::operator!="
  - "_bstr_t::operator<"
  - "_bstr_t::operator<="
  - "_bstr_t::operator!"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador !="
  - "Operador <, comparando objetos específicos"
  - "Operador <=, com objetos específicos"
  - "Operador ==, com objetos Visual C++ específicos"
  - "Operador >, comparando objetos específicos"
  - "Operador >=, comparando objetos específicos"
  - "Operador !=, operadores relacionais"
  - "Operador <, bstr"
  - "Operador <=, bstr"
  - "Operador ==, bstr"
  - "Operador >, bstr"
  - "Operador >=, bstr"
  - "operator!=, operadores relacionais"
  - "operator<, bstr"
  - "operator<=, bstr"
  - "operator==, bstr"
  - "operator>=, bstr"
  - "operadores relacionais, Classe _bstr_t"
ms.assetid: e153da72-37c3-4d8a-b8eb-730d65da64dd
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores relacionais _bstr_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Compara dois objetos `_bstr_t`.  
  
## Sintaxe  
  
```  
  
      bool operator!( ) const throw( );   
bool operator==(  
   const _bstr_t& str   
) const throw( );  
bool operator!=(  
   const _bstr_t& str   
) const throw( );  
bool operator<(  
   const _bstr_t& str   
) const throw( );  
bool operator>(  
   const _bstr_t& str   
) const throw( );  
bool operator<=(  
   const _bstr_t& str   
) const throw( );  
bool operator>=(  
   const _bstr_t& str   
) const throw( );  
```  
  
## Comentários  
 Esses operadores comparam dois objetos `_bstr_t` lexicograficamente.  Os operadores retornam **true** se as comparações forem mantidas. Caso contrário, eles retornam **false**.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_bstr\_t](../cpp/bstr-t-class.md)