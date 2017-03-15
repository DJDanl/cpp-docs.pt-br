---
title: "Escrevendo um filtro de exce&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de exceção, filtros"
ms.assetid: 47fc832b-a707-4422-b60a-aaefe14189e5
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Escrevendo um filtro de exce&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode lidar com uma exceção indo diretamente ao nível do manipulador de exceção ou continuando a execução.  Em vez de usar o código do manipulador de exceção para lidar com a exceção e de queda, você pode usar o comando *filter* para limpar o problema e, em seguida, retornando – 1, retomar o fluxo normal sem limpar a pilha.  
  
> [!NOTE]
>  Algumas exceções não podem ser retomadas.  Se *filter* for avaliado em –1 para essa exceção, o sistema gerará uma nova exceção.  Ao chamar [RaiseException](http://msdn.microsoft.com/library/windows/desktop/ms680552), você determina se uma exceção continuará.  
  
 Por exemplo, o código a seguir usa uma chamada de função na expressão *filter*: essa função tratará o problema e retornará –1 para retomar o fluxo de controle normal:  
  
```  
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
  
 É uma boa ideia usar uma chamada de função na expressão *filter* sempre que *filter* precisar fazer algo complexo.  Avaliar a expressão causa a execução da função, nesse caso, `Eval_Exception`.  
  
 Observe o uso de [GetExceptionCode](http://msdn.microsoft.com/library/windows/desktop/ms679356) para determinar a exceção.  Você deve chamar essa função dentro do próprio filtro.  `Eval_Exception` não pode chamar **GetExceptionCode**, mas deve ter o código de exceção passado para ele.  
  
 Esse manipulador passa o controle para outro manipulador, a menos que a exceção seja um inteiro ou um estouro de ponto flutuante.  Se for o caso, o manipulador chamará uma função \(`ResetVars` é apenas um exemplo, não uma função de API\) para redefinir alguns variáveis globais.  *Statement\-block\-2*, que neste exemplo está vazio, nunca pode ser executado porque `Eval_Exception` nunca retorna EXCEPTION\_EXECUTE\_HANDLER \(1\).  
  
 Usar uma chamada de função é uma boa técnica de uso geral para lidar com expressões de filtro complexas.  Outros dois recursos da linguagem C úteis são:  
  
-   O operador condicional  
  
-   O operador vírgula  
  
 O operador condicional geralmente é útil, pois pode ser usado para verificar se há um código de retorno específico e retornar um de dois valores diferentes.  Por exemplo, o filtro no código a seguir confirma a exceção apenas se a exceção for `STATUS_INTEGER_OVERFLOW`:  
  
```  
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ? 1 : 0 ) {  
```  
  
 O propósito do operador condicional nesse caso é basicamente fornecer clareza, pois o código a seguir gera os mesmos resultados:  
  
```  
__except( GetExceptionCode() == STATUS_INTEGER_OVERFLOW ) {  
```  
  
 O operador condicional é mais útil em situações em que talvez você queira que o filtro seja avaliado em –1, EXCEPTION\_CONTINUE\_EXECUTION.  
  
 O operador vírgula permite executar várias operações independentes dentro de uma única expressão.  O efeito é basicamente o de executar várias instruções e depois retornar o valor da última expressão.  Por exemplo, o código a seguir armazena o código de exceção em uma variável e o testa:  
  
```  
__except( nCode = GetExceptionCode(), nCode == STATUS_INTEGER_OVERFLOW )  
```  
  
## Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)