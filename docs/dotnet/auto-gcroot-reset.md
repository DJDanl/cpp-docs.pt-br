---
title: "auto_gcroot::reset | Microsoft Docs"
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
  - "msclr::auto_gcroot::reset"
  - "auto_gcroot::reset"
  - "msclr.auto_gcroot.reset"
  - "auto_gcroot.reset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método reset"
ms.assetid: dd58467f-3885-4a15-99fb-ed6dd5d19622
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# auto_gcroot::reset
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Destruir o objeto de propriedade atual e faça opcionalmente a possessão de um novo objeto.  
  
## Sintaxe  
  
```  
void reset(  
   _element_type _new_ptr = nullptr  
);  
```  
  
#### Parâmetros  
 `_new_ptr`  
 \(Opcional\) O novo objeto.  
  
## Exemplo  
  
```  
// msl_auto_gcroot_reset.cpp  
// compile with: /clr  
#include <msclr\auto_gcroot.h>  
  
using namespace System;  
using namespace msclr;  
  
ref class ClassA {  
   String^ m_s;  
public:  
   ClassA( String^ s ) : m_s( s ) {  
      Console::WriteLine( "ClassA constructor: " + m_s );  
   }  
   ~ClassA() {  
      Console::WriteLine( "ClassA destructor: " + m_s );  
   }  
  
   void PrintHello() {  
      Console::WriteLine( "Hello from {0} A!", m_s );  
   }  
};  
  
int main()  
{  
   auto_gcroot<ClassA^> agc1 = gcnew ClassA( "first" );  
   agc1->PrintHello();  
  
   ClassA^ ha = gcnew ClassA( "second" );  
   agc1.reset( ha ); // release first object, reference second  
   agc1->PrintHello();  
  
   agc1.reset(); // release second object, set to nullptr  
  
   Console::WriteLine( "done" );  
}  
```  
  
  **O construtor de ClassA: primeiro**  
**Hello world primeiro de\!**  
**O construtor de ClassA: segundo**  
**Destruidor de ClassA: primeiro**  
**Hello world dependendo de A\!**  
**Destruidor de ClassA: segundo**  
**feita**   
## Requisitos  
 msclr \<de**Arquivo de cabeçalho** \\ auto\_gcroot.h\>  
  
 msclr de**Namespace**  
  
## Consulte também  
 [Membros auto\_gcroot](../dotnet/auto-gcroot-members.md)   
 [auto\_gcroot::release](../dotnet/auto-gcroot-release.md)   
 [auto\_gcroot::attach](../dotnet/auto-gcroot-attach.md)