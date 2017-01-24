---
title: "Bool auto_handle::operator | Microsoft Docs"
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
  - "auto_handle.operator bool"
  - "msclr.auto_handle.operator bool"
  - "operator bool"
  - "msclr::auto_handle::operator bool"
  - "auto_handle::operator bool"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Bool auto_handle::operator"
ms.assetid: 2e535e99-cf87-4008-b588-02c587d77453
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Bool auto_handle::operator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Operador para usar `auto_handle` em uma expressão condicional.  
  
## Sintaxe  
  
```  
operator bool();  
```  
  
## Valor de retorno  
 `true` se o objeto for válido; ajustado `false` de outra forma.  
  
## Comentários  
 Esse operador é convertido na verdade `_detail_class::_safe_bool` que é mais segura que `bool` porque ela não pode ser convertido em um tipo integral.  
  
## Exemplo  
  
```  
// msl_auto_handle_operator_bool.cpp  
// compile with: /clr  
#include <msclr\auto_handle.h>  
  
using namespace System;  
using namespace msclr;  
  
int main() {  
   auto_handle<String> s1;  
   auto_handle<String> s2 = "hi";  
   if ( s1 ) Console::WriteLine( "s1 is valid" );  
   if ( !s1 ) Console::WriteLine( "s1 is invalid" );  
   if ( s2 ) Console::WriteLine( "s2 is valid" );  
   if ( !s2 ) Console::WriteLine( "s2 is invalid" );  
   s2.reset();  
   if ( s2 ) Console::WriteLine( "s2 is now valid" );  
   if ( !s2 ) Console::WriteLine( "s2 is now invalid" );  
}  
```  
  
  **o s1 não é válido**  
**s2 é válido**  
**s2 agora é inválido**   
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ auto\_handle.h\>  
  
 msclr de**Namespace**  
  
## Consulte também  
 [Membros auto\_handle](../dotnet/auto-handle-members.md)   
 [auto\_handle::operator\!](../dotnet/auto-handle-operator-logical-not.md)