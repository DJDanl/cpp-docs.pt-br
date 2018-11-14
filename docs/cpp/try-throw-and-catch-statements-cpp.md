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
ms.openlocfilehash: a55c1f2d5c2e73028b337d17b74fe1280f670707
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51326700"
---
# <a name="try-throw-and-catch-statements-c"></a>Instruções try, throw e catch (C++)

Para implementar o tratamento de exceções em C++, use **tente**, **throw**, e **catch** expressões.

Primeiro, use uma **tente** bloco para incluir uma ou mais instruções que podem gerar uma exceção.

Um **lançar** expressão sinaliza que uma condição excepcional — muitas vezes, um erro – ocorreu em um **tente** bloco. Você pode usar um objeto de qualquer tipo como o operando de um **lançar** expressão. Normalmente, esse objeto é usado para passar informações sobre o erro. Na maioria dos casos, é recomendável que você use o [std:: Exception](../standard-library/exception-class.md) classe ou uma das classes derivadas que são definidas na biblioteca padrão. Se uma delas não for apropriada, recomendamos que você derive sua própria classe de exceção de `std::exception`.

Para tratar exceções que podem ser lançadas, implementar uma ou mais **catch** blocos imediatamente após um **tente** bloco. Cada **catch** bloco Especifica o tipo de exceção, ele pode manipular.

Este exemplo mostra uma **tente** bloco e seus manipuladores. Suponhamos que `GetNetworkResource()` adquira dados por uma conexão de rede e que os dois tipos de exceções sejam classes definidas pelo usuário que derivam de `std::exception`. Observe que as exceções são capturadas pela **const** faz referência na **catch** instrução. Recomendamos que você lance exceções por valor e captura-as pela referência const.

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

O código após o **tente** cláusula é a seção protegida de código. O **lançar** expressão *lança*— ou seja, gera – uma exceção. O bloco de código após o **catch** cláusula é o manipulador de exceção. Esse é o manipulador que *captura* a exceção que é lançada se os tipos na **throw** e **catch** expressões são compatíveis. Para obter uma lista de regras que regem a correspondência de tipo em **catch** blocos, consulte [como os blocos Catch são avaliados](../cpp/how-catch-blocks-are-evaluated-cpp.md). Se o **catch** instrução Especifica que um sinal de reticências (...) em vez de um tipo, o **catch** bloco manipula todos os tipos de exceção. Quando você compila com a [/EHa](../build/reference/eh-exception-handling-model.md) opção, eles podem incluir exceções C estruturadas e exceções assíncronas geradas pelo sistema ou gerados pelo aplicativo, como violações de divisão por zero e de ponto flutuante de proteção, de memória . Porque **catch** blocos são processados na ordem do programa para localizar um tipo compatível, um manipulador de reticências deve ser o último manipulador associado **tente** bloco. Use `catch(...)` com cuidado; não permita que um programa continue a menos que o bloco catch saiba tratar a exceção específica que será capturada. Normalmente, um bloco `catch(...)` é usado para registrar erros e executar a limpeza especial antes de execução do programa ser interrompida.

Um **lançar** expressão que não tem operando Relança a exceção que está sendo manipulada no momento. Recomendamos essa forma ao lançar novamente a exceção, pois isso preserva as informações de tipo polimórfico da exceção original. Essa expressão deve ser usada apenas em uma **catch** manipulador ou em uma função que é chamada de um **catch** manipulador. O objeto de exceção lançado novamente é o objeto da exceção original, não uma cópia.

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

## <a name="see-also"></a>Consulte também

[Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Exceções C++ não tratadas](../cpp/unhandled-cpp-exceptions.md)<br/>
[__uncaught_exception](../c-runtime-library/reference/uncaught-exception.md)