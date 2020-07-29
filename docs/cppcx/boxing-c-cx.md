---
title: Conversão boxing (C++/CX)
ms.date: 12/30/2016
ms.assetid: edfb12fa-2a9b-42f6-bdac-d4d76cb8274e
ms.openlocfilehash: 59c7f8ec56a912ed993316fba093b87bd85e16b1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233529"
---
# <a name="boxing-ccx"></a>Conversão boxing (C++/CX)

A *conversão boxing* está encapsulando uma variável de tipo de valor, como [Windows:: Foundation::D atetime](/uwp/api/windows.foundation.datetime)— ou um tipo escalar fundamental, como **`int`** — em uma classe ref quando a variável é passada para um método que usa [Platform:: Object ^](../cppcx/platform-object-class.md) como seu tipo de entrada.

## <a name="passing-a-value-type-to-an-object-parameter"></a>Passando um tipo de valor a um parâmetro Object^

Embora não seja preciso executar boxing explicitamente de uma variável para passá-la a um parâmetro de método do tipo [Platform::Object^](../cppcx/platform-object-class.md), você precisa fazer a conversão explícita de volta ao tipo original ao recuperar valores cujo boxing foi realizado anteriormente.

[!code-cpp[cx_boxing#01](../cppcx/codesnippet/CPP/cx_boxing/class1.cpp#01)]

### <a name="using-platformiboxt-to-support-nullable-value-types"></a>Usando platform:: IBox \<T> para dar suporte a tipos de valor anulável

C# e Visual Basic oferecem suporte ao conceito de tipos de valor anuláveis. No C++/CX, você pode usar o `Platform::IBox<T>` tipo para expor métodos públicos que dão suporte a parâmetros de tipo de valor anulável. O exemplo a seguir mostra um método público C++/CX que retorna NULL quando um chamador C# passa NULL para um dos argumentos.

[!code-cpp[cx_boxing#02](../cppcx/codesnippet/CPP/cx_boxing/class1.h#02)]

Em um cliente XAML do C#, você pode consumi-lo deste modo:

```

// C# client code
    BoxingDemo.Class1 obj = new BoxingDemo.Class1();
    int? a = null;
    int? b = 5;
    var result = obj.Multiply(a,b); //result = null
```

## <a name="see-also"></a>Confira também

[Type System (C++/CX)](../cppcx/type-system-c-cx.md)<br/>
[Conversão (C++/CX)](../cppcx/casting-c-cx.md)<br/>
[Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
