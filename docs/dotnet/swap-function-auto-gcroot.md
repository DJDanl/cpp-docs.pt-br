---
title: "Fun&#231;&#227;o swap (auto_gcroot) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "msclr::swap"
  - "msclr.swap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função swap"
ms.assetid: 2fe8146b-a7f7-445a-9ae9-53b5556be701
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o swap (auto_gcroot)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Objetos de troca entre um `auto_gcroot` e outros.  
  
## Sintaxe  
  
```  
template<typename _element_type>  
void swap(  
   auto_gcroot<_element_type> & _left,  
   auto_gcroot<_element_type> & _right  
);  
```  
  
#### Parâmetros  
 `_left`  
 Um `auto_gcroot`.  
  
 `_right`  
 Outro `auto_gcroot`.  
  
## Exemplo  
  
```  
// msl_swap_auto_gcroot.cpp  
// compile with: /clr  
#include <msclr\auto_gcroot.h>  
  
using namespace System;  
using namespace msclr;  
  
int main() {  
   auto_gcroot<String^> s1 = "string one";  
   auto_gcroot<String^> s2 = "string two";  
  
   Console::WriteLine( "s1 = '{0}', s2 = '{1}'",  
      s1->ToString(), s2->ToString() );  
   swap( s1, s2 );  
   Console::WriteLine( "s1 = '{0}', s2 = '{1}'",  
      s1->ToString(), s2->ToString() );  
}  
```  
  
  **s1 \= “cadeia de caracteres, s2 uma” \= “cadeia de caracteres dois”**  
**s1 \= “cadeia de caracteres dois”, s2 \= “cadeia de caracteres uma”**   
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ auto\_gcroot.h\>  
  
 msclr de**Namespace**  
  
## Consulte também  
 [auto\_gcroot](../dotnet/auto-gcroot.md)   
 [auto\_gcroot::swap](../dotnet/auto-gcroot-swap.md)