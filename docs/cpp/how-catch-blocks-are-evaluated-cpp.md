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
ms.openlocfilehash: 11804c48631659b84006abb824837efea3902416
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188631"
---
# <a name="how-catch-blocks-are-evaluated-c"></a>Como blocos catch são avaliados (C++)

O C++ permite lançar exceções de qualquer tipo, embora seja recomendável lançar os tipos derivados de std::exception. Uma C++ exceção pode ser detectada por um manipulador **Catch** que especifica o mesmo tipo que a exceção gerada, ou por um manipulador que pode capturar qualquer tipo de exceção.

Se o tipo de exceção lançada for uma classe, que também tenha uma classe base (ou classes), ela pode ser capturada pelos manipuladores que aceitam classes base do tipo da exceção, bem como por referências às bases do tipo da exceção. Observe que, quando uma exceção é capturada por uma referência, ela é associada ao objeto de exceção lançado real; caso contrário, é uma cópia (bem semelhante a um argumento para uma função).

Quando uma exceção é lançada, ela pode ser detectada pelos seguintes tipos de manipuladores **Catch** :

- Um manipulador que pode aceitar qualquer tipo (usando a sintaxe de reticências).

- Um manipulador que aceita o mesmo tipo que o objeto de exceção; Como é uma cópia, os modificadores **const** e **volatile** são ignorados.

- Um manipulador que aceita uma referência para mesmo tipo do objeto de exceção.

- Um manipulador que aceita uma referência a uma forma **const** ou **volátil** do mesmo tipo que o objeto de exceção.

- Um manipulador que aceita uma classe base do mesmo tipo que o objeto de exceção; Como é uma cópia, os modificadores **const** e **volatile** são ignorados. O manipulador **Catch** para uma classe base não deve preceder o manipulador **Catch** para a classe derivada.

- Um manipulador que aceita uma referência a uma classe base do mesmo tipo do objeto de exceção.

- Um manipulador que aceita uma referência a uma forma **const** ou **volátil** de uma classe base do mesmo tipo que o objeto de exceção.

- Um manipulador que aceita um ponteiro no qual um objeto de ponteiro gerado pode ser convertido pelas regras padrão de conversão de ponteiro.

A ordem na qual os manipuladores **Catch** aparecem é significativa, pois os manipuladores para um determinado bloco **try** são examinados em ordem de sua aparência. Por exemplo, é um erro para colocar o manipulador de uma classe base antes do manipulador de uma classe derivada. Depois que um manipulador de **Catch** correspondente for encontrado, os manipuladores subsequentes não serão examinados. Como resultado, um manipulador de **captura** de reticências deve ser o último manipulador para seu bloco **try** . Por exemplo:

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

Neste exemplo, o manipulador de **captura** de reticências é o único manipulador que é examinado.

## <a name="see-also"></a>Confira também

[Práticas C++ recomendadas modernas para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)
