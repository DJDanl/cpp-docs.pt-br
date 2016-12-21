---
title: "_set_new_mode | Microsoft Docs"
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
  - "_set_new_mode"
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
  - "api-ms-win-crt-heap-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "set_new_mode"
  - "_set_new_mode"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _set_new_mode"
  - "modos de manipulador"
  - "Função set_new_mode"
ms.assetid: 4d14039a-e54e-4689-8c70-74a4b9834768
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_new_mode
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um novo modo de manipulador de `malloc`.  
  
## Sintaxe  
  
```  
int _set_new_mode(  
   int newhandlermode   
);  
```  
  
#### Parâmetros  
 `newhandlermode`  
 Novo modo de manipulador de `malloc`; o valor válido é 0 ou 1.  
  
## Valor de retorno  
 Retorna o modo anterior do manipulador definido para `malloc`.  Um valor de retorno 1 indica que, falha alocar memória, `malloc` chamado anteriormente a nova rotina do manipulador; um valor de retorno 0 indica que não fez.  Se o argumento de `newhandlermode` não é igual a 0 ou 1, 1 será retornado.  
  
## Comentários  
 A função C\+\+ `_set_new_mode` define o novo modo de manipulador de [malloc](../../c-runtime-library/reference/malloc.md).  O novo modo de manipulador indica se, em caso de falha, `malloc` deve chamar a nova rotina do manipulador conforme definido por [\_set\_new\_handler](../Topic/_set_new_handler.md).  Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha para alocar memória.  Você pode substituir esse comportamento padrão para que, quando `malloc` não aloca memória, `malloc` chama a nova rotina de manipulador da mesma forma que o operador de `new` faz quando falha pela mesma razão.  Para obter mais informações, consulte os operadores de [novo](../../cpp/new-operator-cpp.md) e de [excluir](../../cpp/delete-operator-cpp.md)*na referência de linguagem C\+\+*.  Para substituir a opção, chame:  
  
```  
_set_new_mode(1)  
```  
  
 no início do programa ou link com o Newmode.obj \(consulte [Opções de link](../Topic/Link%20Options.md)\).  
  
 Essa função valida seu parâmetro.  Se `newhandlermode` não for 0 ou 1, a função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, **\_**`set_new_mode` retorna \-1 e defina `errno` a `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_set_new_mode`|\<new.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Alocação de memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [\_query\_new\_handler](../../c-runtime-library/reference/query-new-handler.md)   
 [\_query\_new\_mode](../../c-runtime-library/reference/query-new-mode.md)