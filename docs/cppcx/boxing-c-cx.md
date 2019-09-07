---
title: Conversão boxing (C++/CX)
ms.date: 12/30/2016
ms.assetid: edfb12fa-2a9b-42f6-bdac-d4d76cb8274e
ms.openlocfilehash: 90c5af31efc6523683227dbf54c85390bc98510a
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740673"
---
# <a name="boxing-ccx"></a>Conversão boxing (C++/CX)

*Boxing* é o encapsulamento de uma variável de tipo de valor, como [Windows::Foundation::DateTime](/uwp/api/windows.foundation.datetime)(ou de um tipo escalar fundamental, como `int`), em uma classe ref quando a variável é transmitida para um método que usa [Platform::Object^](../cppcx/platform-object-class.md) como seu tipo de entrada.

## <a name="passing-a-value-type-to-an-object-parameter"></a>Passando um tipo de valor a um parâmetro Object^

Embora não seja preciso executar boxing explicitamente de uma variável para passá-la a um parâmetro de método do tipo [Platform::Object^](../cppcx/platform-object-class.md), você precisa fazer a conversão explícita de volta ao tipo original ao recuperar valores cujo boxing foi realizado anteriormente.

[!code-cpp[cx_boxing#01](../cppcx/codesnippet/CPP/cx_boxing/class1.cpp#01)]

### <a name="using-platformiboxt-to-support-nullable-value-types"></a>Usando platform:: iBox\<T > para dar suporte a tipos de valor anulável

C# e Visual Basic oferecem suporte ao conceito de tipos de valor anuláveis. Em C++/CX, você pode usar o `Platform::IBox<T>` tipo para expor métodos públicos que dão suporte a parâmetros de tipo de valor anulável. O exemplo a seguir mostra C++um método público/CX que retorna NULL quando C# um chamador passa NULL para um dos argumentos.

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

[Sistema de tipos (C++/CX)](../cppcx/type-system-c-cx.md)<br/>
[Conversão (C++/CX)](../cppcx/casting-c-cx.md)<br/>
[Referência da linguagem C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
