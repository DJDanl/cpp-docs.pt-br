---
title: "_get_fmode | Microsoft Docs"
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
  - "_get_fmode"
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
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "get_fmode"
  - "_get_fmode"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _get_fmode"
  - "tradução de arquivo [C++], modo padrão"
  - "Função get_fmode"
ms.assetid: 22ea70e2-b9b5-422d-b514-64f4beaea45c
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_fmode
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o modo de conversão de arquivo padrão para operações de E\/S de arquivo.  
  
## Sintaxe  
  
```  
errno_t _get_fmode(   
   int * pmode   
);  
```  
  
#### Parâmetros  
 \[saída\] `pmode`  
 Um ponteiro para um número inteiro a ser preenchido com o modo padrão atual: `_O_TEXT` ou `_O_BINARY`.  
  
## Valor de retorno  
 Retorna zero se bem\-sucedido; um código de erro da falha.  Se `pmode` é `NULL`, o manipulador inválido do parâmetro será invocado como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` será definido como `EINVAL` e a função retornará `EINVAL`.  
  
## Comentários  
 A função obtém o valor da variável global de [\_fmode](../../c-runtime-library/fmode.md) .  Essa variável especifica o modo de conversão de arquivo padrão do nível baixo e passa operações de E\/S de arquivo, como `_open`, `_pipe`, `fopen`, e `freopen`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_get_fmode`|\<stdlib.h\>|\<fcntl.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo em [\_set\_fmode](../../c-runtime-library/reference/set-fmode.md).  
  
## Equivalente ao .NET Framework  
 Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [\_fmode](../../c-runtime-library/fmode.md)   
 [\_set\_fmode](../../c-runtime-library/reference/set-fmode.md)   
 [\_setmode](../../c-runtime-library/reference/setmode.md)   
 [E\/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md)