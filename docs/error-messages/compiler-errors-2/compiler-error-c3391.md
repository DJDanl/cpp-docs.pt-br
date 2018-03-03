---
title: C3391 de erro do compilador | Microsoft Docs
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c5302939fa8a77a244c039d45c10ea5596897240
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3391"></a>C3391 de erro do compilador
'type_arg': argumento de tipo inválido para parâmetro de generic 'generic_type' do parâmetro genérico deve ser um tipo de valor não nulo  
  
Um tipo genérico foi instanciado incorretamente. Verifique a definição de tipo. Para obter mais informações, consulte <xref:System.Nullable> e [genéricos](../../windows/generics-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir usa c# para criar um componente que contém um tipo genérico que tem determinadas restrições que não são suportadas na criação de tipos genéricos em C + + CLI. Para obter mais informações, consulte [Restrições a parâmetros de tipo](/dotnet/csharp/programming-guide/generics/constraints-on-type-parameters).  
  
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