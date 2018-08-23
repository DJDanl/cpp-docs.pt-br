---
title: Conversão boxing (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: edfb12fa-2a9b-42f6-bdac-d4d76cb8274e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e70b908bddbf7034e1d60f16cb0e492c0a707586
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42598874"
---
# <a name="boxing-ccx"></a>Conversão boxing (C++/CX)
*Boxing* é o encapsulamento de uma variável de tipo de valor, como [Windows::Foundation::DateTime](http://msdn.microsoft.com/library/windows/apps/windows.foundation.datetime.aspx)(ou de um tipo escalar fundamental, como `int`), em uma classe ref quando a variável é transmitida para um método que usa [Platform::Object^](../cppcx/platform-object-class.md) como seu tipo de entrada.  
  
## <a name="passing-a-value-type-to-an-object-parameter"></a>Passando um tipo de valor a um parâmetro Object^  
 Embora não seja preciso executar boxing explicitamente de uma variável para passá-la a um parâmetro de método do tipo [Platform::Object^](../cppcx/platform-object-class.md), você precisa fazer a conversão explícita de volta ao tipo original ao recuperar valores cujo boxing foi realizado anteriormente.  
  
 [!code-cpp[cx_boxing#01](../cppcx/codesnippet/CPP/cx_boxing/class1.cpp#01)]  
  
### <a name="using-platformiboxt-to-support-nullable-value-types"></a>Usando Platform:: ibox\<T > para dar suporte a tipos de valor anulável  
 C# e Visual Basic oferecem suporte ao conceito de tipos de valor anuláveis. No C + + c++ /CX, você pode usar o `Platform::IBox<T>` tipo para expor os métodos públicos que oferecem suporte a parâmetros de tipo de valor anulável. O exemplo a seguir mostra um C + + / método público de CX que retorna nulo quando um chamador c# passa nulo para um dos argumentos.  
  
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
 [Conversão (C++ c++ /CX)](../cppcx/casting-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)