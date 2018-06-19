---
title: C3391 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3391
dev_langs:
- C++
helpviewer_keywords:
- C3391
ms.assetid: c32532b9-7db4-4ccd-84b9-479e5a1a19d1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 28615d85eca534966a4d8b90cef20ea577e0d592
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33256608"
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