---
title: Escrevendo um filtro de exceção
ms.date: 11/04/2016
helpviewer_keywords:
- exception handling [C++], filters
ms.assetid: 47fc832b-a707-4422-b60a-aaefe14189e5
ms.openlocfilehash: 05d3aa79d1293001e80a77b3171b7a4607cd81c7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369479"
---
# <a name="writing-an-exception-filter"></a>Escrevendo um filtro de exceção

Você pode lidar com uma exceção indo diretamente ao nível do manipulador de exceção ou continuando a execução. Em vez de usar o código do manipulador de exceção para lidar com a exceção e cair, você pode usar o *filtro* para limpar o problema e, em seguida, retornando -1, retomar o fluxo normal sem limpar a pilha.

> [!NOTE]
> Algumas exceções não podem ser retomadas. Se *o filtro* avaliar para -1 para tal exceção, o sistema aumentará uma nova exceção. Quando você chama [RaiseException,](/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception)você determina se a exceção continuará.

Por exemplo, o código a seguir usa uma chamada de função na expressão *do filtro:* esta função lida com o problema e, em seguida, retorna -1 para retomar o fluxo normal de controle:

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

É uma boa ideia usar uma chamada de função na expressão do *filtro* sempre que o *filtro* precisa fazer algo complexo. Avaliar a expressão causa a execução da função, nesse caso, `Eval_Exception`.

Observe o uso de [GetExceptionCode](/windows/win32/Debug/getexceptioncode) para determinar a exceção. Você deve chamar essa função dentro do próprio filtro. `Eval_Exception`não `GetExceptionCode`pode chamar, mas deve ter o código de exceção passado para ele.

Esse manipulador passa o controle para outro manipulador, a menos que a exceção seja um inteiro ou um estouro de ponto flutuante. Se for o caso, o manipulador chamará uma função (`ResetVars` é apenas um exemplo, não uma função de API) para redefinir alguns variáveis globais. *O statement-block-2*, que neste exemplo está vazio, nunca pode ser executado porque `Eval_Exception` nunca retorna EXCEPTION_EXECUTE_HANDLER (1).

Usar uma chamada de função é uma boa técnica de uso geral para lidar com expressões de filtro complexas. Outros dois recursos da linguagem C úteis são:

- O operador condicional

- O operador vírgula

O operador condicional geralmente é útil, pois pode ser usado para verificar se há um código de retorno específico e retornar um de dois valores diferentes. Por exemplo, o filtro no código a seguir reconhece a exceção somente se a exceção for STATUS_INTEGER_OVERFLOW:

```cpp
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ? 1 : 0 ) {
```

O propósito do operador condicional nesse caso é basicamente fornecer clareza, pois o código a seguir gera os mesmos resultados:

```cpp
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ) {
```

O operador condicional é mais útil em situações em que você pode querer que o filtro avalie para -1, EXCEPTION_CONTINUE_EXECUTION.

O operador vírgula permite executar várias operações independentes dentro de uma única expressão. O efeito é basicamente o de executar várias instruções e depois retornar o valor da última expressão. Por exemplo, o código a seguir armazena o código de exceção em uma variável e o testa:

```cpp
__except( nCode = GetExceptionCode(), nCode == STATUS_INTEGER_OVERFLOW )
```

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Tratamento estruturado de exceções (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
