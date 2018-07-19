---
title: Escrevendo um filtro de exceção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- exception handling [C++], filters
ms.assetid: 47fc832b-a707-4422-b60a-aaefe14189e5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eb4b02144f55231a7b4472cd62322fd61a543d18
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942154"
---
# <a name="writing-an-exception-filter"></a>Escrevendo um filtro de exceção
Você pode lidar com uma exceção indo diretamente ao nível do manipulador de exceção ou continuando a execução. Em vez de usar o código do manipulador de exceção para lidar com a exceção e queda, você pode usar *filtro* para limpar o problema e em seguida, ao retornar -1, retomar o fluxo normal sem limpar a pilha.  
  
> [!NOTE]
>  Algumas exceções não podem ser retomadas. Se *filtro* é avaliada como -1 para essa exceção, o sistema gerará uma nova exceção. Quando você chama [RaiseException](http://msdn.microsoft.com/library/windows/desktop/ms680552), você determina se a exceção continuará.  
  
 Por exemplo, o código a seguir usa uma chamada de função na *filtro* expressão: essa função tratará o problema e, em seguida, retorna -1 para retomar o fluxo de controle normal:  
  
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
  
 Ele é uma boa ideia usar uma chamada de função na *filtro* expressão sempre que *filtro* precisa fazer algo complexo. Avaliar a expressão causa a execução da função, nesse caso, `Eval_Exception`.  
  
 Observe o uso de [GetExceptionCode](http://msdn.microsoft.com/library/windows/desktop/ms679356) para determinar a exceção. Você deve chamar essa função dentro do próprio filtro. `Eval_Exception` não é possível chamar `GetExceptionCode`, mas ele deve ter o código de exceção passado para ele.  
  
 Esse manipulador passa o controle para outro manipulador, a menos que a exceção seja um inteiro ou um estouro de ponto flutuante. Se for o caso, o manipulador chamará uma função (`ResetVars` é apenas um exemplo, não uma função de API) para redefinir alguns variáveis globais. *Instrução de bloco de 2*, que neste exemplo está vazio, nunca pode ser executado porque `Eval_Exception` nunca retorna EXCEPTION_EXECUTE_HANDLER (1).  
  
 Usar uma chamada de função é uma boa técnica de uso geral para lidar com expressões de filtro complexas. Outros dois recursos da linguagem C úteis são:  
  
-   O operador condicional  
  
-   O operador vírgula  
  
 O operador condicional geralmente é útil, pois pode ser usado para verificar se há um código de retorno específico e retornar um de dois valores diferentes. Por exemplo, o filtro no código a seguir confirma a exceção apenas se a exceção é STATUS_INTEGER_OVERFLOW:  
  
```cpp 
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ? 1 : 0 ) {  
```  
  
 O propósito do operador condicional nesse caso é basicamente fornecer clareza, pois o código a seguir gera os mesmos resultados:  
  
```cpp 
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ) {  
```  
  
 O operador condicional é mais útil em situações em que você desejaria o filtro avalie como -1, EXCEPTION_CONTINUE_EXECUTION.  
  
 O operador vírgula permite executar várias operações independentes dentro de uma única expressão. O efeito é basicamente o de executar várias instruções e depois retornar o valor da última expressão. Por exemplo, o código a seguir armazena o código de exceção em uma variável e o testa:  
  
```cpp 
__except( nCode = GetExceptionCode(), nCode == STATUS_INTEGER_OVERFLOW )  
```  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)