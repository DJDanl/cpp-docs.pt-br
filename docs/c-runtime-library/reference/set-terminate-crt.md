---
title: "set_terminate (CRT) | Microsoft Docs"
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
  - "set_terminate"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "set_terminate"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "tratamento de exceção, encerramento"
  - "Função set_terminate"
  - "Função terminate"
ms.assetid: 3ff1456a-7898-44bc-9266-a328a80b6006
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# set_terminate (CRT)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Instala sua própria rotina de conclusão a ser chamada por `terminate`.  
  
## Sintaxe  
  
```  
terminate_function set_terminate(  
   terminate_function termFunction  
);  
```  
  
#### Parâmetros  
 `termFunction`  
 Ponteiro para finalizar uma função que você grave.  
  
## Valor de retorno  
 Retorna um ponteiro para a função previous registrada por `set_terminate` de forma que a função anterior pode ser restaurados posteriormente.  Se nenhuma função anterior foi definida, o valor de retorno pode ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.  
  
## Comentários  
 A função de `set_terminate` instala `termFunction` como a função chamada por `terminate`.  `set_terminate` é usado com manipulação de exceção C\+\+ e pode ser chamado em qualquer momento do programa antes que a exceção seja gerada.  chamadas `abort` de`terminate` por padrão.  Você pode alterar esse padrão escrevendo sua própria função de término e chamando `set_terminate` com o nome da função como seu argumento.  `terminate` chama a função last especificada como um argumento para `set_terminate`.  Depois de executar qualquer tarefa desejada de limpeza, `termFunction` deve sair do programa.  Se não é encerrado \(se retorna ao chamador\), `abort` é chamado.  
  
 Em um ambiente multithread, encerre funções são mantidos separados para cada thread.  Necessidades das novas cada thread de instalar seus próprios encerram a função.  Assim, cada thread é responsável de sua própria manipulação de término.  
  
 O tipo de `terminate_function` é definido em EH.H como um ponteiro para uma função definida pelo usuário do término, `termFunction` que retorna `void`.  A função personalizada `termFunction` não pode aceitar argumentos e não deve retornar ao chamador.  Se fizer isso, `abort` é chamado.  Uma exceção não pode ser gerada a partir de `termFunction`.  
  
```  
typedef void ( *terminate_function )( );  
```  
  
> [!NOTE]
>  A função de `set_terminate` só funciona fora do depurador.  
  
 Há um único manipulador de `set_terminate` para todas as dlls ou Execuções dinamicamente vinculado; mesmo se você chamar `set_terminate` seu manipulador pode ser substituído por outro, ou você pode substituir um manipulador definido por outro DLL ou por um EXE.  
  
 Essa função não tem suporte em **\/clr:pure**.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`set_terminate`|\<eh.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [encerrar](../../c-runtime-library/reference/terminate-crt.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas do tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [\_get\_terminate](../../c-runtime-library/reference/get-terminate.md)   
 [set\_unexpected](../../c-runtime-library/reference/set-unexpected-crt.md)   
 [terminate](../../c-runtime-library/reference/terminate-crt.md)   
 [unexpected](../Topic/unexpected%20\(CRT\).md)