---
title: C3225 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3225
dev_langs:
- C++
helpviewer_keywords:
- C3225
ms.assetid: f5f66973-256e-4298-ac46-c87819cbde34
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8f9f6691ddacf6b3c1347b9fd4cac134433741a6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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