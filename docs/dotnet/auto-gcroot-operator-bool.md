---
title: "Bool auto_gcroot::operator | Microsoft Docs"
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
  - "auto_gcroot.operator bool"
  - "auto_gcroot::operator bool"
  - "msclr.auto_gcroot.operator bool"
  - "msclr::auto_gcroot::operator bool"
  - "operator bool"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador bool"
ms.assetid: 87d38498-4221-4de8-8d02-c2dd2e6274ec
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Bool auto_gcroot::operator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Operador para usar `auto_gcroot` em uma expressão condicional.  
  
## Sintaxe  
  
```  
operator bool() const;  
```  
  
## Valor de retorno  
 `true` se o objeto for válido; ajustado `false` de outra forma.  
  
## Comentários  
 Esse operador é convertido na verdade `_detail_class::_safe_bool` que é mais segura que `bool` porque ela não pode ser convertido em um tipo integral.  
  
## Exemplo  
  
```  
// msl_auto_gcroot_operator_bool.cpp  
// compile with: /clr  
#include <msclr\auto_gcroot.h>  
  
using namespace System;  
using namespace msclr;  
  
int main() {  
   auto_gcroot<String^> s;  
   if ( s ) Console::WriteLine( "s is valid" );  
   if ( !s ) Console::WriteLine( "s is invalid" );  
   s = "something";  
   if ( s ) Console::WriteLine( "now s is valid" );  
   if ( !s ) Console::WriteLine( "now s is invalid" );  
   s.reset();  
   if ( s ) Console::WriteLine( "now s is valid" );  
   if ( !s ) Console::WriteLine( "now s is invalid" );  
}  
```  
  
  **s é inválido**  
**agora s é válido**  
**agora s é inválido**   
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ auto\_gcroot.h\>  
  
 msclr de**Namespace**  
  
## Consulte também  
 [Membros auto\_gcroot](../dotnet/auto-gcroot-members.md)   
 [auto\_gcroot::operator\!](../dotnet/auto-gcroot-operator-logical-not.md)