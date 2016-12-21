---
title: "auto_gcroot::swap | Microsoft Docs"
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
  - "msclr.auto_gcroot.swap"
  - "msclr::auto_gcroot::swap"
  - "auto_gcroot::swap"
  - "auto_gcroot.swap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "auto_gcroot::swap"
ms.assetid: 4915c629-6a53-432c-8155-3a7511dc70cb
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# auto_gcroot::swap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Objetos de troca com outro `auto_gcroot`.  
  
## Sintaxe  
  
```  
void swap(  
   auto_gcroot<_element_type> & _right  
);  
```  
  
#### Parâmetros  
 `_right`  
 `auto_gcroot` com a qual alternar objetos.  
  
## Exemplo  
  
```  
// msl_auto_gcroot_swap.cpp  
// compile with: /clr  
#include <msclr\auto_gcroot.h>  
  
using namespace System;  
using namespace msclr;  
  
int main() {  
   auto_gcroot<String^> s1 = "string one";  
   auto_gcroot<String^> s2 = "string two";  
  
   Console::WriteLine( "s1 = '{0}', s2 = '{1}'",  
      s1->ToString(), s2->ToString() );  
   s1.swap( s2 );  
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
 [Membros auto\_gcroot](../dotnet/auto-gcroot-members.md)   
 [Função swap \(auto\_gcroot\)](../dotnet/swap-function-auto-gcroot.md)