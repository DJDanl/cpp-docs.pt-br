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
ms.openlocfilehash: 21d68b25fa3695a9b5637dcace081424f99911d8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87188096"
---
# <a name="how-catch-blocks-are-evaluated-c"></a>Como blocos catch são avaliados (C++)

O C++ permite lançar exceções de qualquer tipo, embora seja recomendável lançar os tipos derivados de std::exception. Uma exceção de C++ pode ser detectada por um **`catch`** manipulador que especifica o mesmo tipo da exceção gerada ou por um manipulador que pode capturar qualquer tipo de exceção.

Se o tipo de exceção lançada for uma classe, que também tenha uma classe base (ou classes), ela pode ser capturada pelos manipuladores que aceitam classes base do tipo da exceção, bem como por referências às bases do tipo da exceção. Observe que, quando uma exceção é capturada por uma referência, ela é associada ao objeto de exceção lançado real; caso contrário, é uma cópia (bem semelhante a um argumento para uma função).

Quando uma exceção é lançada, ela pode ser detectada pelos seguintes tipos de **`catch`** manipuladores:

- Um manipulador que pode aceitar qualquer tipo (usando a sintaxe de reticências).

- Um manipulador que aceita o mesmo tipo que o objeto de exceção; Porque é uma cópia, **`const`** e os **`volatile`** modificadores são ignorados.

- Um manipulador que aceita uma referência para mesmo tipo do objeto de exceção.

- Um manipulador que aceita uma referência a um **`const`** **`volatile`** formulário ou do mesmo tipo que o objeto de exceção.

- Um manipulador que aceita uma classe base do mesmo tipo que o objeto de exceção; Como é uma cópia, **`const`** e os **`volatile`** modificadores são ignorados. O **`catch`** manipulador para uma classe base não deve preceder o **`catch`** manipulador para a classe derivada.

- Um manipulador que aceita uma referência a uma classe base do mesmo tipo do objeto de exceção.

- Um manipulador que aceita uma referência a um **`const`** **`volatile`** formulário ou de uma classe base do mesmo tipo que o objeto de exceção.

- Um manipulador que aceita um ponteiro no qual um objeto de ponteiro gerado pode ser convertido pelas regras padrão de conversão de ponteiro.

A ordem na qual os **`catch`** manipuladores aparecem é significativa, pois os manipuladores para um determinado **`try`** bloco são examinados em ordem de sua aparência. Por exemplo, é um erro para colocar o manipulador de uma classe base antes do manipulador de uma classe derivada. Depois que um **`catch`** manipulador correspondente é encontrado, os manipuladores subsequentes não são examinados. Como resultado, um manipulador de reticências **`catch`** deve ser o último manipulador para seu **`try`** bloco. Por exemplo:

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

Neste exemplo, o manipulador de reticências **`catch`** é o único manipulador que é examinado.

## <a name="see-also"></a>Confira também

[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)
