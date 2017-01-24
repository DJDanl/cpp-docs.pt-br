---
title: "Como definir um construtor est&#225;tico de interface (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "construtores [C++]"
  - "construtor estático de interface"
  - "construtores estáticos, interface"
ms.assetid: 1f031cb2-e94f-43dc-819b-44cf2faaaa49
caps.latest.revision: 10
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como definir um construtor est&#225;tico de interface (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma interface pode ter um construtor estático, que pode ser usado para inicializar membros de dados estáticos.  Um construtor estático será chamado no máximo uma vez, e chamado antes da primeira vez que um membro estático da interface é acessado.  
  
 Para obter mais informações sobre os construtores estáticos, consulte [Como definir construtores estáticos em uma classe ou uma estrutura](../misc/how-to-define-static-constructors-in-a-class-or-struct.md).  
  
## Exemplo  
  
```  
// mcppv2_interface_class2.cpp  
// compile with: /clr  
using namespace System;  
  
interface struct MyInterface {  
   static int i;  
   static void Test() {  
      Console::WriteLine(i);  
   }  
  
   static MyInterface() {   
      Console::WriteLine("in MyInterface static constructor");  
      i = 99;  
   }  
};  
  
ref class MyClass : public MyInterface {};  
  
int main() {  
   MyInterface::Test();  
   MyClass::MyInterface::Test();  
  
   MyInterface ^ mi = gcnew MyClass;  
   mi->Test();  
}  
```  
  
  **no construtor de MyInterface estáticos**  
**99**  
**99**  
**99**   
## Consulte também  
 [interface class](../windows/interface-class-cpp-component-extensions.md)