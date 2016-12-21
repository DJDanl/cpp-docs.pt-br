---
title: "fegetenv | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "fetegenv"
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
  - "fegetenv"
  - "fenv/fegetenv"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função fetegenv"
ms.assetid: 68962421-6978-4b27-8e4c-ad1577830cf6
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fegetenv
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Armazena o ambiente atual de ponto flutuante no objeto especificado.  
  
## Sintaxe  
  
```  
int fegetenv(  
   fenv_t *penv  
);  
  
```  
  
#### Parâmetros  
 `penv`  
 Ponteiro para uma `fenv_t` objeto para conter os valores de ponto flutuante do ambiente atual.  
  
## Valor de retorno  
 Retorna 0 se o ambiente de ponto flutuante foi armazenado com êxito em `penv`. Caso contrário, retorna um valor diferente de zero.  
  
## Comentários  
 O `fegetenv` função armazena o ambiente atual de ponto flutuante no objeto apontado por `penv`. O flutuante ambiente ponto é o conjunto de sinalizadores de status e modos de controle que afetam os cálculos de ponto flutuantes. Isso inclui o modo de direção de arredondamento e os sinalizadores de status para exceções de ponto flutuante. Se `penv` não aponta para um arquivo `fenv_t` do objeto, o comportamento subseqüente é indefinido.  
  
 Para usar essa função, você deve desativar otimizações de ponto flutuantes que poderiam impedir o acesso usando a `#pragma fenv_access(on)` diretiva antes da chamada. Para obter mais informações, consulte [fenv\_access](../../preprocessor/fenv-access.md).  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`fegetenv`|\< fenv \>|\< cfenv \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fesetenv](../../c-runtime-library/reference/fesetenv1.md)