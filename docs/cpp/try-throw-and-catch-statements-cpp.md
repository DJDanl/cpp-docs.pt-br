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
ms.openlocfilehash: 31ed5f7a17b9b45dbbecf5ccb29d2b51a7635eaa
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245136"
---
# <a name="try-throw-and-catch-statements-c"></a>Instruções try, throw e catch (C++)

Para implementar a manipulação de C++exceções no, use as expressões **try**, **throw**e **Catch** .

Primeiro, use um bloco **try** para incluir uma ou mais instruções que podem gerar uma exceção.

Uma expressão **throw** sinaliza que uma condição excepcional – muitas vezes, um erro — ocorreu em um bloco **try** . Você pode usar um objeto de qualquer tipo como o operando de uma expressão **throw** . Normalmente, esse objeto é usado para passar informações sobre o erro. Na maioria dos casos, recomendamos que você use a classe [std:: Exception](../standard-library/exception-class.md) ou uma das classes derivadas que são definidas na biblioteca padrão. Se uma delas não for apropriada, recomendamos que você derive sua própria classe de exceção de `std::exception`.

Para lidar com exceções que podem ser geradas, implemente um ou mais blocos **Catch** imediatamente após um bloco **try** . Cada bloco **Catch** especifica o tipo de exceção que ele pode manipular.

Este exemplo mostra um bloco **try** e seus manipuladores. Suponhamos que `GetNetworkResource()` adquira dados por uma conexão de rede e que os dois tipos de exceções sejam classes definidas pelo usuário que derivam de `std::exception`. Observe que as exceções são detectadas pela referência **const** na instrução **Catch** . Recomendamos que você lance exceções por valor e captura-as pela referência const.

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

O código após a cláusula **try** é a seção de código protegida. A expressão throw *gera*— ou seja, gera — uma exceção. O bloco de código após a cláusula **Catch** é o manipulador de exceção. Esse é o manipulador que *captura* a exceção que é gerada se os tipos nas expressões **throw** e **Catch** forem compatíveis. Para obter uma lista de regras que regem a correspondência de tipos em blocos **Catch** , consulte [como os blocos catch são avaliados](../cpp/how-catch-blocks-are-evaluated-cpp.md). Se a instrução **Catch** especificar uma elipse (...) em vez de um tipo, o bloco **Catch** tratará de cada tipo de exceção. Quando você compila com a opção [/EHA](../build/reference/eh-exception-handling-model.md) , elas podem incluir exceções estruturadas C e exceções assíncronas geradas pelo sistema ou pelo aplicativo, como proteção de memória, divisão por zero e violações de ponto flutuante. Como os blocos **Catch** são processados em ordem de programa para localizar um tipo correspondente, um manipulador de reticências deve ser o último manipulador para o bloco **try** associado. Use `catch(...)` com cuidado; não permita que um programa continue a menos que o bloco catch saiba tratar a exceção específica que será capturada. Normalmente, um bloco `catch(...)` é usado para registrar erros e executar a limpeza especial antes de execução do programa ser interrompida.

Uma expressão **throw** que não tem nenhum operando gera novamente a exceção que está sendo manipulada no momento. Recomendamos essa forma ao lançar novamente a exceção, pois isso preserva as informações de tipo polimórfico da exceção original. Essa expressão deve ser usada apenas em um manipulador **Catch** ou em uma função que é chamada a partir de um manipulador **Catch** . O objeto de exceção lançado novamente é o objeto da exceção original, não uma cópia.

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

[Práticas C++ recomendadas modernas para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Exceções C++ não tratadas](../cpp/unhandled-cpp-exceptions.md)<br/>
[__uncaught_exception](../c-runtime-library/reference/uncaught-exception.md)