---
title: "feclearexcept | Microsoft Docs"
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
  - "feclearexcept"
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
  - "feclearexcept"
  - "fenv/feclearexcept"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função feclearexcept"
ms.assetid: ef419da3-c248-4432-b53c-8e7a475d9533
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# feclearexcept
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Tenta limpar os sinalizadores de exceção de ponto flutuante especificados pelo argumento.  
  
## Sintaxe  
  
```  
int feclearexcept(  
   int excepts  
);  
```  
  
#### Parâmetros  
 `excepts`  
 Os sinalizadores de status de exceção para limpar.  
  
## Valor de retorno  
 Retorna zero se `excepts` for zero, ou se todas as exceções especificadas foram limpas com êxito. Caso contrário, retorna um valor diferente de zero.  
  
## Comentários  
 O `feclearexcept` sinalizadores de status de exceção especificadas pelo ponto de função tenta limpar o flutuante `excepts`. A função oferece suporte a essas macros de exceção, definidas em fenv:  
  
|Macro de exceção|Descrição|  
|----------------------|---------------|  
|FE\_DIVBYZERO|Ocorreu um erro singularidade da ou poste em uma operação ponto flutuante anteriormente; um valor infinito foi criado.|  
|FE\_INEXACT|A função foi forçada a arredondar o resultado de uma operação de ponto flutuante anteriormente armazenado.|  
|FE\_INVALID|Ocorreu um erro de domínio em uma operação de ponto flutuante anteriormente.|  
|FE\_OVERFLOW|Ocorreu um erro de intervalo. o resultado de uma operação de ponto flutuante anterior era muito grande para ser representado.|  
|FE\_UNDERFLOW|O resultado de uma operação de ponto flutuante anterior era muito pequeno para ser representado na precisão total; um valor de denormal foi criado.|  
|FE\_ALLEXCEPT|O OR bit a bit de todos com suporte a exceções de ponto flutuante.|  
  
 O `excepts` argumento pode ser zero ou o OR bit a bit de um ou mais das macros de exceção com suporte. O resultado de qualquer outro valor de argumento é indefinido.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`feclearexcept`|\< fenv \>|\< cfenv \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fetestexcept](../Topic/fetestexcept1.md)