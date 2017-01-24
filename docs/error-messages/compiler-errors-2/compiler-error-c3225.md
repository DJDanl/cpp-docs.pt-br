---
title: "Erro do Compilador C3225 | Microsoft Docs"
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
  - "C3225"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3225"
ms.assetid: f5f66973-256e-4298-ac46-c87819cbde34
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3225
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o argumento do tipo genérico para o “arg” não pode ser “, tipo” deve ser um tipo de valor ou de identificador  
  
 O argumento do tipo genérico não é do tipo correto.  
  
 Para obter mais informações, consulte [Generics](../../windows/generics-cpp-component-extensions.md).  
  
## Exemplo  
 Você não pode criar uma instância de um tipo genérico com um tipo nativo.  O exemplo a seguir produz C3225.  
  
```  
// C3225.cpp  
// compile with: /clr  
class A {};  
  
ref class B {};  
  
generic <class T>  
ref class C {};  
  
int main() {  
   C<A>^ c = gcnew C<A>;   // C3225  
   C<B^>^ c2 = gcnew C<B^>;   // OK  
}  
```  
  
## Exemplo  
 O exemplo a seguir cria um C\# do componente.  Observe que a restrição especifica que o tipo genérico pode ser criado somente uma instância de com um tipo de valor.  
  
```  
// C3225_b.cs  
// compile with: /target:library  
// a C# program  
public class MyList<T> where T: struct {}  
```  
  
## Exemplo  
 Este exemplo utiliza o componente C\# criado, e viola a restrição que MyList pode ser criado somente uma instância de com um tipo de valor diferente <xref:System.Nullable>.  O exemplo a seguir produz C3225.  
  
```  
// C3225_c.cpp  
// compile with: /clr  
#using "C3225_b.dll"  
ref class A {};  
value class B {};  
int main() {  
   MyList<A> x;   // C3225  
   MyList<B> y;   // OK  
}  
```