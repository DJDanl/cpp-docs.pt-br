---
title: "Conversão boxing (C + + CX) | Microsoft Docs"
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: edfb12fa-2a9b-42f6-bdac-d4d76cb8274e
caps.latest.revision: "12"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5d953e35c0fe238dc8dee76ad6c2d5aab7a0ab1b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="boxing-ccx"></a>Conversão boxing (C++/CX)
*Boxing* é o encapsulamento de uma variável de tipo de valor, como [Windows::Foundation::DateTime](http://msdn.microsoft.com/library/windows/apps/windows.foundation.datetime.aspx)(ou de um tipo escalar fundamental, como `int`), em uma classe ref quando a variável é transmitida para um método que usa [Platform::Object^](../cppcx/platform-object-class.md) como seu tipo de entrada.  
  
## <a name="passing-a-value-type-to-an-object-parameter"></a>Passando um tipo de valor a um parâmetro Object^  
 Embora não seja preciso executar boxing explicitamente de uma variável para passá-la a um parâmetro de método do tipo [Platform::Object^](../cppcx/platform-object-class.md), você precisa fazer a conversão explícita de volta ao tipo original ao recuperar valores cujo boxing foi realizado anteriormente.  
  
 [!code-cpp[cx_boxing#01](../cppcx/codesnippet/CPP/cx_boxing/class1.cpp#01)]  
  
### <a name="using-platformiboxt-to-support-nullable-value-types"></a>Usando Platform:: ibox\<T > para dar suporte a tipos de valor anuláveis  
 C# e Visual Basic oferecem suporte ao conceito de tipos de valor anuláveis. Em C + + CX, você pode usar o `Platform::IBox<T>` tipo para expor os métodos públicos que oferecem suporte a parâmetros de tipo de valor anuláveis. O exemplo a seguir mostra um C + + método público de CX que retorna nulo quando um chamador c# passa nulo para um dos argumentos.  
  
 [!code-cpp[cx_boxing#02](../cppcx/codesnippet/CPP/cx_boxing/class1.h#02)]  
  
 Em um cliente XAML do C#, você pode consumi-lo deste modo:  
  
```  
  
// C# client code  
    BoxingDemo.Class1 obj = new BoxingDemo.Class1();  
    int? a = null;  
    int? b = 5;  
    var result = obj.Multiply(a,b); //result = null  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos (C++/CX)](../cppcx/type-system-c-cx.md)   
 [Conversão (C + + CX)](../cppcx/casting-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)