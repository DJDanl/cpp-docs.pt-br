---
title: Especificações de exceção (lançar, noexcept) (C++)
ms.date: 01/18/2018
helpviewer_keywords:
- exceptions [C++], exception specifications
- throwing exceptions [C++], throw keyword
- C++ exception handling [C++], throwing exceptions
- throw keyword [C++]
- noexcept keyword [C++]
ms.assetid: 4d3276df-6f31-4c7f-8cab-b9d2d003a629
ms.openlocfilehash: a3d4c0446cd8dde83febb1b4269811b5dec3c477
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222108"
---
# <a name="exception-specifications-throw-noexcept-c"></a>Especificações de exceção (lançar, noexcept) (C++)

Especificações de exceção são um recurso da linguagem C++ que indicam a intenção do programador sobre os tipos de exceção que podem ser propagadas por uma função. Você pode especificar que uma função pode ou não pode sair por uma exceção usando uma *especificação de exceção*. O compilador pode usar essas informações para otimizar as chamadas para a função e encerrar o programa se uma exceção inesperada ignora a função.

Antes do c++17, havia dois tipos de especificação de exceção. O *especificação noexcept* era nova no c++11. Especifica se o conjunto de exceções possíveis que podem escapar a função está vazio. O *especificação de exceção dinâmica*, ou `throw(optional_type_list)` especificação, foi preterido no c++11 e removidos em c++17, exceto para `throw()`, que é um alias para `noexcept(true)`. Essa especificação de exceção foi projetada para fornecer informações de resumo sobre quais exceções podem ser lançadas fora de uma função, mas na prática foi encontrado para ser um problema. Uma especificação de exceção dinâmica que provou ser um pouco útil era a incondicional `throw()` especificação. Por exemplo, a declaração de função:

```cpp
void MyFunction(int i) throw();
```
informa o compilador que a função não lança exceções. No entanto, no **/std: c + + 14** modo isso pode resultar em comportamento indefinido se a função gera uma exceção. Portanto, é recomendável usar o [noexcept](../cpp/noexcept-cpp.md) operador em vez daquele acima:

```cpp
void MyFunction(int i) noexcept;
```
A tabela a seguir resume o Microsoft C++ implementação de especificações de exceção:

|Especificação de exceção|Significado|
|-----------------------------|-------------|
|`noexcept`<br/>`noexcept(true)`<br/>`throw()`|A função não gera uma exceção. Na [/std: c + + 14](../build/reference/std-specify-language-standard-version.md) modo (o que é o padrão), `noexcept` e `noexcept(true)` são equivalentes. Quando uma exceção é lançada de uma função que é declarada `noexcept` ou `noexcept(true)`, [std:: Terminate](../standard-library/exception-functions.md#terminate) é invocado. Quando uma exceção é lançada de uma função declarada como `throw()` na **/std: c + + 14** modo, o resultado é um comportamento indefinido. Nenhuma função específica é invocada. Isso é uma divergência em relação a c++14 standard, que exigia que o compilador para invocar [std::unexpected](../standard-library/exception-functions.md#unexpected).  <br/> **Visual Studio 2017 versão 15.5 e posterior**: Na **/std: c + + 17** modo `noexcept`, `noexcept(true)`, e `throw()` são todas equivalentes. Na **/std: c + + 17** modo `throw()` é um alias para `noexcept(true)`. Na **/std:c++17 + + 17** modo, quando uma exceção é lançada de uma função declarada com qualquer uma dessas especificações [std:: Terminate](../standard-library/exception-functions.md#terminate) é invocado conforme solicitado pelo C++ 17 standard.|
|`noexcept(false)`<br/>`throw(...)`<br/>Não há especificação|A função pode gerar uma exceção de qualquer tipo.|
|`throw(type)`| (**C + + 14 e versões anteriores**) a função pode gerar uma exceção do tipo `type`. O compilador aceita a sintaxe, mas o interpretará como `noexcept(false)`. Na **/std: c + + 17** modo, o compilador emite aviso C5040.|

Se a manipulação de exceção é usada em um aplicativo, deve haver uma função na pilha de chamadas que manipula exceções antes de sair do escopo externo de uma função marcada `noexcept`, `noexcept(true)`, ou `throw()`. Se todas as funções chamadas entre a que lança uma exceção e aquela que lida com a exceção são especificados como `noexcept`, `noexcept(true)` (ou `throw()` no **/std: c + + 17** modo), o programa é encerrado quando o função noexcept propaga a exceção.

O comportamento de exceção de uma função depende dos seguintes fatores:

- Qual [modo de compilação padrão de linguagem](../build/reference/std-specify-language-standard-version.md) está definido.
- Se você estiver compilando a função em C ou C++.

- Qual [/EH](../build/reference/eh-exception-handling-model.md) opção de compilador que você usar.

- Se a especificação de exceção for determinada explicitamente.

As especificações explícitas de exceção não são permitidas em funções C. Uma função C é presumido como não lançam exceções em **/EHsc**e pode lançar exceções estruturadas sob **/EHs**, **/EHa**, ou **/EHac**.

A tabela a seguir resume se uma função C++ pode potencialmente gerar sob várias opções de tratamento de exceções do compilador:

|Função|/EHsc|/EHs|/EHa|/EHac|
|--------------|------------|-----------|-----------|------------|
|Função C++ sem especificação de exceção|Sim|Sim|Sim|Sim|
|Função C++ com `noexcept`, `noexcept(true)`, ou `throw()` especificação de exceção|Não|Não|Sim|Sim|
|Função C++ com `noexcept(false)`, `throw(...)`, ou `throw(type)` especificação de exceção|Sim|Sim|Sim|Sim|

## <a name="example"></a>Exemplo

```cpp
// exception_specification.cpp
// compile with: /EHs
#include <stdio.h>

void handler() {
   printf_s("in handler\n");
}

void f1(void) throw(int) {
   printf_s("About to throw 1\n");
   if (1)
      throw 1;
}

void f5(void) throw() {
   try {
      f1();
   }
   catch(...) {
      handler();
    }
}

// invalid, doesn't handle the int exception thrown from f1()
// void f3(void) throw() {
//   f1();
// }

void __declspec(nothrow) f2(void) {
   try {
      f1();
   }
   catch(int) {
      handler();
    }
}

// only valid if compiled without /EHc
// /EHc means assume extern "C" functions don't throw exceptions
extern "C" void f4(void);
void f4(void) {
   f1();
}

int main() {
   f2();

   try {
      f4();
   }
   catch(...) {
      printf_s("Caught exception from f4\n");
   }
   f5();
}
```

```Output
About to throw 1
in handler
About to throw 1
Caught exception from f4
About to throw 1
in handler
```

## <a name="see-also"></a>Consulte também

[Instruções try, throw e catch (C++)](../cpp/try-throw-and-catch-statements-cpp.md)<br/>
[Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)