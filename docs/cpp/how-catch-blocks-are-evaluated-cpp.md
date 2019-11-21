---
title: Como blocos catch são avaliados (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- try-catch keyword [C++], catchable types
- catch keyword [C++], types of catch handlers
- C++ exception handling, catch handlers
- exception handling, catching and deleting exceptions
- types [C++], exception handling
ms.assetid: 202dbf07-8ace-4b3b-b3ae-4b45c275e0b4
ms.openlocfilehash: 027dc87923a588ea891dbf6dd835e2baba75a1cb
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245852"
---
# <a name="how-catch-blocks-are-evaluated-c"></a>Como blocos catch são avaliados (C++)

O C++ permite lançar exceções de qualquer tipo, embora seja recomendável lançar os tipos derivados de std::exception. A C++ exception can be caught by a **catch** handler that specifies the same type as the thrown exception, or by a handler that can catch any type of exception.

Se o tipo de exceção lançada for uma classe, que também tenha uma classe base (ou classes), ela pode ser capturada pelos manipuladores que aceitam classes base do tipo da exceção, bem como por referências às bases do tipo da exceção. Observe que, quando uma exceção é capturada por uma referência, ela é associada ao objeto de exceção lançado real; caso contrário, é uma cópia (bem semelhante a um argumento para uma função).

When an exception is thrown, it may be caught by the following types of **catch** handlers:

- Um manipulador que pode aceitar qualquer tipo (usando a sintaxe de reticências).

- A handler that accepts the same type as the exception object; because it is a copy, **const** and **volatile** modifiers are ignored.

- Um manipulador que aceita uma referência para mesmo tipo do objeto de exceção.

- A handler that accepts a reference to a **const** or **volatile** form of the same type as the exception object.

- A handler that accepts a base class of the same type as the exception object; since it is a copy, **const** and **volatile** modifiers are ignored. The **catch** handler for a base class must not precede the **catch** handler for the derived class.

- Um manipulador que aceita uma referência a uma classe base do mesmo tipo do objeto de exceção.

- A handler that accepts a reference to a **const** or **volatile** form of a base class of the same type as the exception object.

- Um manipulador que aceita um ponteiro no qual um objeto de ponteiro gerado pode ser convertido pelas regras padrão de conversão de ponteiro.

The order in which **catch** handlers appear is significant, because handlers for a given **try** block are examined in order of their appearance. Por exemplo, é um erro para colocar o manipulador de uma classe base antes do manipulador de uma classe derivada. After a matching **catch** handler is found, subsequent handlers are not examined. As a result, an ellipsis **catch** handler must be the last handler for its **try** block. Por exemplo:

```cpp
// ...
try
{
    // ...
}
catch( ... )
{
    // Handle exception here.
}
// Error: the next two handlers are never examined.
catch( const char * str )
{
    cout << "Caught exception: " << str << endl;
}
catch( CExcptClass E )
{
    // Handle CExcptClass exception here.
}
```

In this example, the ellipsis **catch** handler is the only handler that is examined.

## <a name="see-also"></a>Consulte também

[Modern C++ best practices for exceptions and error handling](../cpp/errors-and-exception-handling-modern-cpp.md)