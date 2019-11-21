---
title: Escrevendo um filtro de exceção
ms.date: 11/04/2016
helpviewer_keywords:
- exception handling [C++], filters
ms.assetid: 47fc832b-a707-4422-b60a-aaefe14189e5
ms.openlocfilehash: aaf0dc77207399d7c6be86127d7decf03895ced5
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245981"
---
# <a name="writing-an-exception-filter"></a>Escrevendo um filtro de exceção

Você pode lidar com uma exceção indo diretamente ao nível do manipulador de exceção ou continuando a execução. Instead of using the exception handler code to handle the exception and falling through, you can use *filter* to clean up the problem and then, by returning -1, resume normal flow without clearing the stack.

> [!NOTE]
>  Algumas exceções não podem ser retomadas. If *filter* evaluates to -1 for such an exception, the system raises a new exception. When you call [RaiseException](/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception), you determine whether the exception will continue.

For example, the following code uses a function call in the *filter* expression: this function handles the problem and then returns -1 to resume normal flow of control:

```cpp
// exceptions_Writing_an_Exception_Filter.cpp
#include <windows.h>
int main() {
   int Eval_Exception( int );

   __try {}

   __except ( Eval_Exception( GetExceptionCode( ))) {
      ;
   }

}
void ResetVars( int ) {}
int Eval_Exception ( int n_except ) {
   if ( n_except != STATUS_INTEGER_OVERFLOW &&
      n_except != STATUS_FLOAT_OVERFLOW )   // Pass on most exceptions
   return EXCEPTION_CONTINUE_SEARCH;

   // Execute some code to clean up problem
   ResetVars( 0 );   // initializes data to 0
   return EXCEPTION_CONTINUE_EXECUTION;
}
```

It is a good idea to use a function call in the *filter* expression whenever *filter* needs to do anything complex. Avaliar a expressão causa a execução da função, nesse caso, `Eval_Exception`.

Note the use of [GetExceptionCode](/windows/win32/Debug/getexceptioncode) to determine the exception. Você deve chamar essa função dentro do próprio filtro. `Eval_Exception` cannot call `GetExceptionCode`, but it must have the exception code passed to it.

Esse manipulador passa o controle para outro manipulador, a menos que a exceção seja um inteiro ou um estouro de ponto flutuante. Se for o caso, o manipulador chamará uma função (`ResetVars` é apenas um exemplo, não uma função de API) para redefinir alguns variáveis globais. *Statement-block-2*, which in this example is empty, can never be executed because `Eval_Exception` never returns EXCEPTION_EXECUTE_HANDLER (1).

Usar uma chamada de função é uma boa técnica de uso geral para lidar com expressões de filtro complexas. Outros dois recursos da linguagem C úteis são:

- O operador condicional

- O operador vírgula

O operador condicional geralmente é útil, pois pode ser usado para verificar se há um código de retorno específico e retornar um de dois valores diferentes. For example, the filter in the following code recognizes the exception only if the exception is STATUS_INTEGER_OVERFLOW:

```cpp
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ? 1 : 0 ) {
```

O propósito do operador condicional nesse caso é basicamente fornecer clareza, pois o código a seguir gera os mesmos resultados:

```cpp
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ) {
```

The conditional operator is more useful in situations where you might want the filter to evaluate to -1, EXCEPTION_CONTINUE_EXECUTION.

O operador vírgula permite executar várias operações independentes dentro de uma única expressão. O efeito é basicamente o de executar várias instruções e depois retornar o valor da última expressão. Por exemplo, o código a seguir armazena o código de exceção em uma variável e o testa:

```cpp
__except( nCode = GetExceptionCode(), nCode == STATUS_INTEGER_OVERFLOW )
```

## <a name="see-also"></a>Consulte também

[Writing an exception handler](../cpp/writing-an-exception-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)