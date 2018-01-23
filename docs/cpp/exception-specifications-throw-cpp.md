---
title: "Especificações de exceção (lançar, noexcept) (C++) | Microsoft Docs"
ms.custom: 
ms.date: 01/18/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- exceptions [C++], exception specifications
- throwing exceptions [C++], throw keyword
- C++ exception handling [C++], throwing exceptions
- throw keyword [C++]
- noexcept keyword [C++]
ms.assetid: 4d3276df-6f31-4c7f-8cab-b9d2d003a629
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bd96f666c4733f1c9b1aff65705840a46729194c
ms.sourcegitcommit: 6f40bba1772a09ff0e3843d5f70b553e1a15ab50
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2018
---
# <a name="exception-specifications-throw-noexcept-c"></a>Especificações de exceção (lançar, noexcept) (C++)

Especificações de exceção são um recurso de linguagem C++ que indicam a intenção do programador sobre os tipos de exceção que pode ser propagada por uma função. Você pode especificar que uma função pode não ser encerrado ou por uma exceção usando uma *especificação de exceção*. O compilador pode usar essas informações para otimizar a chamadas para a função e encerrar o programa se uma exceção inesperada ignora a função. 

Antes de C++ 17 havia dois tipos de especificação de exceção. O *noexcept especificação* era nova no C++ 11. Especifica se o conjunto de exceções potenciais que podem escapar a função está vazio. O *especificação de exceção dinâmico*, ou `throw(optional_type_list)` especificação foi preterido no C++ 11 e removido em C++ 17, exceto para `throw()`, que é um alias para `noexcept(true)`. Essa especificação de exceção foi projetada para fornecer informações de resumo sobre quais exceções podem ser geradas fora de uma função, mas na prática, ele foi encontrado para ser problemático. Uma especificação de exceção dinâmico que revelar um pouco úteis foi o incondicional `throw()` especificação. Por exemplo, a declaração da função:

```cpp
void MyFunction(int i) throw();
```

 informa o compilador que a função não lança exceções. No entanto, em **/std:c + + 14** modo, isso poderá resultar em comportamento inesperado se a função gera uma exceção. Portanto, é recomendável usar o [noexcept](../cpp/noexcept-cpp.md) operador em vez de acima:

```cpp
void MyFunction(int i) noexcept;
```

A tabela a seguir resume a implementação do Visual C++ de especificações de exceção:

|Especificação de exceção|Significado|
|-----------------------------|-------------|
|`noexcept`<br>`noexcept(true)`<br>`throw()`|A função não gera uma exceção. Em [/std:c + + 14](../build/reference/std-specify-language-standard-version.md) modo (o que é o padrão), `noexcept` e `noexcept(true)` são equivalentes. Quando uma exceção é gerada de uma função que é declarada `noexcept` ou `noexcept(true)`, [std::terminate](../standard-library/exception-functions.md#terminate) é invocado. Quando uma exceção é gerada de uma função declarada como `throw()` na **/std:c + + 14** modo, o resultado é um comportamento indefinido. Nenhuma função específica é invocada. Isso é uma divergência de C + + 14 padrão, que são necessários para invocar o compilador [std::unexpected](../standard-library/exception-functions.md#unexpected).  <br> **Visual Studio 2017 versão posterior e 15.5**: em **/std:c + + 17** modo, `noexcept`, `noexcept(true)`, e `throw()` são todas equivalentes. Em **/std:c + + 17** modo, `throw()` é um alias para `noexcept(true)`. Em **/std:c + + 17** modo, quando uma exceção é gerada de uma função declarada com qualquer uma dessas especificações [std::terminate](../standard-library/exception-functions.md#terminate) é invocado de acordo com o padrão C++ 17.|
|`noexcept(false)`<br/>`throw(...)`<br/>Não há especificação|A função pode lançar uma exceção de qualquer tipo.|
|`throw(type)`| (**C + + 14 e anteriores**) a função pode lançar uma exceção do tipo `type`. O compilador do C++ da Microsoft aceita a sintaxe, mas o interpretará como `noexcept(false)`. Em **/std:c + + 17** modo, o compilador emite o aviso C5040.|

 Se o tratamento de exceção é usado em um aplicativo, deve haver uma função na pilha de chamadas identificadores geradas exceções antes de sair do escopo externo de uma função marcados `noexcept`, `noexcept(true)`, ou `throw()`. Se todas as funções chamadas entre o que lança uma exceção e o que lida com a exceção são especificados como `noexcept`, `noexcept(true)` (ou `throw()` na **/std:c + + 17** modo), o programa é encerrado quando o função noexcept propaga a exceção.

 O comportamento de exceção de uma função depende dos seguintes fatores:

- Qual [modo de compilação padrão do idioma](../build/reference/std-specify-language-standard-version.md) está definido.
- Se você estiver compilando a função em C ou C++.

- Qual [/EH](../build/reference/eh-exception-handling-model.md) opção de compilador que você usa.

- Se a especificação de exceção for determinada explicitamente.

 As especificações explícitas de exceção não são permitidas em funções C. Uma função C não deve para lançar exceções em **/EHsc**e pode gerar exceções estruturadas em **/EHs**, **/EHa**, ou **/EHac**.

 A tabela a seguir resume se uma função C++ potencialmente pode gerar em várias opções de tratamento de exceção do compilador:

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

 [Try, throw e catch instruções (C++)](../cpp/try-throw-and-catch-statements-cpp.md) [tratamento de exceção de C++](../cpp/cpp-exception-handling.md)