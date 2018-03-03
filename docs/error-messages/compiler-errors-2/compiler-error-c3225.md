---
title: C3225 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3225
dev_langs:
- C++
helpviewer_keywords:
- C3225
ms.assetid: f5f66973-256e-4298-ac46-c87819cbde34
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9c189e2f4a0af7363f5bb988c9911bd90eb72809
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3225"></a>C3225 de erro do compilador
argumento de tipo genérico para 'arg' não pode ser 'type', ele deve ser um tipo de valor ou lidar com tipo  
  
 O argumento de tipo genérico não era do tipo correto.  
  
 Para obter mais informações, consulte [Genéricos](../../windows/generics-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 Não é possível instanciar um tipo genérico com um tipo nativo. O exemplo a seguir gera C3225.  
  
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
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um componente usando o c#. Observe que a restrição Especifica que o tipo genérico só pode ser instanciado com um tipo de valor.  
  
```  
// C3225_b.cs  
// compile with: /target:library  
// a C# program  
public class MyList<T> where T: struct {}  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo consome c#-autoria do componente e viola a restrição que MyList só pode ser instanciado com um tipo de valor diferente de <xref:System.Nullable>. O exemplo a seguir gera C3225.  
  
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