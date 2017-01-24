---
title: "Erro do Compilador C3114 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3114"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3114"
ms.assetid: b5d2df4f-87d0-4292-9981-25c6a6013c05
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3114
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“argumento”: não um argumento de atributo nomeado válido  
  
 Para que um membro de dados da classe do atributo é um argumento nomeado válido, ele não deve ser marcado `static`, `const`, ou `literal`.  Se uma propriedade, a propriedade não deve ser `static` e deve ter obter e acessadores de mídias.  
  
 Para obter mais informações, consulte [property](../../windows/property-cpp-component-extensions.md) e [User\-Defined Attributes](../../windows/user-defined-attributes-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C3114.  
  
```  
// C3114.cpp  
// compile with: /clr /c  
public ref class A : System::Attribute {  
public:  
   static property int StaticProp {  
      int get();  
   }  
  
   property int Prop2 {  
      int get();  
      void set(int i);  
   }  
};  
  
[A(StaticProp=123)]   // C3114  
public ref class R {};  
  
[A(Prop2=123)]   // OK  
public ref class S {};  
```