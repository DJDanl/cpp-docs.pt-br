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

Você pode lidar com uma exceção indo diretamente ao nível do manipulador de exceção ou continuando a execução. Em vez de usar o código do manipulador de exceção para lidar com a exceção e fazer a passagem, você pode usar o *filtro* para limpar o problema e, em seguida, retornar-1, retomar o fluxo normal sem limpar a pilha.

> [!NOTE]
>  Algumas exceções não podem ser retomadas. Se o *filtro* for avaliado como-1 para essa exceção, o sistema gerará uma nova exceção. Ao chamar [RaiseException](/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception), você determina se a exceção continuará.

Por exemplo, o código a seguir usa uma chamada de função na expressão de *filtro* : essa função manipula o problema e, em seguida, retorna-1 para retomar o fluxo de controle normal:

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

É uma boa ideia usar uma chamada de função na expressão de *filtro* sempre que o *filtro* precisar fazer algo complexo. Avaliar a expressão causa a execução da função, nesse caso, `Eval_Exception`.

Observe o uso de [GetExceptionCode](/windows/win32/Debug/getexceptioncode) para determinar a exceção. Você deve chamar essa função dentro do próprio filtro. `Eval_Exception` não pode chamar `GetExceptionCode`, mas deve ter o código de exceção passado para ele.

Esse manipulador passa o controle para outro manipulador, a menos que a exceção seja um inteiro ou um estouro de ponto flutuante. Se for o caso, o manipulador chamará uma função (`ResetVars` é apenas um exemplo, não uma função de API) para redefinir alguns variáveis globais. *Statement-Block-2*, que neste exemplo está vazio, nunca pode ser executado porque `Eval_Exception` nunca retorna EXCEPTION_EXECUTE_HANDLER (1).

Usar uma chamada de função é uma boa técnica de uso geral para lidar com expressões de filtro complexas. Outros dois recursos da linguagem C úteis são:

- O operador condicional

- O operador vírgula

O operador condicional geralmente é útil, pois pode ser usado para verificar se há um código de retorno específico e retornar um de dois valores diferentes. Por exemplo, o filtro no código a seguir reconhecerá a exceção somente se a exceção for STATUS_INTEGER_OVERFLOW:

```cpp
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ? 1 : 0 ) {
```

O propósito do operador condicional nesse caso é basicamente fornecer clareza, pois o código a seguir gera os mesmos resultados:

```cpp
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ) {
```

O operador condicional é mais útil em situações em que você talvez queira que o filtro seja avaliado como-1, EXCEPTION_CONTINUE_EXECUTION.

O operador vírgula permite executar várias operações independentes dentro de uma única expressão. O efeito é basicamente o de executar várias instruções e depois retornar o valor da última expressão. Por exemplo, o código a seguir armazena o código de exceção em uma variável e o testa:

```cpp
__except( nCode = GetExceptionCode(), nCode == STATUS_INTEGER_OVERFLOW )
```

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)