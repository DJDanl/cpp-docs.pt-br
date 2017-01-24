---
title: "set_unexpected (CRT) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "set_unexpected"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "set_unexpected"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "tratamento de exceção, encerramento"
  - "Função set_unexpected"
  - "função inesperada"
ms.assetid: ebcef032-4771-48e5-88aa-2a1ab8750aa6
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# set_unexpected (CRT)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Instala sua própria função de término a ser chamada por `unexpected`.  
  
## Sintaxe  
  
```  
unexpected_function set_unexpected(  
   unexpected_function unexpFunction   
);  
```  
  
#### Parâmetros  
 `unexpFunction`  
 Ponteiro para uma função que você grave para substituir a função de `unexpected` .  
  
## Valor de retorno  
 Retorna um ponteiro para a função previous de término registrada por `_set_unexpected` de forma que a função anterior pode ser restaurados posteriormente.  Se nenhuma função anterior foi definida, o valor de retorno pode ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.  
  
## Comentários  
 A função de `set_unexpected` instala `unexpFunction` como a função chamada por `unexpected`.  `unexpected` não é usada na implementação de manipulação de exceções gerais do atual C\+\+.  O tipo de `unexpected_function` é definido em EH.H como um ponteiro para uma inesperada função definida pelo usuário, `unexpFunction` que retorna `void`.  A função personalizadas de `unexpFunction` não deve retornar ao chamador.  
  
```  
typedef void ( *unexpected_function )( );  
```  
  
 Por padrão, chamadas `terminate`de `unexpected` .  Você pode alterar este comportamento padrão escrevendo sua própria função de término e chamando `set_unexpected` com o nome da função como seu argumento.  `unexpected` chama a função last especificada como um argumento para `set_unexpected`.  
  
 Ao contrário da função personalizada de término instalada por uma chamada a `set_terminate`, uma exceção pode ser gerada a partir de `unexpFunction`.  
  
 Em um ambiente multithread, as funções inesperadas são mantidas separadamente para cada thread.  Necessidades de cada thread de instalar novos sua própria função inesperada.  Assim, cada thread é responsável de sua própria manipulação de forma inesperada.  
  
 Na implementação atual da Microsoft na manipulação de exceção C\+\+, `unexpected` chama `terminate` por padrão e nunca for chamado pela biblioteca de tempo de execução manipulação de exceções gerais.  Não há nenhuma vantagem específico para chamar `unexpected` em vez de `terminate`.  
  
 Há um único manipulador de `set_unexpected` para todas as dlls ou Execuções dinamicamente vinculado; mesmo se você chamar `set_unexpected` seu manipulador pode ser substituído por outro ou se você estiver substituindo um manipulador definido por outro DLL ou por um EXE.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`set_unexpected`|\<eh.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas do tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [\_get\_unexpected](../Topic/_get_unexpected.md)   
 [set\_terminate](../../c-runtime-library/reference/set-terminate-crt.md)   
 [terminate](../../c-runtime-library/reference/terminate-crt.md)   
 [unexpected](../Topic/unexpected%20\(CRT\).md)