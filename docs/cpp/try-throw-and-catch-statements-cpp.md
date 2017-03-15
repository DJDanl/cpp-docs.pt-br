---
title: "Instru&#231;&#245;es try, throw e catch (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "catch_cpp"
  - "throw"
  - "try_cpp"
  - "try"
  - "throw_cpp"
  - "catch"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave catch [C++]"
  - "palavras-chave [C++], tratamento de exceção"
  - "Tratamento de exceções do C++, sintaxe de instrução"
  - "try-catch palavra-chave [C++], sobre o tratamento de exceção de try-catch"
  - "palavra-chave throw [C++]"
  - "palavra-chave try-catch [C++]"
  - "try-catch-chave [C++], tratamento de exceção"
  - "Lançando exceções, a palavra-chave throw"
  - "try-catch-chave [C++], [C++] s de palavra-chave throw"
  - "Lançando exceções, Implementando o tratamento de exceção do C++"
  - "lançando exceções"
  - "palavra-chave [C++], throw () versus throw Throw"
ms.assetid: 15e6a87b-b8a5-4032-a7ef-946c644ba12a
caps.latest.revision: 24
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es try, throw e catch (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para implementar o tratamento de exceções em C++, você usa as expressões `try`, `throw` e `catch`.  
  
 Primeiro, use um bloco `try` para incluir uma ou mais instruções que possam lançar uma exceção.  
  
 Uma expressão `throw` sinaliza que uma condição excepcional – geralmente, um erro – ocorreu em um bloco `try`. Você pode usar um objeto de qualquer tipo como o operando de uma expressão `throw`. Normalmente, esse objeto é usado para passar informações sobre o erro. Na maioria dos casos, é recomendável que você use o [std:: Exception](../standard-library/exception-class1.md) classe ou uma das classes derivadas que são definidas na biblioteca padrão. Se uma delas não for apropriada, recomendamos que você derive sua própria classe de exceção de `std::exception`.  
  
 Para tratar as exceções que podem ser lançadas, implemente um ou vários blocos `catch` imediatamente depois de um bloco `try`. Cada bloco `catch` especifica o tipo de exceção que ele pode tratar.  
  
 Este exemplo mostra um bloco `try` e seus manipuladores. Suponhamos que `GetNetworkResource()` adquira dados por uma conexão de rede e que os dois tipos de exceções sejam classes definidas pelo usuário que derivam de `std::exception`. Observe que as exceções são capturadas pela referência `const` na instrução `catch`. Recomendamos que você lance exceções por valor e captura-as pela referência const.  
  
## <a name="example"></a>Exemplo  
  
```  
  
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
 O código após a cláusula `try` é a seção de código protegida. O `throw` expressão *lança*— ou seja, gera – uma exceção. O bloco de código após a cláusula `catch` é o manipulador de exceções. Esse é o manipulador que *captura* a exceção que é lançada se os tipos na `throw` e `catch` expressões são compatíveis. Para obter uma lista de regras que regem a correspondência de tipo em `catch` blocos, consulte [como blocos Catch são avaliados](../Topic/How%20Catch%20Blocks%20are%20Evaluated%20\(C++\).md). Se a instrução `catch` especificar reticências (...) em vez de um tipo, o bloco `catch` tratará todo tipo de exceção. Quando você compila com a [/EHa](../build/reference/eh-exception-handling-model.md) opção, eles podem incluir exceções estruturadas de C e exceções assíncronas geradas pelo sistema ou geradas pelo aplicativo, como violações de divisão por zero e de ponto flutuante de proteção de memória. Como os blocos `catch` são processados na ordem do programa para localizar um tipo compatível, um manipulador de reticências deve ser o último manipulador para o bloco `try` associado. Use `catch(...)` com cuidado; não permita que um programa continue a menos que o bloco catch saiba tratar a exceção específica que será capturada. Normalmente, um bloco `catch(...)` é usado para registrar erros e executar a limpeza especial antes de execução do programa ser interrompida.  
  
 Uma expressão `throw` que não tem operando relança a exceção que está sendo tratada no momento. Recomendamos essa forma ao lançar novamente a exceção, pois isso preserva as informações de tipo polimórfico da exceção original. Essa expressão deve ser usada somente em um manipulador `catch` ou em uma função que é chamada por um manipulador `catch`. O objeto de exceção lançado novamente é o objeto da exceção original, não uma cópia.  
  
```  
try {  
   throw CSomeOtherException();  
}  
catch(...) {  
   // Catch all exceptions – dangerous!!!  
   // Respond (perhaps only partially) to the exception, then  
   // re-throw to pass the exception to some other handler  
   // ...  
   throw;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções C++](../cpp/cpp-exception-handling.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Exceções do C++ não tratadas](../cpp/unhandled-cpp-exceptions.md)   
 [__uncaught_exception](../c-runtime-library/reference/uncaught-exception.md)