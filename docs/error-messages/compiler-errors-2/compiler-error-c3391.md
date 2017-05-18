---
title: C3391 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3391
dev_langs:
- C++
helpviewer_keywords:
- C3391
ms.assetid: c32532b9-7db4-4ccd-84b9-479e5a1a19d1
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: b551b1a7e0ae03a7de5108a1d114155786972847
ms.openlocfilehash: 7b5922ccf353162dc32c99e3818227639d0f5985
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3391"></a>C3391 de erro do compilador
'type_arg': argumento de tipo inválido para parâmetro genérico param de genérico 'generic_type' deve ser um tipo de valor não nulo  
  
Um tipo genérico foi instanciado incorretamente. Verifique a definição de tipo. Para obter mais informações, consulte <xref:System.Nullable>e [genéricos](../../windows/generics-cpp-component-extensions.md).</xref:System.Nullable>  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir usa c# para criar um componente que contém um tipo genérico que tem determinadas restrições que não oferecem suporte à criação de tipos genéricos no C + + / CLI. Para obter mais informações, consulte [restrições em parâmetros de tipo](/dotnet/articles/csharp/programming-guide/generics/constraints-on-type-parameters).  
  
```cs  
// C3391.cs  
// Compile by using: csc /target:library C3391.cs  
// a C# program  
public class GR<N>  
where N : struct {}  
```  
  
Quando o componente C3391.dll estiver disponível, o exemplo a seguir gera C3391.  
  
```cpp  
// C3391_b.cpp  
// Compile by using: cl /clr C3391_b.cpp  
#using <C3391.dll>  
using namespace System;  
value class VClass {};  
  
int main() {  
   GR< Nullable<VClass> >^ a =   
      gcnew GR< Nullable<VClass> >();   // C3391 can't be Nullable  
   GR<VClass>^ aa = gcnew GR<VClass>(); // OK  
}  
```
