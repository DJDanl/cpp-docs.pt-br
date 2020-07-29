---
title: Instruções try, throw e catch (C++)
ms.date: 11/04/2016
f1_keywords:
- catch_cpp
- try_cpp
- throw_cpp
helpviewer_keywords:
- catch keyword [C++]
- keywords [C++], exception handling
- C++ exception handling, statement syntax
- try-catch keyword [C++], about try-catch exception handling
- throw keyword [C++]
- try-catch keyword [C++]
- try-catch keyword [C++], exception handling
- throwing exceptions [C++], throw keyword
- try-catch keyword [C++], throw keyword [C++]s
- throwing exceptions [C++], implementing C++ exception handling
- throwing exceptions [C++]
- throw keyword [C++], throw() vs. throw(...)
ms.assetid: 15e6a87b-b8a5-4032-a7ef-946c644ba12a
ms.openlocfilehash: 4108d24b2c285b9d55d514dffae7b2efda1b3f86
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227056"
---
# <a name="try-throw-and-catch-statements-c"></a>Instruções try, throw e catch (C++)

Para implementar a manipulação de exceção em C++, você usa **`try`** **`throw`** expressões, e **`catch`** .

Primeiro, use um **`try`** bloco para incluir uma ou mais instruções que podem gerar uma exceção.

Uma **`throw`** expressão sinaliza que uma condição excepcional – muitas vezes, um erro — ocorreu em um **`try`** bloco. Você pode usar um objeto de qualquer tipo como o operando de uma **`throw`** expressão. Normalmente, esse objeto é usado para passar informações sobre o erro. Na maioria dos casos, recomendamos que você use a classe [std:: Exception](../standard-library/exception-class.md) ou uma das classes derivadas que são definidas na biblioteca padrão. Se uma delas não for apropriada, recomendamos que você derive sua própria classe de exceção de `std::exception`.

Para lidar com exceções que podem ser geradas, implemente um ou mais **`catch`** blocos imediatamente após um **`try`** bloco. Cada **`catch`** bloco especifica o tipo de exceção que pode manipular.

Este exemplo mostra um **`try`** bloco e seus manipuladores. Suponhamos que `GetNetworkResource()` adquira dados por uma conexão de rede e que os dois tipos de exceções sejam classes definidas pelo usuário que derivam de `std::exception`. Observe que as exceções são capturadas por **`const`** referência na **`catch`** instrução. Recomendamos que você lance exceções por valor e captura-as pela referência const.

## <a name="example"></a>Exemplo

```cpp
MyData md;
try {
   // Code that could throw an exception
   md = GetNetworkResource();
}
catch (const networkIOException& e) {
   // Code that executes when an exception of type
   // networkIOException is thrown in the try block
   // ...
   // Log error message in the exception object
   cerr << e.what();
}
catch (const myDataFormatException& e) {
   // Code that handles another exception type
   // ...
   cerr << e.what();
}

// The following syntax shows a throw expression
MyData GetNetworkResource()
{
   // ...
   if (IOSuccess == false)
      throw networkIOException("Unable to connect");
   // ...
   if (readError)
      throw myDataFormatException("Format error");
   // ...
}
```

## <a name="remarks"></a>Comentários

O código após a **`try`** cláusula é a seção de código protegida. A **`throw`** expressão *gera*— ou seja, gera — uma exceção. O bloco de código após a **`catch`** cláusula é o manipulador de exceção. Esse é o manipulador que *captura* a exceção que é gerada se os tipos nas **`throw`** **`catch`** expressões e são compatíveis. Para obter uma lista de regras que regem a correspondência de tipos em **`catch`** blocos, consulte [como os blocos de captura são avaliados](../cpp/how-catch-blocks-are-evaluated-cpp.md). Se a **`catch`** instrução especificar reticências (...) em vez de um tipo, o **`catch`** bloco tratará de cada tipo de exceção. Quando você compila com a opção [/EHA](../build/reference/eh-exception-handling-model.md) , elas podem incluir exceções estruturadas C e exceções assíncronas geradas pelo sistema ou pelo aplicativo, como proteção de memória, divisão por zero e violações de ponto flutuante. Como **`catch`** blocos são processados em ordem de programa para localizar um tipo correspondente, um manipulador de reticências deve ser o último manipulador para o **`try`** bloco associado. Use `catch(...)` com cuidado; não permita que um programa continue a menos que o bloco catch saiba tratar a exceção específica que será capturada. Normalmente, um bloco `catch(...)` é usado para registrar erros e executar a limpeza especial antes de execução do programa ser interrompida.

Uma **`throw`** expressão que não tem nenhum operando lança novamente a exceção que está sendo manipulada no momento. Recomendamos essa forma ao lançar novamente a exceção, pois isso preserva as informações de tipo polimórfico da exceção original. Essa expressão deve ser usada apenas em um **`catch`** manipulador ou em uma função que é chamada a partir de um **`catch`** manipulador. O objeto de exceção lançado novamente é o objeto da exceção original, não uma cópia.

```cpp
try {
   throw CSomeOtherException();
}
catch(...) {
   // Catch all exceptions - dangerous!!!
   // Respond (perhaps only partially) to the exception, then
   // re-throw to pass the exception to some other handler
   // ...
   throw;
}
```

## <a name="see-also"></a>Confira também

[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Exceções de C++ não tratadas](../cpp/unhandled-cpp-exceptions.md)<br/>
[__uncaught_exception](../c-runtime-library/reference/uncaught-exception.md)
