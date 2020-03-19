---
title: Especificações de exceção (throw, noexcept)C++()
ms.date: 01/18/2018
helpviewer_keywords:
- exceptions [C++], exception specifications
- throwing exceptions [C++], throw keyword
- C++ exception handling [C++], throwing exceptions
- throw keyword [C++]
- noexcept keyword [C++]
ms.assetid: 4d3276df-6f31-4c7f-8cab-b9d2d003a629
ms.openlocfilehash: 4c7cc6027a3af4c300b88389cb29e3ccf091514e
ms.sourcegitcommit: 44eeb065c3148d0484de791080a3f963109744fc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/18/2020
ms.locfileid: "79509395"
---
# <a name="exception-specifications-throw-noexcept-c"></a>Especificações de exceção (throw, noexcept)C++()

As especificações de exceção C++ são um recurso de linguagem que indica a intenção do programador sobre os tipos de exceção que podem ser propagados por uma função. Você pode especificar que uma função pode ou não ser encerrada por uma exceção usando uma *especificação de exceção*. O compilador pode usar essas informações para otimizar as chamadas para a função e para encerrar o programa se uma exceção inesperada escapar da função.

Antes do C++ 17 havia dois tipos de especificação de exceção. A *especificação noexcept* era nova no c++ 11. Especifica se o conjunto de possíveis exceções que podem escapar da função está vazio. A especificação de *exceção dinâmica*, ou `throw(optional_type_list)` especificação, foi preterida no c++ 11 e removida no c++ 17, exceto pelo `throw()`, que é um alias para `noexcept(true)`. Essa especificação de exceção foi criada para fornecer informações resumidas sobre quais exceções podem ser geradas fora de uma função, mas na prática ela foi considerada problemática. A especificação de exceção dinâmica que provava ser um pouco útil era a especificação de `throw()` incondicional. Por exemplo, a declaração da função:

```cpp
void MyFunction(int i) throw();
```

informa o compilador que a função não lança exceções. No entanto, em **/std: modo c++ 14** isso poderia levar a um comportamento indefinido se a função gerar uma exceção. Portanto, é recomendável usar o operador [noexcept](../cpp/noexcept-cpp.md) em vez de um acima:

```cpp
void MyFunction(int i) noexcept;
```

A tabela a seguir resume a implementação C++ de especificações de exceção da Microsoft:

|Especificação de exceção|Significado|
|-----------------------------|-------------|
|`noexcept`<br/>`noexcept(true)`<br/>`throw()`|A função não gera uma exceção. Em [/std: modo c++ 14](../build/reference/std-specify-language-standard-version.md) (que é o padrão), `noexcept` e `noexcept(true)` são equivalentes. Quando uma exceção é gerada de uma função que é declarada `noexcept` ou `noexcept(true)`, [std:: Terminate](../standard-library/exception-functions.md#terminate) é invocado. Quando uma exceção é gerada de uma função declarada como `throw()` no modo **/std: c++ 14** , o resultado é um comportamento indefinido. Nenhuma função específica é invocada. Essa é uma divergência do padrão C++ 14, que exigia que o compilador invocasse [std:: inesperado](../standard-library/exception-functions.md#unexpected).  <br/> **Visual Studio 2017 versão 15,5 e posterior**: em **/std: modo c++ 17** , `noexcept`, `noexcept(true)`e `throw()` são equivalentes. Em **/std: modo c++ 17** , `throw()` é um alias para `noexcept(true)`. Em **/std: modo c++ 17** , quando uma exceção é gerada de uma função declarada com qualquer uma dessas especificações, [std:: Terminate](../standard-library/exception-functions.md#terminate) é invocado conforme exigido pelo padrão c++ 17.|
|`noexcept(false)`<br/>`throw(...)`<br/>Sem especificação|A função pode gerar uma exceção de qualquer tipo.|
|`throw(type)`| (**C++ 14 e anterior**) A função pode gerar uma exceção do tipo `type`. O compilador aceita a sintaxe, mas a interpreta como `noexcept(false)`. Em **/std: modo c++ 17** o compilador emite aviso C5040.|

Se a manipulação de exceção for usada em um aplicativo, deverá haver uma função na pilha de chamadas que manipula exceções lançadas antes de sair do escopo externo de uma função marcada `noexcept`, `noexcept(true)`ou `throw()`. Se qualquer função chamada entre aquela que gera uma exceção e a que manipula a exceção for especificada como `noexcept`, `noexcept(true)` (ou `throw()` no modo **/std: c++ 17** ), o programa será encerrado quando a função noexcept propagar a exceção.

O comportamento de exceção de uma função depende dos seguintes fatores:

- Qual [modo de compilação padrão de idioma](../build/reference/std-specify-language-standard-version.md) está definido.
- Se você estiver compilando a função em C ou C++.

- A opção de compilador [/eh](../build/reference/eh-exception-handling-model.md) que você usa.

- Se a especificação de exceção for determinada explicitamente.

As especificações explícitas de exceção não são permitidas em funções C. Pressupõe-se que uma função C não gere exceções em **/EHsc**e possa lançar exceções estruturadas em **o/EHS**, **/EHA**ou **/EHac**.

A tabela a seguir resume se uma C++ função pode potencialmente ser lançada sob várias opções de manipulação de exceção de compilador:

|Função|/EHsc|/EHs|/EHa|/EHac|
|--------------|------------|-----------|-----------|------------|
|Função C++ sem especificação de exceção|Sim|Sim|Sim|Sim|
|C++função com especificação de exceção `noexcept`, `noexcept(true)`ou `throw()`|Não|Não|Sim|Sim|
|C++função com especificação de exceção `noexcept(false)`, `throw(...)`ou `throw(type)`|Sim|Sim|Sim|Sim|

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

## <a name="see-also"></a>Confira também

[Instruções try, throw e catch (C++)](../cpp/try-throw-and-catch-statements-cpp.md)<br/>
[Práticas C++ recomendadas modernas para exceções e tratamento de erros](errors-and-exception-handling-modern-cpp.md)