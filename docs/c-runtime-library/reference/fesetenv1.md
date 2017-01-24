---
title: "fesetenv | Microsoft Docs"
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
  - "fesetenv"
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
  - "fesetenv"
  - "fenv/fesetenv"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função fesetenv"
ms.assetid: ffc64fff-8ea7-4d59-9e04-ff96ef8cd012
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fesetenv
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o ambiente atual de ponto flutuante.  
  
## Sintaxe  
  
```  
int fesetenv(  
   const fenv_t *penv  
);  
  
```  
  
#### Parâmetros  
 `penv`  
 Ponteiro para uma `fenv_t` objeto que contém um ambiente de ponto flutuante conforme definido por uma chamada para [fegetenv](../Topic/fegetenv2.md) ou [feholdexcept](../Topic/feholdexcept1.md). Você também pode especificar o ambiente de ponto flutuante de inicialização padrão usando a macro FE\_DFL\_ENV.  
  
## Valor de retorno  
 Retorna 0 se o ambiente foi definido com êxito. Caso contrário, retorna um valor diferente de zero.  
  
## Comentários  
 O `fesetenv` função define o ambiente atual de ponto flutuante do valor armazenado no `fenv_t` objeto apontado por `penv`. O flutuante ambiente ponto é o conjunto de sinalizadores de status e modos de controle que afetam os cálculos de ponto flutuantes. Isso inclui o modo de arredondamento e os sinalizadores de status para exceções de ponto flutuante. Se `penv` não é FE\_DFL\_ENV ou não aponta para um arquivo `fenv_t` do objeto, o comportamento subseqüente é indefinido.  
  
 Uma chamada para essa função define a exceção sinalizadores de status que estão na `penv` mas não gera essas exceções.  
  
 Para usar essa função, você deve desativar otimizações de ponto flutuantes que poderiam impedir o acesso usando a `#pragma fenv_access(on)` diretiva antes da chamada. Para obter mais informações, consulte [fenv\_access](../../preprocessor/fenv-access.md).  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`fesetenv`|\< fenv \>|\< cfenv \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fegetenv](../../c-runtime-library/reference/fegetenv1.md)   
 [feclearexcept](../../c-runtime-library/reference/feclearexcept1.md)   
 [feholdexcept](../../c-runtime-library/reference/feholdexcept2.md)   
 [fesetexceptflag](../Topic/fesetexceptflag2.md)